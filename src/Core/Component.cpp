#include "Component.h"
#include "Engine.h"

std::vector<Component*> Component::components;

Component::Component()
{
	cEngine->AddNewComponent(this);
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
