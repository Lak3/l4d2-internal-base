#pragma once

#include "../../SDK/SDK.h"

namespace Hooks
{
	namespace EngineVGui
	{
		inline Hook::CTable Table;

		namespace GetPanel
		{
			using FN = unsigned int(__fastcall*)(void*, void*, VGuiPanel_t);
			constexpr uint32_t Index = 1u;

			unsigned int __fastcall Detour(void* ecx, void* edx, VGuiPanel_t type);
		}

		namespace IsGameUIVisible
		{
			using FN = bool(__fastcall*)(void*, void*);
			constexpr uint32_t Index = 2u;

			bool __fastcall Detour(void* ecx, void* edx);
		}

		namespace ActivateGameUI
		{
			using FN = void(__fastcall*)(void*, void*);
			constexpr uint32_t Index = 3u;

			void __fastcall Detour(void* ecx, void* edx);
		}

		namespace Paint
		{
			using FN = void(__fastcall*)(void*, void*, int);
			constexpr uint32_t Index = 14u;

			void __fastcall Detour(void* ecx, void* edx, int mode);
		}

		void Init();
	}
}