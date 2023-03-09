#pragma once
#include "interfaces.h"

namespace hooks
{
	void SetUp() noexcept;
	void Destory() noexcept;

	using CreateMoveFunction = bool(__thiscall*)(void*, float, CUserCmd*) noexcept;
	inline CreateMoveFunction CreateMoveOriginal = nullptr;
	bool __stdcall CreateMove(float frameTime, CUserCmd* cmd) noexcept;
}