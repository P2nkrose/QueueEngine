#include "qBoxCollider2D.h"
#include "qTransform.h"
#include "qGameObject.h"

namespace Q
{
	BoxCollider2D::BoxCollider2D()
		: Collider()
	{
	}
	BoxCollider2D::~BoxCollider2D()
	{
	}
	void BoxCollider2D::Initialize()
	{
	}
	void BoxCollider2D::Update()
	{
	}
	void BoxCollider2D::LateUpdate()
	{
	}
	void BoxCollider2D::Render(HDC hdc)
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);

		Vector2 offset = GetOffset();
		Rectangle(hdc, pos.x + offset.x
			, pos.y + offset.y
			, pos.x + offset.x + 50		// 50 * 50 = 충돌체 크기
			, pos.y + offset.y + 50);

		SelectObject(hdc, oldBrush);
	}
}