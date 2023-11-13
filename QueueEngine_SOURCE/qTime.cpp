#include "qTime.h"

namespace Q
{
	LARGE_INTEGER Time::CpuFrequency = {};				// ���� ������
	LARGE_INTEGER Time::PrevFrequency = {};				// �� ������
	LARGE_INTEGER Time::CurrentFrequency = {};			// ���� ������
	float Time::DeltaTimeValue = 0.0f;

	void Time::Initialize()
	{
		// CPU ���� ������
		QueryPerformanceFrequency(&CpuFrequency);

		// ���α׷��� ���������� ��������� ������ (���� ������)
		QueryPerformanceCounter(&PrevFrequency);
	}
		
	void Time::Update()
	{
		// ���� ������
		QueryPerformanceCounter(&CurrentFrequency);

		//differenceFrequency(���ݺ��� �ǽ��� ������) : ���� ������ - ��������
		float differenceFrequency = static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);
		
		// DeltaTimeValue(���α׷��� ����Ǵ� �ð�(�ӵ�)) : �ǽ��������� / ����������
		DeltaTimeValue = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart);

		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;


	}
	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;

		time += DeltaTimeValue;
		float fps = 1.0f / DeltaTimeValue;

		// wchar �ʱ�ȭ�� �տ� L�� �ٿ��� ��
		// ����� ����ε� �츮�� �ϵ��ڵ��� ������ ���ͷ��̶�� ��
		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"Time : %d", (int)fps);
		
		int len = wcsnlen_s(str, 50);


		TextOut(hdc, 0, 0, str, len);
	}
}