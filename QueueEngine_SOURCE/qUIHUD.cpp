#include "qUIHUD.h"
#include "qResources.h"

namespace Q
{
	UIHUD::UIHUD()
		: UIBase(eUIType::HpBar)
	{
	}

	UIHUD::~UIHUD()
	{
	}

	void UIHUD::OnInit()
	{
		//mTexture = 


		mTexture = Resources::Find<graphics::Texture>(L"KirbyHud0");
		mTexture = Resources::Find<graphics::Texture>(L"KirbyHud1");
		mTexture = Resources::Find<graphics::Texture>(L"KirbyHud2");
		mTexture = Resources::Find<graphics::Texture>(L"KirbyHud3");
		mTexture = Resources::Find<graphics::Texture>(L"KirbyHud4");
		mTexture = Resources::Find<graphics::Texture>(L"KirbyHud5");
		mTexture = Resources::Find<graphics::Texture>(L"KirbyHud6");
		mTexture = Resources::Find<graphics::Texture>(L"KirbyHud7");
		mTexture = Resources::Find<graphics::Texture>(L"KirbyHud8");
	}

	void UIHUD::OnActive()
	{
	}

	void UIHUD::OnInActive()
	{
	}

	void UIHUD::OnUpdate()
	{
	}

	void UIHUD::OnLateUpdate()
	{
	}

	void UIHUD::OnRender(HDC hdc)
	{
		TransparentBlt(hdc
			, 0, 0
			, mTexture->GetWidth()
			, mTexture->GetHeight()
			, mTexture->GetHdc()
			, 0, 0
			, mTexture->GetWidth()
			, mTexture->GetHeight()
			, RGB(255, 0, 255));
	}

	void UIHUD::OnClear()
	{
	}
}