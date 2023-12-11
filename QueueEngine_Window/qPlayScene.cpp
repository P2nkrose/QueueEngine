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
#include "qMonster.h"
#include "qWaddleDeeScript.h"
#include "qWindObject.h"
#include "qWindObjectScript.h"
#include "qIceKirbyScript.h"
#include "qBoxCollider2D.h"
#include "qCollisionManager.h"

namespace Q
{
	PlayScene::PlayScene()
		: mKirby(nullptr)
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

		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Monster, true);

		// 카메라
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(50.0f, 420.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		
		
		// 배경
		mBackGround = object::Instantiate<BackGround>(enums::eLayerType::BackGround);
		SpriteRenderer* bgsr = mBackGround->AddComponent<SpriteRenderer>();

		graphics::Texture* bgTexture = Resources::Find<graphics::Texture>(L"BackGround");
		bgsr->SetTexture(bgTexture);
		bgsr->SetSize(Vector2::Two);
		mBackGround->GetComponent<Transform>()->SetPosition(Vector2(-318.0f, 70.0f));

		// 맵
		mStage = object::Instantiate<Stage>(enums::eLayerType::Stage);
		SpriteRenderer* stageSr = mStage->AddComponent<SpriteRenderer>();
		stageSr->SetSize(Vector2::Two);

		graphics::Texture* stageTexture = Resources::Find<graphics::Texture>(L"Stage");
		stageSr->SetTexture(stageTexture);

		mStage->GetComponent<Transform>()->SetPosition(Vector2(-318.0f, 70.0f));

		// 커비
		
		mKirby = object::Instantiate<Player>(enums::eLayerType::Player);
		PlayerScript* kirbyScript = mKirby->AddComponent<PlayerScript>();

		// 카메라 커비타겟
		cameraComp->SetTarget(mKirby);

		

		//Transform* stageTr = mStage->GetComponent<Transform>();

		//mPlayer->GetComponent<Transform>()->SetPosition(stageTr->GetPosition() + Vector2(50.0f, 360.0f));
		
		mKirby->GetComponent<Transform>()->SetPosition(Vector2(20.0f, 420.0f));

		// 커비 콜라이더
		BoxCollider2D* collider = mKirby->AddComponent<BoxCollider2D>();
		collider->SetOffset(Vector2(235.0f, -80.0f));


		graphics::Texture* RightStandKirbyTex = Resources::Find<graphics::Texture>(L"RightStandKirby");
		graphics::Texture* LeftStandKirbyTex = Resources::Find<graphics::Texture>(L"LeftStandKirby");
		graphics::Texture* RightDownKirbyTex = Resources::Find<graphics::Texture>(L"RightDownKirby");
		graphics::Texture* LefttDownKirbyTex = Resources::Find<graphics::Texture>(L"LeftDownKirby");
		graphics::Texture* RightWalkKirbyTex = Resources::Find<graphics::Texture>(L"RightWalkKirby");
		graphics::Texture* LeftWalkKirbyTex = Resources::Find<graphics::Texture>(L"LeftWalkKirby");
		graphics::Texture* LeftWindKirbyTex = Resources::Find<graphics::Texture>(L"LeftWindKirby");
		graphics::Texture* LeftWindKirbyTex2 = Resources::Find<graphics::Texture>(L"LeftWindKirby2");
		graphics::Texture* RightWindKirbyTex = Resources::Find<graphics::Texture>(L"RightWindKirby");
		graphics::Texture* RightWindKirbyTex2 = Resources::Find<graphics::Texture>(L"RightWindKirby2");
		graphics::Texture* RightTackleKirbyTex = Resources::Find<graphics::Texture>(L"RightTackleKirby");
		graphics::Texture* LeftTackleKirbyTex = Resources::Find<graphics::Texture>(L"LeftTackleKirby");



		Animator* animator = mKirby->AddComponent<Animator>();
		animator->CreateAnimation(L"RightStandKirby", RightStandKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(29.26262627f, 32.0f), Vector2::Zero, 3, 0.5f);

		animator->CreateAnimation(L"LeftStandKirby", LeftStandKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(29.26262627f, 32.0f), Vector2::Zero, 3, 0.5f);

		animator->CreateAnimation(L"RightDownKirby", RightDownKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(34.0f, 32.0f), Vector2::Zero, 3, 0.5f);

		animator->CreateAnimation(L"LeftDownKirby", LefttDownKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(34.0f, 32.0f), Vector2::Zero, 3, 0.5f);
		
		animator->CreateAnimation(L"RightWalkKirby", RightWalkKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(30.0f, 30.0f), Vector2::Zero, 10, 0.2f);

		animator->CreateAnimation(L"LeftWalkKirby", LeftWalkKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(30.0f, 30.0f), Vector2::Zero, 10, 0.2f);

		animator->CreateAnimation(L"LeftWindKirby", LeftWindKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(33.6f, 30.0f), Vector2::Zero, 5, 0.1f);

		animator->CreateAnimation(L"RightWindKirby", RightWindKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(33.6f, 30.0f), Vector2::Zero, 5, 0.1f);

		animator->CreateAnimation(L"LeftWindKirby2", LeftWindKirbyTex2,
			Vector2(0.0f, 0.0f), Vector2(34.5f, 31.0f), Vector2::Zero, 2, 0.1f);

		animator->CreateAnimation(L"RightWindKirby2", RightWindKirbyTex2,
			Vector2(0.0f, 0.0f), Vector2(34.5f, 31.0f), Vector2::Zero, 2, 0.1f);

		animator->CreateAnimation(L"LeftTackleKirby", LeftTackleKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(39.5f, 30.0f), Vector2::Zero, 2, 0.1f);

		animator->CreateAnimation(L"RightTackleKirby", RightTackleKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(39.5f, 30.0f), Vector2::Zero, 2, 0.1f);

		animator->GetCompleteEvent(L"RightWindKirby") = std::bind(&PlayerScript::Wind2, kirbyScript);
		animator->GetCompleteEvent(L"LeftWindKirby") = std::bind(&PlayerScript::Wind2, kirbyScript);



		animator->PlayAnimation(L"RightStandKirby", true);
		mKirby->SetActive(true);

		mKirby->GetComponent<Transform>()->SetScale(Vector2::Two);
		

		
		// 아이스커비
		mIceKirby = object::Instantiate<Player>(enums::eLayerType::Player);
		IceKirbyScript * icekirbyScript = mIceKirby->AddComponent<IceKirbyScript>();

		graphics::Texture* RightStandIceKirbyTex = Resources::Find<graphics::Texture>(L"RightStandIceKirby");
		graphics::Texture* LeftStandIceKirbyTex = Resources::Find<graphics::Texture>(L"LeftStandIceKirby");
		graphics::Texture* RightDownIceKirbyTex = Resources::Find<graphics::Texture>(L"RightDownIceKirby");
		graphics::Texture* LefttDownIceKirbyTex = Resources::Find<graphics::Texture>(L"LeftDownIceKirby");
		graphics::Texture* RightWalkIceKirbyTex = Resources::Find<graphics::Texture>(L"RightWalkIceKirby");
		graphics::Texture* LeftWalkIceKirbyTex = Resources::Find<graphics::Texture>(L"LeftWalkIceKirby");
		graphics::Texture* LeftEffectIceKirbyTex = Resources::Find<graphics::Texture>(L"LeftEffectIceKirby");
		graphics::Texture* RightEffectIceKirbyTex = Resources::Find<graphics::Texture>(L"RightEffectIceKirby");
		graphics::Texture* RightEffectIceKirbyTex2 = Resources::Find<graphics::Texture>(L"RightEffectIceKirby2");
		graphics::Texture* LeftEffectIceKirbyTex2 = Resources::Find<graphics::Texture>(L"LeftEffectIceKirby2");
		graphics::Texture* RightTackleIceKirbyTex = Resources::Find<graphics::Texture>(L"RightTackleIceKirby");
		graphics::Texture* LeftTackleIceKirbyTex = Resources::Find<graphics::Texture>(L"LeftTackleIceKirby");
		
		Animator* IceAnimator = mIceKirby->AddComponent<Animator>();

		IceAnimator->CreateAnimation(L"RightStandIceKirby", RightStandIceKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(26.0f, 30.0f), Vector2::Zero, 2, 0.5f);

		IceAnimator->CreateAnimation(L"LeftStandIceKirby", LeftStandIceKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(26.0f, 30.0f), Vector2::Zero, 3, 0.5f);

		IceAnimator->CreateAnimation(L"RightDownIceKirby", RightDownIceKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(31.0f, 24.0f), Vector2::Zero, 2, 0.5f);

		IceAnimator->CreateAnimation(L"LeftDownIceKirby", LefttDownIceKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(31.0f, 24.0f), Vector2::Zero, 2, 0.5f);

		IceAnimator->CreateAnimation(L"RightWalkIceKirby", RightWalkIceKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(26.0f, 32.0f), Vector2::Zero, 10, 0.2f);

		IceAnimator->CreateAnimation(L"LeftWalkIceKirby", LeftWalkIceKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(26.0f, 32.0f), Vector2::Zero, 10, 0.2f);

		IceAnimator->CreateAnimation(L"LeftEffectIceKirby", LeftEffectIceKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(30.0f, 33.0f), Vector2::Zero, 4, 0.1f);

		IceAnimator->CreateAnimation(L"RightEffectIceKirby", RightEffectIceKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(30.0f, 33.0f), Vector2::Zero, 4, 0.1f);

		IceAnimator->CreateAnimation(L"LeftEffectIceKirby2", LeftEffectIceKirbyTex2,
			Vector2(0.0f, 0.0f), Vector2(100.0f, 47.0f), Vector2::Zero, 4, 0.1f);

		IceAnimator->CreateAnimation(L"RightEffectIceKirby2", RightEffectIceKirbyTex2,
			Vector2(0.0f, 0.0f), Vector2(100.0f, 47.0f), Vector2::Zero, 4, 0.1f);

		IceAnimator->CreateAnimation(L"LeftTackleIceKirby", LeftTackleIceKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(37.0f, 28.0f), Vector2::Zero, 2, 0.2f);

		IceAnimator->CreateAnimation(L"RightTackleIceKirby", RightTackleIceKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(37.0f, 28.0f), Vector2::Zero, 2, 0.2f);


		
		
		//if (Input::GetKeyDown(eKeyCode::SPACE))
		//{

		//	IceAnimator->PlayAnimation(L"RightStandIceKirby", true);
		//	Transform* kirbyTr = mKirby->GetComponent<Transform>();
		//	mIceKirby->GetComponent<Transform>()->SetPosition(kirbyTr->GetPosition());
		//	mIceKirby->SetActive(true);
		//}


		// 이펙트




		// 몬스터 (Waddle Dee)
		Monster* wd = object::Instantiate<Monster>(enums::eLayerType::Monster);
		wd->AddComponent<WaddleDeeScript>();
		
		graphics::Texture* leftDeeTex = Resources::Find<graphics::Texture>(L"LeftDee");
		graphics::Texture* rightDeeTex = Resources::Find<graphics::Texture>(L"RightDee");

		Animator* deeAnimator = wd->AddComponent<Animator>();
		deeAnimator->CreateAnimation(L"LeftDee", leftDeeTex,
			Vector2::Zero, Vector2(24.0f, 23.5f), Vector2::Zero, 8, 0.3f);

		deeAnimator->CreateAnimation(L"RightDee", rightDeeTex,
			Vector2::Zero, Vector2(23.8f, 23.0f), Vector2::Zero, 8, 0.3f);

		deeAnimator->PlayAnimation(L"LeftDee", true);

		wd->GetComponent<Transform>()->SetScale(Vector2(2.5f, 2.5f));
		wd->GetComponent<Transform>()->SetPosition(Vector2(200.0f, 420.0f));

		// 몬스터 콜라이더

		BoxCollider2D* colliderWD = wd->AddComponent<BoxCollider2D>();
		colliderWD->SetOffset(Vector2(245.0f, -80.0f));


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

		//titleUnder = object::Instantiate<BackGround>(enums::eLayerType::BackGround, Vector2(0.0f, 405.0f));
		//SpriteRenderer* titleudsr = titleUnder->AddComponent<SpriteRenderer>();

		//graphics::Texture* TitleUnderTexture = Resources::Find<graphics::Texture>(L"Under");
		//titleudsr->SetSize(Vector2::Half);
		//titleudsr->SetTexture(TitleUnderTexture);

		
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