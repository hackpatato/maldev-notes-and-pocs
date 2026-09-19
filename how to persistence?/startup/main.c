//1. find the startup 
//2. find the where are we
//3. copy to startup
//4.I apologize for my poor English
#include <stdio.h>
#include <windows.h> 
#include <shlobj.h>

//first 
int main() {
    wchar_t path[MAX_PATH];
    wchar_t exePath[MAX_PATH];

    HRESULT result1 = SHGetFolderPathW(NULL, CSIDL_STARTUP, NULL, 0, appPath);
    //what me made it ? SHGetFolderPathW is windows api we use for find the folder paths
    // CSIDL_STARTUP for starup for this user...
    //path for the address.
    // we finded the startup 
    //and we going to  find the where are we?
    DWORD result2 = GetModuleFileNameW(NULL, exePath, MAX_PATH);
    /*GetModuleFileNameW for windows api . to find the what we are (path and name)
      exePath for the address .
      The maxpath for limit is 260 characters
    */
    if (CopyFile(exePath, appPath, FALSE)) {
        printf("We did it ")
    } else {
        printf("We didn't succeed  ")
    }
    /*
    CopyFile is windows api
    exePath the path of  exe path 
    appPath for startup adress 
    false for overwrite . 
    */
}    