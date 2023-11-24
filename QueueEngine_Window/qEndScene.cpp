//#include "qEndScene.h"
//#include "qGameObject.h"
//#include "qPlayer.h"
//#include "qTransform.h"
//#include "qSpriteRenderer.h"
//#include "qInput.h"
//#include "qTitleScene.h"
//#include "qSceneManager.h"
//#include "qObject.h"
//#include "qTexture.h"
//
//namespace Q
//{
//	EndScene::EndScene()
//	{
//	}
//
//	EndScene::~EndScene()
//	{
//	}
//
//	void EndScene::Initialize()
//	{
//		{
//			end = object::Instantiate<Player>(enums::eLayerType::BackGround, Vector2(0, 0));
//			SpriteRenderer* sr = end->AddComponent<SpriteRenderer>();
//
//			graphics::Texture* tex = new graphics::Texture();
//			tex->Load(L"Q:\\assortrock\\Win32API\\QueueEngine\\Resources\\EndScene.png");
//		}
//	}
//	void EndScene::Update()
//	{
//		Scene::Update();
//	}
//	void EndScene::LateUpdate()
//	{
//		Scene::LateUpdate();
//
//		if (Input::GetKeyDown(eKeyCode::N))
//		{
//			SceneManager::LoadScene(L"TitleScene");
//		}
//	}
//	void EndScene::Render(HDC hdc)
//	{
//		Scene::Render(hdc);
//	}
//}