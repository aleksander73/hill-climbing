#ifndef HILL_CLIMBER_H_
#define HILL_CLIMBER_H_

#include "Vector2d.h"

class HillClimber {
	private:
		float minX, maxX, minY, maxY, step;
		int iterations, neighbours;
		Vector2d origin();
		Vector2d sampleNeighbourhood(float (*f)(Vector2d), Vector2d origin);
		float random();
	public:
		HillClimber(float minX, float maxX, float minY, float maxY, int iterations, float step, int neighbours);
		Vector2d findMaximum(float (*f)(Vector2d));
};

#endif
