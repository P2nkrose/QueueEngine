#pragma once

#include "CommonInclude.h"
#include "GameObject_player01.h"
#include "qGameObject.h"
#include "GameObject_monster01.h"
#include "qShoot.h"


namespace Q
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		void clearRenderTarget();
		void copyRenderTarget(HDC source, HDC dest);


	private:
		HWND mHwnd;
		HDC mHdc;

		// 도화지
		HDC mBackHdc;	// 하나 더만듬
		HBITMAP mBackBitmap;

		// 해상도
		UINT mWidth;
		UINT mHeight;

		// 플레이어
		//GameObject01 mPlayer1;
		//GameObject02 mPlayer2;
		//GameObject03 mMonster1;

		//std::vector<GameObject02*> mGameObjects;
		//std::vector<Scene*> mScenes;


		//Shoot* mBullet;
		//std::vector<Shoot*> mBullets;
		
	};
}
	



