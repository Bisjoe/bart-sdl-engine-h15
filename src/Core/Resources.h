#pragma once
#include "Common.h"
/*
// Shortcuts
#define cResources Resources::GetInstance()
#define Textures cResources->GetTextures()
#define Fonts cResources->GetFonts()
#define Musics cResources->GetMusics()
#define Sounds cResources->GetSounds()

class Resources
{

#pragma region SINGLETON
public:
	static Resources* GetInstance()
	{
		if (!instance)
		{
			instance = new Resources();
		}
		return instance;
	}

	static void Kill()
	{
		delete instance;
		instance = nullptr;
	}

private:
	Resources();
	~Resources();

	static Resources* instance;
#pragma endregion

public:
	ResourceManager<SDL_Texture, std::string>*	GetTextures()	{ return textures; }
	ResourceManager<TTF_Font, std::string>*		GetFonts()		{ return fonts;    }
	ResourceManager<Mix_Music, std::string>*	GetMusics()		{ return musics;   }
	ResourceManager<Mix_Chunk, std::string>*	GetSounds()		{ return sounds;   }
	
private:
	ResourceManager<SDL_Texture, std::string>*	textures;
	ResourceManager<TTF_Font, std::string>*		fonts;
	ResourceManager<Mix_Music, std::string>*	musics;
	ResourceManager<Mix_Chunk, std::string>*	sounds;
	
};

*/