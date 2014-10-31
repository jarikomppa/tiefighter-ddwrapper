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
#include "myIDirectDrawSurface4.h"

myIDirectDrawSurface4::myIDirectDrawSurface4(IDirectDrawSurface4 * aOriginal)
{
  logf("myIDirectDrawSurface4 ctor\n");
  mOriginal = aOriginal;
}

myIDirectDrawSurface4::~myIDirectDrawSurface4()
{
  logf("myIDirectDrawSurface4 dtor\n");
}

HRESULT __stdcall myIDirectDrawSurface4::QueryInterface(REFIID riid, LPVOID FAR * ppvObj)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::QueryInterface(REFIID, LPVOID FAR * 0x%x);", ppvObj);
  HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
  logfc(" -> return %d\n", x);
  pushtab();
  if (x == 0) genericQueryInterface(riid, ppvObj);
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirectDrawSurface4::AddRef()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::AddRef();");
  ULONG x = mOriginal->AddRef();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirectDrawSurface4::Release()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::Release();");
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

HRESULT __stdcall myIDirectDrawSurface4::AddAttachedSurface(LPDIRECTDRAWSURFACE4 a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::AddAttachedSurface(LPDIRECTDRAWSURFACE4 0x%x);", a);
  HRESULT x = mOriginal->AddAttachedSurface((a)?((myIDirectDrawSurface4 *)a)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::AddOverlayDirtyRect(LPRECT a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::AddOverlayDirtyRect(LPRECT 0x%x);", a);
  HRESULT x = mOriginal->AddOverlayDirtyRect(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::Blt(LPRECT a, LPDIRECTDRAWSURFACE4 b, LPRECT c, DWORD d, LPDDBLTFX e)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::Blt(LPRECT 0x%x, LPDIRECTDRAWSURFACE4 0x%x, LPRECT 0x%x, DWORD %d, LPDDBLTFX 0x%x);", a, b, c, d, e);
  HRESULT x = mOriginal->Blt(a, (b)?((myIDirectDrawSurface4 *)b)->mOriginal:0, c, d, e);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::BltBatch(LPDDBLTBATCH a, DWORD b, DWORD c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::BltBatch(LPDDBLTBATCH 0x%x, DWORD %d, DWORD %d);", a, b, c);
  HRESULT x = mOriginal->BltBatch(a, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::BltFast(DWORD a, DWORD b, LPDIRECTDRAWSURFACE4 c, LPRECT d, DWORD e)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::BltFast(DWORD %d, DWORD %d, LPDIRECTDRAWSURFACE4 0x%x, LPRECT 0x%x, DWORD %d);", a, b, c, d, e);
  HRESULT x = mOriginal->BltFast(a, b, (c)?((myIDirectDrawSurface4 *)c)->mOriginal:0, d, e);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::DeleteAttachedSurface(DWORD a, LPDIRECTDRAWSURFACE4 b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::DeleteAttachedSurface(DWORD %d, LPDIRECTDRAWSURFACE4 0x%x);", a, b);
  HRESULT x = mOriginal->DeleteAttachedSurface(a, (b)?((myIDirectDrawSurface4 *)b)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::EnumAttachedSurfaces(LPVOID a, LPDDENUMSURFACESCALLBACK2 b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::EnumAttachedSurfaces(LPVOID 0x%x, LPDDENUMSURFACESCALLBACK2 0x%x);", a, b);
  HRESULT x = mOriginal->EnumAttachedSurfaces(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::EnumOverlayZOrders(DWORD a, LPVOID b, LPDDENUMSURFACESCALLBACK2 c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::EnumOverlayZOrders(DWORD %d, LPVOID 0x%x, LPDDENUMSURFACESCALLBACK2 0x%x);", a, b, c);
  HRESULT x = mOriginal->EnumOverlayZOrders(a, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::Flip(LPDIRECTDRAWSURFACE4 a, DWORD b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::Flip(LPDIRECTDRAWSURFACE4 0x%x, DWORD %d);", a, b);
  HRESULT x = mOriginal->Flip((a)?((myIDirectDrawSurface4 *)a)->mOriginal:0, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::GetAttachedSurface(LPDDSCAPS2 a, LPDIRECTDRAWSURFACE4 FAR * b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::GetAttachedSurface(LPDDSCAPS2 0x%x, LPDIRECTDRAWSURFACE4 FAR * 0x%x);", a, b);
  HRESULT x = mOriginal->GetAttachedSurface(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  myIDirectDrawSurface4 * n = (myIDirectDrawSurface4 *)wrapfetch(*b);
  if (n == NULL && *b != NULL)
  {
    n = (myIDirectDrawSurface4 *)new myIDirectDrawSurface4(*b);
    wrapstore(n, *b);
    logf("Wrapped.\n");
  }
  *b = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::GetBltStatus(DWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::GetBltStatus(DWORD %d);", a);
  HRESULT x = mOriginal->GetBltStatus(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::GetCaps(LPDDSCAPS2 a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::GetCaps(LPDDSCAPS2 0x%x);", a);
  HRESULT x = mOriginal->GetCaps(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::GetClipper(LPDIRECTDRAWCLIPPER FAR * a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::GetClipper(LPDIRECTDRAWCLIPPER FAR * 0x%x);", a);
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

HRESULT __stdcall myIDirectDrawSurface4::GetColorKey(DWORD a, LPDDCOLORKEY b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::GetColorKey(DWORD %d, LPDDCOLORKEY 0x%x);", a, b);
  HRESULT x = mOriginal->GetColorKey(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::GetDC(HDC FAR * a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::GetDC(HDC FAR *);");
  HRESULT x = mOriginal->GetDC(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::GetFlipStatus(DWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::GetFlipStatus(DWORD %d);", a);
  HRESULT x = mOriginal->GetFlipStatus(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::GetOverlayPosition(LPLONG a, LPLONG b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::GetOverlayPosition(LPLONG 0x%x, LPLONG 0x%x);", a, b);
  HRESULT x = mOriginal->GetOverlayPosition(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::GetPalette(LPDIRECTDRAWPALETTE FAR * a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::GetPalette(LPDIRECTDRAWPALETTE FAR * 0x%x);", a);
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

HRESULT __stdcall myIDirectDrawSurface4::GetPixelFormat(LPDDPIXELFORMAT a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::GetPixelFormat(LPDDPIXELFORMAT 0x%x);", a);
  HRESULT x = mOriginal->GetPixelFormat(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::GetSurfaceDesc(LPDDSURFACEDESC2 a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::GetSurfaceDesc(LPDDSURFACEDESC2 0x%x);", a);
  HRESULT x = mOriginal->GetSurfaceDesc(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::Initialize(LPDIRECTDRAW a, LPDDSURFACEDESC2 b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::Initialize(LPDIRECTDRAW 0x%x, LPDDSURFACEDESC2 0x%x);", a, b);
  HRESULT x = mOriginal->Initialize((a)?((myIDirectDraw *)a)->mOriginal:0, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::IsLost()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::IsLost();");
  HRESULT x = mOriginal->IsLost();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::Lock(LPRECT a, LPDDSURFACEDESC2 b, DWORD c, HANDLE d)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::Lock(LPRECT 0x%x, LPDDSURFACEDESC2 0x%x, DWORD %d, HANDLE);", a, b, c);
  HRESULT x = mOriginal->Lock(a, b, c, d);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::ReleaseDC(HDC a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::ReleaseDC(HDC);");
  HRESULT x = mOriginal->ReleaseDC(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::Restore()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::Restore();");
  HRESULT x = mOriginal->Restore();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::SetClipper(LPDIRECTDRAWCLIPPER a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::SetClipper(LPDIRECTDRAWCLIPPER 0x%x);", a);
  HRESULT x = mOriginal->SetClipper((a)?((myIDirectDrawClipper *)a)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::SetColorKey(DWORD a, LPDDCOLORKEY b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::SetColorKey(DWORD %d, LPDDCOLORKEY 0x%x);", a, b);
  HRESULT x = mOriginal->SetColorKey(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::SetOverlayPosition(LONG a, LONG b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::SetOverlayPosition(LONG, LONG);");
  HRESULT x = mOriginal->SetOverlayPosition(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::SetPalette(LPDIRECTDRAWPALETTE a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::SetPalette(LPDIRECTDRAWPALETTE 0x%x);", a);
  HRESULT x = mOriginal->SetPalette((a)?((myIDirectDrawPalette *)a)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::Unlock(LPRECT a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::Unlock(LPRECT 0x%x);", a);
  HRESULT x = mOriginal->Unlock(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::UpdateOverlay(LPRECT a, LPDIRECTDRAWSURFACE4 b, LPRECT c, DWORD d, LPDDOVERLAYFX e)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::UpdateOverlay(LPRECT 0x%x, LPDIRECTDRAWSURFACE4 0x%x, LPRECT 0x%x, DWORD %d, LPDDOVERLAYFX 0x%x);", a, b, c, d, e);
  HRESULT x = mOriginal->UpdateOverlay(a, (b)?((myIDirectDrawSurface4 *)b)->mOriginal:0, c, d, e);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::UpdateOverlayDisplay(DWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::UpdateOverlayDisplay(DWORD %d);", a);
  HRESULT x = mOriginal->UpdateOverlayDisplay(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::UpdateOverlayZOrder(DWORD a, LPDIRECTDRAWSURFACE4 b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::UpdateOverlayZOrder(DWORD %d, LPDIRECTDRAWSURFACE4 0x%x);", a, b);
  HRESULT x = mOriginal->UpdateOverlayZOrder(a, (b)?((myIDirectDrawSurface4 *)b)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::GetDDInterface(LPVOID FAR * a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::GetDDInterface(LPVOID FAR * 0x%x);", a);
  HRESULT x = mOriginal->GetDDInterface(a);
  logfc(" -> return %d\n", x);
  pushtab();
  LPVOID n = (LPVOID)wrapfetch(*a);
  if (n == NULL && *a != NULL)
  {
    n = (LPVOID)new myIDirectDraw4((IDirectDraw4 *)*a);
    wrapstore(n, *a);
    logf("Wrapped.\n");
  }
  *a = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::PageLock(DWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::PageLock(DWORD %d);", a);
  HRESULT x = mOriginal->PageLock(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::PageUnlock(DWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::PageUnlock(DWORD %d);", a);
  HRESULT x = mOriginal->PageUnlock(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::SetSurfaceDesc(LPDDSURFACEDESC2 a, DWORD b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::SetSurfaceDesc(LPDDSURFACEDESC2 0x%x, DWORD %d);", a, b);
  HRESULT x = mOriginal->SetSurfaceDesc(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::SetPrivateData(REFGUID a, LPVOID b, DWORD c, DWORD d)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::SetPrivateData(REFGUID, LPVOID 0x%x, DWORD %d, DWORD %d);", b, c, d);
  HRESULT x = mOriginal->SetPrivateData(a, b, c, d);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::GetPrivateData(REFGUID a, LPVOID b, LPDWORD c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::GetPrivateData(REFGUID, LPVOID 0x%x, LPDWORD 0x%x);", b, c);
  HRESULT x = mOriginal->GetPrivateData(a, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::FreePrivateData(REFGUID a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::FreePrivateData(REFGUID);");
  HRESULT x = mOriginal->FreePrivateData(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::GetUniquenessValue(LPDWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::GetUniquenessValue(LPDWORD 0x%x);", a);
  HRESULT x = mOriginal->GetUniquenessValue(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface4::ChangeUniquenessValue()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface4::ChangeUniquenessValue();");
  HRESULT x = mOriginal->ChangeUniquenessValue();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

