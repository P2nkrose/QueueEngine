#pragma once

#include "qEntity.h"
#include "qComponent.h"

namespace Q 
{
	using namespace math;
	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	
		void SetPos(Vector2 pos) { mPosition.x = pos.x;  mPosition.y = pos.y; }
		Vector2 GetPosition() { return mPosition; }

	private:

		Vector2 mPosition;

	};
}



