#include "Component.h"

std::vector<Component*> Component::components;

Component::Component()
{
	components.push_back(this);
}

Component::~Component()
{
}

void Component::Start()
{
	std::cout << "Component Start!" << std::endl;
}

void Component::Update()
{
	std::cout << "Component Update!" << std::endl;
}

void Component::Draw()
{
	std::cout << "Component Draw!" << std::endl;
}

void Component::Stop()
{

}
