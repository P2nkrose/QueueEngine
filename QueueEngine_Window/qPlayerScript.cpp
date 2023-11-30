#include "qPlayerScript.h"
#include "qInput.h"
#include "qTransform.h"
#include "qTime.h"
#include "qGameObject.h"
#include "qAnimator.h"

namespace Q
{
	PlayerScript::PlayerScript()
		: mState(PlayerScript::eState::Stand)
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
			stand();
			break;
		case Q::PlayerScript::eState::Walk:
			move();
			break;
		case Q::PlayerScript::eState::SitDown:
			break;
		case Q::PlayerScript::eState::Jump:
			break;
		case Q::PlayerScript::eState::Eat:
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
	void PlayerScript::stand()
	{
		if (Input::GetKey(eKeyCode::Right))
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"RightWalk");
		}

		if (Input::GetKey(eKeyCode::Left))
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"LeftWalk");
		}

		if (Input::GetKey(eKeyCode::Down))
		{

		}
	}
	void PlayerScript::move()
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


		if (Input::GetKeyUp(eKeyCode::Left) || Input::GetKeyUp(eKeyCode::Right))
		{
			mState = PlayerScript::eState::Stand;
			mAnimator->PlayAnimation(L"Stand", false);
		}
	}
}