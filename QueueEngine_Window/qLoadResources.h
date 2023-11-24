#pragma once
#include "..\\QueueEngine_SOURCE\\qResources.h"
#include "..\\QueueEngine_SOURCE\\qTexture.h"

namespace Q
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Map", L"..\\Resources\\map.png");
		Resources::Load<graphics::Texture>(L"Kirby", L"..\\Resources\\kirby.png");
	}
}

