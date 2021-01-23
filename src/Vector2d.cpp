#include "Vector2d.h"

#include <math.h>
#include <cmath>

Vector2d::Vector2d(float x, float y) {
	this->x = x;
	this->y = y;
}

Vector2d Vector2d::operator+(Vector2d& v) {
	return Vector2d(this->x + v.x, this->y + v.y);
}

Vector2d Vector2d::rotate(float angle) {
	float angle_ = fmod(angle, 360.0f);
	float rad = angle_ * M_PI / 180.0f;
	float sin = std::sin(rad);
	float cos = std::cos(rad);
	return Vector2d(this->x * cos - this->y * sin, this->x * sin + this->y * cos);
}

float Vector2d::getX() {
	return this->x;
}

float Vector2d::getY() {
	return this->y;
}
