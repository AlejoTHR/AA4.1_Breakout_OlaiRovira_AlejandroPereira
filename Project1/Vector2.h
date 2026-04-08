#pragma once

class Vector2 {
public:
	int x;
	int y;

	Vector2()
		: x(0), y(0){}
	Vector2(int _x, int _y)
		: x(_x), y(_y) {}

	//Operators
	inline Vector2 operator+(const Vector2& other) {
		return Vector2(x + other.x, y + other.y);
	}

	inline Vector2 operator*=(const int& other) {
		return Vector2(x * other, y * other);
	}

	inline bool operator==(const Vector2& other) {
		return x == other.x && y == other.y;
	}

	inline void operator!() {
		x = -x;
		y = -y;
	}
};