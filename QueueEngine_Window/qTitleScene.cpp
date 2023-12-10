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
#include "qResources.h"
#include "qPlayerScript.h"
#include "qCamera.h"
#include "qRenderer.h"
#include "qBackGround.h"
#include "qMath.h"
#include "qAnimator.h"

namespace Q
{
	TitleScene::TitleScene()
		: title(nullptr)
		, titleUnder(nullptr)
	{
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(270.0f, 405.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;


		// 360 270
		title = object::Instantiate<BackGround>(enums::eLayerType::BackGround);
		SpriteRenderer* titlesr = title->AddComponent<SpriteRenderer>();

		graphics::Texture* TitleTexture = Resources::Find<graphics::Texture>(L"Title");
		titlesr->SetTexture(TitleTexture);

		titlesr->SetSize(Vector2::Half);

		

		//

		//titleUnder = object::Instantiate<BackGround>(enums::eLayerType::BackGround, Vector2(0.0f, 405.0f));
		//SpriteRenderer* titleudsr = titleUnder->AddComponent<SpriteRenderer>();

		//graphics::Texture* TitleUnderTexture = Resources::Find<graphics::Texture>(L"Under");
		//titleudsr->SetTexture(TitleUnderTexture);

		//titleudsr->SetSize(Vector2::Half);


		Scene::Initialize();
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
		/*wchar_t str[50] = L"Title Scene";
		TextOut(hdc, 0, 0, str, 11);*/
	}
}