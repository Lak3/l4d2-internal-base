#pragma once

#include "../../SDK/SDK.h"

namespace Hooks
{
	namespace SequenceTransitioner
	{
		namespace CheckForSequenceChange
		{
			inline Hook::CFunction Func;
			using FN = void(__fastcall*)(void*, void*, CStudioHdr*, int, bool, bool);

			void __fastcall Detour(void* ecx, void* edx, CStudioHdr* hdr, int nCurSequence, bool bForceNewSequence, bool bInterpolate);
		}

		void Init();
	}
}