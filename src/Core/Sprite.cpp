#include "Sprite.h"

Sprite::Sprite()
	: image(nullptr)
	, isVisible(true)
	, angle(0)
	, srcRect(0)
	, dstRect(0)
	, scaled(false)
{
	srcRect = new SDL_Rect();
	srcRect->x = 0;
	srcRect->y = 0;
	srcRect->w = Engine::GetInstance()->GetScreenSize().x;
	srcRect->h = Engine::GetInstance()->GetScreenSize().y;
	
	dstRect = new SDL_Rect();
	dstRect->x = 0;
	dstRect->y = 0;
}

Sprite::Sprite(const std::string& path)
	: image(nullptr)
	, isVisible(true)
	, angle(0)
	, srcRect(0)
	, dstRect(0)
	, scaled(false)
{
	image = LoadImage(path);

	srcRect = new SDL_Rect();
	srcRect->x = 0;
	srcRect->y = 0;
	srcRect->w = Engine::GetInstance()->GetScreenSize().x;
	srcRect->h = Engine::GetInstance()->GetScreenSize().y;

	dstRect = new SDL_Rect();
	dstRect->x = 0;
	dstRect->y = 0;
	dstRect->w = 50;
	dstRect->h = 50;
}

Sprite::Sprite(const std::string& path, int x, int y)
	: image(nullptr)
	, isVisible(true)
	, angle(0)
	, srcRect(0)
	, dstRect(0)
	, scaled(false)
{
	image = LoadImage(path);

	srcRect = new SDL_Rect();
	srcRect->x = 0;
	srcRect->y = 0;
	srcRect->w = Engine::GetInstance()->GetScreenSize().x;
	srcRect->h = Engine::GetInstance()->GetScreenSize().y;

	dstRect = new SDL_Rect();
	dstRect->x = x;
	dstRect->y = y;
}

Sprite::Sprite(const std::string& path, int x, int y, int w, int h)
	: image(nullptr)
	, isVisible(true)
	, angle(0)
	, srcRect(0)
	, dstRect(0)
{
	image = LoadImage(path);

	srcRect = new SDL_Rect();
	srcRect->x = 0;
	srcRect->y = 0;
	srcRect->w = Engine::GetInstance()->GetScreenSize().x;
	srcRect->h = Engine::GetInstance()->GetScreenSize().y;

	dstRect = new SDL_Rect();
	dstRect->x = x;
	dstRect->y = y;
	dstRect->w = w;
	dstRect->h = h;

	if (dstRect->w == 0 || dstRect->h == 0)
		scaled = false;
	else
		scaled = true;
}

Sprite::Sprite(const std::string& path, SDL_Rect* dstRect)
	: image(nullptr)
	, isVisible(true)
	, angle(0)
	, srcRect(0)
	, dstRect(0)
{
	image = LoadImage(path);

	srcRect = new SDL_Rect();
	srcRect->x = 0;
	srcRect->y = 0;
	srcRect->w = Engine::GetInstance()->GetScreenSize().x;
	srcRect->h = Engine::GetInstance()->GetScreenSize().y;

	this->dstRect = dstRect;

	if (dstRect->w == 0 || dstRect->h == 0)
		scaled = false;
	else
		scaled = true;
}

Sprite::~Sprite()
{

}

void Sprite::Start()
{
	std::cout << "Sprite Start!" << std::endl;
}

void Sprite::Update()
{
	std::cout << "Sprite Update!" << std::endl;
}

void Sprite::Stop()
{
	std::cout << "Sprite Stop!" << std::endl;
}

void Sprite::Draw()
{
	if (isVisible)
		ApplySurface(Engine::GetInstance()->GetRenderer()->GetScreen());
}

// (0, 0) return to the sprite original size
void Sprite::ScaleSprite(int w, int h)
{
	if (w != 0 && h != 0)
	{
		dstRect->w = w;
		dstRect->h = h;
		scaled = true;
	}
	else
	{
		scaled = false;
	}
		
}

void Sprite::ApplySurface(SDL_Surface* surface)
{
	if (!scaled)
	{
		SDL_BlitSurface(image
			, srcRect
			, surface
			, dstRect);
	}
	else
	{
		SDL_BlitScaled(image
			, srcRect
			, surface
			, dstRect);
	}	
}

SDL_Surface* Sprite::LoadImage(const std::string& path)
{
	SDL_Surface* temp = nullptr;
	temp = IMG_Load(path.c_str());
	if (temp == nullptr)
	{
		printf(" Unable to load image %s SDLError: %s\n", path , SDL_GetError());
	}
	return temp;
}
