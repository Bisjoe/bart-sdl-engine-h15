#pragma once

/*
MODE D'EMPLOI

//construct pool
Pool* myPool = new Pool<MyType>(10);
//get object from pool
MyType* i = myPool->NewInstance();

//put object back in pool
myPool->FreeInstance(i);
*/
 
template<class T>
class Pool
{

protected:
	T* _ObjectData;
	T** _ObjectFree;
	int _ObjectCount, _Top;

	void FreeAll()
	{
		int i = (_ObjectCount - 1);

		for (_Top = 0; _Top < _ObjectCount; _Top++)
		{
			_ObjectFree[_Top] = &_ObjectData[i--];
		}
	}

public:
	void FreeInstance(T* instance)
	{
		if ((instance) && (_Top<_ObjectCount) && (instance >= &_ObjectData[0]) && (instance <= &_ObjectData[_ObjectCount - 1]))
		{
			_ObjectFree[_Top++] = instance;
		}
	}
	T* NewInstance()
	{
		if (_Top > 0) {
			return _ObjectFree[--_Top];
		}
		return 0;
	}

	Pool(int count)
	{
		_ObjectData = new T[count];
		_ObjectFree = new T*[count];

		_ObjectCount = count;

		FreeAll();
	}

	virtual ~Pool()
	{
		delete[] _ObjectData;
		delete[] _ObjectFree;
	}
};