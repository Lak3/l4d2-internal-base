#pragma once

#include "EngineTrace.h"

enum VGuiPanel_t {
	PANEL_ROOT = 0,
	PANEL_GAMEUIDLL,
	PANEL_CLIENTDLL,
	PANEL_TOOLS,
	PANEL_INGAMESCREENS,
	PANEL_GAMEDLL,
	PANEL_CLIENTDLL_TOOLS,
	PANEL_GAMEUIBACKGROUND,
	PANEL_TRANSITIONEFFECT,
	PANEL_STEAMOVERLAY
};

enum PaintMode_t {
	PAINT_UIPANELS = (1 << 0),
	PAINT_INGAMEPANELS = (1 << 1),
};

class IEngineVGui
{
public:
	virtual					~IEngineVGui(void) = 0;

	virtual unsigned int	GetPanel(VGuiPanel_t type) = 0;
	virtual bool			IsGameUIVisible() = 0;
	virtual void			ActivateGameUI() = 0;
};

namespace I { inline IEngineVGui* EngineVGui = nullptr; }