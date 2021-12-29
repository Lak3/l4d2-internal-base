#pragma once

#include "color.h"

class IClientModelRenderable;
class IClientRenderable;
struct studiohdr_t;

//18.06.2021
enum EClientClass {
	INVALID = -1,
	Jockey = 265,
	Spitter = 272,
	Charger = 99,
	Hunter = 263,
	Smoker = 270,
	Boomer = 0,
	Tank = 276,
	Witch = 277,
	Infected = 264,
	CVomitJarProjectile = 252,
	CTerrorWeapon = 235,
	CTerrorMeleeWeapon = 231,
	CTerrorGun = 230,
	CTankClaw = 187,
	CSubMachinegun = 182,
	CSpitterProjectile = 176,
	CSpitterClaw = 175,
	CSniperRifle = 172,
	CSniper_Scout = 171,
	CSniper_Military = 170,
	CSniper_AWP = 169,
	CSmokerClaw = 167,
	CSMG_Silenced = 166,
	CSMG_MP5 = 165,
	CShotgun_SPAS = 163,
	CShotgun_Chrome = 162,
	CRifle_SG552 = 155,
	CRifle_M60 = 154,
	CRifle_Desert = 153,
	CRifle_AK47 = 152,
	CPumpShotgun = 148,
	CPropaneTank = 142,
	CMagnumPistol = 116,
	CPistol = 131,
	CPipeBombProjectile = 130,
	CPipeBomb = 129,
	CPainPills = 121,
	COxygenTank = 120,
	CBaseMountedWeapon = 18,
	CPropMountedGun = 146,
	CMolotovProjectile = 119,
	CMolotov = 118,
	CPropMinigun = 145,
	CJockeyClaw = 112,
	CItem_VomitJar = 106,
	CItemUpgradePackIncendiary = 111,
	CItemUpgradePackExplosive = 110,
	CItemDefibrillator = 109,
	CItemBaseUpgradePack = 108,
	CItemAmmoPack = 107,
	CItem_Adrenaline = 105,
	CHunterClaw = 100,
	CGrenadeLauncher_Projectile = 97,
	CGrenadeLauncher = 96,
	CGnome = 95,
	CGasCan = 94,
	CFirstAidKit = 73,
	CFireworkCrate = 72,
	CColaBottles = 44,
	CClaw = 42,
	CChargerClaw = 41,
	CChainsaw = 39,
	CPointPropUseTarget = 135,
	CTEBullets = 206,
	CBoomerClaw = 34,
	CBaseSniperRifle = 24,
	CBaseShotgun = 23,
	CBaseRifle = 22,
	CBaseBeltItem = 8,
	CBaseBackpackItem = 7,
	CBaseAutoShotgun = 6,
	CAutoShotgun = 2,
	CAssaultRifle = 1,
	SurvivorBot = 275,
	NextBotCombatCharacter = 267,
	CFireCrackerBlast = 69,
	CInsectSwarm = 104,
	CInferno = 101,
	CVomit = 251,
	CTongue = 246,
	CThrow = 245,
	CSpitAbility = 174,
	CSelfDestruct = 160,
	CLunge = 115,
	CLeap = 113,
	CCharge = 40,
	CBaseAbility = 3,
	CTutorLesson = 249,
	CTransitioningPlayer = 247,
	CTerrorViewModel = 234,
	CFuncRagdollFader = 87,
	CTerrorGameRulesProxy = 229,
	CSurvivorPosition = 185,
	CScavengeProgressDisplay = 157,
	CPropHealthCabinet = 144,
	CFinaleTrigger = 68,
	CClientPath = 43,
	CTerrorPlayerResource = 233,
	CTerrorPlayer = 232,
	CSurvivorRescue = 186,
	CSurvivorDeathModel = 184,
	CBaseUpgradeItem = 29,
	CWeaponScavengeItemSpawn = 259,
	CWeaponAmmoSpawn = 256,
	CWeaponSpawn = 260,
	CTeamTrainWatcher = 0,
	CSoundMixLayer = 173,
	CPointScriptUseTarget = 136,
	CEnvWeaponFire = 66,
	CWeaponCSBaseGun = 258,
	CWeaponCSBase = 257,
	CBaseCSGrenade = 12,
	CCSGameRulesProxy = 47,
	CWeaponCubemap = 0,
	CWeaponCycler = 0,
	CPlantedC4 = 0,
	CCSTeam = 50,
	CCSPlayer = 48,
	CCSRagdoll = 49,
	CTEPlayerAnimEvent = 226,
	CBaseCSGrenadeProjectile = 13,
	CTestTraceline = 243,
	CTEWorldDecal = 244,
	CTESpriteSpray = 241,
	CTESprite = 240,
	CTESparks = 239,
	CTESmoke = 238,
	CTEShowLine = 237,
	CTEProjectedDecal = 228,
	CTEPlayerDecal = 227,
	CTEPhysicsProp = 225,
	CTEParticleSystem = 224,
	CTEMuzzleFlash = 223,
	CTELargeFunnel = 221,
	CTEKillPlayerAttachments = 220,
	CTEImpact = 219,
	CTEGlowSprite = 218,
	CTEShatterSurface = 236,
	CTEFootprintDecal = 215,
	CTEFizz = 214,
	CTEExplosion = 213,
	CTEEnergySplash = 212,
	CTEEffectDispatch = 211,
	CTEDynamicLight = 210,
	CTEDecal = 208,
	CTEClientProjectile = 207,
	CTEBubbleTrail = 205,
	CTEBubbles = 204,
	CTEBSPDecal = 203,
	CTEBreakModel = 202,
	CTEBloodStream = 201,
	CTEBloodSprite = 200,
	CTEBeamSpline = 199,
	CTEBeamRingPoint = 198,
	CTEBeamRing = 197,
	CTEBeamPoints = 196,
	CTEBeamLaser = 195,
	CTEBeamFollow = 194,
	CTEBeamEnts = 193,
	CTEBeamEntPoint = 192,
	CTEBaseBeam = 191,
	CTEArmorRicochet = 190,
	CTEMetalSparks = 222,
	CSteamJet = 181,
	CSmokeStack = 168,
	DustTrail = 262,
	CFireTrail = 71,
	SporeTrail = 274,
	SporeExplosion = 273,
	RocketTrail = 269,
	SmokeTrail = 271,
	CPropVehicleDriveable = 147,
	ParticleSmokeGrenade = 268,
	CParticleFire = 122,
	MovieExplosion = 266,
	CTEGaussExplosion = 217,
	CEnvQuadraticBeam = 62,
	CEmbers = 53,
	CEnvWind = 67,
	CPrecipitation = 139,
	CPrecipitationBlocker = 140,
	CBaseTempEntity = 26,
	CHandleTest = 98,
	CTeamplayRoundBasedRulesProxy = 189,
	CSpriteTrail = 180,
	CSpriteOriented = 179,
	CSprite = 178,
	CRagdollPropAttached = 151,
	CRagdollProp = 150,
	CPredictedViewModel = 141,
	CPoseController = 137,
	CGameRulesProxy = 93,
	CFuncSimpleLadder = 90,
	CInfoLadderDismount = 102,
	CFuncLadder = 82,
	CTEFoundryHelpers = 216,
	CEnvDetailController = 57,
	CWorld = 261,
	CWaterLODControl = 255,
	CWaterBullet = 254,
	CVoteController = 253,
	CVGuiScreen = 250,
	CPropJeep = 0,
	CPropVehicleChoreoGeneric = 0,
	CFuncPlayerGhostInfectedClip = 85,
	CFuncPlayerInfectedClip = 86,
	CTriggerPlayerMovement = 248,
	CBaseTrigger = 28,
	CTest_ProxyToggle_Networkable = 242,
	CBaseTeamObjectiveResource = 25,
	CTeam = 188,
	CFlare = 0,
	CSun = 183,
	CParticlePerformanceMonitor = 123,
	CSpotlightEnd = 177,
	CSlideshowDisplay = 164,
	CShadowControl = 161,
	CSceneEntity = 158,
	CRopeKeyframe = 156,
	CRagdollManager = 149,
	CPhysBoxMultiplayer = 126,
	CPropDoorRotatingCheckpoint = 143,
	CBasePropDoor = 21,
	CDynamicProp = 52,
	CPostProcessController = 138,
	CPointCommentaryNode = 134,
	CPlayerResource = 133,
	CPlasma = 132,
	CPhysMagnet = 128,
	CPhysicsProp = 127,
	CBreakable = 35,
	CPhysBox = 125,
	CParticleSystem = 124,
	CMaterialModifyControl = 117,
	CLightGlow = 114,
	CInfoOverlayAccessor = 103,
	CFuncTrackTrain = 92,
	CFuncSmokeVolume = 91,
	CFuncRotating = 89,
	CFuncReflectiveGlass = 88,
	CFuncOccluder = 84,
	CFuncMoveLinear = 83,
	CFuncMonitor = 0,
	CFunc_LOD = 77,
	CFuncElevator = 81,
	CTEDust = 209,
	CFunc_Dust = 76,
	CFuncConveyor = 80,
	CFuncBrush = 79,
	CBreakableSurface = 37,
	CFuncAreaPortalWindow = 78,
	CFish = 74,
	CFireSmoke = 70,
	CEnvTonemapController = 65,
	CEnvScreenEffect = 63,
	CEnvScreenOverlay = 64,
	CEnvProjectedTexture = 61,
	CEnvParticleScript = 59,
	CFogController = 75,
	CEnvDOFController = 58,
	CEnvPhysicsBlocker = 60,
	CEntityParticleTrail = 56,
	CEntityFlame = 55,
	CEntityDissolve = 54,
	CDynamicLight = 51,
	CColorCorrectionVolume = 46,
	CColorCorrection = 45,
	CBreakableProp = 36,
	CBeamSpotlight = 32,
	CButtonTimed = 38,
	CScriptBaseButton = 159,
	CBaseButton = 9,
	CBaseToggle = 27,
	CBasePlayer = 20,
	CBaseFlex = 16,
	CBaseEntity = 15,
	CBaseDoor = 14,
	CBaseCombatCharacter = 10,
	CBaseAnimatingOverlay = 5,
	CBoneFollower = 33,
	CBaseAnimating = 4,
	CAI_BaseNPC = 0,
	CBeam = 31,
	CBaseViewModel = 30,
	CBaseParticleEntity = 19,
	CBaseGrenade = 17,
	CBaseCombatWeapon = 11
};

//24.12.2021
enum EWeaponID {
	WEAPON_PISTOL = 1,
	WEAPON_UZI,
	WEAPON_PUMP_SHOTGUN,
	WEAPON_AUTO_SHOTGUN,
	WEAPON_M16A1,
	WEAPON_HUNTING_RIFLE,
	WEAPON_MAC10,
	WEAPON_CHROME_SHOTGUN,
	WEAPON_SCAR,
	WEAPON_MILITARY_SNIPER,
	WEAPON_SPAS,
	WEAPON_FIRSTAID_KIT,
	WEAPON_MOLOTOV,
	WEAPON_PIPEBOMB,
	WEAPON_PAINPILLS,
	WEAPON_GASCAN,
	WEAPON_PROPANE_TANK,
	WEAPON_OXYGEN_TANK,
	WEAPON_MELEE,
	WEAPON_CHAINSAW,
	WEAPON_GRENADE_LAUNCHER,
	WEAPON_ADRENALINE = 23,
	WEAPON_DEFIBRILLATOR,
	WEAPON_VOMITJAR,
	WEAPON_AK47,
	WEAPON_UPGRADEPACK_INCENDIARY = 30,
	WEAPON_UPGRADEPACK_EXPLOSIVE,
	WEAPON_DEAGLE,
	WEAPON_MP5,
	WEAPON_SSG552,
	WEAPON_AWP,
	WEAPON_SCOUT,
	WEAPON_M60,

	WEAPON_MAX
};

//26.12.2021
enum EZombieclass {
	CLASS_UNKNOWN,
	CLASS_SMOKER,
	CLASS_BOOMER,
	CLASS_HUNTER,
	CLASS_SPITTER,
	CLASS_JOCKEY,
	CLASS_CHARGER,
	CLASS_TANK = 8,
	CLASS_SURVIVOR //From what I saw, m_zombieClass was always 9 on survivors.
};

enum ClientFrameStage_t {
	FRAME_UNDEFINED = -1,
	FRAME_START,
	FRAME_NET_UPDATE_START,
	FRAME_NET_UPDATE_POSTDATAUPDATE_START,
	FRAME_NET_UPDATE_POSTDATAUPDATE_END,
	FRAME_NET_UPDATE_END,
	FRAME_RENDER_START,
	FRAME_RENDER_END
};

enum MaterialThreadMode_t {
	MATERIAL_SINGLE_THREADED,
	MATERIAL_QUEUED_SINGLE_THREADED,
	MATERIAL_QUEUED_THREADED
};

enum NormalDecodeMode_t {
	NORMAL_DECODE_NONE = 0,
	NORMAL_DECODE_ATI2N = 1,
	NORMAL_DECODE_ATI2N_ALPHA = 2
};

enum MaterialVarType_t {
	MATERIAL_VAR_TYPE_FLOAT = 0,
	MATERIAL_VAR_TYPE_STRING,
	MATERIAL_VAR_TYPE_VECTOR,
	MATERIAL_VAR_TYPE_TEXTURE,
	MATERIAL_VAR_TYPE_INT,
	MATERIAL_VAR_TYPE_FOURCC,
	MATERIAL_VAR_TYPE_UNDEFINED,
	MATERIAL_VAR_TYPE_MATRIX,
	MATERIAL_VAR_TYPE_MATERIAL
};

enum MoveType_t {
	MOVETYPE_NONE = 0,
	MOVETYPE_ISOMETRIC,
	MOVETYPE_WALK,
	MOVETYPE_STEP,
	MOVETYPE_FLY,
	MOVETYPE_FLYGRAVITY,
	MOVETYPE_VPHYSICS,
	MOVETYPE_PUSH,
	MOVETYPE_NOCLIP,
	MOVETYPE_LADDER,
	MOVETYPE_OBSERVER,
	MOVETYPE_CUSTOM,
	MOVETYPE_LAST = MOVETYPE_CUSTOM,
	MOVETYPE_MAX_BITS = 4
};


enum MaterialVarFlags_t {
	MATERIAL_VAR_DEBUG = (1 << 0),
	MATERIAL_VAR_NO_DEBUG_OVERRIDE = (1 << 1),
	MATERIAL_VAR_NO_DRAW = (1 << 2),
	MATERIAL_VAR_USE_IN_FILLRATE_MODE = (1 << 3),
	MATERIAL_VAR_VERTEXCOLOR = (1 << 4),
	MATERIAL_VAR_VERTEXALPHA = (1 << 5),
	MATERIAL_VAR_SELFILLUM = (1 << 6),
	MATERIAL_VAR_ADDITIVE = (1 << 7),
	MATERIAL_VAR_ALPHATEST = (1 << 8),
	MATERIAL_VAR_MULTIPASS = (1 << 9),
	MATERIAL_VAR_ZNEARER = (1 << 10),
	MATERIAL_VAR_MODEL = (1 << 11),
	MATERIAL_VAR_FLAT = (1 << 12),
	MATERIAL_VAR_NOCULL = (1 << 13),
	MATERIAL_VAR_NOFOG = (1 << 14),
	MATERIAL_VAR_IGNOREZ = (1 << 15),
	MATERIAL_VAR_DECAL = (1 << 16),
	MATERIAL_VAR_ENVMAPSPHERE = (1 << 17),
	MATERIAL_VAR_NOALPHAMOD = (1 << 18),
	MATERIAL_VAR_ENVMAPCAMERASPACE = (1 << 19),
	MATERIAL_VAR_BASEALPHAENVMAPMASK = (1 << 20),
	MATERIAL_VAR_TRANSLUCENT = (1 << 21),
	MATERIAL_VAR_NORMALMAPALPHAENVMAPMASK = (1 << 22),
	MATERIAL_VAR_NEEDS_SOFTWARE_SKINNING = (1 << 23),
	MATERIAL_VAR_OPAQUETEXTURE = (1 << 24),
	MATERIAL_VAR_ENVMAPMODE = (1 << 25),
	MATERIAL_VAR_SUPPRESS_DECALS = (1 << 26),
	MATERIAL_VAR_HALFLAMBERT = (1 << 27),
	MATERIAL_VAR_WIREFRAME = (1 << 28),
	MATERIAL_VAR_ALLOWALPHATOCOVERAGE = (1 << 29)
};

enum PreviewImageRetVal_t {
	MATERIAL_PREVIEW_IMAGE_BAD = 0,
	MATERIAL_PREVIEW_IMAGE_OK,
	MATERIAL_NO_PREVIEW_IMAGE
};

enum MaterialPropertyTypes_t {
	MATERIAL_PROPERTY_NEEDS_LIGHTMAP = 0,
	MATERIAL_PROPERTY_OPACITY,
	MATERIAL_PROPERTY_REFLECTIVITY,
	MATERIAL_PROPERTY_NEEDS_BUMPED_LIGHTMAPS
};

enum ImageFormat {
	IMAGE_FORMAT_UNKNOWN = -1,
	IMAGE_FORMAT_RGBA8888 = 0,
	IMAGE_FORMAT_ABGR8888,
	IMAGE_FORMAT_RGB888,
	IMAGE_FORMAT_BGR888,
	IMAGE_FORMAT_RGB565,
	IMAGE_FORMAT_I8,
	IMAGE_FORMAT_IA88,
	IMAGE_FORMAT_P8,
	IMAGE_FORMAT_A8,
	IMAGE_FORMAT_RGB888_BLUESCREEN,
	IMAGE_FORMAT_BGR888_BLUESCREEN,
	IMAGE_FORMAT_ARGB8888,
	IMAGE_FORMAT_BGRA8888,
	IMAGE_FORMAT_DXT1,
	IMAGE_FORMAT_DXT3,
	IMAGE_FORMAT_DXT5,
	IMAGE_FORMAT_BGRX8888,
	IMAGE_FORMAT_BGR565,
	IMAGE_FORMAT_BGRX5551,
	IMAGE_FORMAT_BGRA4444,
	IMAGE_FORMAT_DXT1_ONEBITALPHA,
	IMAGE_FORMAT_BGRA5551,
	IMAGE_FORMAT_UV88,
	IMAGE_FORMAT_UVWQ8888,
	IMAGE_FORMAT_RGBA16161616F,
	IMAGE_FORMAT_RGBA16161616,
	IMAGE_FORMAT_UVLX8888,
	IMAGE_FORMAT_R32F,
	IMAGE_FORMAT_RGB323232F,
	IMAGE_FORMAT_RGBA32323232F,
	IMAGE_FORMAT_NV_DST16,
	IMAGE_FORMAT_NV_DST24,
	IMAGE_FORMAT_NV_INTZ,
	IMAGE_FORMAT_NV_RAWZ,
	IMAGE_FORMAT_ATI_DST16,
	IMAGE_FORMAT_ATI_DST24,
	IMAGE_FORMAT_NV_NULL,
	IMAGE_FORMAT_ATI2N,
	IMAGE_FORMAT_ATI1N,
	IMAGE_FORMAT_DXT1_RUNTIME,
	IMAGE_FORMAT_DXT5_RUNTIME,
	NUM_IMAGE_FORMATS
};

enum RenderTargetSizeMode_t {
	RT_SIZE_NO_CHANGE = 0,
	RT_SIZE_DEFAULT = 1,
	RT_SIZE_PICMIP = 2,
	RT_SIZE_HDR = 3,
	RT_SIZE_FULL_FRAME_BUFFER = 4,
	RT_SIZE_OFFSCREEN = 5,
	RT_SIZE_FULL_FRAME_BUFFER_ROUNDED_UP = 6
};

enum MaterialRenderTargetDepth_t {
	MATERIAL_RT_DEPTH_SHARED = 0x0,
	MATERIAL_RT_DEPTH_SEPARATE = 0x1,
	MATERIAL_RT_DEPTH_NONE = 0x2,
	MATERIAL_RT_DEPTH_ONLY = 0x3
};

enum MaterialContextType_t {
	MATERIAL_HARDWARE_CONTEXT,
	MATERIAL_QUEUED_CONTEXT,
	MATERIAL_NULL_CONTEXT
};

enum CompiledVtfFlags {
	TEXTUREFLAGS_POINTSAMPLE = 0x00000001,
	TEXTUREFLAGS_TRILINEAR = 0x00000002,
	TEXTUREFLAGS_CLAMPS = 0x00000004,
	TEXTUREFLAGS_CLAMPT = 0x00000008,
	TEXTUREFLAGS_ANISOTROPIC = 0x00000010,
	TEXTUREFLAGS_HINT_DXT5 = 0x00000020,
	TEXTUREFLAGS_SRGB = 0x00000040,
	TEXTUREFLAGS_NORMAL = 0x00000080,
	TEXTUREFLAGS_NOMIP = 0x00000100,
	TEXTUREFLAGS_NOLOD = 0x00000200,
	TEXTUREFLAGS_ALL_MIPS = 0x00000400,
	TEXTUREFLAGS_PROCEDURAL = 0x00000800,
	TEXTUREFLAGS_ONEBITALPHA = 0x00001000,
	TEXTUREFLAGS_EIGHTBITALPHA = 0x00002000,
	TEXTUREFLAGS_ENVMAP = 0x00004000,
	TEXTUREFLAGS_RENDERTARGET = 0x00008000,
	TEXTUREFLAGS_DEPTHRENDERTARGET = 0x00010000,
	TEXTUREFLAGS_NODEBUGOVERRIDE = 0x00020000,
	TEXTUREFLAGS_SINGLECOPY = 0x00040000,
	TEXTUREFLAGS_UNUSED_00080000 = 0x00080000,
	TEXTUREFLAGS_UNUSED_00100000 = 0x00100000,
	TEXTUREFLAGS_UNUSED_00200000 = 0x00200000,
	TEXTUREFLAGS_UNUSED_00400000 = 0x00400000,
	TEXTUREFLAGS_NODEPTHBUFFER = 0x00800000,
	TEXTUREFLAGS_UNUSED_01000000 = 0x01000000,
	TEXTUREFLAGS_CLAMPU = 0x02000000,
	TEXTUREFLAGS_VERTEXTEXTURE = 0x04000000,
	TEXTUREFLAGS_SSBUMP = 0x08000000,
	TEXTUREFLAGS_UNUSED_10000000 = 0x10000000,
	TEXTUREFLAGS_BORDER = 0x20000000,
	TEXTUREFLAGS_UNUSED_40000000 = 0x40000000,
	TEXTUREFLAGS_UNUSED_80000000 = 0x80000000
};

enum LightType_t {
	MATERIAL_LIGHT_DISABLE = 0,
	MATERIAL_LIGHT_POINT,
	MATERIAL_LIGHT_DIRECTIONAL,
	MATERIAL_LIGHT_SPOT
};

enum MaterialCullMode_t {
	MATERIAL_CULLMODE_CCW,
	MATERIAL_CULLMODE_CW
};

enum MaterialFogMode_t {
	MATERIAL_FOG_NONE,
	MATERIAL_FOG_LINEAR,
	MATERIAL_FOG_LINEAR_BELOW_FOG_Z
};

enum MaterialHeightClipMode_t {
	MATERIAL_HEIGHTCLIPMODE_DISABLE,
	MATERIAL_HEIGHTCLIPMODE_RENDER_ABOVE_HEIGHT,
	MATERIAL_HEIGHTCLIPMODE_RENDER_BELOW_HEIGHT
};

enum MaterialMatrixMode_t {
	MATERIAL_VIEW = 0,
	MATERIAL_PROJECTION,
	MATERIAL_TEXTURE0,
	MATERIAL_TEXTURE1,
	MATERIAL_TEXTURE2,
	MATERIAL_TEXTURE3,
	MATERIAL_TEXTURE4,
	MATERIAL_TEXTURE5,
	MATERIAL_TEXTURE6,
	MATERIAL_TEXTURE7,
	MATERIAL_MODEL,
	NUM_MATRIX_MODES = MATERIAL_MODEL + 1,
	NUM_TEXTURE_TRANSFORMS = MATERIAL_TEXTURE7 - MATERIAL_TEXTURE0 + 1
};

enum StencilOperation_t {
	STENCILOPERATION_KEEP = 1,
	STENCILOPERATION_ZERO = 2,
	STENCILOPERATION_REPLACE = 3,
	STENCILOPERATION_INCRSAT = 4,
	STENCILOPERATION_DECRSAT = 5,
	STENCILOPERATION_INVERT = 6,
	STENCILOPERATION_INCR = 7,
	STENCILOPERATION_DECR = 8
};

enum StencilComparisonFunction_t {
	STENCILCOMPARISONFUNCTION_NEVER = 1,
	STENCILCOMPARISONFUNCTION_LESS = 2,
	STENCILCOMPARISONFUNCTION_EQUAL = 3,
	STENCILCOMPARISONFUNCTION_LESSEQUAL = 4,
	STENCILCOMPARISONFUNCTION_GREATER = 5,
	STENCILCOMPARISONFUNCTION_NOTEQUAL = 6,
	STENCILCOMPARISONFUNCTION_GREATEREQUAL = 7,
	STENCILCOMPARISONFUNCTION_ALWAYS = 8
};

enum OverrideType_t {
	OVERRIDE_NORMAL = 0,
	OVERRIDE_BUILD_SHADOWS,
	OVERRIDE_DEPTH_WRITE,
	OVERRIDE_SSAO_DEPTH_WRITE
};

enum {
	EF_BONEMERGE = 0x001,
	EF_BRIGHTLIGHT = 0x002,
	EF_DIMLIGHT = 0x004,
	EF_NOINTERP = 0x008,
	EF_NOSHADOW = 0x010,
	EF_NODRAW = 0x020,
	EF_NORECEIVESHADOW = 0x040,
	EF_BONEMERGE_FASTCULL = 0x080,
	EF_ITEM_BLINK = 0x100,
	EF_PARENT_ANIMATES = 0x200,
	EF_MAX_BITS = 10
};

enum SolidFlags_t {
	FSOLID_CUSTOMRAYTEST = 0x0001,
	FSOLID_CUSTOMBOXTEST = 0x0002,
	FSOLID_NOT_SOLID = 0x0004,
	FSOLID_TRIGGER = 0x0008,
	FSOLID_NOT_STANDABLE = 0x0010,
	FSOLID_VOLUME_CONTENTS = 0x0020,
	FSOLID_FORCE_WORLD_ALIGNED = 0x0040,
	FSOLID_USE_TRIGGER_BOUNDS = 0x0080,
	FSOLID_ROOT_PARENT_ALIGNED = 0x0100,
	FSOLID_TRIGGER_TOUCH_DEBRIS = 0x0200,

	FSOLID_MAX_BITS = 10
};

enum {
	TEAM_SURVIVOR = 2,
	TEAM_INFECTED
};

enum {
	MATERIAL_ADAPTER_NAME_LENGTH = 512
};

enum {
	ADDDECAL_TO_ALL_LODS = -1
};

#define SURVIVORSET_L4D1 1

#define	FL_ONGROUND		(1 << 0)
#define FL_DUCKING		(1 << 1)
#define	FL_WATERJUMP	(1 << 2)
#define FL_ONTRAIN		(1 << 3)
#define FL_INRAIN		(1 << 4)
#define FL_FROZEN		(1 << 5)
#define FL_ATCONTROLS	(1 << 6)
#define	FL_CLIENT		(1 << 7)
#define FL_FAKECLIENT	(1 << 8)
#define	FL_INWATER		(1 << 9)

#define IN_ATTACK		(1 << 0)
#define IN_JUMP			(1 << 1)
#define IN_DUCK			(1 << 2)
#define IN_FORWARD		(1 << 3)
#define IN_BACK			(1 << 4)
#define IN_USE			(1 << 5)
#define IN_CANCEL		(1 << 6)
#define IN_LEFT			(1 << 7)
#define IN_RIGHT		(1 << 8)
#define IN_MOVELEFT		(1 << 9)
#define IN_MOVERIGHT	(1 << 10)
#define IN_ATTACK2		(1 << 11)
#define IN_RUN			(1 << 12)
#define IN_RELOAD		(1 << 13)
#define IN_ALT1			(1 << 14)
#define IN_ALT2			(1 << 15)
#define IN_SCORE		(1 << 16)
#define IN_SPEED		(1 << 17)
#define IN_WALK			(1 << 18)
#define IN_ZOOM			(1 << 19)
#define IN_WEAPON1		(1 << 20)
#define IN_WEAPON2		(1 << 21)
#define IN_BULLRUSH		(1 << 22)
#define IN_GRENADE1		(1 << 23)
#define IN_GRENADE2		(1 << 24)
#define	IN_ATTACK3		(1 << 25)

#define	MAX_EDICT_BITS				11
#define	MAX_EDICTS					(1<<MAX_EDICT_BITS)
#define MAX_SERVER_CLASS_BITS		9
#define MAX_SERVER_CLASSES			(1<<MAX_SERVER_CLASS_BITS)
#define NUM_ENT_ENTRY_BITS			(MAX_EDICT_BITS + 1)
#define NUM_ENT_ENTRIES				(1 << NUM_ENT_ENTRY_BITS)
#define ENT_ENTRY_MASK				(NUM_ENT_ENTRIES - 1)
#define INVALID_EHANDLE_INDEX		0xFFFFFFFF
#define NUM_SERIAL_NUM_BITS			(32 - NUM_ENT_ENTRY_BITS)

#define CREATERENDERTARGETFLAGS_HDR		0x00000001

#define STUDIO_NONE						0x00000000
#define STUDIO_RENDER					0x00000001
#define STUDIO_VIEWXFORMATTACHMENTS		0x00000002
#define STUDIO_DRAWTRANSLUCENTSUBMODELS 0x00000004
#define STUDIO_TWOPASS					0x00000008
#define STUDIO_STATIC_LIGHTING			0x00000010
#define STUDIO_WIREFRAME				0x00000020
#define STUDIO_ITEM_BLINK				0x00000040
#define STUDIO_NOSHADOWS				0x00000080
#define STUDIO_WIREFRAME_VCOLLIDE		0x00000100
#define STUDIO_GENERATE_STATS			0x01000000
#define STUDIO_SSAODEPTHTEXTURE			0x08000000
#define STUDIO_SHADOWDEPTHTEXTURE		0x40000000
#define STUDIO_TRANSPARENCY				0x80000000

#define	HITGROUP_GENERIC	0
#define	HITGROUP_HEAD		1
#define	HITGROUP_CHEST		2
#define	HITGROUP_STOMACH	3
#define HITGROUP_LEFTARM	4	
#define HITGROUP_RIGHTARM	5
#define HITGROUP_LEFTLEG	6
#define HITGROUP_RIGHTLEG	7
#define HITGROUP_GEAR		10

#define	CONTENTS_EMPTY			0
#define	CONTENTS_SOLID			0x1
#define	CONTENTS_WINDOW			0x2
#define	CONTENTS_AUX			0x4
#define	CONTENTS_GRATE			0x8
#define	CONTENTS_SLIME			0x10
#define	CONTENTS_WATER			0x20
#define	CONTENTS_BLOCKLOS		0x40
#define CONTENTS_OPAQUE			0x80
#define	LAST_VISIBLE_CONTENTS	0x80
#define ALL_VISIBLE_CONTENTS (LAST_VISIBLE_CONTENTS | (LAST_VISIBLE_CONTENTS-1))
#define CONTENTS_TESTFOGVOLUME	0x100
#define CONTENTS_UNUSED			0x200	
#define CONTENTS_UNUSED6		0x400
#define CONTENTS_TEAM1			0x800
#define CONTENTS_TEAM2			0x1000
#define CONTENTS_IGNORE_NODRAW_OPAQUE	0x2000
#define CONTENTS_MOVEABLE		0x4000
#define	CONTENTS_AREAPORTAL		0x8000
#define	CONTENTS_PLAYERCLIP		0x10000
#define	CONTENTS_MONSTERCLIP	0x20000
#define	CONTENTS_CURRENT_0		0x40000
#define	CONTENTS_CURRENT_90		0x80000
#define	CONTENTS_CURRENT_180	0x100000
#define	CONTENTS_CURRENT_270	0x200000
#define	CONTENTS_CURRENT_UP		0x400000
#define	CONTENTS_CURRENT_DOWN	0x800000
#define	CONTENTS_ORIGIN			0x1000000
#define	CONTENTS_MONSTER		0x2000000
#define	CONTENTS_DEBRIS			0x4000000
#define	CONTENTS_DETAIL			0x8000000
#define	CONTENTS_TRANSLUCENT	0x10000000
#define	CONTENTS_LADDER			0x20000000
#define CONTENTS_HITBOX			0x40000000

#define	MASK_ALL					(0xFFFFFFFF)
#define	MASK_SOLID					(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_WINDOW|CONTENTS_MONSTER|CONTENTS_GRATE)
#define	MASK_PLAYERSOLID			(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_PLAYERCLIP|CONTENTS_WINDOW|CONTENTS_MONSTER|CONTENTS_GRATE)
#define	MASK_NPCSOLID				(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_MONSTERCLIP|CONTENTS_WINDOW|CONTENTS_MONSTER|CONTENTS_GRATE)
#define	MASK_WATER					(CONTENTS_WATER|CONTENTS_MOVEABLE|CONTENTS_SLIME)
#define	MASK_OPAQUE					(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_OPAQUE)
#define MASK_OPAQUE_AND_NPCS		(MASK_OPAQUE|CONTENTS_MONSTER)
#define MASK_BLOCKLOS				(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_BLOCKLOS)
#define MASK_BLOCKLOS_AND_NPCS		(MASK_BLOCKLOS|CONTENTS_MONSTER)
#define	MASK_VISIBLE				(MASK_OPAQUE|CONTENTS_IGNORE_NODRAW_OPAQUE)
#define MASK_VISIBLE_AND_NPCS		(MASK_OPAQUE_AND_NPCS|CONTENTS_IGNORE_NODRAW_OPAQUE)
#define	MASK_SHOT					(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_MONSTER|CONTENTS_WINDOW|CONTENTS_DEBRIS|CONTENTS_HITBOX)
#define MASK_SHOT_HULL				(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_MONSTER|CONTENTS_WINDOW|CONTENTS_DEBRIS|CONTENTS_GRATE)
#define MASK_SHOT_PORTAL			(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_WINDOW|CONTENTS_MONSTER)
#define MASK_SOLID_BRUSHONLY		(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_WINDOW|CONTENTS_GRATE)
#define MASK_PLAYERSOLID_BRUSHONLY	(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_WINDOW|CONTENTS_PLAYERCLIP|CONTENTS_GRATE)
#define MASK_NPCSOLID_BRUSHONLY		(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_WINDOW|CONTENTS_MONSTERCLIP|CONTENTS_GRATE)
#define MASK_NPCWORLDSTATIC			(CONTENTS_SOLID|CONTENTS_WINDOW|CONTENTS_MONSTERCLIP|CONTENTS_GRATE)
#define MASK_SPLITAREAPORTAL		(CONTENTS_WATER|CONTENTS_SLIME)
#define MASK_CURRENT				(CONTENTS_CURRENT_0|CONTENTS_CURRENT_90|CONTENTS_CURRENT_180|CONTENTS_CURRENT_270|CONTENTS_CURRENT_UP|CONTENTS_CURRENT_DOWN)
#define	MASK_DEADSOLID				(CONTENTS_SOLID|CONTENTS_PLAYERCLIP|CONTENTS_WINDOW|CONTENTS_GRATE)

#define TEXTURE_GROUP_LIGHTMAP						"Lightmaps"
#define TEXTURE_GROUP_WORLD							"World textures"
#define TEXTURE_GROUP_MODEL							"Model textures"
#define TEXTURE_GROUP_VGUI							"VGUI textures"
#define TEXTURE_GROUP_PARTICLE						"Particle textures"
#define TEXTURE_GROUP_DECAL							"Decal textures"
#define TEXTURE_GROUP_SKYBOX						"SkyBox textures"
#define TEXTURE_GROUP_CLIENT_EFFECTS				"ClientEffect textures"
#define TEXTURE_GROUP_OTHER							"Other textures"
#define TEXTURE_GROUP_PRECACHED						"Precached"
#define TEXTURE_GROUP_CUBE_MAP						"CubeMap textures"
#define TEXTURE_GROUP_RENDER_TARGET					"RenderTargets"
#define TEXTURE_GROUP_UNACCOUNTED					"Unaccounted textures"
#define TEXTURE_GROUP_STATIC_INDEX_BUFFER			"Static Indices"
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_DISP		"Displacement Verts"
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_COLOR	"Lighting Verts"
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_WORLD	"World Verts"
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_MODELS	"Model Verts"
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_OTHER	"Other Verts"
#define TEXTURE_GROUP_DYNAMIC_INDEX_BUFFER			"Dynamic Indices"
#define TEXTURE_GROUP_DYNAMIC_VERTEX_BUFFER			"Dynamic Verts"
#define TEXTURE_GROUP_DEPTH_BUFFER					"DepthBuffer"
#define TEXTURE_GROUP_VIEW_MODEL					"ViewModel"
#define TEXTURE_GROUP_PIXEL_SHADERS					"Pixel Shaders"
#define TEXTURE_GROUP_VERTEX_SHADERS				"Vertex Shaders"
#define TEXTURE_GROUP_RENDER_TARGET_SURFACE			"RenderTarget Surfaces"
#define TEXTURE_GROUP_MORPH_TARGETS					"Morph Targets"

struct RenderableInstance_t {
	uint8_t m_nAlpha;
};

class KeyValues {
public:
	char __pad00[36];
};

struct MaterialAdapterInfo_t {
	char m_pDriverName[MATERIAL_ADAPTER_NAME_LENGTH];
	unsigned int m_VendorID;
	unsigned int m_DeviceID;
	unsigned int m_SubSysID;
	unsigned int m_Revision;
	int m_nDXSupportLevel;
	int m_nMaxDXSupportLevel;
	unsigned int m_nDriverVersionHigh;
	unsigned int m_nDriverVersionLow;
};

struct MaterialVideoMode_t {
	int m_Width;
	int m_Height;
	ImageFormat m_Format;
	int m_RefreshRate;
};

struct LightDesc_t {
	LightType_t m_Type;
	Vector m_Color;
	Vector m_Position;
	Vector m_Direction;
	float  m_Range;
	float m_Falloff;
	float m_Attenuation0;
	float m_Attenuation1;
	float m_Attenuation2;
	float m_Theta;
	float m_Phi;
	float m_ThetaDot;
	float m_PhiDot;
	unsigned int m_Flags;
	float OneOver_ThetaDot_Minus_PhiDot;
	float m_RangeSquared;
};

struct ShaderStencilState_t {
	bool m_bEnable;
	StencilOperation_t m_FailOp;
	StencilOperation_t m_ZFailOp;
	StencilOperation_t m_PassOp;
	StencilComparisonFunction_t m_CompareFunc;
	int m_nReferenceValue;
	uint32_t m_nTestMask;
	uint32_t m_nWriteMask;

	ShaderStencilState_t() {
		m_bEnable = false;
		m_PassOp = m_FailOp = m_ZFailOp = STENCILOPERATION_KEEP;
		m_CompareFunc = STENCILCOMPARISONFUNCTION_ALWAYS;
		m_nReferenceValue = 0;
		m_nTestMask = m_nWriteMask = 0xFFFFFFFF;
	}
};

struct DrawModelState_t {
	studiohdr_t* m_pStudioHdr;
	void* m_pStudioHWData;
	IClientRenderable* m_pRenderable;
	const matrix3x4_t* m_pModelToWorld;
	void* m_decals;
	int	m_drawFlags;
	int	m_lod;
};

struct ModelRenderInfo_t {
	Vector origin;
	Vector angles;
	IClientRenderable* pRenderable;
	const void* pModel;
	const matrix3x4_t* pModelToWorld;
	const matrix3x4_t* pLightingOffset;
	const Vector* pLightingOrigin;
	int flags;
	int entity_index;
	int skin;
	int body;
	int hitboxset;
	unsigned short instance;

	ModelRenderInfo_t()
	{
		pModelToWorld = NULL;
		pLightingOffset = NULL;
		pLightingOrigin = NULL;
	}
};

struct StaticPropRenderInfo_t {
	const matrix3x4_t* pModelToWorld;
	const void* pModel;
	IClientRenderable* pRenderable;
	Vector* pLightingOrigin;
	short skin;
	unsigned short instance;
};

struct DrawModelInfo_t {
	studiohdr_t* m_pStudioHdr;
	void* m_pHardwareData;
	void* m_Decals;
	int				m_Skin;
	int				m_Body;
	int				m_HitboxSet;
	void* m_pClientEntity;
	int				m_Lod;
	void* m_pColorMeshes;
	bool			m_bStaticLighting;
	Vector			m_vecAmbientCube[6];
	int				m_nLocalLightCount;
	LightDesc_t		m_LocalLightDescs[4];
};

struct ModelRenderSystemData_t {
	IClientRenderable* m_pRenderable;
	IClientModelRenderable* m_pModelRenderable;
	RenderableInstance_t	m_InstanceData;
};