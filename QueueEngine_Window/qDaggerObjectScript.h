#pragma once
#include "qScript.h"
#include "qNinjaKirbyScript.h"
#include "qEnums.h"

namespace Q
{
	class DaggerObjectScript : public Script
	{
	public:

		enum class eState
		{
			DaggerObject,
			False,
		};

		enum class eDirection
		{
			Right,
			Left,
			Down,
		};


		DaggerObjectScript();
		~DaggerObjectScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetEffect(GameObject* effect) { mEffect = effect; };

		
		eDirection mDirection;

	private:
		void DaggerOject();
		void False();


	private:
		eState mState;
	

		class Animator* mEffectAnimator;

		GameObject* mEffect;
	};
}


