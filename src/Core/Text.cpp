#include "Text.h"
#pragma warning(disable: 4996)


Text::Text()
	: text("")
	, fontSrc(DEFAULT_TEXT_FONT)
	, fontSize(DEFAULT_TEXT_FONTSIZE)
	, wrapper(DEFAULT_TEXT_WRAPPER)
	, color(DEFAULT_TEXT_COLOR)
{
	Init(0, 0);
}

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
	Init(x, y);
}

Text::Text(char* const text, char* const fontSrc, const int fontSize, const int wrapper, const int x, const int y, DefaultColor color)
	: text(text)
	, fontSrc(fontSrc)
	, fontSize(fontSize)
	, wrapper(wrapper)
	, color(GetColor(color))
{
	Init(x, y);
}

Text::~Text()
{

}

void Text::AddToTxtsList(char* const text, const int x, const int y)
{
	elemInList++;
	for (int i = 0; i < DEFAULT_FADEIN_MAX; ++i)
	{
		if (fadeInTxtsList[i].used == false)
		{
			fadeInTxtsList[i].used = true;
			strcpy(fadeInTxtsList[i].text, text);
			fadeInTxtsList[i].message = TTF_RenderText_Blended(this->font, text, this->color);
			SDL_Rect* tempDstRect = new SDL_Rect();
			tempDstRect->x = x;
			tempDstRect->y = y;
			fadeInTxtsList[i].dstRect = tempDstRect;
			break;
		}
	}
}

void Text::Init(const int x, const int y)
{
	elemInList = 0;
	srcRect = new SDL_Rect();
	srcRect->x = 0;
	srcRect->y = 0;
	srcRect->w = DEFAULT_WIN_W;
	srcRect->h = DEFAULT_WIN_H;

	dstRect = new SDL_Rect();
	dstRect->x = x;
	dstRect->y = y;
	for (int i = 0; i < DEFAULT_FADEIN_MAX; ++i)
	{
		fadeInTxtsList[i] = DEFAUL_FADEINTXT;
	}
	this->font = TTF_OpenFont(this->fontSrc, this->fontSize);
}

void Text::SetFont(char* const font) {
	this->fontSrc = font;
}

void Text::SetFontsize(const int fontSize) {
	this->fontSize = fontSize;
	UpdateMessage();
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


// Work in progress, still not quite working well yet
point<int> Text::GetTextSize() {
	int w = 0, h = 0;
	char tempString[250] = "";
	if (text[0] != '\0')
		strcpy(tempString, text);
	if (elemInList > 0) 
	{
		for (int i = 0; i < DEFAULT_FADEIN_MAX; ++i)
		{
			if (fadeInTxtsList[i].used != false)
			{
				strcat(tempString, fadeInTxtsList[i].text);
			}
		}
		
	}
	TTF_SizeText(font, tempString, &w, &h);
	return point<int> { w, h };
}

void Text::Start()
{
	message = TTF_RenderText_Blended_Wrapped(this->font, this->text, this->color, this->wrapper);
}

void Text::UpdateFadeIn()
{
	float dt = Engine::GetInstance()->GetTimer()->GetDeltaTime();
	for (int i = 0; i < DEFAULT_FADEIN_MAX; ++i)
	{
		if (fadeInTxtsList[i].used != false)
		{
			fadeInTxtsList[i].currentTime += dt;
			if (fadeInTxtsList[i].currentTime >= 1.0f / framerate)
			{
				fadeInTxtsList[i].currentTime = 0;
				if (fadeInTxtsList[i].alpha < 255)
				{
					fadeInTxtsList[i].alpha += 0.1f;
					SDL_SetSurfaceAlphaMod(fadeInTxtsList[i].message, fadeInTxtsList[i].alpha);
					ShowFadeIn(Engine::GetInstance()->GetRenderer()->GetScreen());
				}
				else
				{
					elemInList--;
					if (text[0] == '\0')
						strcpy(compText, fadeInTxtsList[i].text);
					else
					strcat(compText, fadeInTxtsList[i].text);
					text = compText;
					fadeInTxtsList[i] = DEFAUL_FADEINTXT;
					UpdateMessage();
				}
			}
		}
	}
}

void Text::Stop()
{
	
}

void Text::Draw()
{
	if (text[0] != '\0')
		ShowMessage(Engine::GetInstance()->GetRenderer()->GetScreen());
	if (elemInList > 0)
		ShowFadeIn(Engine::GetInstance()->GetRenderer()->GetScreen());
}

void Text::ShowMessage(SDL_Surface* surface)
{
	SDL_BlitSurface(this->message
		, srcRect
		, surface
		, dstRect);
}

void Text::ShowFadeIn(SDL_Surface* surface)
{
	for (int i = 0; i < DEFAULT_FADEIN_MAX; ++i)
	{
		if (fadeInTxtsList[i].used != false)
		{
			SDL_BlitSurface(fadeInTxtsList[i].message
				, srcRect
				, surface
				, fadeInTxtsList[i].dstRect);
		}
	}
	
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
