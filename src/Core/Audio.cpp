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


/**
	Validate and convert a volume given, assume in percent,
	to the default values used by SDL_Mixer (0 (0%) to 128 (100%))
**/
int Audio::Volume(int volumeLevel)
{
	volumeLevel = (volumeLevel / 100.f) * 128;
	return volumeLevel < 0 ? 0
			: volumeLevel > 128 ? 128
			: volumeLevel;
}


/**
	Change the volume of all channels
	------------------------
	@volumeLevel the volume level to give, in percents
**/
void Audio::SetSfxVolume(int volumeLevel)
{
	Mix_Volume(-1, Volume(volumeLevel));
}

/**
	Change the volume of a specific SFX
	(useful to make quick correction if one sound is louder than the others (due to the file itself))
	------------------------
	@volumeLevel the volume level to give, in percents
**/
void Audio::SetSfxVolume(Mix_Chunk* chunk, int volumeLevel)
{
	Mix_VolumeChunk(chunk, Volume(volumeLevel));
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