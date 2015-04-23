#include "Sprite.h"

/** 
	Default Sprite constructor
	[!] Should never be used directly
**/
Sprite::Sprite()
	: texture(nullptr)
	, isVisible(true)
	, angle(0)
	, srcRect(0)
	, dstRect(0)
	, flipType (SDL_FLIP_NONE)
{

	srcRect = new SDL_Rect();
	srcRect->x = 0;
	srcRect->y = 0;
	srcRect->h = 0;
	srcRect->w = 0;

	dstRect = new SDL_Rect();
	dstRect->x = 0;
	dstRect->y = 0;
	dstRect->h = 0;
	dstRect->w = 0;
}

/**
	Sprite (Texture) constructor
	-------------------
	This'll create a sprite out of a texture.
	@filepath : The path to your spritesheet or image
**/
Sprite::Sprite(std::string filepath)
	: texture(Textures->LoadTexture(filepath))
	, isVisible(true)
	, angle(0)
	, srcRect(0)
	, dstRect(0)
	, flipType(SDL_FLIP_NONE)
{
	srcRect = new SDL_Rect();
	srcRect->x = 0;
	srcRect->y = 0;
	SDL_QueryTexture(texture, NULL, NULL, &srcRect->w, &srcRect->h);

	dstRect = new SDL_Rect();
	dstRect->x = 0;
	dstRect->y = 0;
	SDL_QueryTexture(texture, NULL, NULL, &dstRect->w, &dstRect->h);
}

/**
	Sprite (Texture & Sprite Coordinates) constructor
	-------------------
	This'll create a sprite out of a texture's using specific coordinates.
	This is suited for all actors (Tiles, Characters, Enemies...)
	@filepath : The path to your spritesheet or image (also correspond as ID)
	@srcPos - The Sprite's starting (x,y) position from the Sprite Sheet (correspond to top-left corner)
	@srcSize - The Sprite's width/height
**/
Sprite::Sprite(std::string filepath, const point<int> srcPos, const point<int> srcSize)
	: texture(Textures->LoadTexture(filepath))
	, isVisible(true)
	, angle(0)
	, srcRect(0)
	, dstRect(0)
	, flipType(SDL_FLIP_NONE)
{
	srcRect = new SDL_Rect();
	srcRect->x = srcPos.x;
	srcRect->y = srcPos.y;
	srcRect->w = srcSize.x;
	srcRect->h = srcSize.y;

	dstRect = new SDL_Rect();
	dstRect->x = 0;
	dstRect->y = 0;
	dstRect->w = srcSize.x;
	dstRect->h = srcSize.y;
}

Sprite::~Sprite()
{}

void Sprite::Draw()
{
	if (isVisible)
		ApplyTexture(Engine::GetInstance()->GetRenderer());
}

void Sprite::ApplyTexture(SDL_Renderer* renderer)
{
	SDL_RenderCopyEx(renderer, texture, srcRect, dstRect, angle, NULL, flipType);
}


/**
	Scales a sprite by the desired k factor.
	-------------------
	@k - the number to scale by (enter 1 to get back to default texture size)
**/
void Sprite::Scale(float k)
{
	dstRect->w *= (int) k;
	dstRect->h *= (int) k;
}

/**
	Resizes the sprite to the desired size 
	-------------------
	@w - sprite new width
	@h - sprite new height
**/
void Sprite::ResizeTo(int w, int h)
{
	dstRect->w = w;
	dstRect->h = h;
}

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
void Sprite::Flip(SDL_RendererFlip flip)
{
	this->flipType = flip;
}

/**
	Rotate the sprite to the given angle
	-------------------
	@angle angle desired
**/
void Sprite::SetRotation(float angle)
{
	this->angle = angle;
}

/**
	Rotate the sprite by the given angle
	-------------------
	@angle angle to add to the current angle rotation
**/
void Sprite::RotateBy(float angle)
{
	this->angle += angle;
	// Fail safe, prevent the angle to break it's float max value 
	// (unlikely but possible if something continuously rotate fast on the screen for a (very) long time)
	// Better safe than sorry
	if (this->angle >= 360)
	{
		this->angle -= 360;
	}
}

void Sprite::Kill()
{
	delete this;
}