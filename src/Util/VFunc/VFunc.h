#pragma once

#include "../Offsets/Offsets.h"

class CUtil_VFunc
{
public:
	template<typename T>
	inline T Get(const void* inst, const unsigned int index, const unsigned int offset = 0u) {
		return reinterpret_cast<T>(GetTable(inst, offset)[index]);
	}

private:
	void**& GetTable(void* inst, const unsigned int offset = 0u);
	const void** GetTable(const void* inst, const unsigned int offset = 0u);
};

namespace U { inline CUtil_VFunc VFunc; }