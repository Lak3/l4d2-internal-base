#pragma once

#include "BaseClient/BaseClient.h"
#include "BasePlayer/BasePlayer.h"
#include "CL_Main/CL_Main.h"
#include "ClientMode/ClientMode.h"
#include "ClientPrediction/ClientPrediction.h"
#include "EngineVGui/EngineVGui.h"
#include "ModelRender/ModelRender.h"
#include "ModelRenderSystem/ModelRenderSystem.h"
#include "SequenceTransitioner/SequenceTransitioner.h"
#include "TerrorGameRules/TerrorGameRules.h"
#include "TerrorPlayer/TerrorPlayer.h"
#include "WndProc/WndProc.h"

class CGlobal_Hooks
{
public:
	void Init();
};

namespace G { inline CGlobal_Hooks Hooks; }