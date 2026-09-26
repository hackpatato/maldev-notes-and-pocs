#ifndef HKCU_H
#define HKCU_H

#include <windows.h>
#include <stdbool.h>

// Unicode (wchar_t) parametreler kabul eden fonksiyon
bool SetStartupRegistry(const wchar_t* valueName, const wchar_t* valueData);

#endif