#ifndef VECTOR2D_H_
#define VECTOR2D_H_

#include <iostream>

class Vector2d {
	private:
		float x, y;
	public:
		Vector2d();
		Vector2d(float x, float y);
		Vector2d operator+(Vector2d v);
		bool operator==(Vector2d v);
		Vector2d rotate(float angle);
		float getX();
		void setX(float x);
		float getY();
		void setY(float y);
		friend std::ostream& operator<<(std::ostream& os, Vector2d& v);
};

#endif
