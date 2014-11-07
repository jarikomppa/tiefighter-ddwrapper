// Generated with:
// ddwrappergen 1.130524 (c)2013 Jari Komppa http://iki.fi/sol/
//
// If you wish to use the generator, don't do manual changes to this file
// This is your first and only warning.
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
// 
// 1. The origin of this software must not be misrepresented; you must not
// claim that you wrote the original software. If you use this software
// in a product, an acknowledgment in the product documentation would be
// appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not be
// misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source
// distribution.

#include "wrapper.h"
#include "myIDirect3D.h"

myIDirect3D::myIDirect3D(IDirect3D * aOriginal)
{
  logf("myIDirect3D ctor\n");
  mOriginal = aOriginal;
}

myIDirect3D::~myIDirect3D()
{
  logf("myIDirect3D dtor\n");
}

HRESULT __stdcall myIDirect3D::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D::QueryInterface(REFIID, LPVOID * 0x%x);", ppvObj);
  HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
  logfc(" -> return %d\n", x);
  pushtab();
  if (x == 0) genericQueryInterface(riid, ppvObj);
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirect3D::AddRef()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D::AddRef();");
  ULONG x = mOriginal->AddRef();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirect3D::Release()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D::Release();");
#ifdef PASSTHROUGH_WRAPPER
  ULONG x = mOriginal->Release();
#else
  ULONG x = 0;
#endif
  logfc(" -> return %d\n", x);
  pushtab();
  if (x == 0)
  {
    wrapstore(mOriginal, 0);
    mOriginal = NULL;
    delete this;
  }
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3D::Initialize(REFCLSID a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D::Initialize(REFCLSID);");
  HRESULT x = mOriginal->Initialize(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

extern GUID gFakeDeviceGuid;


HRESULT __stdcall myIDirect3D::EnumDevices(LPD3DENUMDEVICESCALLBACK a, LPVOID b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D::EnumDevices(LPD3DENUMDEVICESCALLBACK 0x%x, LPVOID 0x%x);", a, b);
#ifdef PASSTHROUGH_WRAPPER
  HRESULT x = mOriginal->EnumDevices(a, b);
#else
  HRESULT x = 0;
  char * dd = "ddwrapper fake device";
  char * dn = "ddwrapper";
  D3DDEVICEDESC d3ddd;
  d3ddd.dwSize = sizeof(D3DDEVICEDESC);
  d3ddd.dwFlags = 
	  D3DDD_COLORMODEL |           
	  D3DDD_DEVCAPS     |         
	  D3DDD_TRANSFORMCAPS|        
	  D3DDD_LIGHTINGCAPS  |       
	  D3DDD_BCLIPPING      |      
	  D3DDD_LINECAPS        |     
	  D3DDD_TRICAPS          |    
	  D3DDD_DEVICERENDERBITDEPTH  |
	  D3DDD_DEVICEZBUFFERBITDEPTH |
	  D3DDD_MAXBUFFERSIZE        |
	  D3DDD_MAXVERTEXCOUNT       ;

  d3ddd.dcmColorModel = D3DCOLOR_RGB;
  d3ddd.dwDevCaps = D3DDEVCAPS_FLOATTLVERTEX | D3DDEVCAPS_EXECUTESYSTEMMEMORY | D3DDEVCAPS_TLVERTEXSYSTEMMEMORY | D3DDEVCAPS_TLVERTEXVIDEOMEMORY | D3DDEVCAPS_TEXTURESYSTEMMEMORY | D3DDEVCAPS_TEXTUREVIDEOMEMORY | D3DDEVCAPS_DRAWPRIMTLVERTEX | D3DDEVCAPS_CANRENDERAFTERFLIP | D3DDEVCAPS_TEXTURENONLOCALVIDMEM | D3DDEVCAPS_HWRASTERIZATION | D3DDEVCAPS_CANBLTSYSTONONLOCAL | D3DDEVCAPS_DRAWPRIMTLVERTEX | D3DDEVCAPS_DRAWPRIMITIVES2 | D3DDEVCAPS_DRAWPRIMITIVES2EX | D3DDEVCAPS_HWTRANSFORMANDLIGHT;
  d3ddd.dtcTransformCaps.dwSize = sizeof(D3DTRANSFORMCAPS);
  d3ddd.dtcTransformCaps.dwCaps = D3DTRANSFORMCAPS_CLIP;
  d3ddd.bClipping = 1;
  d3ddd.dlcLightingCaps.dwSize = sizeof(D3DLIGHTINGCAPS);
  d3ddd.dlcLightingCaps.dwNumLights = 16;
  d3ddd.dlcLightingCaps.dwLightingModel = D3DLIGHTINGMODEL_RGB;
  d3ddd.dlcLightingCaps.dwCaps = D3DLIGHTCAPS_POINT | D3DLIGHTCAPS_SPOT | D3DLIGHTCAPS_DIRECTIONAL;
  d3ddd.dpcLineCaps.dwSize = sizeof(D3DPRIMCAPS);
  
  d3ddd.dpcLineCaps.dwMiscCaps =                  /* Capability flags */
	  D3DPMISCCAPS_CULLNONE |
		D3DPMISCCAPS_CULLCW |
		D3DPMISCCAPS_CULLCCW;

  d3ddd.dpcLineCaps.dwRasterCaps = 0;
  d3ddd.dpcLineCaps.dwZCmpCaps = 
		D3DPCMPCAPS_NEVER |
		D3DPCMPCAPS_LESS |
		D3DPCMPCAPS_EQUAL |
		D3DPCMPCAPS_LESSEQUAL |
		D3DPCMPCAPS_GREATER |
		D3DPCMPCAPS_NOTEQUAL |
		D3DPCMPCAPS_GREATEREQUAL |
		D3DPCMPCAPS_ALWAYS;

  d3ddd.dpcLineCaps.dwSrcBlendCaps = 0;
  d3ddd.dpcLineCaps.dwDestBlendCaps = 0;
  d3ddd.dpcLineCaps.dwAlphaCmpCaps = 
		D3DPCMPCAPS_NEVER |
		D3DPCMPCAPS_LESS |
		D3DPCMPCAPS_EQUAL |
		D3DPCMPCAPS_LESSEQUAL |
		D3DPCMPCAPS_GREATER |
		D3DPCMPCAPS_NOTEQUAL |
		D3DPCMPCAPS_GREATEREQUAL |
		D3DPCMPCAPS_ALWAYS;

  d3ddd.dpcLineCaps.dwShadeCaps = 
	D3DPSHADECAPS_COLORFLATRGB |
		D3DPSHADECAPS_COLORGOURAUDRGB |
		D3DPSHADECAPS_COLORPHONGRGB |
		D3DPSHADECAPS_SPECULARFLATRGB |
		D3DPSHADECAPS_SPECULARGOURAUDRGB |
		D3DPSHADECAPS_SPECULARPHONGRGB |
		D3DPSHADECAPS_ALPHAFLATBLEND |
		D3DPSHADECAPS_ALPHAFLATSTIPPLED |
		D3DPSHADECAPS_ALPHAGOURAUDBLEND |
		D3DPSHADECAPS_ALPHAGOURAUDSTIPPLED |
		D3DPSHADECAPS_ALPHAPHONGBLEND |
		D3DPSHADECAPS_ALPHAPHONGSTIPPLED;

  d3ddd.dpcLineCaps.dwTextureCaps = 
		D3DPTEXTURECAPS_PERSPECTIVE |
		D3DPTEXTURECAPS_ALPHA;

  d3ddd.dpcLineCaps.dwTextureFilterCaps =
		D3DPTFILTERCAPS_NEAREST |
		D3DPTFILTERCAPS_LINEAR |
		D3DPTFILTERCAPS_MIPNEAREST |
		D3DPTFILTERCAPS_MIPLINEAR |
		D3DPTFILTERCAPS_LINEARMIPNEAREST |
		D3DPTFILTERCAPS_LINEARMIPLINEAR;

  d3ddd.dpcLineCaps.dwTextureBlendCaps =
		D3DPBLENDCAPS_ZERO |
		D3DPBLENDCAPS_ONE |
		D3DPBLENDCAPS_SRCCOLOR |
		D3DPBLENDCAPS_INVSRCCOLOR |
		D3DPBLENDCAPS_SRCALPHA |
		D3DPBLENDCAPS_INVSRCALPHA |
		D3DPBLENDCAPS_DESTALPHA |
		D3DPBLENDCAPS_INVDESTALPHA |
		D3DPBLENDCAPS_DESTCOLOR |
		D3DPBLENDCAPS_INVDESTCOLOR |
		D3DPBLENDCAPS_SRCALPHASAT |
		D3DPBLENDCAPS_BOTHSRCALPHA |
		D3DPBLENDCAPS_BOTHINVSRCALPHA;

  d3ddd.dpcLineCaps.dwTextureAddressCaps =
		D3DPTADDRESSCAPS_WRAP |
		D3DPTADDRESSCAPS_MIRROR |
		D3DPTADDRESSCAPS_CLAMP |
		D3DPTADDRESSCAPS_BORDER |
		D3DPTADDRESSCAPS_INDEPENDENTUV;

  d3ddd.dpcLineCaps.dwStippleWidth = 0; 
  d3ddd.dpcLineCaps.dwStippleHeight = 0;
  d3ddd.dpcTriCaps = d3ddd.dpcLineCaps;
  d3ddd.dwDeviceRenderBitDepth = DDBD_32; // something the game might believe..
  d3ddd.dwDeviceZBufferBitDepth = DDBD_32;
  d3ddd.dwMaxBufferSize = 0;
  d3ddd.dwMaxVertexCount = 0xffff;
  
  a(&gFakeDeviceGuid, dd, dn, &d3ddd, &d3ddd, b);
#endif
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3D::CreateLight(LPDIRECT3DLIGHT * a, IUnknown * b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D::CreateLight(LPDIRECT3DLIGHT * 0x%x, IUnknown *);", a);
  HRESULT x = mOriginal->CreateLight(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  myIDirect3DLight * n = (myIDirect3DLight *)wrapfetch(*a);
  if (n == NULL && *a != NULL)
  {
    n = (myIDirect3DLight *)new myIDirect3DLight(*a);
    wrapstore(n, *a);
    logf("Wrapped.\n");
  }
  *a = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3D::CreateMaterial(LPDIRECT3DMATERIAL * a, IUnknown * b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D::CreateMaterial(LPDIRECT3DMATERIAL * 0x%x, IUnknown *);", a);
  HRESULT x = mOriginal->CreateMaterial(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  myIDirect3DMaterial * n = (myIDirect3DMaterial *)wrapfetch(*a);
  if (n == NULL && *a != NULL)
  {
    n = (myIDirect3DMaterial *)new myIDirect3DMaterial(*a);
    wrapstore(n, *a);
    logf("Wrapped.\n");
  }
  *a = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3D::CreateViewport(LPDIRECT3DVIEWPORT * a, IUnknown * b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D::CreateViewport(LPDIRECT3DVIEWPORT * 0x%x, IUnknown *);", a);
#ifdef PASSTHROUGH_WRAPPER
  HRESULT x = mOriginal->CreateViewport(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  myIDirect3DViewport * n = (myIDirect3DViewport *)wrapfetch(*a);
  if (n == NULL && *a != NULL)
  {
    n = (myIDirect3DViewport *)new myIDirect3DViewport(*a);
    wrapstore(n, *a);
    logf("Wrapped.\n");
  }
  *a = n;
  poptab();
#else
  HRESULT x = 0;
  logfc(" -> return %d\n", x);
  pushtab();
  myIDirect3DViewport *n = (myIDirect3DViewport *)new myIDirect3DViewport(*a);
    wrapstore(n, *a);
    logf("Wrapped.\n");
  *a = n;
  poptab();
#endif
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3D::FindDevice(LPD3DFINDDEVICESEARCH a, LPD3DFINDDEVICERESULT b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D::FindDevice(LPD3DFINDDEVICESEARCH 0x%x, LPD3DFINDDEVICERESULT 0x%x);", a, b);
  HRESULT x = mOriginal->FindDevice(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

