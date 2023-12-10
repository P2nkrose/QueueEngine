#include "qDashObjectScript.h"
#include "qInput.h"
#include "qTransform.h"
#include "qTime.h"
#include "qGameObject.h"
#include "qAnimator.h"
#include "qDashObject.h"
#include "qObject.h"
#include "qResources.h"

namespace Q
{
	DashObjectScript::DashObjectScript()
		: mState(DashObjectScript::eState::False)
		, mDirection(DashObjectScript::eDirection::Right)
	{
	}

	DashObjectScript::~DashObjectScript()
	{
	}

	void DashObjectScript::Initialize()
	{
	}

	void DashObjectScript::Update()
	{
		if (mEffectAnimator == nullptr)
		{
			mEffectAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case Q::DashObjectScript::eState::DashObject:
			DashObject();
			break;
		case Q::DashObjectScript::eState::False:
			False();
			break;
		default:
			break;
		}
	}

	void DashObjectScript::LateUpdate()
	{
	}

	void DashObjectScript::Render(HDC hdc)
	{
	}

	void DashObjectScript::DashObject()
	{
		mState = DashObjectScript::eState::DashObject;
		if (mDirection == DashObjectScript::eDirection::Right)
		{
			mEffectAnimator->PlayAnimation(L"RightDashEffect");
		}
		else if (mDirection == DashObjectScript::eDirection::Left)
		{
			mEffectAnimator->PlayAnimation(L"LeftDashEffect");
		}
	}

	void DashObjectScript::False()
	{
		mState = DashObjectScript::eState::False;
		if (Input::GetKeyUp(eKeyCode::X))
		{
			object::Destroy(GetOwner());
		}
	}
}