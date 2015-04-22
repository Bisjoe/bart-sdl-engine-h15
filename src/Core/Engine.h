#pragma once

#include "Common.h"
#include "Component.h"

// Shortcuts
// Engine access
#define cEngine Engine::GetInstance()

// delta time
#define DTime cEngine->GetTimer()->GetDeltaTime()

// Resources
#define Textures cEngine->GetTextures()
#define Fonts cEngine->GetFonts()
#define Sounds cEngine->GetSounds()
#define Musics cEngine->GetMusics()

// Audio
#define cAudio cEngine->GetAudio()

// Inputs
#define ThisKeyPressed cEngine->GetInput()->IsKeyPressed
#define ThisKeyHeld cEngine->GetInput()->IsKeyHeld
#define ThisKeyReleased cEngine->GetInput()->IsKeyReleased

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

	void AddNewComponent(Component* comp);
	void DeleteComponent(Component* comp);
		
	SDL_Renderer* GetRenderer()									{ return renderer; }
	ResourceManager<SDL_Texture, std::string>* GetTextures()	{ return textures; }
	ResourceManager<TTF_Font, std::string>*	GetFonts()			{ return fonts;    }
	ResourceManager<Mix_Music, std::string>* GetMusics()		{ return musics;   }
	ResourceManager<Mix_Chunk, std::string>* GetSounds()		{ return sounds;   }
	Input*	GetInput()											{ return input;    }
	Timer*	GetTimer()											{ return timer;    }
	SDL_Window*	GetWindow()										{ return window;   }
	Audio* GetAudio()											{ return audio;    }

private:
	void Start();
	void Update();
	void Draw();

	void CheckNew();
	void CheckDeleted();
	

	SDL_Window* window;
	SDL_Renderer* renderer;
	Input* input;
	Timer* timer;
	Audio* audio;
	point<float> scaling;

	std::vector<Component*> toDelete;
	std::vector<Component*> toAdd;
	bool addNeeded;
	bool delNeeded;

	ResourceManager<SDL_Texture, std::string>*	textures;
	ResourceManager<TTF_Font, std::string>*		fonts;
	ResourceManager<Mix_Music, std::string>*	musics;
	ResourceManager<Mix_Chunk, std::string>*	sounds;
};

