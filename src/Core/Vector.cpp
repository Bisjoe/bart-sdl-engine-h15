#include "Vector.h"
#include <math.h>
#include <float.h>


//////////////////
//Vector2D
/////////////////

//Creates a new vector, x and y becomes the combination of both vector's
//The resulting vector is from Left+Right, even though it's commutative
Vector2D Add(const Vector2D* const left, const Vector2D* const right)
{
	Vector2D result = {};
	result.x = left->x + right->x;
	result.y = left->y + right->y;
	return result;
}

//The resulting vector is from Left- Right
Vector2D Substract(const Vector2D* const left, const Vector2D* const right)
{
	Vector2D result = {};
	result.x = left->x - right->x;
	result.y = left->y - right->y;
	return result;
}

//X * scale, Y * scale, that's about it.
Vector2D Scale(const Vector2D* const vect, float scale)
{
	Vector2D result = {};
	result.x = vect->x * scale;
	result.y = vect->y * scale;
	return result;
}

//Moving the vector by using the preceding add function, re-using code, aww yeah!
void MoveBy(const Vector2D* const by, Vector2D* const toMove)
{
	(*toMove) = Add(by, toMove);
	return;
}


//NO IDEA WHAT THIS DOES
//Just kidding, it gets the polar angle in degree of a specific vector. 
//Yup... yup(??) help me out sir, SIR, SIRRRR, I SAID HELP ME OUT, NO COME BACK.
//Please don't read these comments. I'm bored
float GetPolarAngleDeg(const Vector2D* const vect) 
{
	float rad = atan2(vect->y, vect->x);
	float deg;
	deg = 0.f;

	//We're cleaning out all the easy answers
	if (vect->x == 0 && vect->y > 0)
	{
		deg = 90.0f;
	}
	else if (vect->x == 0 && vect->y < 0)
	{
		deg = 270.0f;
	}
	else if (vect->x < 0 && vect->y == 0)
	{
		deg = 180.0f;
	}
	//Otherwise we do the ugly math, which isn't so bad
	else
	{
		deg = rad * 180.f/PI;
	}

	return deg;
}

//NO IDEA WHAT THIS ONE DOES EITHER, easy peasy, japanesy.
//Mostly kidding, it gives out the angle between two vector in degree
float AngleBetweenDeg(const Vector2D* const left, const Vector2D* const right)
{
	float result;
	result = 0.f;
	Vector2D lefty = *left;
	Vector2D righty = *right;
	if (Normalize(&lefty) && Normalize(&righty))
	{
		result = acos((lefty.x * righty.x) + (lefty.y * righty.y)) * 180.f/PI;
	}
	return result;
}

//I think this one is pretty nifty, we square root the result of the squared length... using LengthSq()!
float Length(const Vector2D* const vect)
{
	return sqrt(LengthSq(vect));
}

//That's the squared length
float LengthSq(const Vector2D* const vect)
{
	float x = vect->x;
	float y = vect->y;
	return (x*x + y*y);
}

//We attempt to normalize a vector, that's by definition, a vector with a length of 1.
//True is returned on success, false is returned on failure.
bool Normalize(Vector2D* const vect)
{
	bool success;
	float length = Length(vect);
	if (length == 0)
	{
		success = false;
	}
	else
	{
		vect->x = vect->x / length;
		vect->y = vect->y / length;
		success = true;
	}
	return success;
}

//Scale a vector directly
void ScaleBy(Vector2D* const vect, float scale)
{
	(*vect) = Scale(vect, scale);
	return;
}

//Get a normalized vector from an angle in degree
Vector2D GetVectorByAngleDeg(float angle)
{
	float radians;
	//We turn our current angle in radian since radians are needed for ze following step
	radians = angle / 180.f*PI;
	Vector2D result = {};
	result.x = cos(radians);
	result.y = sin(radians);
	return result;
}

//We use epsilon to make our unit tests less wonky, 0.000000000000000000000005f and 0.0000000000000000000051f should be considered equal
//This example is actually terribad since I doubt these are legal, but you get the point, right?
bool Equals(const Vector2D* const left, const Vector2D* const right)
{
	return ((abs(left->x - right->x) < FLT_EPSILON) && (abs(left->y - right->y) < FLT_EPSILON));
}







//////////////////
//Vector3D
/////////////////


Vector3D Add(const Vector3D* const left, const Vector3D* const right)
{
	Vector3D result = {};
	result.x = left->x + right->x;
	result.y = left->y + right->y;
	result.z = left->z + right->z;
	return result;
}

Vector3D Substract(const Vector3D* const left, const Vector3D* const right)
{
	Vector3D result = {};
	result.x = left->x - right->x;
	result.y = left->y - right->y;
	result.z = left->z - right->z;
	return result;
}

Vector3D Scale(const Vector3D* const vect, float scale)
{
	Vector3D result = {};
	result.x = vect->x * scale;
	result.y = vect->y * scale;
	result.z = vect->z * scale;
	return result;
}

float Dot(const Vector3D* const left, const Vector3D* const right)
{
	return ((left->x * right->x) + (left->y * right->y) + (left->z * right->z));
}

// Feels like I had to specify these in the header and in here...
// WARNING: THIS IS UNDER THE ASSUMPTION THAT WE ARE UNDER A RIGHT HANDED COORDINATE SYSTEM PER DEFAULT
// Gives out the cross product result as if it were originally a left-handed vector displayed in a right handed system, hence the '-z'
Vector3D CrossLH(const Vector3D* const left, const Vector3D* const right)
{
	Vector3D result;
	result = CrossRH(left, right);
	result.z = -result.z;
	return result;
}

// WARNING: THIS IS UNDER THE ASSUMPTION THAT WE ARE UNDER A RIGHT HANDED COORDINATE SYSTEM PER DEFAULT
// Gives out the cross product result.
Vector3D CrossRH(const Vector3D* const left, const Vector3D* const right)
{
	Vector3D result;
	result.x = left->y * right->z - left->z * right->y;
	result.y = left->z * right->x - left->x * right->z;
	result.z = left->x * right->y - left->y * right->x;
	return result;
}
void MoveBy(Vector3D* const by, Vector3D* const toMove)
{
	(*toMove) = Add(by, toMove);
	return;
}

float Length(const Vector3D* const vect)
{
	return sqrt(LengthSq(vect));
}

float LengthSq(const Vector3D* const vect)
{
	float x = vect->x;
	float y = vect->y;
	float z = vect->z;
	return (x*x + y*y + z*z);
}


//We attempt to normalize a vector, that's by definition, a vector with a length of 1.
//True is returned on success, false is returned on failure.
bool Normalize(Vector3D* const vect)
{
	bool success;
	float length = Length(vect);
	if (length == 0)
	{
		success = false;
	}
	else
	{
		vect->x = vect->x / length;
		vect->y = vect->y / length;
		vect->z = vect->z / length;
		success = true;
	}
	return success;
}

void ScaleBy(Vector3D* const vect, float scale)
{
	(*vect) = Scale(vect, scale);
	return;
}

bool Equals(const Vector3D* const left, const Vector3D* const right)
{
	return ((abs(left->x - right->x) < FLT_EPSILON) && (abs(left->y - right->y) < FLT_EPSILON) && (abs(left->z - right->z) < FLT_EPSILON));
}