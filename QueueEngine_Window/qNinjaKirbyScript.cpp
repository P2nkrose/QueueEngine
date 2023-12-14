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
		case Q::NinjaKirbyScript::eState::Effect:
			Effect();
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


	void NinjaKirbyScript::Stand()
	{

	}

	void NinjaKirbyScript::Walk()
	{
	}

	void NinjaKirbyScript::Down()
	{
	}

	void NinjaKirbyScript::Effect()
	{
	}

	void NinjaKirbyScript::Tackle()
	{
	}

	void NinjaKirbyScript::Tackle2()
	{
	}
}