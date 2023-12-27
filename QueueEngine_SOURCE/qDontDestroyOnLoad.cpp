#include "qDontDestroyOnLoad.h"
#include "qSceneManager.h"
#include "qCamera.h"
#include "qRenderer.h"
#include "qGameObject.h"
#include "qObject.h"

namespace Q
{
	DontDestroyOnLoad::DontDestroyOnLoad()
	{
	}

	DontDestroyOnLoad::~DontDestroyOnLoad()
	{
	}

	void DontDestroyOnLoad::Initialize()
	{
		Scene::Initialize();

		//GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(0.0f, 420.0f));
		//Camera* cameraComp = camera->AddComponent<Camera>();
		//renderer::mainCamera = cameraComp;

		//cameraComp->SetTarget(SceneManager::allKirby);
	}

	void DontDestroyOnLoad::Update()
	{
		Scene::Update();


	}

	void DontDestroyOnLoad::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void DontDestroyOnLoad::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}

	void DontDestroyOnLoad::OnEnter()
	{
		Scene::OnEnter();
	}

	void DontDestroyOnLoad::OnExit()
	{
		Scene::OnExit();
	}
}