#include "SDL.h"
#include "ResourceHolder.h"

template <typename Resource, typename Identifier>
ResourceHolder<Resource, Identifier>::ResourceHolder()
{

}

template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::LoadTexture(Identifier id, const std::string& filename)
{
	SDL_Surface* surface;
	SDL_Texture* texture;

	surface = IMG_Load(filename.c_str());
	
	texture = SDL_CreateTextureFromSurface(Engine::GetInstance()->GetRenderer(), surface);
	
	texture = texture;
	SDL_FreeSurface(surface);
	
	InsertResource(id, std::move(texture));
}


template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::LoadSound(Identifier id, const std::string& filename)
{
	Mix_Chunk* sound;
	sound = Mix_LoadWAV(filename.c_str());
	InsertResource(id, std::move(sound));
}


template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::LoadMusic(Identifier id, const std::string& filename)
{
	Mix_Music* music;
	music = Mix_LoadMUS(filename.c_str());
	InsertResource(id, std::move(music));
	if (!music)
	{
		std::cout << "Music could not be load, ERROR: %s\n", Mix_GetError();
	}
}


template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::LoadFont(Identifier id, const std::string& filename)
{
	TTF_Font* font;
	font = TTF_OpenFont(filename.c_str(), 10);
	InsertResource(id, std::move(font));
}

template <typename Resource, typename Identifier>
Resource* ResourceHolder<Resource, Identifier>::Get(Identifier id) const
{
	auto found = mResources.find(id);
	assert(found != mResources.end());

	return found->second;
}

template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::InsertResource(Identifier id, Resource* resource)
{
	auto inserted = mResources.insert(std::make_pair(id, std::move(resource)));
	assert(inserted.second);
	
}