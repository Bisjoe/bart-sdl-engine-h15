#include "Engine.h"

Engine* Engine::instance = 0;

Engine::Engine()
	: window(nullptr)
	, audio(nullptr)
	, renderer(nullptr)
	, input(nullptr)
	, timer(nullptr)
	, textures(nullptr)
	, fonts(nullptr)
	, musics(nullptr)
	, sounds(nullptr)
{

}

Engine::~Engine()
{
	Textures->Clear();
	Fonts->Clear();
	// Music and Sounds are cleared at the deletion of audio

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

	SDL_Quit();
}

void Engine::Init()
{
	Init(DEFAULT_WIN_W, DEFAULT_WIN_H);
}

void Engine::Init(int screenWidth, int screenHeight) {
	
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
			textures = new ResourceManager<SDL_Texture, std::string>();
			fonts = new ResourceManager<TTF_Font, std::string>();
			musics = new ResourceManager<Mix_Music, std::string>();
			sounds = new ResourceManager<Mix_Chunk, std::string>();
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
