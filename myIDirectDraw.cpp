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
  logf("myIDirectDraw::QueryInterface(REFIID {%08x-%04x-%04x-%02x%02x%02x%02x%02x%02x%02x%02x}, LPVOID FAR * 0x%x);", 
	  riid.Data1, riid.Data2, riid.Data3, 
	  riid.Data4[0], riid.Data4[1], riid.Data4[2], riid.Data4[3],
	  riid.Data4[4], riid.Data4[5], riid.Data4[6], riid.Data4[7],
	  ppvObj);

#ifdef PASSTHROUGH_WRAPPER
  HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
#else
  HRESULT x = 0;
#endif
  pushtab();
  if (x == 0) genericQueryInterface(riid, ppvObj);
  poptab();
  logfc(" -> return %d\n", x);
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
#ifdef PASSTHROUGH_WRAPPER
  ULONG x = mOriginal->Release();
#else
  ULONG x = 0;
#endif
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
#ifdef PASSTHROUGH_WRAPPER
  HRESULT x = mOriginal->CreatePalette(a, b, c, d);
  pushtab();
  myIDirectDrawPalette * n = (myIDirectDrawPalette *)wrapfetch(*c);
  if (n == NULL && *c != NULL)
  {
    n = (myIDirectDrawPalette *)new myIDirectDrawPalette(*c, a, b);
    wrapstore(n, *c);
    logf("Wrapped.\n");
  }
  *c = n;
  poptab();
#else
  HRESULT x = 0;
  pushtab();
  logfc("\n");
  *c = (myIDirectDrawPalette *)new myIDirectDrawPalette(*c, a, b);
  poptab();
#endif
  LeaveCriticalSection(&gCS);
  logfc(" -> return %d\n", x);
  return x;
}

HRESULT __stdcall myIDirectDraw::CreateSurface(LPDDSURFACEDESC a, LPDIRECTDRAWSURFACE FAR * b, IUnknown FAR * c)
{
  startbiglog();
  EnterCriticalSection(&gCS);
  logf("myIDirectDraw::CreateSurface(LPDDSURFACEDESC 0x%x, LPDIRECTDRAWSURFACE FAR * 0x%x, IUnknown FAR *);\n", a, b);
  pushtab();
	logf("dwHeight = %x (%d)\n", a->dwHeight, a->dwHeight);
	logf("dwWidth = %x (%d)\n", a->dwWidth, a->dwWidth);
	logf("dwLinearSize = %x (%d)\n", a->dwLinearSize, a->dwLinearSize);
	logf("dwBackBufferCount = %x (%d)\n",a->dwBackBufferCount,a->dwBackBufferCount);
	logf("dwRefreshRate = %x (%d)\n", a->dwRefreshRate, a->dwRefreshRate);
	logf("dwAlphaBitDepth = %x (%d)\n", a->dwAlphaBitDepth, a->dwAlphaBitDepth);
	logf("dwReserved = %x (%d)\n", a->dwReserved, a->dwReserved);
	logf("lpSurface = %x (%d)\n", a->lpSurface, a->lpSurface);
	logf("ddsCaps.dwCaps = %x (%d)\n", a->ddsCaps.dwCaps, a->ddsCaps.dwCaps);
	logf("ddpfPixelFormat.dwSize = %x (%d)\n", a->ddpfPixelFormat.dwSize, a->ddpfPixelFormat.dwSize);
	logf("ddpfPixelFormat.dwFlags = %x (%d)\n", a->ddpfPixelFormat.dwFlags, a->ddpfPixelFormat.dwFlags);
	logf("ddpfPixelFormat.dwFourCC = %x (%d)\n", a->ddpfPixelFormat.dwFourCC, a->ddpfPixelFormat.dwFourCC);
	logf("ddpfPixelFormat.dwRGBBitCount = %x (%d)\n", a->ddpfPixelFormat.dwRGBBitCount, a->ddpfPixelFormat.dwRGBBitCount);
	logf("ddpfPixelFormat.dwRBitMask = %x (%d)\n", a->ddpfPixelFormat.dwRBitMask, a->ddpfPixelFormat.dwRBitMask);
	logf("ddpfPixelFormat.dwGBitMask = %x (%d)\n", a->ddpfPixelFormat.dwGBitMask, a->ddpfPixelFormat.dwGBitMask);
	logf("ddpfPixelFormat.dwBBitMask = %x (%d)\n", a->ddpfPixelFormat.dwBBitMask, a->ddpfPixelFormat.dwBBitMask);
	logf("ddpfPixelFormat.dwRGBAlphaBitMask = %x (%d)\n", a->ddpfPixelFormat.dwRGBAlphaBitMask, a->ddpfPixelFormat.dwRGBAlphaBitMask);
  poptab();
#ifdef PASSTHROUGH_WRAPPER
  HRESULT x = mOriginal->CreateSurface(a, b, c);
  pushtab();
  IDirectDrawSurface * n = (IDirectDrawSurface *)wrapfetch(*b);
  if (n == NULL && *b != NULL)
  {
    n = (IDirectDrawSurface *)new myIDirectDrawSurface(*b, a);
    wrapstore(n, *b);
    logf("Wrapped.\n");
  }
  *b = n;
  poptab();
#else
  pushtab();
  *b = (IDirectDrawSurface *)new myIDirectDrawSurface(*b, a);
  poptab();
  HRESULT x = 0;
#endif
  LeaveCriticalSection(&gCS);
  logfc(" -> return %d\n", x);
  endbiglog();
  return x;
}

HRESULT __stdcall myIDirectDraw::DuplicateSurface(LPDIRECTDRAWSURFACE a, LPDIRECTDRAWSURFACE FAR * b)
{
	/*
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
  */
	UNDEFINED_(E_FAIL);
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
#ifdef PASSTHROUGH_WRAPPER
  HRESULT x = mOriginal->FlipToGDISurface();
#else
  HRESULT x = 0;
  gl_updatescreen();
#endif
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

// caps dumped from win7
static unsigned char mycaps[] = {
0x6C, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD1, 0x9D, 0x49, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x90, 0x46, 0x85, 0x00, 0x88, 0xFF, 0x18, 0x00
};

HRESULT __stdcall myIDirectDraw::GetCaps(LPDDCAPS a, LPDDCAPS b)
{
  EnterCriticalSection(&gCS);
  startbiglog();
  logf("myIDirectDraw::GetCaps(LPDDCAPS 0x%x, LPDDCAPS 0x%x);", a, b);
#ifdef PASSTHROUGH_WRAPPER  
  HRESULT x = mOriginal->GetCaps(a, b);
  pushtab();
    logfc("\n");
    loghexdump(sizeof(DDCAPS), a);
  poptab();

  pushtab();
	logf("dwSize = %d\n", a->dwSize);
	logf("dwCaps = %d\n", a->dwCaps);
	logf("dwCaps2 = %d\n", a->dwCaps2);
	logf("dwCKeyCaps = %d\n", a->dwCKeyCaps);
	logf("dwFXCaps = %d\n", a->dwFXCaps);
	logf("dwFXAlphaCaps = %d\n", a->dwFXAlphaCaps);
	logf("dwPalCaps = %d\n", a->dwPalCaps);
	logf("dwSVCaps = %d\n", a->dwSVCaps);
	logf("dwAlphaBltConstBitDepths = %d\n", a->dwAlphaBltConstBitDepths);
	logf("dwAlphaBltPixelBitDepths = %d\n", a->dwAlphaBltPixelBitDepths);
	logf("dwAlphaBltSurfaceBitDepths = %d\n", a->dwAlphaBltSurfaceBitDepths);
	logf("dwAlphaOverlayConstBitDepths = %d\n", a->dwAlphaOverlayConstBitDepths);
	logf("dwAlphaOverlayPixelBitDepths = %d\n", a->dwAlphaOverlayPixelBitDepths);
	logf("dwAlphaOverlaySurfaceBitDepths = %d\n", a->dwAlphaOverlaySurfaceBitDepths);
	logf("dwZBufferBitDepths = %d\n", a->dwZBufferBitDepths);
	logf("dwVidMemTotal = %d\n", a->dwVidMemTotal);
	logf("dwVidMemFree = %d\n", a->dwVidMemFree);
	logf("dwMaxVisibleOverlays = %d\n", a->dwMaxVisibleOverlays);
	logf("dwCurrVisibleOverlays = %d\n", a->dwCurrVisibleOverlays);
	logf("dwNumFourCCCodes = %d\n", a->dwNumFourCCCodes);
	logf("dwAlignBoundarySrc = %d\n", a->dwAlignBoundarySrc);
	logf("dwAlignSizeSrc = %d\n", a->dwAlignSizeSrc);
	logf("dwAlignBoundaryDest = %d\n", a->dwAlignBoundaryDest);
	logf("dwAlignSizeDest = %d\n", a->dwAlignSizeDest);
	logf("dwAlignStrideAlign = %d\n", a->dwAlignStrideAlign);
	//logf("dwRops[DD_ROP_SPACE] = %d\n", dwRops[DD_ROP_SPACE]);
	//logf("ddsCaps = %d\n", ddsCaps);
	logf("dwMinOverlayStretch = %d\n", a->dwMinOverlayStretch);
	logf("dwMaxOverlayStretch = %d\n", a->dwMaxOverlayStretch);
	logf("dwMinLiveVideoStretch = %d\n", a->dwMinLiveVideoStretch);
	logf("dwMaxLiveVideoStretch = %d\n", a->dwMaxLiveVideoStretch);
	logf("dwMinHwCodecStretch = %d\n", a->dwMinHwCodecStretch);
	logf("dwMaxHwCodecStretch = %d\n", a->dwMaxHwCodecStretch);
	logf("dwReserved1 = %d\n", a->dwReserved1);
	logf("dwReserved2 = %d\n", a->dwReserved2);
	logf("dwReserved3 = %d\n", a->dwReserved3);
	poptab();

#else
  HRESULT x = 0;
  if (a)
  {
	  memcpy(a, mycaps, 0x16c);
  }
#endif
  logfc(" -> return %d\n", x);
  endbiglog();	
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
    n = (IDirectDrawSurface *)new myIDirectDrawSurface(*a, NULL);
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
#ifdef PASSTHROUGH_WRAPPER
  HRESULT x = mOriginal->GetMonitorFrequency(a);
  pushtab();
    logfc("\n");
    loghexdump(sizeof(DWORD), a);
  poptab();
#else
  HRESULT x = 0;
  // win7 ddraw gives the actual refresh rate (120 for my monitor), but I guess
  // 60hz should do.. 70hz was a common refresh back then, but games may use this
  // value to create a timer or something and that might blow up if we spend way too
  // much time flipping graphics..
  *a = 60; 
#endif
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
#ifdef PASSTHROUGH_WRAPPER
  HRESULT x = mOriginal->GetVerticalBlankStatus(a);
  pushtab();
    logfc("\n");
    loghexdump(sizeof(BOOL), a);
  poptab();
#else
  HRESULT x = 0;
  // real ddraw in win7 seems to return 0 and 1 on subsequent calls, so we'll follow suit
  static int flipflop = 0;
  flipflop = !flipflop;
  *a = flipflop;
#endif
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
#ifdef PASSTHROUGH_WRAPPER
  HRESULT x = mOriginal->RestoreDisplayMode();
#else
  HRESULT x = 0;
#endif
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
#ifdef PASSTHROUGH_WRAPPER
  HRESULT x = mOriginal->SetCooperativeLevel(a, b);
#else
  HRESULT x = 0;
  gl_init(a);
#endif
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
#ifdef PASSTHROUGH_WRAPPER
  HRESULT x = mOriginal->SetDisplayMode(a, b, c);
#else
  HRESULT x = 0;
  gl_setvideomode(a,b,c);
#endif
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

