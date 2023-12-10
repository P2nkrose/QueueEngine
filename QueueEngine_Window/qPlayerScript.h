#pragma once
#include "qScript.h"
#include "qWindObjectScript.h"

namespace Q
{
	class PlayerScript : public Script
	{
	public:

		enum class eState
		{
			Stand,
			Walk,
			Down,
			Tackle,
			Jump,
			Wind,
			Wind2
		};

		enum class eDirection
		{
			Right,
			Left,
			Down,
		};

		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void Wind2();

		void WindEffect();

	private:
		void Stand();
		void Walk();
		void Down();
		void Wind();
		void Tackle();


	private:
		eState mState;
		eDirection mDirection;
		class Animator* mAnimator;
		bool mOneTime;
		float mDeathTime;

		//void (*StartEvent)();
		//void (*CompleteEvent)();
		//void (*EndEvent)();
	};
}



