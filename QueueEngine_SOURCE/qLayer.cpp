#include "qLayer.h"

namespace Q
{
	Layer::Layer()
		: mGameObjects{}
	{
	}

	Layer::~Layer()
	{
	}

	void Layer::Initialize()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
			{
				continue;
			}

			gameObj->Initialize();
		}
	}

	void Layer::Update()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
			{
				continue;
			}

			gameObj->Update();
		}
	}

	void Layer::LateUpdate()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
			{
				continue;
			}

			gameObj->LateUpdate();
		}
	}

	void Layer::Render(HDC hdc)
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
			{
				continue;
			}

			gameObj->Render(hdc);
		}
	}

	void Layer::Destroy()
	{
		for (GameObjectIter iter = mGameObjects.begin(); iter != mGameObjects.end();)
		{
			GameObject::eState active = (*iter)->GetActive();
			if (active == GameObject::eState::Dead)
			{
				iter = mGameObjects.erase(iter);
				continue;
			}
			iter++;
		}
	}

	void Layer::AddGameObject(GameObject* gameObject)
	{
		if (gameObject == nullptr)
		{
			return;
		}

		mGameObjects.push_back(gameObject);
	}
}