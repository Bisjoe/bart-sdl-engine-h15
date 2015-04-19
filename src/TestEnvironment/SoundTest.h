#pragma once

#include "Common.h"
#include "Component.h"

//Sound refers to a single sound instance
//SFX refers to all sounds

//SFX//
//1 - Plays Sound
//2 - 100% Sfx Volume
//3 - 50% Sfx Volume
//4 - Pauses Sfx
//5 - Resumes Sfx
//6 - Stops Sfx

//Music//
//Numpad_1 - Plays Music
//Numpad_2 - 100% Music Volume
//Numpad_3 - 50% Music Volume
//Numpad_4 - Pauses Music
//Numpad_5 - Resumes Music
//Numpad_6 - Stops Music

//Global//
//Numpad_+ - 100% Global Volume
//Numpad_- - 50% Global Volume

class SoundTest :
	public Component
{
public:
	SoundTest();
	~SoundTest();

	void Start();
	void Update();
	void Stop();

private:
};

