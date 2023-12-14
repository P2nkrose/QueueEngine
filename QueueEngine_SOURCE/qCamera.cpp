#include "qCamera.h"
#include "qGameObject.h"
#include "qTransform.h"
#include "qApplication.h"

extern Q::Application application;

namespace Q
{
	Camera::Camera()
		: Component(enums::eComponentType::Camera)
		, mDistance(Vector2::Zero)
		, mResolution(Vector2::Zero)
		, mLookPosition(Vector2::Zero)
		, mTarget(nullptr)
	{
	}
	Camera::~Camera()
	{
	}
	void Camera::Initialize()
	{
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();
	}

	void Camera::Update()
	{
		if (mTarget)
		{
			Transform* tr = mTarget->GetComponent<Transform>();
			mLookPosition = tr->GetPosition() - Vector2(-100.0f, 60.0f);

		}
		else
		{
			Transform* cameraTr = GetOwner()->GetComponent<Transform>();
			mLookPosition = cameraTr->GetPosition();
			// 화면 흰색 안나오기 : if문으로 막기
		}

		

		mDistance = mLookPosition - (mResolution / 2.0f);
	}

	void Camera::LateUpdate()
	{
	}

	void Camera::Render(HDC hdc)
	{
	}
}