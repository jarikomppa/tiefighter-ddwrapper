#define _CRT_SECURE_NO_WARNINGS
#define STRICT
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <shlobj.h>
#include <stdio.h>
#include <stdlib.h>
#include <varargs.h>
#include "gloutput.h"

CRITICAL_SECTION gCS;

bool _stdcall SetWindowPosHook(HWND, HWND, int, int, int, int, int) { return true; }
bool _stdcall SetWindowLongHook(HWND, int, int) { return true; }
bool _stdcall ShowWindowHook(HWND, int) { return true; }

bool _stdcall DllMain(HANDLE, DWORD dwReason, LPVOID) 
{
	if(dwReason==DLL_PROCESS_ATTACH) 
	{
		InitializeCriticalSection(&gCS);		
	} 
	else 
    if(dwReason==DLL_PROCESS_DETACH) 
	{
		gl_exit();
		DeleteCriticalSection(&gCS);
	}
	return true;
}

#define DISABLE_LOGGING
#define MAX_TABDEPTH 100

int gLoglines = 0;
int gTabStops = 0;
int gLastTick = 0;

void pushtab()
{
	gTabStops++;
}

void poptab()
{
	gTabStops--;
	if (gTabStops < 0)
		gTabStops = 0;
}

long long milliseconds_now() {
    static LARGE_INTEGER s_frequency;
    static BOOL s_use_qpc = QueryPerformanceFrequency(&s_frequency);
    if (s_use_qpc) {
        LARGE_INTEGER now;
        QueryPerformanceCounter(&now);
        return (1000LL * now.QuadPart) / s_frequency.QuadPart;
    } else {
        return GetTickCount();
    }
}

static FILE * gBigLog = NULL;

FILE * doopenlog()
{
	char fname[]="wrapper0.log";
	fname[7] = '0' + (gLoglines >> 20); // new file every ~1024k lines

	return fopen(fname, "a");
}

FILE * openlog()
{
	if (gBigLog)
		return gBigLog;
	return doopenlog();
}

void closelog(FILE * f)
{
	if (gBigLog)
		return;
	fclose(f);
}


void startbiglog()
{
#ifndef DISABLE_LOGGING
	gBigLog = doopenlog();
#endif
}

void endbiglog()
{
#ifndef DISABLE_LOGGING
	fclose(gBigLog);
	gBigLog = NULL;
#endif
}

void logfc(char * fmt, ...)
{
#ifndef DISABLE_LOGGING
	if (gTabStops > MAX_TABDEPTH)
		return;
	
	va_list ap;
	va_start(ap, fmt);
	FILE *f = openlog();
	if (f)
	{
		vfprintf(f, fmt, ap);
		closelog(f);
	}
	va_end(ap);
#endif
}

void logf(char * fmt, ...)
{
#ifndef DISABLE_LOGGING
	if (gTabStops > MAX_TABDEPTH)
		return;

	gLoglines++;
	int tick = (int)milliseconds_now();
	logfc("[%+8dms] ", tick - gLastTick);
	gLastTick = tick;
	va_list ap;
	va_start(ap, fmt);
	FILE *f = openlog();
	if (f)
	{
		int i;
		for (i = 0; i < gTabStops; i++) fputc('\t', f);
		vfprintf(f, fmt, ap);
		closelog(f);
	}
	va_end(ap);
#endif
}

void loghexdump(int size, void * aData)
{
#ifndef DISABLE_LOGGING
	int bl = 0;
	if (gBigLog == NULL)
	{
		bl = 1;
		startbiglog();
	}
	char temp[256];
	char *p = &temp[0];
	int i;
	unsigned char *data = (unsigned char*)aData;
	for (i = 0; i < size; i++)
	{
		p += sprintf(p, "%02X ", data[i]);
		if (i % 32 == 15)
			p += sprintf(p, "  ");
		if (i % 32 == 31)
		{
			logf("%s\n", temp);
			p = &temp[0];
		}
	}
	if (size % 32 != 31)
		logf("%s\n",temp);
	if (bl)
		endbiglog();
#endif
}

struct WrapPair
{
	void * mOriginal;
	void * mWrapper;
};

#define MAX_PAIRS 65536
WrapPair gWrapPair[MAX_PAIRS];
int gWrapPairs = 0;

void * do_wrapfetch(void * aOriginal)
{
#ifdef PASSTHROUGH_WRAPPER
	int i;
	for (i = 0; i < gWrapPairs; i++)
	{
		if (gWrapPair[i].mOriginal == aOriginal)
		{
			return gWrapPair[i].mWrapper;
		}
	}
#endif
	return NULL;
}

void wrapstore(void * aOriginal, void * aWrapper)
{
#ifdef PASSTHROUGH_WRAPPER
	if (do_wrapfetch(aOriginal) == NULL)
	{
		gWrapPair[gWrapPairs].mOriginal = aOriginal;
		gWrapPair[gWrapPairs].mWrapper = aWrapper;
		gWrapPairs++;
	}
	else
	{
		int i;
		for (i = 0; i < gWrapPairs; i++)
		{
			if (gWrapPair[i].mOriginal == aOriginal)
			{
				gWrapPair[i].mWrapper = aWrapper;
				return;
			}
		}
	}

	if (gWrapPairs >= MAX_PAIRS)
	{
		logf("**** Max number of wrappers exceeded - adjust and recompile\n");
	}
#endif
}


void * wrapfetch(void * aOriginal)
{
	void * ret = do_wrapfetch(aOriginal);

/*	if (ret == NULL)
	{
		logf("Pre-wrapped object not found - returning null\n");
	}
*/
	return ret;
}