#pragma once

#include "../Includes/ehandle.h"

class IBaseClientDLL
{
public:
	virtual int				Connect(void* appSystemFactory, CGlobalVarsBase* pGlobals) = 0;
	virtual int				Init(void* appSystemFactory, CGlobalVarsBase* pGlobals) = 0;
	virtual void			PostInit() = 0;
	virtual void			Shutdown(void) = 0;
	virtual void			LevelInitPreEntity(char const* pMapName) = 0;
	virtual void			LevelInitPostEntity() = 0;
	virtual void			LevelShutdown(void) = 0;
	virtual ClientClass*	GetAllClasses(void) = 0;
	virtual int				HudVidInit(void) = 0;
	virtual void			HudProcessInput(bool bActive) = 0;
	virtual void			HudUpdate(bool bActive) = 0;
	virtual void			HudReset(void) = 0;
	virtual void			HudText(const char* message) = 0;
	virtual bool			ShouldDrawDropdownConsole() = 0;
	virtual void			IN_ActivateMouse(void) = 0;
	virtual void			IN_DeactivateMouse(void) = 0;
	virtual void			IN_Accumulate(void) = 0;
	virtual void			IN_ClearStates(void) = 0;
	virtual bool			IN_IsKeyDown(const char* name, bool& isdown) = 0;
	virtual int				IN_KeyEvent(int eventcode, int keynum, const char* pszCurrentBinding) = 0;
	virtual void			CreateMove(int sequence_number, float input_sample_frametime, bool active) = 0;
	virtual void			ExtraMouseSample(float frametime, bool active) = 0;
	virtual bool			WriteUsercmdDeltaToBuffer(int nSlot, void* buf, int from, int to, bool isnewcommand) = 0;
	virtual void			EncodeUserCmdToBuffer(int nSlot, void* buf, int slot) = 0;
	virtual void			DecodeUserCmdFromBuffer(int nSlot, void* buf, int slot) = 0;
	virtual void			View_Render(void* rect) = 0;
	virtual void			RenderView(const void* view, int nClearFlags, int whatToDraw) = 0;
	virtual void			View_Fade(void* pSF) = 0;
	virtual void			SetCrosshairAngle(const Vector& angle) = 0;
	virtual void			InitSprite(void* pSprite, const char* loadname) = 0;
	virtual void			ShutdownSprite(void* pSprite) = 0;
	virtual int				GetSpriteSize(void) const = 0;
	virtual void			VoiceStatus(int entindex, int iSsSlot, int bTalking) = 0;
	virtual void			InstallStringTableCallback(char const* tableName) = 0;
	virtual void			FrameStageNotify(int curStage) = 0;
	virtual bool			DispatchUserMessage(int msg_type, __int32 nFlags, int size, const void* msg) = 0;
	virtual void*			SaveInit(int size) = 0;
	virtual void			SaveWriteFields(void*, const char*, void*, void*, void*, int) = 0;
	virtual void			SaveReadFields(void*, const char*, void*, void*, void*, int) = 0;
	virtual void			PreSave(void*) = 0;
	virtual void			Save(void*) = 0;
	virtual void			WriteSaveHeaders(void*) = 0;
	virtual void			ReadRestoreHeaders(void*) = 0;
	virtual void			Restore(void*, bool) = 0;
	virtual void			DispatchOnRestore() = 0;
	virtual void*			GetStandardRecvProxies() = 0;
	virtual void			WriteSaveGameScreenshot(const char* pFilename) = 0;
	virtual void			EmitSentenceCloseCaption(char const* tokenstream) = 0;
	virtual void			EmitCloseCaption(char const* captionname, float duration) = 0;
	virtual bool			CanRecordDemo(char* errorMsg, int length) const = 0;
	virtual void			OnDemoRecordStart(char const* pDemoBaseName) = 0;
	virtual void			OnDemoRecordStop() = 0;
	virtual void			OnDemoPlaybackStart(char const* pDemoBaseName) = 0;
	virtual void			OnDemoPlaybackStop() = 0;
	virtual void			RecordDemoPolishUserInput(int nCmdIndex) = 0;
	virtual bool			CacheReplayRagdolls(const char* pFilename, int nStartTick) = 0;
	virtual void			ReplayUI_SendMessage(void* pMsg) = 0;
	virtual void*			GetReplayFactory() = 0;
	virtual void			ClearLocalPlayerReplayPtr() = 0;
	virtual int				GetScreenWidth() = 0;
	virtual int				GetScreenHeight() = 0;
	virtual void			WriteSaveGameScreenshotOfSize(const char* pFilename, int width, int height, bool bCreatePowerOf2Padded = false, bool bWriteVTF = false) = 0;
	virtual void			WriteReplayScreenshot(void* params) = 0;
	virtual void			UpdateReplayScreenshotCache() = 0;
	virtual bool			GetPlayerView(void* playerView) = 0;
	virtual void            UpdateProgressBar(float unk1, const char* unk2) = 0;
	virtual bool			ShouldHideLoadingPlaque(void) = 0;
};

namespace I { inline IBaseClientDLL* BaseClient = nullptr; }