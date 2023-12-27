#pragma once
#include "qComponent.h"

namespace Q
{
	class Rigidbody : public Component
	{
	public:
		Rigidbody();
		~Rigidbody();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetMass(float mass) { mMass = mass; }
		void AddForce(Vector2 force) { mForce = force; }
		void SetGround(bool ground) { mbGround = ground; }
		void SetVelocity(Vector2 velocity) { mVelocity = velocity; }
		Vector2 GetVelocity() { return mVelocity; }

	private:
		bool mbGround;		// 바닥에 닿았는지 안닿았는지 bool
		float mMass;		// 질량
		float mFriction;	// 마찰

		Vector2 mForce;		// 힘
		Vector2 mAccelation;// 가속도
		Vector2 mVelocity;	// 속도 (방향을 포함함)
		Vector2 mGravity;	// 중력

	};
}

