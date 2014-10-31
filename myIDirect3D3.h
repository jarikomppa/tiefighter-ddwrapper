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

class myIDirect3D3 : public IDirect3D3
{
public:
  myIDirect3D3(IDirect3D3 * aOriginal);
  ~myIDirect3D3();

  HRESULT __stdcall QueryInterface(REFIID riid, LPVOID * ppvObj);
  ULONG __stdcall AddRef();
  ULONG __stdcall Release();
  HRESULT __stdcall EnumDevices(LPD3DENUMDEVICESCALLBACK a, LPVOID b);
  HRESULT __stdcall CreateLight(LPDIRECT3DLIGHT * a, LPUNKNOWN b);
  HRESULT __stdcall CreateMaterial(LPDIRECT3DMATERIAL3 * a, LPUNKNOWN b);
  HRESULT __stdcall CreateViewport(LPDIRECT3DVIEWPORT3 * a, LPUNKNOWN b);
  HRESULT __stdcall FindDevice(LPD3DFINDDEVICESEARCH a, LPD3DFINDDEVICERESULT b);
  HRESULT __stdcall CreateDevice(REFCLSID a, LPDIRECTDRAWSURFACE4 b, LPDIRECT3DDEVICE3 * c, LPUNKNOWN d);
  HRESULT __stdcall CreateVertexBuffer(LPD3DVERTEXBUFFERDESC a, LPDIRECT3DVERTEXBUFFER * b, DWORD c, LPUNKNOWN d);
  HRESULT __stdcall EnumZBufferFormats(REFCLSID a, LPD3DENUMPIXELFORMATSCALLBACK b, LPVOID c);
  HRESULT __stdcall EvictManagedTextures();

  IDirect3D3 * mOriginal;
};

