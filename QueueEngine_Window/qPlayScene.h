#pragma once
#include "qScene.h"

namespace Q
{
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:
		// 노말커비
		class Player* mKirby;
		class WindObject* windObject;

		// 아이스커비
		class Player* mIceKirby;
		
		// 타이틀
		class Stage* mStage;
		class BackGround* mBackGround;
		class BackGround* titleUnder;
	};
}



