#include "Sprite.h"

Sprite::Sprite()
	: image(nullptr)
	, isVisible(true)
	, angle(0)
	, srcRect(0)
	, dstRect(0)
{
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
{
	image = LoadImage(path);

	dstRect = new SDL_Rect();
	dstRect->x = 0;
	dstRect->y = 0;
}

Sprite::Sprite(const std::string& path, int x, int y)
	: image(nullptr)
	, isVisible(true)
	, angle(0)
	, srcRect(0)
	, dstRect(0)
{
	image = LoadImage(path);

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

	dstRect = new SDL_Rect();
	dstRect->x = x;
	dstRect->y = y;
	dstRect->w = w;
	dstRect->h = h;
}

Sprite::Sprite(const std::string& path, SDL_Rect* dstRect)
	: image(nullptr)
	, isVisible(true)
	, angle(0)
	, srcRect(0)
	, dstRect(0)
{
	image = LoadImage(path);
	this->dstRect = dstRect;
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

void Sprite::ApplySurface(SDL_Surface* surface)
{
	SDL_BlitSurface(image
		, srcRect
		, surface
		, dstRect);
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
