#include "qScene.h"
#include "CommonInclude.h"

namespace Q
{
	Scene::Scene()
		:mGameObjects{}
	{
	}
	Scene::~Scene()
	{
	}
	void Scene::Initialize()
	{
	}
	void Scene::Update()
	{
		/*for (size_t i = 0; i < mGameObjects.size(); i++)
		{
			mGameObjects[i]->Update();
		}*/
		
		// 범위 기반 for문
		for (GameObject02* gameobj : mGameObjects)
		{
			gameobj->Update();
		}
	}
	void Scene::LateUpdate()
	{
		for (GameObject02* gameobj : mGameObjects)
		{
			gameobj->LateUpdate();
		}
	}
	void Scene::Render(HDC hdc)
	{
		for (GameObject02* gameobj : mGameObjects)
		{
			gameobj->Render(hdc);
		}
	}


	void Scene::AddGameObject(GameObject02* gameObject)
	{
		mGameObjects.push_back(gameObject);
	}
}