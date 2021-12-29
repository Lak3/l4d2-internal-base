#pragma once

#include "IClientEntity.h"

class C_BaseEntity;
class IClientVehicle;
class CTakeDamageInfo;
class IPhysicsObject;
class CDmgAccumulator;
class CEntityMapData;
class C_Infected;
class C_BasePlayer;
class C_Team;
class C_BaseCombatCharacter;
class C_BaseCombatWeapon;
class C_BaseAnimating;

typedef CHandle<C_BaseEntity> EHANDLE;

class C_BaseEntity : public IClientEntity
{
public:
	enum thinkmethods_t {
		THINK_FIRE_ALL_FUNCTIONS,
		THINK_FIRE_BASE_ONLY,
		THINK_FIRE_ALL_BUT_BASE,
	};

public:
	virtual                         ~C_BaseEntity() = 0;

	virtual void*					GetDataDescMap() = 0; //datamap_t*
	virtual void*					YouForgotToImplementOrDeclareClientClass() = 0;
	virtual void*					GetPredDescMap() = 0; //datamap_t*

	virtual void					FireBullets(const void* info) = 0; //FireBulletsInfo_t&
	virtual bool					ShouldDrawUnderwaterBulletBubbles() = 0;
	virtual bool					ShouldDrawWaterImpacts(void) = 0;
	virtual bool					HandleShotImpactingWater(const void* info, const Vector& vecEnd, ITraceFilter* pTraceFilter, Vector* pVecTracerDest) = 0;
	virtual ITraceFilter*			GetBeamTraceFilter(void) = 0;
	virtual void					DispatchTraceAttack(const CTakeDamageInfo* info, const Vector& vecDir, trace_t* ptr, CDmgAccumulator* pAccumulator = NULL) = 0;
	virtual void					TraceAttack(const CTakeDamageInfo* info, const Vector& vecDir, trace_t* ptr, CDmgAccumulator* pAccumulator = NULL) = 0;
	virtual void					DoImpactEffect(trace_t& tr, int nDamageType) = 0;
	virtual void					MakeTracer(const Vector& vecTracerSrc, const trace_t& tr, int iTracerType) = 0;
	virtual int						GetTracerAttachment(void) = 0;
	virtual int						BloodColor() = 0;
	virtual const char*				GetTracerType() = 0;
	virtual void					Spawn(void) = 0;
	virtual void					SpawnClientEntity(void) = 0;
	virtual void					Precache(void) = 0;
	virtual void					Activate() = 0;
	virtual void					OnParseMapDataFinished(void) = 0;
	virtual bool					KeyValue(const char* szKeyName, const char* szValue) = 0;
	virtual bool					KeyValue(const char* szKeyName, float flValue) = 0;
	virtual bool					KeyValue(const char* szKeyName, const Vector& vecValue) = 0;
	virtual bool					GetKeyValue(const char* szKeyName, char* szValue, int iMaxLen) = 0;
	virtual void					InitSharedVars(void) = 0;
	virtual bool					Init(int entnum, int iSerialNum) = 0;
	virtual C_BaseAnimating*		GetBaseAnimating() = 0;
	virtual void					SetClassname(const char* className) = 0;
	virtual void			        RecordToolMessage() = 0;
	virtual Vector					GetObserverCamOrigin(void) = 0;
	virtual IMaterial*				GetShadowDrawMaterial(void) = 0;
	virtual bool					TestCollision(const Ray_t& ray, unsigned int fContentsMask, trace_t& tr) = 0;
	virtual bool					TestHitboxes(const Ray_t& ray, unsigned int fContentsMask, trace_t& tr) = 0;
	virtual bool                    IsAbleToHaveFireEffect() const = 0;
	virtual float					GetAttackDamageScale(void) = 0;
	virtual void					ValidateModelIndex(void) = 0;
	virtual void					SetDormant(bool bDormant) = 0;
	virtual void					OnSetDormant(bool unk1) = 0;
	virtual int				        GetEFlags() const = 0;
	virtual void			        SetEFlags(int iEFlags) = 0;
	virtual bool					ShouldSavePhysics() = 0;
	virtual void					OnSave() = 0;
	virtual void					OnRestore() = 0;
	virtual int						ObjectCaps(void) = 0;

private:
	virtual void*					GetUsePriority(C_BaseEntity* unk1) = 0;

public:
	virtual int						Save(void* save) = 0;
	virtual int						Restore(void* restore) = 0;
	virtual bool	                CreateVPhysics() = 0;
	virtual void	                VPhysicsDestroyObject(void) = 0;
	virtual void					VPhysicsUpdate(IPhysicsObject* pPhysics) = 0;
	virtual int						VPhysicsGetObjectList(IPhysicsObject** pList, int listMax) = 0;
	virtual bool					VPhysicsIsFlesh(void) = 0;
	virtual const Vector&			GetPrevLocalOrigin() const = 0;
	virtual const Vector&			GetPrevLocalAngles() const = 0;
	virtual const Vector&			WorldAlignMins() const = 0;
	virtual const Vector&			WorldAlignMaxs() const = 0;
	virtual const Vector&			WorldSpaceCenter() const = 0;
	virtual void					ComputeWorldSpaceSurroundingBox(Vector* pVecWorldMins, Vector* pVecWorldMaxs) = 0;
	virtual int						GetSolid(void) const = 0;
	virtual int			 			GetSolidFlags(void) const = 0;
	virtual bool					GetAttachment(int number, Vector& origin) = 0;

private:
	virtual bool					GetAttachmentVelocity(int number, Vector& originVel, void* angleVel) = 0;

public:
	virtual void					InvalidateAttachments() = 0;
	virtual C_Team*					GetTeam(void) const = 0;
	virtual int						GetTeamNumber(void) const = 0;
	virtual void					ChangeTeam(int iTeamNum) = 0;
	virtual int						GetRenderTeamNumber(void) = 0;
	virtual bool					InSameTeam(const C_BaseEntity* pEntity) const = 0;
	virtual bool					InLocalTeam(void) = 0;
	virtual bool					IsValidIDTarget(void) = 0;
	virtual const char*				GetIDString(void) = 0;
	virtual const char				GetUseString(C_BaseEntity* unk1) = 0;

private:
	virtual int						GetUseType(C_BaseEntity* unk2) = 0;
	virtual C_BaseEntity*			GetGlowEntity() = 0;

public:
	virtual bool					IsAbleToGlow() = 0;
	virtual bool					IsPotentiallyUsable() = 0;
	virtual void					UpdatePartitionListEntry() = 0;
	virtual bool                    InitializeAsClientEntity(const char* pszModelName, int renderGroup) = 0; //RenderGroup_t
	virtual void					Simulate() = 0;
	virtual IClientVehicle*			GetClientVehicle() = 0;
	virtual void					GetAimEntOrigin(IClientEntity* pAttachedTo, Vector* pAbsOrigin, Vector* pAbsAngles) = 0;
	virtual const Vector&			GetOldOrigin() = 0;
	virtual void					ComputeTranslucencyType(void) = 0;
	virtual void					GetToolRecordingState(void* msg) = 0;
	virtual void					CleanupToolRecordingState(void* msg) = 0;
	virtual int          			GetCollideType(void) = 0; //CollideType_t
	virtual bool					IsSelfAnimating() = 0;
	virtual	void					OnLatchInterpolatedVariables(int flags) = 0;
	virtual CStudioHdr*				OnNewModel() = 0;
	virtual void					OnNewParticleEffect(const char* pszParticleName, void* pNewParticleEffect) = 0;
	virtual void					OnParticleEffectDeleted(void* unk1) = 0;
	virtual void					ResetLatched() = 0;
	virtual bool					Interpolate(float currentTime) = 0;
	virtual bool					IsSubModel(void) = 0;
	virtual void					CreateLightEffects(void) = 0;
	virtual void					Clear(void) = 0;
	virtual int						DrawBrushModel(bool bTranslucent, int nFlags, bool bTwoPass) = 0;
	virtual float					GetTextureAnimationStartTime() = 0;
	virtual void					TextureAnimationWrapped() = 0;
	virtual void					SetNextClientThink(float nextThinkTime) = 0;
	virtual void					SetHealth(int iHealth) = 0;
	virtual int						GetHealth() const = 0;
	virtual int						GetActualHealth()const = 0;
	virtual int						GetMaxHealth() const = 0;
	virtual void					AddDecal(const Vector& rayStart, const Vector& rayEnd, const Vector& decalCenter, int hitbox, int decalIndex, bool doTrace, trace_t& tr, int maxLODToDecal = 0) = 0;
	virtual bool					IsClientCreated(void) const = 0;
	virtual void					UpdateOnRemove(void) = 0;
	virtual void					SUB_Remove(void) = 0;
	virtual C_BasePlayer*			GetPredictionOwner(void) = 0;
	virtual void					InitPredictable(C_BasePlayer* unk1) = 0;
	virtual void					SetPredictable(bool state) = 0;
	virtual char const*				DamageDecal(int bitsDamageType, int gameMaterial) = 0;
	virtual void					DecalTrace(trace_t* pTrace, char const* decalName) = 0;
	virtual void					ImpactTrace(trace_t* pTrace, int iDamageType, const char* pCustomImpactName) = 0;
	virtual bool					ShouldPredict(void) = 0;
	virtual void					Think(void) = 0;

private:
	virtual void*					PreRender(int unk1) = 0;

public:
	virtual const char*				GetPlayerName(void) const = 0;
	virtual void					EstimateAbsVelocity(Vector& unk1) = 0;
	virtual bool			        CanBePoweredUp(void) = 0;
	virtual bool			        AttemptToPowerup(int iPowerup, float flTime, float flAmount = 0, C_BaseEntity* pAttacker = NULL, void* pDamageModifier = NULL) = 0;
	virtual bool			        IsCurrentlyTouching(void) const = 0;
	virtual void			        StartTouch(C_BaseEntity* pOther) = 0;
	virtual void			        Touch(C_BaseEntity* pOther) = 0;
	virtual void			        EndTouch(C_BaseEntity* pOther) = 0;
	virtual unsigned int	        PhysicsSolidMaskForEntity(void) const = 0;

private:
	virtual void*					OnGroundChanged(C_BaseEntity* unk1, C_BaseEntity* unk2) = 0;

public:
	virtual void					PhysicsSimulate(void) = 0;
	virtual bool					IsPlayer(void) const = 0;
	virtual bool					IsBaseCombatCharacter(void) = 0;
	virtual C_BaseCombatCharacter*	MyCombatCharacterPointer(void) = 0;
	virtual C_Infected*				MyInfectedPointer(void) = 0;
	virtual void*					MyInfectedRagdollPointer(void) = 0;
	virtual bool					IsNPC(void) = 0;
	virtual bool					IsNextBot() = 0;
	virtual bool					IsBaseObject(void) const = 0;
	virtual bool					IsBaseCombatWeapon(void) const = 0;
	virtual C_BaseCombatWeapon*		MyCombatWeaponPointer() = 0;
	virtual bool					IsBaseTrain(void) const = 0;
	virtual bool					IsElevator(void) const = 0;
	virtual Vector			        EyePosition(void) = 0;
	virtual const Vector&			EyeAngles(void) = 0;
	virtual const Vector&			LocalEyeAngles(void) = 0;
	virtual Vector		            EarPosition(void) = 0;
	virtual bool		            ShouldCollide(int collisionGroup, int contentsMask) const = 0;
	virtual float					GetFriction() const = 0;
	virtual const Vector&			GetViewOffset() const = 0;
	virtual void		            SetViewOffset(const Vector& v) = 0;
	virtual void					GetGroundVelocityToApply(Vector& unk1) = 0;
	virtual bool                    ShouldInterpolate() = 0;
	virtual void                    BoneMergeFastCullBloat(Vector& localMins, Vector& localMaxs, const Vector& thisEntityMins, const Vector& thisEntityMaxs) const = 0;
	virtual bool					OnPredictedEntityRemove(bool isbeingremoved, C_BaseEntity* predicted) = 0;
	virtual C_BaseEntity*			GetShadowUseOtherEntity(void) const = 0;
	virtual void					SetShadowUseOtherEntity(C_BaseEntity* pEntity) = 0;
	virtual bool					AddRagdollToFadeQueue(void) = 0;
	virtual int						GetStudioBody(void) = 0;
	virtual void                    PerformCustomPhysics(Vector* pNewPosition, Vector* pNewVelocity, Vector* pNewAngles, Vector* pNewAngVelocity) = 0;

public:
	M_NETVAR(m_flSimulationTime, float, "CBaseEntity", "m_flSimulationTime");
	M_NETVAR(m_flAnimTime, float, "CBaseEntity", "m_flAnimTime");
	M_NETVAR(m_flCreateTime, float, "CBaseEntity", "m_flCreateTime");
	M_NETVAR(m_cellbits, int, "CBaseEntity", "m_cellbits");
	M_NETVAR(m_cellX, int, "CBaseEntity", "m_cellX");
	M_NETVAR(m_cellY, int, "CBaseEntity", "m_cellY");
	M_NETVAR(m_cellZ, int, "CBaseEntity", "m_cellZ");
	M_NETVAR(m_vecOrigin, Vector, "CBaseEntity", "m_vecOrigin");
	M_NETVAR(m_angRotation, Vector, "CBaseEntity", "m_angRotation");
	M_NETVAR(m_nModelIndex, int, "CBaseEntity", "m_nModelIndex");
	M_NETVAR(m_fEffects, int, "CBaseEntity", "m_fEffects");
	M_NETVAR(m_nRenderMode, int, "CBaseEntity", "m_nRenderMode");
	M_NETVAR(m_nRenderFX, int, "CBaseEntity", "m_nRenderFX");
	M_NETVAR(m_clrRender, int, "CBaseEntity", "m_clrRender");
	M_NETVAR(m_iTeamNum, int, "CBaseEntity", "m_iTeamNum");
	M_NETVAR(m_CollisionGroup, int, "CBaseEntity", "m_CollisionGroup");
	M_NETVAR(m_flElasticity, float, "CBaseEntity", "m_flElasticity");
	M_NETVAR(m_flShadowCastDistance, float, "CBaseEntity", "m_flShadowCastDistance");
	M_NETVAR(m_hOwnerEntity, EHANDLE, "CBaseEntity", "m_hOwnerEntity");
	M_NETVAR(m_hEffectEntity, EHANDLE, "CBaseEntity", "m_hEffectEntity");
	M_NETVAR(moveparent, int, "CBaseEntity", "moveparent");
	M_NETVAR(m_iParentAttachment, int, "CBaseEntity", "m_iParentAttachment");
	M_NETVAR(m_hScriptUseTarget, EHANDLE, "CBaseEntity", "m_hScriptUseTarget");
	M_NETVAR(m_Collision, ICollideable*, "CBaseEntity", "m_Collision");
	M_NETVAR(m_vecMins, Vector, "CBaseEntity", "m_vecMins");
	M_NETVAR(m_vecMaxs, Vector, "CBaseEntity", "m_vecMaxs");
	M_NETVAR(m_nSolidType, int, "CBaseEntity", "m_nSolidType");
	M_NETVAR(m_usSolidFlags, unsigned short, "CBaseEntity", "m_usSolidFlags");
	M_NETVAR(m_nSurroundType, int, "CBaseEntity", "m_nSurroundType");
	M_NETVAR(m_triggerBloat, int, "CBaseEntity", "m_triggerBloat");
	M_NETVAR(m_vecSpecifiedSurroundingMins, Vector, "CBaseEntity", "m_vecSpecifiedSurroundingMins");
	M_NETVAR(m_vecSpecifiedSurroundingMaxs, Vector, "CBaseEntity", "m_vecSpecifiedSurroundingMaxs");
	M_NETVAR(m_Glow, void*, "CBaseEntity", "m_Glow");
	M_NETVAR(m_iGlowType, int, "CBaseEntity", "m_iGlowType");
	M_NETVAR(m_nGlowRange, int, "CBaseEntity", "m_nGlowRange");
	M_NETVAR(m_nGlowRangeMin, int, "CBaseEntity", "m_nGlowRangeMin");
	M_NETVAR(m_glowColorOverride, int, "CBaseEntity", "m_glowColorOverride");
	M_NETVAR(m_bFlashing, bool, "CBaseEntity", "m_bFlashing");
	M_NETVAR(m_iTextureFrameIndex, int, "CBaseEntity", "m_iTextureFrameIndex");
	M_NETVAR(m_bSimulatedEveryTick, bool, "CBaseEntity", "m_bSimulatedEveryTick");
	M_NETVAR(m_bAnimatedEveryTick, bool, "CBaseEntity", "m_bAnimatedEveryTick");
	M_NETVAR(m_bAlternateSorting, bool, "CBaseEntity", "m_bAlternateSorting");
	M_NETVAR(m_bGlowBackfaceMult, bool, "CBaseEntity", "m_bGlowBackfaceMult");
	M_NETVAR(m_Gender, int, "CBaseEntity", "m_Gender");
	M_NETVAR(m_fadeMinDist, float, "CBaseEntity", "m_fadeMinDist");
	M_NETVAR(m_fadeMaxDist, float, "CBaseEntity", "m_fadeMaxDist");
	M_NETVAR(m_flFadeScale, float, "CBaseEntity", "m_flFadeScale");
	M_NETVAR(m_nMinCPULevel, int, "CBaseEntity", "m_nMinCPULevel");
	M_NETVAR(m_nMaxCPULevel, int, "CBaseEntity", "m_nMaxCPULevel");
	M_NETVAR(m_nMinGPULevel, int, "CBaseEntity", "m_nMinGPULevel");
	M_NETVAR(m_nMaxGPULevel, int, "CBaseEntity", "m_nMaxGPULevel");

public:
	inline bool PhysicsRunThink(thinkmethods_t thinkMethod = THINK_FIRE_ALL_FUNCTIONS) {
		return reinterpret_cast<bool(__thiscall*)(void*, thinkmethods_t)>(U::Offsets.m_dwPhysicsRunThink)(this, thinkMethod);
	}

	inline unsigned char& m_MoveType() {
		return *reinterpret_cast<unsigned char*>(reinterpret_cast<DWORD>(this) + 0x144);
	}
};