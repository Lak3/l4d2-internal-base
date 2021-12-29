#pragma once

#include "VGuiSurface.h"

typedef void (*GetMouseCallback_t)(int&, int&);
typedef void (*SetMouseCallback_t)(int, int);
typedef void (*PlaySoundFunc_t)(const char*);

class IMatSystemSurface : public IVGuiSurface
{
public:
public:
	virtual void			AttachToWindow(void* hwnd, bool bLetAppDriveInput = false) = 0;
	virtual void			EnableWindowsMessages(bool bEnable) = 0;
	virtual void			Begin3DPaint(int iLeft, int iTop, int iRight, int iBottom) = 0;
	virtual void			End3DPaint() = 0;
	virtual void			DisableClipping(bool bDisable) = 0;
	virtual void			SetMouseCallbacks(GetMouseCallback_t getFunc, SetMouseCallback_t setFunc) = 0;
	virtual void			InstallPlaySoundFunc(PlaySoundFunc_t soundFunc) = 0;
	virtual void			DrawColoredCircle(int centerx, int centery, float radius, int r, int g, int b, int a) = 0;
	virtual int				DrawColoredText(HFont font, int x, int y, int r, int g, int b, int a, char* fmt, ...) = 0;
	virtual void			DrawColoredTextRect(HFont font, int x, int y, int w, int h, int r, int g, int b, int a, char* fmt, ...) = 0;
	virtual void			DrawTextHeight(HFont font, int w, int& h, char* fmt, ...) = 0;
	virtual int				DrawTextLen(HFont font, char* fmt, ...) = 0;
	virtual void			DrawPanelIn3DSpace(VPANEL pRootPanel, const VMatrix& panelCenterToWorld, int nPixelWidth, int nPixelHeight, float flWorldWidth, float flWorldHeight) = 0;
	virtual void			DrawSetTextureMaterial(int id, IMaterial* pMaterial) = 0;

private:
	virtual bool			HandleInputEvent(const void* event) = 0; //InputEvent_t&

public:
	virtual void			Set3DPaintTempRenderTarget(const char* unk1) = 0;
	virtual void			Reset3DPaintTempRenderTarget(void) = 0;
	virtual IMaterial*		DrawGetTextureMaterial(int id) = 0;
	virtual void			DrawColoredTextMultiLine(unsigned long unk1, int unk2, int unk3, int unk4, int unk5, int unk6, int unk7, int unk8, char* unk9, ...) = 0;

public:
	inline void StartDrawing() {
		reinterpret_cast<void(__thiscall*)(void*)>(U::Offsets.m_dwStartDrawing)(this);
	}

	inline void FinishDrawing() {
		reinterpret_cast<void(__thiscall*)(void*)>(U::Offsets.m_dwFinishDrawing)(this);
	}
};

namespace I { inline IMatSystemSurface* MatSystemSurface = nullptr; }