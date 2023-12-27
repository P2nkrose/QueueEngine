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
		// ��������� ���ӿ�����Ʈ�� �����ش�.
		activeScene->EraseGameObject(gameObject);

		// �ش� ���ӿ�����Ʈ�� -> DontDestroy������ �־��ش�.
		Scene* dontDestroyOnLoad = SceneManager::GetDontDestroyOnLoad();
		dontDestroyOnLoad->AddGameObject(gameObject, gameObject->GetLayerType());

		// ī�޶� ����
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(0.0f, 420.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		//cameraComp->SetTarget(gameObject);

	}
	
}