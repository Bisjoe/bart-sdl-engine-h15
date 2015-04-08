#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Vector.h"
#include "Rectangle.h"
#include <math.h>

//I heard there was an existing rectangle class so I decided to use a namespace, same with rectangle.

	//A circle
	class Circle
	{
	private:
		//Our circle's middle X/Y pos
		float x;
		float y;

		//Our circle's radius
		float radius;

	public:
		//Our defaults
		Circle();
		~Circle();

		//Our special constructors, we always need a point and a radius.
		Circle(float x, float y, float radius);
		Circle(const Vector2D* const center, float radius);

		//Wheter or not a point is contained in a circle, it considers points ON the circle as WITHIN it.
		bool Contains(const float x, const float y);
		bool Contains(const Vector2D* const point);

		//Getters
		float GetX() const { return x; };
		float GetY() const { return y; };
		float GetRadiusSq() const { return sqrt(radius); };
		float GetRadius() const { return radius; };

		//Setters, not inlined in case of future checks. Trust this guy -->[Me].
		void SetPosition(const Vector2D* const vect);
		void SetPosition(const float x, const float y);

		//Simply move ze circle
		void MoveBy(const Vector2D*  const vect);
		void MoveBy(const float x, const float y);

		//Wheter or not two circles collide with each other
		bool CollidesWith(const Circle* const circ);

		//IT'S A BONUS, WOOO, *cough* calm down sir, this checks wheter our circle collides with a rectangle, and vice versa.
		bool CollidesWith(const Rectangle* const rect); //Bonus

	};


#endif