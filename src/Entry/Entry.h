#pragma once

#include "../Hooks/Hooks.h"

class CGlobal_ModuleEntry
{
public:
	void Load();
};

namespace G { inline CGlobal_ModuleEntry ModuleEntry; }