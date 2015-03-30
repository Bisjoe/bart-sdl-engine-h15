#pragma once
#include "Sprite.h"
class Ship :
	public Sprite
{
public:
	Ship();
	~Ship();

	void Start();
	void Update();
	void Stop();
};

