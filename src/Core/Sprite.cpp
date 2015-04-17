#include "Sprite.h"

//////////////////////////////
//Default Sprite constructor//
//////////////////////////////
//Shouldn't ever be used directly
//////////////////////////////
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
Sprite::Sprite(Texture::ID id)
	: texture(Engine::GetInstance()->GetTextures()->Get(id))
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
Sprite::Sprite(Texture::ID id, const point<int> srcPos, const point<int> srcSize)
	: texture(Engine::GetInstance()->GetTextures()->Get(id))
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

void Sprite::Start()
{}

void Sprite::Update()
{}

void Sprite::Stop()
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


//////////////////
//Sprite Scaling//
//////////////////
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

/*
Uint32 Sprite::GetPixel(SDL_Surface *surface, int x, int y)
{
	int bpp = surface->format->BytesPerPixel;
	//Here p is the address to the pixel we want to retrieve
	Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;


	switch (bpp) {
	case 1:
		return *p;

	case 2:
		return *(Uint16 *)p;

	case 3:
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			return p[0] << 16 | p[1] << 8 | p[2];
		else
			return p[0] | p[1] << 8 | p[2] << 16;

	case 4:
		return *(Uint32 *)p;

	default:
		return 0;       //shouldn't happen, but avoids warnings
	}
}

void Sprite::DrawPixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
	int bpp = surface->format->BytesPerPixel;
	//Here p is the address to the pixel we want to set
	Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;


	switch (bpp) {
	case 1:
		*p = pixel;
		break;

	case 2:
		*(Uint16 *)p = pixel;
		break;

	case 3:
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN) {
			p[0] = (pixel >> 16) & 0xff;
			p[1] = (pixel >> 8) & 0xff;
			p[2] = pixel & 0xff;
		}
		else {
			p[0] = pixel & 0xff;
			p[1] = (pixel >> 8) & 0xff;
			p[2] = (pixel >> 16) & 0xff;
		}
		break;

	case 4:
		*(Uint32 *)p = pixel;
		break;
	}
}
**/