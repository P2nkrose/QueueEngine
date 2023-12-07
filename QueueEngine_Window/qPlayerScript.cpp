#include "qPlayerScript.h"
#include "qInput.h"
#include "qTransform.h"
#include "qTime.h"
#include "qGameObject.h"
#include "qAnimator.h"
#include "qWindObject.h"
#include "qWindObjectScript.h"
#include "qObject.h"
#include "qResources.h"


namespace Q
{
	PlayerScript::PlayerScript()
		: mState(PlayerScript::eState::Stand)
		, mDirection(PlayerScript::eDirection::Right)
		, oneTime(false)
	{
	}
	PlayerScript::~PlayerScript()
	{
	}
	void PlayerScript::Initialize()
	{
	}
	void PlayerScript::Update()
	{
		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case Q::PlayerScript::eState::Stand:
			Stand();
			break;
		case Q::PlayerScript::eState::Walk:
			Walk();
			break;
		case Q::PlayerScript::eState::Down:
			Down();
			break;
		case Q::PlayerScript::eState::Jump:
			break;
		case Q::PlayerScript::eState::Wind:
			Wind();
			break;
		case Q::PlayerScript::eState::Wind2:
			Wind2();
			break;
		case Q::PlayerScript::eState::Tackle:
			Tackle();
			break;
		default:
			break;
		}



	}

	void PlayerScript::LateUpdate()
	{
	}

	void PlayerScript::Render(HDC hdc)
	{
	}


	// 스탠드
	void PlayerScript::Stand()
	{

		// 이펙트
		WindObject* windObject = object::Instantiate<WindObject>(enums::eLayerType::Effect);
		WindObjectScript* windSrc = windObject->AddComponent<WindObjectScript>();


		graphics::Texture* rightWindEffectTex = Resources::Find<graphics::Texture>(L"RightWindEffect");
		graphics::Texture* leftWindEffectTex = Resources::Find<graphics::Texture>(L"LeftWindEffect");

		Animator* windEffectAnimator = windObject->AddComponent<Animator>();

		windEffectAnimator->CreateAnimation(L"RightWindEffect", rightWindEffectTex,
			Vector2(0.0f, 0.0f), Vector2(50.0f, 30.0f), Vector2::Zero, 2, 0.1f);

		windEffectAnimator->CreateAnimation(L"LeftWindEffect", leftWindEffectTex,
			Vector2(0.0f, 0.0f), Vector2(50.0f, 30.0f), Vector2::Zero, 2, 0.1f);

		windEffectAnimator->PlayAnimation(L"RightWindEffect", false);

		Transform* tr = GetOwner()->GetComponent<Transform>();

		windObject->GetComponent<Transform>()->SetPosition(tr->GetPosition() + Vector2(50.0f, 0.0f));
		windObject->GetComponent<Transform>()->SetScale(Vector2(1.5f, 1.5f));

		

		
		// 마우스
		if (Input::GetKey(eKeyCode::LButton))
		{
			Vector2 mousePos = Input::GetMousePosition();
		}

		// 키보드
		if (Input::GetKey(eKeyCode::Right))
		{
			mState = PlayerScript::eState::Walk;
			mDirection = PlayerScript::eDirection::Right;
			mAnimator->PlayAnimation(L"RightWalkKirby");
		}
		else if (Input::GetKey(eKeyCode::Left))
		{
			mState = PlayerScript::eState::Walk;
			mDirection = PlayerScript::eDirection::Left;
			mAnimator->PlayAnimation(L"LeftWalkKirby");
		}

		if (Input::GetKeyDown(eKeyCode::Down))
		{
			mState = PlayerScript::eState::Down;
			if (mDirection == PlayerScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightDownKirby");
			}
			else if (mDirection == PlayerScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftDownKirby");
			}
		}


		if (Input::GetKeyDown(eKeyCode::Z))
		{
			mState = PlayerScript::eState::Wind;
			oneTime = false;
			if (mDirection == PlayerScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightWindKirby", false);

			}
			else if (mDirection == PlayerScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftWindKirby", false);
				
			}

		}
		
	}

	// 다운

	void PlayerScript::Down()
	{
		if (Input::GetKeyDown(eKeyCode::Right))
		{
			mDirection == PlayerScript::eDirection::Right;
			mAnimator->PlayAnimation(L"RightDownKirby", true);
			if (Input::GetKeyDown(eKeyCode::Left))
			{
				mDirection == PlayerScript::eDirection::Left;
				mAnimator->PlayAnimation(L"LeftDownKirby", true);
			}
		}
		else if (Input::GetKeyDown(eKeyCode::Left))
		{
			mDirection == PlayerScript::eDirection::Left;
			mAnimator->PlayAnimation(L"LeftDownKirby", true);
		}


		if (Input::GetKeyDown(eKeyCode::X))
		{
			mState = PlayerScript::eState::Tackle;
			if (mDirection == PlayerScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightTackleKirby", false);
			}
			else if (mDirection == PlayerScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftTackleKirby", false);
			}
		}



		if (Input::GetKeyUp(eKeyCode::Down))
		{
			mState = PlayerScript::eState::Stand;
			if (mDirection == PlayerScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightStandKirby", true);
			}
			else if (mDirection == PlayerScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftStandKirby", true);
			}
		}
	}

	// 워크

	void PlayerScript::Walk()
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
			mState = PlayerScript::eState::Stand;
			mDirection = PlayerScript::eDirection::Right;
			mAnimator->PlayAnimation(L"RightStandKirby", true);
		}
		else if (Input::GetKeyUp(eKeyCode::Left))
		{
			mState = PlayerScript::eState::Stand;
			mDirection = PlayerScript::eDirection::Left;
			mAnimator->PlayAnimation(L"LeftStandKirby", true);

		}
	}

	// 윈드

	void PlayerScript::Wind()
	{
		if (Input::GetKeyUp(eKeyCode::Z))
		{
			mState = PlayerScript::eState::Stand;
			if (mDirection == PlayerScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightStandKirby", true);
				
			}
			else if (mDirection == PlayerScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftStandKirby", true);
			}
		}
	}

	// 태클

	void PlayerScript::Tackle()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		if (Input::GetKey(eKeyCode::X))
		{
			if (mDirection == PlayerScript::eDirection::Right)
			{
				pos.x += 300.0f * Time::DeltaTime();
				
			}
			else if (mDirection == PlayerScript::eDirection::Left)
			{
				pos.x -= 300.0f * Time::DeltaTime();
			}
		}

		tr->SetPosition(pos);

		if (Input::GetKeyUp(eKeyCode::X))
		{
			if (Input::GetKey(eKeyCode::Down))
			{
				mState = PlayerScript::eState::Down;
				if (mDirection == PlayerScript::eDirection::Right)
				{
					mAnimator->PlayAnimation(L"RightDownKirby", true);
				}
				else if (mDirection == PlayerScript::eDirection::Left)
				{
					mAnimator->PlayAnimation(L"LeftDownKirby", true);
				}
			}
			else
			{
				mState = PlayerScript::eState::Stand;
				if (mDirection == PlayerScript::eDirection::Right)
				{
					mAnimator->PlayAnimation(L"RightStandKirby", true);
				}
				else if (mDirection == PlayerScript::eDirection::Left)
				{
					mAnimator->PlayAnimation(L"LeftStandKirby", true);
				}
			}

		}
	
	}
	
	// 윈드2

	void PlayerScript::Wind2()
	{
		if (Input::GetKey(eKeyCode::Z))
		{
			mState = PlayerScript::eState::Wind2;

			if (mDirection == PlayerScript::eDirection::Right && oneTime == false)
			{
				// 한번만 실행되게 조건을 걸어야 함(if문이나 bool)
				mAnimator->PlayAnimation(L"RightWindKirby2", true);
			}
			else if (mDirection == PlayerScript::eDirection::Left && oneTime == false)
			{
				mAnimator->PlayAnimation(L"LeftWindKirby2", true);
			}
			oneTime = true;
		}


		if (Input::GetKeyUp(eKeyCode::Z))
		{
			mState = PlayerScript::eState::Stand;
			if (mDirection == PlayerScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightStandKirby", true);

			}
			else if (mDirection == PlayerScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftStandKirby", true);
			}
		}
	}

	void PlayerScript::WindEffect()
	{


	}





}


