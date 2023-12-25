#pragma once

namespace Q::enums
{
	enum class eComponentType
	{
		Transform,
		Collider,
		Rigidbody,
		Script,
		SpriteRenderer,
		Animator,
		Camera,
		End,
	};

	enum class eLayerType
	{
		None,
		BackGround,
		Stage,
		Monster,
		Kirby,
		Effect,
		Floor,
		Particle,
		Max = 16,
	};

	enum class eResourceType
	{
		Texture,
		AudioClip,
		Animation,
		Prefab,	// 게임오브젝트 저장할 데이터
		End
	};

	enum class eDirection
	{
		Right,
		Left,
	};

	enum class eColliderType
	{
		Circle2D,
		Rect2D,
		End,
	};


}