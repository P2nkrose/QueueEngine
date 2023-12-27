#pragma once
#include "qComponent.h"
#include "qGameObject.h"
#include "qLayer.h"
#include "qScene.h"
#include "qSceneManager.h"
#include "qTransform.h"
#include "qCamera.h"
#include "qRenderer.h"


namespace Q::object
{
	template <typename T>
	static T* Instantiate(Q::enums::eLayerType type)
	{
		T* gameObject = new T();
		gameObject->SetLayerType(type);
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);


		return gameObject;
	}


	template <typename T>
	static T* Instantiate(Q::enums::eLayerType type, math::Vector2 position)
	{
		T* gameObject = new T();
		gameObject->SetLayerType(type);
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(position);

		return gameObject;
	}

	static void Destroy(GameObject* obj)
	{
		obj->death();
	}

	static void DontDestroyOnLoad(GameObject* gameObject)
	{
		Scene* activeScene = SceneManager::GetActiveScene();
		// 현재씬에서 게임오브젝트를 지워준다.
		activeScene->EraseGameObject(gameObject);

		// 해당 게임오브젝트를 -> DontDestroy씬으로 넣어준다.
		Scene* dontDestroyOnLoad = SceneManager::GetDontDestroyOnLoad();
		dontDestroyOnLoad->AddGameObject(gameObject, gameObject->GetLayerType());

		// 카메라 고정
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(0.0f, 420.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		//cameraComp->SetTarget(gameObject);

	}
	
}