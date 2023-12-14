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
		class Kirby* mKirby;
		class WindObject* windObject;

		// 아이스커비
		class IceKirby* mIceKirby;

		// 스파크커비
		class SparkKirby* mSparkKirby;

		// 메탈커비
		class MetalKirby* mMetalKirby;
		
		// 타이틀
		class Stage* mStage;
		class BackGround* mBackGround;
		class BackGround* titleUnder;
	};
}



