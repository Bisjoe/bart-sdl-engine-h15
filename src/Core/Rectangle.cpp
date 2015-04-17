#include "Rectangle.h"
#include <math.h>
#include <stdexcept>


//Default Constructor, everything's a zero.
Rectangle::Rectangle()
:x(0),
y(0),
width(0),
height(0)
{
	return;
}

//Default deconstructor
Rectangle::~Rectangle()
{
	return;
}


//Rectangle's Constructor:
//We do not accept any negative width or height over here. You shall obey!
//Has there been a consensus on wheter the height would mean the rectangle would go up from X/Y or down from it?
//I'm pretty sure it's assumed that it is the top-left corner based upon the very next constructor...
//You could pretty much do just about anything, heck the x/y could be from the rectangle's mid point... ARGH

//Assume everything in the code is based upon this very system. We build rectangles downward, from X/Y, which is the top left point.
/////////////////////////////////////////////////
//(X,Y)//////////////////////////////////////////
////*----------------------*/////////////////////
////|//////////////////////|/////////////////////
////|//////////////////////|Height///////////////
////|//////////////////////|/////////////////////
////*----------------------*(X+Width, Y-Height)//
////////////Width////////////////////////////////
Rectangle::Rectangle(float x, float y, float width, float height)
:x(x),
y(y),
width(abs(width)),
height(abs(height))
{
	return;
}

//I really do not like how one is considered the topLeft and one is considered btmRight...
//It makes dealing with various cases counter-intuitive or simply forces you to make the function restrictive.
//Did I mention how annoying this is? Of course I did, gawsh.
Rectangle::Rectangle(const Vector2D* const topLeft, const Vector2D* const btmRight)
:x(topLeft->x),
y(topLeft->y),
width(abs(btmRight->x - this->x)),
height(abs(btmRight->y - this->y))
{
	//There could have been a thousand way to deal with this, so I'm defending my point with this:
	//topLeft is supposed to be the top left point && btmRight is supposed to be the bottom right point, nothing else..
	//Surprisingly, this involves that we simply do not change anything or do any more validation than above, because none is necessary.
	//The distance between x1 and x2 = width, the distance between y1 and y2 is = height. The rectangle'll be valid no matter what.

	//You could argue that you could draw the rectangle first and then simply realign the x/y at the top left corner, or switch the rectangle around...
	//I disagree, you'd do something that goes against this function's parameter's names.
	//Heck if we even dealt this correctly we'd simply throw an exception if you entered invalid values.
	//I believe throwing an exception is the general consensus, you'd rather have a valid rectangle than one the user didn't expect.

	//Well I just convinced myself to throw an exception, they're definitely fine in constructors, there's a thing about memory leaks...
	//But in this case such thing can't happen. Phew.
	if ((btmRight->x < topLeft->x) || (btmRight->y > topLeft ->x))
	{
		throw std::invalid_argument ("Invalid arguments");
	}
}

//Simple check to determine if a point is within coords
// Please keep in mind if a point was ON one of the rectangle's border, it will be considered as WITHIN the rectangle.
bool Rectangle::Contains(const float x, const float y)
{
	return (x >= this->GetX() && x <= (this->GetX() + this->GetWidth()) && y >= this->GetY() && y <= (this->GetY() + this->GetHeight()));
}

//Simply pass the vector as two points, I bet you could flip those around as needed.
//Even if this looks like a simple one liner, I refuse to believe this should be inlined.
bool Rectangle::Contains(const Vector2D* const point)
{
	return Contains(point->x, point->y);
}

//For the sake of consistency, the vector is reusing the setposition(points) func and not vice versa.
void Rectangle::SetPosition(const Vector2D* const vect)
{
	SetPosition(vect->x, vect->y);
	return;
}

//We only have to change the x/y variables to move a rectangle, it'll be drawn using its width and height, how nifty is that.
void Rectangle::SetPosition(float x, float y)
{
	this->x = x;
	this->y = y;
	return;
}

//Using MoveBy(Points), reusing functions is fun!
void Rectangle::MoveBy(const Vector2D*  const vect)
{
	MoveBy(vect->x, vect->y);
	return;
}

//Nothing special over here. However we call setPosition instead of manually setting the variables.
//This is extremely important if we ever had illegal possibilities to consider.
void Rectangle::MoveBy(const float x, const float y)
{
	SetPosition(this->GetX()+x, this->GetY()+y);
	return;
}

//I believe this is the easiest collision algorithm to figure out by oneself. 
// Every axis-aligned rectangle-rectangle collisions must respect these  statements to actually be colliding.
// Rect1.TopLeftX < B.BottomRight2
// Rect1.BottomRightX > B.TopLeftX1 
// Rect1.TopLeftY < B.BottomRightY
// Rect1.BottomRightY > B.TopLeftY
bool Rectangle::CollidesWith(const Rectangle* const rect) const
{
	bool areColliding;
	areColliding = false;
	if (this->GetX() < (rect->GetX() + rect->GetWidth()) && (this->GetX() + this->GetWidth()) > rect->GetX() &&
		this->GetY() < (rect->GetY() + rect->GetHeight()) && (this->GetY() + this->GetHeight())> rect->GetY())
	{
		areColliding = true;
	}
	return areColliding;
}