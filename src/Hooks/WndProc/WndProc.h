#pragma once

#include "../../SDK/SDK.h"

namespace Hooks
{
	namespace WndProc
	{
		inline WNDPROC oWndProc = nullptr;
		inline HWND    hwGame = nullptr;

		LRESULT CALLBACK Detour(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

		void Init();
	}
}