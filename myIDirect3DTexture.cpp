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
#include "myIDirect3DTexture.h"

myIDirect3DTexture::myIDirect3DTexture(IDirect3DTexture * aOriginal)
{
  logf("myIDirect3DTexture ctor\n");
  mOriginal = aOriginal;
}

myIDirect3DTexture::~myIDirect3DTexture()
{
  logf("myIDirect3DTexture dtor\n");
}

HRESULT __stdcall myIDirect3DTexture::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DTexture::QueryInterface(REFIID, LPVOID * 0x%x);", ppvObj);
  HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
  logfc(" -> return %d\n", x);
  pushtab();
  if (x == 0) genericQueryInterface(riid, ppvObj);
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirect3DTexture::AddRef()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DTexture::AddRef();");
  ULONG x = mOriginal->AddRef();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirect3DTexture::Release()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DTexture::Release();");
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

HRESULT __stdcall myIDirect3DTexture::Initialize(LPDIRECT3DDEVICE a, LPDIRECTDRAWSURFACE b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DTexture::Initialize(LPDIRECT3DDEVICE 0x%x, LPDIRECTDRAWSURFACE 0x%x);", a, b);
  HRESULT x = mOriginal->Initialize((a)?((myIDirect3DDevice *)a)->mOriginal:0, (b)?((myIDirectDrawSurface *)b)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DTexture::GetHandle(LPDIRECT3DDEVICE a, LPD3DTEXTUREHANDLE b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DTexture::GetHandle(LPDIRECT3DDEVICE 0x%x, LPD3DTEXTUREHANDLE 0x%x);", a, b);
  HRESULT x = mOriginal->GetHandle((a)?((myIDirect3DDevice *)a)->mOriginal:0, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DTexture::PaletteChanged(DWORD a, DWORD b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DTexture::PaletteChanged(DWORD %d, DWORD %d);", a, b);
  HRESULT x = mOriginal->PaletteChanged(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DTexture::Load(LPDIRECT3DTEXTURE a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DTexture::Load(LPDIRECT3DTEXTURE 0x%x);", a);
  HRESULT x = mOriginal->Load((a)?((myIDirect3DTexture *)a)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DTexture::Unload()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DTexture::Unload();");
  HRESULT x = mOriginal->Unload();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

