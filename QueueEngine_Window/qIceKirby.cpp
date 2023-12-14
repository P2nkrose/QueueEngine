#include "qIceKirby.h"
#include "qInput.h"
#include "qTransform.h"
#include "qTime.h"

namespace Q
{
	void IceKirby::Initialize()
	{
		GameObject::Initialize();
	}

	void IceKirby::Update()
	{
		GameObject::Update();
	}

	void IceKirby::LateUpdate()
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

	void IceKirby::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
