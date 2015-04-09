#include "Input.h"

Input::Input()
{
	// Initialise both arrays with false
	
	// Keyboard
	SDL_memset(keys, false, sizeof(bool) * KEY_COUNT);
	SDL_memcpy(lastKeys, keys, sizeof(bool)  *KEY_COUNT);
	
	// Mouse
	SDL_memset(mouseButtons, false, sizeof(bool) * MOUSE_BUTTON_COUNT);
	SDL_memcpy(lastMouseButtons, mouseButtons, sizeof(bool)  *MOUSE_BUTTON_COUNT);
}

Input::~Input()
{
}

void Input::Poll(const SDL_Event& e)
{
	switch (e.type)
	{
	case SDL_KEYDOWN:
		if (!e.key.repeat)
		{
			lastKeys[e.key.keysym.scancode] = false;
			keys[e.key.keysym.scancode] = true;
		}
		break;
	case SDL_KEYUP:
		lastKeys[e.key.keysym.scancode] = true;
		keys[e.key.keysym.scancode] = false;
		break;
	case SDL_MOUSEMOTION:
		break;
	case SDL_MOUSEBUTTONDOWN:
		break;
	case SDL_MOUSEBUTTONUP:
		break;
	default:
		break;
	}
}

bool Input::IsKeyHeld(const SDL_Scancode& key)
{
	return keys[key];
}

bool Input::IsKeyPressed(const SDL_Scancode& key)
{
	bool isPressed = !lastKeys[key] && keys[key];
	if (isPressed)
	{
		lastKeys[key] = keys[key];
	}
	return isPressed;
}

bool Input::IsKeyReleased(const SDL_Scancode& key)
{
	bool isReleased = lastKeys[key] && !keys[key];
	if (isReleased)
	{
		lastKeys[key] = keys[key];
	}
	return isReleased;
}

bool Input::IsMouseButtonHeld(int button)
{
	return false;
}

bool Input::IsMouseButtonPressed(int button)
{
	return false;
}

bool Input::IsMouseButtonReleased(int button)
{
	return false;
}

void Input::GetMousePosition(int& x, int& y)
{
	return;
}
