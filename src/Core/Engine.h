#pragma once

#include "Common.h"
#include "Component.h"

#define Textures Engine::GetInstance()->GetTextures()
#define Fonts Engine::GetInstance()->GetFonts()
#define Sounds Engine::GetInstance()->GetSounds()
#define Musics Engine::GetInstance()->GetMusics()
#define AudioSys Engine::GetInstance()->GetAudio()


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
	void Init(int screenWidth, int screenHeight, point<float> NativeResolution = { 0, 0 });
	void Run();
	void Stop();

	Audio*								GetAudio()		 { return audio; }
	Input*								GetInput()		 { return input; }
	Timer*								GetTimer()		 { return timer; }
	SDL_Renderer*						GetRenderer()	 { return renderer; }
	SDL_Window*							GetWindow()		 { return window; }
	ResourceHolder<SDL_Texture, int>*	GetTextures()	 { return textures; }
	ResourceHolder<TTF_Font, int>*		GetFonts()		 { return fonts; }
	ResourceHolder<Mix_Music, int>*		GetMusics()		 { return musics; }
	ResourceHolder<Mix_Chunk, int>*		GetSounds()		 { return sounds; }

private:
	void Start();
	void Update();
	void Draw();

	Audio*								audio;
	Input*								input;
	Timer*								timer;
	SDL_Renderer*						renderer;
	SDL_Window*							window;
	ResourceHolder<SDL_Texture, int>*	textures;
	ResourceHolder<TTF_Font, int>*		fonts;
	ResourceHolder<Mix_Music, int>*		musics;
	ResourceHolder<Mix_Chunk, int>*		sounds;
	point<float>						scaling;
};

