#ifndef TextureHolder_HPP
#define TextureHolder_HPP

#include "Common.h"
#include <map>
#include <memory>
#include <cassert>
#include <stdexcept>

namespace Texture { enum ID; }
namespace Font { enum ID; }
namespace Music { enum ID; }
namespace Sound { enum ID; }

template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
	ResourceHolder();
	void				LoadTexture(Identifier id, const std::string& filename);
	void				LoadSound(Identifier id, const std::string & filename);
	void				LoadMusic(Identifier id, const std::string & filename);
	void				LoadFont(Identifier id, const std::string & filename);

	Resource*			Get(Identifier id) const;

private:
	void				InsertResource(Identifier id, Resource* resource);


private:
	std::map<Identifier, Resource*>	mResources;
};



#include "ResourceHolder.inl"
#endif
