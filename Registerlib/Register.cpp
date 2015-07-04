#include "stdafx.h"
#include "md5.h"
#include "Base64.h"
#include <string>
#include <algorithm>
#include "Registerlib.h"


BOOL GetMachineSerialNumberA(LPSTR pszSerialNumber, DWORD dwMaxCount)
{
	CHAR  szVolume[256] = { 0 }, szFileSysName[256] = { 0 };
	DWORD dwSerialNumber(0), dwFileNameLength(0), dwFileSysFlag(0);
	GetVolumeInformationA("C:\\", szVolume, _countof(szVolume), &dwSerialNumber, &dwFileNameLength, &dwFileSysFlag, szFileSysName, _countof(szFileSysName));
	return sprintf_s(pszSerialNumber, dwMaxCount, "FFEF1%04X", dwSerialNumber ^ 0x34795814) > 0;
}

VOID EncryptMachineToKeyA(LPCSTR lpMachineCode, LPSTR pszRegisterCode, DWORD dwMaxCount)
{
	std::string strSerial(lpMachineCode);
	strSerial.append("-WJQ");
	CBase64 Base64;
	std::string strBase64 = Base64.Encode(strSerial.c_str(), strSerial.length());
	MD5 md5(strBase64);
	std::string strMd5 = md5.toString();
	std::transform(strMd5.begin(), strMd5.end(), strMd5.begin(), toupper);

	lstrcpynA(pszRegisterCode, strMd5.c_str(), dwMaxCount);
}

BOOL GetMachineRegisterCodeA(LPSTR pszRegisterCode, DWORD dwMaxCount)
{
	BOOL bReturn(FALSE);
	CHAR szSerialNumber[512] = { 0 };
	if (GetMachineSerialNumberA(szSerialNumber, _countof(szSerialNumber)))
	{
		EncryptMachineToKeyA(szSerialNumber, pszRegisterCode, dwMaxCount);
		bReturn = TRUE;
	}
	return bReturn;
}
