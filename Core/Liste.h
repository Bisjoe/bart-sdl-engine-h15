#pragma once

#include <string.h>

template <class T>
class Liste
{
public:
	Liste();
	Liste(T maxCount);
	~Liste();

	void Add(int i);

private:

	const int MIN_LENGTH;
	int currentLength;
	int nb;
	T* content;
};

