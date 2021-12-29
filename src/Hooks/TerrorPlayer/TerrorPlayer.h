#pragma once

#include "../../SDK/SDK.h"

namespace Hooks
{
	namespace TerrorPlayer
	{
		namespace AvoidPlayers
		{
			inline Hook::CFunction Func;
			using FN = void(__fastcall*)(C_TerrorPlayer*, void*, CUserCmd*);

			void __fastcall Detour(C_TerrorPlayer* pThis, void* edx, CUserCmd* pCmd);
		}

		void Init();
	}
}