#pragma once
#include "qResouce.h"

namespace Q
{
	class Resources
	{
	public:
		template <typename T>
		static T* Find(const std::wstring& key)
		{
			//std::map<std::wstring, Resource*>::iterator iter = mResources.find(key);
			auto iter = mResources.find(key);

			if (iter == mResources.end())
			{
				return nullptr;
			}

			return dynamic_cast<T*>(iter->second);
		}


		template <typename T>
		static T* Load(const std::wstring& key, const std::wstring& path)
		{
			T* resource = Resources::Find<T>(key);
			if (resource != nullptr)
			{
				return resource;
			}

			resource = new T();
			if (FAILED(resource->Load(path)))
			{
				assert(false);
				return nullptr;
			}

			resource->SetName(key);
			resource->SetPath(path);
			mResources.insert(std::make_pair(key, resource));


			return resource;
		}

		static void Insert(const std::wstring& key, Resource* resource)
		{
			if (key == L"")
			{
				return;
			}

			if (resource == nullptr)
			{
				return;
			}

			mResources.insert(std::make_pair(key, resource));
		}

	private:

		static std::map<std::wstring, Resource*> mResources;

	};

}



