#pragma once

#include "MatRenderContext.h"

class IMaterialVar;
class IMaterialSystemHardwareConfig;
struct MaterialSystem_Config_t;

typedef unsigned long FourCC;
typedef unsigned short MaterialVarSym_t;
typedef unsigned short MaterialHandle_t;

class IMaterial
{
public:
	virtual const char*				GetName() const = 0;
	virtual const char*				GetTextureGroupName() const = 0;
	virtual PreviewImageRetVal_t	GetPreviewImageProperties(int* width, int* height, ImageFormat* imageFormat, bool* isTranslucent) const = 0;
	virtual PreviewImageRetVal_t	GetPreviewImage(unsigned char* data, int width, int height, ImageFormat imageFormat) const = 0;
	virtual int						GetMappingWidth() = 0;
	virtual int						GetMappingHeight() = 0;
	virtual int						GetNumAnimationFrames() = 0;
	virtual bool					InMaterialPage(void) = 0;
	virtual	void					GetMaterialOffset(float* pOffset) = 0;
	virtual void					GetMaterialScale(float* pScale) = 0;
	virtual IMaterial*				GetMaterialPage(void) = 0;
	virtual IMaterialVar*			FindVar(const char* varName, bool* found, bool complain = true) = 0;
	virtual void					IncrementReferenceCount(void) = 0;
	virtual void					DecrementReferenceCount(void) = 0;
	virtual int 					GetEnumerationID(void) const = 0;
	virtual void					GetLowResColorSample(float s, float t, float* color) const = 0;
	virtual void					RecomputeStateSnapshots() = 0;
	virtual bool					IsTranslucent() = 0;
	virtual bool					IsAlphaTested() = 0;
	virtual bool					IsVertexLit() = 0;
	virtual void*					GetVertexFormat() const = 0;
	virtual bool					HasProxy(void) const = 0;
	virtual bool					UsesEnvCubemap(void) = 0;
	virtual bool					NeedsTangentSpace(void) = 0;
	virtual bool					NeedsPowerOfTwoFrameBufferTexture(bool bCheckSpecificToThisFrame = true) = 0;
	virtual bool					NeedsFullFrameBufferTexture(bool bCheckSpecificToThisFrame = true) = 0;
	virtual bool					NeedsSoftwareSkinning(void) = 0;
	virtual void					AlphaModulate(float alpha) = 0;
	virtual void					ColorModulate(float r, float g, float b) = 0;
	virtual void					SetMaterialVarFlag(MaterialVarFlags_t flag, bool on) = 0;
	virtual bool					GetMaterialVarFlag(MaterialVarFlags_t flag) const = 0;
	virtual void					GetReflectivity(Vector& reflect) = 0;
	virtual bool					GetPropertyFlag(MaterialPropertyTypes_t type) = 0;
	virtual bool					IsTwoSided() = 0;
	virtual void					SetShader(const char* pShaderName) = 0;
	virtual int						GetNumPasses(void) = 0;
	virtual int						GetTextureMemoryBytes(void) = 0;
	virtual void					Refresh() = 0;
	virtual bool					NeedsLightmapBlendAlpha(void) = 0;
	virtual bool					NeedsSoftwareLighting(void) = 0;
	virtual int						ShaderParamCount() const = 0;
	virtual IMaterialVar**			GetShaderParams(void) = 0;
	virtual bool					IsErrorMaterial() const = 0;
	virtual void					SetUseFixedFunctionBakedLighting(bool bEnable) = 0;
	virtual float					GetAlphaModulation() = 0;
	virtual void					GetColorModulation(float* r, float* g, float* b) = 0;

public:
	inline void						AddRef()  { IncrementReferenceCount(); }
	inline void						Release() { DecrementReferenceCount(); }
};

class IMaterialVar
{
public:
	virtual ITexture*			GetTextureValue(void) = 0;
	virtual char const*			GetName(void) const = 0;
	virtual MaterialVarSym_t	GetNameAsSymbol() const = 0;
	virtual void				SetFloatValue(float val) = 0;
	virtual void				SetIntValue(int val) = 0;
	virtual void				SetStringValue(char const* val) = 0;
	virtual char const*			GetStringValue(void) const = 0;
	virtual void				SetFourCCValue(FourCC type, void* pData) = 0;
	virtual void				GetFourCCValue(FourCC* type, void** ppData) = 0;
	virtual void				SetVecValue(float const* val, int numcomps) = 0;
	virtual void				SetVecValue(float x, float y) = 0;
	virtual void				SetVecValue(float x, float y, float z) = 0;
	virtual void				SetVecValue(float x, float y, float z, float w) = 0;
	virtual void				GetLinearVecValue(float* val, int numcomps) const = 0;
	virtual void				SetTextureValue(ITexture*) = 0;
	virtual IMaterial*			GetMaterialValue(void) = 0;
	virtual void				SetMaterialValue(IMaterial*) = 0;
	virtual bool				IsDefined() const = 0;
	virtual void				SetUndefined() = 0;
	virtual void				SetMatrixValue(VMatrix const& matrix) = 0;
	virtual const VMatrix&		GetMatrixValue() = 0;
	virtual bool				MatrixIsIdentity() const = 0;
	virtual void				CopyFrom(IMaterialVar* pMaterialVar) = 0;
	virtual void				SetValueAutodetectType(char const* val) = 0;
	virtual IMaterial*			GetOwningMaterial() = 0;
	virtual void				SetVecComponentValue(float fVal, int nComponent) = 0;
	virtual int					GetIntValueInternal(void) const = 0;
	virtual float				GetFloatValueInternal(void) const = 0;
	virtual float const*		GetVecValueInternal() const = 0;
	virtual void				GetVecValueInternal(float* val, int numcomps) const = 0;
	virtual int					VectorSizeInternal() const = 0;
};

class ITexture
{
public:
	virtual const char*			GetName(void) const = 0;
	virtual int					GetMappingWidth() const = 0;
	virtual int					GetMappingHeight() const = 0;
	virtual int					GetActualWidth() const = 0;
	virtual int					GetActualHeight() const = 0;
	virtual int					GetNumActionFrames() const = 0;
	virtual bool				IsTranslucent() const = 0;
	virtual bool				IsMipmapped() const = 0;
	virtual void				GetLowResColorSample(float s, float t, float* color) const = 0;
	virtual void*				GetResourceData(unsigned int data_type, size_t* num_bytes) const = 0;
	virtual void				IncrementReferenceCount(void) = 0;
	virtual void				DecrementReferenceCount(void) = 0;
	virtual void				SetTextureRegenerator(void* texture_regen) = 0;
	virtual void				Download(void* rect = 0, int additional_creation_flags = 0) = 0;
	virtual int					GetApproximateVidMemBytes(void) const = 0;
	virtual bool				IsError() const = 0;
	virtual bool				IsVolumeTexture() const = 0;
	virtual int					GetMappingDepth() const = 0;
	virtual int					GetActualDepth() const = 0;
	virtual ImageFormat			GetImageFormat() const = 0;
	virtual NormalDecodeMode_t	GetNormalDecodeMode() const = 0;
	virtual bool				IsRenderTarget() const = 0;
	virtual bool				IsCubeMap() const = 0;
	virtual bool				IsNormalMap() const = 0;
	virtual bool				IsProcedural() const = 0;
	virtual void				DeleteIfUnreferenced() = 0;
	virtual void				SwapContents(ITexture* pOther) = 0;
	virtual unsigned int		GetFlags(void) const = 0;
	virtual void				ForceLODOverride(int iNumLodsOverrideUpOrDown) = 0;

public:
	inline void					AddRef()  { IncrementReferenceCount(); }
	inline void					Release() { DecrementReferenceCount(); }
};

class IMaterialSystem : public IAppSystem
{
public:
	virtual void*							Init(char const* pShaderAPIDLL, void* pMaterialProxyFactory, void* fileSystemFactory, void* cvarFactory = NULL) = 0;
	virtual void							SetShaderAPI(char const* pShaderAPIDLL) = 0;
	virtual void							SetAdapter(int nAdapter, int nFlags) = 0;
	virtual void							ModInit() = 0;
	virtual void							ModShutdown() = 0;
	virtual void							SetThreadMode(MaterialThreadMode_t mode, int nServiceThread = -1) = 0;
	virtual MaterialThreadMode_t			GetThreadMode() = 0;
	virtual bool							IsRenderThreadSafe(void) = 0;
	virtual void							ExecuteQueued() = 0;
	virtual IMaterialSystemHardwareConfig*	GetHardwareConfig(const char* pVersion, int* returnCode) = 0;
	virtual bool							UpdateConfig(bool bForceUpdate) = 0;
	virtual bool							OverrideConfig(const MaterialSystem_Config_t& config, bool bForceUpdate) = 0;
	virtual const MaterialSystem_Config_t&	GetCurrentConfigForVideoCard() const = 0;
	virtual bool							GetRecommendedConfigurationInfo(int nDXLevel, KeyValues* pKeyValues) = 0;
	virtual int								GetDisplayAdapterCount() const = 0;
	virtual int								GetCurrentAdapter() const = 0;
	virtual void							GetDisplayAdapterInfo(int adapter, MaterialAdapterInfo_t& info) const = 0;
	virtual int								GetModeCount(int adapter) const = 0;
	virtual void							GetModeInfo(int adapter, int mode, MaterialVideoMode_t& info) const = 0;
	virtual void							AddModeChangeCallBack(void* func) = 0;
	virtual void							GetDisplayMode(MaterialVideoMode_t& mode) const = 0;
	virtual bool							SetMode(void* hwnd, const MaterialSystem_Config_t& config) = 0;
	virtual bool							SupportsMSAAMode(int nMSAAMode) = 0;
	virtual const void*						GetVideoCardIdentifier(void) const = 0;
	virtual void							SpewDriverInfo() const = 0;
	virtual void							GetBackBufferDimensions(int& width, int& height) const = 0;
	virtual ImageFormat						GetBackBufferFormat() const = 0;
	virtual bool							SupportsHDRMode(void* nHDRModede) = 0;
	virtual bool							AddView(void* hwnd) = 0;
	virtual void							RemoveView(void* hwnd) = 0;
	virtual void							SetView(void* hwnd) = 0;
	virtual void							BeginFrame(float frameTime) = 0;
	virtual void							EndFrame() = 0;
	virtual void							Flush(bool flushHardware = false) = 0;
	virtual void							SwapBuffers() = 0;
	virtual void							EvictManagedResources() = 0;
	virtual void							ReleaseResources(void) = 0;
	virtual void							ReacquireResources(void) = 0;
	virtual void							AddReleaseFunc(void* func) = 0;
	virtual void							RemoveReleaseFunc(void* func) = 0;
	virtual void							AddRestoreFunc(void* func) = 0;
	virtual void							RemoveRestoreFunc(void* func) = 0;
	virtual void							ResetTempHWMemory(bool bExitingLevel = false) = 0;
	virtual void							HandleDeviceLost() = 0;
	virtual int								ShaderCount() const = 0;
	virtual int								GetShaders(int nFirstShader, int nMaxCount, void** ppShaderList) const = 0;
	virtual int								ShaderFlagCount() const = 0;
	virtual const char*						ShaderFlagName(int nIndex) const = 0;
	virtual void							GetShaderFallback(const char* pShaderName, char* pFallbackShader, int nFallbackLength) = 0;
	virtual void*							GetMaterialProxyFactory() = 0;
	virtual void							SetMaterialProxyFactory(void* pFactory) = 0;
	virtual void							EnableEditorMaterials() = 0;
	virtual void							EnableGBuffers(void) = 0;
	virtual void							SetInStubMode(bool bInStubMode) = 0;
	virtual void							DebugPrintUsedMaterials(const char* pSearchSubString, bool bVerbose) = 0;
	virtual void							DebugPrintUsedTextures(void) = 0;
	virtual void							ToggleSuppressMaterial(char const* pMaterialName) = 0;
	virtual void							ToggleDebugMaterial(char const* pMaterialName) = 0;
	virtual bool							UsingFastClipping(void) = 0;
	virtual int								StencilBufferBits(void) = 0;
	virtual void							UncacheAllMaterials() = 0;
	virtual void							UncacheUnusedMaterials(bool bRecomputeStateSnapshots = false) = 0;
	virtual void							CacheUsedMaterials() = 0;
	virtual void							ReloadTextures() = 0;
	virtual void							ReloadMaterials(const char* pSubString = NULL) = 0;
	virtual IMaterial*						CreateMaterial(const char* pMaterialName, KeyValues* pVMTKeyValues) = 0;
	virtual IMaterial*						FindMaterial(char const* pMaterialName, const char* pTextureGroupName, bool complain = true, const char* pComplainPrefix = NULL) = 0;
	virtual MaterialHandle_t				FirstMaterial() const = 0;
	virtual MaterialHandle_t				NextMaterial(MaterialHandle_t h) const = 0;
	virtual MaterialHandle_t				InvalidMaterial() const = 0;
	virtual IMaterial*						GetMaterial(MaterialHandle_t h) const = 0;
	virtual int								GetNumMaterials() const = 0;
	virtual ITexture*						FindTexture(char const* pTextureName, const char* pTextureGroupName, bool complain = true, int additional_creation_flags = 0) = 0;
	virtual bool							IsTextureLoaded(char const* pTextureName) const = 0;
	virtual ITexture*						CreateProceduralTexture(const char* pTextureName, const char* pTextureGroupName, int w, int h, ImageFormat fmt, int nFlags) = 0;
	virtual void							BeginRenderTargetAllocation() = 0;
	virtual void							EndRenderTargetAllocation() = 0;
	virtual ITexture*						CreateRenderTargetTexture(int w, int h, RenderTargetSizeMode_t sizeMode, ImageFormat format, MaterialRenderTargetDepth_t depth = MATERIAL_RT_DEPTH_SHARED) = 0;
	virtual ITexture*						CreateNamedRenderTargetTextureEx(const char* pRTName, int w, int h, RenderTargetSizeMode_t sizeMode, ImageFormat format, MaterialRenderTargetDepth_t depth = MATERIAL_RT_DEPTH_SHARED, unsigned int textureFlags = TEXTUREFLAGS_CLAMPS | TEXTUREFLAGS_CLAMPT, unsigned int renderTargetFlags = 0) = 0;
	virtual ITexture*						CreateNamedRenderTargetTexture(const char* pRTName, int w, int h, RenderTargetSizeMode_t sizeMode, ImageFormat format, MaterialRenderTargetDepth_t depth = MATERIAL_RT_DEPTH_SHARED, bool bClampTexCoords = true, bool bAutoMipMap = false) = 0;
	virtual ITexture*						CreateNamedRenderTargetTextureEx2(const char* pRTName, int w, int h, RenderTargetSizeMode_t sizeMode, ImageFormat format, MaterialRenderTargetDepth_t depth = MATERIAL_RT_DEPTH_SHARED, unsigned int textureFlags = TEXTUREFLAGS_CLAMPS | TEXTUREFLAGS_CLAMPT, unsigned int renderTargetFlags = 0) = 0;
	virtual void							BeginLightmapAllocation() = 0;
	virtual void							EndLightmapAllocation() = 0;
	virtual int 							AllocateLightmap(int width, int height, int offsetIntoLightmapPage[2], IMaterial* pMaterial) = 0;
	virtual int								AllocateWhiteLightmap(IMaterial* pMaterial) = 0;
	virtual void							UpdateLightmap(int lightmapPageID, int lightmapSize[2], int offsetIntoLightmapPage[2], float* pFloatImage, float* pFloatImageBump1, float* pFloatImageBump2, float* pFloatImageBump3) = 0;
	virtual int								GetNumSortIDs() = 0;
	virtual void							GetSortInfo(void* sortInfoArray) = 0;
	virtual void							GetLightmapPageSize(int lightmap, int* width, int* height) const = 0;
	virtual void							ResetMaterialLightmapPageInfo() = 0;
	virtual void							ClearBuffers(bool bClearColor, bool bClearDepth, bool bClearStencil = false) = 0;
	virtual IMatRenderContext*				GetRenderContext() = 0;
	virtual void							BeginUpdateLightmaps(void) = 0;
	virtual void							EndUpdateLightmaps(void) = 0;
	virtual void*							Lock() = 0;
	virtual void							Unlock(void* unk1) = 0;
	virtual IMatRenderContext*				CreateRenderContext(MaterialContextType_t type) = 0;
	virtual IMatRenderContext*				SetRenderContext(IMatRenderContext*) = 0;
	virtual bool							SupportsCSAAMode(int nNumSamples, int nQualityLevel) = 0;
	virtual void							RemoveModeChangeCallBack(void* func) = 0;
	virtual IMaterial*						FindProceduralMaterial(const char* pMaterialName, const char* pTextureGroupName, KeyValues* pVMTKeyValues) = 0;
	virtual void							AddTextureAlias(const char* pAlias, const char* pRealName) = 0;
	virtual void							RemoveTextureAlias(const char* pAlias) = 0;
	virtual int								AllocateDynamicLightmap(int lightmapSize[2], int* pOutOffsetIntoPage, int frameID) = 0;
	virtual void							SetExcludedTextures(const char* pScriptName) = 0;
	virtual void							UpdateExcludedTextures(void) = 0;
	virtual bool							IsInFrame() const = 0;
	virtual void							CompactMemory() = 0;
	virtual void							ReloadFilesInList(void* pFilesToReload) = 0;

private:
	virtual void*							GetTextureInformation(const char* unk1, void* unk2) const = 0;

public:
	virtual void							FinishRenderTargetAllocation(void) = 0;
	virtual void							ReEnableRenderTargetAllocation_IRealizeIfICallThisAllTexturesWillBeUnloadedAndLoadTimeWillSufferHorribly(void) = 0;
};

namespace I { inline IMaterialSystem* MaterialSystem = nullptr; }

inline bool IsErrorMaterial(IMaterial* pMat) {
	return !pMat || pMat->IsErrorMaterial();
}

inline bool IsErrorTexture(ITexture* pTex) {
	return !pTex || pTex->IsError();
}