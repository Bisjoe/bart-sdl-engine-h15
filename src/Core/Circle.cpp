#include "Circle.h"

//While "using namespace TP" could have been used, I'm against the use of such thing, deal with it *put shades on*.
//There's valid reasons for ze above mention.


//Default Constructor, everything's a zero.
Circle::Circle():
x(0),
y(0),
radius(0)
{
	return;
}

//Default deconstructor
Circle::~Circle()
{
	return;
}

//Remember kids, there's no such thing as a negative radius in heaven, at least not for an ordinary circle.
Circle::Circle(float x, float y, float radius)
: x(x),
y(y),
radius(abs(radius))
{
	return;
}

//We've got a vector instead of two coords, that's quite not as amusing as I had hoped.
Circle::Circle(const Vector2D* const center, float radius)
: x(center->x),
y(center->y),
radius(abs(radius))
{
	return;
}

// If a point is contained within a circle
// Points ON the circle's border are considered to be part of the circle
bool Circle::Contains(const float x, const float y)
{
	return (pow(x - this->x, 2) + pow(y - this->y, 2)) <= pow(this->radius, 2);
}

//We're simply passing both coords of the vectors in the existing function
bool Circle::Contains(const Vector2D* const point)
{
	return Contains(point->x, point->y);
}

//We set the circle's position by using the existing SetPosition(x,y)
void Circle::SetPosition(const Vector2D* const vect)
{
	SetPosition(vect->x, vect->y);
	return;
}

//We're setting it its position for real!
void Circle::SetPosition(const float x, const float y)
{
	this->x = x;
	this->y = y;
	return;
}

//We're re-using the moveBy(x,y) function which is reusing setPosition, reusing code is nifty*! *[When used intelligently]
void Circle::MoveBy(const Vector2D*  const vect)
{
	MoveBy(vect->x, vect->y);
	return;
}

//We're simply setting the circle's position to what it would be if we moved it, that way we can deal with all the checks that setPosition might implement one day.
void Circle::MoveBy(const float x, const float y)
{
	SetPosition(this->GetX() + x, this->GetY() +y);
	return;
}

//If a circle collides with another specified circle, we'll return it.
bool Circle::CollidesWith(const Circle* const circ)
{
	return (pow(circ->GetX() - this->GetX(), 2) + pow(circ->GetY() - this->GetY(), 2)) <= pow(this->GetRadius() + circ->GetRadius(), 2);
}


//WARNING: THIS FUNCTION IS ONLY LEGAL WHEN USING AXIS ALIGNED RECTANGLE, which are the only kind of rectangle we're using... so yeah.
//This formula wouldn't work in any other circumstances.
bool Circle::CollidesWith(const Rectangle* const rect)
{
	//We're using a vector2D to store the X and Y distance positions of the circle
	Vector2D circleDistance;
	//We're storing the rectangle's center coordinate, minus its actual position, so let's consider it it's relative center?
	//Alternatively you might consider it the super vector of HalfRectangleWidth and HalfRectangleHeight... weee!!!
	Vector2D rectCenter;
	rectCenter.x = rect->GetWidth() / 2;
	rectCenter.y = rect->GetWidth() / 2;

	//Self-Explaining boolean
	bool areColliding;

	//This part is really nifty, by getting the absolute value of the distance of the circle's center and the rectangle's center...
	//We only have to do math once instead of four time. That's the magic of axis aligned rectangles
	circleDistance.x = abs(this->x - ((rect->GetX() + rect->GetWidth()) / 2));
	circleDistance.y = abs(this->y - ((rect->GetY() + rect->GetHeight()) / 2));

	//We're storing the squared distance of the circle's from the rectangle, minus half the rectangle's size.
	//It's gonna be really useful when calculating wheter or not the corner is colliding with the circle. Trust me.
	float cornerDistance_sq = pow((circleDistance.x - rectCenter.x), 2) + pow((circleDistance.y - rectCenter.y), 2);

	//Cases where the circle is far enough from the rectangle, no collisions.
	if ((circleDistance.x > (rectCenter.x + this->radius)) || (circleDistance.y > (rectCenter.y + this->radius)))
	{
		areColliding = false;
	}
	//Cases where the circle is close enough to the rectangle in any direction, collision.
	else if ((circleDistance.x <= (rectCenter.x)) || (circleDistance.y <= (rectCenter.y)))
	{
		areColliding = true;
	}
	//Rare cases when the corner of the rectangle is colliding with the circle
	else if (cornerDistance_sq <= pow((this->radius), 2))
	{
		areColliding = true;
	}

	return areColliding;
}
