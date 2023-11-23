#pragma once

namespace Q::enums
{
	enum class eLayerType
	{
		None,
		BackGround,
		//Tree
		//character
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