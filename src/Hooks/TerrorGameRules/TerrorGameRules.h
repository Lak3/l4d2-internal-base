#pragma once

#include "../../SDK/SDK.h"

namespace Hooks
{
	namespace TerrorGameRules
	{
		namespace GetSurvivorSet
		{
			inline Hook::CFunction Func;
			using FN = int(__fastcall*)(void*, void*);

			int __fastcall Detour(void* ecx, void* edx);
		}

		void Init();
	}
}