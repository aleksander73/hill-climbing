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

Vector2d HillClimber::sampleNeighbourhood(float (*f)(Vector2d), Vector2d origin) {
	Vector2d r = Vector2d(0.0f, this->step);
	Vector2d best = origin;
	for(int i = 0; i < this->neighbours; i++) {
		float angle = ((float)i / (float)neighbours) * 360.0f;
		Vector2d v = origin + r.rotate(angle);
		if(f(v) > f(best)) {
			best = v;
		}
	}
	return best;
}

float HillClimber::random() {
	static std::default_random_engine e;
	static std::uniform_real_distribution<> dis(0, 1);
	return  dis(e);
}

Vector2d HillClimber::findMaximum(float (*f)(Vector2d)) {
	return Vector2d(0.0f, 0.0f);
}
