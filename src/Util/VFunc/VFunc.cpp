#include "VFunc.h"

void**& CUtil_VFunc::GetTable(void* inst, const unsigned int offset)
{
	return *reinterpret_cast<void***>(reinterpret_cast<unsigned int>(inst) + offset);
}

const void** CUtil_VFunc::GetTable(const void* inst, const unsigned int offset)
{
	return *reinterpret_cast<const void***>(reinterpret_cast<unsigned int>(inst) + offset);
}