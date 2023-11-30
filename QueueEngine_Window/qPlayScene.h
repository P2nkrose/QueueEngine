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
		class Player* mPlayer;
		class Stage* mStage;
		class BackGround* mBackGround;
		class BackGround* titleUnder;
	};
}



