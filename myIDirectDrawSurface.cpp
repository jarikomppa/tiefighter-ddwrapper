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
#include "myIDirectDrawSurface.h"

myIDirectDrawSurface::myIDirectDrawSurface(IDirectDrawSurface * aOriginal, LPDDSURFACEDESC aSurfacedesc)
{
  logf("myIDirectDrawSurface ctor\n");

  mOriginal = aOriginal;

  mSurfaceData = NULL;
  mRealSurfaceData = NULL;
  mCurrentPalette = NULL;
  mWidth = 0;
  mHeight = 0;
  mPitch = 0;

  if (aSurfacedesc == NULL)
  {
	  //UNDEFINED_void  
	  return;
  }


	mWidth = gScreenWidth;
	mHeight = gScreenHeight;
	mSurfaceDesc = *aSurfacedesc;

	if (aSurfacedesc->dwFlags & DDSD_WIDTH) mWidth = aSurfacedesc->dwWidth;
	if (aSurfacedesc->dwFlags & DDSD_HEIGHT) mHeight = aSurfacedesc->dwHeight;
	// we don't need no stinking extra pitch bytes..
	mPitch = mWidth * gScreenBits / 8;
	
	// ..unless you insist
	if (aSurfacedesc->dwFlags & DDSD_PITCH) mPitch = aSurfacedesc->lPitch; 

	if (aSurfacedesc->dwFlags & DDSD_CAPS)
	{
		if (aSurfacedesc->ddsCaps.dwCaps & DDSCAPS_PRIMARYSURFACE)
		{
			gPrimarySurface = this;			
		}
	}

	mSurfaceDesc.dwWidth = mWidth;
	mSurfaceDesc.dwHeight = mHeight;
	mSurfaceDesc.lPitch = mPitch;
	mSurfaceDesc.dwFlags |= DDSD_WIDTH | DDSD_HEIGHT | DDSD_PITCH;

	// Let's pad the framebuffer by a couple of megs, in case
	// the app writes outside bounds..
	// (we have enough trouble being stable as it is)
	mRealSurfaceData = new unsigned char[mHeight * mPitch + 2 * 1024 * 1024];
	mSurfaceData = mRealSurfaceData + 1024 * 1024 * 1;
	memset(mSurfaceData, 0, mHeight * mPitch);
}

myIDirectDrawSurface::~myIDirectDrawSurface()
{
	char * extrabit = "";
	if (this == gBackBuffer) extrabit = " (backbuffer)";
	if (this == gPrimarySurface) extrabit = " (primary)";

  logf("myIDirectDrawSurface dtor%s\n", extrabit);

  if (this == gBackBuffer)
  {
	  gBackBuffer = NULL;
  }

  if (this == gPrimarySurface)
	{
		gPrimarySurface = NULL;
		delete gBackBuffer;
		gBackBuffer = NULL;
	}
	delete[] mRealSurfaceData;

}

HRESULT __stdcall myIDirectDrawSurface::QueryInterface(REFIID riid, LPVOID FAR * ppvObj)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::QueryInterface(REFIID, LPVOID FAR * 0x%x);", ppvObj);
  HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
  logfc(" -> return %d\n", x);
  pushtab();
  if (x == 0) genericQueryInterface(riid, ppvObj);
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirectDrawSurface::AddRef()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::AddRef();");
  ULONG x = mOriginal->AddRef();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

ULONG __stdcall myIDirectDrawSurface::Release()
{
  EnterCriticalSection(&gCS);
  char *extrabit = "";
  if (this == gPrimarySurface) extrabit = " (Primary)";
  if (this == gBackBuffer) extrabit = " (Backbuffer)";
  logf("myIDirectDrawSurface::Release(); %s", extrabit);
#ifdef PASSTHROUGH_WRAPPER
  ULONG x = mOriginal->Release();
#else
  ULONG x = 0;
#endif
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

HRESULT __stdcall myIDirectDrawSurface::AddAttachedSurface(LPDIRECTDRAWSURFACE a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::AddAttachedSurface(LPDIRECTDRAWSURFACE 0x%x);", a);
  HRESULT x = mOriginal->AddAttachedSurface((a)?((myIDirectDrawSurface *)a)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::AddOverlayDirtyRect(LPRECT a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::AddOverlayDirtyRect(LPRECT 0x%x);", a);
  HRESULT x = mOriginal->AddOverlayDirtyRect(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::Blt(LPRECT a, LPDIRECTDRAWSURFACE b, LPRECT c, DWORD d, LPDDBLTFX e)
{
  EnterCriticalSection(&gCS);
  startbiglog();
  char *extrabit = "";
  if (this == gPrimarySurface) extrabit = " (Primary)";
  if (this == gBackBuffer) extrabit = " (Backbuffer)";
  char *bbit = "";
  if (b == gPrimarySurface) extrabit = " (Primary)";
  if (b == gBackBuffer) extrabit = " (Backbuffer)";
  logf("myIDirectDrawSurface::Blt(LPRECT 0x%x, LPDIRECTDRAWSURFACE 0x%x%s, LPRECT 0x%x, DWORD %d, LPDDBLTFX 0x%x); %s\n", a, b, bbit, c, d, e, extrabit);
  pushtab();
	if (a && c)
		logf("myIDDrawSurface1::Blt([%d,%d,%d,%d],%08x,[%d,%d,%d,%d],%d,%08x)",
			a->top,a->left,a->bottom,a->right,
			b,
			c->top,c->left,c->bottom,c->right,
			d,
			e);
	else
	if (a)
		logf("myIDDrawSurface1::Blt([%d,%d,%d,%d],%08x,[null],%d,%08x)",
			a->top,a->left,a->bottom,a->right,
			b,
			d,
			e);
	else
	if (c)
		logf("myIDDrawSurface1::Blt([null],%08x,[%d,%d,%d,%d],%d,%08x)",
			b,
			c->top,c->left,c->bottom,c->right,
			d,
			e);
	else
		logf("myIDDrawSurface1::Blt([null],%08x,[null],%d,%08x)",
			b,
			d,
			e);

	logfc("\n");
	logf("Flags: ");
	if (d & DDBLT_COLORFILL) logfc("DDBLT_COLORFILL ");
	if (d & DDBLT_DDFX) logfc("DDBLT_DDFX ");
	if (d & DDBLT_DDROPS) logfc("DDBLT_DDROPS ");
	if (d & DDBLT_DEPTHFILL) logfc("DDBLT_DEPTHFILL ");
	if (d & DDBLT_KEYDESTOVERRIDE) logfc("DDBLT_KEYDESTOVERRIDE ");
	if (d & DDBLT_KEYSRCOVERRIDE) logfc("DDBLT_KEYSRCOVERRIDE ");
	if (d & DDBLT_ROP) logfc("DDBLT_ROP ");
	if (d & DDBLT_ROTATIONANGLE) logfc("DDBLT_ROTATIONANGLE ");
	if (d & DDBLT_KEYDEST) logfc("DDBLT_KEYDEST ");
	if (d & DDBLT_KEYSRC) logfc("DDBLT_KEYSRC ");
	if (d & DDBLT_ASYNC) logfc("DDBLT_ASYNC ");
	if (d & DDBLT_DONOTWAIT) logfc("DDBLT_DONOTWAIT ");
	if (d & DDBLT_WAIT) logfc("DDBLT_WAIT ");
	logfc("\n");
	if (e)
	{
		logf("dwSize = %x (%d)\n", e->dwSize, e->dwSize);
		logf("dwDDFX = %x (%d)\n", e->dwDDFX, e->dwDDFX);
		logf("dwROP = %x (%d)\n", e->dwROP, e->dwROP);
		logf("dwDDROP = %x (%d)\n", e->dwDDROP, e->dwDDROP);
		logf("dwRotationAngle = %x (%d)\n", e->dwRotationAngle, e->dwRotationAngle);
		logf("dwZBufferOpCode = %x (%d)\n", e->dwZBufferOpCode, e->dwZBufferOpCode);
		logf("dwZBufferLow = %x (%d)\n", e->dwZBufferLow, e->dwZBufferLow);
		logf("dwZBufferHigh = %x (%d)\n", e->dwZBufferHigh, e->dwZBufferHigh);
		logf("dwZBufferBaseDest = %x (%d)\n", e->dwZBufferBaseDest, e->dwZBufferBaseDest);
		logf("dwZDestConstBitDepth = %x (%d)\n", e->dwZDestConstBitDepth, e->dwZDestConstBitDepth);
		logf("lpDDSZBufferDest = %x (%d)\n", e->lpDDSZBufferDest, e->lpDDSZBufferDest);
		logf("dwZSrcConstBitDepth = %x (%d)\n", e->dwZSrcConstBitDepth, e->dwZSrcConstBitDepth);
		logf("lpDDSZBufferSrc = %x (%d)\n", e->lpDDSZBufferSrc, e->lpDDSZBufferSrc);
		logf("dwAlphaEdgeBlendBitDepth = %x (%d)\n", e->dwAlphaEdgeBlendBitDepth, e->dwAlphaEdgeBlendBitDepth);
		logf("dwAlphaEdgeBlend = %x (%d)\n", e->dwAlphaEdgeBlend, e->dwAlphaEdgeBlend);
		logf("dwReserved = %x (%d)\n", e->dwReserved, e->dwReserved);
		logf("dwAlphaDestConstBitDepth = %x (%d)\n", e->dwAlphaDestConstBitDepth, e->dwAlphaDestConstBitDepth);
		logf("lpDDSAlphaDest = %x (%d)\n", e->lpDDSAlphaDest, e->lpDDSAlphaDest);
		logf("dwAlphaSrcConstBitDepth = %x (%d)\n", e->dwAlphaSrcConstBitDepth, e->dwAlphaSrcConstBitDepth);
		logf("lpDDSAlphaSrc = %x (%d)\n", e->lpDDSAlphaSrc, e->lpDDSAlphaSrc);
		logf("dwFillColor = %x (%d)\n", e->dwFillColor, e->dwFillColor);
		logf("ddckDestColorkey = %x (%d)\n", e->ddckDestColorkey, e->ddckDestColorkey);
		logf("ddckSrcColorkey = %x (%d)\n", e->ddckSrcColorkey, e->ddckSrcColorkey);
	}
 poptab();
#ifdef PASSTHROUGH_WRAPPER
  HRESULT x = mOriginal->Blt(a, (b)?((myIDirectDrawSurface *)b)->mOriginal:0, c, d, e);
#else
  HRESULT x = 0;
  if (d == DDBLT_COLORFILL)
  {
	  if (this->mSurfaceDesc.ddpfPixelFormat.dwRGBBitCount == 8)
	  {
		  memset(mSurfaceData, e->dwFillColor, mWidth * mHeight);
	  }
	  if (this->mSurfaceDesc.ddpfPixelFormat.dwRGBBitCount == 16)
	  {
		  unsigned short * surf = (unsigned short*)mSurfaceData;
		  int i, j;
		  for (i = 0; i < mHeight; i++)
			  for (j = 0; j < mWidth; j++)
				  surf[i * mPitch/2 + j] = e->dwFillColor;
	  }
  }
  if (d == DDBLT_ROP)
  {
	  // assuming full copy and equal sized surfaces
	  if (b)
	  {
		  memcpy(mSurfaceData, ((myIDirectDrawSurface*)b)->mSurfaceData, mWidth * mHeight * 2);
	  }
  }
#endif
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  endbiglog();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::BltBatch(LPDDBLTBATCH a, DWORD b, DWORD c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::BltBatch(LPDDBLTBATCH 0x%x, DWORD %d, DWORD %d);", a, b, c);
  HRESULT x = mOriginal->BltBatch(a, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::BltFast(DWORD a, DWORD b, LPDIRECTDRAWSURFACE c, LPRECT d, DWORD e)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::BltFast(DWORD %d, DWORD %d, LPDIRECTDRAWSURFACE 0x%x, LPRECT 0x%x, DWORD %d);", a, b, c, d, e);
  HRESULT x = mOriginal->BltFast(a, b, (c)?((myIDirectDrawSurface *)c)->mOriginal:0, d, e);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::DeleteAttachedSurface(DWORD a, LPDIRECTDRAWSURFACE b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::DeleteAttachedSurface(DWORD %d, LPDIRECTDRAWSURFACE 0x%x);", a, b);
  HRESULT x = mOriginal->DeleteAttachedSurface(a, (b)?((myIDirectDrawSurface *)b)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::EnumAttachedSurfaces(LPVOID a, LPDDENUMSURFACESCALLBACK b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::EnumAttachedSurfaces(LPVOID 0x%x, LPDDENUMSURFACESCALLBACK 0x%x);", a, b);
  HRESULT x = mOriginal->EnumAttachedSurfaces(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::EnumOverlayZOrders(DWORD a, LPVOID b, LPDDENUMSURFACESCALLBACK c)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::EnumOverlayZOrders(DWORD %d, LPVOID 0x%x, LPDDENUMSURFACESCALLBACK 0x%x);", a, b, c);
  HRESULT x = mOriginal->EnumOverlayZOrders(a, b, c);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::Flip(LPDIRECTDRAWSURFACE a, DWORD b)
{
  EnterCriticalSection(&gCS);
  char *extrabit = "";
  if (this == gPrimarySurface) extrabit = " (Primary)";
  if (this == gBackBuffer) extrabit = " (Backbuffer)";
  char *abit = "";
  if (a == gPrimarySurface) extrabit = " (Primary)";
  if (a == gBackBuffer) extrabit = " (Backbuffer)";

  logf("myIDirectDrawSurface::Flip(LPDIRECTDRAWSURFACE 0x%x%s, DWORD %d); %s", a, abit, b, extrabit);
#ifdef PASSTHROUGH_WRAPPER
  HRESULT x = mOriginal->Flip((a)?((myIDirectDrawSurface *)a)->mOriginal:0, b);
#else
  HRESULT x = 0;
  gl_updatescreen();
#endif
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::GetAttachedSurface(LPDDSCAPS a, LPDIRECTDRAWSURFACE FAR * b)
{
  EnterCriticalSection(&gCS);
  char *extrabit = "";
  if (this == gPrimarySurface) extrabit = " (Primary)";
  if (this == gBackBuffer) extrabit = " (Backbuffer)";
  logf("myIDirectDrawSurface::GetAttachedSurface(LPDDSCAPS 0x%x, LPDIRECTDRAWSURFACE FAR * 0x%x);%s", a, b, extrabit);
#ifdef PASSTHROUGH_WRAPPER
  HRESULT x = mOriginal->GetAttachedSurface(a, b);
  pushtab();
  myIDirectDrawSurface * n = (myIDirectDrawSurface *)wrapfetch(*b);
  if (n == NULL && *b != NULL)
  {
    n = (myIDirectDrawSurface *)new myIDirectDrawSurface(*b, NULL);
    wrapstore(n, *b);
    logf("Wrapped.\n");
  }
  *b = n;
  poptab();
#else
  pushtab();
  logfc("\n");
  HRESULT x = 0;
  if (!gBackBuffer)
  {
	  DDSURFACEDESC bbdesc = mSurfaceDesc;
	  bbdesc.ddsCaps.dwCaps |= a->dwCaps;	
	  bbdesc.ddsCaps.dwCaps &= ~DDSCAPS_PRIMARYSURFACE;
	  gBackBuffer = new myIDirectDrawSurface(NULL, &bbdesc);
	  gBackBuffer->mSurfaceData = mSurfaceData;
  }
  *b = gBackBuffer;
  poptab();
#endif
  logfc(" -> return %d\n", x);
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::GetBltStatus(DWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::GetBltStatus(DWORD %d);", a);
  HRESULT x = mOriginal->GetBltStatus(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::GetCaps(LPDDSCAPS a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::GetCaps(LPDDSCAPS 0x%x);", a);
  HRESULT x = mOriginal->GetCaps(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::GetClipper(LPDIRECTDRAWCLIPPER FAR * a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::GetClipper(LPDIRECTDRAWCLIPPER FAR * 0x%x);", a);
  HRESULT x = mOriginal->GetClipper(a);
  logfc(" -> return %d\n", x);
  pushtab();
  myIDirectDrawClipper * n = (myIDirectDrawClipper *)wrapfetch(*a);
  if (n == NULL && *a != NULL)
  {
    n = (myIDirectDrawClipper *)new myIDirectDrawClipper(*a);
    wrapstore(n, *a);
    logf("Wrapped.\n");
  }
  *a = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::GetColorKey(DWORD a, LPDDCOLORKEY b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::GetColorKey(DWORD %d, LPDDCOLORKEY 0x%x);", a, b);
  HRESULT x = mOriginal->GetColorKey(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::GetDC(HDC FAR * a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::GetDC(HDC FAR *);");
  HRESULT x = mOriginal->GetDC(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::GetFlipStatus(DWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::GetFlipStatus(DWORD %d);", a);
  HRESULT x = mOriginal->GetFlipStatus(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::GetOverlayPosition(LPLONG a, LPLONG b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::GetOverlayPosition(LPLONG 0x%x, LPLONG 0x%x);", a, b);
  HRESULT x = mOriginal->GetOverlayPosition(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::GetPalette(LPDIRECTDRAWPALETTE FAR * a)
{
	/*
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::GetPalette(LPDIRECTDRAWPALETTE FAR * 0x%x);", a);
  HRESULT x = mOriginal->GetPalette(a);
  logfc(" -> return %d\n", x);
  pushtab();
  myIDirectDrawPalette * n = (myIDirectDrawPalette *)wrapfetch(*a);
  if (n == NULL && *a != NULL)
  {
    n = (myIDirectDrawPalette *)new myIDirectDrawPalette(*a);
    wrapstore(n, *a);
    logf("Wrapped.\n");
  }
  *a = n;
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
  */
	UNDEFINED_(E_FAIL);

}

HRESULT __stdcall myIDirectDrawSurface::GetPixelFormat(LPDDPIXELFORMAT a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::GetPixelFormat(LPDDPIXELFORMAT 0x%x);", a);
  HRESULT x = mOriginal->GetPixelFormat(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::GetSurfaceDesc(LPDDSURFACEDESC a)
{
  EnterCriticalSection(&gCS);
  startbiglog();
  char *extrabit = "";
  if (this == gPrimarySurface) extrabit = " (Primary)";
  if (this == gBackBuffer) extrabit = " (Backbuffer)";
  logf("myIDirectDrawSurface::GetSurfaceDesc(LPDDSURFACEDESC 0x%x);%s", a, extrabit);
#ifdef PASSTHROUGH_WRAPPER
  HRESULT x = mOriginal->GetSurfaceDesc(a);
  pushtab();
    logfc("\n");
    loghexdump(sizeof(DDSURFACEDESC), a);
	
	logf("dwSize = %x (%d)\n", a->dwSize, a->dwSize);
	logf("dwFlags = %x (%d)", a->dwFlags, a->dwFlags);
#define FLAGGY(x) if ((a->dwFlags & x) == x) logfc(#x " ");
	FLAGGY(DDSD_ALL)
	FLAGGY(DDSD_ALPHABITDEPTH) 
	FLAGGY(DDSD_BACKBUFFERCOUNT)
	FLAGGY(DDSD_CAPS)
	FLAGGY(DDSD_CKDESTBLT)
	FLAGGY(DDSD_CKDESTOVERLAY)
	FLAGGY(DDSD_CKSRCBLT)
	FLAGGY(DDSD_CKSRCOVERLAY)
	FLAGGY(DDSD_HEIGHT)
	FLAGGY(DDSD_LINEARSIZE)
	FLAGGY(DDSD_LPSURFACE)
	FLAGGY(DDSD_MIPMAPCOUNT)
	FLAGGY(DDSD_PITCH)
	FLAGGY(DDSD_PIXELFORMAT)
	FLAGGY(DDSD_REFRESHRATE)
	FLAGGY(DDSD_TEXTURESTAGE)
	FLAGGY(DDSD_WIDTH)
	FLAGGY(DDSD_ZBUFFERBITDEPTH)
#undef FLAGGY
	logfc("\n");
	logf("dwHeight = %x (%d)\n", a->dwHeight, a->dwHeight);
	logf("dwWidth = %x (%d)\n", a->dwWidth, a->dwWidth);
	logf("dwLinearSize = %x (%d)\n", a->dwLinearSize, a->dwLinearSize);
	logf("dwBackBufferCount = %x (%d)\n",a->dwBackBufferCount,a->dwBackBufferCount);
	logf("dwRefreshRate = %x (%d)\n", a->dwRefreshRate, a->dwRefreshRate);
	logf("dwAlphaBitDepth = %x (%d)\n", a->dwAlphaBitDepth, a->dwAlphaBitDepth);
	logf("dwReserved = %x (%d)\n", a->dwReserved, a->dwReserved);
	logf("lpSurface = %x (%d)\n", a->lpSurface, a->lpSurface);
	logf("ddsCaps.dwCaps = %x (%d)\n", a->ddsCaps.dwCaps, a->ddsCaps.dwCaps);
	logf("ddpfPixelFormat.dwSize = %x (%d)\n", a->ddpfPixelFormat.dwSize, a->ddpfPixelFormat.dwSize);
	logf("ddpfPixelFormat.dwFlags = %x (%d)\n", a->ddpfPixelFormat.dwFlags, a->ddpfPixelFormat.dwFlags);
	logf("ddpfPixelFormat.dwFourCC = %x (%d)\n", a->ddpfPixelFormat.dwFourCC, a->ddpfPixelFormat.dwFourCC);
	logf("ddpfPixelFormat.dwRGBBitCount = %x (%d)\n", a->ddpfPixelFormat.dwRGBBitCount, a->ddpfPixelFormat.dwRGBBitCount);
	logf("ddpfPixelFormat.dwRBitMask = %x (%d)\n", a->ddpfPixelFormat.dwRBitMask, a->ddpfPixelFormat.dwRBitMask);
	logf("ddpfPixelFormat.dwGBitMask = %x (%d)\n", a->ddpfPixelFormat.dwGBitMask, a->ddpfPixelFormat.dwGBitMask);
	logf("ddpfPixelFormat.dwBBitMask = %x (%d)\n", a->ddpfPixelFormat.dwBBitMask, a->ddpfPixelFormat.dwBBitMask);
	logf("ddpfPixelFormat.dwRGBAlphaBitMask = %x (%d)\n", a->ddpfPixelFormat.dwRGBAlphaBitMask, a->ddpfPixelFormat.dwRGBAlphaBitMask);
//	logf("ddpfPixelFormat = %d\n", ddpfPixelFormat);

  poptab();

#else
  HRESULT x = 0;
#endif
  logfc(" -> return %d\n", x);
  endbiglog();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::Initialize(LPDIRECTDRAW a, LPDDSURFACEDESC b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::Initialize(LPDIRECTDRAW 0x%x, LPDDSURFACEDESC 0x%x);", a, b);
  HRESULT x = mOriginal->Initialize((a)?((myIDirectDraw *)a)->mOriginal:0, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::IsLost()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::IsLost();");
  HRESULT x = mOriginal->IsLost();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::Lock(LPRECT a, LPDDSURFACEDESC b, DWORD c, HANDLE d)
{
  EnterCriticalSection(&gCS);
  startbiglog();
  char *extrabit = "";
  if (this == gPrimarySurface) extrabit = " (Primary)";
  if (this == gBackBuffer) extrabit = " (Backbuffer)";
  logf("myIDirectDrawSurface::Lock(LPRECT 0x%x, LPDDSURFACEDESC 0x%x, DWORD %d, HANDLE); %s\n", a, b, c, extrabit);
  pushtab();
  logf("surfacedesc flags: ");
#define FLAGGY(x) if ((b->dwFlags & x) == x) logfc(#x " ");
	FLAGGY(DDSD_ALL)
	FLAGGY(DDSD_ALPHABITDEPTH) 
	FLAGGY(DDSD_BACKBUFFERCOUNT)
	FLAGGY(DDSD_CAPS)
	FLAGGY(DDSD_CKDESTBLT)
	FLAGGY(DDSD_CKDESTOVERLAY)
	FLAGGY(DDSD_CKSRCBLT)
	FLAGGY(DDSD_CKSRCOVERLAY)
	FLAGGY(DDSD_HEIGHT)
	FLAGGY(DDSD_LINEARSIZE)
	FLAGGY(DDSD_LPSURFACE)
	FLAGGY(DDSD_MIPMAPCOUNT)
	FLAGGY(DDSD_PITCH)
	FLAGGY(DDSD_PIXELFORMAT)
	FLAGGY(DDSD_REFRESHRATE)
	FLAGGY(DDSD_TEXTURESTAGE)
	FLAGGY(DDSD_WIDTH)
	FLAGGY(DDSD_ZBUFFERBITDEPTH)
	logfc("\n");
	poptab();
#undef FLAGGY
#ifdef PASSTHROUGH_WRAPPER
  HRESULT x = mOriginal->Lock(a, b, c, d);
  pushtab();
    loghexdump(sizeof(DDSURFACEDESC), b);
  poptab();

#else
  HRESULT x = 0;
	*b = mSurfaceDesc;

	b->dwFlags |= DDSD_LPSURFACE | DDSD_WIDTH | DDSD_HEIGHT | DDSD_PITCH;
	b->lpSurface = mSurfaceData;

	b->dwWidth = mWidth;
	b->dwHeight = mHeight;
	b->lPitch = mPitch;

#endif
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  endbiglog();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::ReleaseDC(HDC a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::ReleaseDC(HDC);");
  HRESULT x = mOriginal->ReleaseDC(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::Restore()
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::Restore();");
  HRESULT x = mOriginal->Restore();
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::SetClipper(LPDIRECTDRAWCLIPPER a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::SetClipper(LPDIRECTDRAWCLIPPER 0x%x);", a);
  HRESULT x = mOriginal->SetClipper((a)?((myIDirectDrawClipper *)a)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::SetColorKey(DWORD a, LPDDCOLORKEY b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::SetColorKey(DWORD %d, LPDDCOLORKEY 0x%x);", a, b);
  HRESULT x = mOriginal->SetColorKey(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::SetOverlayPosition(LONG a, LONG b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::SetOverlayPosition(LONG, LONG);");
  HRESULT x = mOriginal->SetOverlayPosition(a, b);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::SetPalette(LPDIRECTDRAWPALETTE a)
{
  EnterCriticalSection(&gCS);
  char *extrabit = "";
  if (this == gPrimarySurface) extrabit = " (Primary)";
  if (this == gBackBuffer) extrabit = " (Backbuffer)";
  logf("myIDirectDrawSurface::SetPalette(LPDIRECTDRAWPALETTE 0x%x);%s", a, extrabit);
#ifdef PASSTHROUGH_WRAPPER
  HRESULT x = mOriginal->SetPalette((a)?((myIDirectDrawPalette *)a)->mOriginal:0);
#else
  HRESULT x = 0;
  mCurrentPalette = (myIDirectDrawPalette*)a;
#endif
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::Unlock(LPVOID a)
{
  EnterCriticalSection(&gCS);
  char *extrabit = "";
  if (this == gPrimarySurface) extrabit = " (Primary)";
  if (this == gBackBuffer) extrabit = " (Backbuffer)";
  logf("myIDirectDrawSurface::Unlock(LPVOID 0x%x);%s", a, extrabit);
#ifdef PASSTHROUGH_WRAPPER
  HRESULT x = mOriginal->Unlock(a);
#else
  HRESULT x = 0;
#endif
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::UpdateOverlay(LPRECT a, LPDIRECTDRAWSURFACE b, LPRECT c, DWORD d, LPDDOVERLAYFX e)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::UpdateOverlay(LPRECT 0x%x, LPDIRECTDRAWSURFACE 0x%x, LPRECT 0x%x, DWORD %d, LPDDOVERLAYFX 0x%x);", a, b, c, d, e);
  HRESULT x = mOriginal->UpdateOverlay(a, (b)?((myIDirectDrawSurface *)b)->mOriginal:0, c, d, e);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::UpdateOverlayDisplay(DWORD a)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::UpdateOverlayDisplay(DWORD %d);", a);
  HRESULT x = mOriginal->UpdateOverlayDisplay(a);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

HRESULT __stdcall myIDirectDrawSurface::UpdateOverlayZOrder(DWORD a, LPDIRECTDRAWSURFACE b)
{
  EnterCriticalSection(&gCS);
  logf("myIDirectDrawSurface::UpdateOverlayZOrder(DWORD %d, LPDIRECTDRAWSURFACE 0x%x);", a, b);
  HRESULT x = mOriginal->UpdateOverlayZOrder(a, (b)?((myIDirectDrawSurface *)b)->mOriginal:0);
  logfc(" -> return %d\n", x);
  pushtab();
  poptab();
  LeaveCriticalSection(&gCS);
  return x;
}

