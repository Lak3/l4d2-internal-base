#pragma once

#include "DrawManager/DrawManager.h"

namespace I { inline void* ClientMode = nullptr; }

struct WeaponSpawnInfo_t
{
	const wchar_t* m_szName;
	Color m_Color;
};

//Array of GetWeaponID's with their name and appropriate color.
static WeaponSpawnInfo_t g_aSpawnInfo[] =
{
	{ L"unknown", { 204, 204, 204, 255 } },
	{ L"pistol", { 204, 204, 204, 255 } },
	{ L"uzi", { 204, 204, 204, 255 } },
	{ L"pump shotgun", { 204, 204, 204, 255 } },
	{ L"auto shotgun", { 204, 204, 204, 255 } },
	{ L"m16a1", { 204, 204, 204, 255 } },
	{ L"hunting rifle", { 204, 204, 204, 255 } },
	{ L"mac10", { 204, 204, 204, 255 } },
	{ L"chrome shotgun", { 204, 204, 204, 255 } },
	{ L"scar", { 204, 204, 204, 255 } },
	{ L"military sniper", { 204, 204, 204, 255 } },
	{ L"spas", { 204, 204, 204, 255 } },
	{ L"firstaid", { 153, 255, 153, 255 } },
	{ L"molotov", { 255, 255, 255, 255 } },
	{ L"pipebomb", { 255, 255, 255, 255 } },
	{ L"pills", { 153, 255, 153, 255 } },
	{ L"gascan", { 255, 178, 0, 255 } },
	{ L"propane tank", { 255, 178, 0, 255 } },
	{ L"oxygen tank", { 255, 178, 0, 255 } },
	{ L"melee weapon", { 204, 204, 204, 255 } },
	{ L"chainsaw", { 204, 204, 204, 255 } },
	{ L"grenade launcher", { 204, 204, 204, 255 } },
	{ L"unknown", { 255, 255, 255, 255 } },
	{ L"adrenaline", { 153, 255, 153, 255 } },
	{ L"defibrillator", { 153, 255, 153, 255 } },
	{ L"vomitjar", { 255, 255, 255, 255 } },
	{ L"ak47", { 204, 204, 204, 255 } },
	{ L"unknown", { 255, 255, 255, 255 } },
	{ L"unknown", { 255, 255, 255, 255 } },
	{ L"firework crate", { 255, 255, 255, 255 } },
	{ L"incendiary ammo", { 255, 255, 255, 255 } },
	{ L"explosive ammo", { 255, 255, 255, 255 } },
	{ L"deagle", { 204, 204, 204, 255 } },
	{ L"mp5", { 204, 204, 204, 255 } },
	{ L"sg552", { 204, 204, 204, 255 } },
	{ L"awp", { 204, 204, 204, 255 } },
	{ L"scout", { 204, 204, 204, 255 } },
	{ L"m60", { 204, 204, 204, 255 } },
	{ L"unknown", { 255, 255, 255, 255 } },
};