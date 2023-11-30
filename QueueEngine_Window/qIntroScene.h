#pragma once
#include "qScene.h"

namespace Q
{
	class IntroScene : public Scene
	{
	public:

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;


	private:

	};
}

