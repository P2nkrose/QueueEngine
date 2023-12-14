#pragma once
#include "qComponent.h"
#include "qGameObject.h"
#include "qLayer.h"
#include "qScene.h"
#include "qSceneManager.h"
#include "qTransform.h"


namespace Q::object
{
	template <typename T>
	static T* Instantiate(Q::enums::eLayerType type)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}


	template <typename T>
	static T* Instantiate(Q::enums::eLayerType type, math::Vector2 position)
	{
		T* gameObject = new T();
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

	
}