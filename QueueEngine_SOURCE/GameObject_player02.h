#pragma once
#include "CommonInclude.h"


namespace Q
{
	class GameObject02
	{
	public:
		GameObject02();
		~GameObject02();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y)
		{
			pX = x;
			pY = y;
		}

		float GetPositionX() { return pX; }
		float GetPositionY() { return pY; }

	private:

		// ���ӿ�����Ʈ "�÷��̾�"�� ��ǥ
		float pX;
		float pY;
	};
}


