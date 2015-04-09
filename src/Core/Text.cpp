#include "Text.h"


Text::Text(char* const text)
	: text(text)
	, fontSrc(DEFAULT_TEXT_FONT)
	, fontSize(DEFAULT_TEXT_FONTSIZE)
	, wrapper(DEFAULT_TEXT_WRAPPER)
	, color(DEFAULT_TEXT_COLOR)
{
	Init(0, 0);
}

Text::Text(char* const text, char* const fontSrc)
	: text(text)
	, fontSrc(fontSrc)
	, fontSize(DEFAULT_TEXT_FONTSIZE)
	, wrapper(DEFAULT_TEXT_WRAPPER)
	, color(DEFAULT_TEXT_COLOR)
{
	Init(0, 0);
}

Text::Text(char* const text, char* const fontSrc, const int fontSize)
	: text(text)
	, fontSrc(fontSrc)
	, fontSize(fontSize)
	, wrapper(DEFAULT_TEXT_WRAPPER)
	, color(DEFAULT_TEXT_COLOR)
{
	Init(0, 0);
}

Text::Text(char* const text, char* const fontSrc, const int fontSize, const int wrapper)
	: text(text)
	, fontSrc(fontSrc)
	, fontSize(fontSize)
	, wrapper(wrapper)
	, color(DEFAULT_TEXT_COLOR)
{
	Init(0, 0);
}

Text::Text(char* const text, char* const fontSrc, const int fontSize, const int wrapper, const int x, const int y)
	: text(text)
	, fontSrc(fontSrc)
	, fontSize(fontSize)
	, wrapper(wrapper)
	, color(DEFAULT_TEXT_COLOR)
{
	Init(x, y);
}

Text::Text(char* const text, char* const fontSrc, const int fontSize, const int wrapper, const int x, const int y, SDL_Color color)
	: text(text)
	, fontSrc(fontSrc)
	, fontSize(fontSize)
	, wrapper(wrapper)
	, color(color)
{
	Init(0, 0);
}

Text::Text(char* const text, char* const fontSrc, const int fontSize, const int wrapper, const int x, const int y, DefaultColor color)
	: text(text)
	, fontSrc(fontSrc)
	, fontSize(fontSize)
	, wrapper(wrapper)
	, color(GetColor(color))
{
	Init(0, 0);
}

Text::~Text()
{

}

void Text::Init(const int x, const int y)
{
	srcRect = new SDL_Rect();
	srcRect->x = 0;
	srcRect->y = 0;
	srcRect->w = DEFAULT_WIN_W;
	srcRect->h = DEFAULT_WIN_H;

	dstRect = new SDL_Rect();
	dstRect->x = x;
	dstRect->y = y;
}

void Text::SetFont(char* const font) {
	this->fontSrc = font;
}

void Text::SetFontsize(const int fontSize) {
	this->fontSize = fontSize;
}

void Text::SetPosition(const int x, const int y) {
	dstRect->x = x;
	dstRect->y = y;
}

void Text::SetWrapper(const int wrapper) {
	this->wrapper = wrapper;

}

void Text::SetTextColor(const SDL_Color color) {
	this->color = color;
}

void Text::SetTextColor(const DefaultColor color) {
	this->color = GetColor(color);
}

// Use this to change the message midplay
void Text::UpdateMessage() {
	this->font = TTF_OpenFont(this->fontSrc, this->fontSize);
	message = TTF_RenderText_Blended_Wrapped(this->font, this->text, this->color, this->wrapper);
}

void Text::Start()
{
	this->font = TTF_OpenFont(this->fontSrc, this->fontSize);
	message = TTF_RenderText_Blended_Wrapped(this->font, this->text, this->color, this->wrapper);
}

void Text::Update()
{
	/* Update message test | Take out commentary to see it in action
	(working so far, but may cause a crash after a while.)
	this->x++;
	this->color = { this->x, 0, 0 };
	UpdateMessage();
	*/
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

SDL_Color Text::GetColor(DefaultColor color)
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
