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
#include "myIDirect3DDevice.h"

myIDirect3DDevice::myIDirect3DDevice(IDirect3DDevice * aOriginal)
{
  logf("myIDirect3DDevice ctor\n");
  mOriginal = aOriginal;
}

myIDirect3DDevice::~myIDirect3DDevice()
{
  logf("myIDirect3DDevice dtor\n");
}

HRESULT __stdcall myIDirect3DDevice::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice::QueryInterface(REFIID, LPVOID * 0x%x);", ppvObj);
  HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
  logfc(" -> return %d\n", x);
  pushtab();
  if (x == 0) genericQueryInterface(riid, ppvObj);
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirect3DDevice::AddRef()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice::AddRef();");
  ULONG x = mOriginal->AddRef();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirect3DDevice::Release()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice::Release();");
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

HRESULT __stdcall myIDirect3DDevice::Initialize(LPDIRECT3D a, LPGUID b, LPD3DDEVICEDESC c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice::Initialize(LPDIRECT3D 0x%x, LPGUID 0x%x, LPD3DDEVICEDESC 0x%x);", a, b, c);
  HRESULT x = mOriginal->Initialize((a)?((myIDirect3D *)a)->mOriginal:0, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice::GetCaps(LPD3DDEVICEDESC a, LPD3DDEVICEDESC b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice::GetCaps(LPD3DDEVICEDESC 0x%x, LPD3DDEVICEDESC 0x%x);", a, b);
  HRESULT x = mOriginal->GetCaps(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice::SwapTextureHandles(LPDIRECT3DTEXTURE a, LPDIRECT3DTEXTURE b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice::SwapTextureHandles(LPDIRECT3DTEXTURE 0x%x, LPDIRECT3DTEXTURE 0x%x);", a, b);
  HRESULT x = mOriginal->SwapTextureHandles((a)?((myIDirect3DTexture *)a)->mOriginal:0, (b)?((myIDirect3DTexture *)b)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice::CreateExecuteBuffer(LPD3DEXECUTEBUFFERDESC a, LPDIRECT3DEXECUTEBUFFER * b, IUnknown * c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice::CreateExecuteBuffer(LPD3DEXECUTEBUFFERDESC 0x%x, LPDIRECT3DEXECUTEBUFFER * 0x%x, IUnknown *);", a, b);
  HRESULT x = mOriginal->CreateExecuteBuffer(a, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  myIDirect3DExecuteBuffer * n = (myIDirect3DExecuteBuffer *)wrapfetch(*b);
  if (n == NULL && *b != NULL)
  {
    n = (myIDirect3DExecuteBuffer *)new myIDirect3DExecuteBuffer(*b);
    wrapstore(n, *b);
    logf("Wrapped.\n");
  }
  *b = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice::GetStats(LPD3DSTATS a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice::GetStats(LPD3DSTATS 0x%x);", a);
  HRESULT x = mOriginal->GetStats(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice::Execute(LPDIRECT3DEXECUTEBUFFER a, LPDIRECT3DVIEWPORT b, DWORD c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice::Execute(LPDIRECT3DEXECUTEBUFFER 0x%x, LPDIRECT3DVIEWPORT 0x%x, DWORD %d);", a, b, c);
  HRESULT x = mOriginal->Execute((a)?((myIDirect3DExecuteBuffer *)a)->mOriginal:0, (b)?((myIDirect3DViewport *)b)->mOriginal:0, c);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice::AddViewport(LPDIRECT3DVIEWPORT a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice::AddViewport(LPDIRECT3DVIEWPORT 0x%x);", a);
  HRESULT x = mOriginal->AddViewport((a)?((myIDirect3DViewport *)a)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice::DeleteViewport(LPDIRECT3DVIEWPORT a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice::DeleteViewport(LPDIRECT3DVIEWPORT 0x%x);", a);
  HRESULT x = mOriginal->DeleteViewport((a)?((myIDirect3DViewport *)a)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice::NextViewport(LPDIRECT3DVIEWPORT a, LPDIRECT3DVIEWPORT * b, DWORD c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice::NextViewport(LPDIRECT3DVIEWPORT 0x%x, LPDIRECT3DVIEWPORT * 0x%x, DWORD %d);", a, b, c);
  HRESULT x = mOriginal->NextViewport((a)?((myIDirect3DViewport *)a)->mOriginal:0, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  myIDirect3DViewport * n = (myIDirect3DViewport *)wrapfetch(*b);
  if (n == NULL && *b != NULL)
  {
    n = (myIDirect3DViewport *)new myIDirect3DViewport(*b);
    wrapstore(n, *b);
    logf("Wrapped.\n");
  }
  *b = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice::Pick(LPDIRECT3DEXECUTEBUFFER a, LPDIRECT3DVIEWPORT b, DWORD c, LPD3DRECT d)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice::Pick(LPDIRECT3DEXECUTEBUFFER 0x%x, LPDIRECT3DVIEWPORT 0x%x, DWORD %d, LPD3DRECT 0x%x);", a, b, c, d);
  HRESULT x = mOriginal->Pick((a)?((myIDirect3DExecuteBuffer *)a)->mOriginal:0, (b)?((myIDirect3DViewport *)b)->mOriginal:0, c, d);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice::GetPickRecords(LPDWORD a, LPD3DPICKRECORD b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice::GetPickRecords(LPDWORD 0x%x, LPD3DPICKRECORD 0x%x);", a, b);
  HRESULT x = mOriginal->GetPickRecords(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice::EnumTextureFormats(LPD3DENUMTEXTUREFORMATSCALLBACK a, LPVOID b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice::EnumTextureFormats(LPD3DENUMTEXTUREFORMATSCALLBACK 0x%x, LPVOID 0x%x);", a, b);
  HRESULT x = mOriginal->EnumTextureFormats(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice::CreateMatrix(LPD3DMATRIXHANDLE a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice::CreateMatrix(LPD3DMATRIXHANDLE 0x%x);", a);
  HRESULT x = mOriginal->CreateMatrix(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice::SetMatrix(D3DMATRIXHANDLE a, const LPD3DMATRIX b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice::SetMatrix(D3DMATRIXHANDLE, const LPD3DMATRIX);");
  HRESULT x = mOriginal->SetMatrix(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice::GetMatrix(D3DMATRIXHANDLE a, LPD3DMATRIX b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice::GetMatrix(D3DMATRIXHANDLE, LPD3DMATRIX 0x%x);", b);
  HRESULT x = mOriginal->GetMatrix(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice::DeleteMatrix(D3DMATRIXHANDLE a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice::DeleteMatrix(D3DMATRIXHANDLE);");
  HRESULT x = mOriginal->DeleteMatrix(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice::BeginScene()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice::BeginScene();");
  HRESULT x = mOriginal->BeginScene();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice::EndScene()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice::EndScene();");
  HRESULT x = mOriginal->EndScene();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice::GetDirect3D(LPDIRECT3D * a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice::GetDirect3D(LPDIRECT3D * 0x%x);", a);
  HRESULT x = mOriginal->GetDirect3D(a);
  logfc(" -> return %d\n", x);
  pushtab();
  LPDIRECT3D n = (LPDIRECT3D)wrapfetch(*a);
  if (n == NULL && *a != NULL)
  {
    n = (LPDIRECT3D)new myIDirect3D(*a);
    wrapstore(n, *a);
    logf("Wrapped.\n");
  }
  *a = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

