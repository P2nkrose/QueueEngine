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


	private:
		//eLayerType mType;
		std::vector<GameObject*> mGameObjects;
	};

	typedef std::vector<GameObject*>::iterator GameObjectIter;
}



