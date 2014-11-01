#ifndef GLOUTPUT_H
#define GLOUTPUT_H

void gl_init(HWND aHwnd);
void gl_exit();
void gl_setvideomode(int w, int h, int bits);
void gl_updatescreen();

extern int gScreenWidth;
extern int gScreenHeight;
extern int gScreenBits;
extern int gRealScreenWidth;
extern int gRealScreenHeight;

extern int gTexData[2048*1024];
extern int gTemp[640*480];

class myIDirectDrawSurface;
extern myIDirectDrawSurface *gPrimarySurface, *gBackBuffer;

#endif