#pragma once

#include "IClientNetworkable.h"

class CMouthInfo;

class IClientEntity : public IClientUnknown, public IClientRenderable, public IClientNetworkable, public IClientThinkable
{
public:
	virtual void			Release(void) = 0;
	virtual const Vector&	GetAbsOrigin(void) const = 0;
	virtual const Vector&	GetAbsAngles(void) const = 0;
	virtual CMouthInfo*		GetMouth(void) = 0;
	virtual bool			GetSoundSpatialization(void* info) = 0;
	virtual bool			IsBlurred(void) = 0;

public:
	template<typename T>
	inline T As()
	{
		if (!this)
			return nullptr;

#ifdef _DEBUG
		return dynamic_cast<T>(this);
#else
		return static_cast<T>(this);
#endif
	}
};