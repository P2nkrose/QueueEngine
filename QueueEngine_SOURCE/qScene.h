#pragma once
#include "qEntity.h"
#include "GameObject_player02.h"


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

		void AddGameObject(GameObject02* gameObject);
		

	private:

		std::vector<GameObject02*> mGameObjects;
	};
}


