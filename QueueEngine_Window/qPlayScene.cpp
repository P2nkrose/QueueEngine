#include "qPlayScene.h"
#include "qGameObject.h"
#include "qPlayer.h"
#include "qTransform.h"
#include "qSpriteRenderer.h"
#include "qInput.h"
#include "qEndScene.h"
#include "qSceneManager.h"
#include "qTitleScene.h"
#include "qObject.h"
#include "qTexture.h"
#include "qResources.h"
#include "qPlayerScript.h"
#include "qCamera.h"
#include "qRenderer.h"

namespace Q
{
	PlayScene::PlayScene()
		: mPlayer(nullptr)
	{

	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(381.0f, 283.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;
		
		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player, Vector2(0.0f, 320.0f));
		SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
		sr->SetSize(Vector2(3.0f, 3.0f));
		mPlayer->AddComponent<PlayerScript>();

		graphics::Texture* kirbyTexture = Resources::Find<graphics::Texture>(L"Kirby");
		sr->SetTexture(kirbyTexture);


		GameObject* bg = object::Instantiate<GameObject>(enums::eLayerType::BackGround);
		SpriteRenderer* bgsr = bg->AddComponent<SpriteRenderer>();
		bgsr->SetSize(Vector2(1.9f, 1.7f));

		graphics::Texture* bgTexture = Resources::Find<graphics::Texture>(L"Map");
		bgsr->SetTexture(bgTexture);
		
		Scene::Initialize();
		
	}


	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		//wchar_t str[50] = L"Play Scene";
		//TextOut(hdc, 0, 0, str, 10);
	}

	void PlayScene::OnEnter()
	{
	}

	void PlayScene::OnExit()
	{
		//Transform* tr = bg->GetComponent<Transform>();
		//tr->SetPosition(Vector2(0, 0));
	}
}