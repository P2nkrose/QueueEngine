#pragma once
#include "CommonInclude.h"

namespace Q
{
	class Time
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		static float DeltaTime() { return DeltaTimeValue; }

	private:
		static LARGE_INTEGER CpuFrequency;			// 고유 진동수
		static LARGE_INTEGER PrevFrequency;		// 앞 진동수
		static LARGE_INTEGER CurrentFrequency;		// 현재 진동수
		static float DeltaTimeValue;
	};
}


