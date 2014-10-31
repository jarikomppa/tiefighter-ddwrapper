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
#include "myIDirectDrawPalette.h"

myIDirectDrawPalette::myIDirectDrawPalette(IDirectDrawPalette * aOriginal)
{
  logf("myIDirectDrawPalette ctor\n");
  mOriginal = aOriginal;
}

myIDirectDrawPalette::~myIDirectDrawPalette()
{
  logf("myIDirectDrawPalette dtor\n");
}

HRESULT __stdcall myIDirectDrawPalette::QueryInterface(REFIID riid, LPVOID FAR * ppvObj)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawPalette::QueryInterface(REFIID, LPVOID FAR * 0x%x);", ppvObj);
  HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
  logfc(" -> return %d\n", x);
  pushtab();
  if (x == 0) genericQueryInterface(riid, ppvObj);
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirectDrawPalette::AddRef()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawPalette::AddRef();");
  ULONG x = mOriginal->AddRef();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirectDrawPalette::Release()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawPalette::Release();");
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

HRESULT __stdcall myIDirectDrawPalette::GetCaps(LPDWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawPalette::GetCaps(LPDWORD 0x%x);", a);
  HRESULT x = mOriginal->GetCaps(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawPalette::GetEntries(DWORD a, DWORD b, DWORD c, LPPALETTEENTRY d)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawPalette::GetEntries(DWORD %d, DWORD %d, DWORD %d, LPPALETTEENTRY 0x%x);", a, b, c, d);
  HRESULT x = mOriginal->GetEntries(a, b, c, d);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawPalette::Initialize(LPDIRECTDRAW a, DWORD b, LPPALETTEENTRY c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawPalette::Initialize(LPDIRECTDRAW 0x%x, DWORD %d, LPPALETTEENTRY 0x%x);", a, b, c);
  HRESULT x = mOriginal->Initialize((a)?((myIDirectDraw *)a)->mOriginal:0, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawPalette::SetEntries(DWORD a, DWORD b, DWORD c, LPPALETTEENTRY d)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawPalette::SetEntries(DWORD %d, DWORD %d, DWORD %d, LPPALETTEENTRY 0x%x);", a, b, c, d);
  HRESULT x = mOriginal->SetEntries(a, b, c, d);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

