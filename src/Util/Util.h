#pragma once

#include "Math/Math.h"

#include <fstream>
#include <thread>
#include <vector>
#include <string>
#include <map>

inline std::wstring UTIL_GetVKeyName(const int vKey)
{
	switch (vKey)
	{
	case VK_LBUTTON:
		return L"Left Mouse";
	case VK_RBUTTON:
		return L"Right Mouse";
	case VK_MBUTTON:
		return L"Middle Mouse";
	case VK_XBUTTON1:
		return L"XButton 1";
	case VK_XBUTTON2:
		return L"XButton 2";
	case VK_DELETE:
		return L"Delete";
	case 0:
		return L"None";
	default:
		break;
	}

	wchar_t szBuff[16] = { L"\0" };

	if (GetKeyNameTextW(MapVirtualKeyW(vKey, MAPVK_VK_TO_VSC) << 16, szBuff, 16))
		return szBuff;

	return L"Unknown Key";
}