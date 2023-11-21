#include "qInput.h"

namespace Q
{
	std::vector<Input::Key> Input::Keys = {};

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M', VK_SPACE,
		VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN,
	};

	void Input::Initialize()
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
	}

}
