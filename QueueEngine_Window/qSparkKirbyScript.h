#pragma once
#include "qScript.h"

namespace Q
{
	class SparkKirbyScript : public Script
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

		SparkKirbyScript();
		~SparkKirbyScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	public:
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


