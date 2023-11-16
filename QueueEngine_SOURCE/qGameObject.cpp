#include "qGameObject.h"
#include "qInput.h"
#include "qTime.h"

namespace Q
{
	GameObject::GameObject()
	{
	}

	GameObject::~GameObject()
	{
		for (Component* comp : mComponents)
		{
			comp = nullptr;
			delete comp;
		}
	}

	void GameObject::Initialize()
	{
		for (Component* comp : mComponents)
		{
			comp->Initialize();
		}
	}

	void GameObject::Update()
	{
		for (Component* comp : mComponents)
		{
			comp->Update();
		}
	}

	void GameObject::LateUpdate()
	{
		for (Component* comp : mComponents)
		{
			comp->LateUpdate();
		}
	}

	void GameObject::Render(HDC hdc)
	{
		for (Component* comp : mComponents)
		{
			comp->Render(hdc);
		}
	}

}
