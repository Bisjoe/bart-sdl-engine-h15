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

	void SetPosition(int x, int y) { 
		dstRect->x = x; dstRect->y = y; }
	void SetDstFrame(int x, int y, int w, int h) { 
		dstRect->x = x, dstRect->y = y; dstRect->w = w; dstRect->h = h; }
	void SetSrcFrame(int x, int y, int w, int h) {
		srcRect->x = x, srcRect->y = y; srcRect->w = w; srcRect->h = h;
	}

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

