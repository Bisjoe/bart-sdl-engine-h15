#pragma once
#include "Common.h"
#include "Engine.h"

class Sprite :
	public Component
{
public:
	Sprite();
	Sprite(const std::string& path);
	Sprite(const std::string& path, int x, int y);
	Sprite(const std::string& path, int x, int y, int w, int h);
	Sprite(const std::string& path, SDL_Rect* dstRect);
	~Sprite();

	virtual void Start();
	virtual void Update();
	virtual void Stop();

	void Draw();

protected:
	SDL_Surface* LoadImage(const std::string& path);
	void ApplySurface(SDL_Surface* surface);
	
private:
	SDL_Surface* image;
	SDL_Rect* srcRect;
	SDL_Rect* dstRect;
	float angle;
	bool isVisible;
};

