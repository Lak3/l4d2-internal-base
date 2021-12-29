#pragma once

#include "DebugOverlay.h"

#ifdef CopyFile
#undef CopyFile
#endif

class IMaterial;
class CPhysCollide;
class client_textmessage_t;
class IAchievementMgr;
class ISpatialQuery;
class IMaterialSystem;
class INetChannelInfo;
class SurfInfo;
class CAudioSource;
class CGamestatsData;
class CSentence;
class CSteamAPIContext;

struct player_info_t {
private:
	char __pad00[0x8];

public:
	char name[32];
	int  userid;

private:
	char __pad01[0x150];
};

struct color32 {
	int r, g, b, a;
};

class IVEngineClient
{
public:
	virtual int						GetIntersectingSurfaces(const void* model, const Vector& vCenter, const float radius, const bool bOnlyVisibleSurfaces, SurfInfo* pInfos, const int nMaxInfos) = 0;
	virtual Vector					GetLightForPoint(const Vector& pos, bool bClamp) = 0;
	virtual IMaterial*				TraceLineMaterialAndLighting(const Vector& start, const Vector& end, Vector& diffuseLightColor, Vector& baseColor) = 0;
	virtual const char*				ParseFile(const char* data, char* token, int maxlen) = 0;
	virtual bool					CopyLocalFile(const char* source, const char* destination) = 0;
	virtual void					GetScreenSize(int& width, int& height) = 0;
	virtual void					ServerCmd(const char* szCmdString, bool bReliable = true) = 0;
	virtual void					ClientCmd(const char* szCmdString) = 0;
	virtual bool					GetPlayerInfo(int ent_num, player_info_t* pinfo) = 0;
	virtual int						GetPlayerForUserID(int userID) = 0;
	virtual client_textmessage_t*	TextMessageGet(const char* pName) = 0;
	virtual bool					Con_IsVisible(void) = 0;
	virtual int						GetLocalPlayer(void) = 0;
	virtual const void*				LoadModel(const char* pName, bool bProp = false) = 0;
	virtual float					OBSOLETE_Time(void) = 0;
	virtual float					GetLastTimeStamp(void) = 0;
	virtual CSentence*				GetSentence(CAudioSource* pAudioSource) = 0;
	virtual float					GetSentenceLength(CAudioSource* pAudioSource) = 0;
	virtual bool					IsStreaming(CAudioSource* pAudioSource) const = 0;
	virtual void					GetViewAngles(Vector& va) = 0;
	virtual void					SetViewAngles(Vector& va) = 0;
	virtual int						GetMaxClients(void) = 0;
	virtual	const char*				Key_LookupBinding(const char* pBinding) = 0;
	virtual const char*				Key_BindingForKey(int& code) = 0; //ButtonCode_t&
	virtual void					StartKeyTrapMode(void) = 0;
	virtual bool					CheckDoneKeyTrapping(int& code) = 0; //ButtonCode_t&
	virtual bool					IsInGame(void) = 0;
	virtual bool					IsConnected(void) = 0;
	virtual bool					IsDrawingLoadingImage(void) = 0;
	virtual void					HideLoadingPlaque() = 0;
	virtual void					Con_NPrintf(int pos, const char* fmt, ...) = 0;
	virtual void					Con_NXPrintf(const struct con_nprint_s* info, const char* fmt, ...) = 0;
	virtual int						IsBoxVisible(const Vector& mins, const Vector& maxs) = 0;
	virtual int						IsBoxInViewCluster(const Vector& mins, const Vector& maxs) = 0;
	virtual bool					CullBox(const Vector& mins, const Vector& maxs) = 0;
	virtual void					Sound_ExtraUpdate(void) = 0;
	virtual const char*				GetGameDirectory(void) = 0;
	virtual const VMatrix&			WorldToScreenMatrix() = 0;
	virtual const VMatrix&			WorldToViewMatrix() = 0;
	virtual int						GameLumpVersion(int lumpId) const = 0;
	virtual int						GameLumpSize(int lumpId) const = 0;
	virtual bool					LoadGameLump(int lumpId, void* pBuffer, int size) = 0;
	virtual int						LevelLeafCount() const = 0;
	virtual ISpatialQuery*			GetBSPTreeQuery() = 0;
	virtual void					LinearToGamma(float* linear, float* gamma) = 0;
	virtual float					LightStyleValue(int style) = 0;
	virtual void					ComputeDynamicLighting(const Vector& pt, const Vector* pNormal, Vector& color) = 0;
	virtual void					GetAmbientLightColor(Vector& color) = 0;
	virtual int						GetDXSupportLevel() = 0;
	virtual bool					SupportsHDR() = 0;
	virtual void					Mat_Stub(IMaterialSystem* pMatSys) = 0;
	virtual void					GetChapterName(char* pchBuff, int iMaxLength) = 0;
	virtual char const*				GetLevelName(void) = 0;
	virtual char const*				GetLevelNameShort(void) = 0;
	virtual struct IVoiceTweak_s*	GetVoiceTweakAPI(void) = 0;
	virtual void					EngineStats_BeginFrame(void) = 0;
	virtual void					EngineStats_EndFrame(void) = 0;
	virtual void					FireEvents() = 0;
	virtual int						GetLeavesArea(int* pLeaves, int nLeaves) = 0;
	virtual bool					DoesBoxTouchAreaFrustum(const Vector& mins, const Vector& maxs, int iArea) = 0;
	virtual void					GetFrustumList(void** unk1, int unk2) = 0;
	virtual void					SetAudioState(const void* state) = 0; //AudioState_t&
	virtual int						SentenceGroupPick(int groupIndex, char* name, int nameBufLen) = 0;
	virtual int						SentenceGroupPickSequential(int groupIndex, char* name, int nameBufLen, int sentenceIndex, int reset) = 0;
	virtual int						SentenceIndexFromName(const char* pSentenceName) = 0;
	virtual const char*				SentenceNameFromIndex(int sentenceIndex) = 0;
	virtual int						SentenceGroupIndexFromName(const char* pGroupName) = 0;
	virtual const char*				SentenceGroupNameFromIndex(int groupIndex) = 0;
	virtual float					SentenceLength(int sentenceIndex) = 0;
	virtual void					ComputeLighting(const Vector& pt, const Vector* pNormal, bool bClamp, Vector& color, Vector* pBoxColors = NULL) = 0;
	virtual void					ActivateOccluder(int nOccluderIndex, bool bActive) = 0;
	virtual bool					IsOccluded(const Vector& vecAbsMins, const Vector& vecAbsMaxs) = 0;
	virtual void*					SaveAllocMemory(size_t num, size_t size) = 0;
	virtual void					SaveFreeMemory(void* pSaveMem) = 0;
	virtual INetChannelInfo*		GetNetChannelInfo(void) = 0;
	virtual void					DebugDrawPhysCollide(const CPhysCollide* pCollide, IMaterial* pMaterial, matrix3x4_t& transform, const color32& color) = 0;
	virtual void					CheckPoint(const char* pName) = 0;
	virtual void					DrawPortals() = 0;
	virtual bool					IsPlayingDemo(void) = 0;
	virtual bool					IsRecordingDemo(void) = 0;
	virtual bool					IsPlayingTimeDemo(void) = 0;

private:
	virtual void*					GetDemoRecordingTick() = 0;
	virtual void*					GetDemoPlaybackTick() = 0;
	virtual void*					GetDemoPlaybackStartTick() = 0;
	virtual void*					GetDemoPlaybackTimeScale() = 0;
	virtual void*					GetDemoPlaybackTotalTicks() = 0;

public:
	virtual bool					IsPaused(void) = 0;
	virtual float					GetTimescale(void) const = 0;
	virtual bool					IsTakingScreenshot(void) = 0;
	virtual bool					IsHLTV(void) = 0;
	virtual bool					IsLevelMainMenuBackground(void) = 0;
	virtual void					GetMainMenuBackgroundName(char* dest, int destlen) = 0;
	virtual void					SetOcclusionParameters(const void* params) = 0; //OcclusionParams_t&
	virtual void					GetUILanguage(char* dest, int destlen) = 0;
	virtual int						IsSkyboxVisibleFromPoint(const Vector& vecPoint) = 0; //SkyboxVisibility_t
	virtual const char*				GetMapEntitiesString() = 0;
	virtual bool					IsInEditMode(void) = 0;
	virtual float					GetScreenAspectRatio() = 0;
	virtual unsigned int			GetEngineBuildNumber() = 0;
	virtual const char*				GetProductVersionString() = 0;
	virtual void					GrabPreColorCorrectedFrame(int x, int y, int width, int height) = 0;
	virtual bool					IsHammerRunning() const = 0;
	virtual void					ExecuteClientCmd(const char* szCmdString) = 0;
	virtual bool					MapHasHDRLighting(void) = 0;
	virtual int						GetAppID() = 0;
	virtual Vector					GetLightForPointFast(const Vector& pos, bool bClamp) = 0;
	virtual void					ClientCmd_Unrestricted(const char* szCmdString) = 0;
	virtual void					SetRestrictServerCommands(bool bRestrict) = 0;
	virtual void					SetRestrictClientCommands(bool bRestrict) = 0;
	virtual void					SetOverlayBindProxy(int iOverlayID, void* pBindProxy) = 0;
	virtual bool					CopyFrameBufferToMaterial(const char* pMaterialName) = 0;
	virtual void					ReadConfiguration(int unk1, const bool readDefault = false) = 0;
	virtual void					SetAchievementMgr(IAchievementMgr* pAchievementMgr) = 0;
	virtual IAchievementMgr*		GetAchievementMgr() = 0;
	virtual bool					MapLoadFailed(void) = 0;
	virtual void					SetMapLoadFailed(bool bState) = 0;
	virtual bool					IsLowViolence() = 0;
	virtual const char*				GetMostRecentSaveGame(void) = 0;
	virtual void					SetMostRecentSaveGame(const char* lpszFilename) = 0;
	virtual void					StartXboxExitingProcess() = 0;
	virtual bool					IsSaveInProgress() = 0;
	virtual unsigned int			OnStorageDeviceAttached(void) = 0;
	virtual void					OnStorageDeviceDetached(void) = 0;
	virtual void					WriteScreenshot(const char* pFilename) = 0;
	virtual void					ResetDemoInterpolation(void) = 0;
	virtual int						GetActiveSplitScreenPlayerSlot() = 0;
	virtual int						SetActiveSplitScreenPlayerSlot(int slot) = 0;
	virtual bool					SetLocalPlayerIsResolvable(char const* pchContext, int nLine, bool bResolvable) = 0;
	virtual bool					IsLocalPlayerResolvable() = 0;
	virtual int						GetSplitScreenPlayer(int nSlot) = 0;
	virtual bool					IsSplitScreenActive() = 0;
	virtual bool					IsValidSplitScreenSlot(int nSlot) = 0;
	virtual int						FirstValidSplitScreenSlot() = 0; // -1 == invalid
	virtual int						NextValidSplitScreenSlot(int nPreviousSlot) = 0; // -1 == invalid
	virtual void*					GetSinglePlayerSharedMemorySpace(const char* szName, int ent_num = 0) = 0;

private:
	virtual void					ComputeLightingCube(const Vector& pt, bool bClamp, Vector* pBoxColors) = 0;
	virtual void					RegisterDemoCustomDataCallback(void* szCallbackSaveID, void* pCallback) = 0;
	virtual void					RecordDemoCustomData(void* pCallback, const void* pData, size_t iDataLength) = 0;

public:
	virtual void					SetPitchScale(float unk1) = 0;
	virtual float					GetPitchScale(void) = 0;
	virtual void					SetLeafFlag(int nLeafIndex, int nFlagBits) = 0;
	virtual void					RecalculateBSPLeafFlags(void) = 0;
	virtual bool					DSPGetCurrentDASRoomNew(void) = 0;
	virtual bool					DSPGetCurrentDASRoomChanged(void) = 0;
	virtual bool					DSPGetCurrentDASRoomSkyAbove(void) = 0;
	virtual float					DSPGetCurrentDASRoomSkyPercent(void) = 0;
	virtual void					SetMixGroupOfCurrentMixer(const char* szgroupname, const char* szparam, float val, int setMixerType) = 0;
	virtual int						GetMixLayerIndex(const char* szmixlayername) = 0;
	virtual void					SetMixLayerLevel(int index, float level) = 0;
	virtual bool					IsCreatingReslist() = 0;
	virtual bool					IsCreatingXboxReslist() = 0;
	virtual void					SetTimescale(float unk1) = 0;
	virtual void					SetGamestatsData(CGamestatsData* pGamestatsData) = 0;
	virtual CGamestatsData*			GetGamestatsData() = 0;
	virtual	const char*				Key_LookupBindingEx(const char* pBinding, int iUserId = -1, int iStartCount = 0, int nFlags = 0) = 0; //BindingLookupOption_t
	virtual void					UpdateDAndELights(void) = 0;
	virtual int						GetBugSubmissionCount() const = 0;
	virtual void					ClearBugSubmissionCount() = 0;
	virtual bool					DoesLevelContainWater() const = 0;
	virtual float					GetServerSimulationFrameTime() const = 0;
	virtual void					SolidMoved(class IClientEntity* pSolidEnt, class ICollideable* pSolidCollide, const Vector* pPrevAbsOrigin, bool accurateBboxTriggerChecks) = 0;
	virtual void					TriggerMoved(class IClientEntity* pTriggerEnt, bool accurateBboxTriggerChecks) = 0;
	virtual void					ComputeLeavesConnected(const Vector& vecOrigin, int nCount, const int* pLeafIndices, bool* pIsConnected) = 0;
	virtual bool					IsInCommentaryMode(void) = 0;
	virtual void					SetBlurFade(float amount) = 0;
	virtual bool					IsTransitioningToLoad() = 0;
	virtual void					SearchPathsChangedAfterInstall() = 0;
	virtual void					ConfigureSystemLevel(int nCPULevel, int nGPULevel) = 0;
	virtual void					SetConnectionPassword(char const* pchCurrentPW) = 0;
	virtual CSteamAPIContext*		GetSteamAPIContext() = 0;
	virtual void					SubmitStatRecord(char const* szMapName, unsigned __int32 uiBlobVersion, unsigned __int32 uiBlobSize, const void* pvBlob) = 0;
	virtual void					ServerCmdKeyValues(void* pKeyValues) = 0;
};

namespace I { inline IVEngineClient* EngineClient = nullptr; }