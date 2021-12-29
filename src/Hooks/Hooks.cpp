#include "Hooks.h"

using namespace Hooks;

void CGlobal_Hooks::Init()
{
	const MH_STATUS MH_INIT_STATUS = MH_Initialize();
	XASSERT(MH_INIT_STATUS != MH_STATUS::MH_OK);

	if (MH_INIT_STATUS == MH_STATUS::MH_OK)
	{
		BaseClient::Init();
		BasePlayer::Init();
		CL_Main::Init();
		ClientMode::Init();
		ClientPrediction::Init();
		EngineVGui::Init();
		ModelRender::Init();
		ModelRenderSystem::Init();
		SequenceTransitioner::Init();
		TerrorGameRules::Init();
		TerrorPlayer::Init();
		WndProc::Init();
	}

	XASSERT(MH_EnableHook(MH_ALL_HOOKS) != MH_STATUS::MH_OK);
}