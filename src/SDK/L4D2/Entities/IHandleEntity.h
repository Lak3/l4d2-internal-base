#pragma once

#include "../Interfaces/MaterialSystem.h"

class CBaseHandle;

class IHandleEntity
{
public:
	virtual						~IHandleEntity() = 0;

	virtual void				SetRefEHandle(const CBaseHandle& handle) = 0;
	virtual const CBaseHandle&	GetRefEHandle() const = 0;
};