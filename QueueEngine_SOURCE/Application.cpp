#include "Application.h"
#include "qInput.h"
#include "qTime.h"

namespace Q
{
	Application::Application()
		:mHwnd(nullptr), mHdc(nullptr)
	{
	}

	Application::~Application()
	{
	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

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
		Time::Render(mHdc);

		mPlayer1.Render(mHdc);
		mPlayer2.Render(mHdc);
		mMonster1.Render(mHdc);
	}
}


