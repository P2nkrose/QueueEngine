#pragma once
#include "..\\QueueEngine_SOURCE\\qResources.h"
#include "..\\QueueEngine_SOURCE\\qTexture.h"

namespace Q
{
	void LoadResources()
	{

		Resources::Load<graphics::Texture>(L"Title", L"..\\Resources\\img\\Title\\Title.png");
		Resources::Load<graphics::Texture>(L"Under", L"..\\Resources\\img\\Title\\under.png");

		Resources::Load<graphics::Texture>(L"BackGround", L"..\\Resources\\img\\BackGround\\BackGroundTest.bmp");
		Resources::Load<graphics::Texture>(L"Stage", L"..\\Resources\\img\\Stage\\StageTest.bmp");

		Resources::Load<graphics::Texture>(L"Bubble", L"..\\Resources\\Bubble.png");
		Resources::Load<graphics::Texture>(L"Effect", L"..\\Resources\\Effect.png");
		Resources::Load<graphics::Texture>(L"Cat", L"..\\Resources\\Cat.bmp");

		//Resources::Load<graphics::Texture>(L"KirbyDance", L"..\\Resources\\KirbyDacne.png");



		// ¿ÃπÃ¡ˆ

		// BackGround
		Resources::Load<graphics::Texture>(L"Under", L"..\\Resources\\img\\BackGround\\BackGround.bmp");
		Resources::Load<graphics::Texture>(L"Under", L"..\\Resources\\img\\BackGround\\BackGround1.bmp");
		Resources::Load<graphics::Texture>(L"Under", L"..\\Resources\\img\\BackGround\\bossBackGround.bmp");

		// Boss
		Resources::Load<graphics::Texture>(L"Under", L"..\\Resources\\img\\Boss\\Boss.bmp");

		// Enemy
		Resources::Load<graphics::Texture>(L"Under", L"..\\Resources\\img\\Enemy\\AllEnemy.bmp");
		Resources::Load<graphics::Texture>(L"Under", L"..\\Resources\\img\\Enemy\\AnimalEnemy.bmp");
		Resources::Load<graphics::Texture>(L"Under", L"..\\Resources\\img\\Enemy\\NormalEnemy1.bmp");
		Resources::Load<graphics::Texture>(L"Under", L"..\\Resources\\img\\Enemy\\NormalEnemy2.bmp");
		Resources::Load<graphics::Texture>(L"Under", L"..\\Resources\\img\\Enemy\\SwordKnight.bmp");

		// Etc
		Resources::Load<graphics::Texture>(L"Under", L"..\\Resources\\img\\Etc\\Effect1.bmp");
		Resources::Load<graphics::Texture>(L"Under", L"..\\Resources\\img\\Etc\\Effect2.bmp");
		Resources::Load<graphics::Texture>(L"Under", L"..\\Resources\\img\\Etc\\Font.bmp");
		Resources::Load<graphics::Texture>(L"Under", L"..\\Resources\\img\\Etc\\Icon.bmp");
		Resources::Load<graphics::Texture>(L"Under", L"..\\Resources\\img\\Etc\\Item.bmp");
		Resources::Load<graphics::Texture>(L"Under", L"..\\Resources\\img\\Etc\\LevelSelect.bmp");

		// Kirby
		Resources::Load<graphics::Texture>(L"AnimalKirby", L"..\\Resources\\img\\Kirby\\AnimalKirbyAlpha.bmp");
		Resources::Load<graphics::Texture>(L"Under", L"..\\Resources\\img\\Kirby\\CutterKirby.bmp");
		Resources::Load<graphics::Texture>(L"Under", L"..\\Resources\\img\\Kirby\\FireKirby.bmp");
		Resources::Load<graphics::Texture>(L"Under", L"..\\Resources\\img\\Kirby\\IceKirby.bmp");
		Resources::Load<graphics::Texture>(L"Under", L"..\\Resources\\img\\Kirby\\IceKirby2.bmp");
		Resources::Load<graphics::Texture>(L"StandKirby", L"..\\Resources\\img\\Kirby\\NormalKirby11.bmp");
		Resources::Load<graphics::Texture>(L"RightWalkKirby", L"..\\Resources\\img\\Kirby\\NormalKirby22.bmp");
		Resources::Load<graphics::Texture>(L"LeftWalkKirby", L"..\\Resources\\img\\Kirby\\NormalKirby33.bmp");
		Resources::Load<graphics::Texture>(L"Under", L"..\\Resources\\img\\Kirby\\SparkKirby.bmp");
		Resources::Load<graphics::Texture>(L"Under", L"..\\Resources\\img\\Kirby\\SwordKirby.bmp");

		// stage
		Resources::Load<graphics::Texture>(L"Under", L"..\\Resources\\img\\Stage\\Stage1.bmp");
		Resources::Load<graphics::Texture>(L"Under", L"..\\Resources\\img\\Stage\\Stage2.bmp");





	}
}

