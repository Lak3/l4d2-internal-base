#include "NetVarManager.h"

#include "../../SDK/L4D2/Interfaces/BaseClientDll.h"

inline int GetOffsetInternal(RecvTable* pTable, const char* const szVar)
{
	for (int n = 0; n < pTable->GetNumProps(); n++)
	{
		RecvProp* pProp = pTable->GetProp(n);

		if (!pProp)
			continue;

		if (strcmp(szVar, pProp->GetName()) == 0)
			return pProp->GetOffset();

		RecvTable* pDataTable = pProp->GetDataTable();

		if (!pDataTable)
			continue;

		const int nOffset = GetOffsetInternal(pDataTable, szVar);

		if (nOffset)
			return (nOffset + pProp->GetOffset());
	}

	return 0;
}

int CUtil_NetVarManager::Get(const char* const szClass, const char* const szVar)
{
	ClientClass* pCC = I::BaseClient->GetAllClasses();

	while (pCC)
	{
		if (strcmp(szClass, pCC->m_pNetworkName) == 0)
			return GetOffsetInternal(pCC->m_pRecvTable, szVar);

		pCC = pCC->m_pNext;
	}

	return 0;
}