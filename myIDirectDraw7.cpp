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
#include "myIDirectDraw7.h"

myIDirectDraw7::myIDirectDraw7(IDirectDraw7 * aOriginal)
{
  logf("myIDirectDraw7 ctor\n");
  mOriginal = aOriginal;
}

myIDirectDraw7::~myIDirectDraw7()
{
  logf("myIDirectDraw7 dtor\n");
}

HRESULT __stdcall myIDirectDraw7::QueryInterface(REFIID riid, LPVOID FAR * ppvObj)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw7::QueryInterface(REFIID, LPVOID FAR * 0x%x);", ppvObj);
  HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
  logfc(" -> return %d\n", x);
  pushtab();
  if (x == 0) genericQueryInterface(riid, ppvObj);
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirectDraw7::AddRef()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw7::AddRef();");
  ULONG x = mOriginal->AddRef();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirectDraw7::Release()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw7::Release();");
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

HRESULT __stdcall myIDirectDraw7::Compact()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw7::Compact();");
  HRESULT x = mOriginal->Compact();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw7::CreateClipper(DWORD a, LPDIRECTDRAWCLIPPER FAR * b, IUnknown FAR * c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw7::CreateClipper(DWORD %d, LPDIRECTDRAWCLIPPER FAR * 0x%x, IUnknown FAR *);", a, b);
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

HRESULT __stdcall myIDirectDraw7::CreatePalette(DWORD a, LPPALETTEENTRY b, LPDIRECTDRAWPALETTE FAR * c, IUnknown FAR * d)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw7::CreatePalette(DWORD %d, LPPALETTEENTRY 0x%x, LPDIRECTDRAWPALETTE FAR * 0x%x, IUnknown FAR *);", a, b, c);
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

HRESULT __stdcall myIDirectDraw7::CreateSurface(LPDDSURFACEDESC2 a, LPDIRECTDRAWSURFACE7 FAR * b, IUnknown FAR * c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw7::CreateSurface(LPDDSURFACEDESC2 0x%x, LPDIRECTDRAWSURFACE7 FAR * 0x%x, IUnknown FAR *);", a, b);
  HRESULT x = mOriginal->CreateSurface(a, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  IDirectDrawSurface7 * n = (IDirectDrawSurface7 *)wrapfetch(*b);
  if (n == NULL && *b != NULL)
  {
    n = (IDirectDrawSurface7 *)new myIDirectDrawSurface7(*b);
    wrapstore(n, *b);
    logf("Wrapped.\n");
  }
  *b = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw7::DuplicateSurface(LPDIRECTDRAWSURFACE7 a, LPDIRECTDRAWSURFACE7 FAR * b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw7::DuplicateSurface(LPDIRECTDRAWSURFACE7 0x%x, LPDIRECTDRAWSURFACE7 FAR * 0x%x);", a, b);
  HRESULT x = mOriginal->DuplicateSurface((a)?((myIDirectDrawSurface7 *)a)->mOriginal:0, b);
  logfc(" -> return %d\n", x);
  pushtab();
  IDirectDrawSurface7 * n = (IDirectDrawSurface7 *)wrapfetch(*b);
  if (n == NULL && *b != NULL)
  {
    n = (IDirectDrawSurface7 *)new myIDirectDrawSurface7(*b);
    wrapstore(n, *b);
    logf("Wrapped.\n");
  }
  *b = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw7::EnumDisplayModes(DWORD a, LPDDSURFACEDESC2 b, LPVOID c, LPDDENUMMODESCALLBACK2 d)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw7::EnumDisplayModes(DWORD %d, LPDDSURFACEDESC2 0x%x, LPVOID 0x%x, LPDDENUMMODESCALLBACK2 0x%x);", a, b, c, d);
  HRESULT x = mOriginal->EnumDisplayModes(a, b, c, d);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw7::EnumSurfaces(DWORD a, LPDDSURFACEDESC2 b, LPVOID c, LPDDENUMSURFACESCALLBACK7 d)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw7::EnumSurfaces(DWORD %d, LPDDSURFACEDESC2 0x%x, LPVOID 0x%x, LPDDENUMSURFACESCALLBACK7 0x%x);", a, b, c, d);
  HRESULT x = mOriginal->EnumSurfaces(a, b, c, d);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw7::FlipToGDISurface()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw7::FlipToGDISurface();");
  HRESULT x = mOriginal->FlipToGDISurface();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw7::GetCaps(LPDDCAPS a, LPDDCAPS b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw7::GetCaps(LPDDCAPS 0x%x, LPDDCAPS 0x%x);", a, b);
  HRESULT x = mOriginal->GetCaps(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw7::GetDisplayMode(LPDDSURFACEDESC2 a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw7::GetDisplayMode(LPDDSURFACEDESC2 0x%x);", a);
  HRESULT x = mOriginal->GetDisplayMode(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw7::GetFourCCCodes(LPDWORD a, LPDWORD b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw7::GetFourCCCodes(LPDWORD 0x%x, LPDWORD 0x%x);", a, b);
  HRESULT x = mOriginal->GetFourCCCodes(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw7::GetGDISurface(LPDIRECTDRAWSURFACE7 FAR * a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw7::GetGDISurface(LPDIRECTDRAWSURFACE7 FAR * 0x%x);", a);
  HRESULT x = mOriginal->GetGDISurface(a);
  logfc(" -> return %d\n", x);
  pushtab();
  IDirectDrawSurface7 * n = (IDirectDrawSurface7 *)wrapfetch(*a);
  if (n == NULL && *a != NULL)
  {
    n = (IDirectDrawSurface7 *)new myIDirectDrawSurface7(*a);
    wrapstore(n, *a);
    logf("Wrapped.\n");
  }
  *a = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw7::GetMonitorFrequency(LPDWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw7::GetMonitorFrequency(LPDWORD 0x%x);", a);
  HRESULT x = mOriginal->GetMonitorFrequency(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw7::GetScanLine(LPDWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw7::GetScanLine(LPDWORD 0x%x);", a);
  HRESULT x = mOriginal->GetScanLine(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw7::GetVerticalBlankStatus(LPBOOL a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw7::GetVerticalBlankStatus(LPBOOL 0x%x);", a);
  HRESULT x = mOriginal->GetVerticalBlankStatus(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw7::Initialize(GUID FAR * a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw7::Initialize(GUID FAR *);");
  HRESULT x = mOriginal->Initialize(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw7::RestoreDisplayMode()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw7::RestoreDisplayMode();");
  HRESULT x = mOriginal->RestoreDisplayMode();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw7::SetCooperativeLevel(HWND a, DWORD b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw7::SetCooperativeLevel(HWND 0x%x, DWORD %d);", a, b);
  HRESULT x = mOriginal->SetCooperativeLevel(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw7::SetDisplayMode(DWORD a, DWORD b, DWORD c, DWORD d, DWORD e)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw7::SetDisplayMode(DWORD %d, DWORD %d, DWORD %d, DWORD %d, DWORD %d);", a, b, c, d, e);
  HRESULT x = mOriginal->SetDisplayMode(a, b, c, d, e);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw7::WaitForVerticalBlank(DWORD a, HANDLE b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw7::WaitForVerticalBlank(DWORD %d, HANDLE);", a);
  HRESULT x = mOriginal->WaitForVerticalBlank(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw7::GetAvailableVidMem(LPDDSCAPS2 a, LPDWORD b, LPDWORD c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw7::GetAvailableVidMem(LPDDSCAPS2 0x%x, LPDWORD 0x%x, LPDWORD 0x%x);", a, b, c);
  HRESULT x = mOriginal->GetAvailableVidMem(a, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw7::GetSurfaceFromDC(HDC a, LPDIRECTDRAWSURFACE7 * b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw7::GetSurfaceFromDC(HDC, LPDIRECTDRAWSURFACE7 * 0x%x);", b);
  HRESULT x = mOriginal->GetSurfaceFromDC(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  IDirectDrawSurface7 * n = (IDirectDrawSurface7 *)wrapfetch(*b);
  if (n == NULL && *b != NULL)
  {
    n = (IDirectDrawSurface7 *)new myIDirectDrawSurface7(*b);
    wrapstore(n, *b);
    logf("Wrapped.\n");
  }
  *b = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw7::RestoreAllSurfaces()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw7::RestoreAllSurfaces();");
  HRESULT x = mOriginal->RestoreAllSurfaces();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw7::TestCooperativeLevel()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw7::TestCooperativeLevel();");
  HRESULT x = mOriginal->TestCooperativeLevel();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw7::GetDeviceIdentifier(LPDDDEVICEIDENTIFIER2 a, DWORD b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw7::GetDeviceIdentifier(LPDDDEVICEIDENTIFIER2 0x%x, DWORD %d);", a, b);
  HRESULT x = mOriginal->GetDeviceIdentifier(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw7::StartModeTest(LPSIZE a, DWORD b, DWORD c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw7::StartModeTest(LPSIZE 0x%x, DWORD %d, DWORD %d);", a, b, c);
  HRESULT x = mOriginal->StartModeTest(a, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDraw7::EvaluateMode(DWORD a, DWORD * b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw7::EvaluateMode(DWORD %d, DWORD *);", a);
  HRESULT x = mOriginal->EvaluateMode(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

