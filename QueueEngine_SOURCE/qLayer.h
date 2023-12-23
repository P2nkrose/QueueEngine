#pragma once
#include "qEntity.h"
#include "CommonInclude.h"
#include "qGameObject.h"


namespace Q
{
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();
		

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		virtual void Destroy();

		void AddGameObject(GameObject* gameObject);
		void EraseGameObejct(GameObject* eraseGameObj);
		const std::vector<GameObject*> GetGameObjects() { return mGameObjects; }


	private:
		void eraseDeadGameObject();


	private:
		std::vector<GameObject*> mGameObjects;
	};

	typedef std::vector<GameObject*>::iterator GameObjectIter;
}



