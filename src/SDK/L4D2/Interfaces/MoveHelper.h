#pragma once

#include "ModelRender.h"

class IMoveHelper
{
public:
	virtual	char const*		GetName(void* handle) const = 0;
	virtual void			SetHost(C_BaseEntity* unk1) = 0;
	virtual void			ResetTouchList(void) = 0;
	virtual bool			AddToTouched(const void* tr, const Vector& impactvelocity) = 0;
	virtual void			SetGroundNormal(const Vector& unk1) = 0;
	virtual void			ProcessImpacts(void) = 0;
	virtual void			Con_NPrintf(int idx, char const* fmt, ...) = 0;
	virtual void			StartSound(const Vector& origin, int channel, char const* sample, float volume, int soundlevel, int fFlags, int pitch) = 0;
	virtual void			StartSound(const Vector& origin, const char* soundname) = 0;
	virtual void			PlaybackEventFull(int flags, int clientindex, unsigned short eventindex, float delay, Vector& origin, Vector& angles, float fparam1, float fparam2, int iparam1, int iparam2, int bparam1, int bparam2) = 0;
	virtual bool			PlayerFallingDamage(void) = 0;
	virtual void			PlayerSetAnimation(int playerAnim) = 0;
	virtual void*			GetSurfaceProps(void) = 0;
	virtual bool			IsWorldEntity(const unsigned int handle) = 0;

protected:
	virtual					~IMoveHelper() = 0;
};

namespace I { inline IMoveHelper* MoveHelper = nullptr; }