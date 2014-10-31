#pragma once

extern int gWidth;
extern int gHeight;

enum TextureFormat {
	tfX1R5G5B5=24,
	tfA1R5G5B5=25,
	tfA4R4G4B4=26,
	tfR5G6B5=23,
	tfX8R8G8B8=22,
	tfA8R8G8B8=21,
};

int d3d9GetUsedMem();
void d3d9Init(HWND);
void d3d9BeginScene();
void* d3d9CreateTexture(int width, int height, DWORD format, DWORD type);
void d3d9ReleaseTexture(void* tex);
void* d3d9Lock(void* tex, bool surf);
void d3d9Unlock(void* tex, bool surf);
void d3d9SetGamma(const void* pRamp);
void d3d9Exit();
void SetMaterial(float* data);
void d3d9SetTex(int stage, void* tex);
void d3d9DrawPrim(DWORD,DWORD,void*,DWORD);
void d3d9DrawIPrim(DWORD,DWORD,void*,void*,DWORD,DWORD);
void d3d9Present();
void d3d9SetRenderState(DWORD a, DWORD b);
void d3d9SetTextureStageState(DWORD a, DWORD b, DWORD c);
int d3d9GetTexPitch(void* tex);
void d3d9CopyTex(void* from, void* to);
void d3d9ResetWindow();