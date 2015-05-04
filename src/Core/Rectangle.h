#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Vector.h"

class Rectangle 
{
private:
	//The rectangle's top left X/Y coords.
	float x;
	float y;

	//Rectangle's width and height.
	float width;
	float height;

public:
	//Our defaults.
	Rectangle();
	~Rectangle();

	//Our 'specials' constructors.
	Rectangle(float x, float y, float width, float height);
	Rectangle(const Vector2D* const topLeft, const Vector2D* const btmRight);

	//Wheter or not a point is contained within a rectangle, considers points ON the rectangle as part of the rectangle.
	bool Contains(const float x, const float y);
	bool Contains(const Vector2D* const point);

	//Getters
	float GetX() const { return x; }
	float GetY() const { return y; }
	float GetWidth() const { return width; }
	float GetHeight() const { return height; }

	//Setters
	void SetPosition(const Vector2D* const vect);
	void SetPosition(const float x, const float y);

	//Setters
	void SetSize(const Vector2D* const vect);
	void SetSize(const float w, const float h);

	//Move the rectangle's coordinates by specified x/y.
	void MoveBy(const Vector2D*  const vect);
	void MoveBy(const float x, const float y);

	//Determines if a rectangle collides with another rectangle.
	bool CollidesWith(const Rectangle* const rect) const;
};

#endif