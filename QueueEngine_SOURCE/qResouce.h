#pragma once
#include "qEntity.h"

namespace Q
{
	class Resource : public Entity	// 순수가상함수가 한개라도 들어있는 클래스를 "추상클래스". 메모리할당 X 상속받아서만 사용해야 함.
	{
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0;	// 순수가상함수. 실제 메모리에 할당이 불가해지는 문법이다.

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};
}


