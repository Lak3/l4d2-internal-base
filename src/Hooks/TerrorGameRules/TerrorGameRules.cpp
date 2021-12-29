#include "TerrorGameRules.h"

using namespace Hooks;

//This can be used to determine which set of survivors is currently in use (l4d1 or l4d2)
//SURVIVORSET_L4D1 == 1 (defined in const.h)
int __fastcall TerrorGameRules::GetSurvivorSet::Detour(void* ecx, void* edx)
{
	return Func.Original<FN>()(ecx, edx);
}

void TerrorGameRules::Init()
{
	//FastGetSurvivorSet
	{
		using namespace GetSurvivorSet;

		const FN pfGetSurvivorSet = reinterpret_cast<FN>(U::Offsets.m_dwGetSurvivorSet);
		XASSERT(pfGetSurvivorSet == nullptr);

		if (pfGetSurvivorSet)
			XASSERT(Func.Init(pfGetSurvivorSet, &Detour) == false);
	}
}