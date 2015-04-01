#pragma once

#include <iostream>
#include <vector>

class Component
{
friend class Engine;

public:
	Component();
	~Component();

	virtual void Start();
	virtual void Update();
	virtual void Draw();
	virtual void Stop();

private:
	static std::vector<Component*> components;
	int depth;
};

