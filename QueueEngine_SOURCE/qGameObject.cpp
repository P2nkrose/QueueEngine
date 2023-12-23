#include "qGameObject.h"
#include "qInput.h"
#include "qTime.h"
#include "qTransform.h"



namespace Q
{
	GameObject::GameObject()
		: mState(eState::Active)
		, mLayerType(eLayerType::None)
	{
		mComponents.resize((UINT)enums::eComponentType::End);
		initializeTransform();
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
			if (comp == nullptr)
			{
				continue;
			}

			comp->Initialize();
		}
	}

	void GameObject::Update()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
			{
				continue;
			}
			comp->Update();
		}
	}

	void GameObject::LateUpdate()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
			{
				continue;
			}
			comp->LateUpdate();
		}
	}

	void GameObject::Render(HDC hdc)
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
			{
				continue;
			}
			comp->Render(hdc);
		}
	}

	void GameObject::initializeTransform()
	{
		AddComponent<Transform>();
	}

}
