#include "TerrorPlayer.h"

#include "../../Features/Vars.h"

using namespace Hooks;

void __fastcall TerrorPlayer::AvoidPlayers::Detour(C_TerrorPlayer* pThis, void* edx, CUserCmd* pCmd)
{
	Func.Original<FN>()(pThis, edx, pCmd);
}

void TerrorPlayer::Init()
{
	//AvoidPlayers
	{
		using namespace AvoidPlayers;

		const FN pfAvoidPlayers = reinterpret_cast<FN>(U::Offsets.m_dwAvoidPlayers);
		XASSERT(pfAvoidPlayers == nullptr);

		if (pfAvoidPlayers)
			XASSERT(Func.Init(pfAvoidPlayers, &Detour) == false);
	}
}