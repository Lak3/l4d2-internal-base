#pragma once

#include "Prediction.h"

class IClientRenderable;
class IMaterial;
class ITexture;
class IMatRenderContext;

struct colorVec {
	unsigned r, g, b, a;
};

enum {
	DRAWWORLDLISTS_DRAW_STRICTLYABOVEWATER = 0x001,
	DRAWWORLDLISTS_DRAW_STRICTLYUNDERWATER = 0x002,
	DRAWWORLDLISTS_DRAW_INTERSECTSWATER = 0x004,
	DRAWWORLDLISTS_DRAW_WATERSURFACE = 0x008,
	DRAWWORLDLISTS_DRAW_SKYBOX = 0x010,
	DRAWWORLDLISTS_DRAW_CLIPSKYBOX = 0x020,
	DRAWWORLDLISTS_DRAW_SHADOWDEPTH = 0x040,
	DRAWWORLDLISTS_DRAW_REFRACTION = 0x080,
	DRAWWORLDLISTS_DRAW_REFLECTION = 0x100,
	DRAWWORLDLISTS_DRAW_WORLD_GEOMETRY = 0x200,
	DRAWWORLDLISTS_DRAW_DECALS_AND_OVERLAYS = 0x400,
	DRAWWORLDLISTS_DRAW_SIMPLE_WORLD_MODEL = 0x800,
	DRAWWORLDLISTS_DRAW_SIMPLE_WORLD_MODEL_WATER = 0x1000,
	DRAWWORLDLISTS_DRAW_SKIP_DISPLACEMENTS = 0x2000,
	DRAWWORLDLISTS_DRAW_SSAO = 0x4000
};

enum {
	MAT_SORT_GROUP_STRICTLY_ABOVEWATER = 0,
	MAT_SORT_GROUP_STRICTLY_UNDERWATER,
	MAT_SORT_GROUP_INTERSECTS_WATER_SURFACE,
	MAT_SORT_GROUP_WATERSURFACE,

	MAX_MAT_SORT_GROUPS
};

enum ERenderDepthMode_t {
	DEPTH_MODE_NORMAL = 0,
	DEPTH_MODE_SHADOW = 1,
	DEPTH_MODE_SSA0 = 2,

	DEPTH_MODE_MAX
};

enum {
	VIEW_SETUP_VIS_EX_RETURN_FLAGS_USES_RADIAL_VIS = 0x00000001
};

class IVRenderView
{
public:
	virtual void			DrawBrushModel(IClientEntity* baseentity, void* model, const Vector& origin, const Vector& angles, bool bUnused) = 0;
	virtual void			DrawIdentityBrushModel(void* pList, void* model) = 0;
	virtual void			TouchLight(struct dlight_t* light) = 0;
	virtual void			Draw3DDebugOverlays(void) = 0;
	virtual void			SetBlend(float blend) = 0;
	virtual float			GetBlend(void) = 0;
	virtual void			SetColorModulation(float const* blend) = 0;
	virtual void			GetColorModulation(float* blend) = 0;
	virtual void			SceneBegin(void) = 0;
	virtual void			SceneEnd(void) = 0;
	virtual void			GetVisibleFogVolume(const Vector& eyePoint, const void* pVisOverrideData, void* pInfo) = 0;
	virtual void*			CreateWorldList() = 0;
	virtual void			BuildWorldLists(void* pList, void* pInfo, int iForceFViewLeaf, const void* pVisData = NULL, bool bShadowDepth = false, float* pReflectionWaterHeight = NULL) = 0;
	virtual void			DrawWorldLists(void* pRenderContext, void* pList, unsigned long flags, float waterZAdjust) = 0;

private:
	virtual void*			GetNumIndicesForWorldLists(void* unk1, unsigned long unk2) = 0;

public:
	virtual void			DrawTopView(bool enable) = 0;
	virtual void			TopViewBounds(Vector2D const& mins, Vector2D const& maxs) = 0;
	virtual void			DrawLights(void) = 0;
	virtual void			DrawMaskEntities(void) = 0;
	virtual void			DrawTranslucentSurfaces(void* pRenderContext, void* pList, int* pSortList, int sortCount, unsigned long flags) = 0;
	virtual void			DrawLineFile(void) = 0;
	virtual void			DrawLightmaps(void* pList, int pageId) = 0;
	virtual void			ViewSetupVis(bool novis, int numorigins, const Vector origin[]) = 0;
	virtual bool			AreAnyLeavesVisible(int* leafList, int nLeaves) = 0;
	virtual	void			VguiPaint(void) = 0;
	virtual void			ViewDrawFade(byte* color, IMaterial* pMaterial, bool mapFullTextureToScreen = true) = 0;
	virtual void			OLD_SetProjectionMatrix(float fov, float zNear, float zFar) = 0;
	virtual colorVec		GetLightAtPoint(Vector& pos) = 0;
	virtual int				GetViewEntity(void) = 0;
	virtual bool			IsViewEntity(int entindex) = 0;
	virtual float			GetFieldOfView(void) = 0;
	virtual unsigned char** GetAreaBits(void) = 0;
	virtual void			SetFogVolumeState(int nVisibleFogVolume, bool bUseHeightFog) = 0;
	virtual void			SetWaterFogNearFar(int unk1) = 0;
	virtual void			InstallBrushSurfaceRenderer(void* pBrushRenderer) = 0;
	virtual void			DrawBrushModelShadow(IClientRenderable* pRenderable) = 0;
	virtual	bool			LeafContainsTranslucentSurfaces(void* pList, int sortIndex, unsigned long flags) = 0;
	virtual bool			DoesBoxIntersectWaterVolume(const Vector& mins, const Vector& maxs, int leafWaterDataID) = 0;
	virtual void			SetAreaState(unsigned char* chAreaBits, unsigned char* chAreaPortalBits) = 0;
	virtual void			VGui_Paint(int mode) = 0;
	virtual void			Push3DView(IMatRenderContext* pRenderContext, const void* view, int nFlags, ITexture* pRenderTarget, void* frustumPlanes) = 0;
	virtual void			Push2DView(IMatRenderContext* pRenderContext, const void* view, int nFlags, ITexture* pRenderTarget, void* frustumPlanes) = 0;
	virtual void			PopView(IMatRenderContext* pRenderContext, void* frustumPlanes) = 0;
	virtual void			SetMainView(const Vector& vecOrigin, const Vector& angles) = 0;
	virtual void			ViewSetupVisEx(bool novis, int numorigins, const Vector origin[], unsigned int& returnFlags) = 0;
	virtual void			OverrideViewFrustum(void* custom) = 0;
	virtual void			DrawBrushModelShadowDepth(IClientEntity* baseentity, void* model, const Vector& origin, const Vector& angles, ERenderDepthMode_t DepthMode) = 0;
	virtual void			UpdateBrushModelLightmap(void* model, IClientRenderable* pRenderable) = 0;
	virtual void			BeginUpdateLightmaps(void) = 0;
	virtual void			EndUpdateLightmaps() = 0;
	virtual void			OLD_SetOffCenterProjectionMatrix(float fov, float zNear, float zFar, float flAspectRatio, float flBottom, float flTop, float flLeft, float flRight) = 0;
	virtual void			OLD_SetProjectionMatrixOrtho(float left, float top, float right, float bottom, float zNear, float zFar) = 0;
	virtual void			Push3DView(const void* pSetup, int unk1, ITexture* unk2, void* pPlane, ITexture* unk3) = 0;
	virtual void			GetMatricesForView(const void* view, VMatrix* pWorldToView, VMatrix* pViewToProjection, VMatrix* pWorldToProjection, VMatrix* pWorldToPixels) = 0;

private:
	virtual void*			EnumerateLeaf(int unk1, int unk2) = 0;
};

namespace I { inline IVRenderView* RenderView = nullptr; }