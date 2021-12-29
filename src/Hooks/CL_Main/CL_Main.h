#pragma once

#include "../../SDK/SDK.h"

namespace Hooks
{
	namespace CL_Main
	{
		namespace CL_Move
		{
			inline Hook::CFunction Func;
			using FN = void(__cdecl*)(float, bool);

			void __cdecl Detour(float accumulated_extra_samples, bool bFinalTick);
		}

		void Init();
	}
}