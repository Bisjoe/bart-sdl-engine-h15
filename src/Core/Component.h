#pragma once
#include <iostream>
#include <vector>

class Component
{
friend class Engine;

public:
	Component() { toAdd.push_back(this); }
	~Component() {}

	virtual void Start()  = 0;
	virtual void Update() = 0;
	virtual void Draw()	  = 0;
	virtual void Stop()   = 0;
	virtual void Kill()   = 0;

private:
	// Components vectors
	static std::vector<Component*> components;
	static std::vector<Component*> toAdd;
	static std::vector<Component*> toDelete;
	static std::vector<Component*> removed;
};

