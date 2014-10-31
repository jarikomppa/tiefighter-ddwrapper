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
#include "myIDirect3DMaterial2.h"

myIDirect3DMaterial2::myIDirect3DMaterial2(IDirect3DMaterial2 * aOriginal)
{
  logf("myIDirect3DMaterial2 ctor\n");
  mOriginal = aOriginal;
}

myIDirect3DMaterial2::~myIDirect3DMaterial2()
{
  logf("myIDirect3DMaterial2 dtor\n");
}

HRESULT __stdcall myIDirect3DMaterial2::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DMaterial2::QueryInterface(REFIID, LPVOID * 0x%x);", ppvObj);
  HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
  logfc(" -> return %d\n", x);
  pushtab();
  if (x == 0) genericQueryInterface(riid, ppvObj);
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirect3DMaterial2::AddRef()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DMaterial2::AddRef();");
  ULONG x = mOriginal->AddRef();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirect3DMaterial2::Release()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DMaterial2::Release();");
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

HRESULT __stdcall myIDirect3DMaterial2::SetMaterial(LPD3DMATERIAL a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DMaterial2::SetMaterial(LPD3DMATERIAL 0x%x);", a);
  HRESULT x = mOriginal->SetMaterial(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DMaterial2::GetMaterial(LPD3DMATERIAL a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DMaterial2::GetMaterial(LPD3DMATERIAL 0x%x);", a);
  HRESULT x = mOriginal->GetMaterial(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DMaterial2::GetHandle(LPDIRECT3DDEVICE2 a, LPD3DMATERIALHANDLE b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DMaterial2::GetHandle(LPDIRECT3DDEVICE2 0x%x, LPD3DMATERIALHANDLE 0x%x);", a, b);
  HRESULT x = mOriginal->GetHandle((a)?((myIDirect3DDevice2 *)a)->mOriginal:0, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

