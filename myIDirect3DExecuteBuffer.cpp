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
#include "myIDirect3DExecuteBuffer.h"

myIDirect3DExecuteBuffer::myIDirect3DExecuteBuffer(IDirect3DExecuteBuffer * aOriginal)
{
  logf("myIDirect3DExecuteBuffer ctor\n");
  mOriginal = aOriginal;
}

myIDirect3DExecuteBuffer::~myIDirect3DExecuteBuffer()
{
  logf("myIDirect3DExecuteBuffer dtor\n");
}

HRESULT __stdcall myIDirect3DExecuteBuffer::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DExecuteBuffer::QueryInterface(REFIID, LPVOID * 0x%x);", ppvObj);
  HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
  logfc(" -> return %d\n", x);
  pushtab();
  if (x == 0) genericQueryInterface(riid, ppvObj);
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirect3DExecuteBuffer::AddRef()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DExecuteBuffer::AddRef();");
  ULONG x = mOriginal->AddRef();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirect3DExecuteBuffer::Release()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DExecuteBuffer::Release();");
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

HRESULT __stdcall myIDirect3DExecuteBuffer::Initialize(LPDIRECT3DDEVICE a, LPD3DEXECUTEBUFFERDESC b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DExecuteBuffer::Initialize(LPDIRECT3DDEVICE 0x%x, LPD3DEXECUTEBUFFERDESC 0x%x);", a, b);
  HRESULT x = mOriginal->Initialize((a)?((myIDirect3DDevice *)a)->mOriginal:0, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DExecuteBuffer::Lock(LPD3DEXECUTEBUFFERDESC a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DExecuteBuffer::Lock(LPD3DEXECUTEBUFFERDESC 0x%x);", a);
  HRESULT x = mOriginal->Lock(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DExecuteBuffer::Unlock()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DExecuteBuffer::Unlock();");
  HRESULT x = mOriginal->Unlock();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DExecuteBuffer::SetExecuteData(LPD3DEXECUTEDATA a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DExecuteBuffer::SetExecuteData(LPD3DEXECUTEDATA 0x%x);", a);
  HRESULT x = mOriginal->SetExecuteData(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DExecuteBuffer::GetExecuteData(LPD3DEXECUTEDATA a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DExecuteBuffer::GetExecuteData(LPD3DEXECUTEDATA 0x%x);", a);
  HRESULT x = mOriginal->GetExecuteData(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DExecuteBuffer::Validate(LPDWORD a, LPD3DVALIDATECALLBACK b, LPVOID c, DWORD d)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DExecuteBuffer::Validate(LPDWORD 0x%x, LPD3DVALIDATECALLBACK 0x%x, LPVOID 0x%x, DWORD %d);", a, b, c, d);
  HRESULT x = mOriginal->Validate(a, b, c, d);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DExecuteBuffer::Optimize(DWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DExecuteBuffer::Optimize(DWORD %d);", a);
  HRESULT x = mOriginal->Optimize(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

