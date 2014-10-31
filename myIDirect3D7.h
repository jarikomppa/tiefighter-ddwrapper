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

class myIDirect3D7 : public IDirect3D7
{
public:
  myIDirect3D7(IDirect3D7 * aOriginal);
  ~myIDirect3D7();

  HRESULT __stdcall QueryInterface(REFIID riid, LPVOID * ppvObj);
  ULONG __stdcall AddRef();
  ULONG __stdcall Release();
  HRESULT __stdcall EnumDevices(LPD3DENUMDEVICESCALLBACK7 a, LPVOID b);
  HRESULT __stdcall CreateDevice(REFCLSID a, LPDIRECTDRAWSURFACE7 b, LPDIRECT3DDEVICE7 * c);
  HRESULT __stdcall CreateVertexBuffer(LPD3DVERTEXBUFFERDESC a, LPDIRECT3DVERTEXBUFFER7 * b, DWORD c);
  HRESULT __stdcall EnumZBufferFormats(REFCLSID a, LPD3DENUMPIXELFORMATSCALLBACK b, LPVOID c);
  HRESULT __stdcall EvictManagedTextures();

  IDirect3D7 * mOriginal;
};

