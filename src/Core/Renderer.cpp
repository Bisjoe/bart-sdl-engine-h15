#include "Renderer.h"

Renderer::Renderer()
	: isInitialized(false)
	, screen(nullptr)
{

}

Renderer::Renderer(SDL_Window* window)
	: isInitialized(false)
	, screen(nullptr)
{
	screen = SDL_GetWindowSurface(window);
}

Renderer::~Renderer()
{
	SDL_FreeSurface(screen);
	screen = nullptr;
}
