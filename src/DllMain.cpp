#include "Entry/Entry.h"

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	static bool s_bAttached = false;

	if ((fdwReason == DLL_PROCESS_ATTACH) && !s_bAttached)
	{
		G::ModuleEntry.Load();

		s_bAttached = true;
	}

	return TRUE;
}