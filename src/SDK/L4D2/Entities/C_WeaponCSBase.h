#pragma once

#include "C_DynamicProp.h"

class CHudTexture;
class C_TerrorGun;
class C_BaseViewModel;
class C_CSPlayer;

class C_BaseCombatWeapon : public C_BaseAnimating
{
public:
	virtual							~C_BaseCombatWeapon() = 0;

	virtual bool					IsPredicted(void) const = 0;
	virtual int						GetSubType(void) = 0;
	virtual void					SetSubType(int iType) = 0;
	virtual void					Equip(C_BaseCombatCharacter* pOwner) = 0;
	virtual void					Drop(const Vector& vecVelocity) = 0;
	virtual	int						UpdateClientData(C_BaseEntity* pPlayer) = 0;
	virtual bool					IsAllowedToSwitch(void) = 0;
	virtual bool					CanBeSelected(void) = 0;
	virtual bool					VisibleInWeaponSelection(void) = 0;
	virtual bool					HasAmmo(void) = 0;
	virtual void					SetPickupTouch(void) = 0;
	virtual void 					DefaultTouch(C_BaseEntity* pOther) = 0;
	virtual bool					ShouldDisplayAltFireHUDHint() = 0;
	virtual void					DisplayAltFireHudHint() = 0;
	virtual void					RescindAltFireHudHint() = 0;
	virtual bool					ShouldDisplayReloadHUDHint() = 0;
	virtual void					DisplayReloadHudHint() = 0;
	virtual void					RescindReloadHudHint() = 0;
	virtual void					SetViewModelIndex(int index = 0) = 0;
	virtual bool					SendWeaponAnim(int iActivity) = 0;
	virtual void					SendViewModelAnim(int nSequence) = 0;
	virtual int						GetTracerAttachmentIndex(void) = 0;
	virtual void					SetViewModel() = 0;
	virtual bool					HasWeaponIdleTimeElapsed(void) = 0;
	virtual void					SetWeaponIdleTime(float time) = 0;
	virtual float					GetWeaponIdleTime(void) = 0;
	virtual bool					HasAnyAmmo(void) = 0;
	virtual bool					HasPrimaryAmmo(void) = 0;
	virtual bool					HasSecondaryAmmo(void) = 0;
	virtual bool					CanHolster(void) = 0;
	virtual bool					DefaultDeploy(char* szViewModel, char* szWeaponModel, int iActivity, char* szAnimExt) = 0;
	virtual bool					CanDeploy(void) = 0;
	virtual bool					Deploy(void) = 0;
	virtual bool					Holster(C_BaseCombatWeapon* pSwitchingTo = NULL) = 0;
	virtual C_BaseCombatWeapon*		GetLastWeapon(void) = 0;
	virtual void					SetWeaponVisible(bool visible) = 0;
	virtual bool					IsWeaponVisible(void) = 0;
	virtual bool					ReloadOrSwitchWeapons(void) = 0;
	virtual bool					CanSwitchAwayFrom(void) = 0;
	virtual void					ItemPreFrame(void) = 0;
	virtual void					ItemPostFrame(void) = 0;
	virtual void					ItemBusyFrame(void) = 0;
	virtual void					ItemHolsterFrame(void) = 0;
	virtual void					WeaponIdle(void) = 0;
	virtual void					HandleFireOnEmpty() = 0;
	virtual void					CreateMove(float flInputSampleTime, CUserCmd* pCmd, const Vector& vecOldViewAngles) = 0;
	virtual bool					IsWeaponZoomed() const = 0;
	virtual	void					CheckReload(void) = 0;
	virtual void					FinishReload(void) = 0;
	virtual void					AbortReload(void) = 0;
	virtual bool					Reload(void) = 0;
	virtual void					PrimaryAttack(void) = 0;
	virtual void					SecondaryAttack(void) = 0;
	virtual Vector					ShootPosition(void) = 0;
	virtual void					BaseForceFire(C_BaseCombatCharacter* unk1, C_BaseEntity* unk2) = 0;
	virtual int						GetPrimaryAttackActivity(void) = 0;
	virtual int						GetSecondaryAttackActivity(void) = 0;
	virtual int						GetDrawActivity(void) = 0;
	virtual int						GetReloadActivity(void) const = 0;
	virtual float					GetDefaultAnimSpeed(void) = 0;
	virtual int						GetBulletType(void) = 0;
	virtual const Vector&			GetBulletSpread(void) = 0;
	virtual Vector					GetBulletSpread(void* proficiency) = 0;
	virtual float					GetSpreadBias(void* proficiency) = 0;
	virtual float					GetFireRate(void) = 0;
	virtual int						GetMinBurst() = 0;
	virtual int						GetMaxBurst() = 0;
	virtual float					GetMinRestTime() = 0;
	virtual float					GetMaxRestTime() = 0;
	virtual int						GetRandomBurst() = 0;
	virtual void					WeaponSound(int sound_type, float soundtime = 0.0f) = 0;
	virtual void					StopWeaponSound(int sound_type) = 0;
	virtual const void*				GetProficiencyValues() = 0;
	virtual float					GetMaxAutoAimDeflection() = 0;
	virtual float					WeaponAutoAimScale() = 0;
	virtual bool					StartSprinting(void) = 0;
	virtual bool					StopSprinting(void) = 0;
	virtual float					GetDamage(float flDistance, int iLocation) = 0;
	virtual void					SetActivity(int act, float duration) = 0;
	virtual void					AddViewKick(void) = 0;
	virtual char*					GetDeathNoticeName(void) = 0;
	virtual void					OnPickedUp(C_BaseCombatCharacter* pNewOwner) = 0;
	virtual void					AddViewmodelBob(C_BaseViewModel* viewmodel, Vector& origin, Vector& angles) = 0;
	virtual float					CalcViewmodelBob(void) = 0;
	virtual void 					GetControlPanelInfo(int nPanelIndex, const char*& pPanelName) = 0;
	virtual void					GetControlPanelClassName(int nPanelIndex, const char*& pPanelName) = 0;
	virtual bool					ShouldShowControlPanels(void) = 0;
	virtual bool					CanBePickedUpByNPCs(void) = 0;
	virtual C_TerrorGun*			GetTerrorGun(void) = 0;
	virtual const char*				GetViewModel(int viewmodelindex = 0) const = 0;
	virtual const char*				GetWorldModel(void) const = 0;
	virtual const char*				GetAnimPrefix(void) const = 0;
	virtual int						GetMaxClip1(void) const = 0;
	virtual int						GetMaxClip2(void) const = 0;
	virtual int						GetDefaultClip1(void) const = 0;
	virtual int						GetDefaultClip2(void) const = 0;
	virtual int						GetWeight(void) const = 0;
	virtual bool					AllowsAutoSwitchTo(void) const = 0;
	virtual bool					AllowsAutoSwitchFrom(void) const = 0;
	virtual int						GetWeaponFlags(void) const = 0;
	virtual int						GetSlot(void) const = 0;
	virtual int						GetPosition(void) const = 0;
	virtual char const*				GetName(void) const = 0;
	virtual char const*				GetPrintName(void) const = 0;
	virtual char const*				GetShootSound(int iIndex) const = 0;
	virtual int						GetRumbleEffect() const = 0;
	virtual bool					UsesClipsForAmmo1(void) const = 0;
	virtual bool					UsesClipsForAmmo2(void) const = 0;
	virtual bool					IsGrenade() const = 0;
	virtual void					OnMouseWheel(int unk1) = 0;
	virtual const unsigned char*	GetEncryptionKey(void) = 0;
	virtual int						GetPrimaryAmmoType(void) const = 0;
	virtual int						GetSecondaryAmmoType(void) const = 0;
	virtual CHudTexture const*		GetSpriteActive(void) const = 0;
	virtual CHudTexture const*		GetSpriteInactive(void) const = 0;
	virtual CHudTexture const*      GetSpriteSmall(void) const = 0;
	virtual CHudTexture const*		GetSpriteAmmo(void) const = 0;
	virtual CHudTexture const*		GetSpriteAmmo2(void) const = 0;
	virtual CHudTexture const*		GetSpriteCrosshair(void) const = 0;
	virtual CHudTexture const*		GetSpriteAutoaim(void) const = 0;
	virtual CHudTexture const*		GetSpriteZoomedCrosshair(void) const = 0;
	virtual CHudTexture const*		GetSpriteZoomedAutoaim(void) const = 0;
	virtual CHudTexture const*		GetSpriteDualActive(void) const = 0;
	virtual CHudTexture const*		GetSpriteDualInactive(void) const = 0;
	virtual int						ActivityOverride(int baseAct, bool* pRequired) = 0;
	virtual	void*					ActivityList(void) = 0;
	virtual	int						ActivityListCount(void) = 0;
	virtual float					GetReloadDurationModifier(void) = 0;
	virtual float					GetDeployDurationModifier(void) = 0;
	virtual bool					OnFireEvent(C_BaseViewModel* pViewModel, const Vector& origin, const Vector& angles, int event, const char* options) = 0;
	virtual void					Redraw(void) = 0;
	virtual void					ViewModelDrawn(int nFlags, C_BaseViewModel* pViewModel) = 0;
	virtual void					DrawCrosshair(void) = 0;
	virtual bool					ShouldDrawCrosshair(void) = 0;
	virtual bool					IsCarriedByLocalPlayer(void) = 0;
	virtual bool					IsActiveByLocalPlayer(void) = 0;
	virtual bool					ShouldDrawPickup(void) = 0;
	virtual void					HandleInput(void) = 0;
	virtual void					OverrideMouseInput(float* x, float* y) = 0;
	virtual void					OverrideJoystickInput(float* x, float* y) = 0;
	virtual int						KeyInput(int down, int keynum, const char* pszCurrentBinding) = 0;
	virtual bool					AddLookShift(void) = 0;
	virtual void					GetViewmodelBoneControllers(C_BaseViewModel* pViewModel, float controllers[NUM_BONECTRLS]) = 0;
	virtual int						GetWorldModelIndex(void) = 0;
	virtual bool					ShouldDrawThisOrWorldModelClone(void) = 0;
	virtual void					GetToolViewModelState(void* msg) = 0;
	virtual bool					CanLower(void) = 0;
	virtual bool					Ready(void) = 0;
	virtual bool					Lower(void) = 0;
	virtual void					HideThink(void) = 0;

private:
	virtual void*					NetworkStateChanged_m_nNextThinkTick(void) = 0;
	virtual void*					NetworkStateChanged_m_nNextThinkTick(void* unk1) = 0;

public:
	M_NETVAR(m_iPrimaryAmmoType, int, "CBaseCombatWeapon", "m_iPrimaryAmmoType");
	M_NETVAR(m_iSecondaryAmmoType, int, "CBaseCombatWeapon", "m_iSecondaryAmmoType");
	M_NETVAR(m_nViewModelIndex, int, "CBaseCombatWeapon", "m_nViewModelIndex");
	M_NETVAR(m_flNextPrimaryAttack, float, "CBaseCombatWeapon", "m_flNextPrimaryAttack");
	M_NETVAR(m_flNextSecondaryAttack, float, "CBaseCombatWeapon", "m_flNextSecondaryAttack");
	M_NETVAR(m_nNextThinkTick, int, "CBaseCombatWeapon", "m_nNextThinkTick");
	M_NETVAR(m_flTimeWeaponIdle, float, "CBaseCombatWeapon", "m_flTimeWeaponIdle");
	M_NETVAR(m_nQueuedAttack, int, "CBaseCombatWeapon", "m_nQueuedAttack");
	M_NETVAR(m_flTimeAttackQueued, float, "CBaseCombatWeapon", "m_flTimeAttackQueued");
	M_NETVAR(m_bOnlyPump, bool, "CBaseCombatWeapon", "m_bOnlyPump");
	M_NETVAR(m_iViewModelIndex, int, "CBaseCombatWeapon", "m_iViewModelIndex");
	M_NETVAR(m_iWorldModelIndex, int, "CBaseCombatWeapon", "m_iWorldModelIndex");
	M_NETVAR(m_iState, int, "CBaseCombatWeapon", "m_iState");
	M_NETVAR(m_hOwner, int, "CBaseCombatWeapon", "m_hOwner");
	M_NETVAR(m_bInReload, bool, "CBaseCombatWeapon", "m_bInReload");
};

class C_WeaponCSBase : public C_BaseCombatWeapon
{
public:
	virtual				~C_WeaponCSBase() = 0;

	virtual bool		IsHelpingHandExtended(void) const = 0;
	virtual bool		CanPlayerTouch(C_CSPlayer* unk1) = 0;
	virtual bool		IsAttacking(void) const = 0;
	virtual void		WeaponTranslateMainActivity(int unk1) = 0;

private:
	virtual void*		GetWeaponFireActivity(int unk1, int unk2) = 0;
	virtual void*		GetWeaponReloadActivity(int unk1, int unk2) = 0;
	virtual void*		GetWeaponDeployActivity(int unk1, int unk2) = 0;

public:
	virtual bool		IsAwp(void) const = 0;
	virtual bool		CanZoom(void) const = 0;
	virtual bool		HasScope(void) const = 0;

private:
	virtual void*		CycleZoom(void) = 0;

public:
	virtual float		GetMaxSpeed(void) const = 0;
	virtual int			GetWeaponID(void) const = 0;
	virtual bool		IsSilenced(void) const = 0;
	virtual void		SetWeaponModelIndex(const char* pName) = 0;
	virtual void*		GetPlayerModel(void) const = 0;
	virtual bool		ShouldHideWeapon(void) const = 0;
	virtual bool		CanWeaponBeAbsorbedBySpawn(void) const = 0;
	virtual void		EjectBrass(void) = 0;
	virtual void		ClearCrosshair(void) = 0;
	virtual void		ResetCrosshair(void) = 0;

private:
	virtual void*		HasWeaponTimerHud(void) = 0;
	virtual void*		GetWeaponTimerHudPercent(void) = 0;
	virtual void*		GetWeaponTimerHudTextureNames(const char** unk1, const char** unk2) = 0;

public:
	virtual int			GetMuzzleAttachment(void) = 0;
	virtual int			GetShellAttachment(void) = 0;
	virtual bool		HideViewModelWhenZoomed(void) = 0;
	virtual void		UpdateShieldState(void) = 0;
	virtual bool		HasSecondaryAttack(void) = 0;
	virtual int         GetDeployActivity(void) = 0;
	virtual bool		DefaultPistolReload() = 0;
	virtual bool		DeployResetsAttackTime(void) = 0;
	virtual bool		CanBeDropped(void) const = 0;
	virtual bool		ShouldDropBehind(void) = 0;
	virtual bool		IsWeaponUpgraded(void) = 0;

public:
	M_NETVAR(m_iExtraPrimaryAmmo, int, "CWeaponCSBase", "m_iExtraPrimaryAmmo");
};