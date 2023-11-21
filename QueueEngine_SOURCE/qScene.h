#pragma once
#include "qEntity.h"
#include "qGameObject.h"
#include "qLayer.h"


namespace Q
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObj, eLayerType type);

	private:

		std::vector<Layer*> mLayers;
		
	};
}


