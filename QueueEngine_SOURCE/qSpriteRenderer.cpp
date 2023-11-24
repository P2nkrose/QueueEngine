#include "qSpriteRenderer.h"
#include "qGameObject.h"
#include "qTransform.h"
#include "qTexture.h"
#include "qRenderer.h"

namespace Q
{
	SpriteRenderer::SpriteRenderer()
		: Component(enums::eComponentType::SpriteRenderer)
		, mTexture(nullptr)
		, mSize(Vector2::One)
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
	void SpriteRenderer::Initialize()
	{
	}
	void SpriteRenderer::Update()
	{
	}
	void SpriteRenderer::LateUpdate()
	{
	}

	void SpriteRenderer::Render(HDC hdc)
	{

		if (mTexture == nullptr)	// 텍스처 세팅 해주세요!
		{
			assert(false);
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		pos = renderer::mainCamera->CalculatePosition(pos);

		if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Bmp)
		{
			//https://blog.naver.com/power2845/50147965306
			TransparentBlt(hdc, pos.x, pos.y,
				mTexture->GetWidth(), mTexture->GetHeight(),
				mTexture->GetHdc(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight(),
				RGB(255, 0, 255));
		}

		else if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Png)
		{
			Gdiplus::Graphics graphics(hdc);
			graphics.DrawImage(mTexture->GetImage(), 
				Gdiplus::Rect(pos.x, pos.y, 
					mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y));
		}

	}

	
}