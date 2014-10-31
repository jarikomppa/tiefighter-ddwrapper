#define STRICT
#define WIN32_LEAN_AND_MEAN
#define DIRECT3D_VERSION 0x900
#ifdef _DEBUG
#define D3D_DEBUG_INFO
#endif

#include <windows.h>
#include <d3d9.h>
#include <math.h>
#include <d3dx9.h>

#include "ddoutput.h"


#ifdef _DEBUG
#define DEBUGMESS(a) OutputDebugStringA(a)
#else
#define DEBUGMESS(a)
#endif

#define STRINGIFY(x) STRINGIFY_INNER(x)
#define STRINGIFY_INNER(x) #x
#define DEFINED_NOTE DEBUGMESS(__FILE__ "(" STRINGIFY(__LINE__) "): Defined function called: " __FUNCTION__ "\r\n");


#define SafeRelease(a) { if(a) { a->Release(); a=0; } }
#define MYVERTEXFORMAT D3DFVF_XYZRHW|D3DFVF_TEX1
struct MyVertex {
    float x,y,z,w,u,v;
};

int gWidth;
int gHeight;

static HWND window;
static bool Inited=false;
static bool InGame=false;
static int TexCount=0;
static bool DeviceLost=false;
static DWORD FirstFrame=0;
static bool overlayToggled=false;
static bool vwaitFix=true;
static bool vwaitFixToggled=false;

static D3DPRESENT_PARAMETERS params;
static IDirect3D9* d3d9=0;
static IDirect3DDevice9* device=0;
static IDirect3DTexture9* backbuffer;
static void* bbPtr;

static DWORD renderstates[256];
static DWORD texturestates[128];

void *d3d9InterfaceQuery(REFIID a)
{
	void * v;
	d3d9->QueryInterface(a, &v);
	return v;
}

void d3d9Init(HWND win) {
	DEFINED_NOTE;
	//if(Inited) return;
	Inited=true;
	
	window=win;

	memset(renderstates, -1, 256*4);
	memset(texturestates, -1, 128*4);

	d3d9=Direct3DCreate9(D3D_SDK_VERSION);

	gWidth = 1024;
	gHeight = 768;

	ZeroMemory(&params, sizeof(params));
	params.BackBufferCount=1;
	params.BackBufferFormat=D3DFMT_X8R8G8B8;
	params.BackBufferWidth=gWidth;
	params.BackBufferHeight=gHeight;
	params.EnableAutoDepthStencil=true;
	params.AutoDepthStencilFormat=D3DFMT_D24X8;
	params.MultiSampleQuality=0;
	params.MultiSampleType=(D3DMULTISAMPLE_TYPE)0;
	params.Windowed=1;
	params.SwapEffect=D3DSWAPEFFECT_DISCARD;
	params.hDeviceWindow=window;
	params.PresentationInterval=D3DPRESENT_INTERVAL_ONE;

	if(FAILED(d3d9->CreateDevice(D3DADAPTER_DEFAULT,D3DDEVTYPE_HAL,window,D3DCREATE_HARDWARE_VERTEXPROCESSING|D3DCREATE_PUREDEVICE|
		D3DCREATE_MULTITHREADED|D3DCREATE_FPU_PRESERVE,&params,&device))) 
	{
		params.Windowed=1;
		if(FAILED(d3d9->CreateDevice(D3DADAPTER_DEFAULT,D3DDEVTYPE_HAL,window,D3DCREATE_HARDWARE_VERTEXPROCESSING|D3DCREATE_PUREDEVICE|
			D3DCREATE_MULTITHREADED|D3DCREATE_FPU_PRESERVE,&params,&device))) 
				ExitProcess(1);
	}

	/*
	ID3DXBuffer* buff;
	//D3DXCompileShaderFromFileA("effect.fx", 0, 0, "pss", "ps_2_0", 0, &buff, 0, 0);
	D3DXAssembleShader(sFunc, strlen(sFunc), 0, 0, 0, &buff, 0);
	byte bytes[1000];
	memset(bytes,0,1000);
	DWORD d=buff->GetBufferSize();
	memcpy(bytes, buff->GetBufferPointer(), d);

	char str[4096];
	char str2[10];
	strcpy(str, "static const BYTE sFunc[] = { \r\n");
	for(int i=0;i<10;i++) {
		strcat(str, "\t");
		for(int j=0;j<16;j++) {
			strcat(str, "0x");
			itoa(bytes[j+i*16], str2, 16);
			strcat(str, str2);
			strcat(str,", ");
		}
		strcat(str, "\r\n");
	}
	strcat(str, "};\r\n");

	D3DXDisassembleShader((DWORD*)bytes, false, 0, &buff);
	strcpy(str,(char*)buff->GetBufferPointer());
	*/


//	device->SetRenderState(D3DRS_LASTPIXEL, 0);
//	device->SetRenderState(D3DRS_ZFUNC, D3DRS_LESS);
	device->SetRenderState(D3DRS_LIGHTING, 0);
	device->SetRenderState(D3DRS_DITHERENABLE, 0);
	device->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
	device->SetSamplerState(1, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
	device->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_NONE);
	device->SetSamplerState(1, D3DSAMP_MIPFILTER, D3DTEXF_NONE);
	device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	device->SetSamplerState(1, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);

	/*device->SetRenderState(D3DRS_LIGHTING, 0);
	device->SetRenderState(D3DRS_FOGTABLEMODE, 1);
	device->SetRenderState(D3DRS_FOGVERTEXMODE, 0);
	device->SetRenderState(D3DRS_RANGEFOGENABLE, 0);
	device->SetRenderState(D3DRS_FOGENABLE, 1);
	float f=0;
	device->SetRenderState(D3DRS_FOGSTART, *(DWORD*)&f);
	f=1;
	device->SetRenderState(D3DRS_FOGEND, *(DWORD*)&f);*/
}
int d3d9GetUsedMem() { return TexCount*1024*16; }
void d3d9BeginScene() {
	DEFINED_NOTE;
	device->BeginScene();
	InGame=true;
	D3DLOCKED_RECT lr;
	backbuffer->LockRect(0, &lr, 0, 0);
	bbPtr=lr.pBits;
}
void* d3d9CreateTexture(int width, int height, DWORD format, DWORD type) {
	DEFINED_NOTE;
	TexCount++;
	IDirect3DTexture9* tex;
	if(!type) {
		device->CreateTexture(width, height, 1, 0, (D3DFORMAT)format, D3DPOOL_MANAGED, &tex, 0);
		backbuffer=tex;
	} else {
		device->CreateTexture(width, height, 1, 0, (D3DFORMAT)format, (type==1)?D3DPOOL_SYSTEMMEM:D3DPOOL_DEFAULT, &tex, 0);
	}
	return tex;
}
void d3d9ReleaseTexture(void* tex) {
	DEFINED_NOTE;
	TexCount--;
	((IUnknown*)tex)->Release();
}
void* d3d9Lock(void* tex, bool surf) {
	DEFINED_NOTE;
	if(surf&&InGame) { return bbPtr; }
	D3DLOCKED_RECT lr;
	((IDirect3DTexture9*)tex)->LockRect(0, &lr, 0, 0);
	return lr.pBits;
}
void d3d9Unlock(void* tex, bool surf) {
	DEFINED_NOTE;
	if(surf) {
		if(InGame) return;
		((IDirect3DTexture9*)tex)->UnlockRect(0);
		if(DeviceLost) {
			if(device->TestCooperativeLevel()==D3DERR_DEVICENOTRESET) {
				device->Reset(&params);
				for(int i=0;i<256;i++) {
					if(renderstates[i]!=-1) device->SetRenderState((D3DRENDERSTATETYPE)i, renderstates[i]);
				}
				for(int i=0;i<64;i++) {
					if(texturestates[i]!=-1) device->SetTextureStageState(0,(D3DTEXTURESTAGESTATETYPE)i, texturestates[i]);
					if(texturestates[i+64]!=-1) device->SetTextureStageState(1,(D3DTEXTURESTAGESTATETYPE)i, texturestates[i+64]);
				}
				device->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
				device->SetSamplerState(1, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
				device->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_NONE);
				device->SetSamplerState(1, D3DSAMP_MIPFILTER, D3DTEXF_NONE);
				device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
				device->SetSamplerState(1, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
				DeviceLost=false;
			} else return;
		}
		//Stops the background freezing with vwait enabled
		if(GetAsyncKeyState(VK_SCROLL)) {
			if(!vwaitFixToggled) {
				vwaitFixToggled=true;
				vwaitFix=!vwaitFix;
			}
		} else vwaitFixToggled=false;
		if(vwaitFix) {
			if(FirstFrame++ == 2) {
				FirstFrame=0;
				if(device->Present(0,0,0,0)==D3DERR_DEVICELOST) DeviceLost=true;
			}
		} else {
			if(device->Present(0,0,0,0)==D3DERR_DEVICELOST) DeviceLost=true;
		}
	} else {
		((IDirect3DTexture9*)tex)->UnlockRect(0);
	}
}
void d3d9SetGamma(const void* pRamp) {
	DEFINED_NOTE;
	device->SetGammaRamp(0,D3DSGR_NO_CALIBRATION,(D3DGAMMARAMP*)pRamp);
}

void d3d9Exit() {
	DEFINED_NOTE;
	if(!Inited) return;
	Inited=false;
	SafeRelease(device);
	SafeRelease(d3d9);
}

void d3d9SetMaterial(float* data) {
	DEFINED_NOTE;
	D3DMATERIAL9 mat;
	memcpy(&mat, data, 68);
	device->SetMaterial(&mat);
}

void d3d9SetTex(int stage, void* tex) {
	DEFINED_NOTE;
	device->SetTexture(stage,(IDirect3DTexture9*)tex);
}
void d3d9DrawPrim(DWORD type, DWORD fvf, void* ptr, DWORD count) {
	DEFINED_NOTE;
	DWORD stride;
	if(fvf==0x1c4) stride=32;
	else stride=40;
	device->SetFVF(fvf);
	switch(type) {
		case 2: count/=2; break;
		case 3: count--; break;
		case 4: count/=3; break;
		case 5: count-=2; break;
		case 6: count-=2; break;
	}
	device->DrawPrimitiveUP((D3DPRIMITIVETYPE)type,count,ptr,stride);
}
void d3d9DrawIPrim(DWORD type, DWORD fvf, void* v, void* i, DWORD verts, DWORD indicies) {
	DEFINED_NOTE;
	device->SetFVF(fvf);
	DWORD prims=indicies;
	switch(type) {
		case 2: prims/=2; break;
		case 3: prims--; break;
		case 4: prims/=3; break;
		case 5: prims-=2; break;
		case 6: prims-=2; break;
	}
	device->DrawIndexedPrimitiveUP((D3DPRIMITIVETYPE)type,0,verts,prims,i,D3DFMT_INDEX16,v,fvf==0x1c4?32:40);
}

void d3d9Present() {
	DEFINED_NOTE;
	backbuffer->UnlockRect(0);

	InGame=false;
	if(DeviceLost) return;

	device->EndScene();

	if(device->Present(0,0,0,0)==D3DERR_DEVICELOST) {
		DeviceLost=true;
		return;
	}
	device->Clear(0,0,D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER,0x0, 1, 0);
}

void d3d9SetRenderState(DWORD a, DWORD b) {
	DEFINED_NOTE;
	if(a==2||a==4||a==41||a==7||a==26) return;
	/*if(a==D3DRS_LIGHTING||a==D3DRS_FOGTABLEMODE||a==D3DRS_FOGVERTEXMODE||a==D3DRS_RANGEFOGENABLE||a==D3DRS_FOGENABLE
		||a==D3DRS_FOGSTART||a==D3DRS_FOGEND) return;
	if(a==D3DRS_FOGVERTEXMODE||a==34||a==35||a==36||a==37||a==38||a==48||a==28) {
		int iii=0;
	}*/
	if(renderstates[a]==b) return;
	//2 = antialias
	//41 = colour key
	//4 = D3DRENDERSTATE_TEXTUREPERSPECTIVE (1)
	device->SetRenderState((D3DRENDERSTATETYPE)a,b);
	renderstates[a]=b;
}

void d3d9SetTextureStageState(DWORD a, DWORD b, DWORD c) {
	DEFINED_NOTE;
	if(b==12||b==16||b==17) return;
	if(texturestates[b+(a?64:0)]==c) return;
	//12 = D3DTSS_ADDRESS (1)
	//16 = D3DTSS_MAGFILTER (2)
	//17 = D3DTSS_MINFILTER (2)
	device->SetTextureStageState(a,(D3DTEXTURESTAGESTATETYPE)b,c);
	texturestates[b+(a?64:0)]=c;
}

int d3d9GetTexPitch(void* tex) {
	DEFINED_NOTE;
	D3DLOCKED_RECT lr;
	((IDirect3DTexture9*)tex)->LockRect(0, &lr, 0, D3DLOCK_READONLY);
	((IDirect3DTexture9*)tex)->UnlockRect(0);
	return lr.Pitch;
}

void d3d9CopyTex(void* from, void* to) {
	DEFINED_NOTE;
	if(DeviceLost) return;
	device->UpdateTexture((IDirect3DTexture9*) from, (IDirect3DTexture9*)to);
}
void d3d9ResetWindow() {
	DEFINED_NOTE;
	SetWindowLong(window, GWL_STYLE, 0);
	RECT r;
	r.left=0;
	r.right=gWidth;
	r.top=0;
	r.bottom=gHeight;
	AdjustWindowRect(&r, 0, false);
	r.right-=r.left;
	r.left=0;
	r.bottom-=r.top;
	r.top=0;
	SetWindowPos(window, HWND_NOTOPMOST, 0, 0, r.right, r.bottom,SWP_SHOWWINDOW);
}