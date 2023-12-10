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

		Resources::Load<graphics::Texture>(L"LeftDee", L"..\\Resources\\img\\Enemy\\LeftDee1.bmp");
		Resources::Load<graphics::Texture>(L"RightDee", L"..\\Resources\\img\\Enemy\\RightDee1.bmp");

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
		Resources::Load<graphics::Texture>(L"RightStandKirby", L"..\\Resources\\img\\Kirby\\Normal\\RightStandKirby.bmp");
		Resources::Load<graphics::Texture>(L"LeftStandKirby", L"..\\Resources\\img\\Kirby\\Normal\\LeftStandKirby.bmp");
		Resources::Load<graphics::Texture>(L"RightDownKirby", L"..\\Resources\\img\\Kirby\\Normal\\RightDownKirby.bmp");
		Resources::Load<graphics::Texture>(L"LeftDownKirby", L"..\\Resources\\img\\Kirby\\Normal\\LeftDownKirby.bmp");
		Resources::Load<graphics::Texture>(L"RightWalkKirby", L"..\\Resources\\img\\Kirby\\Normal\\RightWalkKirby.bmp");
		Resources::Load<graphics::Texture>(L"LeftWalkKirby", L"..\\Resources\\img\\Kirby\\Normal\\LeftWalkKirby.bmp");
		Resources::Load<graphics::Texture>(L"LeftWindKirby", L"..\\Resources\\img\\Kirby\\Normal\\LeftWindKirby.bmp");
		Resources::Load<graphics::Texture>(L"RightWindKirby", L"..\\Resources\\img\\Kirby\\Normal\\RightWindKirby.bmp");
		Resources::Load<graphics::Texture>(L"RightWindKirby2", L"..\\Resources\\img\\Kirby\\Normal\\RightWindKirby2.bmp");
		Resources::Load<graphics::Texture>(L"LeftWindKirby2", L"..\\Resources\\img\\Kirby\\Normal\\LeftWindKirby2.bmp");
		Resources::Load<graphics::Texture>(L"RightTackleKirby", L"..\\Resources\\img\\Kirby\\Normal\\RightTackleKirby.bmp");
		Resources::Load<graphics::Texture>(L"LeftTackleKirby", L"..\\Resources\\img\\Kirby\\Normal\\LeftTackleKirby.bmp");

		// Effect
		Resources::Load<graphics::Texture>(L"RightWindEffect", L"..\\Resources\\img\\Etc\\RightWindEffect.bmp");
		Resources::Load<graphics::Texture>(L"LeftWindEffect", L"..\\Resources\\img\\Etc\\LeftWindEffect.bmp");
		Resources::Load<graphics::Texture>(L"RightDashEffect", L"..\\Resources\\img\\Etc\\RightDashEffect.bmp");
		Resources::Load<graphics::Texture>(L"LeftDashEffect", L"..\\Resources\\img\\Etc\\LeftDashEffect.bmp");

		// IceKirby
		Resources::Load<graphics::Texture>(L"RightStandIceKirby", L"..\\Resources\\img\\Kirby\\Ice\\RightStandIceKirby.bmp");
		Resources::Load<graphics::Texture>(L"LeftStandIceKirby", L"..\\Resources\\img\\Kirby\\Ice\\LeftStandIceKirby.bmp");
		Resources::Load<graphics::Texture>(L"RightDownIceKirby", L"..\\Resources\\img\\Kirby\\Ice\\RightDownIceKirby.bmp");
		Resources::Load<graphics::Texture>(L"LeftDownIceKirby", L"..\\Resources\\img\\Kirby\\Ice\\LeftDownIceKirby.bmp");
		Resources::Load<graphics::Texture>(L"RightWalkIceKirby", L"..\\Resources\\img\\Kirby\\Ice\\RightWalkIceKirby.bmp");
		Resources::Load<graphics::Texture>(L"LeftWalkIceKirby", L"..\\Resources\\img\\Kirby\\Ice\\LeftWalkIceKirby.bmp");
		Resources::Load<graphics::Texture>(L"RightTackleIceKirby", L"..\\Resources\\img\\Kirby\\Ice\\RightTackleIceKirby.bmp");
		Resources::Load<graphics::Texture>(L"LeftTackleIceKirby", L"..\\Resources\\img\\Kirby\\Ice\\LeftTackleIceKirby.bmp");
		Resources::Load<graphics::Texture>(L"RightEffectIceKirby", L"..\\Resources\\img\\Kirby\\Ice\\RightEffectIceKirby.bmp");
		Resources::Load<graphics::Texture>(L"RightEffectIceKirby2", L"..\\Resources\\img\\Kirby\\Ice\\RightEffectIceKirby2.bmp");
		Resources::Load<graphics::Texture>(L"LeftEffectIceKirby", L"..\\Resources\\img\\Kirby\\Ice\\LeftEffectIceKirby.bmp");
		Resources::Load<graphics::Texture>(L"LeftEffectIceKirby2", L"..\\Resources\\img\\Kirby\\Ice\\LeftEffectIceKirby2.bmp");


		
		



		// stage
		Resources::Load<graphics::Texture>(L"Under", L"..\\Resources\\img\\Stage\\Stage1.bmp");
		Resources::Load<graphics::Texture>(L"Under", L"..\\Resources\\img\\Stage\\Stage2.bmp");





	}
}

