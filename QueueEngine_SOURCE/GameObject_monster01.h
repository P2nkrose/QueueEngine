#pragma once
#include "CommonInclude.h"

namespace Q
{
	class GameObject03
	{
	public:
		GameObject03();
		~GameObject03();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}

		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }

	private:

		// 몬스터 좌표
		float mX;
		float mY;
		float dir;

	};
}


