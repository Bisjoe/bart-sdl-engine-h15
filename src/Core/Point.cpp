#include "Point.h"

using namespace std;

template <class T>
double Distance(const point<T> &a, const point<T> &b)
{
	double dx, dy;
	dx = a.x - b.x;
	dy = a.y - b.y;
	return sqrt(dx*dx + dy * dy);
}

template <class T>
void Milieu(const point<T> &a, const point<T> &b, point<T> &m)
{
	m.x = (a.x + b.x) / 2;
	m.y = (a.y + b.y) / 2;
}