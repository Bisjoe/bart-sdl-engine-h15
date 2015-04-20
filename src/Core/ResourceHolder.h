#ifndef RESOURCE_HOLDER
#define RESOURCE_HOLDER

#include "Common.h"
#include <map>
#include <memory>
#include <cassert>
#include <stdexcept>

/**
	Forward declaration of Enums
	=============================
	Make sure to take a peak at the suggested use from "ResourceIDs.h" within TestEnvironment.
	You'll be able to declare all of your game's various external resources using these enums.
	It'll suddenly become easy to access Textures, Fonts, Music and Sounds across your project.
**/
namespace Texture { enum ID; }
namespace Font { enum ID; }
namespace Music { enum ID; }
namespace Sound { enum ID; }

template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
	//Constructor
	ResourceHolder();

	//Deconstructor
	~ResourceHolder();

	//Load resource
	void				LoadTexture(Identifier id, const std::string& filename);
	void				LoadSound(Identifier id, const std::string & filename);
	void				LoadMusic(Identifier id, const std::string & filename);
	void				LoadFont(Identifier id, const std::string & filename, int fontSize);

	//Get resource from ID
	Resource*			Get(Identifier id) const;

private:
	void				InsertResource(Identifier id, Resource* resource);


private:
	std::map<Identifier, Resource*>	mResources;
};

#include "ResourceHolder.inl"
#endif
