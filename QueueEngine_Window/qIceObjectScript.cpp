#include "qIceObjectScript.h"
#include "qInput.h"
#include "qTransform.h"
#include "qTime.h"
#include "qGameObject.h"
#include "qAnimator.h"
#include "qIceObject.h"
#include "qObject.h"
#include "qResources.h"
#include "qRenderer.h"

namespace Q
{
	extern Camera* mainCamera;

	IceObjectScript::IceObjectScript()
		: mState(IceObjectScript::eState::False)
		, mDirection(IceObjectScript::eDirection::Right)
	{
	}

	IceObjectScript::~IceObjectScript()
	{
	}

	void IceObjectScript::Initialize()
	{
	}

	void IceObjectScript::Update()
	{
		if (mEffectAnimator == nullptr)
		{
			mEffectAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case Q::IceObjectScript::eState::IceObject:
			IceObject();
			break;
		case Q::IceObjectScript::eState::False:
			False();
			break;
		default:
			break;
		}
	}

	void IceObjectScript::LateUpdate()
	{
	}

	void IceObjectScript::Render(HDC hdc)
	{
	}

	void IceObjectScript::IceObject()
	{
		mState = IceObjectScript::eState::IceObject;
		if (mDirection == IceObjectScript::eDirection::Right)
		{
			mEffectAnimator->PlayAnimation(L"RightWindEffect");
		}
		else if (mDirection == IceObjectScript::eDirection::Left)
		{
			mEffectAnimator->PlayAnimation(L"LeftWindEffect");
		}
	}

	void IceObjectScript::False()
	{
		mState = IceObjectScript::eState::False;
		if (Input::GetKeyUp(eKeyCode::Z))
		{
			object::Destroy(GetOwner());
		}
	}
}