#include "qScene.h"
#include "CommonInclude.h"
#include "qCollisionManager.h"

namespace Q
{
	Scene::Scene()
		:mLayers{}
	{
		createLayers();
	}

	Scene::~Scene()
	{
	}

	void Scene::Initialize()
	{
		for (Layer* Layer : mLayers)
		{
			if (Layer == nullptr)
			{
				continue;
			}

			Layer->Initialize();
		}
	}
	void Scene::Update()
	{
		/*for (size_t i = 0; i < mGameObjects.size(); i++)
		{
			mGameObjects[i]->Update();
		}*/
		
		// 범위 기반 for문
		for (Layer* Layer : mLayers)
		{
			if (Layer == nullptr)
			{
				continue;
			}

			Layer->Update();
		}
	}
	void Scene::LateUpdate()
	{
		for (Layer* Layer : mLayers)
		{
			if (Layer == nullptr)
			{
				continue;
			}

			Layer->LateUpdate();
		}
	}
	void Scene::Render(HDC hdc)
	{
		for (Layer* Layer : mLayers)
		{
			if (Layer == nullptr)
			{
				continue;
			}

			Layer->Render(hdc);
		}
	}

	void Scene::Destroy()
	{
		for (Layer* Layer : mLayers)
		{
			if (Layer == nullptr)
			{
				continue;
			}

			Layer->Destroy();
		}
	}



	void Scene::AddGameObject(GameObject* gameObj, const eLayerType type)
	{
		mLayers[(UINT)type]->AddGameObject(gameObj);
	}

	void Scene::EraseGameObject(GameObject* gameObj)
	{
		eLayerType layerType = gameObj->GetLayerType();
		mLayers[(UINT)layerType]->EraseGameObejct(gameObj);
	}

	void Scene::createLayers()
	{
		mLayers.resize((UINT)enums::eLayerType::Max);
		for (size_t i = 0; i < (UINT)enums::eLayerType::Max; i++)
		{
			mLayers[i] = new Layer();
		}
	}


	void Scene::OnEnter()
	{

	}

	void Scene::OnExit()
	{
		CollisionManager::Clear();
	}

}