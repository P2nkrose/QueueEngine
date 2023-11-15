#include "PlayScene.h"
#include "GameObject_player02.h"

namespace Q
{
	PlayScene::PlayScene()
	{

	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		for (int i = 0; i < 100; i++)
		{
			GameObject02* obj = new GameObject02();
			obj->SetPosition(rand() % 1600, rand() % 900);
			AddGameObject(obj);
		}
		
	}


	void PlayScene::Update()
	{
		Scene::Update();

		/*for (GameObject02* gameobj : mGameObjects)
		{
			gameobj->Update();
		}*/
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}