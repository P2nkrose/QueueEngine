#include "GameObject_monster01.h"
#include "qInput.h"

namespace Q
{
	GameObject03::GameObject03()
	{

	}

	GameObject03::~GameObject03()
	{
	}

	void GameObject03::Update()
	{

		if (mX <= 0 || mY <= 0)
		{
			dir = 0.01f;
		}
		else if (mX+100 >= 500 || mY+100 >= 700)
		{
			dir = -0.01f;
		}

		mX += dir;
		mY += dir;

	}

	void GameObject03::LateUpdate()
	{
	}

	void GameObject03::Render(HDC hdc)
	{
		HBRUSH greenBrush = CreateSolidBrush(RGB(0, 255, 0));

		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, greenBrush);

		Rectangle(hdc, mX+200, mY+200, mX+300, mY+300);

		SelectObject(hdc, oldBrush);
		DeleteObject(greenBrush);
	}

}
