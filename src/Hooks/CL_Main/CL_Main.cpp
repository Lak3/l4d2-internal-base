#include "CL_Main.h"

#include "../../Features/Vars.h"

using namespace Hooks;

void __cdecl CL_Main::CL_Move::Detour(float accumulated_extra_samples, bool bFinalTick)
{
	Func.Original<FN>()(accumulated_extra_samples, bFinalTick);

	if (GetAsyncKeyState(VK_XBUTTON1))
	{
		for (int n = 0; n < 5; n++)
			Func.Original<FN>()(accumulated_extra_samples, bFinalTick);
	}
}

void CL_Main::Init()
{
	//CL_Move
	{
		using namespace CL_Move;

		const FN pfCLMove = reinterpret_cast<FN>(U::Offsets.m_dwCLMove);
		XASSERT(pfCLMove == nullptr);

		if (pfCLMove)
			XASSERT(Func.Init(pfCLMove, &Detour) == false);
	}
}