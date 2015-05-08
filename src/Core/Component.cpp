#include "Component.h"

// Only parts that still requires to be in the .cpp
std::vector<Component*> Component::components;
std::vector<Component*> Component::toAdd;
std::vector<Component*> Component::toDelete;
std::vector<Component*> Component::removed;