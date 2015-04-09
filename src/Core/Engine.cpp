#include "Engine.h"

Engine* Engine::instance = 0;

Engine::Engine()
	:window(nullptr)
	, renderer(nullptr)
	, input(nullptr)
	, timer(nullptr)
{

}

Engine::~Engine()
{
	SDL_DestroyWindow(window);
	window = nullptr;

	delete renderer;
	renderer = nullptr;

	delete input;
	input = nullptr;

	delete timer;
	timer = nullptr;

	SDL_Quit();
}

void Engine::Init()
{
	TTF_Init();
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
			input = new Input();
			timer = new Timer();
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

	SDL_UpdateWindowSurface(window);

	SDL_FillRect(renderer->GetScreen(), nullptr, SDL_MapRGB(renderer->GetScreen()->format, 0, 0, 0));
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
