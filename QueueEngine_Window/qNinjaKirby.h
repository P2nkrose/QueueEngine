#pragma once
#include "..\\QueueEngine_SOURCE\\qGameObject.h"

namespace Q
{
	class NinjaKirby : public GameObject
	{
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	};

}
