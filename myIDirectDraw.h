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

#pragma once

class myIDirectDraw : public IDirectDraw
{
public:
  myIDirectDraw(IDirectDraw * aOriginal);
  ~myIDirectDraw();

  HRESULT __stdcall QueryInterface(REFIID riid, LPVOID FAR * ppvObj);
  ULONG __stdcall AddRef();
  ULONG __stdcall Release();
  HRESULT __stdcall Compact();
  HRESULT __stdcall CreateClipper(DWORD a, LPDIRECTDRAWCLIPPER FAR * b, IUnknown FAR * c);
  HRESULT __stdcall CreatePalette(DWORD a, LPPALETTEENTRY b, LPDIRECTDRAWPALETTE FAR * c, IUnknown FAR * d);
  HRESULT __stdcall CreateSurface(LPDDSURFACEDESC a, LPDIRECTDRAWSURFACE FAR * b, IUnknown FAR * c);
  HRESULT __stdcall DuplicateSurface(LPDIRECTDRAWSURFACE a, LPDIRECTDRAWSURFACE FAR * b);
  HRESULT __stdcall EnumDisplayModes(DWORD a, LPDDSURFACEDESC b, LPVOID c, LPDDENUMMODESCALLBACK d);
  HRESULT __stdcall EnumSurfaces(DWORD a, LPDDSURFACEDESC b, LPVOID c, LPDDENUMSURFACESCALLBACK d);
  HRESULT __stdcall FlipToGDISurface();
  HRESULT __stdcall GetCaps(LPDDCAPS a, LPDDCAPS b);
  HRESULT __stdcall GetDisplayMode(LPDDSURFACEDESC a);
  HRESULT __stdcall GetFourCCCodes(LPDWORD a, LPDWORD b);
  HRESULT __stdcall GetGDISurface(LPDIRECTDRAWSURFACE FAR * a);
  HRESULT __stdcall GetMonitorFrequency(LPDWORD a);
  HRESULT __stdcall GetScanLine(LPDWORD a);
  HRESULT __stdcall GetVerticalBlankStatus(LPBOOL a);
  HRESULT __stdcall Initialize(GUID FAR * a);
  HRESULT __stdcall RestoreDisplayMode();
  HRESULT __stdcall SetCooperativeLevel(HWND a, DWORD b);
  HRESULT __stdcall SetDisplayMode(DWORD a, DWORD b, DWORD c);
  HRESULT __stdcall WaitForVerticalBlank(DWORD a, HANDLE b);

  IDirectDraw * mOriginal;
};

