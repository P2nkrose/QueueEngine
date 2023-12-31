#pragma once
#include "qSceneManager.h"
#include "qPlayScene.h"
#include "qPlayScene2.h"
#include "qTitleScene.h"
#include "qIntroScene.h"
#include "qEndScene.h"

namespace Q
{
	void LoadScenes()
	{
		//SceneManager::CreateScene<IntroScene>(L"IntroScene");
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<PlayScene2>(L"PlayScene2");
		//SceneManager::CreateScene<EndScene>(L"EndScene");
		//SceneManager::LoadScene(L"IntroScene");
		SceneManager::LoadScene(L"PlayScene");
	}
}

