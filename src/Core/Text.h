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
#define DEFAULT_FADEIN_MAX 16
#endif
#ifndef DEFAULT_FADEINTXT
#define DEFAULT_FADEINTXT { false, 0, 0, NULL, NULL, "" }
#endif
typedef char const* Str;

// Shortcut to quickly get a color without having to manually set an SDL_Color
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
	Str fontSrc;
	Str text;
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
	Text(Str text);
	Text(int x, int y);
	Text(Str text, Str fontSrc);
	Text(Str text, Str fontSrc, int fontSize);
	Text(Str text, Str fontSrc, int fontSize, int wrapper);
	Text(Str text, Str fontSrc, int fontSize, int wrapper, int x, int y);
	Text(Str text, Str fontSrc, int fontSize, int wrapper, int x, int y, SDL_Color color);
	Text(Str text, Str fontSrc, int fontSize, int wrapper, int x, int y, DefaultColor color);
	~Text();

	// Setters
	void SetFont(Str font);
	void SetText(Str text);
	void SetFontsize(int fontSize);
	void SetPosition(int x, int y);
	void SetWrapper(int wrapper);
	void SetTextColor(const SDL_Color color);
	void SetTextColor(const DefaultColor color);

	// Getter
	point<int> GetTextSize();

	void UpdateMessage();
	virtual void Start();
	virtual void Stop();
	virtual void Draw();

protected:
	FadeInText fadeInTxtsList[DEFAULT_FADEIN_MAX];
	int elemInList;
	char compText[1024];
	void AddToTxtsList(Str text, int x, int y);
	void UpdateFadeIn();
	void Init(int x, int y);
	void ShowMessage(SDL_Surface* surface);
	void Text::ShowFadeIn(SDL_Surface* surface);
	SDL_Color GetColor(DefaultColor color);
};

