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
#include "myIDirect3DVertexBuffer.h"

myIDirect3DVertexBuffer::myIDirect3DVertexBuffer(IDirect3DVertexBuffer * aOriginal)
{
  logf("myIDirect3DVertexBuffer ctor\n");
  mOriginal = aOriginal;
}

myIDirect3DVertexBuffer::~myIDirect3DVertexBuffer()
{
  logf("myIDirect3DVertexBuffer dtor\n");
}

HRESULT __stdcall myIDirect3DVertexBuffer::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DVertexBuffer::QueryInterface(REFIID, LPVOID * 0x%x);", ppvObj);
  HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
  logfc(" -> return %d\n", x);
  pushtab();
  if (x == 0) genericQueryInterface(riid, ppvObj);
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirect3DVertexBuffer::AddRef()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DVertexBuffer::AddRef();");
  ULONG x = mOriginal->AddRef();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirect3DVertexBuffer::Release()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DVertexBuffer::Release();");
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

HRESULT __stdcall myIDirect3DVertexBuffer::Lock(DWORD a, LPVOID * b, LPDWORD c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DVertexBuffer::Lock(DWORD %d, LPVOID * 0x%x, LPDWORD 0x%x);", a, b, c);
  HRESULT x = mOriginal->Lock(a, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DVertexBuffer::Unlock()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DVertexBuffer::Unlock();");
  HRESULT x = mOriginal->Unlock();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DVertexBuffer::ProcessVertices(DWORD a, DWORD b, DWORD c, LPDIRECT3DVERTEXBUFFER d, DWORD e, LPDIRECT3DDEVICE3 f, DWORD g)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DVertexBuffer::ProcessVertices(DWORD %d, DWORD %d, DWORD %d, LPDIRECT3DVERTEXBUFFER 0x%x, DWORD %d, LPDIRECT3DDEVICE3 0x%x, DWORD %d);", a, b, c, d, e, f, g);
  HRESULT x = mOriginal->ProcessVertices(a, b, c, (d)?((myIDirect3DVertexBuffer *)d)->mOriginal:0, e, (f)?((myIDirect3DDevice3 *)f)->mOriginal:0, g);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DVertexBuffer::GetVertexBufferDesc(LPD3DVERTEXBUFFERDESC a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DVertexBuffer::GetVertexBufferDesc(LPD3DVERTEXBUFFERDESC 0x%x);", a);
  HRESULT x = mOriginal->GetVertexBufferDesc(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DVertexBuffer::Optimize(LPDIRECT3DDEVICE3 a, DWORD b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DVertexBuffer::Optimize(LPDIRECT3DDEVICE3 0x%x, DWORD %d);", a, b);
  HRESULT x = mOriginal->Optimize((a)?((myIDirect3DDevice3 *)a)->mOriginal:0, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

