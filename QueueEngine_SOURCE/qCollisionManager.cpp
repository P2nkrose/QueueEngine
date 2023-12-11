#include "qCollisionManager.h"
#include "qScene.h"
#include "qSceneManager.h"
#include "qGameObject.h"
#include "qCollider.h"

namespace Q
{
	std::bitset <(UINT)eLayerType::Max> CollisionManager::mCollisionLayerMatrix[(UINT)eLayerType::Max] = {};

	void CollisionManager::Initialize()
	{
	}

	void CollisionManager::Update()
	{
		Scene* scene = SceneManager::GetActiveScene();
		for (UINT row = 0; (UINT)eLayerType::Max; row++)
		{
			for (UINT col = 0; (UINT)eLayerType::Max; col++)
			{
				if (mCollisionLayerMatrix[row][col] == true)
				{
					LayerCollision(scene, (eLayerType)row, (eLayerType)col);
				}
			}
		}
	}

	void CollisionManager::LateUpdate()
	{
	}

	void CollisionManager::Render(HDC hdc)
	{
	}

	void CollisionManager::CollisionLayerCheck(eLayerType left, eLayerType right, bool enable)
	{
		int row = 0;
		int col = 0;

		if (left <= right)
		{
			row = (UINT)left;
			col = (UINT)right;
		}
		else
		{
			row = (UINT)right;
			col = (UINT)left;
		}

		mCollisionLayerMatrix[row][col] = enable;
	}

	void CollisionManager::LayerCollision(Scene* scene, eLayerType left, eLayerType right)
	{
		const std::vector<GameObject*>& lefts = scene->GetLayer(left)->GetGameObjects();
		const std::vector<GameObject*>& rights = scene->GetLayer(right)->GetGameObjects();

		for (GameObject* left: lefts)
		{
			if (left->IsActive() == false)
			{
				continue;
			}

			Collider* leftCol = left->GetComponent<Collider>();
			if (leftCol == nullptr)
			{
				continue;
			}

			for (GameObject* right : rights)
			{
				if (right->IsActive() == false)
				{
					continue;
				}

				Collider* rightCol = right->GetComponent<Collider>();
				if (rightCol == nullptr)
				{
					continue;
				}
				if (left == right)
				{
					continue;
				}

				ColliderCollision(leftCol, rightCol);
			}
		}
	}
	void CollisionManager::ColliderCollision(Collider* left, Collider* right)
	{
		// 충돌 체크로직을 작성해주면 된다.
	}
}