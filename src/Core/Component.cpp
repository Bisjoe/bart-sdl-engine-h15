#include "Component.h"

std::vector<Component*> Component::components;
std::vector<Component*> Component::toAdd;
std::vector<Component*> Component::toDelete;
std::vector<Component*> Component::removed;

Component::Component()
{
	toAdd.push_back(this);
}

Component::~Component()
{
}

void Component::Start()
{
	
}

void Component::Update()
{
	
}

void Component::Draw()
{
	
}

void Component::Stop()
{

}

void Component::Kill()
{

}
