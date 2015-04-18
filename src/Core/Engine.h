#pragma once

#include "Common.h"
#include "Component.h"

#define Textures Engine::GetInstance()->GetTextures()
#define Fonts Engine::GetInstance()->GetFonts()
#define Sounds Engine::GetInstance()->GetSounds()
#define Musics Engine::GetInstance()->GetMusics()

class Engine
{
#pragma region SINGLETON
public:
	static Engine* GetInstance()
	{
		if (!instance)
		{
			instance = new Engine();
		}
		return instance;
	}

	static void Kill()
	{
		delete instance;
		instance = nullptr;
	}

private:
	Engine();
	~Engine();

	static Engine* instance;
#pragma endregion

public:
	void Init();
	void Init(int screenWidth, int screenHeight);
	void Run();
	void Stop();

	SDL_Renderer*						GetRenderer()	 { return renderer; }
	ResourceManager<SDL_Texture, int>*	GetTextures()	 { return textures; }
	ResourceManager<TTF_Font, int>*		GetFonts()		 { return fonts; }
	ResourceManager<Mix_Music, int>*	GetMusics()		 { return musics; }
	ResourceManager<Mix_Chunk, int>*	GetSounds()		 { return sounds; }
	Input*								GetInput()		 { return input; }
	Timer*								GetTimer()		 { return timer; }
	SDL_Window*							GetWindow()		 { return window; }

private:
	void Start();
	void Update();
	void Draw();

	SDL_Window* window;
	SDL_Renderer* renderer;
	Input* input;
	Timer* timer;
	ResourceManager<SDL_Texture, int>*		textures;
	ResourceManager<TTF_Font, int>*			fonts;
	ResourceManager<Mix_Music, int>*		musics;
	ResourceManager<Mix_Chunk, int>*		sounds;
};

