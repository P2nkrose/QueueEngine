#pragma once
#include "qScript.h"
#include "qTransform.h"

namespace Q
{
	class WindObjectScript : public Script
	{
	public:

		enum class eState
		{
			WindObject,
			False,
		};

		enum class eDirection
		{
			Right,
			Left,
		};

		WindObjectScript();
		~WindObjectScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetEffect(GameObject* effect) { mEffect = effect; };

		///static Animator* GetEffectAnimator() { return mEffectAnimator; }

		virtual void OnCollisionEnter(class Collider* other);
		virtual void OnCollisionStay(class Collider* other);
		virtual void OnCollisionExit(class Collider* other);
		void translate(Transform* MonsterTr);

	private:
		void WindObject();
		void False();

	private:

		eState mState;
		eDirection mDirection;
		class Animator* mEffectAnimator;

		GameObject* mEffect;

	};
}



