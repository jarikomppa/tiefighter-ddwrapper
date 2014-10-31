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
#include "myIDirectDrawSurface3.h"

myIDirectDrawSurface3::myIDirectDrawSurface3(IDirectDrawSurface3 * aOriginal)
{
  logf("myIDirectDrawSurface3 ctor\n");
  mOriginal = aOriginal;
}

myIDirectDrawSurface3::~myIDirectDrawSurface3()
{
  logf("myIDirectDrawSurface3 dtor\n");
}

HRESULT __stdcall myIDirectDrawSurface3::QueryInterface(REFIID riid, LPVOID FAR * ppvObj)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::QueryInterface(REFIID, LPVOID FAR * 0x%x);", ppvObj);
  HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
  logfc(" -> return %d\n", x);
  pushtab();
  if (x == 0) genericQueryInterface(riid, ppvObj);
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirectDrawSurface3::AddRef()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::AddRef();");
  ULONG x = mOriginal->AddRef();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirectDrawSurface3::Release()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::Release();");
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

HRESULT __stdcall myIDirectDrawSurface3::AddAttachedSurface(LPDIRECTDRAWSURFACE3 a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::AddAttachedSurface(LPDIRECTDRAWSURFACE3 0x%x);", a);
  HRESULT x = mOriginal->AddAttachedSurface((a)?((myIDirectDrawSurface3 *)a)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::AddOverlayDirtyRect(LPRECT a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::AddOverlayDirtyRect(LPRECT 0x%x);", a);
  HRESULT x = mOriginal->AddOverlayDirtyRect(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::Blt(LPRECT a, LPDIRECTDRAWSURFACE3 b, LPRECT c, DWORD d, LPDDBLTFX e)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::Blt(LPRECT 0x%x, LPDIRECTDRAWSURFACE3 0x%x, LPRECT 0x%x, DWORD %d, LPDDBLTFX 0x%x);", a, b, c, d, e);
  HRESULT x = mOriginal->Blt(a, (b)?((myIDirectDrawSurface3 *)b)->mOriginal:0, c, d, e);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::BltBatch(LPDDBLTBATCH a, DWORD b, DWORD c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::BltBatch(LPDDBLTBATCH 0x%x, DWORD %d, DWORD %d);", a, b, c);
  HRESULT x = mOriginal->BltBatch(a, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::BltFast(DWORD a, DWORD b, LPDIRECTDRAWSURFACE3 c, LPRECT d, DWORD e)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::BltFast(DWORD %d, DWORD %d, LPDIRECTDRAWSURFACE3 0x%x, LPRECT 0x%x, DWORD %d);", a, b, c, d, e);
  HRESULT x = mOriginal->BltFast(a, b, (c)?((myIDirectDrawSurface3 *)c)->mOriginal:0, d, e);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::DeleteAttachedSurface(DWORD a, LPDIRECTDRAWSURFACE3 b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::DeleteAttachedSurface(DWORD %d, LPDIRECTDRAWSURFACE3 0x%x);", a, b);
  HRESULT x = mOriginal->DeleteAttachedSurface(a, (b)?((myIDirectDrawSurface3 *)b)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::EnumAttachedSurfaces(LPVOID a, LPDDENUMSURFACESCALLBACK b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::EnumAttachedSurfaces(LPVOID 0x%x, LPDDENUMSURFACESCALLBACK 0x%x);", a, b);
  HRESULT x = mOriginal->EnumAttachedSurfaces(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::EnumOverlayZOrders(DWORD a, LPVOID b, LPDDENUMSURFACESCALLBACK c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::EnumOverlayZOrders(DWORD %d, LPVOID 0x%x, LPDDENUMSURFACESCALLBACK 0x%x);", a, b, c);
  HRESULT x = mOriginal->EnumOverlayZOrders(a, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::Flip(LPDIRECTDRAWSURFACE3 a, DWORD b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::Flip(LPDIRECTDRAWSURFACE3 0x%x, DWORD %d);", a, b);
  HRESULT x = mOriginal->Flip((a)?((myIDirectDrawSurface3 *)a)->mOriginal:0, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::GetAttachedSurface(LPDDSCAPS a, LPDIRECTDRAWSURFACE3 FAR * b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::GetAttachedSurface(LPDDSCAPS 0x%x, LPDIRECTDRAWSURFACE3 FAR * 0x%x);", a, b);
  HRESULT x = mOriginal->GetAttachedSurface(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  myIDirectDrawSurface3 * n = (myIDirectDrawSurface3 *)wrapfetch(*b);
  if (n == NULL && *b != NULL)
  {
    n = (myIDirectDrawSurface3 *)new myIDirectDrawSurface3(*b);
    wrapstore(n, *b);
    logf("Wrapped.\n");
  }
  *b = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::GetBltStatus(DWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::GetBltStatus(DWORD %d);", a);
  HRESULT x = mOriginal->GetBltStatus(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::GetCaps(LPDDSCAPS a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::GetCaps(LPDDSCAPS 0x%x);", a);
  HRESULT x = mOriginal->GetCaps(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::GetClipper(LPDIRECTDRAWCLIPPER FAR * a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::GetClipper(LPDIRECTDRAWCLIPPER FAR * 0x%x);", a);
  HRESULT x = mOriginal->GetClipper(a);
  logfc(" -> return %d\n", x);
  pushtab();
  myIDirectDrawClipper * n = (myIDirectDrawClipper *)wrapfetch(*a);
  if (n == NULL && *a != NULL)
  {
    n = (myIDirectDrawClipper *)new myIDirectDrawClipper(*a);
    wrapstore(n, *a);
    logf("Wrapped.\n");
  }
  *a = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::GetColorKey(DWORD a, LPDDCOLORKEY b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::GetColorKey(DWORD %d, LPDDCOLORKEY 0x%x);", a, b);
  HRESULT x = mOriginal->GetColorKey(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::GetDC(HDC FAR * a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::GetDC(HDC FAR *);");
  HRESULT x = mOriginal->GetDC(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::GetFlipStatus(DWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::GetFlipStatus(DWORD %d);", a);
  HRESULT x = mOriginal->GetFlipStatus(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::GetOverlayPosition(LPLONG a, LPLONG b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::GetOverlayPosition(LPLONG 0x%x, LPLONG 0x%x);", a, b);
  HRESULT x = mOriginal->GetOverlayPosition(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::GetPalette(LPDIRECTDRAWPALETTE FAR * a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::GetPalette(LPDIRECTDRAWPALETTE FAR * 0x%x);", a);
  HRESULT x = mOriginal->GetPalette(a);
  logfc(" -> return %d\n", x);
  pushtab();
  myIDirectDrawPalette * n = (myIDirectDrawPalette *)wrapfetch(*a);
  if (n == NULL && *a != NULL)
  {
    n = (myIDirectDrawPalette *)new myIDirectDrawPalette(*a);
    wrapstore(n, *a);
    logf("Wrapped.\n");
  }
  *a = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::GetPixelFormat(LPDDPIXELFORMAT a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::GetPixelFormat(LPDDPIXELFORMAT 0x%x);", a);
  HRESULT x = mOriginal->GetPixelFormat(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::GetSurfaceDesc(LPDDSURFACEDESC a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::GetSurfaceDesc(LPDDSURFACEDESC 0x%x);", a);
  HRESULT x = mOriginal->GetSurfaceDesc(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::Initialize(LPDIRECTDRAW a, LPDDSURFACEDESC b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::Initialize(LPDIRECTDRAW 0x%x, LPDDSURFACEDESC 0x%x);", a, b);
  HRESULT x = mOriginal->Initialize((a)?((myIDirectDraw *)a)->mOriginal:0, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::IsLost()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::IsLost();");
  HRESULT x = mOriginal->IsLost();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::Lock(LPRECT a, LPDDSURFACEDESC b, DWORD c, HANDLE d)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::Lock(LPRECT 0x%x, LPDDSURFACEDESC 0x%x, DWORD %d, HANDLE);", a, b, c);
  HRESULT x = mOriginal->Lock(a, b, c, d);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::ReleaseDC(HDC a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::ReleaseDC(HDC);");
  HRESULT x = mOriginal->ReleaseDC(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::Restore()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::Restore();");
  HRESULT x = mOriginal->Restore();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::SetClipper(LPDIRECTDRAWCLIPPER a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::SetClipper(LPDIRECTDRAWCLIPPER 0x%x);", a);
  HRESULT x = mOriginal->SetClipper((a)?((myIDirectDrawClipper *)a)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::SetColorKey(DWORD a, LPDDCOLORKEY b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::SetColorKey(DWORD %d, LPDDCOLORKEY 0x%x);", a, b);
  HRESULT x = mOriginal->SetColorKey(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::SetOverlayPosition(LONG a, LONG b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::SetOverlayPosition(LONG, LONG);");
  HRESULT x = mOriginal->SetOverlayPosition(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::SetPalette(LPDIRECTDRAWPALETTE a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::SetPalette(LPDIRECTDRAWPALETTE 0x%x);", a);
  HRESULT x = mOriginal->SetPalette((a)?((myIDirectDrawPalette *)a)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::Unlock(LPVOID a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::Unlock(LPVOID 0x%x);", a);
  HRESULT x = mOriginal->Unlock(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::UpdateOverlay(LPRECT a, LPDIRECTDRAWSURFACE3 b, LPRECT c, DWORD d, LPDDOVERLAYFX e)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::UpdateOverlay(LPRECT 0x%x, LPDIRECTDRAWSURFACE3 0x%x, LPRECT 0x%x, DWORD %d, LPDDOVERLAYFX 0x%x);", a, b, c, d, e);
  HRESULT x = mOriginal->UpdateOverlay(a, (b)?((myIDirectDrawSurface3 *)b)->mOriginal:0, c, d, e);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::UpdateOverlayDisplay(DWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::UpdateOverlayDisplay(DWORD %d);", a);
  HRESULT x = mOriginal->UpdateOverlayDisplay(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::UpdateOverlayZOrder(DWORD a, LPDIRECTDRAWSURFACE3 b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::UpdateOverlayZOrder(DWORD %d, LPDIRECTDRAWSURFACE3 0x%x);", a, b);
  HRESULT x = mOriginal->UpdateOverlayZOrder(a, (b)?((myIDirectDrawSurface3 *)b)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::GetDDInterface(LPVOID FAR * a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::GetDDInterface(LPVOID FAR * 0x%x);", a);
  HRESULT x = mOriginal->GetDDInterface(a);
  logfc(" -> return %d\n", x);
  pushtab();
  LPVOID n = (LPVOID)wrapfetch(*a);
  if (n == NULL && *a != NULL)
  {
    n = (LPVOID)new myIDirectDraw3((IDirectDraw3 *)*a);
    wrapstore(n, *a);
    logf("Wrapped.\n");
  }
  *a = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::PageLock(DWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::PageLock(DWORD %d);", a);
  HRESULT x = mOriginal->PageLock(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::PageUnlock(DWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::PageUnlock(DWORD %d);", a);
  HRESULT x = mOriginal->PageUnlock(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface3::SetSurfaceDesc(LPDDSURFACEDESC a, DWORD b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface3::SetSurfaceDesc(LPDDSURFACEDESC 0x%x, DWORD %d);", a, b);
  HRESULT x = mOriginal->SetSurfaceDesc(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

