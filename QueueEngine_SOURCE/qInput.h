#pragma once
#include "CommonInclude.h"


namespace Q
{
	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None
	};

	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M, SPACE,
		Left, Right, Up, Down,
		LButton, MButton, RButton,
		End
	};

	class Input
	{
	public:
		struct Key
		{
			eKeyCode keyCode;
			eKeyState state;
			bool bPressed;
		};

		static void Initialize();
		static void Update();

		__forceinline static bool GetKeyDown(eKeyCode code) {return Keys[(UINT)code].state == eKeyState::Down;}
		__forceinline static bool GetKeyUp(eKeyCode code) {return Keys[(UINT)code].state == eKeyState::Up;}
		__forceinline static bool GetKey(eKeyCode code) {return Keys[(UINT)code].state == eKeyState::Pressed;}
		static math::Vector2 GetMousePosition() { return mMousePosition; }

	private:
		static void createKeys();
		static void getMousePositionByWindow();
		static void clearKeys();

	private:

		//eKeyState mState[] = eKeyState::Up;
		static std::vector<Key> Keys;
		static math::Vector2 mMousePosition;
	};
}


