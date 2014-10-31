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
#include "myIDirect3D2.h"

myIDirect3D2::myIDirect3D2(IDirect3D2 * aOriginal)
{
  logf("myIDirect3D2 ctor\n");
  mOriginal = aOriginal;
}

myIDirect3D2::~myIDirect3D2()
{
  logf("myIDirect3D2 dtor\n");
}

HRESULT __stdcall myIDirect3D2::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D2::QueryInterface(REFIID, LPVOID * 0x%x);", ppvObj);
  HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
  logfc(" -> return %d\n", x);
  pushtab();
  if (x == 0) genericQueryInterface(riid, ppvObj);
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirect3D2::AddRef()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D2::AddRef();");
  ULONG x = mOriginal->AddRef();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirect3D2::Release()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D2::Release();");
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

HRESULT __stdcall myIDirect3D2::EnumDevices(LPD3DENUMDEVICESCALLBACK a, LPVOID b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D2::EnumDevices(LPD3DENUMDEVICESCALLBACK 0x%x, LPVOID 0x%x);", a, b);
  HRESULT x = mOriginal->EnumDevices(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3D2::CreateLight(LPDIRECT3DLIGHT * a, IUnknown * b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D2::CreateLight(LPDIRECT3DLIGHT * 0x%x, IUnknown *);", a);
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

HRESULT __stdcall myIDirect3D2::CreateMaterial(LPDIRECT3DMATERIAL2 * a, IUnknown * b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D2::CreateMaterial(LPDIRECT3DMATERIAL2 * 0x%x, IUnknown *);", a);
  HRESULT x = mOriginal->CreateMaterial(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  myIDirect3DMaterial2 * n = (myIDirect3DMaterial2 *)wrapfetch(*a);
  if (n == NULL && *a != NULL)
  {
    n = (myIDirect3DMaterial2 *)new myIDirect3DMaterial2(*a);
    wrapstore(n, *a);
    logf("Wrapped.\n");
  }
  *a = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3D2::CreateViewport(LPDIRECT3DVIEWPORT2 * a, IUnknown * b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D2::CreateViewport(LPDIRECT3DVIEWPORT2 * 0x%x, IUnknown *);", a);
  HRESULT x = mOriginal->CreateViewport(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  myIDirect3DViewport2 * n = (myIDirect3DViewport2 *)wrapfetch(*a);
  if (n == NULL && *a != NULL)
  {
    n = (myIDirect3DViewport2 *)new myIDirect3DViewport2(*a);
    wrapstore(n, *a);
    logf("Wrapped.\n");
  }
  *a = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3D2::FindDevice(LPD3DFINDDEVICESEARCH a, LPD3DFINDDEVICERESULT b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D2::FindDevice(LPD3DFINDDEVICESEARCH 0x%x, LPD3DFINDDEVICERESULT 0x%x);", a, b);
  HRESULT x = mOriginal->FindDevice(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3D2::CreateDevice(REFCLSID a, LPDIRECTDRAWSURFACE b, LPDIRECT3DDEVICE2 * c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D2::CreateDevice(REFCLSID, LPDIRECTDRAWSURFACE 0x%x, LPDIRECT3DDEVICE2 * 0x%x);", b, c);
  HRESULT x = mOriginal->CreateDevice(a, (b)?((myIDirectDrawSurface *)b)->mOriginal:0, c);
  logfc(" -> return %d\n", x);
  pushtab();
  myIDirect3DDevice2 * n = (myIDirect3DDevice2 *)wrapfetch(*c);
  if (n == NULL && *c != NULL)
  {
    n = (myIDirect3DDevice2 *)new myIDirect3DDevice2(*c);
    wrapstore(n, *c);
    logf("Wrapped.\n");
  }
  *c = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

