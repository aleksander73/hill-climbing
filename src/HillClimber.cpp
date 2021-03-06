#include "HillClimber.h"

#include <random>

HillClimber::HillClimber(float minX, float maxX, float minY, float maxY, int iterations, float step, int neighbours) {
	this->minX = minX;
	this->maxX = maxX;
	this->minY = minY;
	this->maxY = maxY;
	this->iterations = iterations;
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
		this->crop(v);
		if(f(v) > f(best)) {
			best = v;
		}
	}
	return best;
}

Vector2d HillClimber::crop(Vector2d v) {
	if(v.getX() < minX) {
		v.setX(minX);
	} else if(v.getX() > maxX) {
		v.setX(maxX);
	}
	if(v.getY() < minY) {
		v.setY(minY);
	} else if(v.getY() > maxY) {
		v.setY(maxY);
	}
}

float HillClimber::random() {
	static std::default_random_engine e;
	static std::uniform_real_distribution<> dis(0, 1);
	return  dis(e);
}

Vector2d HillClimber::findMaximum(float (*f)(Vector2d)) {
	Vector2d globalBest = Vector2d();
	for(int i = 0; i < this->iterations; i++) {
		Vector2d v = this->origin();
		if(i == 0) {
			globalBest = v;
		}
		bool keepSearching = true;
		while(keepSearching) {
			Vector2d sampled = this->sampleNeighbourhood(f, v);
			if(sampled == v) {
				keepSearching = false;
			} else {
				v = sampled;
			}
		}
		if(f(v) > f(globalBest)) {
			globalBest = v;
		}
	}
	return globalBest;
}
