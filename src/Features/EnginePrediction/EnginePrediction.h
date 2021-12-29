#pragma once

#include "../../SDK/SDK.h"

class CFeatures_EnginePrediction
{
public:
	void Start(C_BasePlayer* pLocal, CUserCmd* cmd);
	void Finish(C_BasePlayer* pLocal, CUserCmd* cmd);

public:
	int GetPredictedFlags() const;

private:
	int GetTickBase(const int nCurrentTickBase, CUserCmd* cmd);

private:
	float m_flOldCurTime = 0.0f;
	float m_flOldFrameTime = 0.0f;

	int m_nOldTickCount = 0;
	int m_nPredictedFlags = 0;

	CMoveData m_MoveData = { };
};

namespace F { inline CFeatures_EnginePrediction EnginePrediction; }