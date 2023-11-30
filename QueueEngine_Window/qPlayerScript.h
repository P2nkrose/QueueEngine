#pragma once
#include "qScript.h"

namespace Q
{
	class PlayerScript : public Script
	{
	public:

		enum class eState
		{
			Stand,
			Walk,
			SitDown,
			Jump,
			Eat
		};

		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void stand();
		void move();

	private:
		eState mState;
		class Animator* mAnimator;
	};
}



