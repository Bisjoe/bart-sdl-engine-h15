#ifndef LINE_SEGMENT_HPP
#define LINE_SEGMENT_HPP

#include "Vector.h"

//For consistency sake I included linesegment in the TP namespace, it only makes sense.
//We can agree to disagree if you agree, but I'd disagree.

	//It pretty much is just a line
	class LineSegment
	{
	private:
		// That's the X/Y origin of the line
		Vector2D from;

		// And this is where the line end in X/Y coords
		Vector2D to;

		//In short, this is the "opposite" line. Quite as simple as x = -y, y = -x. There's logic behind it
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

		//ZE BONUS, if two lines collide, we'll want to know.
		bool IntersectsWith(const LineSegment * seg);
	};


#endif