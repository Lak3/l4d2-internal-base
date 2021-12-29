#include "ClientMode.h"

#include "../../Features/Vars.h"
#include "../../Features/EnginePrediction/EnginePrediction.h"
#include "../../Features/NoSpread/NoSpread.h"

using namespace Hooks;

bool __fastcall ClientMode::ShouldDrawFog::Detour(void* ecx, void* edx)
{
	return Table.Original<FN>(Index)(ecx, edx);
}

bool __fastcall ClientMode::CreateMove::Detour(void* ecx, void* edx, float input_sample_frametime, CUserCmd* cmd)
{
	if (!cmd || !cmd->command_number)
		return Table.Original<FN>(Index)(ecx, edx, input_sample_frametime, cmd);

	if (Table.Original<FN>(Index)(ecx, edx, input_sample_frametime, cmd))
		I::Prediction->SetLocalViewAngles(cmd->viewangles);

	//uintptr_t _ebp; __asm mov _ebp, ebp;
	//bool* pSendPacket = (bool*)(***(uintptr_t***)_ebp - 0x1D);

	C_TerrorPlayer* pLocal = I::ClientEntityList->GetClientEntity(I::EngineClient->GetLocalPlayer())->As<C_TerrorPlayer*>();

	if (pLocal && !pLocal->deadflag())
	{
		C_TerrorWeapon* pWeapon = pLocal->GetActiveWeapon()->As<C_TerrorWeapon*>();

		if (pWeapon)
		{
			F::EnginePrediction.Start(pLocal, cmd);
			{
				F::NoSpread.Run(pLocal, pWeapon, cmd);
			}
			F::EnginePrediction.Finish(pLocal, cmd);
		}
	}

	return false;
}

void __fastcall ClientMode::DoPostScreenSpaceEffects::Detour(void* ecx, void* edx, const void* pSetup)
{
	Table.Original<FN>(Index)(ecx, edx, pSetup);
}

float __fastcall ClientMode::GetViewModelFOV::Detour(void* ecx, void* edx)
{
	return Table.Original<FN>(Index)(ecx, edx);
}

void ClientMode::Init()
{
	XASSERT(Table.Init(I::ClientMode) == false);
	XASSERT(Table.Hook(&ShouldDrawFog::Detour, ShouldDrawFog::Index) == false);
	XASSERT(Table.Hook(&CreateMove::Detour, CreateMove::Index) == false);
	XASSERT(Table.Hook(&DoPostScreenSpaceEffects::Detour, DoPostScreenSpaceEffects::Index) == false);
	XASSERT(Table.Hook(&GetViewModelFOV::Detour, GetViewModelFOV::Index) == false);
}