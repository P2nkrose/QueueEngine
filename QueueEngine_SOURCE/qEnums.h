#pragma once

namespace Q::enums
{

	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		Animator,
		Script,
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