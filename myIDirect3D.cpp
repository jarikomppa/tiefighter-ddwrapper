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
  ULONG x = mOriginal->Release();
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
  d3ddd.dwFlags = 0xffffffff;
  d3ddd.dcmColorModel = D3DCOLOR_RGB | D3DCOLOR_MONO;
  d3ddd.dwDevCaps = D3DDEVCAPS_FLOATTLVERTEX | D3DDEVCAPS_EXECUTESYSTEMMEMORY | D3DDEVCAPS_TLVERTEXSYSTEMMEMORY | D3DDEVCAPS_TLVERTEXVIDEOMEMORY | D3DDEVCAPS_TEXTURESYSTEMMEMORY | D3DDEVCAPS_TEXTUREVIDEOMEMORY | D3DDEVCAPS_DRAWPRIMTLVERTEX | D3DDEVCAPS_CANRENDERAFTERFLIP | D3DDEVCAPS_TEXTURENONLOCALVIDMEM | D3DDEVCAPS_HWRASTERIZATION | D3DDEVCAPS_CANBLTSYSTONONLOCAL | D3DDEVCAPS_DRAWPRIMTLVERTEX | D3DDEVCAPS_DRAWPRIMITIVES2 | D3DDEVCAPS_DRAWPRIMITIVES2EX | D3DDEVCAPS_HWTRANSFORMANDLIGHT;
  d3ddd.dtcTransformCaps.dwSize = sizeof(D3DTRANSFORMCAPS);
  d3ddd.dtcTransformCaps.dwCaps = D3DTRANSFORMCAPS_CLIP;
  d3ddd.bClipping = 1;
  d3ddd.dlcLightingCaps.dwSize = sizeof(D3DLIGHTINGCAPS);
  d3ddd.dlcLightingCaps.dwNumLights = 16;
  d3ddd.dlcLightingCaps.dwLightingModel = D3DLIGHTINGMODEL_RGB;
  d3ddd.dlcLightingCaps.dwCaps = D3DLIGHTCAPS_POINT | D3DLIGHTCAPS_SPOT | D3DLIGHTCAPS_DIRECTIONAL;
  memset(&d3ddd.dpcLineCaps,0xff,sizeof(D3DPRIMCAPS));
  memset(&d3ddd.dpcTriCaps,0xff,sizeof(D3DPRIMCAPS));
  d3ddd.dpcLineCaps.dwSize = sizeof(D3DPRIMCAPS);
  d3ddd.dpcTriCaps.dwSize = sizeof(D3DPRIMCAPS);
  d3ddd.dwDeviceRenderBitDepth = DDBD_16; // something the game might believe..
  d3ddd.dwDeviceZBufferBitDepth = DDBD_16;
  d3ddd.dwMaxBufferSize = 0xfffe; // "must be set to zero". We'll see about that.
  d3ddd.dwMaxVertexCount = 0xfffe;
  
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

