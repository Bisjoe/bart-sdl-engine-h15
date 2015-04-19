#ifndef RESOURCE_MANAGER
#define RESOURCE_MANAGER

#include "Common.h"
#include <map>
#include <memory>
#include <cassert>
#include <stdexcept>

/**
	
**/
template <typename Resource, typename Identifier>
class ResourceManager
{
public:
	//Constructor
	ResourceManager();

	//Deconstructor
	~ResourceManager();

	//Load resource
	Resource* LoadTexture(const std::string &filepath);
	Resource* LoadSound(const std::string &filepath);
	Resource* LoadMusic(const std::string &filepath);
	Resource* LoadFont(const std::string &filepath);

	//Get resource from ID
	Resource* Get(Identifier filepath) const;
	void Clear();

private:
	void InsertResource(Identifier filepath, Resource* resource);

	std::map<Identifier, Resource*>	mResources;
};

#include "ResourcesManager.inl"
#endif
