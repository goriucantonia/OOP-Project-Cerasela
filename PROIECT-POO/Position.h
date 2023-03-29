#pragma once

#include "Game.h"

class Position {
private:
	float x, y;
public:
	float getX() { return x; }
	float getY() { return y; }
	void setX(float a) { x = a; }
	void setY(float a) { y = a; }

	~Position() {};
	Position(float xpos = 0, float ypos = 0 ): x(xpos), y(ypos) {}

	void TranslateX(float a) { x += a; }
	void TranslateY(float b) { y += b; }
	void TranslateX(Position c) { x += c.getX(); y += c.getY(); }

	Position operator+(const Position& z) {
		return Position(x + z.x, y + z.y);
	} 
	friend Position operator+=(Position &q, const Position& z) {
		q.x += z.x;
		q.y += z.y;
		return q;
	}
	Position operator-(const Position& z) {
		return Position(x - z.x, y - z.y);
	}
	friend Position operator-=(Position& q, const Position& z) {
		q.x -= z.x;
		q.y -= z.y;
		return q;
	}
	Position operator*(float scalar) {
		return Position(x * scalar, y * scalar);
	}
	void afisarePunct() {
		cout << "(" << x << "," << y << ")" << endl;
	}

};