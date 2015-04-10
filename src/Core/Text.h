#pragma once
#include "Common.h"
#include "Engine.h"

/**  =====================================================
	 SDL_ttf Documentation http://sdl.beuc.net/sdl.wiki/SDL_ttf			
	 =========================================
	 To get new font: http://www.dafont.com/fr/ (watch for license right, some are personal use only)
	 Also make sure they are in ".ttf" (other type of font may work but have not been tested) and
	 that you place them in your project folder.
**/


// Default consts
char* const DEFAULT_TEXT_FONT = "lhandw.ttf";
const SDL_Color DEFAULT_TEXT_COLOR = { 255, 255, 255 };
const int DEFAULT_TEXT_FONTSIZE = 12;
const int DEFAULT_TEXT_WRAPPER = 150;

// Shortcut to quickly get a color without having to manually set an SDL_Color, use with GetColor()
enum DefaultColor {
	WHITE, 
	RED,
	BLUE,
	GREEN
};

class Text :
	public Component
{
private:
	char* fontSrc;
	char* text;
	int x = 0;
	int currentTime;
	int changeAtTime;
	TTF_Font* font;
	SDL_Surface* message;
	int fontSize;
	int wrapper;
	SDL_Color color;
	SDL_Rect* dstRect; 
	SDL_Rect* srcRect;


public:
	Text(char* const text);
	Text(char* const text, char* const fontSrc);
	Text(char* const text, char* const fontSrc, const int fontSize);
	Text(char* const text, char* const fontSrc, const int fontSize, const int wrapper);
	Text(char* const text, char* const fontSrc, const int fontSize, const int wrapper, const int x, const int y);
	Text(char* const text, char* const fontSrc, const int fontSize, const int wrapper, const int x, const int y, SDL_Color color);
	Text(char* const text, char* const fontSrc, const int fontSize, const int wrapper, const int x, const int y, DefaultColor color);
	~Text();

	void SetFont(char* const font);
	void SetText(char* const text);
	void SetFontsize(const int fontSize);
	void SetPosition(const int x, const int y);
	void SetWrapper(const int wrapper);
	void SetTextColor(const SDL_Color color);
	void SetTextColor(const DefaultColor color);
	void UpdateMessage();

	virtual void Start();
	virtual void Update();
	virtual void Stop();

	void Draw();

protected:
	void Init(const int x, const int y);
	void ShowMessage(SDL_Surface* surface);
	SDL_Color GetColor(DefaultColor color);
};

