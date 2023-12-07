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
		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case Q::WindObjectScript::eState::WindObject:
			WindObject();
			break;
		case Q::WindObjectScript::eState::False:
			break;
		default:
			break;
		}
	}

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
			mAnimator->PlayAnimation(L"RightWindEffect");
		}
		else if (mDirection == WindObjectScript::eDirection::Left)
		{
			mAnimator->PlayAnimation(L"LeftWindEffect");
		}
	}
}