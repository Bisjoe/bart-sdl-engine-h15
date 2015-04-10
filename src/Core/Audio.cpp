#include "Audio.h"

Audio::Audio(char* const filePath, const int playCount)
	: playCount(playCount)
{
	music = Mix_LoadMUS(filePath);
	if (!music)
		std::cout << "Music was not load, ERROR: %s\n", Mix_GetError();
}


Audio::~Audio()
{
	Mix_FreeMusic(music);
}


void Audio::Start()
{
	if (Mix_PlayMusic(music, playCount) == -1)
		std::cout << "Music did not start, ERROR: %s\n", Mix_GetError();
}

void Audio::Update()
{
	
}

void Audio::Stop()
{
	
}
