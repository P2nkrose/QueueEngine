#include "qSparkKirbyScript.h"
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
	SparkKirbyScript::SparkKirbyScript()
		: mState(SparkKirbyScript::eState::Stand)
		, mDirection(SparkKirbyScript::eDirection::Right)
		, mOneTime(false)
	{
	}

	SparkKirbyScript::~SparkKirbyScript()
	{
	}

	void SparkKirbyScript::Initialize()
	{
	}

	void SparkKirbyScript::Update()
	{
		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case Q::SparkKirbyScript::eState::Stand:
			Stand();
			break;
		case Q::SparkKirbyScript::eState::Walk:
			Walk();
			break;
		case Q::SparkKirbyScript::eState::Down:
			Down();
			break;
		case Q::SparkKirbyScript::eState::Tackle:
			Tackle();
			break;
		case Q::SparkKirbyScript::eState::Jump:
			break;
		case Q::SparkKirbyScript::eState::Effect:
			Effect();
			break;
		default:
			break;
		}
	}

	void SparkKirbyScript::LateUpdate()
	{
	}

	void SparkKirbyScript::Render(HDC hdc)
	{
	}

	// ½ºÅÄµå
	void SparkKirbyScript::Stand()
	{
		if (Input::GetKey(eKeyCode::Right))
		{
			mState = SparkKirbyScript::eState::Walk;
			mDirection = SparkKirbyScript::eDirection::Right;
			mAnimator->PlayAnimation(L"RightWalkSparkKirby");
		}
		else if (Input::GetKey(eKeyCode::Left))
		{
			mState = SparkKirbyScript::eState::Walk;
			mDirection = SparkKirbyScript::eDirection::Left;
			mAnimator->PlayAnimation(L"LeftWalkSparkKirby");
		}

		if (Input::GetKeyDown(eKeyCode::Down))
		{
			mState = SparkKirbyScript::eState::Down;
			if (mDirection == SparkKirbyScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightDownSparkKirby");
			}
			else if (mDirection == SparkKirbyScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftDownSparkKirby");
			}
		}


		if (Input::GetKeyDown(eKeyCode::Z))
		{
			mState = SparkKirbyScript::eState::Effect;
			mOneTime = false;
			if (mDirection == SparkKirbyScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightEffectSparkKirby", false);

			}
			else if (mDirection == SparkKirbyScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftEffectSparkKirby", false);

			}
		}

		if (Input::GetKeyDown(eKeyCode::Num1))
		{
			KirbyTypeManager::ChangeKirby(L"Normal");
			//renderer::mainCamera->SetTarget(GetOwner());
		}
		if (Input::GetKeyDown(eKeyCode::Num2))
		{
			KirbyTypeManager::ChangeKirby(L"Ice");
		}
		if (Input::GetKeyDown(eKeyCode::Num4))
		{
			KirbyTypeManager::ChangeKirby(L"Metal");
		}


	}

	// °È±â
	void SparkKirbyScript::Walk()
	{
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
			mState = SparkKirbyScript::eState::Stand;
			mDirection = SparkKirbyScript::eDirection::Right;
			mAnimator->PlayAnimation(L"RightStandSparkKirby", true);
		}
		else if (Input::GetKeyUp(eKeyCode::Left))
		{
			mState = SparkKirbyScript::eState::Stand;
			mDirection = SparkKirbyScript::eDirection::Left;
			mAnimator->PlayAnimation(L"LeftStandSparkKirby", true);

		}
	}

	// ¾É±â
	void SparkKirbyScript::Down()
	{
		if (Input::GetKeyDown(eKeyCode::Right))
		{
			mDirection == SparkKirbyScript::eDirection::Right;
			mAnimator->PlayAnimation(L"RightDownSparkKirby", true);
		}
		else if (Input::GetKeyDown(eKeyCode::Left))
		{
			mDirection == SparkKirbyScript::eDirection::Left;
			mAnimator->PlayAnimation(L"LeftDownSparkKirby", true);
		}


		if (Input::GetKeyDown(eKeyCode::X))
		{
			mState = SparkKirbyScript::eState::Tackle;
			if (mDirection == SparkKirbyScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightTackleSparkKirby", false);
			}
			else if (mDirection == SparkKirbyScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftTackleSparkKirby", false);
			}
		}


		if (Input::GetKeyUp(eKeyCode::Down))
		{
			mState = SparkKirbyScript::eState::Stand;
			if (mDirection == SparkKirbyScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightStandSparkKirby", true);
			}
			else if (mDirection == SparkKirbyScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftStandSparkKirby", true);
			}
		}
	}

	// ±â¼ú
	void SparkKirbyScript::Effect()
	{
		if (Input::GetKeyUp(eKeyCode::Z))
		{
			mState = SparkKirbyScript::eState::Stand;
			if (mDirection == SparkKirbyScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightStandSparkKirby", true);

			}
			else if (mDirection == SparkKirbyScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftStandSparkKirby", true);
			}
		}
	}

	// ÅÂÅ¬
	void SparkKirbyScript::Tackle()
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
			case Q::SparkKirbyScript::eDirection::Right:
				pos.x += 500.0f * Time::DeltaTime();
				break;
			case Q::SparkKirbyScript::eDirection::Left:
				pos.x -= 500.0f * Time::DeltaTime();
				break;
			case Q::SparkKirbyScript::eDirection::Down:
				break;
			default:
				break;
			}
		}

		tr->SetPosition(pos);
	}

	void SparkKirbyScript::Tackle2()
	{
		if (Input::GetKey(eKeyCode::Down))
		{
			mState = SparkKirbyScript::eState::Down;
			if (mDirection == SparkKirbyScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightDownSparkKirby", true);
			}
			else if (mDirection == SparkKirbyScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftDownSparkKirby", true);
			}
		}
		else
		{
			mState = SparkKirbyScript::eState::Stand;
			if (mDirection == SparkKirbyScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightStandSparkKirby", true);
			}
			else if (mDirection == SparkKirbyScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftStandSparkKirby", true);
			}
		}
	}
}