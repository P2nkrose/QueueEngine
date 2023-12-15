#include "qMetalKirbyScript.h"
#include "qResources.h"
#include "qKirbyTypeManager.h"
#include "qRenderer.h"
#include "qInput.h"
#include "qTransform.h"
#include "qTime.h"
#include "qGameObject.h"
#include "qAnimator.h"
#include "qObject.h"
#include "qRenderer.h"

namespace Q
{
	MetalKirbyScript::MetalKirbyScript()
		: mState(MetalKirbyScript::eState::Stand)
		, mDirection(MetalKirbyScript::eDirection::Right)
		, mOneTime(false)
	{
	}

	MetalKirbyScript::~MetalKirbyScript()
	{
	}

	void MetalKirbyScript::Initialize()
	{
	}

	void MetalKirbyScript::Update()
	{
		if(mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case Q::MetalKirbyScript::eState::Stand:
			Stand();
			break;
		case Q::MetalKirbyScript::eState::Walk:
			Walk();
			break;
		case Q::MetalKirbyScript::eState::Down:
			Down();
			break;
		case Q::MetalKirbyScript::eState::Tackle:
			Tackle();
			break;
		case Q::MetalKirbyScript::eState::Jump:
			break;
		case Q::MetalKirbyScript::eState::Effect:
			Effect();
			break;
		case Q::MetalKirbyScript::eState::EffectWalk:
			EffectWalk();
			break;
		default:
			break;
		}
	}

	void MetalKirbyScript::LateUpdate()
	{
	}

	void MetalKirbyScript::Render(HDC hdc)
	{
	}



	void MetalKirbyScript::Stand()
	{
		if (Input::GetKey(eKeyCode::Right))
		{
			mState = MetalKirbyScript::eState::Walk;
			mDirection = MetalKirbyScript::eDirection::Right;
			mAnimator->PlayAnimation(L"RightWalkMetalKirby");
		}
		else if (Input::GetKey(eKeyCode::Left))
		{
			mState = MetalKirbyScript::eState::Walk;
			mDirection = MetalKirbyScript::eDirection::Left;
			mAnimator->PlayAnimation(L"LeftWalkMetalKirby");
		}

		if (Input::GetKeyDown(eKeyCode::Down))
		{
			mState = MetalKirbyScript::eState::Down;
			if (mDirection == MetalKirbyScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightDownMetalKirby");
			}
			else if (mDirection == MetalKirbyScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftDownMetalKirby");
			}
		}

		if (Input::GetKeyDown(eKeyCode::Z))
		{
			mState = MetalKirbyScript::eState::Effect;
			if (mDirection == MetalKirbyScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightEffectModeStandMetalKirby", false);
			}
			else if (mDirection == MetalKirbyScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftEffectModeStandMetalKirby", false);
			}
		}


		// 커비 바꾸기

		if (Input::GetKeyDown(eKeyCode::Num1))
		{
			KirbyTypeManager::ChangeKirby(L"Normal");
			//renderer::mainCamera->SetTarget(GetOwner());
		}
		if (Input::GetKeyDown(eKeyCode::Num2))
		{
			KirbyTypeManager::ChangeKirby(L"Ice");
		}
		if (Input::GetKeyDown(eKeyCode::Num3))
		{
			KirbyTypeManager::ChangeKirby(L"Spark");
		}
		if (Input::GetKeyDown(eKeyCode::Num5))
		{
			KirbyTypeManager::ChangeKirby(L"Ninja");
			//renderer::mainCamera->SetTarget(GetOwner());
		}


	}

	void MetalKirbyScript::Walk()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 95.0f * Time::DeltaTime();
		}
		else if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 95.0f * Time::DeltaTime();
		}


		tr->SetPosition(pos);

		if (Input::GetKeyUp(eKeyCode::Right))
		{
			mState = MetalKirbyScript::eState::Stand;
			mDirection = MetalKirbyScript::eDirection::Right;
			mAnimator->PlayAnimation(L"RightStandMetalKirby", true);
		}
		else if (Input::GetKeyUp(eKeyCode::Left))
		{
			mState = MetalKirbyScript::eState::Stand;
			mDirection = MetalKirbyScript::eDirection::Left;
			mAnimator->PlayAnimation(L"LeftStandMetalKirby", true);

		}
	}

	void MetalKirbyScript::Down()
	{
		if (Input::GetKeyDown(eKeyCode::Right))
		{
			mDirection == MetalKirbyScript::eDirection::Right;
			mAnimator->PlayAnimation(L"RightDownMetalKirby", true);
		}
		else if (Input::GetKeyDown(eKeyCode::Left))
		{
			mDirection == MetalKirbyScript::eDirection::Left;
			mAnimator->PlayAnimation(L"LeftDownMetalKirby", true);
		}

		if (Input::GetKeyDown(eKeyCode::X))
		{
			mState = MetalKirbyScript::eState::Tackle;
			if (mDirection == MetalKirbyScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightTackleMetalKirby", false);
			}
			else if (mDirection == MetalKirbyScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftTackleMetalKirby", false);
			}
		}

		if (Input::GetKeyUp(eKeyCode::Down))
		{
			mState = MetalKirbyScript::eState::Stand;
			if (mDirection == MetalKirbyScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightStandMetalKirby", true);
			}
			else if (mDirection == MetalKirbyScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftStandMetalKirby", true);
			}
		}

	}

	void MetalKirbyScript::Effect()
	{
		mState = MetalKirbyScript::eState::EffectStand;

		if (Input::GetKeyDown(eKeyCode::Z))
		{
			mState = MetalKirbyScript::eState::Stand;
			if (mDirection == MetalKirbyScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightStandMetalKirby", true);
			}
			else if (mDirection == MetalKirbyScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftStandMetalKirby", true);
			}
		}

		if (mState == MetalKirbyScript::eState::EffectStand)
		{
			if (Input::GetKey(eKeyCode::Right))
			{
				mDirection = MetalKirbyScript::eDirection::Right;
				mAnimator->PlayAnimation(L"RightEffectModeWalkMetalKirby", true);
				EffectWalk();
			}
			else if (Input::GetKey(eKeyCode::Left))
			{
				mDirection = MetalKirbyScript::eDirection::Left;
				mAnimator->PlayAnimation(L"LeftEffectModeWalkMetalKirby", true);
				EffectWalk();
			}
		}
	}

	void MetalKirbyScript::EffectWalk()
	{
		mState = MetalKirbyScript::eState::EffectWalk;

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 100.0f * Time::DeltaTime();
		}
		else if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}


		tr->SetPosition(pos);


		if (Input::GetKeyUp(eKeyCode::Right))
		{
			mState = MetalKirbyScript::eState::EffectStand;
			mDirection = MetalKirbyScript::eDirection::Right;
			mAnimator->PlayAnimation(L"RightEffectModeStandMetalKirby", true);
		}
		else if (Input::GetKeyUp(eKeyCode::Left))
		{
			mState = MetalKirbyScript::eState::EffectStand;
			mDirection = MetalKirbyScript::eDirection::Left;
			mAnimator->PlayAnimation(L"LeftEffectModeStandMetalKirby", true);
		}

	}

	void MetalKirbyScript::Tackle()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (mAnimator->IsComplete())
		{
			Tackle2();
		}
		else
		{
			switch (mDirection)
			{
			case Q::MetalKirbyScript::eDirection::Right:
				pos.x += 700.0f * Time::DeltaTime();
				break;
			case Q::MetalKirbyScript::eDirection::Left:
				pos.x -= 700.0f * Time::DeltaTime();
				break;
			case Q::MetalKirbyScript::eDirection::Down:
				break;
			default:
				break;
			}
		}

		tr->SetPosition(pos);
	}

	void MetalKirbyScript::Tackle2()
	{
		if (Input::GetKey(eKeyCode::Down))
		{
			mState = MetalKirbyScript::eState::Down;
			if (mDirection == MetalKirbyScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightDownMetalKirby", true);
			}
			else if (mDirection == MetalKirbyScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftDownMetalKirby", true);
			}
		}
		else
		{
			mState = MetalKirbyScript::eState::Stand;
			if (mDirection == MetalKirbyScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightStandMetalKirby", true);
				if (Input::GetKeyDown(eKeyCode::Z))
				{
					mAnimator->PlayAnimation(L"RightStandMetalKirby", true);
				}
			}
			else if (mDirection == MetalKirbyScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftStandMetalKirby", true);
				if (Input::GetKeyDown(eKeyCode::Z))
				{
					mAnimator->PlayAnimation(L"LeftStandMetalKirby", true);
				}
			}
		}
	}

	
}