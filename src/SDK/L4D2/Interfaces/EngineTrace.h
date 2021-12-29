#pragma once

#include "EngineClient.h"

class C_BaseEntity;
class IHandleEntity;
class ICollideable;
class ITraceListData;
class CPhysCollide;

#define DISPSURF_FLAG_SURFACE		(1 << 0)
#define DISPSURF_FLAG_WALKABLE		(1 << 1)
#define DISPSURF_FLAG_BUILDABLE		(1 << 2)
#define DISPSURF_FLAG_SURFPROP1		(1 << 3)
#define DISPSURF_FLAG_SURFPROP2		(1 << 4)

enum TraceType_t {
	TRACE_EVERYTHING = 0,
	TRACE_WORLD_ONLY,
	TRACE_ENTITIES_ONLY,
	TRACE_EVERYTHING_FILTER_PROPS
};

class ITraceFilter
{
public:
	virtual bool ShouldHitEntity(IHandleEntity* pEntity, int contentsMask) = 0;
	virtual TraceType_t	GetTraceType() const = 0;
};

class IEntityEnumerator
{
public:
	virtual bool EnumEntity(IHandleEntity* pHandleEntity) = 0;
};

struct cplane_t {
	Vector normal;
	float dist;
	unsigned char type;
	unsigned char signbits;
	unsigned char __pad00[2];
};

struct BrushSideInfo_t {
	cplane_t plane;			// The plane of the brush side
	unsigned short bevel;	// Bevel plane?
	unsigned short thin;	// Thin?
};

struct Ray_t
{
	Ray_t() {

	}

	Ray_t(const Vector vStart, const Vector vEnd)
	{
		m_Delta = VectorAligned(vEnd - vStart);
		m_IsSwept = (m_Delta.LenghtSqr() != 0);
		m_Extents.Init();
		m_pWorldAxisTransform = 0;
		m_IsRay = true;
		m_StartOffset.Init();
		m_Start = vStart;
	}

	VectorAligned m_Start;
	VectorAligned m_Delta;
	VectorAligned m_StartOffset;
	VectorAligned m_Extents;
	const matrix3x4_t* m_pWorldAxisTransform;
	bool m_IsRay;
	bool m_IsSwept;

	void Init(const Vector vStart, const Vector vEnd)
	{
		m_Delta = VectorAligned(vEnd - vStart);
		m_IsSwept = (m_Delta.LenghtSqr() != 0);
		m_Extents.Init();
		m_pWorldAxisTransform = 0;
		m_IsRay = true;
		m_StartOffset.Init();
		m_Start = vStart;
	}
};

class CBaseTrace
{
public:
	Vector startpos;
	Vector endpos;
	cplane_t plane;

	float fraction;

	int contents;
	unsigned short dispFlags;

	bool allsolid;
	bool startsolid;

	CBaseTrace() {}
};

struct csurface_t
{
	const char* name;
	short surfaceProps;
	unsigned short flags;
};

class CGameTrace : public CBaseTrace
{
public:
	bool DidHit() const;

public:
	float fractionleftsolid;
	csurface_t surface;
	int hitgroup;
	short physicsbone;
	unsigned short worldSurfaceIndex;
	C_BaseEntity* m_pEnt;
	int hitbox;

	CGameTrace() { }

private:
	CGameTrace(const CGameTrace& vOther);
};

inline bool CGameTrace::DidHit() const
{
	return fraction < 1 || allsolid || startsolid;
}

typedef CGameTrace trace_t;

class CBrushQuery
{
public:
	CBrushQuery(void)
	{
		m_iCount = 0;
		m_pBrushes = NULL;
		m_iMaxBrushSides = 0;
		m_pReleaseFunc = NULL;
		m_pData = NULL;
	}
	~CBrushQuery(void)
	{
		ReleasePrivateData();
	}
	void ReleasePrivateData(void)
	{
		if (m_pReleaseFunc)
		{
			m_pReleaseFunc(this);
		}

		m_iCount = 0;
		m_pBrushes = NULL;
		m_iMaxBrushSides = 0;
		m_pReleaseFunc = NULL;
		m_pData = NULL;
	}

	inline int Count(void) const { return m_iCount; }
	inline unsigned __int32* Base(void) { return m_pBrushes; }
	inline unsigned __int32 operator[](int iIndex) const { return m_pBrushes[iIndex]; }
	inline unsigned __int32 GetBrushNumber(int iIndex) const { return m_pBrushes[iIndex]; }
	inline int MaxBrushSides(void) const { return m_iMaxBrushSides; }

protected:
	int m_iCount;
	unsigned __int32* m_pBrushes;
	int m_iMaxBrushSides;
	void (*m_pReleaseFunc)(CBrushQuery*);
	void* m_pData;
};

class IEngineTrace
{
public:
	virtual int				GetPointContents(const Vector& vecAbsPosition, int contentsMask = 0, IHandleEntity** ppEntity = NULL) = 0;
	virtual int				GetPointContents_WorldOnly(const Vector& vecAbsPosition, int contentsMask = 0) = 0;
	virtual int				GetPointContents_Collideable(ICollideable* pCollide, const Vector& vecAbsPosition) = 0;
	virtual void			ClipRayToEntity(const Ray_t& ray, unsigned int fMask, IHandleEntity* pEnt, trace_t* pTrace) = 0;
	virtual void			ClipRayToCollideable(const Ray_t& ray, unsigned int fMask, ICollideable* pCollide, trace_t* pTrace) = 0;
	virtual void			TraceRay(const Ray_t& ray, unsigned int fMask, ITraceFilter* pTraceFilter, trace_t* pTrace) = 0;
	virtual void			SetupLeafAndEntityListRay(const Ray_t& ray, ITraceListData* pTraceData) = 0;
	virtual void			SetupLeafAndEntityListBox(const Vector& vecBoxMin, const Vector& vecBoxMax, ITraceListData* pTraceData) = 0;
	virtual void			TraceRayAgainstLeafAndEntityList(const Ray_t& ray, ITraceListData* pTraceData, unsigned int fMask, ITraceFilter* pTraceFilter, trace_t* pTrace) = 0;
	virtual void			SweepCollideable(ICollideable* pCollide, const Vector& vecAbsStart, const Vector& vecAbsEnd, const Vector& vecAngles, unsigned int fMask, ITraceFilter* pTraceFilter, trace_t* pTrace) = 0;
	virtual void			EnumerateEntities(const Ray_t& ray, bool triggers, IEntityEnumerator* pEnumerator) = 0;
	virtual void			EnumerateEntities(const Vector& vecAbsMins, const Vector& vecAbsMaxs, IEntityEnumerator* pEnumerator) = 0;
	virtual ICollideable*	GetCollideable(IHandleEntity* pEntity) = 0;
	virtual int				GetStatByIndex(int index, bool bClear) = 0;
	virtual void			GetBrushesInAABB(const Vector& vMins, const Vector& vMaxs, CBrushQuery& BrushQuery, int iContentsMask = 0xFFFFFFFF, int cmodelIndex = 0) = 0;
	virtual CPhysCollide*	GetCollidableFromDisplacementsInAABB(const Vector& vMins, const Vector& vMaxs) = 0;

private:
	//(int iBrush, CUtlVector<Vector4D> *pPlanesOut, int *pContentsOut)
	virtual int				GetBrushInfo(int iBrush, void* pPlanesOut, int* pContentsOut) = 0;

public:
	virtual bool			PointOutsideWorld(const Vector& ptTest) = 0;
	virtual int				GetLeafContainingPoint(const Vector& ptTest) = 0;
	virtual ITraceListData* AllocTraceListData() = 0;
	virtual void			FreeTraceListData(ITraceListData*) = 0;
};

namespace I { inline IEngineTrace* EngineTrace = nullptr; }

class CTraceFilterWorldAndPropsOnly : public ITraceFilter
{
public:
	bool ShouldHitEntity(IHandleEntity* pServerEntity, int contentsMask) {
		return false;
	}

	virtual TraceType_t	GetTraceType() const {
		return TRACE_EVERYTHING;
	}
};

class CTraceFilter : public ITraceFilter
{
public:
	virtual TraceType_t	GetTraceType() const {
		return TRACE_EVERYTHING;
	}
};

class CTraceFilterHitAll : public CTraceFilter
{
public:
	CTraceFilterHitAll() {
		m_pIgnore = nullptr;
	}

	CTraceFilterHitAll(IHandleEntity* pIgnore) {
		m_pIgnore = pIgnore;
	}

public:
	virtual bool ShouldHitEntity(IHandleEntity* pServerEntity, int contentsMask) {
		return (pServerEntity != m_pIgnore);
	}

private:
	IHandleEntity* m_pIgnore = nullptr;
};