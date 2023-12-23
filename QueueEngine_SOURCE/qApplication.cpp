#include "qApplication.h"
#include "qInput.h"
#include "qTime.h"
#include "qSceneManager.h"
#include "qResources.h"
#include "qCollisionManager.h"

#include <dshow.h>
#pragma comment(lib, "Strmiids.lib")

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
		adjustWindowRect(hwnd, width, height);
		createBuffer(width, height);
		initializeEtc();

		CollisionManager::Initialize();
		SceneManager::Initialize();
		
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();

		Destroy();
	}

	void Application::Update()
	{
		Input::Update();
		Time::Update();

		CollisionManager::Update();
		SceneManager::Update();

		//mPlayer1.Update();
		//mPlayer2.Update();
		//mMonster1.Update();

		/*for (size_t i = 0; i < mGameObjects.size(); i++)
		{
			mGameObjects[i]->Update();
		}*/



		// �Ѿ�
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
		CollisionManager::LateUpdate();
		SceneManager::LateUpdate();
	}

	void Application::Render()
	{
		clearRenderTarget();
		//Time::Render(mBackHdc);

		CollisionManager::Render(mBackHdc);

		SceneManager::Render(mBackHdc);

		//mPlayer1.Render(mBackHdc);
		//mPlayer2.Render(mBackHdc);
		//mMonster1.Render(mBackHdc);

		/*for (int i = 0; i < mGameObjects.size(); i++)
		{
			mGameObjects[i]->Render(mBackHdc);
		}*/


		// �Ѿ�
		/*if (!mBullets.empty())
		{
			for (int i = 0; i < mBullets.size(); i++)
			{
				mBullets[i]->Render(mBackHdc);
			}
		}*/
		// Backbuffer�� �ִ°��� ���� buffer�� ����
		copyRenderTarget(mBackHdc, mHdc);

	}

	void Application::Destroy()
	{
		SceneManager::Destroy();
	}

	void Application::clearRenderTarget()
	{
		// clear
		Rectangle(mBackHdc, -1, -1, 1601, 901);
	}

	void Application::copyRenderTarget(HDC source, HDC dest)
	{
		// BackBitmap�� �ִ°� ���� ��Ʈ�ʿ� ����
		BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
	}
	
	void Application::adjustWindowRect(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0, 0, width, height };

		// �� ũ�⸦ ������ ũ��� �ϰڴ�. (���� ũ�⺸�� Ŀ��)  WS_OVERLAPPEDWINDOW : ������ ��Ÿ��, false : �޴���
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 540, 100, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);
	}

	void Application::createBuffer(UINT width, UINT height)
	{
		// ������ �ػ󵵿� �´� �ϳ� �� ���� ��Ʈ��(��ȭ��) ����
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		// ���Ʈ���� ����ų DC ����
		mBackHdc = CreateCompatibleDC(mHdc);

		// ����
		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);
	}

	void Application::initializeEtc()
	{
		Input::Initialize();
		Time::Initialize();
	}
}


