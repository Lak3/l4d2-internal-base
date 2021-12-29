#include "ClientPrediction.h"

using namespace Hooks;

void __fastcall ClientPrediction::RunCommand::Detour(void* ecx, void* edx, C_BasePlayer* player, CUserCmd* ucmd, IMoveHelper* moveHelper)
{
	Table.Original<FN>(Index)(ecx, edx, player, ucmd, moveHelper);
}

void __fastcall ClientPrediction::SetupMove::Detour(void* ecx, void* edx, C_BasePlayer* player, CUserCmd* ucmd, IMoveHelper* pHelper, CMoveData* move)
{
	Table.Original<FN>(Index)(ecx, edx, player, ucmd, pHelper, move);
}

void __fastcall ClientPrediction::FinishMove::Detour(void* ecx, void* edx, C_BasePlayer* player, CUserCmd* ucmd, CMoveData* move)
{
	Table.Original<FN>(Index)(ecx, edx, player, ucmd, move);
}

void ClientPrediction::Init()
{
	XASSERT(Table.Init(I::Prediction) == false);
	XASSERT(Table.Hook(&RunCommand::Detour, RunCommand::Index) == false);
	XASSERT(Table.Hook(&SetupMove::Detour, SetupMove::Index) == false);
	XASSERT(Table.Hook(&FinishMove::Detour, FinishMove::Index) == false);
}