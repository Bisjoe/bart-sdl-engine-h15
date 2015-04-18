#include "Audio.h"
#include <iostream>
#pragma warning(disable: 4996)

Audio* Audio::audioInst = 0;


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
/*	FreeAllAudio();
	Mix_CloseAudio();*/
}

int Audio::CheckVolume(int volumeLevel)
{
	if (volumeLevel < 0)
	{
		return 0;
	}
	else if (volumeLevel > 100)
	{
		return 100;
	}
	else
	{
		return volumeLevel;
	}
}

void Audio::SetMusicVolume(int volumeLevel)
{
	Mix_VolumeMusic(CheckVolume(volumeLevel));
}
/*
void Audio::SetSfxVolume(char* const filePath, int volumeLevel)
{
	for (int i = 0; i < SOUND_COUNT; ++i)
	{
		if (sfxList[i].used != false)
		{
			if ((strcmp(sfxList[i].filePath, filePath)) == 0)
			{
				Mix_VolumeChunk(sfxList[i].chunk, CheckVolume(volumeLevel));
			}
			return;
		}
	}
	std::cout << "Error while trying to change volume: File not found!" << std::endl;
}

void Audio::SetAllSfxVolume(const int volumeLevel)
{
	for (int i = 0; i < SOUND_COUNT; ++i)
	{
		if (sfxList[i].used != false)
		{
			Mix_VolumeChunk(sfxList[i].chunk, CheckVolume(volumeLevel));
		}
	}
}

void Audio::PlayMusic(char* const filePath)
{
	PlayMusic(filePath, -1);
}

void Audio::PlayMusic(char* const filePath, const int playCount)
{
	music = Mix_LoadMUS(filePath);
	if (!music) 
	{
		std::cout << "Music could not be load, ERROR: %s\n", Mix_GetError();
	}
	else
	{
		if (Mix_PlayMusic(music, playCount) == -1)
		{
			std::cout << "Error while trying to play music, ERROR: %s\n", Mix_GetError();
		}
	}
}*/

void Audio::PlayMusic(Mix_Music* music) 
{
	if (Mix_PlayMusic(music, -1) == -1)
	{
		printf("Error while trying to play music, ERROR: %s\n", Mix_GetError());
	}
}
/*
// By default, does an infinite loop
void Audio::PlaySound(char* const filePath)
{
	PlaySound(filePath, -1);
}


void Audio::PlaySound(char* const filePath, const int playCount)
{
	for (int i = 0; i < SOUND_COUNT; ++i)
	{
		if (sfxList[i].used != false)
		{
			if ((strcmp(sfxList[i].filePath, filePath)) == 0)
			{	
				Mix_PlayChannel(-1, sfxList[i].chunk, playCount-1); // playCount works in base 0. -1 is so it works in base one (enter 1 to play once, 0 to infinity, etc (less confusing when calling the function))
				return;
			}
		}
	}
	std::cout << "ERROR: File to play not found in list." << std::endl;
}
*/
// Default will play once
void Audio::PlaySound(Mix_Chunk* chunk) {
	Mix_PlayChannel(-1, chunk, 0);
}

void Audio::PlaySound(Mix_Chunk* chunk, int playCount) {
	Mix_PlayChannel(-1, chunk, playCount-1);
}

/*
void Audio::FreeAllAudio()
{
	Mix_FreeMusic(music);
	FreeSfxList();
}
*/

/*
void Audio::FreeSfxList()
{
	for (int i = CHANNELS_COUNT; i >= 0; --i)
	{
		if (sfxList[i].used != false) {
			Mix_FreeChunk(sfxList[i].chunk);
			sfxList[i] = DEFAULT_SFX;
		}
	}
}*/