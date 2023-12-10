#include "qIceKirbyScript.h"
#include "qInput.h"
#include "qTransform.h"
#include "qTime.h"
#include "qGameObject.h"
#include "qAnimator.h"
#include "qObject.h"
#include "qResources.h"
#include "qDashObject.h"
#include "qDashObjectScript.h"


namespace Q
{
	IceKirbyScript::IceKirbyScript()
		: mState(IceKirbyScript::eState::Stand)
		, mDirection(IceKirbyScript::eDirection::Right)
		, mOneTime(false)
		, mDeathTime(0.0f)
	{
	}

	IceKirbyScript::~IceKirbyScript()
	{
	}

	void IceKirbyScript::Initialize()
	{
	}

	void IceKirbyScript::Update()
	{
		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case Q::IceKirbyScript::eState::Stand:
			Stand();
			break;
		case Q::IceKirbyScript::eState::Walk:
			Walk();
			break;
		case Q::IceKirbyScript::eState::Down:
			Down();
			break;
		case Q::IceKirbyScript::eState::Tackle:
			Tackle();
			break;
		case Q::IceKirbyScript::eState::Jump:
			break;
		case Q::IceKirbyScript::eState::Effect:
			Effect();
			break;
		case Q::IceKirbyScript::eState::Effect2:
			Effect2();
			break;

		default:
			break;
		}
	}

	void IceKirbyScript::LateUpdate()
	{
	}

	void IceKirbyScript::Render(HDC hdc)
	{
	}



	void IceKirbyScript::Stand()
	{
		if (Input::GetKey(eKeyCode::Right))
		{
			mState = IceKirbyScript::eState::Walk;
			mDirection = IceKirbyScript::eDirection::Right;
			mAnimator->PlayAnimation(L"RightWalkIceKirby");
		}
		else if (Input::GetKey(eKeyCode::Left))
		{
			mState = IceKirbyScript::eState::Walk;
			mDirection = IceKirbyScript::eDirection::Left;
			mAnimator->PlayAnimation(L"LeftWalkIceKirby");
		}

		if (Input::GetKeyDown(eKeyCode::Down))
		{
			mState = IceKirbyScript::eState::Down;
			if (mDirection == IceKirbyScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightDownIceKirby");
			}
			else if (mDirection == IceKirbyScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftDownIceKirby");
			}
		}


		if (Input::GetKeyDown(eKeyCode::Z))
		{
			mState = IceKirbyScript::eState::Effect;
			mOneTime = false;
			if (mDirection == IceKirbyScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightEffectIceKirby", false);

			}
			else if (mDirection == IceKirbyScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftEffectIceKirby", false);

			}

		}
	}


	void IceKirbyScript::Down()
	{
		if (Input::GetKeyDown(eKeyCode::Right))
		{
			mDirection == IceKirbyScript::eDirection::Right;
			mAnimator->PlayAnimation(L"RightDownIceKirby", true);
		}
		else if (Input::GetKeyDown(eKeyCode::Left))
		{
			mDirection == IceKirbyScript::eDirection::Left;
			mAnimator->PlayAnimation(L"LeftDownIceKirby", true);
		}


		if (Input::GetKeyDown(eKeyCode::X))
		{
			mState = IceKirbyScript::eState::Tackle;
			if (mDirection == IceKirbyScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightTackleIceKirby", false);
			}
			else if (mDirection == IceKirbyScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftTackleIceKirby", false);
			}
		}



		if (Input::GetKeyUp(eKeyCode::Down))
		{
			mState = IceKirbyScript::eState::Stand;
			if (mDirection == IceKirbyScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightStandIceKirby", true);
			}
			else if (mDirection == IceKirbyScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftStandIceKirby", true);
			}
		}
	}

	void IceKirbyScript::Walk()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 100.0f * Time::DeltaTime();
			// 2초있다가 스탠드로
		}
		else if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}


		tr->SetPosition(pos);

		if (Input::GetKeyUp(eKeyCode::Right))
		{
			mState = IceKirbyScript::eState::Stand;
			mDirection = IceKirbyScript::eDirection::Right;
			mAnimator->PlayAnimation(L"RightStandIceKirby", true);
		}
		else if (Input::GetKeyUp(eKeyCode::Left))
		{
			mState = IceKirbyScript::eState::Stand;
			mDirection = IceKirbyScript::eDirection::Left;
			mAnimator->PlayAnimation(L"LeftStandIceKirby", true);

		}
	}

	

	void IceKirbyScript::Effect()
	{
		if (Input::GetKeyUp(eKeyCode::Z))
		{
			mState = IceKirbyScript::eState::Stand;
			if (mDirection == IceKirbyScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightStandIceKirby", true);

			}
			else if (mDirection == IceKirbyScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftStandIceKirby", true);
			}
		}
	}

	void IceKirbyScript::Effect2()
	{
		// 이즈컴플리트
	}

	void IceKirbyScript::Tackle()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::X))
		{
			if (mDirection == IceKirbyScript::eDirection::Right)
			{

				pos.x += 300.0f * Time::DeltaTime();

			}
			else if (mDirection == IceKirbyScript::eDirection::Left)
			{

				pos.x -= 300.0f * Time::DeltaTime();
			}
		}

		tr->SetPosition(pos);






		if (Input::GetKeyUp(eKeyCode::X))
		{
			if (Input::GetKey(eKeyCode::Down))
			{
				mState = IceKirbyScript::eState::Down;
				if (mDirection == IceKirbyScript::eDirection::Right)
				{
					mAnimator->PlayAnimation(L"RightDownIceKirby", true);
				}
				else if (mDirection == IceKirbyScript::eDirection::Left)
				{
					mAnimator->PlayAnimation(L"LeftDownIceKirby", true);
				}
			}
			else
			{
				mState = IceKirbyScript::eState::Stand;
				if (mDirection == IceKirbyScript::eDirection::Right)
				{
					mAnimator->PlayAnimation(L"RightStandIceKirby", true);
				}
				else if (mDirection == IceKirbyScript::eDirection::Left)
				{
					mAnimator->PlayAnimation(L"LeftStandIceKirby", true);
				}
			}

		}

	}
}