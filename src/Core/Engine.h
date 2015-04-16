#pragma once

#include "Common.h"
#include "Renderer.h"
#include "Component.h"

//shortcut
#ifndef ENGINE
#define ENGINE Engine::GetInstance()
#endif
#ifndef GET_INPUT
#define GET_INPUT ENGINE->GetInput()
#endif
#ifndef GET_INPUT_HELD
#define GET_INPUT_HELD GET_INPUT->IsKeyHeld
#endif
#ifndef GET_INPUT_PRESSED
#define GET_INPUT_PRESSED GET_INPUT->IsKeyPressed
#endif
#ifndef GET_INPUT_RELEASED
#define GET_INPUT_RELEASED GET_INPUT->IsKeyReleased
#endif

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

	Renderer* GetRenderer()				{ return renderer; }
	Input* GetInput()					{ return input; }
	Timer* GetTimer()					{ return timer; }
	point<int> GetScreenSize()			{ return screenSize; };

private:
	void Start();
	void Update();
	void Draw();
	point<int> screenSize;
	SDL_Window* window;
	Renderer* renderer;
	Input* input;
	Timer* timer;
};

