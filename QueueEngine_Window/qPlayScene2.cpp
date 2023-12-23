#pragma once
#include "qPlayScene2.h"
#include "qCollisionManager.h"
#include "qCamera.h"
#include "qObject.h"
#include "qRenderer.h"
#include "qSpriteRenderer.h"
#include "qBackGround2.h"
#include "qResources.h"
#include "qTransform.h"
#include "qStage2.h"

namespace Q
{
	PlayScene2::PlayScene2()
		//: mKirby(nullptr)
		//, mStage2(nullptr)
		//, mBackGround2(nullptr)
	{

	}
	PlayScene2::~PlayScene2()
	{

	}
	void PlayScene2::Initialize()
	{
		// 타입별 충돌할 타입 true로 해놓기
		CollisionManager::CollisionLayerCheck(eLayerType::Kirby, eLayerType::Monster, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Effect, eLayerType::Monster, true);

		// 카메라
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(0.0f, 420.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;


		// 배경
		mBackGround2 = object::Instantiate<BackGround2>(enums::eLayerType::BackGround);
		SpriteRenderer* bgsr2 = mBackGround2->AddComponent<SpriteRenderer>();

		graphics::Texture* bgTexture2 = Resources::Find<graphics::Texture>(L"BackGround2");
		bgsr2->SetTexture(bgTexture2);
		bgsr2->SetSize(Vector2::Two);
		mBackGround2->GetComponent<Transform>()->SetPosition(Vector2(-318.0f, 70.0f));

		// 맵
		mStage2 = object::Instantiate<Stage2>(enums::eLayerType::Stage);
		SpriteRenderer* stageSr2 = mStage2->AddComponent<SpriteRenderer>();
		stageSr2->SetSize(Vector2::Two);

		graphics::Texture* stageTexture = Resources::Find<graphics::Texture>(L"Stage2");
		stageSr2->SetTexture(stageTexture);

		mStage2->GetComponent<Transform>()->SetPosition(Vector2(-318.0f, 70.0f));



		Scene::Initialize();
	}
	void PlayScene2::Update()
	{
		Scene::Update();
	}
	void PlayScene2::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void PlayScene2::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void PlayScene2::OnEnter()
	{

	}
	void PlayScene2::OnExit()
	{

	}
}