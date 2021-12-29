#pragma once

#include "GameMovement.h"

class MDLHandle_t;
struct vcollide_t;
struct virtualmodel_t;

typedef void model_t;

struct mstudiobbox {
	int         bone;
	int         group;
	Vector		bbmin;
	Vector		bbmax;
	int         szhitboxnameindex;
	int         _pad00[8];

	const char* pszHitboxName()
	{
		if (szhitboxnameindex == 0)
			return "";

		return ((const char*)this) + szhitboxnameindex;
	}
};

struct mstudiohitboxset {
	int                   sznameindex;
	inline char* const    pszName(void) const { return ((char*)this) + sznameindex; }
	int                   numhitboxes;
	int                   hitboxindex;
	inline mstudiobbox*	  pHitbox(int i) const { return (mstudiobbox*)(((unsigned char*)this) + hitboxindex) + i; };
};

struct studiohdr_t {
	unsigned char     _pad00[0xAC];
	int               numhitboxsets;
	int               hitboxsetindex;

	inline mstudiohitboxset* pHitboxSet(const int n) const {
		return (mstudiohitboxset*)(((unsigned char*)this) + hitboxsetindex) + n;
	};
};

class IVModelInfo
{
public:
	virtual							~IVModelInfo(void) { }

	virtual const model_t*			GetModel(int modelindex) const = 0;
	virtual int						GetModelIndex(const char* name) const = 0;
	virtual const char*				GetModelName(const model_t* model) const = 0;
	virtual vcollide_t*				GetVCollide(const model_t* model) const = 0;
	virtual vcollide_t*				GetVCollide(int modelindex) const = 0;
	virtual vcollide_t*				GetPhysics2VCollide(int unk1) const = 0;
	virtual void					GetModelBounds(const model_t* model, Vector& mins, Vector& maxs) const = 0;
	virtual	void					GetModelRenderBounds(const model_t* model, Vector& mins, Vector& maxs) const = 0;
	virtual int						GetModelFrameCount(const model_t* model) const = 0;
	virtual int						GetModelType(const model_t* model) const = 0;
	virtual void*					GetModelExtraData(const model_t* model) = 0;
	virtual bool					ModelHasMaterialProxy(const model_t* model) const = 0;
	virtual bool					IsTranslucent(model_t const* model) const = 0;
	virtual bool					IsTranslucentTwoPass(const model_t* model) const = 0;

private:
	virtual void*					Unused0(void) = 0;

public:
	virtual void					ComputeTranslucencyType(model_t const* unk1, int unk2, int unk3) = 0;
	virtual int						GetModelMaterialCount(const model_t* model) const = 0;
	virtual void					GetModelMaterials(const model_t* model, int count, IMaterial** ppMaterial) = 0;
	virtual bool					IsModelVertexLit(const model_t* model) const = 0;
	virtual const char*				GetModelKeyValueText(const model_t* model) = 0;
	virtual bool					GetModelKeyValue(const model_t* model, void* buf) = 0;
	virtual float					GetModelRadius(const model_t* model) = 0;
	virtual const studiohdr_t*		FindModel(const studiohdr_t* pStudioHdr, void** cache, const char* modelname) const = 0;
	virtual const studiohdr_t*		FindModel(void* cache) const = 0;
	virtual	virtualmodel_t*			GetVirtualModel(const studiohdr_t* pStudioHdr) const = 0;
	virtual byte*					GetAnimBlock(const studiohdr_t* pStudioHdr, int iBlock) const = 0;
	virtual void					GetModelMaterialColorAndLighting(const model_t* model, Vector const& origin, Vector const& angles, trace_t* pTrace, Vector& lighting, Vector& matColor) = 0;
	virtual void					GetIlluminationPoint(const model_t* model, IClientRenderable* pRenderable, Vector const& origin, Vector const& angles, Vector* pLightingCenter) = 0;
	virtual int						GetModelContents(int modelIndex) const = 0;
	virtual studiohdr_t*			GetStudiomodel(const model_t* mod) = 0;
	virtual int						GetModelSpriteWidth(const model_t* model) const = 0;
	virtual int						GetModelSpriteHeight(const model_t* model) const = 0;
	virtual void					SetLevelScreenFadeRange(float flMinSize, float flMaxSize) = 0;
	virtual void					GetLevelScreenFadeRange(float* pMinArea, float* pMaxArea) const = 0;
	virtual void					SetViewScreenFadeRange(float flMinSize, float flMaxSize) = 0;
	virtual unsigned char			ComputeLevelScreenFade(const Vector& vecAbsOrigin, float flRadius, float flFadeScale) const = 0;
	virtual unsigned char			ComputeViewScreenFade(const Vector& vecAbsOrigin, float flRadius, float flFadeScale) const = 0;
	virtual int						GetAutoplayList(const studiohdr_t* pStudioHdr, unsigned short** pAutoplayList) const = 0;
	virtual CPhysCollide*			GetCollideForVirtualTerrain(int index) = 0;
	virtual bool					IsUsingFBTexture(const model_t* model, int nSkin, int nBody, void* pClientRenderable) const = 0;
	virtual const model_t*			FindOrLoadModel(const char* name) const = 0;
	virtual MDLHandle_t				GetCacheHandle(const model_t* model) const = 0;
	virtual int						GetBrushModelPlaneCount(const model_t* model) const = 0;
	virtual void					GetBrushModelPlane(const model_t* model, int nIndex, cplane_t& plane, Vector* pOrigin) const = 0;
	virtual int						GetSurfacepropsForVirtualTerrain(int index) = 0;
	virtual bool					UsesEnvCubemap(const model_t* model) const = 0;
	virtual bool					UsesStaticLighting(const model_t* model) const = 0;
};

namespace I { inline IVModelInfo* ModelInfo = nullptr; }