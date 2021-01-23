#include <iostream>

#include "Vector2d.h"
#include "HillClimber.h"

float f(Vector2d v) {
	return -(v.getX() * v.getX() + v.getY() * v.getY());
}

int main(int argc, char* argv[]) {
	HillClimber hillClimber = HillClimber(-100.0f, 100.0f, -100.0f, 100.0f, 100, 0.01, 100);
	Vector2d maximum = hillClimber.findMaximum(&f);
	std::cout << "Maximum: " << maximum << " = " << f(maximum) << std::endl;
	return 0;
}
