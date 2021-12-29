#pragma once

#include "../../SDK/SDK.h"

namespace Hooks
{
	namespace BasePlayer
	{
		namespace CalcPlayerView
		{
			inline Hook::CFunction Func;
			using FN = void(__fastcall*)(C_BasePlayer*, void*, Vector&, Vector&, float&);

			void __fastcall Detour(C_BasePlayer* pThis, void* edx, Vector& eyeOrigin, Vector& eyeAngles, float& fov);
		}

		void Init();
	}
}