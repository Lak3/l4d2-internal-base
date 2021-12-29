#pragma once

#include "C_WeaponCSBase.h"

class C_TerrorPlayer;

class IResponseRulesWeaponSource
{
public:
	virtual const char* GetResponseRulesWeaponName(void) const = 0;
};

class C_TerrorWeapon : public C_WeaponCSBase, public IResponseRulesWeaponSource
{
public:
	virtual				~C_TerrorWeapon() = 0;

	virtual bool		IsDualWielding(void) const = 0;
	virtual bool		CanPlayerMove(void) const = 0;
	virtual bool		HasSecondaryMelee(void) = 0;
	virtual bool		CanSecondaryMeleeInterruptReload(void) = 0;
	virtual bool		CanDeployFor(C_TerrorPlayer* unk1) = 0;
	virtual bool		CanFidget(void) = 0;
	virtual bool		IsDroppedWhenHolstered(void) const = 0;
	virtual bool		WantsCSItemPostFrame(void) const = 0;
	virtual void		UseAction(void) = 0;
	virtual void		OnStunned(float unk1) = 0;
	virtual void		OnPouncedUpon(void) = 0;
	virtual void		OnOwnerTakeDamage(const void* unk1) = 0;
	virtual void		AddUpgrade(int unk1) = 0;
	virtual void		RemoveUpgrade(int unk1) = 0;
	virtual void		RemoveAllUpgrades(void) = 0;
	virtual bool		HasUpgrade(int unk1) const = 0;
	virtual void		CalcViewmodelLayerActivity(int unk1) const = 0;
	virtual void		TranslateViewmodelActivity(int unk1) const = 0;
	virtual int			GetViewmodelMeleeActivity(void) = 0;
	virtual int			GetLayerForViewmodelActicity(int unk1) const = 0;
	virtual bool		CanExtendHelpingHand(void) const = 0;
	virtual float		GetSwingForward(void) = 0;
	virtual void		TrySwing(float unk1, float unk2, float unk3) = 0;
	virtual void		OnHit(CGameTrace& unk1, const Vector& unk2, bool unk3) = 0;
	virtual void		OnSwingStart(void) = 0;
	virtual void		OnSwingEnd(bool unk1) = 0;
	virtual void		DoSwing(void) = 0;
	virtual float		SwingYawStart(void) const = 0;
	virtual float		SwingYawEnd(void) const = 0;
	virtual float		SwingPitchStart(void) const = 0;
	virtual float		SwingPitchEnd(void) const = 0;
	virtual void		CheckQueuedReload(void) = 0;
	virtual void		CheckCancelledReload(void) = 0;

public:
	M_NETVAR(m_helpingHandSuppressionTimer, void*, "CTerrorWeapon", "m_helpingHandSuppressionTimer");
	M_NETVAR(m_duration, float, "CTerrorWeapon", "m_duration");
	M_NETVAR(m_timestamp, float, "CTerrorWeapon", "m_timestamp");
	M_NETVAR(m_helpingHandTimer, void*, "CTerrorWeapon", "m_helpingHandTimer");
	M_NETVAR(m_helpingHandTargetTimer, void*, "CTerrorWeapon", "m_helpingHandTargetTimer");
	M_NETVAR(m_helpingHandState, int, "CTerrorWeapon", "m_helpingHandState");
	M_NETVAR(m_helpingHandTarget, EHANDLE, "CTerrorWeapon", "m_helpingHandTarget");
	M_NETVAR(m_helpingHandExtendDuration, float, "CTerrorWeapon", "m_helpingHandExtendDuration");
	M_NETVAR(m_reloadQueuedStartTime, float, "CTerrorWeapon", "m_reloadQueuedStartTime");
	M_NETVAR(m_releasedAltFireButton, bool, "CTerrorWeapon", "m_releasedAltFireButton");
	M_NETVAR(m_releasedFireButton, bool, "CTerrorWeapon", "m_releasedFireButton");
	M_NETVAR(m_isHoldingAltFireButton, bool, "CTerrorWeapon", "m_isHoldingAltFireButton");
	M_NETVAR(m_isHoldingFireButton, bool, "CTerrorWeapon", "m_isHoldingFireButton");
	M_NETVAR(m_bPickedUpOnTransition, bool, "CTerrorWeapon", "m_bPickedUpOnTransition");
	M_NETVAR(m_DroppedByInfectedGender, bool, "CTerrorWeapon", "m_DroppedByInfectedGender");
	M_NETVAR(m_iBloodyWeaponLevel, int, "CTerrorWeapon", "m_iBloodyWeaponLevel");
	M_NETVAR(m_attackTimer, void*, "CTerrorWeapon", "m_attackTimer");
	M_NETVAR(m_swingTimer, void*, "CTerrorWeapon", "m_swingTimer");
	M_NETVAR(m_nUpgradedPrimaryAmmoLoaded, int, "CTerrorWeapon", "m_nUpgradedPrimaryAmmoLoaded");

public:
	inline float& GetCurrentSpread() {
		return *reinterpret_cast<float*>(reinterpret_cast<DWORD>(this) + 0xD0C);
	}

	inline bool CanPrimaryAttack() {
		return (m_flNextPrimaryAttack() <= I::GlobalVars->curtime);
	}

	inline bool CanSecondaryAttack() {
		return (m_flNextSecondaryAttack() <= I::GlobalVars->curtime);
	}

	inline void UpdateSpread() {
		reinterpret_cast<void(__thiscall*)(void*)>(U::Offsets.m_dwUpdateSpread)(this);
	}
};

class C_BaseBackpackItem : public C_TerrorWeapon
{
public:
	virtual					~C_BaseBackpackItem() = 0;
	virtual C_BaseEntity*	GetTargetEntity(C_TerrorPlayer* unk1, int unk2) = 0;
	virtual bool			ShouldStartAction(int unk1, C_TerrorPlayer* unk2, C_BaseEntity* unk3) = 0;
	virtual void			StartAction(int unk1, void* unk2) = 0;
	virtual void			OnStartAction(int unk1, C_TerrorPlayer* unk2, C_BaseEntity* unk3, float unk4) = 0;
	virtual float			GetActionDuration(void) = 0;

public:
	M_NETVAR(m_bPerformingAction, bool, "CBaseBackpackItem", "m_bPerformingAction");
};

class C_BaseMountedWeapon : public C_DynamicProp
{
public:
	virtual			~C_BaseMountedWeapon() = 0;
	virtual void	GetStandPosition(Vector* unk1) const = 0;

public:
	M_NETVAR(m_initialAngles, Vector, "CBaseMountedWeapon", "m_initialAngles");
	M_NETVAR(m_owner, EHANDLE, "CBaseMountedWeapon", "m_owner");
	M_NETVAR(m_maxYaw, float, "CBaseMountedWeapon", "m_maxYaw");
	M_NETVAR(m_maxPitch, float, "CBaseMountedWeapon", "m_maxPitch");
	M_NETVAR(m_minPitch, float, "CBaseMountedWeapon", "m_minPitch");
	M_NETVAR(m_firing, bool, "CBaseMountedWeapon", "m_firing");
	M_NETVAR(m_overheated, bool, "CBaseMountedWeapon", "m_overheated");
	M_NETVAR(m_heat, float, "CBaseMountedWeapon", "m_heat");
};

class C_WeaponSpawn : public C_BaseAnimating
{
public:
	virtual			~C_WeaponSpawn() = 0;
	virtual int		GetWeaponID(void) const = 0;

public:
	M_NETVAR(m_weaponID, int, "CWeaponSpawn", "m_weaponID");
	M_NETVAR(m_flGlowRange, float, "CWeaponSpawn", "m_flGlowRange");
};

