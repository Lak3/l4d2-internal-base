#include "Pattern.h"

#define INRANGE(x,a,b)	(x >= a && x <= b)
#define GetBits(x)		(INRANGE((x & (~0x20)),'A','F') ? ((x & (~0x20)) - 'A' + 0xA) : (INRANGE(x,'0','9') ? x - '0' : 0))
#define GetBytes(x)		(GetBits(x[0]) << 4 | GetBits(x[1]))

DWORD CUtil_Pattern::Find(const char* const szModule, const char* const szPattern)
{
    const DWORD dwMod = reinterpret_cast<DWORD>(GetModuleHandleA(szModule));

    if (!dwMod)
        return 0x0;

    const PIMAGE_NT_HEADERS32 pNTH = reinterpret_cast<PIMAGE_NT_HEADERS32>(dwMod + reinterpret_cast<PIMAGE_DOS_HEADER>(dwMod)->e_lfanew);

    if (!pNTH)
        return 0x0;

    return FindPattern(dwMod + pNTH->OptionalHeader.BaseOfCode, dwMod + pNTH->OptionalHeader.SizeOfCode, szPattern);
}

DWORD CUtil_Pattern::FindPattern(const DWORD dwAddress, const DWORD dwLen, const char* const szPattern)
{
    const char* szPatt = szPattern;
    DWORD dwFirstMatch = 0x0;

    for (DWORD dwCur = dwAddress; dwCur < dwLen; dwCur++)
    {
        if (!szPatt)
            return dwFirstMatch;

        const BYTE pCurByte = *(BYTE*)dwCur;
        const BYTE pBytePatt = *(BYTE*)szPatt;

        if (pBytePatt == '\?' || pCurByte == GetBytes(szPatt))
        {
            if (!dwFirstMatch)
                dwFirstMatch = dwCur;

            if (!szPatt[2])
                return dwFirstMatch;

            szPatt += (pBytePatt == '\?\?' || pBytePatt != '\?') ? 3 : 2;
        }
        else
        {
            szPatt = szPattern;
            dwFirstMatch = 0x0;
        }
    }

    return 0x0;
}