#include "qIceObject.h"
#include "qInput.h"
#include "qTransform.h"
#include "qTime.h"

namespace Q
{
	void IceObject::Initialize()
	{
		GameObject::Initialize();
	}

	void IceObject::Update()
	{
		GameObject::Update();
	}

	void IceObject::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void IceObject::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}