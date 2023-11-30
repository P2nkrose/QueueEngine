#include "qStage.h"
#include "qInput.h"
#include "qTransform.h"
#include "qTime.h"

namespace Q 
{
	void Stage::Initialize()
	{
		GameObject::Initialize();
	}

	void Stage::Update()
	{
		GameObject::Update();
	}

	void Stage::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Stage::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}