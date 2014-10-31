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
#include "myIDirectDrawSurface.h"

myIDirectDrawSurface::myIDirectDrawSurface(IDirectDrawSurface * aOriginal)
{
  logf("myIDirectDrawSurface ctor\n");
  mOriginal = aOriginal;
}

myIDirectDrawSurface::~myIDirectDrawSurface()
{
  logf("myIDirectDrawSurface dtor\n");
}

HRESULT __stdcall myIDirectDrawSurface::QueryInterface(REFIID riid, LPVOID FAR * ppvObj)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::QueryInterface(REFIID, LPVOID FAR * 0x%x);", ppvObj);
  HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
  logfc(" -> return %d\n", x);
  pushtab();
  if (x == 0) genericQueryInterface(riid, ppvObj);
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirectDrawSurface::AddRef()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::AddRef();");
  ULONG x = mOriginal->AddRef();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirectDrawSurface::Release()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::Release();");
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

HRESULT __stdcall myIDirectDrawSurface::AddAttachedSurface(LPDIRECTDRAWSURFACE a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::AddAttachedSurface(LPDIRECTDRAWSURFACE 0x%x);", a);
  HRESULT x = mOriginal->AddAttachedSurface((a)?((myIDirectDrawSurface *)a)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::AddOverlayDirtyRect(LPRECT a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::AddOverlayDirtyRect(LPRECT 0x%x);", a);
  HRESULT x = mOriginal->AddOverlayDirtyRect(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::Blt(LPRECT a, LPDIRECTDRAWSURFACE b, LPRECT c, DWORD d, LPDDBLTFX e)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::Blt(LPRECT 0x%x, LPDIRECTDRAWSURFACE 0x%x, LPRECT 0x%x, DWORD %d, LPDDBLTFX 0x%x);", a, b, c, d, e);
  HRESULT x = mOriginal->Blt(a, (b)?((myIDirectDrawSurface *)b)->mOriginal:0, c, d, e);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::BltBatch(LPDDBLTBATCH a, DWORD b, DWORD c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::BltBatch(LPDDBLTBATCH 0x%x, DWORD %d, DWORD %d);", a, b, c);
  HRESULT x = mOriginal->BltBatch(a, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::BltFast(DWORD a, DWORD b, LPDIRECTDRAWSURFACE c, LPRECT d, DWORD e)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::BltFast(DWORD %d, DWORD %d, LPDIRECTDRAWSURFACE 0x%x, LPRECT 0x%x, DWORD %d);", a, b, c, d, e);
  HRESULT x = mOriginal->BltFast(a, b, (c)?((myIDirectDrawSurface *)c)->mOriginal:0, d, e);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::DeleteAttachedSurface(DWORD a, LPDIRECTDRAWSURFACE b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::DeleteAttachedSurface(DWORD %d, LPDIRECTDRAWSURFACE 0x%x);", a, b);
  HRESULT x = mOriginal->DeleteAttachedSurface(a, (b)?((myIDirectDrawSurface *)b)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::EnumAttachedSurfaces(LPVOID a, LPDDENUMSURFACESCALLBACK b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::EnumAttachedSurfaces(LPVOID 0x%x, LPDDENUMSURFACESCALLBACK 0x%x);", a, b);
  HRESULT x = mOriginal->EnumAttachedSurfaces(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::EnumOverlayZOrders(DWORD a, LPVOID b, LPDDENUMSURFACESCALLBACK c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::EnumOverlayZOrders(DWORD %d, LPVOID 0x%x, LPDDENUMSURFACESCALLBACK 0x%x);", a, b, c);
  HRESULT x = mOriginal->EnumOverlayZOrders(a, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::Flip(LPDIRECTDRAWSURFACE a, DWORD b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::Flip(LPDIRECTDRAWSURFACE 0x%x, DWORD %d);", a, b);
  HRESULT x = mOriginal->Flip((a)?((myIDirectDrawSurface *)a)->mOriginal:0, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::GetAttachedSurface(LPDDSCAPS a, LPDIRECTDRAWSURFACE FAR * b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::GetAttachedSurface(LPDDSCAPS 0x%x, LPDIRECTDRAWSURFACE FAR * 0x%x);", a, b);
  HRESULT x = mOriginal->GetAttachedSurface(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  myIDirectDrawSurface * n = (myIDirectDrawSurface *)wrapfetch(*b);
  if (n == NULL && *b != NULL)
  {
    n = (myIDirectDrawSurface *)new myIDirectDrawSurface(*b);
    wrapstore(n, *b);
    logf("Wrapped.\n");
  }
  *b = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::GetBltStatus(DWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::GetBltStatus(DWORD %d);", a);
  HRESULT x = mOriginal->GetBltStatus(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::GetCaps(LPDDSCAPS a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::GetCaps(LPDDSCAPS 0x%x);", a);
  HRESULT x = mOriginal->GetCaps(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::GetClipper(LPDIRECTDRAWCLIPPER FAR * a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::GetClipper(LPDIRECTDRAWCLIPPER FAR * 0x%x);", a);
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

HRESULT __stdcall myIDirectDrawSurface::GetColorKey(DWORD a, LPDDCOLORKEY b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::GetColorKey(DWORD %d, LPDDCOLORKEY 0x%x);", a, b);
  HRESULT x = mOriginal->GetColorKey(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::GetDC(HDC FAR * a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::GetDC(HDC FAR *);");
  HRESULT x = mOriginal->GetDC(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::GetFlipStatus(DWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::GetFlipStatus(DWORD %d);", a);
  HRESULT x = mOriginal->GetFlipStatus(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::GetOverlayPosition(LPLONG a, LPLONG b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::GetOverlayPosition(LPLONG 0x%x, LPLONG 0x%x);", a, b);
  HRESULT x = mOriginal->GetOverlayPosition(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::GetPalette(LPDIRECTDRAWPALETTE FAR * a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::GetPalette(LPDIRECTDRAWPALETTE FAR * 0x%x);", a);
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

HRESULT __stdcall myIDirectDrawSurface::GetPixelFormat(LPDDPIXELFORMAT a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::GetPixelFormat(LPDDPIXELFORMAT 0x%x);", a);
  HRESULT x = mOriginal->GetPixelFormat(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::GetSurfaceDesc(LPDDSURFACEDESC a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::GetSurfaceDesc(LPDDSURFACEDESC 0x%x);", a);
  HRESULT x = mOriginal->GetSurfaceDesc(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::Initialize(LPDIRECTDRAW a, LPDDSURFACEDESC b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::Initialize(LPDIRECTDRAW 0x%x, LPDDSURFACEDESC 0x%x);", a, b);
  HRESULT x = mOriginal->Initialize((a)?((myIDirectDraw *)a)->mOriginal:0, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::IsLost()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::IsLost();");
  HRESULT x = mOriginal->IsLost();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::Lock(LPRECT a, LPDDSURFACEDESC b, DWORD c, HANDLE d)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::Lock(LPRECT 0x%x, LPDDSURFACEDESC 0x%x, DWORD %d, HANDLE);", a, b, c);
  HRESULT x = mOriginal->Lock(a, b, c, d);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::ReleaseDC(HDC a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::ReleaseDC(HDC);");
  HRESULT x = mOriginal->ReleaseDC(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::Restore()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::Restore();");
  HRESULT x = mOriginal->Restore();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::SetClipper(LPDIRECTDRAWCLIPPER a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::SetClipper(LPDIRECTDRAWCLIPPER 0x%x);", a);
  HRESULT x = mOriginal->SetClipper((a)?((myIDirectDrawClipper *)a)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::SetColorKey(DWORD a, LPDDCOLORKEY b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::SetColorKey(DWORD %d, LPDDCOLORKEY 0x%x);", a, b);
  HRESULT x = mOriginal->SetColorKey(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::SetOverlayPosition(LONG a, LONG b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::SetOverlayPosition(LONG, LONG);");
  HRESULT x = mOriginal->SetOverlayPosition(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::SetPalette(LPDIRECTDRAWPALETTE a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::SetPalette(LPDIRECTDRAWPALETTE 0x%x);", a);
  HRESULT x = mOriginal->SetPalette((a)?((myIDirectDrawPalette *)a)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::Unlock(LPVOID a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::Unlock(LPVOID 0x%x);", a);
  HRESULT x = mOriginal->Unlock(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::UpdateOverlay(LPRECT a, LPDIRECTDRAWSURFACE b, LPRECT c, DWORD d, LPDDOVERLAYFX e)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::UpdateOverlay(LPRECT 0x%x, LPDIRECTDRAWSURFACE 0x%x, LPRECT 0x%x, DWORD %d, LPDDOVERLAYFX 0x%x);", a, b, c, d, e);
  HRESULT x = mOriginal->UpdateOverlay(a, (b)?((myIDirectDrawSurface *)b)->mOriginal:0, c, d, e);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::UpdateOverlayDisplay(DWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::UpdateOverlayDisplay(DWORD %d);", a);
  HRESULT x = mOriginal->UpdateOverlayDisplay(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::UpdateOverlayZOrder(DWORD a, LPDIRECTDRAWSURFACE b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::UpdateOverlayZOrder(DWORD %d, LPDIRECTDRAWSURFACE 0x%x);", a, b);
  HRESULT x = mOriginal->UpdateOverlayZOrder(a, (b)?((myIDirectDrawSurface *)b)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

