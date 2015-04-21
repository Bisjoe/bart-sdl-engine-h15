#ifndef POINT_H
#define POINT_H

#include <iostream>

template <class T>
struct point
{
	point()
		: x(0), y(0) { }

	point(T x, T y)
	: x(x), y(y) { }

	T x, y;
};

template <class T>
double Distance(const point<T> &a, const point<T> &b);

template <class T>
void Milieu(const point<T> &a, const point<T> &b, point<T> &m);

#endif
