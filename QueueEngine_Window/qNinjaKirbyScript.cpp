#include "qNinjaKirbyScript.h"
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
#include "qDaggerObject.h"
#include "qDaggerObjectScript.h"

namespace Q
{
	NinjaKirbyScript::NinjaKirbyScript()
		: mState(NinjaKirbyScript::eState::Stand)
		, mDirection(NinjaKirbyScript::eDirection::Right)
		, mOneTime(false)
	{
	}

	NinjaKirbyScript::~NinjaKirbyScript()
	{
	}

	void NinjaKirbyScript::Initialize()
	{
	}

	void NinjaKirbyScript::Update()
	{
		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case Q::NinjaKirbyScript::eState::Stand:
			Stand();
			break;
		case Q::NinjaKirbyScript::eState::Walk:
			Walk();
			break;
		case Q::NinjaKirbyScript::eState::Down:
			Down();
			break;
		case Q::NinjaKirbyScript::eState::Tackle:
			Tackle();
			break;
		case Q::NinjaKirbyScript::eState::Jump:
			break;
		case Q::NinjaKirbyScript::eState::Dagger:
			Dagger();
			break;
		case Q::NinjaKirbyScript::eState::Sting:
			Sting();
			break;
		default:
			break;
		}
	}

	void NinjaKirbyScript::LateUpdate()
	{
	}

	void NinjaKirbyScript::Render(HDC hdc)
	{
	}

	// 스탠드
	void NinjaKirbyScript::Stand()
	{
		mState = NinjaKirbyScript::eState::Stand;
		if (mDirection == NinjaKirbyScript::eDirection::Right)
		{
			mAnimator->PlayAnimation(L"RightStandNinjaKirby", true);
		}
		else if (mDirection == NinjaKirbyScript::eDirection::Left)
		{
			mAnimator->PlayAnimation(L"LeftStandNinjaKirby", true);
		}

		if (Input::GetKey(eKeyCode::Right))
		{
			mState = NinjaKirbyScript::eState::Walk;
			mDirection = NinjaKirbyScript::eDirection::Right;
			mAnimator->PlayAnimation(L"RightWalkNinjaKirby");
		}
		else if (Input::GetKey(eKeyCode::Left))
		{
			mState = NinjaKirbyScript::eState::Walk;
			mDirection = NinjaKirbyScript::eDirection::Left;
			mAnimator->PlayAnimation(L"LeftWalkNinjaKirby");
		}

		if (Input::GetKeyDown(eKeyCode::Down))
		{
			mState = NinjaKirbyScript::eState::Down;
			if (mDirection == NinjaKirbyScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightDownNinjaKirby");
			}
			else if (mDirection == NinjaKirbyScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftDownNinjaKirby");
			}
		}

		if (Input::GetKeyDown(eKeyCode::Z))
		{
			// 표창 이펙트
			Transform* tr = GetOwner()->GetComponent<Transform>();

			DaggerObject* rightDaggerObject = object::Instantiate<DaggerObject>(enums::eLayerType::Effect, tr->GetPosition() + Vector2(70.0f, 20.0f));
			DaggerObject* leftDaggerObject = object::Instantiate<DaggerObject>(enums::eLayerType::Effect, tr->GetPosition() + Vector2(-20.0f, 20.0f));
			
		
			DaggerObjectScript* rightDaggerSrc = rightDaggerObject->AddComponent<DaggerObjectScript>();
			DaggerObjectScript* leftDaggerSrc = leftDaggerObject->AddComponent<DaggerObjectScript>();

			graphics::Texture* RightDaggerEffectTex = Resources::Find<graphics::Texture>(L"RightDaggerEffect");
			graphics::Texture* LeftDaggerEffectTex = Resources::Find<graphics::Texture>(L"LeftDaggerEffect");

			Animator* rightDaggerEffectAnimator = rightDaggerObject->AddComponent<Animator>();
			Animator* leftDaggerEffectAnimator = leftDaggerObject->AddComponent<Animator>();


			rightDaggerEffectAnimator->CreateAnimation(L"RightDaggerEffect", RightDaggerEffectTex,
				Vector2(0.0f, 0.0f), Vector2(29.0f, 30.0f), Vector2::Zero, 8, 0.1f);

			leftDaggerEffectAnimator->CreateAnimation(L"LeftDaggerEffect", LeftDaggerEffectTex,
				Vector2(0.0f, 0.0f), Vector2(29.0f, 30.0f), Vector2::Zero, 8, 0.1f);

			rightDaggerObject->GetComponent<Transform>()->SetScale(Vector2::Half);
			leftDaggerObject->GetComponent<Transform>()->SetScale(Vector2::Half);



			mState = NinjaKirbyScript::eState::Dagger;
			mOneTime = false;
			if (mDirection == NinjaKirbyScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightDaggerNinjaKirby", false);
				rightDaggerEffectAnimator->PlayAnimation(L"RightDaggerEffect", true);
			}
			else if (mDirection == NinjaKirbyScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftDaggerNinjaKirby", false);
				//leftDaggerEffectAnimator->PlayAnimation(L"LeftDaggerEffect", true);
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
			//renderer::mainCamera->SetTarget(GetOwner());
		}
		if (Input::GetKeyDown(eKeyCode::Num4))
		{
			KirbyTypeManager::ChangeKirby(L"Metal");
			//renderer::mainCamera->SetTarget(GetOwner());
		}

	}
	
	// 다운
	void NinjaKirbyScript::Down()
	{
		if (Input::GetKeyDown(eKeyCode::Right))
		{
			mDirection == NinjaKirbyScript::eDirection::Right;
			mAnimator->PlayAnimation(L"RightDownNinjaKirby", true);
		}
		else if (Input::GetKeyDown(eKeyCode::Left))
		{
			mDirection == NinjaKirbyScript::eDirection::Left;
			mAnimator->PlayAnimation(L"LeftDownNinjaKirby", true);
		}


		if (Input::GetKeyDown(eKeyCode::X))
		{
			mState = NinjaKirbyScript::eState::Tackle;
			if (mDirection == NinjaKirbyScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightTackleNinjaKirby", false);
			}
			else if (mDirection == NinjaKirbyScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftTackleNinjaKirby", false);
			}
		}

		if (Input::GetKeyDown(eKeyCode::Z))
		{
			mState = NinjaKirbyScript::eState::Sting;
			if (mDirection == NinjaKirbyScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightStingNinjaKirby", false);
			}
			else if (mDirection == NinjaKirbyScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftStingNinjaKirby", false);
			}
		}


		if (Input::GetKeyUp(eKeyCode::Down))
		{
			mState = NinjaKirbyScript::eState::Stand;
			if (mDirection == NinjaKirbyScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightStandNinjaKirby", true);
			}
			else if (mDirection == NinjaKirbyScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftStandNinjaKirby", true);
			}
		}
	}

	// 워크
	void NinjaKirbyScript::Walk()
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
			mState = NinjaKirbyScript::eState::Stand;
			mDirection = NinjaKirbyScript::eDirection::Right;
			mAnimator->PlayAnimation(L"RightStandNinjaKirby", true);
		}
		else if (Input::GetKeyUp(eKeyCode::Left))
		{
			mState = NinjaKirbyScript::eState::Stand;
			mDirection = NinjaKirbyScript::eDirection::Left;
			mAnimator->PlayAnimation(L"LeftStandNinjaKirby", true);

		}
	}

	// 태클
	void NinjaKirbyScript::Tackle()
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
			case Q::NinjaKirbyScript::eDirection::Right:
				pos.x += 600.0f * Time::DeltaTime();
				break;
			case Q::NinjaKirbyScript::eDirection::Left:
				pos.x -= 600.0f * Time::DeltaTime();
				break;
			case Q::NinjaKirbyScript::eDirection::Down:
				break;
			default:
				break;
			}
		}

		tr->SetPosition(pos);
	}

	void NinjaKirbyScript::Tackle2()
	{
		if (Input::GetKey(eKeyCode::Down))
		{
			mState = NinjaKirbyScript::eState::Down;
			if (mDirection == NinjaKirbyScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightDownNinjaKirby", true);
			}
			else if (mDirection == NinjaKirbyScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftDownNinjaKirby", true);
			}
		}
		else
		{
			mState = NinjaKirbyScript::eState::Stand;
			if (mDirection == NinjaKirbyScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightStandNinjaKirby", true);
			}
			else if (mDirection == NinjaKirbyScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftStandNinjaKirby", true);
			}
		}
	}



	void NinjaKirbyScript::Dagger()
	{
		

	}

	// 찌르기스킬
	void NinjaKirbyScript::Sting()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (mAnimator->IsComplete())
		{
			Sting2();
		}
		else
		{
			switch (mDirection)
			{
			case Q::NinjaKirbyScript::eDirection::Right:
				pos.x += 100.0f * Time::DeltaTime();
				break;
			case Q::NinjaKirbyScript::eDirection::Left:
				pos.x -= 100.0f * Time::DeltaTime();
				break;
			case Q::NinjaKirbyScript::eDirection::Down:
				break;
			default:
				break;
			}
		}

		tr->SetPosition(pos);
	}

	void NinjaKirbyScript::Sting2()
	{
		if (Input::GetKey(eKeyCode::Down))
		{
			mState = NinjaKirbyScript::eState::Down;
			if (mDirection == NinjaKirbyScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightDownNinjaKirby", true);
			}
			else if (mDirection == NinjaKirbyScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftDownNinjaKirby", true);
			}
		}
		else
		{
			mState = NinjaKirbyScript::eState::Stand;
			if (mDirection == NinjaKirbyScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightStandNinjaKirby", true);
			}
			else if (mDirection == NinjaKirbyScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftStandNinjaKirby", true);
			}
		}
	}
}