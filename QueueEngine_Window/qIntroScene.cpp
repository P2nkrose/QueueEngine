#include "qIntroScene.h"
#include "qGameObject.h"
#include "qKirby.h"
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
#include "qTime.h"

#include <Vfw.h>
#include "..\QueueEngine_SOURCE\qApplication.h"
#pragma comment (lib, "Vfw32.lib")

extern Q::Application application;

namespace Q
{
	//HWND m_hVideo;
	//float mTime = 0.0f;
	void IntroScene::Initialize()
	{
	//	m_hVideo = MCIWndCreate(application.GetHwnd(), NULL, WS_CHILD | WS_VISIBLE | MCIWNDF_NOPLAYBAR, L"..\\Resources\\video\\KirbyWmv.wmv");
		
	//	MCIWndPlay(m_hVideo);
	}
	void IntroScene::Update() {
	//	mTime += Time::DeltaTime();
	//	if (mTime > 10.0f) {
	//		SceneManager::LoadScene(L"PlayScene");
	//	}
	}
	void IntroScene::LateUpdate()
	{
		
	}
	void IntroScene::Render(HDC hdc)
	{
		
	}
	void IntroScene::OnEnter() {
	}
	void IntroScene::OnExit()
	{
	}
}