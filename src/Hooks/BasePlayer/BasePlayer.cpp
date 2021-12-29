#include "BasePlayer.h"

#include "../../Features/Vars.h"

using namespace Hooks;

void __fastcall BasePlayer::CalcPlayerView::Detour(C_BasePlayer* pThis, void* edx, Vector& eyeOrigin, Vector& eyeAngles, float& fov)
{
	if (pThis && !pThis->deadflag()) //Thanks Spook for telling me to do it here.
	{
		const Vector vOldPunch = pThis->GetPunchAngle();

		pThis->m_vecPunchAngle().Init();
		Func.Original<FN>()(pThis, edx, eyeOrigin, eyeAngles, fov);
		pThis->m_vecPunchAngle() = vOldPunch;
	}
	else
	{
		Func.Original<FN>()(pThis, edx, eyeOrigin, eyeAngles, fov);
	}
}

void BasePlayer::Init()
{
	//CalcPlayerView
	{
		using namespace CalcPlayerView;

		const FN pfCalcPlayerView = reinterpret_cast<FN>(U::Offsets.m_dwCalcPlayerView);
		XASSERT(pfCalcPlayerView == nullptr);

		if (pfCalcPlayerView)
			XASSERT(Func.Init(pfCalcPlayerView, &Detour) == false);
	}
}