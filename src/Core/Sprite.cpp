#include "Sprite.h"

Sprite::Sprite()
	: texture(nullptr)
	, isVisible(true)
	, angle(0)
	, srcRect(0)
	, dstRect(0)
	, scaled(false)
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


Sprite::Sprite(Texture::ID id)
	: texture(Engine::GetInstance()->GetTextures()->Get(id))
	, isVisible(true)
	, angle(0)
	, srcRect(0)
	, dstRect(0)
	//, scaled()
{
	srcRect = new SDL_Rect();
	srcRect->x = 0;
	srcRect->y = 0;
	SDL_QueryTexture(texture, NULL, NULL, &srcRect->w, &srcRect->h);


	dstRect = new SDL_Rect();
	dstRect->x = 0;
	dstRect->y = 0;
	SDL_QueryTexture(texture, NULL, NULL, &dstRect->w, &dstRect->h);
	//SDL_GetWindowSize(Engine::GetInstance()->GetWindow(), &dstRect->w, &dstRect->h);
}


Sprite::Sprite(Texture::ID id, point<int> srcPos, point<int> srcSize)
	: texture(Engine::GetInstance()->GetTextures()->Get(id))
	, isVisible(true)
	, angle(0)
	, srcRect(0)
	, dstRect(0)
	//, scaled()
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
		ApplyTexture(Engine::GetInstance()->GetRenderer());
}


void Sprite::ApplyTexture(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, texture, srcRect, dstRect);
}

/*
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

void Sprite::HorizontalMirror()
{
	SDL_Surface imageTemp = SDL_Surface((*image));
	for (int x = 0; x < image->w; x++)
	{
		for (int y = 0; y < image->h; y++)
		{
			DrawPixel(image, image->w - x, y, GetPixel(&imageTemp, x, y));
		}
	}
}

void Sprite::VerticalMirror()
{
	SDL_Surface imageTemp = SDL_Surface((*image));
	for (int x = 0; x < image->w; x++)
	{
		for (int y = 0; y < image->h; y++)
		{
			DrawPixel(image, x, image->h - y, GetPixel(&imageTemp, x, y));
		}
	}
}

void Sprite::HorizontalFlip()
{
	SDL_Surface* imageTemp = new SDL_Surface();
	imageTemp = LoadImage(path);
	for (int x = 0; x < image->w; x++)
	{
		for (int y = 0; y < image->h; y++)
		{
			DrawPixel(image, image->w-x, y, GetPixel(imageTemp, x, y));
		}
	}
	imageTemp = NULL;
}

void Sprite::VerticalFlip()
{
	SDL_Surface* imageTemp = new SDL_Surface();
	imageTemp = LoadImage(path);
	int x;
	int y;
	for (x = 0; x < image->w; x++)
	{
		for (y = 0; y < image->h; y++)	
		{
			DrawPixel(image, x, image->h-y, GetPixel(imageTemp, x, y));
		}
	}
	imageTemp = NULL;
}
*/