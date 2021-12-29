#pragma once

#include "MatSystemSurface.h"

class IMatRenderContext //: public IRefCounted or something.
{
public: //From the baseclass which I didn't bother to add.
	virtual int				AddRef() = 0;
	virtual int				Release() = 0;

public: //IMatRenderContext itself.
	virtual void			BeginRender() = 0;
	virtual void			EndRender() = 0;
	virtual void			Flush(bool flush_hardware = false) = 0;
	virtual void			BindLocalCubemap(void* texture) = 0;
	virtual void			SetRenderTarget(void* texture) = 0;
	virtual void*			GetRenderTarget() = 0;
	virtual void			GetRenderTargetDimensions(int& width, int& height) const = 0;
	virtual void			Bind(IMaterial* material, void* proxyData = 0) = 0;
	virtual void			BindLightmapPage(int lightmap_page_id) = 0;
	virtual void			DepthRange(float _near, float _far) = 0;
	virtual void			ClearBuffers(bool clear_color, bool clear_depth, bool clear_stencil = false) = 0;
	virtual void			ReadPixels(int x, int y, int width, int height, unsigned char* data, int dstFormat) = 0;
	virtual void			SetLightingState(void* unknown) = 0;
	virtual void			SetLights(int unk1, void* unk2) = 0;
	virtual void			SetAmbientLightCube(void* Vector_4d) = 0;
	virtual void			CopyRenderTargetToTexture(void* texture) = 0;
	virtual void			SetFramebufferCopyTexture(void* texture, int texture_index) = 0;
	virtual void*			GetFramebufferCopyTexture(int texture_index) = 0;
	virtual void			MatrixMode(int mode) = 0;
	virtual void			PushMatrix() = 0;
	virtual void			PopMatrix() = 0;
	virtual void			LoadMatrix(VMatrix const& matrix) = 0;
	virtual void			LoadMatrix(matrix3x4_t const& matrix) = 0;
	virtual void			MultMatrix(VMatrix const& matrix) = 0;
	virtual void			MultMatrix(matrix3x4_t const& matrix) = 0;
	virtual void			MultMatrixLocal(VMatrix const& matrix) = 0;
	virtual void			MultMatrixLocal(matrix3x4_t const& matrix) = 0;
	virtual void			GetMatrix(int matrix_mode, VMatrix* matrix) = 0;
	virtual void			GetMatrix(int matrix_mode, matrix3x4_t* matrix) = 0;
	virtual void			LoadIdentity(void) = 0;
	virtual void			OrTho(double left, double top, double right, double bottom, double zNear, double zFar) = 0;
	virtual void			PerspectiveX(double fovx, double aspect, double zNear, double zFar) = 0;
	virtual void			PickMatrix(int x, int y, int width, int height) = 0;
	virtual void			Rotate(float angle, float x, float y, float z) = 0;
	virtual void			Translate(float x, float y, float z) = 0;
	virtual void			Scale(float x, float y, float z) = 0;
	virtual void			Viewport(int x, int y, int width, int height) = 0;
	virtual void			GetViewport(int& x, int& y, int& width, int& height) const = 0;
	virtual void			CullMode(int cull_mode) = 0;
	virtual void			SetHeightClipMode(int height_clip_mode) = 0;
	virtual void			SetHeightClipZ(float z) = 0;
	virtual void			FogMode(int mode) = 0;
	virtual void			FogStart(float start) = 0;
	virtual void			FogEnd(float end) = 0;
	virtual int				GetFogMode() = 0;
	virtual void			FogColor3f(float r, float g, float b) = 0;
	virtual void			FogColor3fv(float const* rgb) = 0;
	virtual void			FogColor3ub(unsigned char r, unsigned char g, unsigned char b) = 0;
	virtual void			FogColor3ubv(unsigned char const* rgb) = 0;
	virtual void			GetFogColor(unsigned char* rgb) = 0;
	virtual void			SetFogZ(float _z) = 0;
	virtual void			FogStartWater(float start) = 0;
	virtual void			FogEndWater(float end) = 0;
	virtual void			SetNumBoneWeights(int num) = 0;
	virtual void*			CreateStaticMesh(unsigned long long fmt, char const* group, IMaterial* material, int unk1) = 0;
	virtual void			DestroyStaticMesh(void* mesh) = 0;
	virtual void*			GetDynamicMesh(bool buffered = true, void* vertex_override = 0, void* index_override = 0, IMaterial* bind = 0) = 0;
	virtual void*			CreateStaticVertexBuffer(unsigned long long fmt, int vertex_count, char const* group) = 0;
	virtual void*			CreateStaticIndexBuffer(int fmt, int index_cound, char const* group) = 0;
	virtual void			DestroyVertexBuffer(void* unk) = 0;
	virtual void			DestroyIndexBuffer(void* unk) = 0;
	virtual void*			GetDynamicVertexBuffer(int streamID, unsigned long long vertexFormat, bool bBuffered = true) = 0;
	virtual void*			GetDynamicIndexBuffer(int fmt, bool bBuffered = true) = 0;
	virtual void			BindVertexBuffer(int streamID, void* pVertexBuffer, int nOffsetInBytes, int nFirstVertex, int nVertexCount, unsigned long long fmt, int nRepetitions = 1) = 0;
	virtual void			BindIndexBuffer(void* pIndexBuffer, int nOffsetInBytes) = 0;
	virtual void			Draw(int primitiveType, int firstIndex, int numIndices) = 0;
	virtual int				SelectionMode(bool selection_mode) = 0;
	virtual void			SelectionBuffer(unsigned int* buffer, int size) = 0;
	virtual void			ClearSelectionNames() = 0;
	virtual void			LoadSelectionName(int name) = 0;
	virtual void			PushSelectionName(int name) = 0;
	virtual void			PopSelectionName() = 0;
	virtual void			ClearColor3ub(unsigned char r, unsigned char g, unsigned char b) = 0;
	virtual void			ClearColor4ub(unsigned char r, unsigned char g, unsigned char b, unsigned char a) = 0;
	virtual void			OverrideDepthEnable(bool enable, bool depth_enable) = 0;
	virtual void			DrawScreenSpaceQuad(IMaterial* material) = 0;
	virtual void			SynchToken(char const* token) = 0;
	virtual float			ComputePixelWidthOfSphere(const Vector& origin, float flRadius) = 0;
	virtual void*			CreateOcclusionQueryObject() = 0;
	virtual void			DestroyOcclusionQueryObject(void* unk) = 0;
	virtual void			BeginOcclusionQueryDrawing(void* unk) = 0;
	virtual void			EndOcclusionQueryDrawing(void* unk) = 0;
	virtual int				OcclusionQueryGetNumPixelsRendered(void* unk) = 0;
	virtual void			SetFlashlightMode(bool enable) = 0;
	virtual void			SetFlashlightState(const void* state, const VMatrix& world_to_texture) = 0;
	virtual int				GetHeightClipMode() = 0;
	virtual float			ComputePixelDiameterOfSphere(const Vector& abs_origin, float radius) = 0;
	virtual void			EnableUserClipTransformOverride(bool enable) = 0;
	virtual void			UserClipTransform(const VMatrix& world_to_view) = 0;
	virtual bool			GetFlashlightMode() const = 0;
	virtual void			ResetOcclusionQueryObject(void* unk) = 0;
	virtual void*			CreateMorph(unsigned int format, char const* debug_name) = 0;
	virtual void			DestroyMorph(void* morph) = 0;
	virtual void			BindMorpth(void* morph) = 0;
	virtual void			SetFlexWeights(int first_weight, int count, const void* weights) = 0;
	virtual void*			LockRenderData(int unk) = 0;
	virtual void			UnlockRenderData(void* unk) = 0;
	virtual void			AddRefRenderData() = 0;
	virtual void			ReleaseRenderData() = 0;
	virtual bool			IsRenderData(void* const* unk) const = 0;
	virtual void			ReadPixelsAndStretch(void* src, void* dst, unsigned char* buff, int dst_format, int dst_stride) = 0;
	virtual void			GetWindowSize(int& width, int& height) const = 0;
	virtual void			DrawScreenSpaceRectangle(IMaterial* mat, int destx, int desty, int width, int height, float src_texture_x0, float src_texture_y0, float src_texture_x1, float src_texture_y1, int src_texture_width, int src_texture_height, void* client_renderable = NULL, int nXDice = 1, int nYDice = 1) = 0;
	virtual void			LoadBoneMatrix(int bone_index, const matrix3x4_t& matrix) = 0;
	virtual void			PushRenderTargetAndViewport() = 0;
	virtual void			PushRenderTargetAndViewport(void* text) = 0;
	virtual void			PushRenderTargetAndViewport(void* text, int view_x, int view_y, int view_w, int view_h) = 0;
	virtual void			PushRenderTargetAndViewport(void* text, void* depth_texture, int view_x, int view_y, int view_w, int view_h) = 0;
	virtual void			PopRenderTargetAndViewport() = 0;
	virtual void			BindLightmapTexture(void* lightmap_texture) = 0;
	virtual void			CopyRenderTargetToTextureEx(void* text, int render_target_id, void* src, void* dst = NULL) = 0;
	virtual void			CopyTextureToRenderTargetEx(int render_target_id, void* text, void* src, void* dst = NULL) = 0;
	virtual void			PerspectiveOffCenterX(double fovx, double aspect, double zNear, double zFar, double bot, double top, double left, double right) = 0;
	virtual void			SetFloatRenderingParameter(int parm_number, float value) = 0;
	virtual void			SetIntRenderinParameter(int parm_number, int value) = 0;
	virtual void			SetVectorReneringParameter(int parm_number, Vector const& value) = 0;
	virtual void			SetStencilState(ShaderStencilState_t const& unk) = 0;
	virtual void			ClearStencilBufferRectangle(int xmin, int ymin, int xmax, int ymax, int value) = 0;
	virtual void			SetRenderTargetEx(int render_target_id, void* text) = 0;
	virtual void			PushCustomClipPlane(const float* plane) = 0;
	virtual void			PopCustomClipPlane(void) = 0;
	virtual void			GetMaxToRender(void* mesh, bool max_until_flush, int* max_verts, int* max_indices) = 0;
	virtual int				GetMaxVerticesToRender(IMaterial* mat) = 0;
	virtual int				GetMaxIndicesToRender() = 0;
	virtual void			DisableAllLocalLights() = 0;
	virtual int				CompareMaterialCombos(IMaterial* mat1, IMaterial* mat2, int light_map_id1, int light_map_id2) = 0;
	virtual void*			GetFlexMesh() = 0;
	virtual void			SetFlashlightStateEx(const void* state, const VMatrix& world_to_texture, void* depth_texture) = 0;
	virtual void*			GetLocalCubemap() = 0;
	virtual void			ClearBuffersObeyStencil(bool clear_color, bool clear_depth) = 0;
	virtual bool			EnableClipping(bool enable) = 0;
	virtual void			GetFogDistances(float* start, float* end, float* fog_z) = 0;
	virtual void			GetWaterFogDistances(float* unk1, float* unk2) = 0;
	virtual void			BeginPixEvent(unsigned long color, const char* name) = 0;
	virtual void			EndPixEvent() = 0;
	virtual void			SetPixMarker(unsigned long color, const char* name) = 0;
	virtual void			BeginBatch(void* indices) = 0;
	virtual void			BindBatch(void* vertices, IMaterial* auto_bind = NULL) = 0;
	virtual void			DrawBatch(int first_index, int num_indices) = 0;
	virtual void			EndBatch() = 0;
	virtual void*			GetCallQueue() = 0;
	virtual void			GetWorldSpaceCameraPosition(Vector* camera_pos) = 0;
	virtual void			GetWorldSpaceCameraVectors(Vector* forward, Vector* right, Vector* up) = 0;
	virtual void			SetToneMappingScaleLinear(const Vector& scale) = 0;
	virtual Vector			GetToneMappingScaleLinear() = 0;
	virtual void			SetShadowDepthBiasFactors(float slope_scale_depth_bias, float depth_bias) = 0;
	virtual void			PerformFullscreenStencilOperation() = 0;
	virtual void			SetLightingOrigin(Vector lighting_origin) = 0;
	virtual void			SetScissorRect(const int left, const int top, const int right, const int bottom, const bool enable_scissor) = 0;
	virtual void			BeginMorphAccumulation() = 0;
	virtual void			EndMorpthAccumulation() = 0;
	virtual void			AccumulateMorph(void* morph, int morph_count, const void* weights) = 0;
	virtual void			PushDeformation(void const* deformation) = 0;
	virtual void			PopDeformation() = 0;
	virtual int				GetNumActiveDeformations() const = 0;
	virtual bool			GetMorphAccumulatorTextCoord(Vector2D* tex_coord, void* morph, int vertex) = 0;
	virtual void*			GetDynamicMeshEx(int vertex_format, bool buffered = true, void* vertex_override = 0, void* index_override = 0, IMaterial* auto_bind = 0) = 0;
	virtual void			FogMaxDensity(float max_density) = 0;
	virtual IMaterial*		GetCurrentMaterial() = 0;
	virtual int				GetCurrentNumBones() const = 0;
	virtual void*			GetCurrentProxy() = 0;
	virtual void			EnableColorCorrection(bool enable) = 0;
	virtual void*			AddLookup(char const* name) = 0;
	virtual bool			RemoveLookup(void* handle) = 0;
	virtual void			LocalLookup(void* handle) = 0;
	virtual void			LoadLookup(void* handle, const char* lookup_name) = 0;
	virtual void			UnlockLookup(void* handle) = 0;
	virtual void			SetLookupWeight(void* handle, float flWeight) = 0;
	virtual void			ResetLookupWeights() = 0;
	virtual void			SetResetable(void* handle, bool resetable) = 0;
	virtual void			SetFullscreenDepthTextureValidityFlag(bool is_valid) = 0;
	virtual void			SetNonInteractivePacifierTexture(void* text, float normalized_x, float normalized_y, float normalized_size) = 0;
	virtual void			SetNonInteractiveTempFullscreenBuffer(void* text, int mode) = 0;
	virtual void			EnableNonInteractiveMode(int mode) = 0;
	virtual void			FlipCulling(bool unk) = 0;
	virtual void			SetTextureRenderingParameter(int unk1, void* text) = 0;
	virtual void			EnableSinglePassFlaslightMode(bool unk) = 0;
	virtual void			DrawInstances(int unk1, void const* unk2) = 0;
	virtual void			OverrideAlphaWriteEnable(bool unk1, bool unk2) = 0;
	virtual void			OverrideColorWriteEnable(bool unk1, bool unk2) = 0;
	virtual void			ClearBuffersObeyStencilStateEx(bool unk1, bool unk2, bool unk3) = 0;
};