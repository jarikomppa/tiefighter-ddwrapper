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

class myIDirect3DViewport : public IDirect3DViewport
{
public:
  myIDirect3DViewport(IDirect3DViewport * aOriginal);
  ~myIDirect3DViewport();

  HRESULT __stdcall QueryInterface(REFIID riid, LPVOID * ppvObj);
  ULONG __stdcall AddRef();
  ULONG __stdcall Release();
  HRESULT __stdcall Initialize(LPDIRECT3D a);
  HRESULT __stdcall GetViewport(LPD3DVIEWPORT a);
  HRESULT __stdcall SetViewport(LPD3DVIEWPORT a);
  HRESULT __stdcall TransformVertices(DWORD a, LPD3DTRANSFORMDATA b, DWORD c, LPDWORD d);
  HRESULT __stdcall LightElements(DWORD a, LPD3DLIGHTDATA b);
  HRESULT __stdcall SetBackground(D3DMATERIALHANDLE a);
  HRESULT __stdcall GetBackground(LPD3DMATERIALHANDLE a, LPBOOL b);
  HRESULT __stdcall SetBackgroundDepth(LPDIRECTDRAWSURFACE a);
  HRESULT __stdcall GetBackgroundDepth(LPDIRECTDRAWSURFACE * a, LPBOOL b);
  HRESULT __stdcall Clear(DWORD a, LPD3DRECT b, DWORD c);
  HRESULT __stdcall AddLight(LPDIRECT3DLIGHT a);
  HRESULT __stdcall DeleteLight(LPDIRECT3DLIGHT a);
  HRESULT __stdcall NextLight(LPDIRECT3DLIGHT a, LPDIRECT3DLIGHT * b, DWORD c);

  IDirect3DViewport * mOriginal;
};

