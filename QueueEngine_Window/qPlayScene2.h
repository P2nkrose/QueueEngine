#pragma once
#include "qScene.h"

namespace Q
{
	class PlayScene2 : public Scene
	{
	public:
		PlayScene2();
		~PlayScene2();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:
		//�븻Ŀ��
		class Kirby* mKirby;
		class WindObject* windObject;

		// ���̽�Ŀ��
		class IceKirby* mIceKirby;

		// ����ũĿ��
		class SparkKirby* mSparkKirby;

		// ��ŻĿ��
		class MetalKirby* mMetalKirby;

		// ���� Ŀ��
		class NinjaKirby* mNinjaKirby;

		// Ÿ��Ʋ
		class Stage2* mStage2;
		class BackGround2* mBackGround2;

	};



}
