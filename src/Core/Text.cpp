#include "Text.h"
#include <assert.h>
#pragma warning(disable: 4996)

Text::Text()
: Sprite()
, text("")
, typewriterText("")
, color(Color::WHITE)
, surface(nullptr)
, options(0)
, fadeInTimer(0)
, fadeInSpeed(0)
, fadeOutTimer(0)
, fadeOutSpeed(0)
, fadeOutDelay(0)
, flashingTimer(0)
, flashingSpeed(0)
, typewriterTimer(0)
, typewriterSpeed(0)
, wrapping(0)
{
}

Text::Text(std::string text, Font::ID font, int wrapping, SDL_Color color, unsigned char options)
: Sprite()
, text(text)
, typewriterText(text)
, font(Fonts->Get(font))
, color(color)
, surface(nullptr)
, options(0)
, fadeInTimer(0)
, fadeInSpeed(0.01f)
, fadeOutTimer(0)
, fadeOutSpeed(0.01f)
, fadeOutDelay(2.f)
, flashingTimer(0)
, flashingSpeed(25/255.f)
, typewriterTimer(0)
, typewriterSpeed(0.15f)
, wrapping(wrapping)
{
	scaling = 1;
	srcRect = new SDL_Rect();
	srcRect->x = 0;
	srcRect->y = 0;

	dstRect = new SDL_Rect();
	dstRect->x = 0;
	dstRect->y = 0;
	SetOptions(options);
	isDirty = true;
}

Text::~Text()
{}

void Text::Start()
{}

void Text::Stop()
{}

void Text::Update()
{
	float dt = DTime;
	if (options & OpFadeIn)
	{
		fadeInTimer += dt;
		if (fadeInTimer >= fadeInSpeed)
		{
			fadeInTimer -= fadeInSpeed;
			if (this->alpha + 1 <= 255)
			{
				this->alpha += 1;
			}
			else
			{
				options = options & ~Options::OpFadeIn;
			}
		}
		isDirty = true;
	}
	if (options & OpFadeOut)
	{
		fadeOutTimer += dt;
		if (fadeOutTimer >= fadeOutDelay)
		{
			if (fadeOutTimer >= fadeOutSpeed + fadeOutDelay)
			{
				fadeOutTimer -= fadeOutSpeed;
				if (this->alpha - 1 >= 0)
				{
					this->alpha -= 1;
				}
				else
				{
					options = options & ~Options::OpFadeOut;
				}
			}
		}
		isDirty = true;
	}
	if (options & OpFlashing)
	{
		flashingTimer += dt;
		if (flashingTimer >= flashingSpeed)
		{
			flashingTimer -= flashingSpeed;
			if (this->alpha != 0)
			{
				this->alpha = 0;
			}
			else
			{
				this->alpha = 255;
			}
		}
		isDirty = true;
	}
	if (options & OpTypewriter)
	{
		typewriterTimer += dt;
		if (typewriterTimer >= typewriterSpeed)
		{
			typewriterTimer -= typewriterSpeed;
			if (text.length() != typewriterText.length())
			{
				this->text += typewriterText[text.length()];
			}
			else
			{
				options = options & ~Options::OpTypewriter;
			}
		}
		isDirty = true;
	}
	if (isDirty)
	{
		UpdateText();
		isDirty = false;
	}
}

void Text::UpdateText()
{
	SDL_DestroyTexture(texture);
	surface = TTF_RenderText_Blended_Wrapped(font, text.c_str(), color, wrapping);
	SDL_SetSurfaceAlphaMod(surface, alpha);
	texture = SDL_CreateTextureFromSurface(Engine::GetInstance()->GetRenderer(), surface);
	SDL_FreeSurface(surface);
	SDL_QueryTexture(texture, NULL, NULL, &srcRect->w, &srcRect->h);
	SDL_QueryTexture(texture, NULL, NULL, &dstRect->w, &dstRect->h);
	Scale(scaling);
}

void Text::SetOptions(unsigned char options)
{
	text = typewriterText;
	this->alpha = 255;
	if (options & OpFadeIn)
	{
		this->alpha = 0;
	}
	if (options & OpTypewriter)
	{
		typewriterText = text;
		text = "";
	}
	this->options = options;
	isDirty = true;
}