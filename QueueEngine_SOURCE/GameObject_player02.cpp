#include "GameObject_player02.h"
#include "qInput.h"
#include "qTime.h"

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
		const int speed = 100.0f;
		if (Input::GetKey(eKeyCode::A))
		{
			pX -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::D))
		{
			pX += speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::W))
		{
			pY -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::S))
		{
			pY += speed * Time::DeltaTime();
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
