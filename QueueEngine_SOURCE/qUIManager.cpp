#include "qUIManager.h"
#include "qUIHUD.h"

namespace Q
{
	std::unordered_map<eUIType, UIBase*> UIManager::mUIs = {};
	std::stack<UIBase*> UIManager::mUIBases = {};
	std::queue<eUIType> UIManager::mRequestUiQueue = {};	
	UIBase* UIManager::mActiveUI = nullptr;



	void UIManager::Initialize()
	{
		// UI 객체 생성해주기
		UIHUD* hud = new UIHUD();
		mUIs.insert(std::make_pair(eUIType::HpBar, hud));

	}
	void UIManager::OnLoad(eUIType type)
	{
		std::unordered_map<eUIType, UIBase*>::iterator iter = mUIs.find(type);

		if (iter == mUIs.end())
		{
			OnFail();
			return;
		}

		OnComplete(iter->second);
	}

	void UIManager::Update()
	{
		std::stack<UIBase*> uiBases = mUIBases;
		while (!uiBases.empty())
		{
			UIBase* uiBase = uiBases.top();
			if (uiBase)
			{
				uiBase->Update();
				uiBases.pop();
			}
		}

		if (mRequestUiQueue.size() > 0)
		{
			eUIType requestUI = mRequestUiQueue.front();
			mRequestUiQueue.pop();
			OnLoad(requestUI);
		}
	}

	void UIManager::LateUpdate()
	{
		std::stack<UIBase*> uiBases = mUIBases;
		while (!uiBases.empty())
		{
			UIBase* uiBase = uiBases.top();
			if (uiBase)
			{
				uiBase->LateUpdate();
				uiBases.pop();
			}
		}
	}

	void UIManager::Render(HDC hdc)
	{
		std::stack<UIBase*> uiBases = mUIBases;
		while (!uiBases.empty())
		{
			UIBase* uiBase = uiBases.top();
			if (uiBase)
			{
				uiBase->Render(hdc);
				uiBases.pop();
			}
		}
	}

	void UIManager::OnComplete(UIBase* addUI)
	{
		if (addUI == nullptr)
		{
			return;
		}

		addUI->Initialize();
		addUI->Active();
		addUI->Update();


		// 만약에 현재 추가된 UI가 전체 화면이라면
		// 전체 화면인 UI 말고 나머지를 전부 비활성화
		if (addUI->IsFullScreen())
		{
			std::stack<UIBase*> uiBases = mUIBases;
			while (!uiBases.empty())
			{
				UIBase* uiBase = uiBases.top();
				uiBases.pop();
				if (uiBase)
				{
					uiBase->InActive();
					
				}
			}
		}

		mUIBases.push(addUI);
		mActiveUI = nullptr;

	}

	void UIManager::OnFail()
	{
		mActiveUI = nullptr;
	}

	void UIManager::Release()
	{
		for (auto iter : mUIs)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}

	void UIManager::Push(enums::eUIType type)
	{
		mRequestUiQueue.push(type);
	}

	void UIManager::Pop(enums::eUIType type)
	{
		if (mUIBases.size() <= 0)
		{
			return;
		}

		// 해당 UI 한개만 스택에서 빼줘야 한다.
		UIBase* uibase = nullptr;

		while (mUIBases.size() > 0)
		{
			uibase = mUIBases.top();
			mUIBases.pop();


		}
	}
}