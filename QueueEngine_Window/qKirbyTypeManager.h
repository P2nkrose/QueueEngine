#pragma once
#include "..\\QueueEngine_SOURCE\\qGameObject.h"

#include "qRenderer.h"


namespace Q
{
	class KirbyTypeManager
	{
	public:
 
		static void ChangeKirby(const std::wstring& type)
		{
			//나머지 전부다 꺼준다
			for (auto iter = mKirbyType.begin(); iter != mKirbyType.end(); iter++)
			{
				iter->second->SetActive(false);
			}
			
			auto iter = mKirbyType.find(type);
			iter->second->SetActive(true);

			renderer::mainCamera->SetTarget(iter->second);

		}

		static void Insert(const std::wstring& typeName, GameObject* type)
		{
			if (typeName == L"")
			{
				return;
			}

			if (type == nullptr)
			{
				return;
			}

			mKirbyType.insert(std::make_pair(typeName, type));
		}

	private:
		static std::map<std::wstring, GameObject*> mKirbyType;
	};

}


