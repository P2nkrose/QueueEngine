#include "qTime.h"

namespace Q
{
	LARGE_INTEGER Time::CpuFrequency = {};				// 고유 진동수
	LARGE_INTEGER Time::PrevFrequency = {};				// 앞 진동수
	LARGE_INTEGER Time::CurrentFrequency = {};			// 현재 진동수
	float Time::DeltaTimeValue = 0.0f;

	void Time::Initialize()
	{
		// CPU 고유 진동수
		QueryPerformanceFrequency(&CpuFrequency);

		// 프로그램이 시작했을때 현재까지의 진동수 (앞전 진동수)
		QueryPerformanceCounter(&PrevFrequency);
	}
		
	void Time::Update()
	{
		// 현재 진동수
		QueryPerformanceCounter(&CurrentFrequency);

		//differenceFrequency(지금부터 실시한 진동수) : 현재 진동수 - 앞진동수
		float differenceFrequency = static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);
		
		// DeltaTimeValue(프로그램이 실행되는 시간(속도)) : 실시한진동수 / 고유진동수
		DeltaTimeValue = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart);

		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;


	}
	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;

		time += DeltaTimeValue;
		float fps = 1.0f / DeltaTimeValue;

		// wchar 초기화는 앞에 L을 붙여야 함
		// 상수는 상수인데 우리가 하드코딩한 값들을 리터럴이라고 함
		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"Time : %d", (int)fps);
		
		size_t len = wcsnlen_s(str, 50);


		TextOut(hdc, 0, 0, str, len);
	}
}