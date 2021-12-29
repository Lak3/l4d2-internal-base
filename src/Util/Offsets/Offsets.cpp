#include "Offsets.h"

void CUtil_Offsets::Init()
{
	m_dwSharedRandomFloat = U::Pattern.Find(_("client.dll"), _("55 8B EC 83 EC 08 A1 ? ? ? ? 53 56 57 8B 7D 14 8D 4D 14 51 89 7D F8 89 45 FC E8 ? ? ? ? 6A 04 8D 55 FC 52 8D 45 14 50 E8 ? ? ? ? 6A 04 8D 4D F8 51 8D 55 14 52 E8 ? ? ? ? 8B 75 08 56 E8 ? ? ? ? 50 8D 45 14 56 50 E8 ? ? ? ? 8D 4D 14 51 E8 ? ? ? ? 8B 15 ? ? ? ? 8B 5D 14 83 C4 30 83 7A 30 00 74 26"));
	XASSERT(m_dwSharedRandomFloat == 0x0);

	m_dwCheckForSequenceChange = U::Pattern.Find(_("client.dll"), _("55 8B EC 83 7D 08 00 56 8B F1 0F 84 ? ? ? ? 83 7E 0C 00 75 10 6A 00 E8 ? ? ? ? 8B 0E 6A 00 E8 ? ? ? ?"));
	XASSERT(m_dwCheckForSequenceChange == 0x0);

	m_dwCalcPlayerView = U::Pattern.Find(_("client.dll"), _("55 8B EC 83 EC 1C 53 56 8B F1 8B 0D ? ? ? ? 8B 01 8B 50 38 57 FF D2 84 C0 75 0D"));
	XASSERT(m_dwCalcPlayerView == 0x0);

	m_dwUpdateSpread = U::Pattern.Find(_("client.dll"), _("53 8B DC 83 EC 08 83 E4 F0 83 C4 04 55 8B 6B 04 89 6C 24 04 8B EC 83 EC 28 56 57 8B F9 E8 ? ? ? ? 8B CF 89 45 F0 E8 ? ? ? ? 8B F0 85 F6 75 1B"));
	XASSERT(m_dwUpdateSpread == 0x0);

	m_dwDrawModels = U::Pattern.Find(_("client.dll"), _("55 8B EC 83 EC 74 A1 ? ? ? ? 33 C5 89 45 FC 8B 45 08 53 56 57 8B 7D 0C 33 F6 8B D9 89 5D CC 89 45 D0 89 7D D4 3B FE 0F 84 ? ? ? ?"));
	XASSERT(m_dwDrawModels == 0x0);

	m_dwAvoidPlayers = U::Pattern.Find(_("client.dll"), _("53 8B DC 83 EC 08 83 E4 F0 83 C4 04 55 8B 6B 04 89 6C 24 04 8B EC 81 EC ? ? ? ? A1 ? ? ? ? 33 C5 89 45 FC 8B 43 08 56 57 8B F9 80 BF ? ? ? ? ? 89 45 90 0F 85 ? ? ? ?"));
	XASSERT(m_dwAvoidPlayers == 0x0);

	m_dwPhysicsRunThink = U::Pattern.Find(_("client.dll"), _("55 8B EC 53 56 8B F1 8B 86 ? ? ? ? C1 E8 16 A8 01 57 B0 01 0F 85 ? ? ? ?"));
	XASSERT(m_dwPhysicsRunThink == 0x0);

	m_dwSetPredictionRandomSeed = U::Pattern.Find(_("client.dll"), _("55 8B EC 8B 45 08 85 C0 75 0C C7 05 ? ? ? ? ? ? ? ? 5D"));
	XASSERT(m_dwSetPredictionRandomSeed == 0x0);

	m_dwGetSurvivorSet = U::Pattern.Find(_("client.dll"), _("55 8B EC 51 8B 0D ? ? ? ? 8B 01 8B 50 28 53 56 BB ? ? ? ? FF D2 8B 10 8B C8 8B 42 04 6A 00 FF D0 8B F0 85 F6 74 45"));
	XASSERT(m_dwGetSurvivorSet == 0x0);

	m_dwCLMove = U::Pattern.Find(_("engine.dll"), _("55 8B EC 81 EC ? ? ? ? A1 ? ? ? ? 33 C5 89 45 FC 56 E8 ? ? ? ? 8B F0 83 7E 68 02 0F 8C"));
	XASSERT(m_dwCLMove == 0x0);

	if (const DWORD dwClientMode = U::Pattern.Find(_("client.dll"), _("89 04 B5 ? ? ? ? E8")))
		m_dwClientMode = (dwClientMode + 0x3);

	if (const DWORD dwGlobalVars = U::Pattern.Find(_("client.dll"), _("A1 ? ? ? ? D9 40 0C 51 D9 1C 24 57")))
		m_dwGlobalVars = (dwGlobalVars + 0x1);

	if (const DWORD dwMoveHelper = U::Pattern.Find(_("client.dll"), _("8B 0D ? ? ? ? 8B 11 8B 52 34")))
		m_dwMoveHelper = (dwMoveHelper + 0x2);

	if (const DWORD dwStartDrawing = U::Pattern.Find(_("vguimatsurface.dll"), _("33 C5 50 8D 45 F4 64 A3 ? ? ? ? 8B F9 80 3D")))
		m_dwStartDrawing = (dwStartDrawing - 0x1B);

	if (const DWORD dwFinishDrawing = U::Pattern.Find(_("vguimatsurface.dll"), _("51 56 A1 ? ? ? ? 33 C5 50 8D 45 F4 64 A3 ? ? ? ? 6A")))
		m_dwFinishDrawing = (dwFinishDrawing - 0x11);

	if (m_dwSharedRandomFloat)
		m_dwRandomSeed = (m_dwSharedRandomFloat + 0x7);

	XASSERT(m_dwStartDrawing == 0x0);
	XASSERT(m_dwFinishDrawing == 0x0);
	XASSERT(m_dwClientMode == 0x0);
	XASSERT(m_dwGlobalVars == 0x0);
	XASSERT(m_dwMoveHelper == 0x0);
	XASSERT(m_dwRandomSeed == 0x0);
}