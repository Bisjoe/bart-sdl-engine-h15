#pragma once
#include "Common.h"
#include "Sprite.h"
#include "Engine.h"

namespace Color
{
	static SDL_Color BLACK = { 0,	  0,	0};
	static SDL_Color WHITE = { 255,	255,  255};
	static SDL_Color RED   = { 255,	  0,	0};
	static SDL_Color GREEN = { 0,	255,	0};
	static SDL_Color BLUE  = { 0,	  0,  255};
	static SDL_Color YELLOW ={ 255, 255,	0};
}

enum Options {
	OpNone = 0,
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
	Text(std::string text, Font::ID font, int wrapping = 0, SDL_Color color = Color::WHITE, unsigned char options = 0);
	~Text();
	

	void Start();
	void Update();
	void Stop();
	void Kill() { delete this; }
	void Draw() { __super::Draw(); }

	void UpdateText();


	void SetText(std::string && text)				{ this->text = text, typewriterText = text , isDirty = true; }
	void SetColor(const SDL_Color color)			{ this->color = color, isDirty = true; }
	void SetOptions(unsigned char options);

private:
	SDL_Color color;
	TTF_Font* font;
	SDL_Surface* surface;
	std::string text;
	std::string typewriterText;
	unsigned char options;
	int wrapping;
	bool isDirty;
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


