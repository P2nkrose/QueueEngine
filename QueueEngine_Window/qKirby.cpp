#include "qKirby.h"
#include "qInput.h"
#include "qTransform.h"
#include "qTime.h"

namespace Q
{
	void Kirby::Initialize()
	{
		GameObject::Initialize();
	}

	void Kirby::Update()
	{
		GameObject::Update();
	}

	void Kirby::LateUpdate()
	{
		GameObject::LateUpdate();

		//if (Input::GetKey(eKeyCode::Right))
		//{
		//	Transform* tr = GetComponent<Transform>();
		//	Vector2 pos = tr->GetPosition();
		//	pos.x += 100.0f * Time::DeltaTime();
		//	tr->SetPosition(pos);
		//}


	}

	void Kirby::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
