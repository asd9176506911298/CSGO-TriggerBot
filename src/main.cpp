#define WIN32_MEAN_AND_LEAN
#include <Windows.h>

#include "core\hooks.h"

DWORD WINAPI Setup(HMODULE hModule)
{
	interfaces::Setup();
	hooks::SetUp();

	while (!GetAsyncKeyState(VK_END))
		Sleep(200);

	hooks::Destory();

	FreeLibraryAndExitThread(hModule, 0);
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD reason, LPVOID reserve)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hModule);
		if (HANDLE thread = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)Setup, hModule, 0, nullptr))
			CloseHandle(thread);
	}

	return true;
}