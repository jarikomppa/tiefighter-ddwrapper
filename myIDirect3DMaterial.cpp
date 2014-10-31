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
#include "myIDirect3DMaterial.h"

myIDirect3DMaterial::myIDirect3DMaterial(IDirect3DMaterial * aOriginal)
{
  logf("myIDirect3DMaterial ctor\n");
  mOriginal = aOriginal;
}

myIDirect3DMaterial::~myIDirect3DMaterial()
{
  logf("myIDirect3DMaterial dtor\n");
}

HRESULT __stdcall myIDirect3DMaterial::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DMaterial::QueryInterface(REFIID, LPVOID * 0x%x);", ppvObj);
  HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
  logfc(" -> return %d\n", x);
  pushtab();
  if (x == 0) genericQueryInterface(riid, ppvObj);
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirect3DMaterial::AddRef()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DMaterial::AddRef();");
  ULONG x = mOriginal->AddRef();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirect3DMaterial::Release()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DMaterial::Release();");
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

HRESULT __stdcall myIDirect3DMaterial::Initialize(LPDIRECT3D a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DMaterial::Initialize(LPDIRECT3D 0x%x);", a);
  HRESULT x = mOriginal->Initialize((a)?((myIDirect3D *)a)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DMaterial::SetMaterial(LPD3DMATERIAL a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DMaterial::SetMaterial(LPD3DMATERIAL 0x%x);", a);
  HRESULT x = mOriginal->SetMaterial(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DMaterial::GetMaterial(LPD3DMATERIAL a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DMaterial::GetMaterial(LPD3DMATERIAL 0x%x);", a);
  HRESULT x = mOriginal->GetMaterial(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DMaterial::GetHandle(LPDIRECT3DDEVICE a, LPD3DMATERIALHANDLE b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DMaterial::GetHandle(LPDIRECT3DDEVICE 0x%x, LPD3DMATERIALHANDLE 0x%x);", a, b);
  HRESULT x = mOriginal->GetHandle((a)?((myIDirect3DDevice *)a)->mOriginal:0, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DMaterial::Reserve()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DMaterial::Reserve();");
  HRESULT x = mOriginal->Reserve();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DMaterial::Unreserve()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DMaterial::Unreserve();");
  HRESULT x = mOriginal->Unreserve();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

