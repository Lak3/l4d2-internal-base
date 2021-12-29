#include "EnginePrediction.h"

//Very minimal prediction, misses a lot of stuff and the rest of the stuff like button offsets are hardcoded.

void CFeatures_EnginePrediction::Start(C_BasePlayer* pLocal, CUserCmd* cmd)
{
	memset(&m_MoveData, 0, sizeof(CMoveData));

	m_flOldCurTime = I::GlobalVars->curtime;
	m_flOldFrameTime = I::GlobalVars->frametime;
	m_nOldTickCount = I::GlobalVars->tickcount;

	const int nOldTickBase = pLocal->m_nTickBase();
	const int nOldFlags = pLocal->m_fFlags();

	const int nTickBase = GetTickBase(nOldTickBase, cmd);

	//StartCommand
	{
		I::MoveHelper->SetHost(pLocal);

		cmd->random_seed = (MD5_PseudoRandom(cmd->command_number) & INT_MAX);
		reinterpret_cast<void(*)(CUserCmd*)>(U::Offsets.m_dwSetPredictionRandomSeed)(cmd);
	}

	I::GlobalVars->curtime = TICKS_TO_TIME(nTickBase);
	I::GlobalVars->frametime = TICK_INTERVAL;
	I::GlobalVars->tickcount = nTickBase;

	cmd->buttons |= pLocal->m_afButtonForced();
	cmd->buttons &= ~pLocal->m_afButtonDisabled();

	I::GameMovement->StartTrackPredictionErrors(pLocal);

	if (cmd->weaponselect != 0)
	{
		C_BaseCombatWeapon* pWeapon = pLocal->GetActiveWeapon()->As<C_TerrorWeapon*>();

		if (pWeapon)
			pLocal->SelectItem(pWeapon->GetName(), cmd->weaponsubtype);
	}

	if (cmd->impulse)
		pLocal->m_nImpulse() = cmd->impulse;

	pLocal->UpdateButtonState(cmd->buttons);
	I::Prediction->SetLocalViewAngles(cmd->viewangles);

	I::Prediction->SetupMove(pLocal, cmd, I::MoveHelper, &m_MoveData);
	I::GameMovement->ProcessMovement(pLocal, &m_MoveData);
	I::Prediction->FinishMove(pLocal, cmd, &m_MoveData);

	m_nPredictedFlags = pLocal->m_fFlags();

	pLocal->m_nTickBase() = nOldTickBase;
	pLocal->m_fFlags() = nOldFlags;
}

void CFeatures_EnginePrediction::Finish(C_BasePlayer* pLocal, CUserCmd* cmd)
{
	I::GameMovement->FinishTrackPredictionErrors(pLocal);

	//FinishCommand
	{
		I::MoveHelper->SetHost(nullptr);
		reinterpret_cast<void(*)(CUserCmd*)>(U::Offsets.m_dwSetPredictionRandomSeed)(nullptr);
	}

	I::GlobalVars->curtime = m_flOldCurTime;
	I::GlobalVars->frametime = m_flOldFrameTime;
	I::GlobalVars->tickcount = m_nOldTickCount;
}

int CFeatures_EnginePrediction::GetPredictedFlags() const
{
	return m_nPredictedFlags;
}

//CasualHacker I believe posted this.
int CFeatures_EnginePrediction::GetTickBase(const int nCurrent, CUserCmd* cmd)
{
	static int s_nTick = 0;
	static CUserCmd* s_pLastCommand = nullptr;

	if (cmd)
	{
		if (!s_pLastCommand || s_pLastCommand->hasbeenpredicted)
			s_nTick = nCurrent;
		else
			s_nTick++;

		s_pLastCommand = cmd;
	}

	return s_nTick;
}