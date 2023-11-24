#pragma once

namespace Q::enums
{

	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		Script,
		Camera,
		End,
	};

	enum class eLayerType
	{
		None,
		BackGround,
		Player,
		Title,
		Max = 16,
	};


	enum class eResourceType
	{
		Texture,
		AudioClip,
		Prefab,
		End
	};
}