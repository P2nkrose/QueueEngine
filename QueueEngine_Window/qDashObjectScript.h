#pragma once
#include "qScript.h"

namespace Q
{
	class DashObjectScript : public Script
	{
	public:
		enum class eState
		{
			DashObject,
			False,
		};

		enum class eDirection
		{
			Right,
			Left,
		};

		DashObjectScript();
		~DashObjectScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetEffect(GameObject* effect) { mEffect = effect; };

	private:
		void DashObject();
		void False();

	private:

		eState mState;
		eDirection mDirection;
		class Animator* mEffectAnimator;

		GameObject* mEffect;
	};

}


