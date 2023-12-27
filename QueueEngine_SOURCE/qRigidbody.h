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
		bool mbGround;		// �ٴڿ� ��Ҵ��� �ȴ�Ҵ��� bool
		float mMass;		// ����
		float mFriction;	// ����

		Vector2 mForce;		// ��
		Vector2 mAccelation;// ���ӵ�
		Vector2 mVelocity;	// �ӵ� (������ ������)
		Vector2 mGravity;	// �߷�

	};
}

