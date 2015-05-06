#pragma once
#include "Common.h"
#include "Engine.h"
#include "Rectangle.h"

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
	Sprite(Texture::ID id);
	Sprite(Texture::ID id, const point<int> srcPos, const point<int> srcSize);
	~Sprite();

	virtual void Start();
	virtual void Update();
	virtual void Stop();
	void Draw();
	void Kill();

	void SetAlpha(int alpha)							{ this->alpha = alpha; }
	void SetPosition(int x, int y)						{ dstRect->x = x; dstRect->y = y; }
	void SetDstFrame(int x, int y, int w, int h)		{ dstRect->x = x, dstRect->y = y; dstRect->w = w; dstRect->h = h; }
	void SetSrcFrame(int x, int y, int w, int h)		{ srcRect->x = x, srcRect->y = y; srcRect->w = w; srcRect->h = h; }
	void SetTexture(Texture::ID id)						{ texture = Engine::GetInstance()->GetTextures()->Get(id); }
	void SetVisible(bool visible)						{ isVisible = visible; }
	void ResizeTo(int w, int h);
	void Flip(unsigned int flip);
	Rectangle GetRect()									{ return Rectangle(dstRect->x, dstRect->y, dstRect->w, dstRect->h); }

	void SetRotation(float angle);
	void RotateBy(float angle);
	void Scale(float k);

	// Getters
	bool IsVisible()			{ return isVisible; }
	point<int> GetPosition()	{ return{ dstRect->x, dstRect->y }; }
	// x = w | y = h
	point<int> GetSize()		{ return{ dstRect->w, dstRect->h }; }
	

protected:
	Sprite();
	void ApplyTexture(SDL_Renderer* renderer);
	void ApplyAlpha();

	SDL_Texture* texture;
	SDL_Rect* dstRect;
	SDL_Rect* srcRect;
	SDL_RendererFlip flipType;

	int alpha;
	float angle;
	float scaling;
	bool isVisible;

};


