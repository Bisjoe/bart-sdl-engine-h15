#include "Engine.h"

Engine* Engine::instance = 0;

Engine::Engine()
{
}

Engine::~Engine()
{
	SDL_DestroyWindow(window);
	window = nullptr;

	delete renderer;
	renderer = nullptr;

	SDL_Quit();
}

void Engine::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		// Créer la fenetre
		window = SDL_CreateWindow(
			DEFAULT_WIN_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			DEFAULT_WIN_W, DEFAULT_WIN_H, SDL_WINDOW_SHOWN);

		if (window == nullptr)
		{
			printf(" Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			renderer = new Renderer(window);
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
}

void Engine::Update()
{
	auto iter = Component::components.begin();
	for (; iter != Component::components.end(); iter++)
	{
		(*iter)->Update();
	}
}

void Engine::Draw()
{
	auto iter = Component::components.begin();
	for (; iter != Component::components.end(); iter++)
	{
		(*iter)->Draw();
	}

	SDL_UpdateWindowSurface(window);
}

void Engine::Run()
{
	Start();
	for (;;)
	{
		Update();
		Draw();
	}
	Stop();
}

void Engine::Stop()
{
	auto iter = Component::components.begin();
	for (; iter != Component::components.end(); iter++)
	{
		(*iter)->Stop();
	}
}
