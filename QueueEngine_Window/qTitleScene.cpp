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

namespace Q
{
	TitleScene::TitleScene()
		: title(nullptr)
		, titleBackGround(nullptr)
	{
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{
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