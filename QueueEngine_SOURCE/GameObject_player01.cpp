#include "GameObject_player01.h"
#include "qInput.h"

namespace Q
{
	GameObject01::GameObject01()
	{
	}

	GameObject01::~GameObject01()
	{
	}

	void GameObject01::Update()
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			pX -= 0.1f;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			pX += 0.1f;
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			pY -= 0.1f;
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			pY += 0.1f;
		}
	}

	void GameObject01::LateUpdate()
	{
	}

	void GameObject01::Render(HDC hdc)
	{
		HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));

		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, redBrush);

		SelectObject(hdc, redBrush);

		Ellipse(hdc, 100+pX, 100+pY, 200+pX, 200+pY);

		SelectObject(hdc, oldBrush);
		DeleteObject(redBrush);
	}

}
