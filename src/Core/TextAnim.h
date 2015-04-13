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
	TextAnim(char* const text, TextAnimType animType);
	TextAnim(char* const text);
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
	void GetAnimation();
	void LetterAnim();
	void LineAnim();
	void WordAnim();

protected:
	void Init();
	
};

