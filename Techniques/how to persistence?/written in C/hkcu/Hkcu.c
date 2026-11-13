#include "hkcu.h"
#include <stdio.h>

bool SetStartupRegistry(const wchar_t* valueName, const wchar_t* valueData) {
    HKEY hKey;
    const wchar_t* regPath = L"Software\\Microsoft\\Windows\\CurrentVersion\\Run";

    LONG result = RegOpenKeyExW(
        HKEY_CURRENT_USER,
        regPath,
        0,
        KEY_SET_VALUE,
        &hKey
    );

    if (result != ERROR_SUCCESS) {
        return false;
    }

    DWORD dataSize = (DWORD)((lstrlenW(valueData) + 1) * sizeof(wchar_t));

    result = RegSetValueExW(
        hKey,
        valueName,
        0,
        REG_SZ,
        (const BYTE*)valueData,
        dataSize
    );

    RegCloseKey(hKey);

    if (result == ERROR_SUCCESS) {
        return true;
    } else {
        return false;
    }
}