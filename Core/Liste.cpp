#include "Liste.h"

template <class T>
Liste::Liste()
	: MIN_LENGTH(100)
	, nb(0)
	, currentLength(nb)
	, content(new int[MIN_LENGTH])
{
}

template <class T>
Liste::Liste(int maxCount)
	: MIN_LENGTH(maxCount)
	, nb(0)
	, currentLength(nb)
	, content(new int[MIN_LENGTH])
{
	
}

template <class T>
Liste::~Liste()
{

}

template <class T>
void Liste::Add(T i)
{
	if (nb < currentLength)
	{
		content[nb] = i;
		nb++;
	}
	else
	{
		T* tempContent;
		memcpy(tempContent, content, currentLength*sizeof(T));
		
		int lastLength = currentLength;
		currentLength *= 2;

		delete[] content;
		content = new T[currentLength];

		memcpy(content, tempContent, lastLength * sizeof(T));
	}
}
