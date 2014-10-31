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
#include "myIDirect3D7.h"

myIDirect3D7::myIDirect3D7(IDirect3D7 * aOriginal)
{
  logf("myIDirect3D7 ctor\n");
  mOriginal = aOriginal;
}

myIDirect3D7::~myIDirect3D7()
{
  logf("myIDirect3D7 dtor\n");
}

HRESULT __stdcall myIDirect3D7::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D7::QueryInterface(REFIID, LPVOID * 0x%x);", ppvObj);
  HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
  logfc(" -> return %d\n", x);
  pushtab();
  if (x == 0) genericQueryInterface(riid, ppvObj);
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirect3D7::AddRef()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D7::AddRef();");
  ULONG x = mOriginal->AddRef();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirect3D7::Release()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D7::Release();");
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

HRESULT __stdcall myIDirect3D7::EnumDevices(LPD3DENUMDEVICESCALLBACK7 a, LPVOID b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D7::EnumDevices(LPD3DENUMDEVICESCALLBACK7 0x%x, LPVOID 0x%x);", a, b);
  HRESULT x = mOriginal->EnumDevices(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3D7::CreateDevice(REFCLSID a, LPDIRECTDRAWSURFACE7 b, LPDIRECT3DDEVICE7 * c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D7::CreateDevice(REFCLSID, LPDIRECTDRAWSURFACE7 0x%x, LPDIRECT3DDEVICE7 * 0x%x);", b, c);
  HRESULT x = mOriginal->CreateDevice(a, (b)?((myIDirectDrawSurface7 *)b)->mOriginal:0, c);
  logfc(" -> return %d\n", x);
  pushtab();
  myIDirect3DDevice7 * n = (myIDirect3DDevice7 *)wrapfetch(*c);
  if (n == NULL && *c != NULL)
  {
    n = (myIDirect3DDevice7 *)new myIDirect3DDevice7(*c);
    wrapstore(n, *c);
    logf("Wrapped.\n");
  }
  *c = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3D7::CreateVertexBuffer(LPD3DVERTEXBUFFERDESC a, LPDIRECT3DVERTEXBUFFER7 * b, DWORD c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D7::CreateVertexBuffer(LPD3DVERTEXBUFFERDESC 0x%x, LPDIRECT3DVERTEXBUFFER7 * 0x%x, DWORD %d);", a, b, c);
  HRESULT x = mOriginal->CreateVertexBuffer(a, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  myIDirect3DVertexBuffer7 * n = (myIDirect3DVertexBuffer7 *)wrapfetch(*b);
  if (n == NULL && *b != NULL)
  {
    n = (myIDirect3DVertexBuffer7 *)new myIDirect3DVertexBuffer7(*b);
    wrapstore(n, *b);
    logf("Wrapped.\n");
  }
  *b = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3D7::EnumZBufferFormats(REFCLSID a, LPD3DENUMPIXELFORMATSCALLBACK b, LPVOID c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D7::EnumZBufferFormats(REFCLSID, LPD3DENUMPIXELFORMATSCALLBACK 0x%x, LPVOID 0x%x);", b, c);
  HRESULT x = mOriginal->EnumZBufferFormats(a, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3D7::EvictManagedTextures()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3D7::EvictManagedTextures();");
  HRESULT x = mOriginal->EvictManagedTextures();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

