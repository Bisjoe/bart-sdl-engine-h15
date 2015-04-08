#include "Text.h"


Text::Text(const char* text)
{
	Init(text, "lhandw.ttf", 12, 0, 0, 150, { 255, 255, 255 });
}

Text::Text(const char* text, const SDL_Color color)
{
	Init(text, "lhandw.ttf", 12, 0, 0, 150, color);
}

Text::Text(const char* text, const DEFAULT_COLOR color)
{
	Init(text, "lhandw.ttf", 12, 0, 0, 150, GetColor(color));
}

Text::Text(const char* text, char* font)
{
	Init(text, font, 12, 0, 0, 150, { 255, 255, 255 });
}

Text::Text(const char* text, char* font, const int fontSize)
{
	Init(text, font, fontSize, 0, 0, 150, { 255, 255, 255 });
}

Text::Text(const char* text, char* font, const int fontSize, const int x, const int y)
{
	Init(text, font, fontSize, x, y, 150, { 255, 255, 255 });
}

Text::Text(const char* text, char* font, const int fontSize, const int x, const int y, const int wrapper)
{
	Init(text, font, fontSize, x, y, wrapper, { 255, 255, 255 });
}

Text::Text(const char* text, char* font, const int fontSize, const int x, const int y, const int wrapper, const SDL_Color color)
{
	Init(text, font, fontSize, x, y, wrapper, color);
}

Text::Text(const char* text, char* font, const int fontSize, const int x, const int y, const int wrapper, const DEFAULT_COLOR color)
{
	Init(text, font, fontSize, x, y, wrapper, GetColor(color));
}


void Text::Init(const char* text, char* font, const int fontSize, const int x, const int y, const int wrapper, const SDL_Color color)
{
	srcRect = new SDL_Rect();
	srcRect->x = 0;
	srcRect->y = 0;
	srcRect->w = DEFAULT_WIN_W;
	srcRect->h = DEFAULT_WIN_H;

	dstRect = new SDL_Rect();
	dstRect->x = x;
	dstRect->y = y;

	this->font = TTF_OpenFont(font, fontSize);
	message = TTF_RenderText_Blended_Wrapped(this->font, text, color, wrapper);
}

Text::~Text()
{

}

void Text::Start()
{

}

void Text::Update()
{
	
}

void Text::Stop()
{
	
}

void Text::Draw()
{
	ShowMessage(Engine::GetInstance()->GetRenderer()->GetScreen());
}

void Text::ShowMessage(SDL_Surface* surface)
{
	SDL_BlitSurface(this->message
		, srcRect
		, surface
		, dstRect);
}

SDL_Color Text::GetColor(DEFAULT_COLOR color)
{
	switch (color) {
		default : {
			return { 0, 0, 0 };
			break;
		}
		case(WHITE) : {
			return { 255, 255, 255 };
			break;
		}
		case(RED) : {
			return { 255, 0, 0 };
			break;
		}
		case(GREEN) : {
			return { 0, 255, 0 };
			break;
		}
		case(BLUE) : {
			return { 0, 0, 255 };
			break;
		}
	}
}
