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
#include "myIDirect3D3.h"

myIDirect3D3::myIDirect3D3(IDirect3D3 * aOriginal)
{
  logf("myIDirect3D3 ctor\n");
  mOriginal = aOriginal;
}

myIDirect3D3::~myIDirect3D3()
{
  logf("myIDirect3D3 dtor\n");
}

HRESULT __stdcall myIDirect3D3::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D3::QueryInterface(REFIID, LPVOID * 0x%x);", ppvObj);
  HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
  logfc(" -> return %d\n", x);
  pushtab();
  if (x == 0) genericQueryInterface(riid, ppvObj);
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirect3D3::AddRef()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D3::AddRef();");
  ULONG x = mOriginal->AddRef();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirect3D3::Release()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D3::Release();");
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

HRESULT __stdcall myIDirect3D3::EnumDevices(LPD3DENUMDEVICESCALLBACK a, LPVOID b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D3::EnumDevices(LPD3DENUMDEVICESCALLBACK 0x%x, LPVOID 0x%x);", a, b);
  HRESULT x = mOriginal->EnumDevices(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3D3::CreateLight(LPDIRECT3DLIGHT * a, LPUNKNOWN b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D3::CreateLight(LPDIRECT3DLIGHT * 0x%x, LPUNKNOWN 0x%x);", a, b);
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

HRESULT __stdcall myIDirect3D3::CreateMaterial(LPDIRECT3DMATERIAL3 * a, LPUNKNOWN b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D3::CreateMaterial(LPDIRECT3DMATERIAL3 * 0x%x, LPUNKNOWN 0x%x);", a, b);
  HRESULT x = mOriginal->CreateMaterial(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  myIDirect3DMaterial3 * n = (myIDirect3DMaterial3 *)wrapfetch(*a);
  if (n == NULL && *a != NULL)
  {
    n = (myIDirect3DMaterial3 *)new myIDirect3DMaterial3(*a);
    wrapstore(n, *a);
    logf("Wrapped.\n");
  }
  *a = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3D3::CreateViewport(LPDIRECT3DVIEWPORT3 * a, LPUNKNOWN b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D3::CreateViewport(LPDIRECT3DVIEWPORT3 * 0x%x, LPUNKNOWN 0x%x);", a, b);
  HRESULT x = mOriginal->CreateViewport(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  myIDirect3DViewport3 * n = (myIDirect3DViewport3 *)wrapfetch(*a);
  if (n == NULL && *a != NULL)
  {
    n = (myIDirect3DViewport3 *)new myIDirect3DViewport3(*a);
    wrapstore(n, *a);
    logf("Wrapped.\n");
  }
  *a = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3D3::FindDevice(LPD3DFINDDEVICESEARCH a, LPD3DFINDDEVICERESULT b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D3::FindDevice(LPD3DFINDDEVICESEARCH 0x%x, LPD3DFINDDEVICERESULT 0x%x);", a, b);
  HRESULT x = mOriginal->FindDevice(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3D3::CreateDevice(REFCLSID a, LPDIRECTDRAWSURFACE4 b, LPDIRECT3DDEVICE3 * c, LPUNKNOWN d)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D3::CreateDevice(REFCLSID, LPDIRECTDRAWSURFACE4 0x%x, LPDIRECT3DDEVICE3 * 0x%x, LPUNKNOWN 0x%x);", b, c, d);
  HRESULT x = mOriginal->CreateDevice(a, (b)?((myIDirectDrawSurface4 *)b)->mOriginal:0, c, d);
  logfc(" -> return %d\n", x);
  pushtab();
  myIDirect3DDevice3 * n = (myIDirect3DDevice3 *)wrapfetch(*c);
  if (n == NULL && *c != NULL)
  {
    n = (myIDirect3DDevice3 *)new myIDirect3DDevice3(*c);
    wrapstore(n, *c);
    logf("Wrapped.\n");
  }
  *c = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3D3::CreateVertexBuffer(LPD3DVERTEXBUFFERDESC a, LPDIRECT3DVERTEXBUFFER * b, DWORD c, LPUNKNOWN d)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D3::CreateVertexBuffer(LPD3DVERTEXBUFFERDESC 0x%x, LPDIRECT3DVERTEXBUFFER * 0x%x, DWORD %d, LPUNKNOWN 0x%x);", a, b, c, d);
  HRESULT x = mOriginal->CreateVertexBuffer(a, b, c, d);
  logfc(" -> return %d\n", x);
  pushtab();
  myIDirect3DVertexBuffer * n = (myIDirect3DVertexBuffer *)wrapfetch(*b);
  if (n == NULL && *b != NULL)
  {
    n = (myIDirect3DVertexBuffer *)new myIDirect3DVertexBuffer(*b);
    wrapstore(n, *b);
    logf("Wrapped.\n");
  }
  *b = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3D3::EnumZBufferFormats(REFCLSID a, LPD3DENUMPIXELFORMATSCALLBACK b, LPVOID c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D3::EnumZBufferFormats(REFCLSID, LPD3DENUMPIXELFORMATSCALLBACK 0x%x, LPVOID 0x%x);", b, c);
  HRESULT x = mOriginal->EnumZBufferFormats(a, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3D3::EvictManagedTextures()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D3::EvictManagedTextures();");
  HRESULT x = mOriginal->EvictManagedTextures();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

