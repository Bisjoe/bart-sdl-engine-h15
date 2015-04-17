#ifndef LINE_SEGMENT_HPP
#define LINE_SEGMENT_HPP

#include "Vector.h"

class LineSegment
{

private:
	// The X/Y origin of the line
	Vector2D from;

	// The line's end point in X/Y coords
	Vector2D to;

	//In short, this is the "opposite" line. Quite as simple as x = -y, y = -x.
	Vector2D normal;

public:
	//Our default constructor/deconstructor
	LineSegment();
	~LineSegment();

	//Our special constructors, they're straightforward, two coords, to form a vector
	LineSegment(float fromX, float fromY, float toX, float toY);
	LineSegment(const Vector2D * const from, const Vector2D * const to);

	//Getters
	Vector2D GetFromPoint() const { return from; };
	Vector2D GetToPoint() const { return to; };
	Vector2D GetNormal() const { return normal; };

	//Returns whether or not two lines collide
	bool IntersectsWith(const LineSegment * seg);
};


#endif