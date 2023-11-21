#include "qScene.h"
#include "CommonInclude.h"

namespace Q
{
	Scene::Scene()
		:mLayers{}
	{
		mLayers.resize((UINT)eLayerType::Max);
		for (size_t i = 0; i < (UINT)eLayerType::Max; i++)
		{
			mLayers[i] = new Layer();
		}
		
		int a = 0;
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

	void Scene::OnEnter()
	{

	}

	void Scene::OnExit()
	{

	}

	void Scene::AddGameObject(GameObject* gameObj, const eLayerType type)
	{
		mLayers[(UINT)type]->AddGameObject(gameObj);
	}

}