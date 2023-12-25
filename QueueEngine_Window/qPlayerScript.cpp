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
#include "qDashObject.h"
#include "qDashObjectScript.h"
#include "qKirbyTypeManager.h"
#include "qCamera.h"
#include "qRenderer.h"
#include "qIceKirby.h"
#include "qIceKirbyScript.h"
#include "qBoxCollider2D.h"
#include "qRigidbody.h"


namespace Q
{
	extern Camera* mainCamera;

	PlayerScript::PlayerScript()
		: mState(PlayerScript::eState::Stand)
		, mDirection(PlayerScript::eDirection::Right)
		, mOneTime(false)
		, mDeathTime(0.0f)
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
		case Q::PlayerScript::eState::Tackle2:
			Tackle2();
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


	// ���ĵ�
	void PlayerScript::Stand()
	{

		
		
		// ���콺
		if (Input::GetKey(eKeyCode::LButton))
		{
			Vector2 mousePos = Input::GetMousePosition();
		}

		// Ű����
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
			mOneTime = false;
			if (mDirection == PlayerScript::eDirection::Right)
			{
				mAnimator->PlayAnimation(L"RightWindKirby", false);

			}
			else if (mDirection == PlayerScript::eDirection::Left)
			{
				mAnimator->PlayAnimation(L"LeftWindKirby", false);
				
			}
		}

		// Ŀ�� �ٲٱ�

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

		if (Input::GetKeyDown(eKeyCode::Num5))
		{
			KirbyTypeManager::ChangeKirby(L"Ninja");
			//renderer::mainCamera->SetTarget(GetOwner());
		}



		
	}

	// �ٿ�
	void PlayerScript::Down()
	{
		if (Input::GetKeyDown(eKeyCode::Right))
		{
			mDirection == PlayerScript::eDirection::Right;
			mAnimator->PlayAnimation(L"RightDownKirby", true);
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

	// ��ũ
	void PlayerScript::Walk()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Rigidbody* rb = GetOwner()->GetComponent<Rigidbody>();

		if (Input::GetKey(eKeyCode::Right))
		{
			//pos.x += 100.0f * Time::DeltaTime();
			// 2���ִٰ� ���ĵ��
			rb->AddForce(Vector2(200.0f, 0.0f));
		}
		else if (Input::GetKey(eKeyCode::Left))
		{
			//pos.x -= 100.0f * Time::DeltaTime();
			rb->AddForce(Vector2(-200.0f, 0.0f));
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

	// ����
	void PlayerScript::Wind()
	{
		if (Input::GetKeyUp(eKeyCode::Z))
		{
			//object::Destroy(GetOwner());
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

	// ����2
	void PlayerScript::Wind2()
	{

		// ����Ʈ
		WindObject* rightWindObject = object::Instantiate<WindObject>(enums::eLayerType::Effect);
		WindObject* leftWindObject = object::Instantiate<WindObject>(enums::eLayerType::Effect);
		WindObjectScript* rightWindSrc = rightWindObject->AddComponent<WindObjectScript>();
		WindObjectScript* leftWindSrc = leftWindObject->AddComponent<WindObjectScript>();

		rightWindSrc->SetEffect(GetOwner());
		leftWindSrc->SetEffect(GetOwner());

		graphics::Texture* rightWindEffectTex = Resources::Find<graphics::Texture>(L"RightWindEffect");
		graphics::Texture* leftWindEffectTex = Resources::Find<graphics::Texture>(L"LeftWindEffect");

		Animator* rightWindEffectAnimator = rightWindObject->AddComponent<Animator>();
		Animator* leftWindEffectAnimator = leftWindObject->AddComponent<Animator>();

		rightWindEffectAnimator->CreateAnimation(L"RightWindEffect", rightWindEffectTex,
			Vector2(0.0f, 0.0f), Vector2(50.0f, 30.0f), Vector2::Zero, 2, 0.1f);

		leftWindEffectAnimator->CreateAnimation(L"LeftWindEffect", leftWindEffectTex,
			Vector2(0.0f, 0.0f), Vector2(50.0f, 30.0f), Vector2::Zero, 2, 0.1f);

		Transform* tr = GetOwner()->GetComponent<Transform>();

		rightWindObject->GetComponent<Transform>()->SetPosition(tr->GetPosition() + Vector2(70.0f, 0.0f));
		leftWindObject->GetComponent<Transform>()->SetPosition(tr->GetPosition() + Vector2(-80.0f, 0.0f));
		
		rightWindObject->GetComponent<Transform>()->SetScale(Vector2::Two);
		leftWindObject->GetComponent<Transform>()->SetScale(Vector2::Two);


		if (Input::GetKey(eKeyCode::Z))
		{
			mState = PlayerScript::eState::Wind2;

			BoxCollider2D* WindRightCollider = rightWindObject->AddComponent<BoxCollider2D>();
			BoxCollider2D* WindLeftCollider = leftWindObject->AddComponent<BoxCollider2D>();

			if (mDirection == PlayerScript::eDirection::Right && mOneTime == false)
			{
				mDirection = PlayerScript::eDirection::Right;
				// �ѹ��� ����ǰ� ������ �ɾ�� ��(if���̳� bool)
				mAnimator->PlayAnimation(L"RightWindKirby2", true);
				rightWindEffectAnimator->PlayAnimation(L"RightWindEffect", true);

				// ������ �ݶ��̴�
				WindRightCollider->SetOffset(Vector2(-10.0f, -5.0f));
				WindRightCollider->SetSize(Vector2(80.0f, 40.0f));
				
			}
			else if (mDirection == PlayerScript::eDirection::Left && mOneTime == false)
			{
				mDirection = PlayerScript::eDirection::Left;
				mAnimator->PlayAnimation(L"LeftWindKirby2", true);
				leftWindEffectAnimator->PlayAnimation(L"LeftWindEffect", true);

				// ���� �ݶ��̴�

				WindLeftCollider->SetOffset(Vector2(-20.0f, -5.0f));
				WindLeftCollider->SetSize(Vector2(90.0f, 40.0f));

			}
			mOneTime = true;
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

	// ��Ŭ
	void PlayerScript::Tackle()
	{
		// ��Ŭ ����Ʈ

		//DashObject* rightDashObject = object::Instantiate<DashObject>(enums::eLayerType::Effect);
		//DashObject* leftDashObject = object::Instantiate<DashObject>(enums::eLayerType::Effect);
		//DashObjectScript* rightDashSrc = rightDashObject->AddComponent<DashObjectScript>();
		//DashObjectScript* leftDashSrc = leftDashObject->AddComponent<DashObjectScript>();

		//rightDashSrc->SetEffect(GetOwner());
		//leftDashSrc->SetEffect(GetOwner());

		//graphics::Texture* rightDashEffectTex = Resources::Find<graphics::Texture>(L"RightDashEffect");
		//graphics::Texture* leftDashEffectTex = Resources::Find<graphics::Texture>(L"LeftDashEffect");

		//Animator* rightDashEffectAnimator = rightDashObject->AddComponent<Animator>();
		//Animator* leftDashEffectAnimator = leftDashObject->AddComponent<Animator>();

		//rightDashEffectAnimator->CreateAnimation(L"RightDashEffect", rightDashEffectTex,
		//	Vector2(0.0f, 0.0f), Vector2(25.0f, 25.0f), Vector2::Zero, 6, 0.1f);

		//leftDashEffectAnimator->CreateAnimation(L"LeftDashEffect", leftDashEffectTex,
		//	Vector2(0.0f, 0.0f), Vector2(25.0f, 25.0f), Vector2::Zero, 6, 0.1f);

		//Transform* tr2 = GetOwner()->GetComponent<Transform>();

		//rightDashObject->GetComponent<Transform>()->SetPosition(tr2->GetPosition() + Vector2(-40.0f, 0.0f));
		//leftDashObject->GetComponent<Transform>()->SetPosition(tr2->GetPosition() + Vector2(40.0f, 0.0f));

		//rightDashObject->GetComponent<Transform>()->SetScale(Vector2(1.5f, 1.5f));
		//leftDashObject->GetComponent<Transform>()->SetScale(Vector2(1.5f, 1.5f));


		// �÷��ִ̾ϸ��̼� ��Ա�

		//rightDashEffectAnimator->PlayAnimation(L"RightDashEffect", false);

		//leftDashEffectAnimator->PlayAnimation(L"LeftDashEffect", false);


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
			case Q::PlayerScript::eDirection::Right:
				pos.x += 700.0f * Time::DeltaTime();
				break;
			case Q::PlayerScript::eDirection::Left:
				pos.x -= 700.0f * Time::DeltaTime();
				break;
			case Q::PlayerScript::eDirection::Down:
				break;
			default:
				break;
			}
		}

		tr->SetPosition(pos);


		if (Input::GetKeyUp(eKeyCode::X))
		{
			

		}

	}

	// ��Ŭ2 (�Ͼ�¸��)
	void PlayerScript::Tackle2()
	{
		if (mDirection == PlayerScript::eDirection::Right)
		{
			mAnimator->PlayAnimation(L"RightTackleKirby2", false);

		}
		else if (mDirection == PlayerScript::eDirection::Left)
		{
			mAnimator->PlayAnimation(L"LeftTackleKirby2", false);

		}


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


	void PlayerScript::OnCollisionEnter(Collider* other)
	{
		// �浹�ϸ� �ڷ� ������ �̺�Ʈ
		int a = 0;
	}

	void PlayerScript::OnCollisionStay(Collider* other)
	{
		// �浹 ���� ����
		int a = 0;
	}

	void PlayerScript::OnCollisionExit(Collider* other)
	{
		// �浹�� �������� ����
		int a = 0;
	}




	
	






}


