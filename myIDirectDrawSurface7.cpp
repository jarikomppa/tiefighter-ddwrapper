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
#include "myIDirectDrawSurface7.h"

myIDirectDrawSurface7::myIDirectDrawSurface7(IDirectDrawSurface7 * aOriginal)
{
  logf("myIDirectDrawSurface7 ctor\n");
  mOriginal = aOriginal;
}

myIDirectDrawSurface7::~myIDirectDrawSurface7()
{
  logf("myIDirectDrawSurface7 dtor\n");
}

HRESULT __stdcall myIDirectDrawSurface7::QueryInterface(REFIID riid, LPVOID FAR * ppvObj)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::QueryInterface(REFIID, LPVOID FAR * 0x%x);", ppvObj);
  HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
  logfc(" -> return %d\n", x);
  pushtab();
  if (x == 0) genericQueryInterface(riid, ppvObj);
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirectDrawSurface7::AddRef()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::AddRef();");
  ULONG x = mOriginal->AddRef();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirectDrawSurface7::Release()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::Release();");
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

HRESULT __stdcall myIDirectDrawSurface7::AddAttachedSurface(LPDIRECTDRAWSURFACE7 a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::AddAttachedSurface(LPDIRECTDRAWSURFACE7 0x%x);", a);
  HRESULT x = mOriginal->AddAttachedSurface((a)?((myIDirectDrawSurface7 *)a)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::AddOverlayDirtyRect(LPRECT a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::AddOverlayDirtyRect(LPRECT 0x%x);", a);
  HRESULT x = mOriginal->AddOverlayDirtyRect(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::Blt(LPRECT a, LPDIRECTDRAWSURFACE7 b, LPRECT c, DWORD d, LPDDBLTFX e)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::Blt(LPRECT 0x%x, LPDIRECTDRAWSURFACE7 0x%x, LPRECT 0x%x, DWORD %d, LPDDBLTFX 0x%x);", a, b, c, d, e);
  HRESULT x = mOriginal->Blt(a, (b)?((myIDirectDrawSurface7 *)b)->mOriginal:0, c, d, e);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::BltBatch(LPDDBLTBATCH a, DWORD b, DWORD c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::BltBatch(LPDDBLTBATCH 0x%x, DWORD %d, DWORD %d);", a, b, c);
  HRESULT x = mOriginal->BltBatch(a, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::BltFast(DWORD a, DWORD b, LPDIRECTDRAWSURFACE7 c, LPRECT d, DWORD e)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::BltFast(DWORD %d, DWORD %d, LPDIRECTDRAWSURFACE7 0x%x, LPRECT 0x%x, DWORD %d);", a, b, c, d, e);
  HRESULT x = mOriginal->BltFast(a, b, (c)?((myIDirectDrawSurface7 *)c)->mOriginal:0, d, e);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::DeleteAttachedSurface(DWORD a, LPDIRECTDRAWSURFACE7 b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::DeleteAttachedSurface(DWORD %d, LPDIRECTDRAWSURFACE7 0x%x);", a, b);
  HRESULT x = mOriginal->DeleteAttachedSurface(a, (b)?((myIDirectDrawSurface7 *)b)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::EnumAttachedSurfaces(LPVOID a, LPDDENUMSURFACESCALLBACK7 b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::EnumAttachedSurfaces(LPVOID 0x%x, LPDDENUMSURFACESCALLBACK7 0x%x);", a, b);
  HRESULT x = mOriginal->EnumAttachedSurfaces(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::EnumOverlayZOrders(DWORD a, LPVOID b, LPDDENUMSURFACESCALLBACK7 c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::EnumOverlayZOrders(DWORD %d, LPVOID 0x%x, LPDDENUMSURFACESCALLBACK7 0x%x);", a, b, c);
  HRESULT x = mOriginal->EnumOverlayZOrders(a, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::Flip(LPDIRECTDRAWSURFACE7 a, DWORD b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::Flip(LPDIRECTDRAWSURFACE7 0x%x, DWORD %d);", a, b);
  HRESULT x = mOriginal->Flip((a)?((myIDirectDrawSurface7 *)a)->mOriginal:0, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::GetAttachedSurface(LPDDSCAPS2 a, LPDIRECTDRAWSURFACE7 FAR * b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::GetAttachedSurface(LPDDSCAPS2 0x%x, LPDIRECTDRAWSURFACE7 FAR * 0x%x);", a, b);
  HRESULT x = mOriginal->GetAttachedSurface(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  myIDirectDrawSurface7 * n = (myIDirectDrawSurface7 *)wrapfetch(*b);
  if (n == NULL && *b != NULL)
  {
    n = (myIDirectDrawSurface7 *)new myIDirectDrawSurface7(*b);
    wrapstore(n, *b);
    logf("Wrapped.\n");
  }
  *b = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::GetBltStatus(DWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::GetBltStatus(DWORD %d);", a);
  HRESULT x = mOriginal->GetBltStatus(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::GetCaps(LPDDSCAPS2 a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::GetCaps(LPDDSCAPS2 0x%x);", a);
  HRESULT x = mOriginal->GetCaps(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::GetClipper(LPDIRECTDRAWCLIPPER FAR * a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::GetClipper(LPDIRECTDRAWCLIPPER FAR * 0x%x);", a);
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

HRESULT __stdcall myIDirectDrawSurface7::GetColorKey(DWORD a, LPDDCOLORKEY b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::GetColorKey(DWORD %d, LPDDCOLORKEY 0x%x);", a, b);
  HRESULT x = mOriginal->GetColorKey(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::GetDC(HDC FAR * a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::GetDC(HDC FAR *);");
  HRESULT x = mOriginal->GetDC(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::GetFlipStatus(DWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::GetFlipStatus(DWORD %d);", a);
  HRESULT x = mOriginal->GetFlipStatus(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::GetOverlayPosition(LPLONG a, LPLONG b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::GetOverlayPosition(LPLONG 0x%x, LPLONG 0x%x);", a, b);
  HRESULT x = mOriginal->GetOverlayPosition(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::GetPalette(LPDIRECTDRAWPALETTE FAR * a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::GetPalette(LPDIRECTDRAWPALETTE FAR * 0x%x);", a);
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

HRESULT __stdcall myIDirectDrawSurface7::GetPixelFormat(LPDDPIXELFORMAT a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::GetPixelFormat(LPDDPIXELFORMAT 0x%x);", a);
  HRESULT x = mOriginal->GetPixelFormat(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::GetSurfaceDesc(LPDDSURFACEDESC2 a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::GetSurfaceDesc(LPDDSURFACEDESC2 0x%x);", a);
  HRESULT x = mOriginal->GetSurfaceDesc(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::Initialize(LPDIRECTDRAW a, LPDDSURFACEDESC2 b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::Initialize(LPDIRECTDRAW 0x%x, LPDDSURFACEDESC2 0x%x);", a, b);
  HRESULT x = mOriginal->Initialize((a)?((myIDirectDraw *)a)->mOriginal:0, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::IsLost()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::IsLost();");
  HRESULT x = mOriginal->IsLost();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::Lock(LPRECT a, LPDDSURFACEDESC2 b, DWORD c, HANDLE d)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::Lock(LPRECT 0x%x, LPDDSURFACEDESC2 0x%x, DWORD %d, HANDLE);", a, b, c);
  HRESULT x = mOriginal->Lock(a, b, c, d);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::ReleaseDC(HDC a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::ReleaseDC(HDC);");
  HRESULT x = mOriginal->ReleaseDC(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::Restore()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::Restore();");
  HRESULT x = mOriginal->Restore();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::SetClipper(LPDIRECTDRAWCLIPPER a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::SetClipper(LPDIRECTDRAWCLIPPER 0x%x);", a);
  HRESULT x = mOriginal->SetClipper((a)?((myIDirectDrawClipper *)a)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::SetColorKey(DWORD a, LPDDCOLORKEY b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::SetColorKey(DWORD %d, LPDDCOLORKEY 0x%x);", a, b);
  HRESULT x = mOriginal->SetColorKey(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::SetOverlayPosition(LONG a, LONG b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::SetOverlayPosition(LONG, LONG);");
  HRESULT x = mOriginal->SetOverlayPosition(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::SetPalette(LPDIRECTDRAWPALETTE a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::SetPalette(LPDIRECTDRAWPALETTE 0x%x);", a);
  HRESULT x = mOriginal->SetPalette((a)?((myIDirectDrawPalette *)a)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::Unlock(LPRECT a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::Unlock(LPRECT 0x%x);", a);
  HRESULT x = mOriginal->Unlock(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::UpdateOverlay(LPRECT a, LPDIRECTDRAWSURFACE7 b, LPRECT c, DWORD d, LPDDOVERLAYFX e)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::UpdateOverlay(LPRECT 0x%x, LPDIRECTDRAWSURFACE7 0x%x, LPRECT 0x%x, DWORD %d, LPDDOVERLAYFX 0x%x);", a, b, c, d, e);
  HRESULT x = mOriginal->UpdateOverlay(a, (b)?((myIDirectDrawSurface7 *)b)->mOriginal:0, c, d, e);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::UpdateOverlayDisplay(DWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::UpdateOverlayDisplay(DWORD %d);", a);
  HRESULT x = mOriginal->UpdateOverlayDisplay(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::UpdateOverlayZOrder(DWORD a, LPDIRECTDRAWSURFACE7 b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::UpdateOverlayZOrder(DWORD %d, LPDIRECTDRAWSURFACE7 0x%x);", a, b);
  HRESULT x = mOriginal->UpdateOverlayZOrder(a, (b)?((myIDirectDrawSurface7 *)b)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::GetDDInterface(LPVOID FAR * a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::GetDDInterface(LPVOID FAR * 0x%x);", a);
  HRESULT x = mOriginal->GetDDInterface(a);
  logfc(" -> return %d\n", x);
  pushtab();
  LPVOID n = (LPVOID)wrapfetch(*a);
  if (n == NULL && *a != NULL)
  {
    n = (LPVOID)new myIDirectDraw7((IDirectDraw7 *)*a);
    wrapstore(n, *a);
    logf("Wrapped.\n");
  }
  *a = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::PageLock(DWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::PageLock(DWORD %d);", a);
  HRESULT x = mOriginal->PageLock(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::PageUnlock(DWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::PageUnlock(DWORD %d);", a);
  HRESULT x = mOriginal->PageUnlock(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::SetSurfaceDesc(LPDDSURFACEDESC2 a, DWORD b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::SetSurfaceDesc(LPDDSURFACEDESC2 0x%x, DWORD %d);", a, b);
  HRESULT x = mOriginal->SetSurfaceDesc(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::SetPrivateData(REFGUID a, LPVOID b, DWORD c, DWORD d)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::SetPrivateData(REFGUID, LPVOID 0x%x, DWORD %d, DWORD %d);", b, c, d);
  HRESULT x = mOriginal->SetPrivateData(a, b, c, d);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::GetPrivateData(REFGUID a, LPVOID b, LPDWORD c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::GetPrivateData(REFGUID, LPVOID 0x%x, LPDWORD 0x%x);", b, c);
  HRESULT x = mOriginal->GetPrivateData(a, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::FreePrivateData(REFGUID a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::FreePrivateData(REFGUID);");
  HRESULT x = mOriginal->FreePrivateData(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::GetUniquenessValue(LPDWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::GetUniquenessValue(LPDWORD 0x%x);", a);
  HRESULT x = mOriginal->GetUniquenessValue(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::ChangeUniquenessValue()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::ChangeUniquenessValue();");
  HRESULT x = mOriginal->ChangeUniquenessValue();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::SetPriority(DWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::SetPriority(DWORD %d);", a);
  HRESULT x = mOriginal->SetPriority(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::GetPriority(LPDWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::GetPriority(LPDWORD 0x%x);", a);
  HRESULT x = mOriginal->GetPriority(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::SetLOD(DWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::SetLOD(DWORD %d);", a);
  HRESULT x = mOriginal->SetLOD(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface7::GetLOD(LPDWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface7::GetLOD(LPDWORD 0x%x);", a);
  HRESULT x = mOriginal->GetLOD(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

