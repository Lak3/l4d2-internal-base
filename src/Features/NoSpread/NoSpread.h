#pragma once

#include "../../SDK/SDK.h"

class CFeatures_NoSpread
{
public:
	void Run(C_TerrorPlayer* pLocal, C_TerrorWeapon* pWeapon, CUserCmd* cmd);

private:
	bool ShouldRun(C_TerrorPlayer* pLocal, C_TerrorWeapon* pWeapon, CUserCmd* cmd);
};

namespace F { inline CFeatures_NoSpread NoSpread; }