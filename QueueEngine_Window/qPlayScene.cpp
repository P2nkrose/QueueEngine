#include "qPlayScene.h"
#include "qGameObject.h"
#include "qPlayer.h"
#include "qTransform.h"
#include "qSpriteRenderer.h"

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
		{
			Player* p1 = new Player();
			Transform* tr = p1->AddComponent<Transform>();
			tr->SetPos(200, 400);
			tr->SetName(L"TR");

			SpriteRenderer* sr = p1->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");

			AddGameObject(p1);
		}

		{
			Player* p1 = new Player();
			Transform* tr = p1->AddComponent<Transform>();
			tr->SetPos(500, 600);
			tr->SetName(L"TR");

			SpriteRenderer* sr = p1->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");

			AddGameObject(p1);
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