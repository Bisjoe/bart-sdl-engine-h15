#include "Audio.h"
#include <iostream>
#pragma warning(disable: 4996)

Audio::Audio()
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
	{
		printf("SDL Mixer could not initialize! SDL_Mixer Error: %s\n", Mix_GetError());
	}
	else
	{
		Mix_AllocateChannels(CHANNEL_COUNT_MAX);
	}
}

Audio::~Audio()
{
	Mix_CloseAudio();
}


/////////////////////
//Volume validation//
/////////////////////
//All functions that alter volume level use this function's return value.
//Channel volumes range from 0 (0% volume) to the default value of 128 (100% volume).
//It is much easier to handle volume in percentages than in arbitrary values.
//We clamp the value between 0-128 based upon the passed volumeLevel percentage.
int Audio::Volume(int volumeLevel)
{
	volumeLevel = (volumeLevel / 100.f) * 128;
	return volumeLevel < 0 ? 0
			: volumeLevel > 128 ? 128
			: volumeLevel;
}

void Audio::SetSfxVolume(int volumeLevel)
{
	Mix_Volume(-1, Volume(volumeLevel));
}

void Audio::SetMusicVolume(int volumeLevel)
{
	Mix_VolumeMusic(Volume(volumeLevel));
}

void Audio::PlaySound(Mix_Chunk* chunk) {
	if (Mix_PlayChannel(-1, chunk, 0) == -1)
	{
		printf("Error while trying to play sound, ERROR: %s\n", Mix_GetError());
	}
}

void Audio::PlaySound(Mix_Chunk* chunk, int playCount) {
	if (Mix_PlayChannel(-1, chunk, playCount - 1) == -1)
	{
		printf("Error while trying to play sound, ERROR: %s\n", Mix_GetError());
	}
}

void Audio::PauseSfx()
{
	Mix_Pause(-1);
}

void Audio::ResumeSfx()
{
	Mix_Resume(-1);
}

void Audio::StopSfx()
{
	Mix_HaltChannel(-1);
}

void Audio::PlayMusic(Mix_Music* music) 
{
	if (Mix_PlayMusic(music, -1) == -1)
	{
		printf("Error while trying to play music, ERROR: %s\n", Mix_GetError());
	}
}

void Audio::PauseMusic()
{
	if (Mix_PlayingMusic() == 1)
	{
		Mix_PauseMusic();
	}
}

void Audio::ResumeMusic()
{
	if (Mix_PausedMusic() == 1)
	{
		Mix_ResumeMusic();
	}
}

void Audio::StopMusic()
{
	if (Mix_PlayingMusic() == 1)
	{
		Mix_HaltMusic();
	}
}