#include "LineSegment.h"

//Default constructor with default values
LineSegment::LineSegment()
:from({ 0, 0 }),
to({ 0, 0 })
{

}

//Default deconstructor
LineSegment::~LineSegment()
{

}

//Things have never been easier, we'll store FromX and FromY into the From vect2d and do the same with toX and toY
LineSegment::LineSegment(float fromX, float fromY, float toX, float toY)
:from({ fromX, fromY }),
to({ toX, toY })
{

}

//Correct me, things just got easier, from becomes from, to becomes to, aaah.
LineSegment::LineSegment(const Vector2D * const from, const Vector2D * const to)
: from(*from),
to(*to)
{

}

// BONUS
// I believe understanding the rectangle corner collision was much harder than this one.
// We're checking if two non-infinite lines collide with each other over here.
bool LineSegment::IntersectsWith(const LineSegment * seg)
{
	//It's much easier to deal with the lines across these formulas by making their own vector from inside
	Vector2D lineA1 = this->GetFromPoint();
	Vector2D lineA2 = this->GetToPoint();
	Vector2D lineB1 = seg->GetFromPoint();
	Vector2D lineB2 = seg->GetToPoint();
	float denominator;
	//Wheter or not they ever intersect
	bool areIntersect;

	//We gotta do a simple check to make sure we wouldn't fail to detect collisions if two lines were to be on top of each other
	if (Equals(&lineA1, &lineB1) || Equals(&lineA1, &lineB2) || Equals(&lineA2, &lineB1) || Equals(&lineA2, &lineB2))
	{
		areIntersect = true;
	}
	//Using an Else case instead of else-if because we'll avoid making unncessary calculations, mostly talking about denominator
	else
	{
		//The denominator of uA and uB(uX being any points on line X) in a Pa = Pb scenario (Px is any point uX along the line from X1 to X2.) are always the same thus we're only calculating it once.
		denominator = (((lineB2.y - lineB1.y) * (lineA2.x - lineA1.x)) - ((lineB2.x - lineB1.x) * (lineA2.y - lineA1.y)));
		//If the resulting denominator were to be 0, we'd have parallel lines with no collision (no surprise there).
		if(denominator == 0)
		{
			areIntersect = false;
		}
		else
		{
			//Since we're dealing with at least one non-infinite length line (though in this case, it's always two), we have to calculate both ua and ub
			float ua = ((((lineB2.x - lineB1.x) * (lineA1.y - lineB1.y)) - ((lineB2.y - lineB1.y) * (lineA1.x - lineB1.x))) / denominator);
			float ub = ((((lineA2.x - lineA1.x) * (lineA1.y - lineB1.y)) - ((lineA2.y - lineA1.y) * (lineA1.x - lineB1.x))) / denominator);

			//If uA is between 0 and 1, then the collision happens between points A1 and A2
			//If uB is between 0 and 1, then the collision happens between points B1 and B2
			if ((ua < 0) || (ua > 1) || (ub < 0) || (ub > 1))
			{
				areIntersect = false;
			}
			else
			{
				areIntersect = true;
			}
		}
	}

	return areIntersect;
}