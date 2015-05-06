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
	virtual void Kill();

private:
	static std::vector<Component*> components;
	static std::vector<Component*> toAdd;
	static std::vector<Component*> toDelete;
	static std::vector<Component*> removed;

	int depth;
};

