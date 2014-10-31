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

class myIDirect3DVertexBuffer : public IDirect3DVertexBuffer
{
public:
  myIDirect3DVertexBuffer(IDirect3DVertexBuffer * aOriginal);
  ~myIDirect3DVertexBuffer();

  HRESULT __stdcall QueryInterface(REFIID riid, LPVOID * ppvObj);
  ULONG __stdcall AddRef();
  ULONG __stdcall Release();
  HRESULT __stdcall Lock(DWORD a, LPVOID * b, LPDWORD c);
  HRESULT __stdcall Unlock();
  HRESULT __stdcall ProcessVertices(DWORD a, DWORD b, DWORD c, LPDIRECT3DVERTEXBUFFER d, DWORD e, LPDIRECT3DDEVICE3 f, DWORD g);
  HRESULT __stdcall GetVertexBufferDesc(LPD3DVERTEXBUFFERDESC a);
  HRESULT __stdcall Optimize(LPDIRECT3DDEVICE3 a, DWORD b);

  IDirect3DVertexBuffer * mOriginal;
};

