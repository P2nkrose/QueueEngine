#pragma once
#include "qScript.h"


namespace Q
{
	class IceObjectScript : public Script
	{
	public:

		enum class eState
		{
			IceObject,
			False,
		};

		enum class eDirection
		{
			Right,
			Left,
		};

		IceObjectScript();
		~IceObjectScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetEffect(GameObject* effect) { mEffect = effect; };

	private:
		void IceObject();
		void False();



	private:
		eState mState;
		eDirection mDirection;
		class Animator* mEffectAnimator;

		GameObject* mEffect;
	};

}

