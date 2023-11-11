#pragma once

#include "CommonInclude.h"
#include "GameObject_player01.h"
#include "GameObject_player02.h"
#include "GameObject_monster01.h"


namespace Q
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd);
		void Run();

		void Update();
		void LateUpdate();
		void Render();


	private:
		HWND mHwnd;
		HDC mHdc;

		// 플레이어
		GameObject01 mPlayer1;
		GameObject02 mPlayer2;
		GameObject03 mMonster1;
	};
}
	



