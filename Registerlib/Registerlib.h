#pragma once

#include <windows.h>

BOOL GetMachineSerialNumberA(LPSTR pszSerialNumber, DWORD dwMaxCount);
BOOL GetMachineRegisterCodeA(LPSTR pszRegisterCode, DWORD dwMaxCount);
VOID EncryptMachineToKeyA(LPCSTR lpMachineCode, LPSTR pszRegisterCode, DWORD dwMaxCount);

