#pragma once

#include "C_BasePlayer.h"

class C_BreakableProp : public C_BaseAnimating
{
public:
	virtual ~C_BreakableProp() = 0;

public:
	M_NETVAR(m_noGhostCollision, int, "CBreakableProp", "m_noGhostCollision");
	M_NETVAR(m_bClientPhysics, bool, "CBreakableProp", "m_bClientPhysics");
};

class C_DynamicProp : public C_BreakableProp
{
public:
	virtual ~C_DynamicProp() = 0;

public:
	M_NETVAR(m_bUseHitboxesForRenderBox, bool, "CDynamicProp", "m_bUseHitboxesForRenderBox");
};

class C_BaseGrenade : public C_BaseCombatCharacter
{
public:
	virtual				~C_BaseGrenade() = 0;

	virtual void		Explode(trace_t* pTrace, int bitsDamageType) = 0;
	virtual void		BounceTouch(C_BaseEntity* pOther) = 0;
	virtual void		Detonate(void) = 0;
	virtual Vector		GetBlastForce() = 0;
	virtual void		BounceSound(void) = 0;
	virtual void		Event_Killed(const CTakeDamageInfo& info) = 0;
	virtual float		GetShakeAmplitude(void) = 0;
	virtual float		GetShakeRadius(void) = 0;
	virtual float		GetDamage() = 0;
	virtual float		GetDamageRadius() = 0;
	virtual void		SetDamage(float flDamage) = 0;
	virtual void		SetDamageRadius(float flDamageRadius) = 0;

private:
	virtual void*		NetworkStateChanged_m_vecVelocity(void) = 0;
	virtual void*		NetworkStateChanged_m_vecVelocity(void* unk1) = 0;
	virtual void*		NetworkStateChanged_m_fFlags(void) = 0;
	virtual void*		NetworkStateChanged_m_fFlags(void* unk1) = 0;

public:
	M_NETVAR(m_flDamage, float, "CBaseGrenade", "m_flDamage");
	M_NETVAR(m_DmgRadius, float, "CBaseGrenade", "m_DmgRadius");
	M_NETVAR(m_bIsLive, bool, "CBaseGrenade", "m_bIsLive");
	M_NETVAR(m_hThrower, int, "CBaseGrenade", "m_hThrower");
	M_NETVAR(m_vecVelocity, Vector, "CBaseGrenade", "m_vecVelocity");
	M_NETVAR(m_fFlags, int, "CBaseGrenade", "m_fFlags");
};