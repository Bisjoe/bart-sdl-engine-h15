#pragma once
#include "Pool.h"

template<typename T>
class PoolObject
{
public:
	PoolObject()			{  }
	PoolObject(int size)	{  }
	~PoolObject()			{  }

	static Pool<T>* pool;
};

template<typename T>
Pool<T>* PoolObject<T>::pool = nullptr;