#pragma once

#include "C_TerrorWeapon.h"

class C_CSPlayer : public C_BasePlayer
{
public:
	virtual				~C_CSPlayer() = 0;

	virtual bool		IsProgressBarActive() const = 0;
	virtual bool		CanShowClassMenu(void) const = 0;
	virtual float		GetRunTopSpeed(void) const = 0;
	virtual float		GetWalkTopSpeed(void) const = 0;
	virtual float		GetCrouchTopSpeed(void) const = 0;
	virtual void		UpdateCollisionBounds(void) = 0;
	virtual void		PlayJumpStartSound(void) = 0;
	virtual void		CreateSplashes(bool unk1, bool unk2, bool unk3, Vector* unk4, bool* unk5, bool* unk6) = 0;
	virtual void		ResetObserverMode(void) = 0;
	virtual void		ResetMaxSpeed(void) = 0;
	virtual void		DoAnimationEvent(int unk1, int unk2) = 0;
	virtual void		KickBack(float unk1, float unk2, float unk3, float unk4, float unk5, float unk6, int unk7) = 0;
	virtual bool		IsImmobilized(void) const = 0;
	virtual bool		CanAttack(void) const = 0;
	virtual bool		CanDeployWeapons(void) const = 0;
	virtual bool		CanUseLadders(void) const = 0;

public:
	M_NETVAR(m_flStamina, float, "CCSPlayer", "m_flStamina");
	M_NETVAR(m_iDirection, int, "CCSPlayer", "m_iDirection");
	M_NETVAR(m_iShotsFired, int, "CCSPlayer", "m_iShotsFired");
	M_NETVAR(m_flVelocityModifier, float, "CCSPlayer", "m_flVelocityModifier");
	M_NETVAR(m_duckUntilOnGround, int, "CCSPlayer", "m_duckUntilOnGround");
	M_NETVAR(m_iAddonBits, int, "CCSPlayer", "m_iAddonBits");
	M_NETVAR(m_AddonModelWeaponIDs, void*, "CCSPlayer", "m_AddonModelWeaponIDs");
	M_NETVAR(m_iThrowGrenadeCounter, int, "CCSPlayer", "m_iThrowGrenadeCounter");
	M_NETVAR(m_iPlayerState, int, "CCSPlayer", "m_iPlayerState");
	M_NETVAR(m_iAccount, int, "CCSPlayer", "m_iAccount");
	M_NETVAR(m_bInBombZone, bool, "CCSPlayer", "m_bInBombZone");
	M_NETVAR(m_bInBuyZone, bool, "CCSPlayer", "m_bInBuyZone");
	M_NETVAR(m_iClass, int, "CCSPlayer", "m_iClass");
	M_NETVAR(m_ArmorValue, int, "CCSPlayer", "m_ArmorValue");
	M_NETVAR(m_angEyeAngles, Vector, "CCSPlayer", "m_angEyeAngles[0]");
	M_NETVAR(m_bHasDefuser, bool, "CCSPlayer", "m_bHasDefuser");
	M_NETVAR(m_bNightVisionOn, bool, "CCSPlayer", "m_bNightVisionOn");
	M_NETVAR(m_bHasNightVision, bool, "CCSPlayer", "m_bHasNightVision");
	M_NETVAR(m_iNightVisionScale, int, "CCSPlayer", "m_iNightVisionScale");
	M_NETVAR(m_bInHostageRescueZone, bool, "CCSPlayer", "m_bInHostageRescueZone");
	M_NETVAR(m_bIsDefusing, bool, "CCSPlayer", "m_bIsDefusing");
	M_NETVAR(m_bHasHelmet, bool, "CCSPlayer", "m_bHasHelmet");
	M_NETVAR(m_vecRagdollVelocity, Vector, "CCSPlayer", "m_vecRagdollVelocity");
	M_NETVAR(m_flFlashDuration, float, "CCSPlayer", "m_flFlashDuration");
	M_NETVAR(m_flFlashMaxAlpha, float, "CCSPlayer", "m_flFlashMaxAlpha");
	M_NETVAR(m_flProgressBarDuration, float, "CCSPlayer", "m_flProgressBarDuration");
	M_NETVAR(m_flProgressBarStartTime, float, "CCSPlayer", "m_flProgressBarStartTime");
	M_NETVAR(m_hRagdoll, int, "CCSPlayer", "m_hRagdoll");
	M_NETVAR(m_cycleLatch, int, "CCSPlayer", "m_cycleLatch");
	M_NETVAR(m_lastLadderNormal, Vector, "CCSPlayer", "m_lastLadderNormal");
};