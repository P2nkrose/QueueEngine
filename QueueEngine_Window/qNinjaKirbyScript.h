#pragma once
#include "qScript.h"

namespace Q
{
	class NinjaKirbyScript : public Script
	{
	public:
		enum class eState
		{
			Stand,
			Walk,
			Down,
			Tackle,
			Jump,
			Effect
		};

		enum class eDirection
		{
			Right,
			Left,
			Down,
		};

		NinjaKirbyScript();
		~NinjaKirbyScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void Tackle2();


	private:
		void Stand();
		void Walk();
		void Down();
		void Effect();
		void Tackle();

	private:
		eState mState;
		eDirection mDirection;
		class Animator* mAnimator;
		bool mOneTime;

	};
}



