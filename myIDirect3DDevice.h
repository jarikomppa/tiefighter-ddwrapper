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

class myIDirect3DDevice : public IDirect3DDevice
{
public:
  myIDirect3DDevice(IDirect3DDevice * aOriginal);
  ~myIDirect3DDevice();

  HRESULT __stdcall QueryInterface(REFIID riid, LPVOID * ppvObj);
  ULONG __stdcall AddRef();
  ULONG __stdcall Release();
  HRESULT __stdcall Initialize(LPDIRECT3D a, LPGUID b, LPD3DDEVICEDESC c);
  HRESULT __stdcall GetCaps(LPD3DDEVICEDESC a, LPD3DDEVICEDESC b);
  HRESULT __stdcall SwapTextureHandles(LPDIRECT3DTEXTURE a, LPDIRECT3DTEXTURE b);
  HRESULT __stdcall CreateExecuteBuffer(LPD3DEXECUTEBUFFERDESC a, LPDIRECT3DEXECUTEBUFFER * b, IUnknown * c);
  HRESULT __stdcall GetStats(LPD3DSTATS a);
  HRESULT __stdcall Execute(LPDIRECT3DEXECUTEBUFFER a, LPDIRECT3DVIEWPORT b, DWORD c);
  HRESULT __stdcall AddViewport(LPDIRECT3DVIEWPORT a);
  HRESULT __stdcall DeleteViewport(LPDIRECT3DVIEWPORT a);
  HRESULT __stdcall NextViewport(LPDIRECT3DVIEWPORT a, LPDIRECT3DVIEWPORT * b, DWORD c);
  HRESULT __stdcall Pick(LPDIRECT3DEXECUTEBUFFER a, LPDIRECT3DVIEWPORT b, DWORD c, LPD3DRECT d);
  HRESULT __stdcall GetPickRecords(LPDWORD a, LPD3DPICKRECORD b);
  HRESULT __stdcall EnumTextureFormats(LPD3DENUMTEXTUREFORMATSCALLBACK a, LPVOID b);
  HRESULT __stdcall CreateMatrix(LPD3DMATRIXHANDLE a);
  HRESULT __stdcall SetMatrix(D3DMATRIXHANDLE a, const LPD3DMATRIX b);
  HRESULT __stdcall GetMatrix(D3DMATRIXHANDLE a, LPD3DMATRIX b);
  HRESULT __stdcall DeleteMatrix(D3DMATRIXHANDLE a);
  HRESULT __stdcall BeginScene();
  HRESULT __stdcall EndScene();
  HRESULT __stdcall GetDirect3D(LPDIRECT3D * a);

  IDirect3DDevice * mOriginal;
};

