#include "TextAnim.h"

TextAnim::TextAnim(Str text)
	: Text()
	, animText(text)
	, animType(LETTER)
	, currentTime(0)
	, frameRate(DEFAULT_FRAMERATE)
	, animationStarted(false)
{
	Init(DEFAULT_TEXT_FONT, DEFAULT_TEXT_FONTSIZE, 0, 0, DEFAULT_TEXT_COLOR);
}

TextAnim::TextAnim(Str text, Str font)
	: Text()
	, animText(text)
	, animType(LETTER)
	, currentTime(0)
	, frameRate(DEFAULT_FRAMERATE)
	, animationStarted(false)
{
	Init(font, DEFAULT_TEXT_FONTSIZE, 0, 0, DEFAULT_TEXT_COLOR);
}

TextAnim::TextAnim(Str text, TextAnimType animType)
	: Text()
	, animText(text)
	, animType(animType)
	, currentTime(0)
	, frameRate(DEFAULT_FRAMERATE)
	, animationStarted(false)
{
	Init(DEFAULT_TEXT_FONT, DEFAULT_TEXT_FONTSIZE, 0, 0, DEFAULT_TEXT_COLOR);
}

TextAnim::TextAnim(Str text, TextAnimType animType, Str font)
	: Text()
	, animText(text)
	, animType(animType)
	, currentTime(0)
	, frameRate(DEFAULT_FRAMERATE)
	, animationStarted(false)
{
	Init(font, DEFAULT_TEXT_FONTSIZE, 0, 0, DEFAULT_TEXT_COLOR);
}

TextAnim::TextAnim(Str text, TextAnimType animType, Str font, int fontSize)
	: Text()
	, animText(text)
	, animType(animType)
	, currentTime(0)
	, frameRate(DEFAULT_FRAMERATE)
	, animationStarted(false)
{
	Init(font, fontSize, 0, 0, DEFAULT_TEXT_COLOR);
}

TextAnim::TextAnim(Str text, TextAnimType animType, Str font, int fontSize, int x, int y)
	: Text(x, y)
	, animText(text)
	, animType(animType)
	, currentTime(0)
	, frameRate(DEFAULT_FRAMERATE)
	, animationStarted(false)
{
	Init(font, fontSize, x, y, DEFAULT_TEXT_COLOR);
}

TextAnim::TextAnim(Str text, TextAnimType animType, Str font, int fontSize, int x, int y, SDL_Color color)
	: Text(x, y)
	, animText(text)
	, animType(animType)
	, currentTime(0)
	, frameRate(DEFAULT_FRAMERATE)
	, animationStarted(false)
{
	Init(font, fontSize, x, y, color);
}

TextAnim::TextAnim(Str text, TextAnimType animType, Str font, int fontSize, int x, int y, DefaultColor color)
	: Text(x, y)
	, animText(text)
	, animType(animType)
	, currentTime(0)
	, frameRate(DEFAULT_FRAMERATE)
	, animationStarted(false)
{
	Init(font, fontSize, x, y, GetColor(color));
}


TextAnim::~TextAnim()
{
	
}

void TextAnim::Init(Str font, int fontSize, int x, int y, SDL_Color color)
{
	SetTextColor(color);
	SetFontsize(fontSize);
	SetFont(font);
	origin = { x, y };
}

void TextAnim::Start()
{

}

void TextAnim::Play()
{
	animationStarted = true;
}

void TextAnim::Update()
{
	if (elemInList > 0)
		UpdateFadeIn();

	if (animationStarted)
	{
		float dt = Engine::GetInstance()->GetTimer()->GetDeltaTime();
		currentTime += dt;
		if (currentTime >= 0.5f)
		{
			SetNextText(), 
			currentTime = 0;
		}
	}
}

void TextAnim::Stop()
{
	animationStarted = false;
}

void TextAnim::SetNextText() 
{
	switch (animType)
	{
	case(WORD) :
		SetNextWord();
		break;
	case(LINE) :
		AddToTxtsList(animText, origin.x, origin.y);
		Stop();
		break;
	case(LETTER) :
		SetNextLetter();
		break;
	default:
		break;
	}
}

void TextAnim::SetNextLetter()
{
	if (animText[0] != '\0')
	{
		if (animText[0] != ' ')
		{
			char s[2];
			s[1] = '\0';
			s[0] = animText[0];
			AddToTxtsList(s, (GetTextSize().x + origin.x), origin.y);
		}
		else
		{
			char s[3];
			s[2] = '\0';
			s[1] = animText[1];
			s[0] = animText[0];
			AddToTxtsList(s, (GetTextSize().x + origin.x), origin.y);
			animText++;
		}
	}
	else
	{
		Stop();
	}
	animText++;
}

void TextAnim::SetNextWord() 
{
	bool kill = false;
	int i = 0;

	Str pos = strchr(animText, ' ');
	if (pos) 
	{
		i = (size_t)(pos - animText) + 1;
	}
	else 
	{
		i = strlen(animText);
	}

	char s[128];
	strncpy_s(s, animText, i);

	AddToTxtsList(s, (GetTextSize().x + origin.x), origin.y);

	animText += i;

	if (kill)
		Stop();
}