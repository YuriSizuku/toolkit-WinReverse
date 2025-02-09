#include <windows.h>
#include "winversion.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		winversion_init();
       	HMODULE hmod = LoadLibraryA("patch.dll");
		if(!hmod) MessageBoxA(NULL, "can not load patch.dll", "dll error", 0);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}