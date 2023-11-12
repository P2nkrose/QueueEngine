#include "Application.h"
#include "qInput.h"
#include "qTime.h"

namespace Q
{
	Application::Application()
	   :mHwnd(nullptr),
		mHdc(nullptr),
		mWidth(0),
		mHeight(0),
		mBackHdc(NULL),
		mBackBitmap(NULL)
	{
	}

	Application::~Application()
	{
	}

	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = {0, 0, width, height};
		
		// �� ũ�⸦ ������ ũ��� �ϰڴ�. (���� ũ�⺸�� Ŀ��)  WS_OVERLAPPEDWINDOW : ������ ��Ÿ��, false : �޴���
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);

		// ������ �ػ󵵿� �´� �ϳ� �� ���� ��Ʈ��(��ȭ��) ����
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);
		 
		// ���Ʈ���� ����ų DC ����
		mBackHdc = CreateCompatibleDC(mHdc);

		// ����
		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);

		mPlayer1.SetPosition(0, 0);
		mPlayer2.SetPosition(0, 0);
		mMonster1.SetPosition(0, 0);

		Input::Initialize();
		Time::Initialize();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		Input::Update();
		Time::Update();

		mPlayer1.Update();
		mPlayer2.Update();
		mMonster1.Update();
	}

	void Application::LateUpdate()
	{
	}

	void Application::Render()
	{
		Rectangle(mBackHdc, 0, 0, 1600, 900);

		Time::Render(mBackHdc);

		mPlayer1.Render(mBackHdc);
		mPlayer2.Render(mBackHdc);
		mMonster1.Render(mBackHdc);

		// BackBitmap�� �ִ°� ���� ��Ʈ�ʿ� ����
		BitBlt(mHdc, 100, 100, mWidth - 100, mHeight - 100, mBackHdc, 0, 0, SRCCOPY);
	}
}


