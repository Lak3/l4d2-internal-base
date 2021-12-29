#pragma once

#include "BaseClientDLL.h"

class IClientNetworkable;
class IClientUnknown;
class IClientEntity;

//From CS:GO, not checked if same on L4D2
struct EntityCacheInfo_t {
	IClientNetworkable* m_pNetworkable;
	unsigned short m_BaseEntitiesIndex;
	unsigned short m_bDormant;
};

class IClientEntityList
{
public:
	virtual IClientNetworkable*		GetClientNetworkable(int entnum) = 0;
	virtual IClientNetworkable*		GetClientNetworkableFromHandle(CBaseHandle hEnt) = 0;
	virtual IClientUnknown*			GetClientUnknownFromHandle(CBaseHandle hEnt) = 0;
	virtual IClientEntity*			GetClientEntity(int entnum) = 0;
	virtual IClientEntity*			GetClientEntityFromHandle(CBaseHandle hEnt) = 0;
	virtual int						NumberOfEntities(bool bIncludeNonNetworkable) = 0;
	virtual int						GetHighestEntityIndex(void) = 0;
	virtual void					SetMaxEntities(int maxents) = 0;
	virtual int						GetMaxEntities() = 0;
	virtual EntityCacheInfo_t*		GetClientNetworkableArray() = 0;
};

namespace I { inline IClientEntityList* ClientEntityList = nullptr; }