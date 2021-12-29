#include "ModelRenderSystem.h"

using namespace Hooks;

void __fastcall ModelRenderSystem::DrawModels::Detour(void* ecx, void* edx, ModelRenderSystemData_t* pEntities, int nCount, int renderMode)
{
	Func.Original<FN>()(ecx, edx, pEntities, nCount, renderMode);
}

void ModelRenderSystem::Init()
{
	//DrawModels
	{
		using namespace DrawModels;

		const FN pfDrawModels = reinterpret_cast<FN>(U::Offsets.m_dwDrawModels);
		XASSERT(pfDrawModels == nullptr);

		if (pfDrawModels)
			XASSERT(Func.Init(pfDrawModels, &Detour) == false);
	}
}