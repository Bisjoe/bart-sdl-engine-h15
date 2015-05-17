#include "Component.h"

std::vector<Component*> Component::components;
std::vector<Component*> Component::toAdd;
std::vector<Component*> Component::toDelete;
std::vector<Component*> Component::removed;

Component::Component()
:isActive(true)
{
	toAdd.push_back(this); 
}

Component::~Component()
{

}