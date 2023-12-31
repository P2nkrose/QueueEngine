#pragma once
#include <cmath>


namespace Q::math
{

	struct Vector2
	{
		static Vector2 One;
		static Vector2 Two;
		static Vector2 Zero;
		static Vector2 Half;

		float x;
		float y;

		Vector2()
			 :x(0.0f)
			, y(0.0f)
		{

		}

		Vector2(float _x, float _y)
			: x(_x),
			  y(_y)
		{

		}

		Vector2 operator-()
		{
			return Vector2(-x, -y);
		}

		Vector2 operator+(Vector2 other)
		{
			return Vector2(x + other.x, y + other.y);
		}

		void operator+=(Vector2 other)
		{
			x += other.x;
			y += other.y;
		}

		Vector2 operator-(Vector2 other)
		{
			return Vector2(x - other.x, y - other.y);
		}

		Vector2 operator/(float value)
		{
			return Vector2(x / value, y / value);
		}

		Vector2 operator*(float value)
		{
			return Vector2(x * value, y * value);
		}

		Vector2 operator*(Vector2 v)
		{
			return Vector2(x * v.x, y * v.y);
		}

		bool operator==(Vector2 v)
		{
			return (x == v.x) && (y == v.y);
		}




		void clear()
		{
			x = 0.0f;
			y = 0.0f;
		}

		float length()
		{
			return sqrtf(x * x + y * y);
		}

		Vector2 normalize()
		{
			float len = length();
			x /= len;
			y /= len;

			return *this;
		}

	};



}


