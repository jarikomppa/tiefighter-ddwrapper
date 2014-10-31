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
#include "myIDirectDraw.h"

myIDirectDraw::myIDirectDraw(IDirectDraw * aOriginal)
{
  logf("myIDirectDraw ctor\n");
  mOriginal = aOriginal;
}

myIDirectDraw::~myIDirectDraw()
{
  logf("myIDirectDraw dtor\n");
}

HRESULT __stdcall myIDirectDraw::QueryInterface(REFIID riid, LPVOID FAR * ppvObj)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw::QueryInterface(REFIID, LPVOID FAR * 0x%x);", ppvObj);
  HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
  logfc(" -> return %d\n", x);
  pushtab();
  if (x == 0) genericQueryInterface(riid, ppvObj);
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirectDraw::AddRef()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw::AddRef();");
  ULONG x = mOriginal->AddRef();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirectDraw::Release()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw::Release();");
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

HRESULT __stdcall myIDirectDraw::Compact()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw::Compact();");
  HRESULT x = mOriginal->Compact();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw::CreateClipper(DWORD a, LPDIRECTDRAWCLIPPER FAR * b, IUnknown FAR * c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw::CreateClipper(DWORD %d, LPDIRECTDRAWCLIPPER FAR * 0x%x, IUnknown FAR *);", a, b);
  HRESULT x = mOriginal->CreateClipper(a, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  myIDirectDrawClipper * n = (myIDirectDrawClipper *)wrapfetch(*b);
  if (n == NULL && *b != NULL)
  {
    n = (myIDirectDrawClipper *)new myIDirectDrawClipper(*b);
    wrapstore(n, *b);
    logf("Wrapped.\n");
  }
  *b = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw::CreatePalette(DWORD a, LPPALETTEENTRY b, LPDIRECTDRAWPALETTE FAR * c, IUnknown FAR * d)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw::CreatePalette(DWORD %d, LPPALETTEENTRY 0x%x, LPDIRECTDRAWPALETTE FAR * 0x%x, IUnknown FAR *);", a, b, c);
  HRESULT x = mOriginal->CreatePalette(a, b, c, d);
  logfc(" -> return %d\n", x);
  pushtab();
  myIDirectDrawPalette * n = (myIDirectDrawPalette *)wrapfetch(*c);
  if (n == NULL && *c != NULL)
  {
    n = (myIDirectDrawPalette *)new myIDirectDrawPalette(*c);
    wrapstore(n, *c);
    logf("Wrapped.\n");
  }
  *c = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw::CreateSurface(LPDDSURFACEDESC a, LPDIRECTDRAWSURFACE FAR * b, IUnknown FAR * c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw::CreateSurface(LPDDSURFACEDESC 0x%x, LPDIRECTDRAWSURFACE FAR * 0x%x, IUnknown FAR *);", a, b);
  HRESULT x = mOriginal->CreateSurface(a, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  IDirectDrawSurface * n = (IDirectDrawSurface *)wrapfetch(*b);
  if (n == NULL && *b != NULL)
  {
    n = (IDirectDrawSurface *)new myIDirectDrawSurface(*b);
    wrapstore(n, *b);
    logf("Wrapped.\n");
  }
  *b = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw::DuplicateSurface(LPDIRECTDRAWSURFACE a, LPDIRECTDRAWSURFACE FAR * b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw::DuplicateSurface(LPDIRECTDRAWSURFACE 0x%x, LPDIRECTDRAWSURFACE FAR * 0x%x);", a, b);
  HRESULT x = mOriginal->DuplicateSurface((a)?((myIDirectDrawSurface *)a)->mOriginal:0, b);
  logfc(" -> return %d\n", x);
  pushtab();
  IDirectDrawSurface * n = (IDirectDrawSurface *)wrapfetch(*b);
  if (n == NULL && *b != NULL)
  {
    n = (IDirectDrawSurface *)new myIDirectDrawSurface(*b);
    wrapstore(n, *b);
    logf("Wrapped.\n");
  }
  *b = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw::EnumDisplayModes(DWORD a, LPDDSURFACEDESC b, LPVOID c, LPDDENUMMODESCALLBACK d)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw::EnumDisplayModes(DWORD %d, LPDDSURFACEDESC 0x%x, LPVOID 0x%x, LPDDENUMMODESCALLBACK 0x%x);", a, b, c, d);
  HRESULT x = mOriginal->EnumDisplayModes(a, b, c, d);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw::EnumSurfaces(DWORD a, LPDDSURFACEDESC b, LPVOID c, LPDDENUMSURFACESCALLBACK d)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw::EnumSurfaces(DWORD %d, LPDDSURFACEDESC 0x%x, LPVOID 0x%x, LPDDENUMSURFACESCALLBACK 0x%x);", a, b, c, d);
  HRESULT x = mOriginal->EnumSurfaces(a, b, c, d);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw::FlipToGDISurface()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw::FlipToGDISurface();");
  HRESULT x = mOriginal->FlipToGDISurface();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw::GetCaps(LPDDCAPS a, LPDDCAPS b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw::GetCaps(LPDDCAPS 0x%x, LPDDCAPS 0x%x);", a, b);
  HRESULT x = mOriginal->GetCaps(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw::GetDisplayMode(LPDDSURFACEDESC a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw::GetDisplayMode(LPDDSURFACEDESC 0x%x);", a);
  HRESULT x = mOriginal->GetDisplayMode(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw::GetFourCCCodes(LPDWORD a, LPDWORD b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw::GetFourCCCodes(LPDWORD 0x%x, LPDWORD 0x%x);", a, b);
  HRESULT x = mOriginal->GetFourCCCodes(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw::GetGDISurface(LPDIRECTDRAWSURFACE FAR * a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw::GetGDISurface(LPDIRECTDRAWSURFACE FAR * 0x%x);", a);
  HRESULT x = mOriginal->GetGDISurface(a);
  logfc(" -> return %d\n", x);
  pushtab();
  IDirectDrawSurface * n = (IDirectDrawSurface *)wrapfetch(*a);
  if (n == NULL && *a != NULL)
  {
    n = (IDirectDrawSurface *)new myIDirectDrawSurface(*a);
    wrapstore(n, *a);
    logf("Wrapped.\n");
  }
  *a = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw::GetMonitorFrequency(LPDWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw::GetMonitorFrequency(LPDWORD 0x%x);", a);
  HRESULT x = mOriginal->GetMonitorFrequency(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw::GetScanLine(LPDWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw::GetScanLine(LPDWORD 0x%x);", a);
  HRESULT x = mOriginal->GetScanLine(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw::GetVerticalBlankStatus(LPBOOL a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw::GetVerticalBlankStatus(LPBOOL 0x%x);", a);
  HRESULT x = mOriginal->GetVerticalBlankStatus(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw::Initialize(GUID FAR * a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw::Initialize(GUID FAR *);");
  HRESULT x = mOriginal->Initialize(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw::RestoreDisplayMode()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw::RestoreDisplayMode();");
  HRESULT x = mOriginal->RestoreDisplayMode();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw::SetCooperativeLevel(HWND a, DWORD b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw::SetCooperativeLevel(HWND 0x%x, DWORD %d);", a, b);
  HRESULT x = mOriginal->SetCooperativeLevel(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw::SetDisplayMode(DWORD a, DWORD b, DWORD c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw::SetDisplayMode(DWORD %d, DWORD %d, DWORD %d);", a, b, c);
  HRESULT x = mOriginal->SetDisplayMode(a, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw::WaitForVerticalBlank(DWORD a, HANDLE b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw::WaitForVerticalBlank(DWORD %d, HANDLE);", a);
  HRESULT x = mOriginal->WaitForVerticalBlank(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

