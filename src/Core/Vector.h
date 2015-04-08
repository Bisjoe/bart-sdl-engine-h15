#ifndef VECTOR_HPP
#define VECTOR_HPP

//Vectors 2D and 3D structs, which are 2d coords and 3d coords.
//While Vector 3D and Vector 2D are pretty similar, no function will be shared between both of them
//It would goes against the very spirit of encapsulation, this is non-arguable. Nope, NOPE, NOPEEEEEEEEE!
struct Vector2D 
{
	float x, y;
};
struct Vector3D 
{
	float x, y, z;
};

//Pie goes without saying, this is the value of a cake.
//That's if the cake happened to describe itself as the ratio of the circumference to the diameter of all circles...
//Yup, cake.
const float PI = 3.1415926535897f;



///////////
//Vector 2D
///////////

//Gives the sum of two vectors.
Vector2D Add(const Vector2D* const left, const Vector2D* const right);

//Gives the *difference of two vectors.     *[Difference as in the result of a substraction]
Vector2D Substract(const Vector2D* const left, const Vector2D* const right);

//Returns the resulting vector from scaling a vector.
Vector2D Scale(const Vector2D* const vect, float scale);

//Move a vector
void MoveBy(const Vector2D* const by, Vector2D* const toMove);

//Get the polar bear angle, minus the whole bear part, sadly.
float GetPolarAngleDeg(const Vector2D* const vect);

//Get the angle between two vectors.
float AngleBetweenDeg(const Vector2D* const left, const Vector2D* const right);

//Gives a vector's length
float Length(const Vector2D* const vect);

//Gives a vector's squared length
float LengthSq(const Vector2D* const vect);

//Normalize a vector if it can,and return wheter or not it could
bool Normalize(Vector2D* const vect);

//Directly scale a vector
void ScaleBy(Vector2D* const vect, float scale);

//Get a normalized vector from an angle in degree
Vector2D GetVectorByAngleDeg(float angle);

//Returns wheter or not two vectors are equals
bool Equals(const Vector2D* const left, const Vector2D* const right);



///////////
// Vector 3D
///////////

//Gives the sum of two vectors.
Vector3D Add(const Vector3D* const left, const Vector3D* const right);

//Gives the *difference of two vectors.
Vector3D Substract(const Vector3D* const left, const Vector3D* const right);

//Returns the resulting vector from scaling a vector.
Vector3D Scale(const Vector3D* const vect, float scale);

//Gives out the dot result of two vectors
float Dot(const Vector3D* const left, const Vector3D* const right);

// WARNING: THIS IS UNDER THE ASSUMPTION THAT WE ARE UNDER A RIGHT HANDED COORDINATE SYSTEM PER DEFAULT
// Gives out the cross product result as if it were originally a left-handed vector displayed in a right handed system, hence the '-z'
Vector3D CrossLH(const Vector3D* const left, const Vector3D* const right);

// WARNING: THIS IS UNDER THE ASSUMPTION THAT WE ARE UNDER A RIGHT HANDED COORDINATE SYSTEM PER DEFAULT
// Gives out the cross product result.
Vector3D CrossRH(const Vector3D* const left, const Vector3D* const right);

//Move a vector
void MoveBy(Vector3D* const by, Vector3D* const tomove);

//Gives a vector's length
float Length(const Vector3D* const vect);

//Gives a vector's squared length
float LengthSq(const Vector3D* const vect);

//Normalize a vector if it can,and return wheter or not it could
bool Normalize(Vector3D* const vect);

//Directly scale a vector
void ScaleBy(Vector3D* const vect, float scale);

//Returns wheter or not two vectors are equals
bool Equals(const Vector3D* const left, const Vector3D* const right);

#endif