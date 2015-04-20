#pragma once
#include "Common.h"
#include "Sprite.h"
#include "Engine.h"

/**  =====================================================
	 SDL_ttf Documentation http://sdl.beuc.net/sdl.wiki/SDL_ttf			
	 =========================================
	 To get new font: http://www.dafont.com/fr/ (watch for license right, some are personal use only)
	 Also make sure they are in ".ttf" (other type of font may work but have not been tested) and
	 that you place them in your project folder.
**/

// Default parameters
#define DEFAULT_TEXT_FONT "retro_computer.ttf"
#define DEFAULT_TEXT_FONTSIZE 14
#define DEFAULT_TEXT_WRAPPER 750

namespace Color
{
	static SDL_Color BLACK	= { 0, 0, 0 };
	static SDL_Color WHITE	= { 255, 255, 255 };
	static SDL_Color RED	= { 255, 0, 0 };
	static SDL_Color GREEN	= { 0, 255, 0 };
	static SDL_Color BLUE	= { 0, 0, 255 };
	static SDL_Color YELLOW = { 255, 255, 0 };
}

enum Options {
	OpTypewriter = 0x01,
	OpFadeIn = 0x02,
	OpFadeOut = 0x04,
	OpFlashing = 0x08,
};

class Text :
	public Sprite
{
public:
	Text();
	Text(std::string text);
	Text(std::string text, SDL_Color color);
	Text(std::string text, point<int> pos);
	Text(std::string text, point<int> pos, SDL_Color color);
	Text(std::string text, point<int> pos, std::string font, int wrapping = 0, SDL_Color color = Color::WHITE, unsigned char options = 0);
	Text(std::string text, point<int> pos, TTF_Font* font, int wrapping = 0, SDL_Color color = Color::WHITE, unsigned char options = 0);
	~Text();

	virtual void Start();
	virtual void Update();
	virtual void Stop();
	void UpdateText();


	void SetText(std::string && text)				{ this->text = text, typewriterText = text, changed = true; }
	void SetColor(const SDL_Color color)			{ this->color = color, changed = true; }
	void SetOptions(unsigned char options);

private:
	SDL_Color color;
	TTF_Font* font;
	SDL_Surface* surface;
	std::string text;
	std::string typewriterText;
	unsigned char options;
	int wrapping;
	bool changed;
	float fadeInTimer;
	float fadeInSpeed;
	float fadeOutTimer;
	float fadeOutSpeed;
	float fadeOutDelay;
	float flashingTimer;
	float flashingSpeed;
	float typewriterTimer;
	float typewriterSpeed;
};