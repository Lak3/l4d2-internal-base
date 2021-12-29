#pragma once

#include "../../SDK/SDK.h"

namespace Hooks
{
	namespace BaseClient
	{
		inline Hook::CTable Table;

		namespace LevelInitPreEntity
		{
			using FN = void(__fastcall*)(void*, void*, char const*);
			constexpr uint32_t Index = 4u;

			void __fastcall Detour(void* ecx, void* edx, char const* pMapName);
		}

		namespace LevelInitPostEntity
		{
			using FN = void(__fastcall*)(void*, void*);
			constexpr uint32_t Index = 5u;

			void __fastcall Detour(void* ecx, void* edx);
		}

		namespace LevelShutdown
		{
			using FN = void(__fastcall*)(void*, void*);
			constexpr uint32_t Index = 6u;

			void __fastcall Detour(void* ecx, void* edx);
		}

		namespace FrameStageNotify
		{
			using FN = void(__fastcall*)(void*, void*, ClientFrameStage_t);
			constexpr uint32_t Index = 34u;

			void __fastcall Detour(void* ecx, void* edx, ClientFrameStage_t curStage);
		}
		
		void Init();
	}
}