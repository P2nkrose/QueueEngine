#include "qDaggerObject.h"
#include "qInput.h"
#include "qTransform.h"
#include "qTime.h"

namespace Q
{
	void DaggerObject::Initialize()
	{
		GameObject::Initialize();
	}

	void DaggerObject::Update()
	{
		GameObject::Update();
	}

	void DaggerObject::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void DaggerObject::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}