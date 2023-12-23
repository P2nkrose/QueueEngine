#include "qPlayScene.h"
#include "qGameObject.h"
#include "qKirby.h"
#include "qIceKirby.h"
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
#include "qCircleCollider2D.h"
#include "qCollisionManager.h"
#include "qKirbyTypeManager.h"
#include "qSparkKirby.h"
#include "qSparkKirbyScript.h"
#include "qMetalKirbyScript.h"
#include "qMetalKirby.h"
#include "qNinjaKirby.h"
#include "qNinjaKirbyScript.h"

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
		

		// 카메라
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(0.0f, 420.0f));
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
		
		mKirby = object::Instantiate<Kirby>(enums::eLayerType::Kirby);

		object::DontDestroyOnLoad(mKirby);
		PlayerScript* kirbyScript = mKirby->AddComponent<PlayerScript>();

		// 카메라 커비타겟
		cameraComp->SetTarget(mKirby);

		mKirby->GetComponent<Transform>()->SetPosition(Vector2(0.0f, 420.0f));
		

		//Transform* stageTr = mStage->GetComponent<Transform>();

		//mPlayer->GetComponent<Transform>()->SetPosition(stageTr->GetPosition() + Vector2(50.0f, 360.0f));
		



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
		graphics::Texture* RightTackleKirbyTex2 = Resources::Find<graphics::Texture>(L"RightTackleKirby2");
		graphics::Texture* LeftTackleKirbyTex = Resources::Find<graphics::Texture>(L"LeftTackleKirby");
		graphics::Texture* LeftTackleKirbyTex2 = Resources::Find<graphics::Texture>(L"LeftTackleKirby2");



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
			Vector2(0.0f, 0.0f), Vector2(30.0f, 30.0f), Vector2::Zero, 10, 0.1f);

		animator->CreateAnimation(L"LeftWalkKirby", LeftWalkKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(30.0f, 30.0f), Vector2::Zero, 10, 0.1f);

		animator->CreateAnimation(L"LeftWindKirby", LeftWindKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(33.6f, 30.0f), Vector2::Zero, 5, 0.1f);

		animator->CreateAnimation(L"RightWindKirby", RightWindKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(33.6f, 30.0f), Vector2::Zero, 5, 0.1f);

		animator->CreateAnimation(L"LeftWindKirby2", LeftWindKirbyTex2,
			Vector2(0.0f, 0.0f), Vector2(34.5f, 31.0f), Vector2::Zero, 2, 0.1f);

		animator->CreateAnimation(L"RightWindKirby2", RightWindKirbyTex2,
			Vector2(0.0f, 0.0f), Vector2(34.5f, 31.0f), Vector2::Zero, 2, 0.1f);

		animator->CreateAnimation(L"RightTackleKirby", RightTackleKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(40.0f, 30.0f), Vector2::Zero, 6, 0.07f);
		
		animator->CreateAnimation(L"LeftTackleKirby", LeftTackleKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(40.0f, 30.0f), Vector2::Zero, 6, 0.07f);

		animator->CreateAnimation(L"RightTackleKirby2", RightTackleKirbyTex2,
			Vector2(0.0f, 0.0f), Vector2(40.0f, 30.0f), Vector2::Zero, 2, 0.1f);

		animator->CreateAnimation(L"LeftTackleKirby2", LeftTackleKirbyTex2,
			Vector2(0.0f, 0.0f), Vector2(40.0f, 30.0f), Vector2::Zero, 2, 0.1f);

		// 이어지기

		animator->GetCompleteEvent(L"RightWindKirby") = std::bind(&PlayerScript::Wind2, kirbyScript);
		animator->GetCompleteEvent(L"LeftWindKirby") = std::bind(&PlayerScript::Wind2, kirbyScript);

		animator->GetCompleteEvent(L"LeftTackleKirby") = std::bind(&PlayerScript::Tackle2, kirbyScript);
		animator->GetCompleteEvent(L"RightTackleKirby") = std::bind(&PlayerScript::Tackle2, kirbyScript);


		animator->PlayAnimation(L"RightStandKirby", true);
		mKirby->SetActive(true);

		mKirby->GetComponent<Transform>()->SetScale(Vector2::Two);
		

		
		// 아이스커비
		mIceKirby = object::Instantiate<IceKirby>(enums::eLayerType::Kirby);
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
		graphics::Texture* RightIceEffectTex = Resources::Find<graphics::Texture>(L"RightIceEffect");
		graphics::Texture* LeftIceEffectTex = Resources::Find<graphics::Texture>(L"LeftIceEffect");
		
		Animator* IceAnimator = mIceKirby->AddComponent<Animator>();

		IceAnimator->CreateAnimation(L"RightStandIceKirby", RightStandIceKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(26.0f, 30.0f), Vector2::Zero, 2, 0.5f);

		IceAnimator->CreateAnimation(L"LeftStandIceKirby", LeftStandIceKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(26.0f, 30.0f), Vector2::Zero, 2, 0.5f);

		IceAnimator->CreateAnimation(L"RightDownIceKirby", RightDownIceKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(31.0f, 30.0f), Vector2::Zero, 2, 0.5f);

		IceAnimator->CreateAnimation(L"LeftDownIceKirby", LefttDownIceKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(31.0f, 30.0f), Vector2::Zero, 2, 0.5f);

		IceAnimator->CreateAnimation(L"RightWalkIceKirby", RightWalkIceKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(26.0f, 30.0f), Vector2::Zero, 10, 0.1f);

		IceAnimator->CreateAnimation(L"LeftWalkIceKirby", LeftWalkIceKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(26.0f, 30.0f), Vector2::Zero, 10, 0.1f);

		IceAnimator->CreateAnimation(L"LeftEffectIceKirby", LeftEffectIceKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(30.0f, 30.0f), Vector2::Zero, 4, 0.1f);

		IceAnimator->CreateAnimation(L"RightEffectIceKirby", RightEffectIceKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(30.0f, 30.0f), Vector2::Zero, 4, 0.1f);

		IceAnimator->CreateAnimation(L"LeftEffectIceKirby2", LeftEffectIceKirbyTex2,
			Vector2(0.0f, 0.0f), Vector2(30.0f, 30.0f), Vector2::Zero, 2, 0.1f);

		IceAnimator->CreateAnimation(L"RightEffectIceKirby2", RightEffectIceKirbyTex2,
			Vector2(0.0f, 0.0f), Vector2(30.0f, 30.0f), Vector2::Zero, 2, 0.1f);

		IceAnimator->CreateAnimation(L"LeftTackleIceKirby", LeftTackleIceKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(37.0f, 28.0f), Vector2::Zero, 2, 0.2f);

		IceAnimator->CreateAnimation(L"RightTackleIceKirby", RightTackleIceKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(37.0f, 28.0f), Vector2::Zero, 2, 0.2f);

		IceAnimator->CreateAnimation(L"LeftIceEffect", LeftIceEffectTex,
			Vector2(0.0f, 0.0f), Vector2(40.0f, 30.0f), Vector2::Zero, 6, 0.04f);

		IceAnimator->CreateAnimation(L"RightIceEffect", RightIceEffectTex,
			Vector2(0.0f, 0.0f), Vector2(40.0f, 30.0f), Vector2::Zero, 6, 0.04f);


		

		IceAnimator->PlayAnimation(L"RightStandIceKirby", true);
		Transform* IcekirbyTr = mIceKirby->GetComponent<Transform>();

		IcekirbyTr->SetPosition(Vector2(0.0f, 410.0f));
		IcekirbyTr->SetScale(Vector2(2.5f, 2.5f));

		// 이펙트 이어지기
		IceAnimator->GetCompleteEvent(L"RightEffectIceKirby") = std::bind(&IceKirbyScript::Effect2, icekirbyScript);
		IceAnimator->GetCompleteEvent(L"LeftEffectIceKirby") = std::bind(&IceKirbyScript::Effect2, icekirbyScript);

		IceAnimator->GetCompleteEvent(L"LeftTackleIceKirby") = std::bind(&IceKirbyScript::Tackle2, icekirbyScript);
		IceAnimator->GetCompleteEvent(L"RightTackleIceKirby") = std::bind(&IceKirbyScript::Tackle2, icekirbyScript);

		// 처음에 안보이기
		mIceKirby->SetActive(false);

		




		// 스파크(전기) 커비
		mSparkKirby = object::Instantiate<SparkKirby>(enums::eLayerType::Kirby);
		SparkKirbyScript* sparkKirbyScript = mSparkKirby->AddComponent<SparkKirbyScript>();

		graphics::Texture* RightStandSparkKirbyTex = Resources::Find<graphics::Texture>(L"RightStandSparkKirby");
		graphics::Texture* LeftStandSparkKirbyTex = Resources::Find<graphics::Texture>(L"LeftStandSparkKirby");
		graphics::Texture* RightDownSparkKirbyTex = Resources::Find<graphics::Texture>(L"RightDownSparkKirby");
		graphics::Texture* LefttDownSparkKirbyTex = Resources::Find<graphics::Texture>(L"LeftDownSparkKirby");
		graphics::Texture* RightWalkSparkKirbyTex = Resources::Find<graphics::Texture>(L"RightWalkSparkKirby");
		graphics::Texture* LeftWalkSparkKirbyTex = Resources::Find<graphics::Texture>(L"LeftWalkSparkKirby");
		graphics::Texture* LeftEffectSparkKirbyTex = Resources::Find<graphics::Texture>(L"LeftEffectSparkKirby");
		graphics::Texture* RightEffectSparkKirbyTex = Resources::Find<graphics::Texture>(L"RightEffectSparkKirby");
		graphics::Texture* RightTackleSparkKirbyTex = Resources::Find<graphics::Texture>(L"RightTackleSparkKirby");
		graphics::Texture* LeftTackleSparkKirbyTex = Resources::Find<graphics::Texture>(L"LeftTackleSparkKirby");


		Animator* SparkAnimator = mSparkKirby->AddComponent<Animator>();

		SparkAnimator->CreateAnimation(L"RightStandSparkKirby", RightStandSparkKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(70.0f, 43.0f), Vector2(-100.0f, 0), 8, 0.2f);

		SparkAnimator->CreateAnimation(L"LeftStandSparkKirby", LeftStandSparkKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(70.0f, 43.0f), Vector2::Zero, 8, 0.2f);

		SparkAnimator->CreateAnimation(L"RightDownSparkKirby", RightDownSparkKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(70.0f, 43.0f), Vector2::Zero, 8, 0.2f);

		SparkAnimator->CreateAnimation(L"LeftDownSparkKirby", LefttDownSparkKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(70.0f, 43.0f), Vector2::Zero, 8, 0.2f);

		SparkAnimator->CreateAnimation(L"RightWalkSparkKirby", RightWalkSparkKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(70.0f, 43.0f), Vector2::Zero, 19, 0.05f);

		SparkAnimator->CreateAnimation(L"LeftWalkSparkKirby", LeftWalkSparkKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(70.0f, 43.0f), Vector2::Zero, 18, 0.05f);

		SparkAnimator->CreateAnimation(L"LeftEffectSparkKirby", LeftEffectSparkKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(70.0f, 43.0f), Vector2::Zero, 7, 0.1f);

		SparkAnimator->CreateAnimation(L"RightEffectSparkKirby", RightEffectSparkKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(70.0f, 43.0f), Vector2::Zero, 7, 0.1f);

		SparkAnimator->CreateAnimation(L"LeftTackleSparkKirby", LeftTackleSparkKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(70.0f, 43.0f), Vector2::Zero, 5, 0.1f);

		SparkAnimator->CreateAnimation(L"RightTackleSparkKirby", RightTackleSparkKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(70.0f, 43.0f), Vector2::Zero, 5, 0.1f);


		SparkAnimator->PlayAnimation(L"RightStandSparkKirby", true);
		Transform* SparkkirbyTr = mSparkKirby->GetComponent<Transform>();

		SparkkirbyTr->SetPosition(Vector2(0.0f, 384.0f));
		SparkkirbyTr->SetScale(Vector2(2.5f, 2.5f));

		mSparkKirby->SetActive(false);



		// 메탈 커비
		mMetalKirby = object::Instantiate<MetalKirby>(enums::eLayerType::Kirby);
		MetalKirbyScript* metalkirbyScript = mMetalKirby->AddComponent<MetalKirbyScript>();

		graphics::Texture* RightStandMetalKirbyTex = Resources::Find<graphics::Texture>(L"RightStandMetalKirby");
		graphics::Texture* LeftStandMetalKirbyTex = Resources::Find<graphics::Texture>(L"LeftStandMetalKirby");
		graphics::Texture* RightDownMetalKirbyTex = Resources::Find<graphics::Texture>(L"RightDownMetalKirby");
		graphics::Texture* LefttDownMetalKirbyTex = Resources::Find<graphics::Texture>(L"LeftDownMetalKirby");
		graphics::Texture* RightWalkMetalKirbyTex = Resources::Find<graphics::Texture>(L"RightWalkMetalKirby");
		graphics::Texture* LeftWalkMetalKirbyTex = Resources::Find<graphics::Texture>(L"LeftWalkMetalKirby");
		graphics::Texture* LeftEffectModeWalkMetalKirbyTex = Resources::Find<graphics::Texture>(L"LeftEffectModeWalkMetalKirby");
		graphics::Texture* RightEffectModeWalkMetalKirbyTex = Resources::Find<graphics::Texture>(L"RightEffectModeWalkMetalKirby");
		graphics::Texture* LeftEffectModeStandMetalKirbyTex = Resources::Find<graphics::Texture>(L"LeftEffectModeStandMetalKirby");
		graphics::Texture* RightEffectModeStandMetalKirbyTex = Resources::Find<graphics::Texture>(L"RightEffectModeStandMetalKirby");
		graphics::Texture* RightTackleMetalKirbyTex = Resources::Find<graphics::Texture>(L"RightTackleMetalKirby");
		graphics::Texture* LeftTackleMetalKirbyTex = Resources::Find<graphics::Texture>(L"LeftTackleMetalKirby");



		Animator* MetalAnimator = mMetalKirby->AddComponent<Animator>();

		MetalAnimator->CreateAnimation(L"RightStandMetalKirby", RightStandMetalKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(32.0f, 30.0f), Vector2::Zero, 2, 0.5f);

		MetalAnimator->CreateAnimation(L"LeftStandMetalKirby", LeftStandMetalKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(32.0f, 30.0f), Vector2::Zero, 2, 0.5f);

		MetalAnimator->CreateAnimation(L"RightDownMetalKirby", RightDownMetalKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(32.0f, 30.0f), Vector2::Zero, 2, 0.5f);

		MetalAnimator->CreateAnimation(L"LeftDownMetalKirby", LefttDownMetalKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(32.0f, 30.0f), Vector2::Zero, 2, 0.5f);

		MetalAnimator->CreateAnimation(L"RightWalkMetalKirby", RightWalkMetalKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(32.0f, 30.0f), Vector2::Zero, 10, 0.2f);

		MetalAnimator->CreateAnimation(L"LeftWalkMetalKirby", LeftWalkMetalKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(32.0f, 30.0f), Vector2::Zero, 10, 0.2f);

		MetalAnimator->CreateAnimation(L"LeftEffectModeWalkMetalKirby", LeftEffectModeWalkMetalKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(32.0f, 30.0f), Vector2::Zero, 7, 0.1f);

		MetalAnimator->CreateAnimation(L"RightEffectModeWalkMetalKirby", RightEffectModeWalkMetalKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(32.0f, 30.0f), Vector2::Zero, 7, 0.1f);

		MetalAnimator->CreateAnimation(L"LeftEffectModeStandMetalKirby", LeftEffectModeStandMetalKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(32.0f, 30.0f), Vector2::Zero, 1, 0.1f);

		MetalAnimator->CreateAnimation(L"RightEffectModeStandMetalKirby", RightEffectModeStandMetalKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(32.0f, 30.0f), Vector2::Zero, 1, 0.1f);

		MetalAnimator->CreateAnimation(L"LeftTackleMetalKirby", LeftTackleMetalKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(32.0f, 30.0f), Vector2::Zero, 2, 0.2f);

		MetalAnimator->CreateAnimation(L"RightTackleMetalKirby", RightTackleMetalKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(32.0f, 30.0f), Vector2::Zero, 2, 0.2f);


		MetalAnimator->PlayAnimation(L"RightStandMetalKirby", true);
		Transform* MetalkirbyTr = mMetalKirby->GetComponent<Transform>();

		MetalkirbyTr->SetPosition(Vector2(50.0f, 414.0f));
		MetalkirbyTr->SetScale(Vector2(2.3f, 2.3f));

		mMetalKirby->SetActive(false);

		MetalAnimator->GetCompleteEvent(L"RightEffectModeStandMetalKirby") = std::bind(&MetalKirbyScript::Effect, metalkirbyScript);
		MetalAnimator->GetCompleteEvent(L"LeftEffectModeStandMetalKirby") = std::bind(&MetalKirbyScript::Effect, metalkirbyScript);


		// 닌자 커비
		mNinjaKirby = object::Instantiate<NinjaKirby>(enums::eLayerType::Kirby);
		NinjaKirbyScript* ninjakirbyScript = mNinjaKirby->AddComponent<NinjaKirbyScript>();

		graphics::Texture* RightStandNinjaKirbyTex = Resources::Find<graphics::Texture>(L"RightStandNinjaKirby");
		graphics::Texture* LeftStandNinjaKirbyTex = Resources::Find<graphics::Texture>(L"LeftStandNinjaKirby");
		graphics::Texture* RightDownNinjaKirbyTex = Resources::Find<graphics::Texture>(L"RightDownNinjaKirby");
		graphics::Texture* LefttDownNinjaKirbyTex = Resources::Find<graphics::Texture>(L"LeftDownNinjaKirby");
		graphics::Texture* RightWalkNinjaKirbyTex = Resources::Find<graphics::Texture>(L"RightWalkNinjaKirby");
		graphics::Texture* LeftWalkNinjaKirbyTex = Resources::Find<graphics::Texture>(L"LeftWalkNinjaKirby");
		graphics::Texture* RightTackleNinjaKirbyTex = Resources::Find<graphics::Texture>(L"RightTackleNinjaKirby");
		graphics::Texture* LeftTackleNinjaKirbyTex = Resources::Find<graphics::Texture>(L"LeftTackleNinjaKirby");
		graphics::Texture* RightStingNinjaKirbyTex = Resources::Find<graphics::Texture>(L"RightStingNinjaKirby");
		graphics::Texture* LeftStingNinjaKirbyTex = Resources::Find<graphics::Texture>(L"LeftStingNinjaKirby");
		graphics::Texture* RightDaggerNinjaKirbyTex = Resources::Find<graphics::Texture>(L"RightDaggerNinjaKirby");
		graphics::Texture* LeftDaggerNinjaKirbyTex = Resources::Find<graphics::Texture>(L"LeftDaggerNinjaKirby");
		



		Animator* NinjaAnimator = mNinjaKirby->AddComponent<Animator>();


		NinjaAnimator->CreateAnimation(L"RightStandNinjaKirby", RightStandNinjaKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(50.0f, 32.0f), Vector2::Zero, 2, 0.5f);

		NinjaAnimator->CreateAnimation(L"LeftStandNinjaKirby", LeftStandNinjaKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(50.0f, 32.0f), Vector2::Zero, 2, 0.5f);

		NinjaAnimator->CreateAnimation(L"RightDownNinjaKirby", RightDownNinjaKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(50.0f, 32.0f), Vector2::Zero, 2, 0.5f);

		NinjaAnimator->CreateAnimation(L"LeftDownNinjaKirby", LefttDownNinjaKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(50.0f, 32.0f), Vector2::Zero, 2, 0.5f);

		NinjaAnimator->CreateAnimation(L"RightWalkNinjaKirby", RightWalkNinjaKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(50.0f, 32.0f), Vector2::Zero, 11, 0.12f);

		NinjaAnimator->CreateAnimation(L"LeftWalkNinjaKirby", LeftWalkNinjaKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(50.0f, 32.0f), Vector2::Zero, 11, 0.12f);

		NinjaAnimator->CreateAnimation(L"LeftTackleNinjaKirby", LeftTackleNinjaKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(50.0f, 32.0f), Vector2::Zero, 3, 0.1f);

		NinjaAnimator->CreateAnimation(L"RightTackleNinjaKirby", RightTackleNinjaKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(50.0f, 32.0f), Vector2::Zero, 3, 0.1f);

		NinjaAnimator->CreateAnimation(L"LeftStingNinjaKirby", LeftStingNinjaKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(50.0f, 32.0f), Vector2::Zero, 10, 0.04f);

		NinjaAnimator->CreateAnimation(L"RightStingNinjaKirby", RightStingNinjaKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(50.0f, 32.0f), Vector2::Zero, 10, 0.04f);

		NinjaAnimator->CreateAnimation(L"LeftDaggerNinjaKirby", LeftDaggerNinjaKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(50.0f, 32.0f), Vector2::Zero, 7, 0.1f);

		NinjaAnimator->CreateAnimation(L"RightDaggerNinjaKirby", RightDaggerNinjaKirbyTex,
			Vector2(0.0f, 0.0f), Vector2(50.0f, 32.0f), Vector2::Zero, 7, 0.1f);

		


		NinjaAnimator->PlayAnimation(L"RightStandNinjaKirby", true);
		Transform* NinjakirbyTr = mNinjaKirby->GetComponent<Transform>();

		NinjakirbyTr->SetPosition(Vector2(50.0f, 413.0f));
		NinjakirbyTr->SetScale(Vector2(2.3f, 2.3f));

		mNinjaKirby->SetActive(false);

		NinjaAnimator->GetCompleteEvent(L"RightDaggerNinjaKirby") = std::bind(&NinjaKirbyScript::Stand, ninjakirbyScript);
		NinjaAnimator->GetCompleteEvent(L"LeftDaggerNinjaKirby") = std::bind(&NinjaKirbyScript::Stand, ninjakirbyScript);


		// 몬스터 (Waddle Dee)
		Monster* mWaddleDee = object::Instantiate<Monster>(enums::eLayerType::Monster);
		mWaddleDee->AddComponent<WaddleDeeScript>();
		
		graphics::Texture* leftDeeTex = Resources::Find<graphics::Texture>(L"LeftDee");
		graphics::Texture* rightDeeTex = Resources::Find<graphics::Texture>(L"RightDee");

		Animator* deeAnimator = mWaddleDee->AddComponent<Animator>();
		deeAnimator->CreateAnimation(L"LeftDee", leftDeeTex,
			Vector2::Zero, Vector2(24.0f, 23.5f), Vector2::Zero, 8, 0.3f);

		deeAnimator->CreateAnimation(L"RightDee", rightDeeTex,
			Vector2::Zero, Vector2(23.8f, 23.0f), Vector2::Zero, 8, 0.3f);

		deeAnimator->PlayAnimation(L"LeftDee", true);

		mWaddleDee->GetComponent<Transform>()->SetScale(Vector2(2.5f, 2.5f));
		mWaddleDee->GetComponent<Transform>()->SetPosition(Vector2(200.0f, 420.0f));



		// 콜라이더


		// 커비 콜라이더
		BoxCollider2D* collider = mKirby->AddComponent<BoxCollider2D>();
		collider->SetOffset(Vector2(-10.0f, -10.0f));
		collider->SetSize(Vector2(50.0f, 50.0f));

		// 이펙트 콜라이더



		// 몬스터 콜라이더

		BoxCollider2D* colliderWD = mWaddleDee->AddComponent<BoxCollider2D>();
		colliderWD->SetOffset(Vector2(-10.0f, -10.0f));
		colliderWD->SetSize(Vector2(40.0f, 40.0f));






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


		// 커비타입 바꾸기
		KirbyTypeManager::Insert(L"Normal", mKirby);
		KirbyTypeManager::Insert(L"Ice", mIceKirby);
		KirbyTypeManager::Insert(L"Spark", mSparkKirby);
		KirbyTypeManager::Insert(L"Metal", mMetalKirby);
		KirbyTypeManager::Insert(L"Ninja", mNinjaKirby);


		
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
		Scene::OnEnter();

		// 타입별 충돌할 2개의 타입 true로 해놓기
		CollisionManager::CollisionLayerCheck(eLayerType::Kirby, eLayerType::Monster, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Effect, eLayerType::Monster, true);
	}

	void PlayScene::OnExit()
	{
		//Transform* tr = bg->GetComponent<Transform>();
		//tr->SetPosition(Vector2(0, 0));
	}
}