#include "Application.h"
#include "qInput.h"
#include "qTime.h"
#include "qSceneManager.h"

namespace Q
{
	Application::Application()
	   :mHwnd(nullptr),
		mHdc(nullptr),
		mWidth(0),
		mHeight(0),
		mBackHdc(NULL),
		mBackBitmap(NULL)
		//mBullets{},
		//mGameObjects{}
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
		
		// 내 크기를 윈도우 크기로 하겠다. (실제 크기보다 커짐)  WS_OVERLAPPEDWINDOW : 윈도우 스타일, false : 메뉴바
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);

		// 윈도우 해상도에 맞는 하나 더 만든 비트맵(도화지) 생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);
		 
		// 백비트맵을 가리킬 DC 생성
		mBackHdc = CreateCompatibleDC(mHdc);

		// 연결
		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);

		//mPlayer1.SetPosition(0, 0);
		//mPlayer2.SetPosition(0, 0);
		//mMonster1.SetPosition(0, 0);

		/*for (int i = 0; i < 100; i++)
		{
			GameObject02* gameObj = new GameObject02();

			gameObj->SetPosition(rand() % 1600, rand() % 900);
			mGameObjects.push_back(gameObj);
		}*/

		SceneManager::Initialize();

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

		SceneManager::Update();

		//mPlayer1.Update();
		//mPlayer2.Update();
		//mMonster1.Update();

		/*for (size_t i = 0; i < mGameObjects.size(); i++)
		{
			mGameObjects[i]->Update();
		}*/



		// 총알
 		/*if (Input::GetKeyDown(eKeyCode::SPACE))
		{
			Shoot* shoot = new Shoot();
			mBullets.push_back(shoot);

			float x = mPlayer2.GetPositionX();
			float y = mPlayer2.GetPositionY();
			
			shoot->SetPosition(x+50, y);
		}*/

		//mBullet->Update();
		/*if (!mBullets.empty())
		{
			for (int i = 0; i < mBullets.size(); i++)
			{
				mBullets[i]->Update();
			}
		}*/
	}

	void Application::LateUpdate()
	{
		SceneManager::LateUpdate();
	}

	void Application::Render()
	{
		clearRenderTarget();

		Time::Render(mBackHdc);

		SceneManager::Render(mBackHdc);

		//mPlayer1.Render(mBackHdc);
		//mPlayer2.Render(mBackHdc);
		//mMonster1.Render(mBackHdc);

		/*for (int i = 0; i < mGameObjects.size(); i++)
		{
			mGameObjects[i]->Render(mBackHdc);
		}*/


		// 총알
		/*if (!mBullets.empty())
		{
			for (int i = 0; i < mBullets.size(); i++)
			{
				mBullets[i]->Render(mBackHdc);
			}
		}*/
		// Backbuffer에 있는것을 원본 buffer에 복사
		copyRenderTarget(mBackHdc, mHdc);

	}
	void Application::clearRenderTarget()
	{
		// clear
		Rectangle(mBackHdc, -1, -1, 1601, 901);
	}

	void Application::copyRenderTarget(HDC source, HDC dest)
	{
		// BackBitmap에 있는걸 원본 비트맵에 복사
		BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
	}
}


