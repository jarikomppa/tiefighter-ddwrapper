#include <Windows.h>
#include <gl/gl.h>
#include "wrapper.h"

int gLastUpdate = -1;
int gScreenWidth = 640;
int gScreenHeight = 480;
int gScreenBits = 8;
int gAllowResize = 0;
WNDPROC origfunc = NULL;
HWND gHwnd;
HDC gWindowDC;

int gRealScreenWidth;
int gRealScreenHeight;

int gTexData[2048*1024];
int gTemp[640*480];

myIDirectDrawSurface *gPrimarySurface = NULL, *gBackBuffer = NULL;

void gl_updatescreen()
{
	int i, j;
	int tex_w = 1024;
	int tex_h = 512;

	if (gScreenWidth > 320)
	{
		tex_w *= 2;
		tex_h *= 2;
	}

	if (gScreenBits == 8)
	{
		if (gPrimarySurface->mCurrentPalette)
		{
			for (i = 0; i < gScreenHeight; i++)
			{
				for (j = 0; j < gScreenWidth; j++)
				{
					int pix = gPrimarySurface->mSurfaceData[j + i * gScreenWidth];
					gTemp[j + i * gScreenWidth] = *(int*)&(gPrimarySurface->mCurrentPalette->mPal[pix]);
				}
			}
		}
	}
	/*
	tex_w/=2;
	tex_h/=2;
	for (i = 0; i < gScreenHeight; i++)
		for (j = 0; j < gScreenWidth; j++)
			gTexData[j + i * tex_w] = gTemp[j + i * gScreenWidth];
*/
	for (i = 0; i < gScreenHeight * 2; i++)
		for (j = 0; j < gScreenWidth * 2; j++)
			gTexData[j + i * tex_w] = gTemp[j/2 + (i/2) * gScreenWidth];

    // upload texture
    glTexImage2D(GL_TEXTURE_2D,    // target
                 0,                // level
                 GL_RGB,           // internalformat
                 tex_w,            // width
                 tex_h,            // height
                 0,                // border
                 GL_RGBA,          // format
                 GL_UNSIGNED_BYTE, // type
                 gTexData);        // texels

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	glShadeModel(GL_SMOOTH);

    glEnable(GL_TEXTURE_2D);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0);
	glViewport(0, 0, gRealScreenWidth, gRealScreenHeight);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	float u = ((float)gScreenWidth*2) / (float)tex_w;
    float v = ((float)gScreenHeight*2) / (float)tex_h;

    float w = 1, h = 1;
	float aspect = (float)gScreenWidth / (float)gScreenHeight;

    w = (gRealScreenHeight * aspect) / gRealScreenWidth;
    h = (gRealScreenWidth * (1 / aspect)) / gRealScreenHeight;

    if (w > h) w = 1; else h = 1;

	glClear(GL_COLOR_BUFFER_BIT);
	glDisable(GL_BLEND);
    glColor3f(1.0f,1.0f,1.0f); 

	glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0,0); glVertex2f( -w,  h);
        glTexCoord2f(u,0); glVertex2f(  w,  h);
        glTexCoord2f(u,v); glVertex2f(  w, -h);	
        glTexCoord2f(0,v); glVertex2f( -w, -h);
    glEnd();
    

	SwapBuffers(gWindowDC);

}


LRESULT CALLBACK newwinproc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{	
	static int focus = 1;
	int tick = GetTickCount();
	if (gLastUpdate == -1)
	{
		gLastUpdate = tick;
	}

	// Force updates at at least 40Hz so that some bits which do not
	// update the screen explicitly show up, including the GDI mode..
	if ((tick - gLastUpdate) > (1000 / 40))
	{
		logf("winproc: too long since last update");
		gl_updatescreen();
	}

	//SetCapture(hWnd); // causes horrible input lag, so let's not use it
	switch (uMsg)
	{
	case WM_KILLFOCUS:
		{
			focus = 0;
			ShowCursor(1);
			ClipCursor(NULL);
		}
		break;
	case WM_SETFOCUS: 
		{
			focus = 1;

			RECT r;
			r.top = 0;
			r.left = 0;
			r.bottom = gScreenHeight;
			r.right = gScreenWidth;
			ClipCursor(&r);

			SetCursorPos(gScreenWidth / 2, gScreenHeight / 2);
			ShowCursor(0); // clipcursor doesn't work with cursor disabled. Yay.

			break;
		}
	case WM_LBUTTONDOWN:
	case WM_LBUTTONUP:
	case WM_RBUTTONDOWN:
	case WM_RBUTTONUP:
	case WM_MOUSEMOVE:
		{
			if (!focus)
				return 0;
		}
		break;
	case WM_WINDOWPOSCHANGING:
		if (!gAllowResize)
		{
			// Host may try to resize and -position the window.
			// Disallow this. The gAllowResize global is so that
			// we can resize ourselves.
			WINDOWPOS * p = (WINDOWPOS *)lParam;
			p->flags |= SWP_NOSIZE | SWP_NOMOVE;
			return 0;		
		}
		break;
	}

	// Pass control to the application..	
	return origfunc(hWnd, uMsg, wParam, lParam);
}

void gl_setvideomode(int w, int h, int bits)
{
	gAllowResize = 1;
	// Go full screen..
	MoveWindow(gHwnd, 0, 0, gRealScreenWidth, gRealScreenHeight, 0);
	// Set position just in case..
	//SetWindowPos(gHwnd, NULL, 0, 0, 0, 0, SWP_NOSIZE);
	gAllowResize = 0;
}

void gl_init(HWND aHwnd)
{	
	// Only init once..
	if (origfunc != NULL)
		return;

	gHwnd = aHwnd;

	// Get the application's window procedure..
	origfunc = (WNDPROC)GetWindowLong(gHwnd, GWL_WNDPROC);
	// ..and replace it with our own.
	//SetWindowLong(gHwnd, GWL_WNDPROC, (long)newwinproc);
	
	RECT r;
	r.top = 0;
	r.left = 0;
	// lowest fallback: 640x480 window
	r.bottom = 480;
	r.right = 640;

	// next up: work area for primary display
	SystemParametersInfo(SPI_GETWORKAREA,0,&r,0);

	// best: full screen
	MONITORINFO mon;
	mon.cbSize = sizeof(mon);

	if (GetMonitorInfo(MonitorFromWindow(gHwnd,MONITOR_DEFAULTTOPRIMARY),&mon))
	{
		r = mon.rcMonitor;
	}
	
	gRealScreenWidth = r.right;
	gRealScreenHeight = r.bottom;
	/*
	gRealScreenWidth /= 2;
	gRealScreenHeight /= 2;
	*/

	gAllowResize = 1;
	// Go full screen..
	MoveWindow(gHwnd, 640, 0, gRealScreenWidth, gRealScreenHeight, 0);
	// Set position just in case..
	//SetWindowPos(gHwnd, NULL, 0, 0, 0, 0, SWP_NOSIZE);
	gAllowResize = 0;

    PIXELFORMATDESCRIPTOR pfd;
    pfd.nSize=sizeof(PIXELFORMATDESCRIPTOR);                             // Size 
    pfd.nVersion=1;                                                      // Version
    pfd.dwFlags=PFD_DRAW_TO_WINDOW|PFD_SUPPORT_OPENGL|PFD_DOUBLEBUFFER;  // Selected flags
    pfd.iPixelType=PFD_TYPE_RGBA;                                        // Pixelformat
    pfd.cColorBits=16;                                                   // Pixel depth
    pfd.cDepthBits=16;                                                   // Zbuffer depth
    pfd.iLayerType=PFD_MAIN_PLANE;                                       // Place the pixelformat on the main plane
	
	HGLRC gOpenGLRC = NULL;
	// this is a bit heavy-handed, but the delay dll loading
	// does seem to require a bit of work on win7..
	// (and delay-loading the opengl dll is required to work in xp)
	// Oddly enough, doing LoadLibrary on opengl didn't work in xp.
	do {
		Sleep(50);
		gWindowDC=GetDC(gHwnd);
		int pf=ChoosePixelFormat(gWindowDC, &pfd);
		SetPixelFormat(gWindowDC, pf, &pfd);
		gOpenGLRC = wglCreateContext(gWindowDC);
	} while (!gOpenGLRC);

	wglMakeCurrent(gWindowDC, gOpenGLRC);

	ShowWindow(gHwnd, SW_SHOW);
	SetForegroundWindow(gHwnd);

	r.top = 0;
	r.left = 0;
	r.bottom = gScreenHeight;
	r.right = gScreenWidth;
	ClipCursor(&r);

	// Create a timer so we'll get some events all the time
	SetTimer(gHwnd, 1, 10, NULL);
}

void gl_exit()
{
}
