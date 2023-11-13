#include "qShoot.h"
#include "qInput.h"
#include "qTime.h"

namespace Q
{

	Shoot::Shoot()
		:sX(0), sY(0)
	{
	}

	Shoot::~Shoot()
	{
	}

	void Shoot::Update()
	{
		const int speed = 100.0f;
		sY -= speed * Time::DeltaTime();
	}

	void Shoot::LateUpdate()
	{

	}

	void Shoot::Render(HDC hdc)
	{
		
		HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));

		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, redBrush);

		SelectObject(hdc, redBrush);

		Ellipse(hdc, 10+sX, 10+sY, 20+sX, 20+sY);

		SelectObject(hdc, oldBrush);
		DeleteObject(redBrush);
		
		

	}

}