#pragma once

namespace Q::enums
{

	enum class eComponentType
	{
		Transform,
		Collider,
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
		Player,
		Effect,
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
}