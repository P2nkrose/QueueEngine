#include "qCollisionManager.h"
#include "qScene.h"
#include "qSceneManager.h"
#include "qGameObject.h"
#include "qCollider.h"
#include "qTransform.h"
#include "qGameObject.h"

namespace Q
{
	std::bitset <(UINT)eLayerType::Max> CollisionManager::mCollisionLayerMatrix[(UINT)eLayerType::Max] = {};
	std::unordered_map<UINT64, bool> CollisionManager::mCollisionMap = {};

	void CollisionManager::Initialize()
	{

	}

	void CollisionManager::Update()
	{
		Scene* scene = SceneManager::GetActiveScene();
		for (UINT row = 0; row < (UINT)eLayerType::Max; row++)
		{
			for (UINT col = 0; col < (UINT)eLayerType::Max; col++)
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

	void CollisionManager::Clear()
	{
		mCollisionMap.clear(); // 충돌중인 정보 클리어
		mCollisionLayerMatrix->reset();
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
		const std::vector<GameObject*>& lefts = SceneManager::GetGameObjects(left);//scene->GetLayer(left)->GetGameObjects();
		const std::vector<GameObject*>& rights = SceneManager::GetGameObjects(right);//scene->GetLayer(right)->GetGameObjects();

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
		// 두 충돌체 번호를 가져온 ID를 확인해서 CollisionID값을 세팅
		CollisionID id = {};
		id.left = left->GetID();
		id.right = right->GetID();

		// 해당 id로 충돌체 정보를 검색해준다.
		// 만약에 충돌체 정보가 없다면 충돌정보를 생성해준다.

		auto iter = mCollisionMap.find(id.id);
		if (iter == mCollisionMap.end())
		{
			mCollisionMap.insert(std::make_pair(id.id, false));
			iter = mCollisionMap.find(id.id);
		}

		// 충돌체크를 해주면 된다.
		if (Intersect(left, right))
		{
			//최초 충돌할떄
			if (iter->second == false)
			{
				left->OnCollisionEnter(right);
				right->OnCollisionEnter(left);
				iter->second = true;
			}
			else // 이미 충돌 중
			{
				left->OnCollisionStay(right);
				right->OnCollisionStay(left);
			}
		}
		else
		{
			//충돌중이었으나 지금은 충돌이 아닌 상태(빠져나온상태)
			if (iter->second == true)
			{
				left->OnCollisionExit(right);
				right->OnCollisionExit(left);

				iter->second = false;
			}
		}

	}
	bool CollisionManager::Intersect(Collider* left, Collider* right)
	{
		Transform* leftTr = left->GetOwner()->GetComponent<Transform>();
		Transform* rightTr = right->GetOwner()->GetComponent<Transform>();

		Vector2 leftPos = leftTr->GetPosition() + left->GetOffset();
		Vector2 rightPos = rightTr->GetPosition() + right->GetOffset();

		// size 1,1 일떄 기본크기가 100픽셀
		Vector2 leftSize = left->GetSize();
		Vector2 rightSize = right->GetSize();

		//AABB 충돌
		if (fabs(leftPos.x - rightPos.x) < fabs(leftSize.x / 2.0f + rightSize.x / 2.0f)
			&& fabs(leftPos.y - rightPos.y) < fabs(leftSize.y / 2.0f + rightSize.y / 2.0f))
		{
			return true;
		}



		// circle - circle

		return false;
	}
}