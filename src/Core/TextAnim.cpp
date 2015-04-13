#include "TextAnim.h"

TextAnim::TextAnim(char* const text, TextAnimType animType)
	: Text()
	, animText(text)
	, animType(animType)
	, currentTime(0)
	, frameRate(DEFAULT_FRAMERATE)
	, animationStarted(false)
{
}

TextAnim::TextAnim(char* const text)
	: Text()
	, animText(text)
	, animType(LETTER)
	, currentTime(0)
	, frameRate(DEFAULT_FRAMERATE)
	, animationStarted(false)
{
}


TextAnim::~TextAnim()
{

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

void TextAnim::LetterAnim()
{

}

void TextAnim::LineAnim()
{

}

void TextAnim::WordAnim()
{

}

void TextAnim::SetNextText() 
{
	if (animText[0] != '\0')
	{
		if (animText[0] != ' ')
		{
			point<int> pos = GetTextSize();
			char s[2];
			s[1] = '\0';
			s[0] = animText[0];
			AddToTxtsList(s, (pos.x + origin.x), origin.y);
		}
		else
		{
			point<int> pos = GetTextSize();
			char s[3];
			s[2] = '\0';
			s[1] = animText[1];
			s[0] = animText[0];
			AddToTxtsList(s, (pos.x + origin.x), origin.y);
			animText++;
		}
	}
	else
	{
		Stop();
	}
	animText++;
}

void TextAnim::GetAnimation() 
{
	switch (animType)
	{
	case(WORD):

		break;
	case(LINE):
		break;
	case(LETTER):
		break;
	default:
		break;
	}

}
