#include "qWindObjectScript.h"
#include "qInput.h"
#include "qTransform.h"
#include "qTime.h"
#include "qGameObject.h"
#include "qAnimator.h"
#include "qWindObject.h"
#include "qObject.h"
#include "qResources.h"

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
}