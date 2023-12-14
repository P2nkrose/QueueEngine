#pragma once
#include "qComponent.h"


namespace Q
{
	class Script : public Component
	{
	public:

		Script();
		~Script();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(class Collider* other);
		virtual void OnCollisionStay(class Collider* other);
		virtual void OnCollisionExit(class Collider* other);

	private:
	};
}



