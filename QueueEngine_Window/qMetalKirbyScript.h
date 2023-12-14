#pragma once
#include "qScript.h"


namespace Q
{
	class MetalKirbyScript : public Script
	{
	public:
		
		enum class eState
		{
			Stand,
			Walk,
			Down,
			Tackle,
			Jump,
			Effect,
			EffectWalk,
			EffectStand,
		};

		enum class eDirection
		{
			Right,
			Left,
			Down,
		};

		MetalKirbyScript();
		~MetalKirbyScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void Tackle2();
		void Effect();
		void EffectWalk();

	private:
		void Stand();
		void Walk();
		void Down();
		void Tackle();

	private:
		eState mState;
		eDirection mDirection;
		class Animator* mAnimator;
		bool mOneTime;
	};

}

