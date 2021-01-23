#include "Vector2d.h"

#include <math.h>

Vector2d::Vector2d(float x, float y) {
	this->x = x;
	this->y = y;
}

Vector2d Vector2d::operator+(Vector2d& v) {
	return Vector2d(this->x + v.x, this->y + v.y);
}

float Vector2d::getX() {
	return this->x;
}

float Vector2d::getY() {
	return this->y;
}
