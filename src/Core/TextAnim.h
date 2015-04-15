#pragma once
#include "Common.h"
#include "Text.h"

enum TextAnimType {
	LETTER,
	LINE,
	WORD,
};


class TextAnim :
	public Text
{
public:
	TextAnim(Str text);
	TextAnim(Str text, Str font);
	TextAnim(Str text, TextAnimType animType);
	TextAnim(Str text, TextAnimType animType, Str font);
	TextAnim(Str text, TextAnimType animType, Str font, int fontSize);
	TextAnim(Str text, TextAnimType animType, Str font, int fontSize, int x, int y);
	TextAnim(Str text, TextAnimType animType, Str font, int fontSize, int x, int y, SDL_Color color);
	TextAnim(Str text, TextAnimType animType, Str font, int fontSize, int x, int y, DefaultColor color);
	~TextAnim();

	void Play();

private:
	bool animationStarted;
	point<int> origin;
	TextAnimType animType;
	float currentTime;
	int frameRate;
	Str animText;
	int currentI;

	void Start();
	void Update();
	void Stop();

	void SetNextText();
	void SetNextLetter();
	void SetNextWord();

protected:
	void Init(Str font, int fontSize, int x, int y, SDL_Color color);
};

