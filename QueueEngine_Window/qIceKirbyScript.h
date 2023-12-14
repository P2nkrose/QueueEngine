#pragma once
#include "qScript.h"

namespace Q
{
	class IceKirbyScript : public Script
	{
	public:

		enum class eState
		{
			Stand,
			Walk,
			Down,
			Tackle,
			Tackle2,
			Jump,
			Effect,
			Effect2,
		};


		enum class eDirection
		{
			Right,
			Left,
			Down,
		};

		IceKirbyScript();
		~IceKirbyScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void Effect2();
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
		float mDeathTime;
	};
}



