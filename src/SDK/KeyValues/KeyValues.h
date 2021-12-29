#pragma once

#include "../L4D2/Entities/C_Infected.h"

class CGlobal_KeyValues
{
public:
	bool LoadFromBuffer(KeyValues* pKval, const char* const szName, const char* const szBuff, void* pSys = nullptr, const char* const szPath = nullptr);
	KeyValues* Init(KeyValues* pKval, const char* const szName);
};

namespace G { inline CGlobal_KeyValues KeyVals; }