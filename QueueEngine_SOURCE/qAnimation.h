#pragma once
#include "qResouce.h"
#include "qTexture.h"

namespace Q
{
	class Animation : public Resource
	{
	public:
		struct Sprite
		{
			Vector2 leftTop;
			Vector2 size;	// sprite 사이즈
			Vector2 offset;	// 캐릭터 중앙
			float duration;	// sprite 간격

			Sprite()
				: leftTop(Vector2::Zero)
				, size(Vector2::Zero)
				, offset(Vector2::Zero)
				, duration(0.0f)
			{

			}
		};

		Animation();
		~Animation();

		// 맵 툴 만들 여지를 남기기위해서 상속받음
		virtual HRESULT Load(const std::wstring& path) override;	

		void Update();
		void Render(HDC hdc);

		void CreateAnimation(const std::wstring& name
			, graphics::Texture* spriteSheet
			, Vector2 leftTop
			, Vector2 size
			, Vector2 offset
			, UINT spriteLength
			, float duration);

		void Reset();

		bool IsComplete() { return mbComplete; }
		void SetAnimator(class Animator* animator) { mAnimator = animator; }




	private:
		class Animator* mAnimator;
		graphics::Texture* mTexture;

		std::vector<Sprite> mAnimationSheet;
		UINT mIndex;
		float mTime;
		bool mbComplete;
	};


}
