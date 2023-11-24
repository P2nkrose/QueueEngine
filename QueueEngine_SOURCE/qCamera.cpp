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
			mLookPosition = tr->GetPosition();
		}

		Transform* cameraTr = GetOwner()->GetComponent<Transform>();
		mLookPosition = cameraTr->GetPosition();

		mDistance = mLookPosition - (mResolution / 2.0f);
	}

	void Camera::LateUpdate()
	{
	}

	void Camera::Render(HDC hdc)
	{
	}
}