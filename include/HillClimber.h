#ifndef HILL_CLIMBER_H_
#define HILL_CLIMBER_H_

#include "Vector2d.h"

class HillClimber {
	private:
		float minX, maxX, minY, maxY, step;
		int neighbours;
	public:
		HillClimber(float minX, float maxX, float minY, float maxY, float step, int neighbours);
		Vector2d findMaximum(float (*f)(Vector2d&));
};

#endif
