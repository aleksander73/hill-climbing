#include "HillClimber.h"

HillClimber::HillClimber(float minX, float maxX, float minY, float maxY, float step, int neighbours) {
	this->minX = minX;
	this->maxX = maxX;
	this->minY = minY;
	this->maxY = maxY;
	this->step = step;
	this->neighbours = neighbours;
}

Vector2d HillClimber::findMaximum(float (*f)(Vector2d&)) {
	return Vector2d(0.0f, 0.0f);
}
