#pragma once
#include "Common.h"
#include "Engine.h"

// Flip shortcuts
#ifndef FLIPPERS
#define FLIPPERS
#define flip_n SDL_FLIP_NONE
#define flip_h SDL_FLIP_HORIZONTAL
#define flip_v SDL_FLIP_VERTICAL
#endif

class Sprite :
	public Component
{
public:
	Sprite();
	Sprite(std::string filepath);
	Sprite(std::string filepath, const point<int> srcPos, const point<int> srcSize);
	~Sprite();

	void Draw();
	void Kill();

	void SetAlpha(int alpha)							{ this->alpha = alpha; }
	void SetPosition(int x, int y)						{ dstRect->x = x; dstRect->y = y; }
	void SetPosition(point<int> pos)					{ dstRect->x = pos.x; dstRect->y = pos.y; }
	void MoveBy(int x, int y)                           { dstRect->x += x, dstRect->y += y; }
	void SetDstFrame(SDL_Rect* rect)					{ dstRect = rect; }
	void SetDstFrame(int x, int y, int w, int h)		{ dstRect->x = x, dstRect->y = y; dstRect->w = w; dstRect->h = h; }
	void SetSrcFrame(SDL_Rect* rect)					{ srcRect = rect; }
	void SetSrcFrame(int x, int y, int w, int h)		{ srcRect->x = x, srcRect->y = y; srcRect->w = w; srcRect->h = h; }
	void ResizeTo(int w, int h);

	/**
		Flips the sprite
		-------------------
		@Flip is the fliptype to use
		- flip_n = no flip (use to return to default after a flip)
		- flip_h = horizontal flip
		- flip_v = vertical flip
		[!] It is impossible to flip vertically and horizontally at the same time,
		instead, do a 180 degree rotation
	**/
	void Flip(SDL_RendererFlip flip);

	void ToggleVisibility()								{ isVisible = !isVisible; }
	void SetVisibility(bool isVisible)					{ this->isVisible = isVisible; }

	void SetRotation(float angle);
	void RotateBy(float angle);
	void Scale(float k);

	// Getters
	bool IsVisible()									{ return isVisible; }
	point<int> GetPosition()                            { return { dstRect->x, dstRect->y }; }
	// x = w | y = h
	point<int> GetSize()								{ return{ dstRect->w, dstRect->h }; }

protected:
	void ApplyTexture(SDL_Renderer* renderer);
	void ApplyAlpha();

	SDL_Texture* texture;
	SDL_Rect* srcRect;
	SDL_Rect* dstRect;
	SDL_RendererFlip flipType;
	float angle;
	float scaling;
	bool isVisible;
	int alpha;
};


