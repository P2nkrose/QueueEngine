#pragma once
#include "qEntity.h"

namespace Q
{
	class Resource : public Entity	// ���������Լ��� �Ѱ��� ����ִ� Ŭ������ "�߻�Ŭ����". �޸��Ҵ� X ��ӹ޾Ƽ��� ����ؾ� ��.
	{
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0;	// ���������Լ�. ���� �޸𸮿� �Ҵ��� �Ұ������� �����̴�.

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};
}


