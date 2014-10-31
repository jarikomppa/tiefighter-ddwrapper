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
#include "myIDirect3DViewport.h"

myIDirect3DViewport::myIDirect3DViewport(IDirect3DViewport * aOriginal)
{
  logf("myIDirect3DViewport ctor\n");
  mOriginal = aOriginal;
}

myIDirect3DViewport::~myIDirect3DViewport()
{
  logf("myIDirect3DViewport dtor\n");
}

HRESULT __stdcall myIDirect3DViewport::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DViewport::QueryInterface(REFIID, LPVOID * 0x%x);", ppvObj);
  HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
  logfc(" -> return %d\n", x);
  pushtab();
  if (x == 0) genericQueryInterface(riid, ppvObj);
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirect3DViewport::AddRef()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DViewport::AddRef();");
  ULONG x = mOriginal->AddRef();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirect3DViewport::Release()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DViewport::Release();");
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

HRESULT __stdcall myIDirect3DViewport::Initialize(LPDIRECT3D a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DViewport::Initialize(LPDIRECT3D 0x%x);", a);
  HRESULT x = mOriginal->Initialize((a)?((myIDirect3D *)a)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DViewport::GetViewport(LPD3DVIEWPORT a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DViewport::GetViewport(LPD3DVIEWPORT 0x%x);", a);
  HRESULT x = mOriginal->GetViewport(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DViewport::SetViewport(LPD3DVIEWPORT a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DViewport::SetViewport(LPD3DVIEWPORT 0x%x);", a);
  HRESULT x = mOriginal->SetViewport(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DViewport::TransformVertices(DWORD a, LPD3DTRANSFORMDATA b, DWORD c, LPDWORD d)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DViewport::TransformVertices(DWORD %d, LPD3DTRANSFORMDATA 0x%x, DWORD %d, LPDWORD 0x%x);", a, b, c, d);
  HRESULT x = mOriginal->TransformVertices(a, b, c, d);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DViewport::LightElements(DWORD a, LPD3DLIGHTDATA b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DViewport::LightElements(DWORD %d, LPD3DLIGHTDATA 0x%x);", a, b);
  HRESULT x = mOriginal->LightElements(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DViewport::SetBackground(D3DMATERIALHANDLE a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DViewport::SetBackground(D3DMATERIALHANDLE);");
  HRESULT x = mOriginal->SetBackground(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DViewport::GetBackground(LPD3DMATERIALHANDLE a, LPBOOL b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DViewport::GetBackground(LPD3DMATERIALHANDLE 0x%x, LPBOOL 0x%x);", a, b);
  HRESULT x = mOriginal->GetBackground(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DViewport::SetBackgroundDepth(LPDIRECTDRAWSURFACE a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DViewport::SetBackgroundDepth(LPDIRECTDRAWSURFACE 0x%x);", a);
  HRESULT x = mOriginal->SetBackgroundDepth((a)?((myIDirectDrawSurface *)a)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DViewport::GetBackgroundDepth(LPDIRECTDRAWSURFACE * a, LPBOOL b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DViewport::GetBackgroundDepth(LPDIRECTDRAWSURFACE * 0x%x, LPBOOL 0x%x);", a, b);
  HRESULT x = mOriginal->GetBackgroundDepth(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  myIDirectDrawSurface * n = (myIDirectDrawSurface *)wrapfetch(*a);
  if (n == NULL && *a != NULL)
  {
    n = (myIDirectDrawSurface *)new myIDirectDrawSurface(*a);
    wrapstore(n, *a);
    logf("Wrapped.\n");
  }
  *a = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DViewport::Clear(DWORD a, LPD3DRECT b, DWORD c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DViewport::Clear(DWORD %d, LPD3DRECT 0x%x, DWORD %d);", a, b, c);
  HRESULT x = mOriginal->Clear(a, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DViewport::AddLight(LPDIRECT3DLIGHT a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DViewport::AddLight(LPDIRECT3DLIGHT 0x%x);", a);
  HRESULT x = mOriginal->AddLight((a)?((myIDirect3DLight *)a)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DViewport::DeleteLight(LPDIRECT3DLIGHT a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DViewport::DeleteLight(LPDIRECT3DLIGHT 0x%x);", a);
  HRESULT x = mOriginal->DeleteLight((a)?((myIDirect3DLight *)a)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DViewport::NextLight(LPDIRECT3DLIGHT a, LPDIRECT3DLIGHT * b, DWORD c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DViewport::NextLight(LPDIRECT3DLIGHT 0x%x, LPDIRECT3DLIGHT * 0x%x, DWORD %d);", a, b, c);
  HRESULT x = mOriginal->NextLight((a)?((myIDirect3DLight *)a)->mOriginal:0, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  myIDirect3DLight * n = (myIDirect3DLight *)wrapfetch(*b);
  if (n == NULL && *b != NULL)
  {
    n = (myIDirect3DLight *)new myIDirect3DLight(*b);
    wrapstore(n, *b);
    logf("Wrapped.\n");
  }
  *b = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

