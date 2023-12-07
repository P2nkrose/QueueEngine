#include "qWaddleDeeScript.h"
#include "qTransform.h"
#include "qTime.h"
#include "qGameObject.h"
#include "qAnimator.h"

namespace Q
{
	WaddleDeeScript::WaddleDeeScript()
		: mState(WaddleDeeScript::eState::Walk)
		, mAnimator(nullptr)
		, mTime(0.0f)
	{
	}

	WaddleDeeScript::~WaddleDeeScript()
	{
	}

	void WaddleDeeScript::Initialize()
	{
	}

	void WaddleDeeScript::Update()
	{
		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case Q::WaddleDeeScript::eState::Walk:
			walk();
			break;
		default:
			break;
		}

	}

	void WaddleDeeScript::LateUpdate()
	{
	}

	void WaddleDeeScript::Render(HDC hdc)
	{
	}

	void WaddleDeeScript::walk()
	{
		mTime += Time::DeltaTime();
		if (mTime > 1.0f)
		{	
			mState = WaddleDeeScript::eState::Walk;
			int direction = rand() % 2;
			mDirection = (eDirection)direction;
			mTime = 0.0f;
			playWalkAnimationBydirection(mDirection);
		}
		Transform* tr = GetOwner()->GetComponent<Transform>();
		translate(tr);

		
	}
	void WaddleDeeScript::playWalkAnimationBydirection(eDirection dir)
	{
		switch (dir)
		{
		case Q::WaddleDeeScript::eDirection::Left:
			mAnimator->PlayAnimation(L"LeftDee", true);
			break;
		case Q::WaddleDeeScript::eDirection::Right:
			mAnimator->PlayAnimation(L"RightDee", true);
			break;
		case Q::WaddleDeeScript::eDirection::End:
			break;
		default:
			assert(false);
			break;
		}
	}
	void WaddleDeeScript::translate(Transform* tr)
	{
		Vector2 pos = tr->GetPosition();

		switch (mDirection)
		{
		case Q::WaddleDeeScript::eDirection::Left:
			pos.x -= 50.0f * Time::DeltaTime();
			break;
		case Q::WaddleDeeScript::eDirection::Right:
			pos.x += 50.0f * Time::DeltaTime();
			break;
		case Q::WaddleDeeScript::eDirection::End:
			break;
		default:
			assert(false);
			break;
		}
		tr->SetPosition(pos);
	}
}