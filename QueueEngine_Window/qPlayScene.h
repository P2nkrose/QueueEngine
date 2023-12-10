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
		// �븻Ŀ��
		class Player* mKirby;
		class WindObject* windObject;

		// ���̽�Ŀ��
		class Player* mIceKirby;
		
		// Ÿ��Ʋ
		class Stage* mStage;
		class BackGround* mBackGround;
		class BackGround* titleUnder;
	};
}



