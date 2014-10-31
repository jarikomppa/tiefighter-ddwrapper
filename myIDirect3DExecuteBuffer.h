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

class myIDirect3DExecuteBuffer : public IDirect3DExecuteBuffer
{
public:
  myIDirect3DExecuteBuffer(IDirect3DExecuteBuffer * aOriginal);
  ~myIDirect3DExecuteBuffer();

  HRESULT __stdcall QueryInterface(REFIID riid, LPVOID * ppvObj);
  ULONG __stdcall AddRef();
  ULONG __stdcall Release();
  HRESULT __stdcall Initialize(LPDIRECT3DDEVICE a, LPD3DEXECUTEBUFFERDESC b);
  HRESULT __stdcall Lock(LPD3DEXECUTEBUFFERDESC a);
  HRESULT __stdcall Unlock();
  HRESULT __stdcall SetExecuteData(LPD3DEXECUTEDATA a);
  HRESULT __stdcall GetExecuteData(LPD3DEXECUTEDATA a);
  HRESULT __stdcall Validate(LPDWORD a, LPD3DVALIDATECALLBACK b, LPVOID c, DWORD d);
  HRESULT __stdcall Optimize(DWORD a);

  IDirect3DExecuteBuffer * mOriginal;
};

