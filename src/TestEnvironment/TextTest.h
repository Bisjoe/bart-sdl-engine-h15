#pragma once

#include "Common.h"
#include "Component.h"
#include "Text.h"

//F1 - FadeIn(Red)
//F2 - FadeOut(Blue)
//F3 - Flashing(Yellow)
//F4 - Typewriter(Green)
//F5 - Flashing & Typewriter(White)
//F6 - Scale1x
//F7 - Scale0.75x
//F8 - ShortText
//F9 - LongText

class TextTest :
	public Text
{
public:
	TextTest();
	~TextTest();

	void Start();
	void Update();
	void Stop();

private:
};

