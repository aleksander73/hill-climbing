#ifndef VECTOR2D_H_
#define VECTOR2D_H_

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
		float getY();
};

#endif
