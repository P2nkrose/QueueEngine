#include "qEndScene.h"
#include "qGameObject.h"
#include "qPlayer.h"
#include "qTransform.h"
#include "qSpriteRenderer.h"

namespace Q
{
	EndScene::EndScene()
	{
	}
	EndScene::~EndScene()
	{
	}
	void EndScene::Initialize()
	{
		{
			Player* bg = new Player();
			Transform* tr = bg->AddComponent<Transform>();
			tr->SetPos(Vector2(0, 0));
			tr->SetName(L"TR");

			SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");
			sr->ImageLoad(L"Q:\\assortrock\\Win32API\\QueueEngine\\Resources\\EndScene.png");


			AddGameObject(bg);
		}
	}
	void EndScene::Update()
	{
		Scene::Update();
	}
	void EndScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void EndScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}