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
#include "myIDirectDrawClipper.h"

myIDirectDrawClipper::myIDirectDrawClipper(IDirectDrawClipper * aOriginal)
{
  logf("myIDirectDrawClipper ctor\n");
  mOriginal = aOriginal;
}

myIDirectDrawClipper::~myIDirectDrawClipper()
{
  logf("myIDirectDrawClipper dtor\n");
}

HRESULT __stdcall myIDirectDrawClipper::QueryInterface(REFIID riid, LPVOID FAR * ppvObj)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawClipper::QueryInterface(REFIID, LPVOID FAR * 0x%x);", ppvObj);
  HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
  logfc(" -> return %d\n", x);
  pushtab();
  if (x == 0) genericQueryInterface(riid, ppvObj);
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirectDrawClipper::AddRef()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawClipper::AddRef();");
  ULONG x = mOriginal->AddRef();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirectDrawClipper::Release()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawClipper::Release();");
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

HRESULT __stdcall myIDirectDrawClipper::GetClipList(LPRECT a, LPRGNDATA b, LPDWORD c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawClipper::GetClipList(LPRECT 0x%x, LPRGNDATA 0x%x, LPDWORD 0x%x);", a, b, c);
  HRESULT x = mOriginal->GetClipList(a, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawClipper::GetHWnd(HWND FAR * a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawClipper::GetHWnd(HWND FAR *);");
  HRESULT x = mOriginal->GetHWnd(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawClipper::Initialize(LPDIRECTDRAW a, DWORD b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawClipper::Initialize(LPDIRECTDRAW 0x%x, DWORD %d);", a, b);
  HRESULT x = mOriginal->Initialize((a)?((myIDirectDraw *)a)->mOriginal:0, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawClipper::IsClipListChanged(BOOL FAR * a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawClipper::IsClipListChanged(BOOL FAR *);");
  HRESULT x = mOriginal->IsClipListChanged(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawClipper::SetClipList(LPRGNDATA a, DWORD b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawClipper::SetClipList(LPRGNDATA 0x%x, DWORD %d);", a, b);
  HRESULT x = mOriginal->SetClipList(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawClipper::SetHWnd(DWORD a, HWND b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawClipper::SetHWnd(DWORD %d, HWND 0x%x);", a, b);
  HRESULT x = mOriginal->SetHWnd(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

