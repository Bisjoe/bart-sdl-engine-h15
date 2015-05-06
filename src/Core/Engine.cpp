#include "Engine.h"

Engine* Engine::instance = 0;

Engine::Engine()
	:window(nullptr)
	, audio(nullptr)
	, input(nullptr)
	, renderer(nullptr)
	, timer(nullptr)
	, textures(nullptr)
	, fonts(nullptr)
	, musics(nullptr)
	, sounds(nullptr)
	, scaling({1, 1})
{

}

Engine::~Engine()
{
	SDL_DestroyWindow(window);
	window = nullptr;

	SDL_DestroyRenderer(renderer);
	renderer = nullptr;

	delete input;
	input = nullptr;

	delete timer;
	timer = nullptr;

	delete audio;
	audio = nullptr;

	textures = nullptr;
	musics = nullptr;
	sounds = nullptr;
	fonts = nullptr;

	SDL_Quit();
}

void Engine::Init()
{
	Init(DEFAULT_WIN_W, DEFAULT_WIN_H);
}

void Engine::Init(int screenWidth, int screenHeight, point<float> NativeResolution) {

	if (TTF_Init() == -1)
	{
		printf("SDL TTF could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
	}
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		// Créer la fenetre
		window = SDL_CreateWindow(
			DEFAULT_WIN_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			screenWidth, screenHeight, SDL_WINDOW_SHOWN);

		if (window == nullptr)
		{
			printf(" Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			audio = new Audio();
			input = new Input();
			timer = new Timer();
			textures = new ResourceHolder<SDL_Texture, int>();
			fonts = new ResourceHolder<TTF_Font, int>();
			musics = new ResourceHolder<Mix_Music, int>();
			sounds = new ResourceHolder<Mix_Chunk, int>();
			if (NativeResolution.x != 0 && NativeResolution.y != 0)
			{
				this->scaling.x = (screenWidth / NativeResolution.x);
				this->scaling.y = (screenHeight / NativeResolution.y);
			}
		}
	}
}

void Engine::Start()
{
	auto iter = Component::components.begin();
	for (; iter != Component::components.end(); iter++)
	{
		(*iter)->Start();
	}

	timer->Reset();
	timer->Start();
}

void Engine::Update()
{
	if (!Component::toAdd.empty())
		CheckNew();
	if (!Component::toDelete.empty())
		CheckDeleted();
	auto iter = Component::components.begin();
	for (; iter != Component::components.end(); iter++)
	{
		(*iter)->Update();
	}

	timer->Tick();
}

void Engine::Draw()
{
	auto iter = Component::components.begin();
	for (; iter != Component::components.end(); iter++)
	{
		(*iter)->Draw();
	}

	SDL_RenderSetScale(renderer, scaling.x, scaling.y);
	SDL_RenderPresent(renderer);
	SDL_RenderClear(renderer);
}


void Engine::Run()
{
	SDL_Event event;
	bool isRunning = true;

	Start();

	while (isRunning)
	{
		while (SDL_PollEvent(&event))
		{
			input->Poll(event);

			switch (event.type)
			{
			case SDL_QUIT:
				isRunning = false;
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					isRunning = false;
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
		}

		Update();
		Draw();
	}

	Stop();
}

void Engine::Stop()
{
	TTF_Quit();
	auto iter = Component::components.begin();
	for (; iter != Component::components.end(); iter++)
	{
		(*iter)->Stop();
	}
	timer->Stop();
}

/**
	Remove a component from the update list
	Can also destroy it
	-------------------------
	@comp Component to delete
	@kill Enter "true" to destroy the component and "false" to only remove it from the update list, default is true
	[!] WARNING: Only use false if you have kept another pointer to the element, or you will have memory leak
**/
void Engine::DeleteComponent(Component* comp)
{
	Component::toDelete.push_back(comp);
}

void Engine::ClearComponents()
{
	auto iter = Component::components.begin();
	for (; iter != Component::components.end(); iter++)
	{
		(*iter)->Kill();
	}
}

// /**
//		Move a component to the end of the update list
//		-------------------------
//		@comp Component to move
// **/
// void Engine::MoveBack(Component* comp)
// {
// 	Component::toAdd.push_back(comp);
// 	DeleteComponent(comp);
// } 

void Engine::CheckNew()
{
	auto iter = Component::toAdd.begin();
	for (; iter != Component::toAdd.end(); iter++)
	{
		Component::components.push_back((*iter));
	}
	Component::toAdd.clear();
}

void Engine::CheckDeleted()
{
	auto iter = Component::toDelete.begin();
	for (; iter != Component::toDelete.end(); iter++)
	{
		auto cIter = Component::components.begin();
		for (; cIter != Component::components.end(); cIter++)
		{
			if (*cIter == *iter)
			{
				(*cIter)->Kill();
				Component::components.erase(cIter);
				break;
			}
		}
	}
	Component::toDelete.clear();
}
