#include "HillClimber.h"

#include <random>

HillClimber::HillClimber(float minX, float maxX, float minY, float maxY, float step, int neighbours) {
	this->minX = minX;
	this->maxX = maxX;
	this->minY = minY;
	this->maxY = maxY;
	this->step = step;
	this->neighbours = neighbours;
}

Vector2d HillClimber::origin() {
	float randX = this->random() * (maxX - minX) + minX;
	float randY = this->random() * (maxY - minY) + minY;
	return Vector2d(randX, randY);
}

float HillClimber::random() {
	static std::default_random_engine e;
	static std::uniform_real_distribution<> dis(0, 1);
	return  dis(e);
}

Vector2d HillClimber::findMaximum(float (*f)(Vector2d&)) {
	return Vector2d(0.0f, 0.0f);
}
