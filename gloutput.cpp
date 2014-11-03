#include <Windows.h>
#include <windowsx.h>
#include <gl/gl.h>
#include "wrapper.h"

int gLastUpdate = -1;
int gScreenWidth = 640;
int gScreenHeight = 480;
int gScreenBits = 8;
int gAllowResize = 0;
int gFocused = 1;
WNDPROC origfunc = NULL;
HWND gHwnd;
HDC gWindowDC;
HGLRC gOpenGLRC = NULL;

int gRealScreenWidth;
int gRealScreenHeight;

int gTexData[2048*1024];
int gTemp[640*480];

myIDirectDrawSurface *gPrimarySurface = NULL, *gBackBuffer = NULL;

void gl_setup();

void gl_updatescreen()
{
	int i, j;
	int tex_w = 1024;
	int tex_h = 512;

	gLastUpdate = GetTickCount();

	//if (!gFocused)
//		return;

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
	if (gScreenBits == 16 && gPrimarySurface && gPrimarySurface->mSurfaceData)
	{
		unsigned short * surf = (unsigned short *)gPrimarySurface->mSurfaceData;
		int pitch = gPrimarySurface->mPitch / 2;
		for (i = 0; i < gScreenHeight; i++)
		{
			for (j = 0; j < gScreenWidth; j++)
			{
				int pix = surf[pitch * i + j];				
						
				int red   = (pix >> 11) & ((1 << 5) - 1);
				int green = (pix >>  5) & ((1 << 6) - 1);
				int blue  = (pix >>  0) & ((1 << 5) - 1);
						
				// fill bottom bits
				red = (red << 3) | (red >> 2);
				green = (green << 2) | (green >> 4);
				blue = (blue << 3) | (blue >> 2);

				gTemp[j + i * gScreenWidth] = (blue << 16) | (green << 8) | red;
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
	if (gFocused)
		glViewport(0, 0, gRealScreenWidth, gRealScreenHeight);
	else
		glViewport(0, 0, gRealScreenWidth/10, gRealScreenHeight/10);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	float u = ((float)gScreenWidth*2) / (float)tex_w;
    float v = ((float)gScreenHeight*2) / (float)tex_h;

    float w = 1, h = 1;
	float aspect = (float)gScreenWidth / (float)gScreenHeight;
	float r_aspect = (1 / aspect);

    w = (gRealScreenHeight * aspect) / gRealScreenWidth;
    h = (gRealScreenWidth * r_aspect) / gRealScreenHeight;

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
    
	// Mouse cursor
	CURSORINFO ci;
	ci.cbSize = sizeof(ci);
	GetCursorInfo(&ci);
	int mousex = ci.ptScreenPos.x;
	int mousey = ci.ptScreenPos.y;

	float mx = (((float)mousex / gScreenWidth) - 0.5f) * w * 2;
	float my = (((float)mousey / gScreenHeight) - 0.5f) * -h * 2;
	
	if (ci.flags & CURSOR_SHOWING && gFocused)
	{
		glDisable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);
		glBlendFunc(GL_ONE, GL_ONE);
	    glColor4f(0.2f,0.2f,0.2f,1.0f); 
		glBegin(GL_TRIANGLES);
			glVertex2f( mx, my);
			glVertex2f( mx+0.05f*r_aspect, my-0.02f*aspect);
			glVertex2f( mx+0.02f*r_aspect, my-0.05f*aspect);	
			glVertex2f( mx, my);
			glVertex2f( mx+0.04f*r_aspect, my-0.01f*aspect);
			glVertex2f( mx+0.01f*r_aspect, my-0.04f*aspect);	
		    glColor4f(0.4f,0.4f,0.4f,1.0f); 
			glVertex2f( mx, my);
			glVertex2f( mx+0.045f*r_aspect, my-0.015f*aspect);
			glVertex2f( mx+0.015f*r_aspect, my-0.045f*aspect);	
		glEnd();
		glDisable(GL_BLEND);
	}


	SwapBuffers(gWindowDC);

}



LRESULT CALLBACK newwinproc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{	
//	logf("newwinproc %x %x %x %x", hWnd, uMsg, wParam, lParam);
#define WMDETECT(x) if (uMsg == x) logf("Window message " #x " %x(%d), %x(%d)\n", wParam, wParam, lParam, lParam);
	WMDETECT(WM_NULL)
	WMDETECT(WM_CREATE)
	WMDETECT(WM_DESTROY)
	WMDETECT(WM_MOVE)
	WMDETECT(WM_SIZE)
	WMDETECT(WM_ACTIVATE)
	WMDETECT(WM_SETFOCUS)
	WMDETECT(WM_KILLFOCUS)
	WMDETECT(WM_ENABLE)
	WMDETECT(WM_SETREDRAW)
	WMDETECT(WM_SETTEXT)
	WMDETECT(WM_GETTEXT)
	WMDETECT(WM_GETTEXTLENGTH)
	WMDETECT(WM_PAINT)
	WMDETECT(WM_CLOSE)
	WMDETECT(WM_QUERYENDSESSION)
	WMDETECT(WM_QUERYOPEN)
	WMDETECT(WM_ENDSESSION)
	WMDETECT(WM_QUIT)
	WMDETECT(WM_ERASEBKGND)
	WMDETECT(WM_SYSCOLORCHANGE)
	WMDETECT(WM_SHOWWINDOW)
	WMDETECT(WM_WININICHANGE)
	WMDETECT(WM_DEVMODECHANGE)
	WMDETECT(WM_ACTIVATEAPP)
	WMDETECT(WM_FONTCHANGE)
	WMDETECT(WM_TIMECHANGE)
	WMDETECT(WM_CANCELMODE)
	WMDETECT(WM_SETCURSOR)
	WMDETECT(WM_MOUSEACTIVATE)
	WMDETECT(WM_CHILDACTIVATE)
	WMDETECT(WM_QUEUESYNC)
	WMDETECT(WM_GETMINMAXINFO)
	WMDETECT(WM_PAINTICON)
	WMDETECT(WM_ICONERASEBKGND)
	WMDETECT(WM_NEXTDLGCTL)
	WMDETECT(WM_SPOOLERSTATUS)
	WMDETECT(WM_DRAWITEM)
	WMDETECT(WM_MEASUREITEM)
	WMDETECT(WM_DELETEITEM)
	WMDETECT(WM_VKEYTOITEM)
	WMDETECT(WM_CHARTOITEM)
	WMDETECT(WM_SETFONT)
	WMDETECT(WM_GETFONT)
	WMDETECT(WM_SETHOTKEY)
	WMDETECT(WM_GETHOTKEY)
	WMDETECT(WM_QUERYDRAGICON)
	WMDETECT(WM_COMPAREITEM)
	WMDETECT(WM_GETOBJECT)
	WMDETECT(WM_COMPACTING)
	WMDETECT(WM_COMMNOTIFY)
	WMDETECT(WM_WINDOWPOSCHANGING)
	WMDETECT(WM_WINDOWPOSCHANGED)
	WMDETECT(WM_POWER)
	WMDETECT(WM_COPYDATA)
	WMDETECT(WM_CANCELJOURNAL)
	WMDETECT(WM_NOTIFY)
	WMDETECT(WM_INPUTLANGCHANGEREQUEST)
	WMDETECT(WM_INPUTLANGCHANGE)
	WMDETECT(WM_TCARD)
	WMDETECT(WM_HELP)
	WMDETECT(WM_USERCHANGED)
	WMDETECT(WM_NOTIFYFORMAT)
	WMDETECT(WM_CONTEXTMENU)
	WMDETECT(WM_STYLECHANGING)
	WMDETECT(WM_STYLECHANGED)
	WMDETECT(WM_DISPLAYCHANGE)
	WMDETECT(WM_GETICON)
	WMDETECT(WM_SETICON)
	WMDETECT(WM_NCCREATE)
	WMDETECT(WM_NCDESTROY)
	WMDETECT(WM_NCCALCSIZE)
	WMDETECT(WM_NCHITTEST)
	WMDETECT(WM_NCPAINT)
	WMDETECT(WM_NCACTIVATE)
	WMDETECT(WM_GETDLGCODE)
	WMDETECT(WM_SYNCPAINT)
	WMDETECT(WM_NCMOUSEMOVE)
	WMDETECT(WM_NCLBUTTONDOWN)
	WMDETECT(WM_NCLBUTTONUP)
	WMDETECT(WM_NCLBUTTONDBLCLK)
	WMDETECT(WM_NCRBUTTONDOWN)
	WMDETECT(WM_NCRBUTTONUP)
	WMDETECT(WM_NCRBUTTONDBLCLK)
	WMDETECT(WM_NCMBUTTONDOWN)
	WMDETECT(WM_NCMBUTTONUP)
	WMDETECT(WM_NCMBUTTONDBLCLK)
	WMDETECT(WM_NCXBUTTONDOWN)
	WMDETECT(WM_NCXBUTTONUP)
	WMDETECT(WM_NCXBUTTONDBLCLK)
	WMDETECT(WM_INPUT_DEVICE_CHANGE)
	WMDETECT(WM_INPUT)
	WMDETECT(WM_KEYFIRST)
	WMDETECT(WM_KEYDOWN)
	WMDETECT(WM_KEYUP)
	WMDETECT(WM_CHAR)
	WMDETECT(WM_DEADCHAR)
	WMDETECT(WM_SYSKEYDOWN)
	WMDETECT(WM_SYSKEYUP)
	WMDETECT(WM_SYSCHAR)
	WMDETECT(WM_SYSDEADCHAR)
	WMDETECT(WM_UNICHAR)
	WMDETECT(WM_KEYLAST)
	WMDETECT(WM_KEYLAST)
	WMDETECT(WM_IME_STARTCOMPOSITION)
	WMDETECT(WM_IME_ENDCOMPOSITION)
	WMDETECT(WM_IME_COMPOSITION)
	WMDETECT(WM_IME_KEYLAST)
	WMDETECT(WM_INITDIALOG)
	WMDETECT(WM_COMMAND)
	WMDETECT(WM_SYSCOMMAND)
	WMDETECT(WM_TIMER)
	WMDETECT(WM_HSCROLL)
	WMDETECT(WM_VSCROLL)
	WMDETECT(WM_INITMENU)
	WMDETECT(WM_INITMENUPOPUP)
	WMDETECT(WM_GESTURE)
	WMDETECT(WM_GESTURENOTIFY)
	WMDETECT(WM_MENUSELECT)
	WMDETECT(WM_MENUCHAR)
	WMDETECT(WM_ENTERIDLE)
	WMDETECT(WM_MENURBUTTONUP)
	WMDETECT(WM_MENUDRAG)
	WMDETECT(WM_MENUGETOBJECT)
	WMDETECT(WM_UNINITMENUPOPUP)
	WMDETECT(WM_MENUCOMMAND)
	WMDETECT(WM_CHANGEUISTATE)
	WMDETECT(WM_UPDATEUISTATE)
	WMDETECT(WM_QUERYUISTATE)
	WMDETECT(WM_CTLCOLORMSGBOX)
	WMDETECT(WM_CTLCOLOREDIT)
	WMDETECT(WM_CTLCOLORLISTBOX)
	WMDETECT(WM_CTLCOLORBTN)
	WMDETECT(WM_CTLCOLORDLG)
	WMDETECT(WM_CTLCOLORSCROLLBAR)
	WMDETECT(WM_CTLCOLORSTATIC)
	WMDETECT(WM_MOUSEFIRST)
	WMDETECT(WM_MOUSEMOVE)
	WMDETECT(WM_LBUTTONDOWN)
	WMDETECT(WM_LBUTTONUP)
	WMDETECT(WM_LBUTTONDBLCLK)
	WMDETECT(WM_RBUTTONDOWN)
	WMDETECT(WM_RBUTTONUP)
	WMDETECT(WM_RBUTTONDBLCLK)
	WMDETECT(WM_MBUTTONDOWN)
	WMDETECT(WM_MBUTTONUP)
	WMDETECT(WM_MBUTTONDBLCLK)
	WMDETECT(WM_MOUSEWHEEL)
	WMDETECT(WM_XBUTTONDOWN)
	WMDETECT(WM_XBUTTONUP)
	WMDETECT(WM_XBUTTONDBLCLK)
	WMDETECT(WM_MOUSEHWHEEL)
	WMDETECT(WM_MOUSELAST)
	WMDETECT(WM_PARENTNOTIFY)
	WMDETECT(WM_ENTERMENULOOP)
	WMDETECT(WM_EXITMENULOOP)
	WMDETECT(WM_NEXTMENU)
	WMDETECT(WM_SIZING)
	WMDETECT(WM_CAPTURECHANGED)
	WMDETECT(WM_MOVING)
	WMDETECT(WM_POWERBROADCAST)
	WMDETECT(WM_DEVICECHANGE)
	WMDETECT(WM_MDICREATE)
	WMDETECT(WM_MDIDESTROY)
	WMDETECT(WM_MDIACTIVATE)
	WMDETECT(WM_MDIRESTORE)
	WMDETECT(WM_MDINEXT)
	WMDETECT(WM_MDIMAXIMIZE)
	WMDETECT(WM_MDITILE)
	WMDETECT(WM_MDICASCADE)
	WMDETECT(WM_MDIICONARRANGE)
	WMDETECT(WM_MDIGETACTIVE)
	WMDETECT(WM_MDISETMENU)
	WMDETECT(WM_ENTERSIZEMOVE)
	WMDETECT(WM_EXITSIZEMOVE)
	WMDETECT(WM_DROPFILES)
	WMDETECT(WM_MDIREFRESHMENU)
	WMDETECT(WM_TOUCH)
	WMDETECT(WM_IME_SETCONTEXT)
	WMDETECT(WM_IME_NOTIFY)
	WMDETECT(WM_IME_CONTROL)
	WMDETECT(WM_IME_COMPOSITIONFULL)
	WMDETECT(WM_IME_SELECT)
	WMDETECT(WM_IME_CHAR)
	WMDETECT(WM_IME_REQUEST)
	WMDETECT(WM_IME_KEYDOWN)
	WMDETECT(WM_IME_KEYUP)
	WMDETECT(WM_MOUSEHOVER)
	WMDETECT(WM_MOUSELEAVE)
	WMDETECT(WM_NCMOUSEHOVER)
	WMDETECT(WM_NCMOUSELEAVE)
	WMDETECT(WM_WTSSESSION_CHANGE)
	WMDETECT(WM_TABLET_FIRST)
	WMDETECT(WM_TABLET_LAST)
	WMDETECT(WM_CUT)
	WMDETECT(WM_COPY)
	WMDETECT(WM_PASTE)
	WMDETECT(WM_CLEAR)
	WMDETECT(WM_UNDO)
	WMDETECT(WM_RENDERFORMAT)
	WMDETECT(WM_RENDERALLFORMATS)
	WMDETECT(WM_DESTROYCLIPBOARD)
	WMDETECT(WM_DRAWCLIPBOARD)
	WMDETECT(WM_PAINTCLIPBOARD)
	WMDETECT(WM_VSCROLLCLIPBOARD)
	WMDETECT(WM_SIZECLIPBOARD)
	WMDETECT(WM_ASKCBFORMATNAME)
	WMDETECT(WM_CHANGECBCHAIN)
	WMDETECT(WM_HSCROLLCLIPBOARD)
	WMDETECT(WM_QUERYNEWPALETTE)
	WMDETECT(WM_PALETTEISCHANGING)
	WMDETECT(WM_PALETTECHANGED)
	WMDETECT(WM_HOTKEY)
	WMDETECT(WM_PRINT)
	WMDETECT(WM_PRINTCLIENT)
	WMDETECT(WM_APPCOMMAND)
	WMDETECT(WM_THEMECHANGED)
	WMDETECT(WM_CLIPBOARDUPDATE)
	WMDETECT(WM_DWMCOMPOSITIONCHANGED)
	WMDETECT(WM_DWMNCRENDERINGCHANGED)
	WMDETECT(WM_DWMCOLORIZATIONCOLORCHANGED)
	WMDETECT(WM_DWMWINDOWMAXIMIZEDCHANGE)
	WMDETECT(WM_DWMSENDICONICTHUMBNAIL)
	WMDETECT(WM_DWMSENDICONICLIVEPREVIEWBITMAP)
	WMDETECT(WM_GETTITLEBARINFOEX)
	WMDETECT(WM_HANDHELDFIRST)
	WMDETECT(WM_HANDHELDLAST)
	WMDETECT(WM_AFXFIRST)
	WMDETECT(WM_AFXLAST)
	WMDETECT(WM_PENWINFIRST)
	WMDETECT(WM_PENWINLAST)
	WMDETECT(WM_APP)
	WMDETECT(WM_USER)

	int tick = GetTickCount();
	if (gLastUpdate == -1)
	{
		gLastUpdate = tick;
	}

	// Force updates at at least 40Hz so that some bits which do not
	// update the screen explicitly show up, including the GDI mode..
	
	if ((tick - gLastUpdate) > (1000 / 40))
	{
	//	logf("winproc: too long since last update");
		gl_updatescreen();
	}
	

	//SetCapture(hWnd); // causes horrible input lag, so let's not use it
	switch (uMsg)
	{
/*
// doesn't seem to be enough to let us alt-tab.. game probably uses some other hook.
	case WM_SYSKEYDOWN:
	case WM_SYSKEYUP:
	case WM_SYSCOMMAND:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);		
*/
	case WM_KILLFOCUS:
		{
			gFocused = 0;
			ShowCursor(1);
			ClipCursor(NULL);
			gAllowResize = 1;
			MoveWindow(gHwnd,0,0,gRealScreenWidth/10,gRealScreenHeight/10,0);			
		}
		break;
	case WM_SETFOCUS: 
		{
			gFocused = 1;

			gl_setup();

			SetCursorPos(gScreenWidth / 2, gScreenHeight / 2);
			break;
		}
	case WM_LBUTTONDOWN:
	case WM_LBUTTONUP:
	case WM_RBUTTONDOWN:
	case WM_RBUTTONUP:
	case WM_MOUSEMOVE:
		{
			if (!gFocused)
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
		else
		{
			gAllowResize--;
		}
		break;
	}
	
	// Pass control to the application..	
	return CallWindowProc(origfunc,hWnd, uMsg, wParam, lParam);
}

void gl_setvideomode(int w, int h, int bits)
{
	gScreenWidth = w;
	gScreenHeight = h;
	gScreenBits = bits;
}

void gl_init(HWND aHwnd)
{	
	// Only init once..
	if (origfunc != NULL)
		return;

	gHwnd = aHwnd;

	// Get the application's window procedure..
	origfunc = (WNDPROC)GetWindowLongPtr(gHwnd, GWLP_WNDPROC);
	// ..and replace it with our own.
	SetWindowLongPtr(gHwnd, GWLP_WNDPROC, (LONG)newwinproc);
	
	// "Certain window data is cached, so changes you make using SetWindowLongPtr 
	//  will not take effect until you call the SetWindowPos function." -- MSDN
	SetWindowPos(gHwnd, NULL, 0, 0, 0, 0, SWP_NOSIZE); 

	gl_setup();
}

void gl_setup()
{
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
	// Go full screen.. (add a scanline to fool win7 not to see this as a fullscreen window)
	MoveWindow(gHwnd, 0, -1, gRealScreenWidth, gRealScreenHeight+1, 0);
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

	ShowCursor(1);
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
