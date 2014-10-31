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
#include "myIDirectDraw4.h"

myIDirectDraw4::myIDirectDraw4(IDirectDraw4 * aOriginal)
{
  logf("myIDirectDraw4 ctor\n");
  mOriginal = aOriginal;
}

myIDirectDraw4::~myIDirectDraw4()
{
  logf("myIDirectDraw4 dtor\n");
}

HRESULT __stdcall myIDirectDraw4::QueryInterface(REFIID riid, LPVOID FAR * ppvObj)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw4::QueryInterface(REFIID, LPVOID FAR * 0x%x);", ppvObj);
  HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
  logfc(" -> return %d\n", x);
  pushtab();
  if (x == 0) genericQueryInterface(riid, ppvObj);
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirectDraw4::AddRef()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw4::AddRef();");
  ULONG x = mOriginal->AddRef();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirectDraw4::Release()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw4::Release();");
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

HRESULT __stdcall myIDirectDraw4::Compact()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw4::Compact();");
  HRESULT x = mOriginal->Compact();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw4::CreateClipper(DWORD a, LPDIRECTDRAWCLIPPER FAR * b, IUnknown FAR * c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw4::CreateClipper(DWORD %d, LPDIRECTDRAWCLIPPER FAR * 0x%x, IUnknown FAR *);", a, b);
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

HRESULT __stdcall myIDirectDraw4::CreatePalette(DWORD a, LPPALETTEENTRY b, LPDIRECTDRAWPALETTE FAR * c, IUnknown FAR * d)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw4::CreatePalette(DWORD %d, LPPALETTEENTRY 0x%x, LPDIRECTDRAWPALETTE FAR * 0x%x, IUnknown FAR *);", a, b, c);
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

HRESULT __stdcall myIDirectDraw4::CreateSurface(LPDDSURFACEDESC2 a, LPDIRECTDRAWSURFACE4 FAR * b, IUnknown FAR * c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw4::CreateSurface(LPDDSURFACEDESC2 0x%x, LPDIRECTDRAWSURFACE4 FAR * 0x%x, IUnknown FAR *);", a, b);
  HRESULT x = mOriginal->CreateSurface(a, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  IDirectDrawSurface4 * n = (IDirectDrawSurface4 *)wrapfetch(*b);
  if (n == NULL && *b != NULL)
  {
    n = (IDirectDrawSurface4 *)new myIDirectDrawSurface4(*b);
    wrapstore(n, *b);
    logf("Wrapped.\n");
  }
  *b = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw4::DuplicateSurface(LPDIRECTDRAWSURFACE4 a, LPDIRECTDRAWSURFACE4 FAR * b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw4::DuplicateSurface(LPDIRECTDRAWSURFACE4 0x%x, LPDIRECTDRAWSURFACE4 FAR * 0x%x);", a, b);
  HRESULT x = mOriginal->DuplicateSurface((a)?((myIDirectDrawSurface4 *)a)->mOriginal:0, b);
  logfc(" -> return %d\n", x);
  pushtab();
  IDirectDrawSurface4 * n = (IDirectDrawSurface4 *)wrapfetch(*b);
  if (n == NULL && *b != NULL)
  {
    n = (IDirectDrawSurface4 *)new myIDirectDrawSurface4(*b);
    wrapstore(n, *b);
    logf("Wrapped.\n");
  }
  *b = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw4::EnumDisplayModes(DWORD a, LPDDSURFACEDESC2 b, LPVOID c, LPDDENUMMODESCALLBACK2 d)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw4::EnumDisplayModes(DWORD %d, LPDDSURFACEDESC2 0x%x, LPVOID 0x%x, LPDDENUMMODESCALLBACK2 0x%x);", a, b, c, d);
  HRESULT x = mOriginal->EnumDisplayModes(a, b, c, d);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw4::EnumSurfaces(DWORD a, LPDDSURFACEDESC2 b, LPVOID c, LPDDENUMSURFACESCALLBACK2 d)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw4::EnumSurfaces(DWORD %d, LPDDSURFACEDESC2 0x%x, LPVOID 0x%x, LPDDENUMSURFACESCALLBACK2 0x%x);", a, b, c, d);
  HRESULT x = mOriginal->EnumSurfaces(a, b, c, d);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw4::FlipToGDISurface()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw4::FlipToGDISurface();");
  HRESULT x = mOriginal->FlipToGDISurface();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw4::GetCaps(LPDDCAPS a, LPDDCAPS b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw4::GetCaps(LPDDCAPS 0x%x, LPDDCAPS 0x%x);", a, b);
  HRESULT x = mOriginal->GetCaps(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw4::GetDisplayMode(LPDDSURFACEDESC2 a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw4::GetDisplayMode(LPDDSURFACEDESC2 0x%x);", a);
  HRESULT x = mOriginal->GetDisplayMode(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw4::GetFourCCCodes(LPDWORD a, LPDWORD b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw4::GetFourCCCodes(LPDWORD 0x%x, LPDWORD 0x%x);", a, b);
  HRESULT x = mOriginal->GetFourCCCodes(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw4::GetGDISurface(LPDIRECTDRAWSURFACE4 FAR * a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw4::GetGDISurface(LPDIRECTDRAWSURFACE4 FAR * 0x%x);", a);
  HRESULT x = mOriginal->GetGDISurface(a);
  logfc(" -> return %d\n", x);
  pushtab();
  IDirectDrawSurface4 * n = (IDirectDrawSurface4 *)wrapfetch(*a);
  if (n == NULL && *a != NULL)
  {
    n = (IDirectDrawSurface4 *)new myIDirectDrawSurface4(*a);
    wrapstore(n, *a);
    logf("Wrapped.\n");
  }
  *a = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw4::GetMonitorFrequency(LPDWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw4::GetMonitorFrequency(LPDWORD 0x%x);", a);
  HRESULT x = mOriginal->GetMonitorFrequency(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw4::GetScanLine(LPDWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw4::GetScanLine(LPDWORD 0x%x);", a);
  HRESULT x = mOriginal->GetScanLine(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw4::GetVerticalBlankStatus(LPBOOL a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw4::GetVerticalBlankStatus(LPBOOL 0x%x);", a);
  HRESULT x = mOriginal->GetVerticalBlankStatus(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw4::Initialize(GUID FAR * a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw4::Initialize(GUID FAR *);");
  HRESULT x = mOriginal->Initialize(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw4::RestoreDisplayMode()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw4::RestoreDisplayMode();");
  HRESULT x = mOriginal->RestoreDisplayMode();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw4::SetCooperativeLevel(HWND a, DWORD b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw4::SetCooperativeLevel(HWND 0x%x, DWORD %d);", a, b);
  HRESULT x = mOriginal->SetCooperativeLevel(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw4::SetDisplayMode(DWORD a, DWORD b, DWORD c, DWORD d, DWORD e)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw4::SetDisplayMode(DWORD %d, DWORD %d, DWORD %d, DWORD %d, DWORD %d);", a, b, c, d, e);
  HRESULT x = mOriginal->SetDisplayMode(a, b, c, d, e);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw4::WaitForVerticalBlank(DWORD a, HANDLE b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw4::WaitForVerticalBlank(DWORD %d, HANDLE);", a);
  HRESULT x = mOriginal->WaitForVerticalBlank(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw4::GetAvailableVidMem(LPDDSCAPS2 a, LPDWORD b, LPDWORD c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw4::GetAvailableVidMem(LPDDSCAPS2 0x%x, LPDWORD 0x%x, LPDWORD 0x%x);", a, b, c);
  HRESULT x = mOriginal->GetAvailableVidMem(a, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw4::GetSurfaceFromDC(HDC a, LPDIRECTDRAWSURFACE4 * b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw4::GetSurfaceFromDC(HDC, LPDIRECTDRAWSURFACE4 * 0x%x);", b);
  HRESULT x = mOriginal->GetSurfaceFromDC(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  IDirectDrawSurface4 * n = (IDirectDrawSurface4 *)wrapfetch(*b);
  if (n == NULL && *b != NULL)
  {
    n = (IDirectDrawSurface4 *)new myIDirectDrawSurface4(*b);
    wrapstore(n, *b);
    logf("Wrapped.\n");
  }
  *b = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw4::RestoreAllSurfaces()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw4::RestoreAllSurfaces();");
  HRESULT x = mOriginal->RestoreAllSurfaces();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw4::TestCooperativeLevel()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw4::TestCooperativeLevel();");
  HRESULT x = mOriginal->TestCooperativeLevel();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw4::GetDeviceIdentifier(LPDDDEVICEIDENTIFIER a, DWORD b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw4::GetDeviceIdentifier(LPDDDEVICEIDENTIFIER 0x%x, DWORD %d);", a, b);
  HRESULT x = mOriginal->GetDeviceIdentifier(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

