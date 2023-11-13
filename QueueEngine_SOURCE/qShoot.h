#pragma once
#include "CommonInclude.h"
#include "GameObject_player01.h"

namespace Q
{
	class Shoot
	{
	public:
		Shoot();
		~Shoot();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y)
		{
			sX = x;
			sY = y;
		}

		float GetPositionX() { return sX; }
		float GetPositionY() { return sY; }

		
	private:

		float sX;
		float sY;
		

	};

}


