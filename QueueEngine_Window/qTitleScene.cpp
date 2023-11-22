#include "qTitleScene.h"
#include "qGameObject.h"
#include "qPlayer.h"
#include "qTransform.h"
#include "qSpriteRenderer.h"
#include "qInput.h"
#include "qPlayScene.h"
#include "qSceneManager.h"
#include "qObject.h"

namespace Q
{
	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{
		{
			//Player* bg1 = new Player();
			//Transform* tr = bg1->AddComponent<Transform>();
			//tr->SetPosition(Vector2(0, 0));
			//tr->SetName(L"TR1");

			//SpriteRenderer* sr = bg1->AddComponent<SpriteRenderer>();
			//sr->SetName(L"SR1");
			//sr->ImageLoad(L"Q:\\assortrock\\Win32API\\QueueEngine\\Resources\\TitleScene.png");


			//AddGameObject(bg1, enums::eLayerType::BackGround);
			bg = object::Instantiate<Player>(enums::eLayerType::BackGround, Vector2(0, 0));
			title = object::Instantiate<Player>(enums::eLayerType::Title, Vector2(0, 0));

			SpriteRenderer* ti = title->AddComponent<SpriteRenderer>();
			ti->ImageLoad(L"Q:\\assortrock\\Win32API\\QueueEngine\\Resources\\Title.png");

			SpriteRenderer* ba = bg->AddComponent<SpriteRenderer>();
			ba->ImageLoad(L"Q:\\assortrock\\Win32API\\QueueEngine\\Resources\\BackScene.png");
		}
	}

	void TitleScene::Update()
	{
		Scene::Update();
	}

	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();
		
		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
	}

	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"Title Scene";
		TextOut(hdc, 0, 0, str, 11);
	}
}