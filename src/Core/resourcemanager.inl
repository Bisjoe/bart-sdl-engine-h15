#include "SDL.h"
#include "ResourceManager.h"

template <typename Resource, typename Identifier>
ResourceManager<Resource, Identifier>::ResourceManager()
{

}

template <typename Resource, typename Identifier>
Resource* ResourceManager<Resource, Identifier>::LoadTexture(Identifier id, const std::string& filename)
{
	// First check if the resource already exist
	Resource* res = Get(id);
	// If not, add and return it
	if (!res)
	{
		SDL_Surface* surface;
		SDL_Texture* texture;
		surface = IMG_Load(filename.c_str());
		// Check if the surface was correctly loaded
		if (!surface)
		{
			// Print error
			printf("Image could not be load, ERROR: %s\n", IMG_GetError());
			return NULL;
		}
		else
		{
			// Create texture from the surface
			texture = SDL_CreateTextureFromSurface(Engine::GetInstance()->GetRenderer(), surface);
			SDL_FreeSurface(surface);
			// Check if the texture was created
			if (!texture)
			{
				// Print error
				printf("Faillure while creating texture, ERROR: %s\n", IMG_GetError());
				return NULL;
			}
			else
			{
				// Add the resource in the manager and return a pointer
				InsertResource(id, std::move(texture));
				return texture;
			}
		}
	}
	// Otherwise, simply return the pointer of the resource
	else
	{
		return res;
	}
}


template <typename Resource, typename Identifier>
Resource* ResourceManager<Resource, Identifier>::LoadSound(Identifier id, const std::string& filename)
{
	// First check if the resource already exist
	Resource* res = Get(id);
	// If not, add and return it
	if (!res)
	{
		Mix_Chunk* sound;
		sound = Mix_LoadWAV(filename.c_str());
		// Check if the sound was loaded
		if (!sound)
		{
			// Print error
			printf("Sound could not be load, ERROR: %s\n", Mix_GetError());
			return NULL;
		}
		else
		{
			// Add the resource in the manager and return a pointer
			InsertResource(id, std::move(sound));
			return sound;
		}
	}
	// Otherwise, simply return the pointer of the resource
	else
	{
		return res;
	}
}


template <typename Resource, typename Identifier>
Resource* ResourceManager<Resource, Identifier>::LoadMusic(Identifier id, const std::string& filename)
{
	// First check if the resource already exist
	Resource* res = Get(id);
	// If not, add and return it
	if (!res)
	{
		Mix_Music* music;
		music = Mix_LoadMUS(filename.c_str());
		// Check if the music was loaded
		if (!music)
		{
			// Print error
			printf("Music could not be load, ERROR: %s\n", Mix_GetError());
			return NULL;
		}
		else {
			// Add the resource in the manager and return a pointer
			InsertResource(id, std::move(music));
			return music;
		}
	}
	// Otherwise, simply return the pointer of the resource
	else
	{
		return res;
	}
}


template <typename Resource, typename Identifier>
Resource* ResourceManager<Resource, Identifier>::LoadFont(Identifier id, const std::string& filename)
{
	// First check if the resource already exist
	Resource* res = Get(id);
	// If not, add and return it
	if (!res)
	{
		TTF_Font* font;
		font = TTF_OpenFont(filename.c_str(), 10);
		// Check if the music was loaded
		if (!font)
		{
			// Print error
			printf("Font could not be load, ERROR: %s\n", TTF_GetError());
			return NULL;
		}
		else
		{
			// Add the resource in the manager and return a pointer
			InsertResource(id, std::move(font));
			return font;
		}
	}
	// Otherwise, simply return the pointer of the resource
	else
	{
		return res;
	}
}

template <typename Resource, typename Identifier>
Resource* ResourceManager<Resource, Identifier>::Get(Identifier id) const
{
	// Find the resource
	auto found = mResources.find(id);
	if (found != mResources.end())
	{
		return found->second; 
	} 
	else
	{
		return NULL;
	}	
}

template <typename Resource, typename Identifier>
void ResourceManager<Resource, Identifier>::InsertResource(Identifier id, Resource* resource)
{
	auto inserted = mResources.insert(std::make_pair(id, std::move(resource)));
	assert(inserted.second);
}