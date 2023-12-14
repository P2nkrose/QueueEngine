#include "qInput.h"
#include "qApplication.h"

extern Q::Application application;

namespace Q
{
	std::vector<Input::Key> Input::Keys = {};
	math::Vector2 Input::mMousePosition = math::Vector2::One;

	int ASCII[(UINT)eKeyCode::End] =
	{
		VK_NUMPAD0, VK_NUMPAD1, VK_NUMPAD2, VK_NUMPAD3,
		VK_NUMPAD4, VK_NUMPAD5, VK_NUMPAD6, VK_NUMPAD7,
		VK_NUMPAD8, VK_NUMPAD9,
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M', VK_SPACE,
		VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN,
		VK_LBUTTON, VK_MBUTTON, VK_RBUTTON,
	};

	void Input::Initialize()
	{
		createKeys();
	}

	void Input::createKeys()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			Keys.push_back(key);
		}
	}

	void Input::Update()
	{
		if (GetFocus())
		{
			for (size_t i = 0; i < Keys.size(); i++)
			{
				// 키가 눌렸다.
				if (GetAsyncKeyState(ASCII[i]) & 0x8000)
				{
					if (Keys[i].bPressed == true)
					{
						Keys[i].state = eKeyState::Pressed;
					}
					else
					{
						Keys[i].state = eKeyState::Down;
					}

					Keys[i].bPressed = true;
				}
				// 키가 안눌렸다.
				else
				{
					if (Keys[i].bPressed == true)
					{
						Keys[i].state = eKeyState::Up;
					}
					else
					{
						Keys[i].state = eKeyState::None;
					}

					Keys[i].bPressed = false;
				}
			}

			getMousePositionByWindow();
		}
		else
		{
			clearKeys();
		}
	}

	void Input::clearKeys()
	{
		for (Key& key : Keys)
		{
			if (key.state == eKeyState::Down || key.state == eKeyState::Pressed)
			{
				key.state = eKeyState::Up;
			}
			else if (key.state == eKeyState::Up)
			{
				key.state = eKeyState::None;
			}

			key.bPressed = false;
		}
	}

	void Input::getMousePositionByWindow()
	{
		POINT mousePos = {};
		GetCursorPos(&mousePos);
		ScreenToClient(application.GetHwnd(), &mousePos);

		mMousePosition.x = mousePos.x;
		mMousePosition.y = mousePos.y;
	}

}
