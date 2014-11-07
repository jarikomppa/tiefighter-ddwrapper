#define STRICT
#define WIN32_LEAN_AND_MEAN
#define INITGUID
#define DIRECTDRAW_VERSION 0x0700
#define DIRECT3D_VERSION   0x0700

#include <windows.h>
#include <ddraw.h>
#include "d3d.h"
#include "wrapper.h"

#ifdef _DEBUG
#define DEBUGMESS(a) OutputDebugStringA(a)
#else
#define DEBUGMESS(a)
#endif


typedef HRESULT (_stdcall *DDrawCreateProc)(void* a, void* b, void* c);
typedef HRESULT (_stdcall *DDrawEnumerateProc)(void* callback, void* context);
typedef void (_stdcall *DDrawMiscProc)();
typedef HRESULT (_stdcall *DDrawCreateExProc)(GUID FAR *lpGUID, LPVOID *lplpDD, REFIID iid, IUnknown FAR *pUnkOuter);

static DDrawCreateProc DDrawCreate=0;
static DDrawEnumerateProc DDrawEnumerate=0;
static DDrawMiscProc AcquireLock;
static DDrawMiscProc ParseUnknown;
static DDrawMiscProc InternalLock;
static DDrawMiscProc InternalUnlock;
static DDrawMiscProc ReleaseLock;
static DDrawCreateExProc DDrawCreateEx;

static void LoadDLL() {
#ifdef PASSTHROUGH_WRAPPER
	char path[MAX_PATH];
	GetSystemDirectoryA(path,MAX_PATH);
	strcat_s(path, "\\ddraw.dll");	
	HMODULE ddrawdll=LoadLibraryA(path);
	DDrawCreate=(DDrawCreateProc)GetProcAddress(ddrawdll, "DirectDrawCreate");
	DDrawEnumerate=(DDrawEnumerateProc)GetProcAddress(ddrawdll, "DirectDrawEnumerateA");
	DDrawCreateEx=(DDrawCreateExProc)GetProcAddress(ddrawdll, "DirectDrawCreateEx");

	AcquireLock=(DDrawMiscProc)GetProcAddress(ddrawdll, "AcquireDDThreadLock");
	ParseUnknown=(DDrawMiscProc)GetProcAddress(ddrawdll, "D3DParseUnknownCommand");
	InternalLock=(DDrawMiscProc)GetProcAddress(ddrawdll, "DDInternalLock");
	InternalUnlock=(DDrawMiscProc)GetProcAddress(ddrawdll, "DDInternalUnlock");
	ReleaseLock=(DDrawMiscProc)GetProcAddress(ddrawdll, "ReleaseDDThreadLock");
#endif
}

extern "C" void __declspec(naked) AcquireDDThreadLock() { 
	logf(__FUNCTION__ "\n");
	_asm jmp AcquireLock;
}
extern "C" void __declspec(naked) D3DParseUnknownCommand() { 
	logf(__FUNCTION__ "\n");
	_asm jmp ParseUnknown;
}
extern "C" void __declspec(naked) DDInternalLock() {
	logf(__FUNCTION__ "\n");
	_asm jmp InternalLock;
}
extern "C" void __declspec(naked) DDInternalUnlock() {
	logf(__FUNCTION__ "\n");
	_asm jmp InternalUnlock;
}
extern "C" void __declspec(naked) ReleaseDDThreadLock() {
	logf(__FUNCTION__ "\n");
	_asm jmp ReleaseLock;
}

extern "C" HRESULT _stdcall DirectDrawCreate(GUID* a, IDirectDraw** b, IUnknown* c) {
	logf(__FUNCTION__ "\n");
#ifdef PASSTHROUGH_WRAPPER
	if(!DDrawCreate) LoadDLL();
	HRESULT hr=DDrawCreate(a,b,c);
	if(FAILED(hr)) return hr;
#endif
	pushtab();
	*b=(IDirectDraw*)new myIDirectDraw(*b);
	poptab();
	return 0;
}

extern "C" HRESULT _stdcall DirectDrawCreateEx(
  GUID FAR *lpGUID,
  LPVOID *lplpDD,
  REFIID iid,
  IUnknown FAR *pUnkOuter
)
{
	logf(__FUNCTION__ "\n");
#ifdef PASSTHROUGH_WRAPPER
	if(!DDrawCreate) LoadDLL();
	HRESULT hr = DDrawCreateEx(lpGUID, lplpDD, iid, pUnkOuter);
	pushtab();
	genericQueryInterface(iid, lplpDD);
	poptab();
	return hr;
#else
	return E_FAIL;
#endif
}

extern "C" HRESULT WINAPI DirectDrawEnumerateA(
	_In_ LPDDENUMCALLBACKA lpCallback,
	_In_ LPVOID lpContext
	)
{
	logf(__FUNCTION__ "\n");
#ifdef PASSTHROUGH_WRAPPER
	if(!DDrawEnumerate) LoadDLL();
	return DDrawEnumerate(lpCallback, lpContext);
#else
	return E_FAIL;
#endif
}




extern "C" __declspec(naked) void CompleteCreateSysmemSurface()
{
	logf(__FUNCTION__ "\n");
}
extern "C" __declspec(naked) void DDGetAttachedSurfaceLcl()
{
	logf(__FUNCTION__ "\n");
}
extern "C" __declspec(naked) void DSoundHelp()
{
	logf(__FUNCTION__ "\n");
}
extern "C" HRESULT WINAPI DirectDrawCreateClipper(
	_In_ DWORD dwFlags,
	_Out_ LPDIRECTDRAWCLIPPER FAR *lplpDDClipper,
	_In_ IUnknown FAR *pUnkOuter
	)
{
	logf(__FUNCTION__ "\n");
	return E_FAIL;
}

extern "C" HRESULT WINAPI DirectDrawEnumerateExA(
	_In_ LPDDENUMCALLBACKEXA lpCallback,
	_In_ LPVOID lpContext,
	_In_ DWORD dwFlags
	)
{
	logf(__FUNCTION__ "\n");
	return E_FAIL;
}

extern "C" HRESULT WINAPI DirectDrawEnumerateExW(
	_In_ LPDDENUMCALLBACKEXW lpCallback,
	_In_ LPVOID lpContext,
	_In_ DWORD dwFlags
	)
{
	logf(__FUNCTION__ "\n");
	return E_FAIL;
}

extern "C" HRESULT WINAPI DirectDrawEnumerateW(
	_In_ LPDDENUMCALLBACKW lpCallback,
	_In_ LPVOID lpContext
	)
{
	logf(__FUNCTION__ "\n");
	return E_FAIL;
}

extern "C" __declspec(naked) void GetDDSurfaceLocal()
{
	logf(__FUNCTION__ "\n");
}

extern "C" __declspec(naked) void GetOLEThunkData()
{
	logf(__FUNCTION__ "\n");
}

extern "C" __declspec(naked) void GetSurfaceFromDC()
{
	logf(__FUNCTION__ "\n");
}

extern "C" __declspec(naked) void RegisterSpecialCase()
{
	logf(__FUNCTION__ "\n");
}

extern "C" __declspec(naked) void SetAppCompatData()
{
	logf(__FUNCTION__ "\n");
}
