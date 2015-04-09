#pragma once

#include "Common.h"

class Renderer
{
public:
	Renderer();
	Renderer(SDL_Window* window);

	~Renderer();

	SDL_Surface* GetScreen(){ return screen; }

private:
	bool isInitialized;
	SDL_Surface* screen;
};

