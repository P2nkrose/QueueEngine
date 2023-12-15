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
#include "qKirbyTypeManager.h"
#include "qIceObject.h"
#include "qIceObjectScript.h"
#include "qRenderer.h"

namespace Q
{

	extern Camera* mainCamera;

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
		case Q::IceKirbyScript::eState::Tackle2:
			Tackle2();
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


	// 스탠드
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

		if (Input::GetKeyDown(eKeyCode::Num1))
		{
			KirbyTypeManager::ChangeKirby(L"Normal");
			//renderer::mainCamera->SetTarget(GetOwner());
		}
		if (Input::GetKeyDown(eKeyCode::Num3))
		{
			KirbyTypeManager::ChangeKirby(L"Spark");
			//renderer::mainCamera->SetTarget(GetOwner());
		}
		if (Input::GetKeyDown(eKeyCode::Num4))
		{
			KirbyTypeManager::ChangeKirby(L"Metal");
			//renderer::mainCamera->SetTarget(GetOwner());
		}
		if (Input::GetKeyDown(eKeyCode::Num5))
		{
			KirbyTypeManager::ChangeKirby(L"Ninja");
			//renderer::mainCamera->SetTarget(GetOwner());
		}


	}

	// 다운
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

	// 워크
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

	// 이펙트
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

		// 이펙트
		IceObject* rightIceObject = object::Instantiate<IceObject>(enums::eLayerType::Effect);
		IceObject* leftIceObject = object::Instantiate<IceObject>(enums::eLayerType::Effect);
		IceObjectScript* rightIceSrc = rightIceObject->AddComponent<IceObjectScript>();
		IceObjectScript* leftIceSrc = leftIceObject->AddComponent<IceObjectScript>();

		rightIceSrc->SetEffect(GetOwner());
		leftIceSrc->SetEffect(GetOwner());

		graphics::Texture* rightIceEffectTex = Resources::Find<graphics::Texture>(L"RightIceEffect");
		graphics::Texture* leftIceEffectTex = Resources::Find<graphics::Texture>(L"LeftIceEffect");

		Animator* rightIceEffectAnimator = rightIceObject->AddComponent<Animator>();
		Animator* leftIceEffectAnimator = leftIceObject->AddComponent<Animator>();

		rightIceEffectAnimator->CreateAnimation(L"RightIceEffect", rightIceEffectTex,
			Vector2(0.0f, 0.0f), Vector2(64.0f, 43.0f), Vector2::Zero, 4, 0.1f);

		leftIceEffectAnimator->CreateAnimation(L"LeftIceEffect", leftIceEffectTex,
			Vector2(0.0f, 0.0f), Vector2(64.0f, 43.0f), Vector2::Zero, 4, 0.1f);

		Transform* tr = GetOwner()->GetComponent<Transform>();

		rightIceObject->GetComponent<Transform>()->SetPosition(tr->GetPosition() + Vector2(80.0f, 0.0f));
		leftIceObject->GetComponent<Transform>()->SetPosition(tr->GetPosition() + Vector2(-110.0f, 0.0f));

		rightIceObject->GetComponent<Transform>()->SetScale(Vector2::Two);
		leftIceObject->GetComponent<Transform>()->SetScale(Vector2::Two);






		if (Input::GetKey(eKeyCode::Z))
		{
			mState = IceKirbyScript::eState::Effect2;
			if (mDirection == IceKirbyScript::eDirection::Right && mOneTime == false)
			{
				// 한번만 실행되게 조건을 걸어야 함(if문이나 bool)
				mAnimator->PlayAnimation(L"RightEffectIceKirby2", true);
				rightIceEffectAnimator->PlayAnimation(L"RightIceEffect", true);

			}
			else if (mDirection == IceKirbyScript::eDirection::Left && mOneTime == false)
			{
				mAnimator->PlayAnimation(L"LeftEffectIceKirby2", true);
				leftIceEffectAnimator->PlayAnimation(L"LeftIceEffect", true);
			}
			mOneTime = true;
		}

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


	// 태클
	void IceKirbyScript::Tackle()
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
			case Q::IceKirbyScript::eDirection::Right:
				pos.x += 700.0f * Time::DeltaTime();
				break;
			case Q::IceKirbyScript::eDirection::Left:
				pos.x -= 700.0f * Time::DeltaTime();
				break;
			case Q::IceKirbyScript::eDirection::Down:
				break;
			default:
				break;
			}
		}

		tr->SetPosition(pos);


	}

	void IceKirbyScript::Tackle2()
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