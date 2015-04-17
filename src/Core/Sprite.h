#pragma once
#include "Common.h"
#include "Engine.h"

class Sprite :
	public Component
{
public:
	Sprite();
	Sprite(Texture::ID id);
	Sprite(Texture::ID id, const point<int> srcPos, const point<int> srcSize);
	~Sprite();

	virtual void Start();
	virtual void Update();
	virtual void Stop();

	void Draw();
	/*
	void HorizontalMirror();
	void VerticalMirror();
	void HorizontalFlip();
	void VerticalFlip();
	Uint32 GetPixel(SDL_Surface *surface, int x, int y);
	void DrawPixel(SDL_Surface *surface, int x, int y, Uint32 pixel);
	*/
	void SetPosition(int x, int y)						{ dstRect->x = x; dstRect->y = y; }
	void SetDstFrame(int x, int y, int w, int h)		{ dstRect->x = x, dstRect->y = y; dstRect->w = w; dstRect->h = h; }
	void SetSrcFrame(int x, int y, int w, int h)		{ srcRect->x = x, srcRect->y = y; srcRect->w = w; srcRect->h = h; }
	void ResizeTo(int w, int h);
	void Flip(SDL_RendererFlip flip);

	void SetRotation(float angle);
	void RotateBy(float angle);
	void Scale(float k);

protected:
	void ApplyTexture(SDL_Renderer* renderer);

private:
	SDL_Texture* texture;
	SDL_Rect* srcRect;
	SDL_Rect* dstRect;
	SDL_RendererFlip flipType;
	float angle;
	bool isVisible;
};


