#pragma once

#include "MinHook/MinHook.h"

#include <memory>

namespace Hook
{
	class CFunction
	{
	public:
		inline bool Init(void* pTarget, void* pDetour) {
			return (MH_CreateHook(pTarget, pDetour, &m_pOriginal) == MH_STATUS::MH_OK);
		}

	public:
		template<typename FN>
		inline FN Original() const {
			return reinterpret_cast<FN>(m_pOriginal);
		}

	private:
		void* m_pOriginal = nullptr;
	};

	class CTable
	{
	public:
		inline bool Init(const void* pTable)
		{
			m_pBase = (unsigned int**)(pTable);

			while (reinterpret_cast<unsigned int*>(*m_pBase)[m_nSize])
				m_nSize += 1u;

			m_pOriginals = std::make_unique<void* []>(m_nSize);

			return (m_pBase && m_nSize);
		}

		inline bool Hook(void* pDetour, const unsigned int nIndex)
		{
			if (m_pBase && m_nSize)
				return (MH_CreateHook((*reinterpret_cast<void***>(m_pBase))[nIndex], pDetour, &m_pOriginals[nIndex]) == MH_STATUS::MH_OK);

			return false;
		}

	public:
		template<typename FN>
		inline FN Original(const unsigned int nIndex) const {
			return reinterpret_cast<FN>(m_pOriginals[nIndex]);
		}

	private:
		unsigned int** m_pBase = 0u;
		unsigned int		      m_nSize = 0u;
		std::unique_ptr<void* []> m_pOriginals = { };
	};

	class CVMTable
	{
	public:
		inline bool Initialize(const void* pTable)
		{
			m_pTable = (uintptr_t**)(pTable);

			if (m_nSize <= 0u)
			{
				while (static_cast<uintptr_t*>(*m_pTable)[m_nSize])
					m_nSize += 1u;
			}

			m_pOriginalTable = *m_pTable;
			m_pCurrent = std::make_unique<uintptr_t[]>(m_nSize);
			memcpy(m_pCurrent.get(), m_pOriginalTable, (m_nSize * sizeof(size_t)));
			*m_pTable = m_pCurrent.get();

			return ((m_nSize > 0u) && m_pOriginalTable && *m_pTable);
		}

		template<typename FN>
		inline FN Original(const size_t nIndex)
		{
			return reinterpret_cast<FN>(m_pOriginalTable[nIndex]);
		}

		inline void Hook(void* pNewFunc, const size_t nIndex)
		{
			m_pCurrent[nIndex] = reinterpret_cast<uintptr_t>(pNewFunc);
		}

		inline void RemoveHook(const size_t nIndex)
		{
			m_pCurrent[nIndex] = m_pOriginalTable[nIndex];
		}

		inline void RestoreTable()
		{
			if ((m_nSize > 0u) && m_pOriginalTable && *m_pTable)
			{
				*m_pTable = m_pOriginalTable;
			}
		}

		inline bool IsInitialized()
		{
			return ((m_nSize > 0u) && m_pOriginalTable && *m_pTable);
		}

	private:
		uintptr_t** m_pTable = nullptr;
		uintptr_t* m_pOriginalTable = nullptr;
		size_t m_nSize = 0u;

		std::unique_ptr<uintptr_t[]> m_pCurrent = { };
	};
}