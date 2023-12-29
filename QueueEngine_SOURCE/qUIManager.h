#pragma once
#include "CommonInclude.h"
#include "qUIBase.h"

namespace Q
{
	using namespace enums;
	class UIManager
	{
	public:
		static void Initialize();
		static void OnLoad(eUIType type);
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
		static void OnComplete(UIBase* addUI);
		static void OnFail();
		static void Release();

		static void Push(enums::eUIType type);
		static void Pop(enums::eUIType type);

	private:
		static std::unordered_map<eUIType, UIBase*> mUIs;
		static std::stack<UIBase*> mUIBases;
		static std::queue<eUIType> mRequestUiQueue;	// 메세지큐 : 메세지에 하나씩 넣어놓고 처리
		static UIBase* mActiveUI;
	};
}


