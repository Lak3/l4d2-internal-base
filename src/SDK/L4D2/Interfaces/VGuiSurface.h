#pragma once

#include "VGuiPanel.h"

#ifdef CreateFont
#undef CreateFont
#endif

#ifdef PlaySound
#undef PlaySound
#endif

typedef unsigned long HCursor;
typedef unsigned long HFont;

enum FontDrawType_t {
	FONT_DRAW_DEFAULT = 0,
	FONT_DRAW_NONADDITIVE,
	FONT_DRAW_ADDITIVE,
	FONT_DRAW_TYPE_COUNT = 2
};

enum SurfaceFeature_e {
	ANTIALIASED_FONTS = 1,
	DROPSHADOW_FONTS = 2,
	ESCAPE_KEY = 3,
	OPENING_NEW_HTML_WINDOWS = 4,
	FRAME_MINIMIZE_MAXIMIZE = 5,
	OUTLINE_FONTS = 6,
	DIRECT_HWND_RENDER = 7
};

enum EFontFlags {
	FONTFLAG_NONE,
	FONTFLAG_ITALIC = 0x001,
	FONTFLAG_UNDERLINE = 0x002,
	FONTFLAG_STRIKEOUT = 0x004,
	FONTFLAG_SYMBOL = 0x008,
	FONTFLAG_ANTIALIAS = 0x010,
	FONTFLAG_GAUSSIANBLUR = 0x020,
	FONTFLAG_ROTARY = 0x040,
	FONTFLAG_DROPSHADOW = 0x080,
	FONTFLAG_ADDITIVE = 0x100,
	FONTFLAG_OUTLINE = 0x200,
	FONTFLAG_CUSTOM = 0x400,
	FONTFLAG_BITMAP = 0x800
};

struct CharRenderInfo {
	FontDrawType_t	drawType;
	wchar_t			ch;
	bool			valid;
	bool			shouldclip;
	int				x, y;
	Vertex_t		verts[2];
	int				textureId;
	int				abcA;
	int				abcB;
	int				abcC;
	int				fontTall;
	HFont			currentFont;
};

class IVGuiSurface : public IAppSystem
{
public:
	virtual void					RunFrame() = 0; //5
	virtual VPANEL					GetEmbeddedPanel() = 0;
	virtual void					SetEmbeddedPanel(VPANEL pPanel) = 0;
	virtual void					PushMakeCurrent(VPANEL panel, bool useInsets) = 0;
	virtual void					PopMakeCurrent(VPANEL panel) = 0;
	virtual void					DrawSetColor(int r, int g, int b, int a) = 0;
	virtual void					DrawSetColor(Color col) = 0;
	virtual void					DrawFilledRect(int x0, int y0, int x1, int y1) = 0;
	virtual void					DrawFilledRectArray(void* pRects, int numRects) = 0;
	virtual void					DrawOutlinedRect(int x0, int y0, int x1, int y1) = 0;
	virtual void					DrawLine(int x0, int y0, int x1, int y1) = 0;
	virtual void					DrawPolyLine(int* px, int* py, int numPoints) = 0;
	virtual void					DrawSetTextFont(HFont font) = 0;
	virtual void					DrawSetTextColor(int r, int g, int b, int a) = 0;
	virtual void					DrawSetTextColor(Color col) = 0;
	virtual void					DrawSetTextPos(int x, int y) = 0;
	virtual void					DrawGetTextPos(int& x, int& y) = 0;
	virtual void					DrawPrintText(const wchar_t* text, int textLen, FontDrawType_t drawType = FONT_DRAW_DEFAULT) = 0;
	virtual void					DrawUnicodeChar(wchar_t wch, FontDrawType_t drawType = FONT_DRAW_DEFAULT) = 0;
	virtual void					DrawFlushText() = 0;
	virtual int						DrawGetTextureId(char const* filename) = 0;
	virtual bool					DrawGetTextureFile(int id, char* filename, int maxlen) = 0;
	virtual void					DrawSetTextureFile(int id, const char* filename, int hardwareFilter, bool forceReload) = 0;
	virtual void					DrawSetTextureRGBA(int id, const unsigned char* rgba, int wide, int tall, int hardwareFilter, bool forceReload) = 0;
	virtual void					DrawSetTexture(int id) = 0;
	virtual void					DrawGetTextureSize(int id, int& wide, int& tall) = 0;
	virtual void					DrawTexturedRect(int x0, int y0, int x1, int y1) = 0;
	virtual bool					IsTextureIDValid(int id) = 0;
	virtual void					DeleteTextureByID(int id) = 0;
	virtual int						CreateNewTextureID(bool procedural = false) = 0;
	virtual void					GetScreenSize(int& wide, int& tall) = 0;
	virtual void					SetAsTopMost(VPANEL panel, bool state) = 0;
	virtual void					BringToFront(VPANEL panel) = 0;
	virtual void					SetForegroundWindow(VPANEL panel) = 0;
	virtual void					SetPanelVisible(VPANEL panel, bool state) = 0;
	virtual void					SetMinimized(VPANEL panel, bool state) = 0;
	virtual bool					IsMinimized(VPANEL panel) = 0;
	virtual void					FlashWindow(VPANEL panel, bool state) = 0;
	virtual void					SetTitle(VPANEL panel, const wchar_t* title) = 0;
	virtual void					SetAsToolBar(VPANEL panel, bool state) = 0;
	virtual void					CreatePopup(VPANEL panel, bool minimised, bool showTaskbarIcon = true, bool disabled = false, bool mouseInput = true, bool kbInput = true) = 0;
	virtual void					SwapBuffers(VPANEL panel) = 0;
	virtual void					Invalidate(VPANEL panel) = 0;
	virtual void					SetCursor(HCursor cursor) = 0;
	virtual void					SetCursorAlwaysVisible(bool state) = 0;
	virtual bool					IsCursorVisible() = 0;
	virtual void					ApplyChanges() = 0;
	virtual bool					IsWithin(int x, int y) = 0;
	virtual bool					HasFocus() = 0;
	virtual bool					SupportsFeature(SurfaceFeature_e feature) = 0;
	virtual void					RestrictPaintToSinglePanel(VPANEL panel) = 0;
	virtual void					SetModalPanel(VPANEL) = 0;
	virtual VPANEL					GetModalPanel() = 0;
	virtual void					UnlockCursor() = 0;
	virtual void					LockCursor() = 0;
	virtual void					SetTranslateExtendedKeys(bool state) = 0;
	virtual VPANEL					GetTopmostPopup() = 0;
	virtual void					SetTopLevelFocus(VPANEL panel) = 0;
	virtual HFont					CreateFont() = 0; //63
	virtual bool					SetFontGlyphSet(HFont hFont, const char* szFont, int nTall, int nWeight, int nFlags, int nBlur, int nScanlines, int unk1, int unk2) = 0;
	virtual bool					AddCustomFontFile(const char* fontFileName) = 0;
	virtual int						GetFontTall(HFont font) = 0;
	virtual int						GetFontTallRequested(HFont font) = 0;
	virtual int						GetFontAscent(HFont font, wchar_t wch) = 0;
	virtual bool					IsFontAdditive(HFont font) = 0;
	virtual void					GetCharABCwide(HFont font, int ch, int& a, int& b, int& c) = 0;
	virtual int						GetCharacterWidth(HFont font, int ch) = 0;
	virtual void					GetTextSize(HFont font, const wchar_t* text, int& wide, int& tall) = 0;
	virtual VPANEL					GetNotifyPanel() = 0;
	virtual void					SetNotifyIcon(VPANEL context, int icon, VPANEL panelToReceiveMessages, const char* text) = 0;
	virtual void					PlaySound(const char* fileName) = 0;
	virtual int						GetPopupCount() = 0;
	virtual VPANEL					GetPopup(int index) = 0;
	virtual bool					ShouldPaintChildPanel(VPANEL childPanel) = 0;
	virtual bool					RecreateContext(VPANEL panel) = 0;
	virtual void					AddPanel(VPANEL panel) = 0;
	virtual void					ReleasePanel(VPANEL panel) = 0;
	virtual void					MovePopupToFront(VPANEL panel) = 0;
	virtual void					MovePopupToBack(VPANEL panel) = 0;
	virtual void					SolveTraverse(VPANEL panel, bool forceApplySchemeSettings = false) = 0;
	virtual void					PaintTraverse(VPANEL panel) = 0;
	virtual void					EnableMouseCapture(VPANEL panel, bool state) = 0;
	virtual void					GetWorkspaceBounds(int& x, int& y, int& wide, int& tall) = 0;
	virtual void					GetAbsoluteWindowBounds(int& x, int& y, int& wide, int& tall) = 0;
	virtual void					GetProportionalBase(int& width, int& height) = 0;
	virtual void					CalculateMouseVisible() = 0;
	virtual bool					NeedKBInput() = 0;
	virtual bool					HasCursorPosFunctions() = 0;
	virtual void					SurfaceGetCursorPos(int& x, int& y) = 0;
	virtual void					SurfaceSetCursorPos(int x, int y) = 0;
	virtual void					DrawTexturedLine(const Vertex_t& a, const Vertex_t& b) = 0;
	virtual void					DrawOutlinedCircle(int x, int y, int radius, int segments) = 0;
	virtual void					DrawTexturedPolyLine(const Vertex_t* p, int n) = 0;
	virtual void					DrawTexturedSubRect(int x0, int y0, int x1, int y1, float texs0, float text0, float texs1, float text1) = 0;
	virtual void					DrawTexturedPolygon(int n, Vertex_t* pVertices, bool bClipVertices) = 0;
	virtual const wchar_t*			GetTitle(VPANEL panel) = 0;
	virtual bool					IsCursorLocked(void) const = 0;
	virtual void					SetWorkspaceInsets(int left, int top, int right, int bottom) = 0;
	virtual bool					DrawGetUnicodeCharRenderInfo(wchar_t ch, CharRenderInfo& info) = 0;
	virtual void					DrawRenderCharFromInfo(const CharRenderInfo& info) = 0;
	virtual void					DrawSetAlphaMultiplier(float alpha) = 0;
	virtual float					DrawGetAlphaMultiplier() = 0;
	virtual void					SetAllowHTMLJavaScript(bool state) = 0;
	virtual void					OnScreenSizeChanged(int nOldWidth, int nOldHeight) = 0;
	virtual HCursor					CreateCursorFromFile(char const* curOrAniFile, char const* pPathID = 0) = 0;
	virtual void*					DrawGetTextureMatInfoFactory(int id) = 0;
	virtual void					PaintTraverseEx(VPANEL panel, bool paintPopups = false) = 0;
	virtual float					GetZPos() const = 0;
	virtual void					SetPanelForInput(VPANEL vpanel) = 0;

private:
	virtual void					DrawFilledRectFastFade(int unk1, int unk2, int unk3, int unk4, int unk5, int unk6, unsigned int alpha0, unsigned int alpha1, bool bHorizontal) = 0;

public:
	virtual void					DrawFilledRectFade(int x0, int y0, int x1, int y1, unsigned int alpha0, unsigned int alpha1, bool bHorizontal) = 0;
	virtual void					DrawSetTextureRGBAEx(int id, const unsigned char* rgba, int wide, int tall, int imageFormat) = 0;
	virtual void					DrawSetTextScale(float sx, float sy) = 0;
	virtual bool					SetBitmapFontGlyphSet(HFont font, const char* windowsFontName, float scalex, float scaley, int flags) = 0;
	virtual bool					AddBitmapFontFile(const char* fontFileName) = 0;
	virtual void					SetBitmapFontName(const char* pName, const char* pFontFilename) = 0;
	virtual const char*				GetBitmapFontName(const char* pName) = 0;
	virtual void					ClearTemporaryFontCache(void) = 0;
	virtual void*					GetIconImageForFullPath(char const* pFullPath) = 0;
	virtual void					DrawUnicodeString(const wchar_t* pwString, FontDrawType_t drawType = FONT_DRAW_DEFAULT) = 0;
	virtual void					PrecacheFontCharacters(HFont font, wchar_t* pCharacters) = 0;
	virtual const char*				GetResolutionKey(void) const = 0;
	virtual const char*				GetFontName(HFont font) = 0;
	virtual const char*				GetFontFamilyName(HFont font) = 0;
	virtual bool					ForceScreenSizeOverride(bool bState, int wide, int tall) = 0;
	virtual bool					ForceScreenPosOffset(bool bState, int x, int y) = 0;
	virtual void					OffsetAbsPos(int& x, int& y) = 0;
	virtual void					SetAbsPosForContext(int id, int x, int y) = 0;
	virtual void					GetAbsPosForContext(int id, int& x, int& y) = 0;
	virtual void					ResetFontCaches() = 0;
	virtual bool					IsScreenSizeOverrideActive(void) = 0;
	virtual bool					IsScreenPosOverrideActive(void) = 0;
	virtual void					DestroyTextureID(int id) = 0;

private:
	virtual const char*				GetWebkitHTMLUserAgentString(void) = 0;
	virtual void*					AccessChromeHTMLController(void) = 0;

public:
	virtual int						GetTextureNumFrames(int id) = 0;
	virtual void					DrawSetTextureFrame(int id, int nFrame, unsigned int* pFrameCache) = 0;
	virtual void					DrawTexturedRectEx(void* unk1) = 0;
	virtual void					GetKernedCharWidth(HFont font, wchar_t ch, wchar_t chBefore, wchar_t chAfter, float& wide, float& abcA, float& abcC) = 0;
	virtual void					DrawUpdateRegionTextureRGBA(int nTextureID, int x, int y, const unsigned char* pchData, int wide, int tall, int imageFormat) = 0;
};

namespace I { inline IVGuiSurface* VGuiSurface = nullptr; }