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


// Default parameters
#ifndef DEFAULT_TEXT_FONT
#define DEFAULT_TEXT_FONT "lhandw.ttf"
#endif
#ifndef DEFAULT_TEXT_COLOR
#define DEFAULT_TEXT_COLOR { 255, 255, 255 }
#endif
#ifndef DEFAULT_TEXT_FONTSIZE
#define DEFAULT_TEXT_FONTSIZE 12
#endif
#ifndef DEFAULT_TEXT_WRAPPER
#define DEFAULT_TEXT_WRAPPER 750
#endif
#ifndef DEFAULT_FADEIN_MAX
#define DEFAULT_FADEIN_MAX 5
#endif
#ifndef DEFAUL_FADEINTXT
#define DEFAUL_FADEINTXT { false, 0, 0, NULL, NULL, "" }
#endif

// Shortcut to quickly get a color without having to manually set an SDL_Color, use with GetColor()
enum DefaultColor {
	WHITE, 
	RED,
	BLUE,
	GREEN
};

struct FadeInText {
	bool used;
	float alpha;
	int currentTime;
	SDL_Surface* message;
	SDL_Rect* dstRect;
	char text[128];
};

class Text :
	public Component
{
private:
	char* fontSrc;
	char* text;
	int currentTime;
	int changeAtTime;
	int framerate;
	
	TTF_Font* font;
	SDL_Surface* message;
	int fontSize;
	int wrapper;
	SDL_Color color;
	SDL_Rect* dstRect; 
	SDL_Rect* srcRect;

public:
	Text();
	Text(char* const text);
	Text(const int x, const int y);
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
	void CopyString(char dest[1000], char const source[]);
	void AppendString(char dest[1000], char const source[]);
	point<int> GetTextSize();
	void UpdateMessage();

	virtual void Start();
	virtual void Stop();

	void Draw();

protected:
	FadeInText fadeInTxtsList[DEFAULT_FADEIN_MAX];
	int elemInList;
	char compText[1000];
	void AddToTxtsList(char* const text, const int x, const int y);
	void UpdateFadeIn();
	void Init(const int x, const int y);
	void ShowMessage(SDL_Surface* surface);
	void Text::ShowFadeIn(SDL_Surface* surface);
	SDL_Color GetColor(DefaultColor color);
};

