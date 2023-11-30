#include "qBackGround.h"
#include "qInput.h"
#include "qTransform.h"
#include "qTime.h"

namespace Q
{
	void BackGround::Initialize()
	{
		GameObject::Initialize();
	}

	void BackGround::Update()
	{
		GameObject::Update();
	}

	void BackGround::LateUpdate()
	{
		GameObject::LateUpdate();


	}

	void BackGround::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}