#pragma once

#include "../../../Util/Util.h"

class CUserCmd
{
public:
	CUserCmd() {
		Reset();
	}

	virtual ~CUserCmd() {

	};

	void Reset()
	{
		command_number = 0;
		tick_count = 0;
		viewangles.Init();
		forwardmove = 0.0f;
		sidemove = 0.0f;
		upmove = 0.0f;
		buttons = 0;
		impulse = 0;
		weaponselect = 0;
		weaponsubtype = 0;
		random_seed = 0;
		mousedx = 0;
		mousedy = 0;
		hasbeenpredicted = false;
	}

	CUserCmd& operator =(const CUserCmd& src)
	{
		if (this == &src)
			return *this;

		command_number = src.command_number;
		tick_count = src.tick_count;
		viewangles = src.viewangles;
		forwardmove = src.forwardmove;
		sidemove = src.sidemove;
		upmove = src.upmove;
		buttons = src.buttons;
		impulse = src.impulse;
		weaponselect = src.weaponselect;
		weaponsubtype = src.weaponsubtype;
		random_seed = src.random_seed;
		mousedx = src.mousedx;
		mousedy = src.mousedy;
		hasbeenpredicted = src.hasbeenpredicted;

		return *this;
	}

	CUserCmd(const CUserCmd& src) {
		*this = src;
	}

	int			  command_number;
	int			  tick_count;
	Vector		  viewangles;
	float		  forwardmove;
	float		  sidemove;
	float		  upmove;
	int			  buttons;
	unsigned char impulse;
	int			  weaponselect;
	int			  weaponsubtype;
	int			  random_seed;
	short		  mousedx;
	short		  mousedy;
	bool		  hasbeenpredicted;
};