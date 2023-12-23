#include "qDaggerObjectScript.h"
#include "qInput.h"
#include "qTransform.h"
#include "qTime.h"
#include "qGameObject.h"
#include "qAnimator.h"
#include "qDaggerObject.h"
#include "qObject.h"
#include "qResources.h"
#include "qRenderer.h"
#include "qNinjaKirbyScript.h"


namespace Q
{
	DaggerObjectScript::DaggerObjectScript()
		: mState(DaggerObjectScript::eState::False)
		
	{
	}

	DaggerObjectScript::~DaggerObjectScript()
	{
	}

	void DaggerObjectScript::Initialize()
	{
		//Script::Initialize();
	}

	void DaggerObjectScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
	
		//mDirection = NinjaKirbyScript::GetDirection();

		if (mDirection == DaggerObjectScript::eDirection::Right)
		{
			pos.x += 300.0f * Time::DeltaTime();
		}
		else if (mDirection == DaggerObjectScript::eDirection::Left)
		{
			pos.x -= 300.0f * Time::DeltaTime();
		}
		
		tr->SetPosition(pos);

	}

	void DaggerObjectScript::LateUpdate()
	{
		//Script::LateUpdate();
	}

	void DaggerObjectScript::Render(HDC hdc)
	{
		//Script::Render(hdc);
	}

	void DaggerObjectScript::DaggerOject()
	{
		
		mState = DaggerObjectScript::eState::DaggerObject;
		if (mDirection == DaggerObjectScript::eDirection::Right)
		{
			mEffectAnimator->PlayAnimation(L"RightDaggerEffect", true);
		}
		else if (mDirection == DaggerObjectScript::eDirection::Left)
		{
			mEffectAnimator->PlayAnimation(L"LeftDaggerEffect", true);
		}
	}

	void DaggerObjectScript::False()
	{
		//mState = DaggerObjectScript::eState::False;
		//Transform* tr = GetOwner()->GetComponent<Transform>();
		//Vector2 pos = tr->GetPosition();

		//if (pos.x > 100.0f)
		//{
		//	object::Destroy(GetOwner());
		//}
	}
}