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
		class Kirby* mKirby;
		class WindObject* windObject;

		// ���̽�Ŀ��
		class IceKirby* mIceKirby;

		// ����ũĿ��
		class SparkKirby* mSparkKirby;

		// ��ŻĿ��
		class MetalKirby* mMetalKirby;
		
		// Ÿ��Ʋ
		class Stage* mStage;
		class BackGround* mBackGround;
		class BackGround* titleUnder;
	};
}



