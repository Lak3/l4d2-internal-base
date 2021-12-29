#pragma once

#include "EngineVGui.h"

class C_BasePlayer;
class C_BaseEntity;

class CMoveData
{
public:
	bool			m_bFirstRunOfFunctions : 1;
	bool			m_bGameCodeMovedPlayer : 1;
	bool			m_bNoAirControl : 1;
	unsigned long	m_nPlayerHandle;
	int				m_nImpulseCommand;
	Vector			m_vecViewAngles;
	Vector			m_vecAbsViewAngles;
	int				m_nButtons;
	int				m_nOldButtons;
	float			m_flForwardMove;
	float			m_flSideMove;
	float			m_flUpMove;
	float			m_flMaxSpeed;
	float			m_flClientMaxSpeed;
	Vector			m_vecVelocity;
	Vector			m_vecOldVelocity;
	float			somefloat;
	Vector			m_vecAngles;
	Vector			m_vecOldAngles;
	float			m_outStepHeight;
	Vector			m_outWishVel;
	Vector			m_outJumpVel;
	Vector			m_vecConstraintCenter;
	float			m_flConstraintRadius;
	float			m_flConstraintWidth;
	float			m_flConstraintSpeedFactor;
	bool			m_bConstraintPastRadius;
	Vector			m_vecAbsOrigin; //edict::origin
};

class IGameMovement
{
public:
	virtual					~IGameMovement(void) {}

	virtual void			ProcessMovement(C_BasePlayer* pPlayer, CMoveData* pMove) = 0;
	virtual void			Reset(void) = 0;
	virtual void			StartTrackPredictionErrors(C_BasePlayer* pPlayer) = 0;
	virtual void			FinishTrackPredictionErrors(C_BasePlayer* pPlayer) = 0;
	virtual void			DiffPrint(char const* fmt, ...) = 0;
	virtual Vector const&	GetPlayerMins(bool ducked) const = 0;
	virtual Vector const&	GetPlayerMaxs(bool ducked) const = 0;
	virtual Vector const&	GetPlayerViewOffset(bool ducked) const = 0;
	virtual bool			IsMovingPlayerStuck(void) const = 0;
	virtual C_BasePlayer*	GetMovingPlayer(void) const = 0;
	virtual void			UnblockPusher(C_BasePlayer* pPlayer, C_BaseEntity* pPusher) = 0;
	virtual void			SetupMovementBounds(CMoveData* pMove) = 0;
};

namespace I { inline IGameMovement* GameMovement = nullptr; }