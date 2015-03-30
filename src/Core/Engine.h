#pragma once

#include "Common.h"
#include "Renderer.h"
#include "Component.h"

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
	void Run();
	void Stop();

	Renderer* GetRenderer(){ return renderer; }
	Input* GetInput(){ return input; }

private:
	void Start();
	void Update();
	void Draw();

	SDL_Window* window;
	Renderer* renderer;
	Input* input;
};

