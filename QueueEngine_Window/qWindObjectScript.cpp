#include "qWindObjectScript.h"
#include "qInput.h"
#include "qTransform.h"
#include "qTime.h"
#include "qGameObject.h"
#include "qAnimator.h"
#include "qWindObject.h"
#include "qObject.h"
#include "qResources.h"
#include "qKirby.h"
#include "qPlayerScript.h"
#include "qCollider.h"
#include "qComponent.h"
#include "qWaddleDeeScript.h"
#include "qPlayScene.h"
#include "qBoxCollider2D.h"
#include "qPlayerScript.h"

namespace Q
{
	WindObjectScript::WindObjectScript()
		: mState(WindObjectScript::eState::False)
		, mDirection(WindObjectScript::eDirection::Right)
	{
	}

	WindObjectScript::~WindObjectScript()
	{
	}

	void WindObjectScript::Initialize()
	{
	}


	void WindObjectScript::Update()
	{
		if (mEffectAnimator == nullptr)
		{
			mEffectAnimator = GetOwner()->GetComponent<Animator>();
		}


		switch (mState)
		{
		case Q::WindObjectScript::eState::WindObject:
			WindObject();
			break;
		case Q::WindObjectScript::eState::False:
			False();
			break;
		default:
			break;
		};
	};

	void WindObjectScript::LateUpdate()
	{
	}

	void WindObjectScript::Render(HDC hdc)
	{
	}

	void WindObjectScript::WindObject()
	{
		mState = WindObjectScript::eState::WindObject;
		if (mDirection == WindObjectScript::eDirection::Right)
		{
			mEffectAnimator->PlayAnimation(L"RightWindEffect");
		}
		else if (mDirection == WindObjectScript::eDirection::Left)
		{
			mEffectAnimator->PlayAnimation(L"LeftWindEffect");
		}
	}

	void WindObjectScript::False()
	{
		mState = WindObjectScript::eState::False;
		if (Input::GetKeyUp(eKeyCode::Z))
		{
			object::Destroy(GetOwner());
		}
	}


	// Ãæµ¹

	void WindObjectScript::OnCollisionEnter(Collider* other)
	{

	}

	
	void WindObjectScript::OnCollisionStay(Collider* other)
	{
		Transform* MonsterTr = other->GetOwner()->GetComponent<Transform>();
		translate(MonsterTr);

		
	}

	void WindObjectScript::OnCollisionExit(Collider* other)
	{
	}



	void WindObjectScript::translate(Transform* MonsterTr)
	{
		Vector2 pos = MonsterTr->GetPosition();

		switch (mDirection)
		{
		case Q::WindObjectScript::eDirection::Left:
			pos.x += 200.0f * Time::DeltaTime();
			break;
		case Q::WindObjectScript::eDirection::Right:
			pos.x -= 200.0f * Time::DeltaTime();

			break;
		default:
			assert(false);
			break;
		}

		MonsterTr->SetPosition(pos);
	}
	



	//Transform* tr = GetOwner()->GetComponent<Transform>();
	//translate(tr);

}