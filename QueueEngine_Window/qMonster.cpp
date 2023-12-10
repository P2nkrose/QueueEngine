#include "qMonster.h"
#include "qInput.h"
#include "qTransform.h"
#include "qTime.h"

namespace Q
{
	void Monster::Initialize()
	{
		GameObject::Initialize();
	}

	void Monster::Update()
	{
		GameObject::Update();
	}

	void Monster::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Monster::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}