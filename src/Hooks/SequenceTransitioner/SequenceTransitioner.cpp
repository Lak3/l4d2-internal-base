#include "SequenceTransitioner.h"

#include "../../Features/Vars.h"

using namespace Hooks;

void __fastcall SequenceTransitioner::CheckForSequenceChange::Detour(void* ecx, void* edx, CStudioHdr* hdr, int nCurSequence, bool bForceNewSequence, bool bInterpolate)
{
	Func.Original<FN>()(ecx, edx, hdr, nCurSequence, bForceNewSequence, bInterpolate);
}

void SequenceTransitioner::Init()
{
	//CheckForSequenceChange
	{
		using namespace CheckForSequenceChange;

		const FN pfCheckForSequenceChange = reinterpret_cast<FN>(U::Offsets.m_dwCheckForSequenceChange);
		XASSERT(pfCheckForSequenceChange == nullptr);

		if (pfCheckForSequenceChange)
			XASSERT(Func.Init(pfCheckForSequenceChange, &Detour) == false);
	}
}