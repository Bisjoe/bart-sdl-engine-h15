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
	TextAnim(char* const text);
	TextAnim(char* const text, char* const font);
	TextAnim(char* const text, TextAnimType animType);
	TextAnim(char* const text, TextAnimType animType, char* const font);
	TextAnim(char* const text, TextAnimType animType, char* const font, const int fontSize);
	TextAnim(char* const text, TextAnimType animType, char* const font, const int fontSize, const int x, const int y);
	~TextAnim();

	void Play();

private:
	bool animationStarted;
	point<int> origin;
	TextAnimType animType;
	float currentTime;
	int frameRate;
	char* animText;
	int currentI;

	void Start();
	void Update();
	void Stop();

	void SetNextText();
	void SetNextLetter();
	void SetNextWord();
	void GetAnimation();
	void LetterAnim();
	void LineAnim();
	void WordAnim();

protected:
	void Init();
	
};

