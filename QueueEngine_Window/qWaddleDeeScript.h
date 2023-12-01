#pragma once
#include "..\\QueueEngine_SOURCE\\qScript.h"
#include "..\\QueueEngine_SOURCE\\qTransform.h"


namespace Q 
{
	class WaddleDeeScript : public Script
	{
	public:
		enum class eState
		{
			Walk
		};

		enum class eDirection
		{
			Left,
			Right,
			End
		};

		WaddleDeeScript();
		~WaddleDeeScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void walk();
		void playWalkAnimationBydirection(eDirection dir);
		void translate(Transform* tr);

	private:
		eState mState;
		class Animator* mAnimator;
		eDirection mDirection;
		float mTime;

	};

}


