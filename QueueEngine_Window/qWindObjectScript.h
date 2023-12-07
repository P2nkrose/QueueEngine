#pragma once
#include "qScript.h"

namespace Q
{
	class WindObjectScript : public Script
	{
	public:

		enum class eState
		{
			WindObject,
			False,
		};

		enum class eDirection
		{
			Right,
			Left,
		};

		WindObjectScript();
		~WindObjectScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetEffect(GameObject* effect) { mEffect = effect; }

	private:
		void WindObject();

	private:

		eState mState;
		eDirection mDirection;
		class Animator* mAnimator;

		GameObject* mEffect;

	};
}



