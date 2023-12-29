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
			Tackle2,
			Dash,
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
		void Tackle2();

	public:
		void OnCollisionEnter(class Collider* other) override;
		void OnCollisionStay(class Collider* other) override;
		void OnCollisionExit(class Collider* other) override;

		void SetPixelMapTexture(graphics::Texture* texture) { mPixelMap = texture; }

	private:
		void Stand();
		void Walk();
		void Down();
		void Wind();
		void Tackle();
		void Dash();


	private:
		eState mState;
		eDirection mDirection;
		class Animator* mAnimator;
		bool mOneTime;
		float mDeathTime;

		graphics::Texture* mPixelMap;

		//void (*StartEvent)();
		//void (*CompleteEvent)();
		//void (*EndEvent)();
	};
}



