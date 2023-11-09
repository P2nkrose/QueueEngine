#include "GameObject_player02.h"

namespace Q
{
	GameObject02::GameObject02()
	{
	}

	GameObject02::~GameObject02()
	{
	}

	void GameObject02::Update()
	{
		if (GetAsyncKeyState('A') & 0x8000)
		{
			pX -= 0.01f;
		}

		if (GetAsyncKeyState('D') & 0x8000)
		{
			pX += 0.01f;
		}

		if (GetAsyncKeyState('W') & 0x8000)
		{
			pY -= 0.01f;
		}

		if (GetAsyncKeyState('S') & 0x8000)
		{
			pY += 0.01f;
		}
	}

	void GameObject02::LateUpdate()
	{
	}

	void GameObject02::Render(HDC hdc)
	{
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		SelectObject(hdc, blueBrush);

		Ellipse(hdc, 300 + pX, 100 + pY, 400 + pX, 200 + pY);

		SelectObject(hdc, oldBrush);
		DeleteObject(blueBrush);
	}

}
