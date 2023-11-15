#pragma once
#include "qSceneManager.h"
#include "PlayScene.h"

namespace Q
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<EndScene>(L"PlayScene");
		//SceneManager::CreateScene<TItleScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}

