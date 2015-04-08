#pragma once
#include "Common.h"
#include "Engine.h"

// =====================================================
// ------------------   QUICK DOC  ---------------------
//
// 
//
//
//
//
//
//

enum DEFAULT_COLOR {
	BLACK, 
	WHITE, 
	RED,
	BLUE,
	GREEN
};

class Text :
	public Component
{
private:
	TTF_Font* font;
	SDL_Surface* message;
	SDL_Rect* dstRect; 
	SDL_Rect* srcRect;


public:
	Text(const char* text);
	Text(const char* text, const SDL_Color color);
	Text(const char* text, const DEFAULT_COLOR color);
	Text(const char* text, char* font);
	Text(const char* text, char* font, const int fontSize);
	Text(const char* text, char* font, const int fontSize, const int x, const int y);
	Text(const char* text, char* font, const int fontSize, const int x, const int y, const int wrapper);
	Text(const char* text, char* font, const int fontSize, const int x, const int y, const int wrapper, const SDL_Color color);
	Text(const char* text, char* font, const int fontSize, const int x, const int y, const int wrapper, const DEFAULT_COLOR color);
	void Init(const char* text, char* font, const int fontSize, const int x, const int y, const int wrapper, const SDL_Color color);


	~Text();

	virtual void Start();
	virtual void Update();
	virtual void Stop();

	void Draw();

protected:
	void ShowMessage(SDL_Surface* surface);
	SDL_Color GetColor(DEFAULT_COLOR color);
};

