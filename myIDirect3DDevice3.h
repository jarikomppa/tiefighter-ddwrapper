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

class myIDirect3DDevice3 : public IDirect3DDevice3
{
public:
  myIDirect3DDevice3(IDirect3DDevice3 * aOriginal);
  ~myIDirect3DDevice3();

  HRESULT __stdcall QueryInterface(REFIID riid, LPVOID * ppvObj);
  ULONG __stdcall AddRef();
  ULONG __stdcall Release();
  HRESULT __stdcall GetCaps(LPD3DDEVICEDESC a, LPD3DDEVICEDESC b);
  HRESULT __stdcall GetStats(LPD3DSTATS a);
  HRESULT __stdcall AddViewport(LPDIRECT3DVIEWPORT3 a);
  HRESULT __stdcall DeleteViewport(LPDIRECT3DVIEWPORT3 a);
  HRESULT __stdcall NextViewport(LPDIRECT3DVIEWPORT3 a, LPDIRECT3DVIEWPORT3 * b, DWORD c);
  HRESULT __stdcall EnumTextureFormats(LPD3DENUMPIXELFORMATSCALLBACK a, LPVOID b);
  HRESULT __stdcall BeginScene();
  HRESULT __stdcall EndScene();
  HRESULT __stdcall GetDirect3D(LPDIRECT3D3 * a);
  HRESULT __stdcall SetCurrentViewport(LPDIRECT3DVIEWPORT3 a);
  HRESULT __stdcall GetCurrentViewport(LPDIRECT3DVIEWPORT3 * a);
  HRESULT __stdcall SetRenderTarget(LPDIRECTDRAWSURFACE4 a, DWORD b);
  HRESULT __stdcall GetRenderTarget(LPDIRECTDRAWSURFACE4 * a);
  HRESULT __stdcall Begin(D3DPRIMITIVETYPE a, DWORD b, DWORD c);
  HRESULT __stdcall BeginIndexed(D3DPRIMITIVETYPE a, DWORD b, LPVOID c, DWORD d, DWORD e);
  HRESULT __stdcall Vertex(LPVOID a);
  HRESULT __stdcall Index(WORD a);
  HRESULT __stdcall End(DWORD a);
  HRESULT __stdcall GetRenderState(D3DRENDERSTATETYPE a, LPDWORD b);
  HRESULT __stdcall SetRenderState(D3DRENDERSTATETYPE a, DWORD b);
  HRESULT __stdcall GetLightState(D3DLIGHTSTATETYPE a, LPDWORD b);
  HRESULT __stdcall SetLightState(D3DLIGHTSTATETYPE a, DWORD b);
  HRESULT __stdcall SetTransform(D3DTRANSFORMSTATETYPE a, LPD3DMATRIX b);
  HRESULT __stdcall GetTransform(D3DTRANSFORMSTATETYPE a, LPD3DMATRIX b);
  HRESULT __stdcall MultiplyTransform(D3DTRANSFORMSTATETYPE a, LPD3DMATRIX b);
  HRESULT __stdcall DrawPrimitive(D3DPRIMITIVETYPE a, DWORD b, LPVOID c, DWORD d, DWORD e);
  HRESULT __stdcall DrawIndexedPrimitive(D3DPRIMITIVETYPE a, DWORD b, LPVOID c, DWORD d, LPWORD e, DWORD f, DWORD g);
  HRESULT __stdcall SetClipStatus(LPD3DCLIPSTATUS a);
  HRESULT __stdcall GetClipStatus(LPD3DCLIPSTATUS a);
  HRESULT __stdcall DrawPrimitiveStrided(D3DPRIMITIVETYPE a, DWORD b, LPD3DDRAWPRIMITIVESTRIDEDDATA c, DWORD d, DWORD e);
  HRESULT __stdcall DrawIndexedPrimitiveStrided(D3DPRIMITIVETYPE a, DWORD b, LPD3DDRAWPRIMITIVESTRIDEDDATA c, DWORD d, LPWORD e, DWORD f, DWORD g);
  HRESULT __stdcall DrawPrimitiveVB(D3DPRIMITIVETYPE a, LPDIRECT3DVERTEXBUFFER b, DWORD c, DWORD d, DWORD e);
  HRESULT __stdcall DrawIndexedPrimitiveVB(D3DPRIMITIVETYPE a, LPDIRECT3DVERTEXBUFFER b, LPWORD c, DWORD d, DWORD e);
  HRESULT __stdcall ComputeSphereVisibility(LPD3DVECTOR a, LPD3DVALUE b, DWORD c, DWORD d, LPDWORD e);
  HRESULT __stdcall GetTexture(DWORD a, LPDIRECT3DTEXTURE2 * b);
  HRESULT __stdcall SetTexture(DWORD a, LPDIRECT3DTEXTURE2 b);
  HRESULT __stdcall GetTextureStageState(DWORD a, D3DTEXTURESTAGESTATETYPE b, LPDWORD c);
  HRESULT __stdcall SetTextureStageState(DWORD a, D3DTEXTURESTAGESTATETYPE b, DWORD c);
  HRESULT __stdcall ValidateDevice(LPDWORD a);

  IDirect3DDevice3 * mOriginal;
};

