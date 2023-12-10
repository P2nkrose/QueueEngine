#pragma once
#include "qScene.h"

namespace Q
{
	class TitleScene : public Scene
	{
	public:
		TitleScene();
		~TitleScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		class BackGround* title;
		class BackGround* titleUnder;
		class Player* mKirby;

	};
}



