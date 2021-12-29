#pragma once

#include "../Interface/Interface.h"

class CUtil_NetVarManager
{
public:
	int Get(const char* const szClass, const char* const szVar);
};

namespace U { inline CUtil_NetVarManager NetVar; }

#define M_NETVAR(_name, type, table, name) inline type &_name() \
{ \
	static const int nOff = U::NetVar.Get(_(table), _(name)); \
	return *reinterpret_cast<type*>(reinterpret_cast<unsigned long>(this) + nOff); \
}