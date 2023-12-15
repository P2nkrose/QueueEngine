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
			Dagger,
			Sting,
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


	public:
		void Sting2();
		void Tackle2();
		void Stand();
		void Idle();

		eDirection GetDirection() { return mDirection; }

	private:
		void Walk();
		void Down();
		void Dagger();
		void Sting();
		void Tackle();

	private:
		eDirection mDirection;
		eState mState;
		class Animator* mAnimator;
		bool mOneTime;

		//std::vector<Shoot*> mBullets;
		//std::vector<DaggerObjectScript*> mDaggers;
	};
}



