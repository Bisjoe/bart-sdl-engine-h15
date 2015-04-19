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

////////////////////////////////
//Sprite (Texture) constructor//
////////////////////////////////
//This'll create a sprite out of a texture.
//This is suited for any non-animated images like a game's HUD, Map or "Title Screen".
//@id - This is your "Sprite sheet" ID.
////////////////////////////////
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

/////////////////////////////////////////////////////
//Sprite (Texture & Sprite Coordinates) constructor//
/////////////////////////////////////////////////////
//This'll create a sprite out of a texture's using specific coordinates.
//This is suited for all actors (Tiles, Characters, Enemies...)
//@id - This is your "Sprite sheet" ID.
//@srcPos - The Sprite's starting (X,Y) position from the Sprite Sheet
//@srcSize - The Sprite's width/height
////////////////////////////////////////////////////////////////////
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


//This'll scale a sprite by the desired K factor.
//ScaleBy(1) will reset the texture back to its original file's size.
//@k - Scaling factor
////////////////////////////////////////////////////////////////////
void Sprite::Scale(float k)
{
	SDL_QueryTexture(texture, NULL, NULL, &dstRect->w, &dstRect->h);
	dstRect->w = (int)(dstRect->w*k);
	dstRect->h = (int)(dstRect->w*k);
}

///////////////////
//Sprite Resizing//
///////////////////
//This'll manually resize a sprite to your desired size.
//This will not modify your sprite's sourcing.
//@w - Desired sprite width
//@h - Desired sprite height
////////////////////////////////////////////////////////
void Sprite::ResizeTo(int w, int h)
{
	dstRect->w = w;
	dstRect->h = h;
}

///////////////////
//Sprite Flipping//
///////////////////
void Sprite::Flip(SDL_RendererFlip flip)
{
	this->flipType = flip;
}

///////////////////
//Sprite Rotation//
///////////////////
void Sprite::SetRotation(float angle)
{
	this->angle = angle;
}

//////////////////////
//Sprite Rotation By//
//////////////////////
void Sprite::RotateBy(float angle)
{
	this->angle += angle;
}