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
#include "qMath.h"
#include "qBackGround.h"
#include "qStage.h"
#include "qAnimator.h"
#include "qWaddleDee.h"
#include "qWaddleDeeScript.h"

namespace Q
{
	PlayScene::PlayScene()
		: mPlayer(nullptr)
		, titleUnder(nullptr)
		, mStage(nullptr)
		, mBackGround(nullptr)
	{

	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{

		// 카메라
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(277.5f, 425.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;
		
		// 배경
		mBackGround = object::Instantiate<BackGround>(enums::eLayerType::BackGround);
		SpriteRenderer* bgsr = mBackGround->AddComponent<SpriteRenderer>();

		graphics::Texture* bgTexture = Resources::Find<graphics::Texture>(L"BackGround");
		bgsr->SetTexture(bgTexture);
		bgsr->SetSize(Vector2::Half);

		// 맵
		mStage = object::Instantiate<Stage>(enums::eLayerType::Stage);
		SpriteRenderer* stageSr = mStage->AddComponent<SpriteRenderer>();
		stageSr->SetSize(Vector2::Half);

		graphics::Texture* stageTexture = Resources::Find<graphics::Texture>(L"Stage");
		stageSr->SetTexture(stageTexture);

		// 커비
		
		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
		mPlayer->AddComponent<PlayerScript>();

		graphics::Texture* standTexture = Resources::Find<graphics::Texture>(L"StandKirby");
		graphics::Texture* rightTexture = Resources::Find<graphics::Texture>(L"RightWalkKirby");
		graphics::Texture* leftTexture = Resources::Find<graphics::Texture>(L"LeftWalkKirby");
		Animator* animator = mPlayer->AddComponent<Animator>();
		animator->CreateAnimation(L"Stand", standTexture,
			Vector2(0.0f, 0.0f), Vector2(29.26262627f, 32.0f), Vector2::Zero, 3, 0.5f);
		
		animator->CreateAnimation(L"RightWalk", rightTexture,
			Vector2(0.0f, 0.0f), Vector2(28.65f, 32.0f), Vector2::Zero, 10, 0.2f);

		animator->CreateAnimation(L"LeftWalk", leftTexture,
			Vector2(0.0f, 0.0f), Vector2(28.65f, 32.0f), Vector2::Zero, 10, 0.2f);

		animator->PlayAnimation(L"Stand", true);

		mPlayer->GetComponent<Transform>()->SetScale(Vector2(1.5f, 1.5f));
		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(30.0f, 269.0f));
		
		// 몬스터 (Waddle Dee)
		WaddleDee* wd = object::Instantiate<WaddleDee>(enums::eLayerType::Monster);
		wd->AddComponent<WaddleDeeScript>();
		
		graphics::Texture* leftDeeTex = Resources::Find<graphics::Texture>(L"LeftDee");
		graphics::Texture* rightDeeTex = Resources::Find<graphics::Texture>(L"RightDee");

		Animator* deeAnimator = wd->AddComponent<Animator>();
		deeAnimator->CreateAnimation(L"LeftDee", leftDeeTex,
			Vector2::Zero, Vector2(24.0f, 23.5f), Vector2::Zero, 8, 0.3f);

		deeAnimator->CreateAnimation(L"RightDee", rightDeeTex,
			Vector2::Zero, Vector2(23.8f, 23.0f), Vector2::Zero, 8, 0.3f);

		deeAnimator->PlayAnimation(L"LeftDee", true);

		wd->GetComponent<Transform>()->SetScale(Vector2(1.7f, 1.7f));
		wd->GetComponent<Transform>()->SetPosition(Vector2(300.0f, 269.0f));

		// 이펙트
		//mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
		//mPlayer->AddComponent<PlayerScript>();

		//graphics::Texture* kirbyTexture = Resources::Find<graphics::Texture>(L"Effect");
		//Animator* animator = mPlayer->AddComponent<Animator>();
		//animator->CreateAnimation(L"KirbyMove", kirbyTexture,
		//	Vector2(0.0f, 0.0f), Vector2(416.0f, 241.0f), Vector2::Zero, 9, 0.1f);
		//animator->PlayAnimation(L"KirbyMove", true);

		//mPlayer->GetComponent<Transform>()->SetPosition(Vector2(100.0f, 100.0f));
		//mPlayer->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));
		//mPlayer->GetComponent<Transform>()->SetRotation(30.0f);


		// 고양이 Test
		//mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
		//mPlayer->AddComponent<PlayerScript>();

		//graphics::Texture* CatTexture = Resources::Find<graphics::Texture>(L"Cat");
		//Animator* animator = mPlayer->AddComponent<Animator>();
		//animator->CreateAnimation(L"CatTest", CatTexture,
		//	Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.5f);
		//animator->PlayAnimation(L"CatTest", true);
		//mPlayer->GetComponent<Transform>()->SetScale(Vector2(3.0f, 3.0f));


		// 아래화면

		titleUnder = object::Instantiate<BackGround>(enums::eLayerType::BackGround, Vector2(0.0f, 405.0f));
		SpriteRenderer* titleudsr = titleUnder->AddComponent<SpriteRenderer>();

		graphics::Texture* TitleUnderTexture = Resources::Find<graphics::Texture>(L"Under");
		titleudsr->SetSize(Vector2::Half);
		titleudsr->SetTexture(TitleUnderTexture);

		
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