#include "qTitleScene.h"
#include "qGameObject.h"
#include "qPlayer.h"
#include "qTransform.h"
#include "qSpriteRenderer.h"
#include "qInput.h"
#include "qPlayScene.h"
#include "qSceneManager.h"
#include "qObject.h"
#include "qTexture.h"

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

			bg = object::Instantiate<Player>(enums::eLayerType::BackGround, Vector2(0, 0));
			SpriteRenderer* sr1 = bg->AddComponent<SpriteRenderer>();

			title = object::Instantiate<Player>(enums::eLayerType::BackGround, Vector2(0, 0));
			SpriteRenderer* sr2 = title->AddComponent<SpriteRenderer>();

			graphics::Texture* tex1 = new graphics::Texture();
			tex1->Load(L"Q:\\assortrock\\Win32API\\QueueEngine\\Resources\\BackScene.png");

			graphics::Texture* tex2 = new graphics::Texture();
			tex2->Load(L"Q:\\assortrock\\Win32API\\QueueEngine\\Resources\\Title.png");


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