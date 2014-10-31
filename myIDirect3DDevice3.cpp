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
#include "myIDirect3DDevice3.h"

myIDirect3DDevice3::myIDirect3DDevice3(IDirect3DDevice3 * aOriginal)
{
  logf("myIDirect3DDevice3 ctor\n");
  mOriginal = aOriginal;
}

myIDirect3DDevice3::~myIDirect3DDevice3()
{
  logf("myIDirect3DDevice3 dtor\n");
}

HRESULT __stdcall myIDirect3DDevice3::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::QueryInterface(REFIID, LPVOID * 0x%x);", ppvObj);
  HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
  logfc(" -> return %d\n", x);
  pushtab();
  if (x == 0) genericQueryInterface(riid, ppvObj);
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirect3DDevice3::AddRef()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::AddRef();");
  ULONG x = mOriginal->AddRef();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirect3DDevice3::Release()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::Release();");
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

HRESULT __stdcall myIDirect3DDevice3::GetCaps(LPD3DDEVICEDESC a, LPD3DDEVICEDESC b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::GetCaps(LPD3DDEVICEDESC 0x%x, LPD3DDEVICEDESC 0x%x);", a, b);
  HRESULT x = mOriginal->GetCaps(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::GetStats(LPD3DSTATS a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::GetStats(LPD3DSTATS 0x%x);", a);
  HRESULT x = mOriginal->GetStats(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::AddViewport(LPDIRECT3DVIEWPORT3 a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::AddViewport(LPDIRECT3DVIEWPORT3 0x%x);", a);
  HRESULT x = mOriginal->AddViewport((a)?((myIDirect3DViewport3 *)a)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::DeleteViewport(LPDIRECT3DVIEWPORT3 a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::DeleteViewport(LPDIRECT3DVIEWPORT3 0x%x);", a);
  HRESULT x = mOriginal->DeleteViewport((a)?((myIDirect3DViewport3 *)a)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::NextViewport(LPDIRECT3DVIEWPORT3 a, LPDIRECT3DVIEWPORT3 * b, DWORD c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::NextViewport(LPDIRECT3DVIEWPORT3 0x%x, LPDIRECT3DVIEWPORT3 * 0x%x, DWORD %d);", a, b, c);
  HRESULT x = mOriginal->NextViewport((a)?((myIDirect3DViewport3 *)a)->mOriginal:0, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  myIDirect3DViewport3 * n = (myIDirect3DViewport3 *)wrapfetch(*b);
  if (n == NULL && *b != NULL)
  {
    n = (myIDirect3DViewport3 *)new myIDirect3DViewport3(*b);
    wrapstore(n, *b);
    logf("Wrapped.\n");
  }
  *b = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::EnumTextureFormats(LPD3DENUMPIXELFORMATSCALLBACK a, LPVOID b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::EnumTextureFormats(LPD3DENUMPIXELFORMATSCALLBACK 0x%x, LPVOID 0x%x);", a, b);
  HRESULT x = mOriginal->EnumTextureFormats(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::BeginScene()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::BeginScene();");
  HRESULT x = mOriginal->BeginScene();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::EndScene()
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::EndScene();");
  HRESULT x = mOriginal->EndScene();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::GetDirect3D(LPDIRECT3D3 * a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::GetDirect3D(LPDIRECT3D3 * 0x%x);", a);
  HRESULT x = mOriginal->GetDirect3D(a);
  logfc(" -> return %d\n", x);
  pushtab();
  LPDIRECT3D3 n = (LPDIRECT3D3)wrapfetch(*a);
  if (n == NULL && *a != NULL)
  {
    n = (LPDIRECT3D3)new myIDirect3D3(*a);
    wrapstore(n, *a);
    logf("Wrapped.\n");
  }
  *a = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::SetCurrentViewport(LPDIRECT3DVIEWPORT3 a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::SetCurrentViewport(LPDIRECT3DVIEWPORT3 0x%x);", a);
  HRESULT x = mOriginal->SetCurrentViewport((a)?((myIDirect3DViewport3 *)a)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::GetCurrentViewport(LPDIRECT3DVIEWPORT3 * a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::GetCurrentViewport(LPDIRECT3DVIEWPORT3 * 0x%x);", a);
  HRESULT x = mOriginal->GetCurrentViewport(a);
  logfc(" -> return %d\n", x);
  pushtab();
  myIDirect3DViewport3 * n = (myIDirect3DViewport3 *)wrapfetch(*a);
  if (n == NULL && *a != NULL)
  {
    n = (myIDirect3DViewport3 *)new myIDirect3DViewport3(*a);
    wrapstore(n, *a);
    logf("Wrapped.\n");
  }
  *a = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::SetRenderTarget(LPDIRECTDRAWSURFACE4 a, DWORD b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::SetRenderTarget(LPDIRECTDRAWSURFACE4 0x%x, DWORD %d);", a, b);
  HRESULT x = mOriginal->SetRenderTarget((a)?((myIDirectDrawSurface4 *)a)->mOriginal:0, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::GetRenderTarget(LPDIRECTDRAWSURFACE4 * a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::GetRenderTarget(LPDIRECTDRAWSURFACE4 * 0x%x);", a);
  HRESULT x = mOriginal->GetRenderTarget(a);
  logfc(" -> return %d\n", x);
  pushtab();
  LPDIRECTDRAWSURFACE4 n = (LPDIRECTDRAWSURFACE4)wrapfetch(*a);
  if (n == NULL && *a != NULL)
  {
    n = (LPDIRECTDRAWSURFACE4)new myIDirectDrawSurface4(*a);
    wrapstore(n, *a);
    logf("Wrapped.\n");
  }
  *a = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::Begin(D3DPRIMITIVETYPE a, DWORD b, DWORD c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::Begin(D3DPRIMITIVETYPE, DWORD %d, DWORD %d);", b, c);
  HRESULT x = mOriginal->Begin(a, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::BeginIndexed(D3DPRIMITIVETYPE a, DWORD b, LPVOID c, DWORD d, DWORD e)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::BeginIndexed(D3DPRIMITIVETYPE, DWORD %d, LPVOID 0x%x, DWORD %d, DWORD %d);", b, c, d, e);
  HRESULT x = mOriginal->BeginIndexed(a, b, c, d, e);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::Vertex(LPVOID a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::Vertex(LPVOID 0x%x);", a);
  HRESULT x = mOriginal->Vertex(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::Index(WORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::Index(WORD);");
  HRESULT x = mOriginal->Index(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::End(DWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::End(DWORD %d);", a);
  HRESULT x = mOriginal->End(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::GetRenderState(D3DRENDERSTATETYPE a, LPDWORD b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::GetRenderState(D3DRENDERSTATETYPE, LPDWORD 0x%x);", b);
  HRESULT x = mOriginal->GetRenderState(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::SetRenderState(D3DRENDERSTATETYPE a, DWORD b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::SetRenderState(D3DRENDERSTATETYPE, DWORD %d);", b);
  HRESULT x = mOriginal->SetRenderState(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::GetLightState(D3DLIGHTSTATETYPE a, LPDWORD b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::GetLightState(D3DLIGHTSTATETYPE, LPDWORD 0x%x);", b);
  HRESULT x = mOriginal->GetLightState(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::SetLightState(D3DLIGHTSTATETYPE a, DWORD b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::SetLightState(D3DLIGHTSTATETYPE, DWORD %d);", b);
  HRESULT x = mOriginal->SetLightState(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::SetTransform(D3DTRANSFORMSTATETYPE a, LPD3DMATRIX b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::SetTransform(D3DTRANSFORMSTATETYPE, LPD3DMATRIX 0x%x);", b);
  HRESULT x = mOriginal->SetTransform(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::GetTransform(D3DTRANSFORMSTATETYPE a, LPD3DMATRIX b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::GetTransform(D3DTRANSFORMSTATETYPE, LPD3DMATRIX 0x%x);", b);
  HRESULT x = mOriginal->GetTransform(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::MultiplyTransform(D3DTRANSFORMSTATETYPE a, LPD3DMATRIX b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::MultiplyTransform(D3DTRANSFORMSTATETYPE, LPD3DMATRIX 0x%x);", b);
  HRESULT x = mOriginal->MultiplyTransform(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::DrawPrimitive(D3DPRIMITIVETYPE a, DWORD b, LPVOID c, DWORD d, DWORD e)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::DrawPrimitive(D3DPRIMITIVETYPE, DWORD %d, LPVOID 0x%x, DWORD %d, DWORD %d);", b, c, d, e);
  HRESULT x = mOriginal->DrawPrimitive(a, b, c, d, e);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::DrawIndexedPrimitive(D3DPRIMITIVETYPE a, DWORD b, LPVOID c, DWORD d, LPWORD e, DWORD f, DWORD g)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::DrawIndexedPrimitive(D3DPRIMITIVETYPE, DWORD %d, LPVOID 0x%x, DWORD %d, LPWORD 0x%x, DWORD %d, DWORD %d);", b, c, d, e, f, g);
  HRESULT x = mOriginal->DrawIndexedPrimitive(a, b, c, d, e, f, g);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::SetClipStatus(LPD3DCLIPSTATUS a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::SetClipStatus(LPD3DCLIPSTATUS 0x%x);", a);
  HRESULT x = mOriginal->SetClipStatus(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::GetClipStatus(LPD3DCLIPSTATUS a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::GetClipStatus(LPD3DCLIPSTATUS 0x%x);", a);
  HRESULT x = mOriginal->GetClipStatus(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::DrawPrimitiveStrided(D3DPRIMITIVETYPE a, DWORD b, LPD3DDRAWPRIMITIVESTRIDEDDATA c, DWORD d, DWORD e)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::DrawPrimitiveStrided(D3DPRIMITIVETYPE, DWORD %d, LPD3DDRAWPRIMITIVESTRIDEDDATA 0x%x, DWORD %d, DWORD %d);", b, c, d, e);
  HRESULT x = mOriginal->DrawPrimitiveStrided(a, b, c, d, e);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::DrawIndexedPrimitiveStrided(D3DPRIMITIVETYPE a, DWORD b, LPD3DDRAWPRIMITIVESTRIDEDDATA c, DWORD d, LPWORD e, DWORD f, DWORD g)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::DrawIndexedPrimitiveStrided(D3DPRIMITIVETYPE, DWORD %d, LPD3DDRAWPRIMITIVESTRIDEDDATA 0x%x, DWORD %d, LPWORD 0x%x, DWORD %d, DWORD %d);", b, c, d, e, f, g);
  HRESULT x = mOriginal->DrawIndexedPrimitiveStrided(a, b, c, d, e, f, g);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::DrawPrimitiveVB(D3DPRIMITIVETYPE a, LPDIRECT3DVERTEXBUFFER b, DWORD c, DWORD d, DWORD e)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::DrawPrimitiveVB(D3DPRIMITIVETYPE, LPDIRECT3DVERTEXBUFFER 0x%x, DWORD %d, DWORD %d, DWORD %d);", b, c, d, e);
  HRESULT x = mOriginal->DrawPrimitiveVB(a, (b)?((myIDirect3DVertexBuffer *)b)->mOriginal:0, c, d, e);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::DrawIndexedPrimitiveVB(D3DPRIMITIVETYPE a, LPDIRECT3DVERTEXBUFFER b, LPWORD c, DWORD d, DWORD e)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::DrawIndexedPrimitiveVB(D3DPRIMITIVETYPE, LPDIRECT3DVERTEXBUFFER 0x%x, LPWORD 0x%x, DWORD %d, DWORD %d);", b, c, d, e);
  HRESULT x = mOriginal->DrawIndexedPrimitiveVB(a, (b)?((myIDirect3DVertexBuffer *)b)->mOriginal:0, c, d, e);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::ComputeSphereVisibility(LPD3DVECTOR a, LPD3DVALUE b, DWORD c, DWORD d, LPDWORD e)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::ComputeSphereVisibility(LPD3DVECTOR 0x%x, LPD3DVALUE 0x%x, DWORD %d, DWORD %d, LPDWORD 0x%x);", a, b, c, d, e);
  HRESULT x = mOriginal->ComputeSphereVisibility(a, b, c, d, e);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::GetTexture(DWORD a, LPDIRECT3DTEXTURE2 * b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::GetTexture(DWORD %d, LPDIRECT3DTEXTURE2 * 0x%x);", a, b);
  HRESULT x = mOriginal->GetTexture(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  LPDIRECT3DTEXTURE2 n = (LPDIRECT3DTEXTURE2)wrapfetch(*b);
  if (n == NULL && *b != NULL)
  {
    n = (LPDIRECT3DTEXTURE2)new myIDirect3DTexture2(*b);
    wrapstore(n, *b);
    logf("Wrapped.\n");
  }
  *b = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::SetTexture(DWORD a, LPDIRECT3DTEXTURE2 b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::SetTexture(DWORD %d, LPDIRECT3DTEXTURE2 0x%x);", a, b);
  HRESULT x = mOriginal->SetTexture(a, (b)?((myIDirect3DTexture2 *)b)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::GetTextureStageState(DWORD a, D3DTEXTURESTAGESTATETYPE b, LPDWORD c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::GetTextureStageState(DWORD %d, D3DTEXTURESTAGESTATETYPE, LPDWORD 0x%x);", a, c);
  HRESULT x = mOriginal->GetTextureStageState(a, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::SetTextureStageState(DWORD a, D3DTEXTURESTAGESTATETYPE b, DWORD c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::SetTextureStageState(DWORD %d, D3DTEXTURESTAGESTATETYPE, DWORD %d);", a, c);
  HRESULT x = mOriginal->SetTextureStageState(a, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirect3DDevice3::ValidateDevice(LPDWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirect3DDevice3::ValidateDevice(LPDWORD 0x%x);", a);
  HRESULT x = mOriginal->ValidateDevice(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

