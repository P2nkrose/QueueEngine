#pragma once
#include <iostream>
#include "CommonInclude.h"

using namespace Q::math;

namespace Q
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void SetName(const std::wstring& name) { mName = name; }
		std::wstring& Getname() { return mName; }

	private:
		std::wstring mName;
	};
}


