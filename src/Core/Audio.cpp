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
		Mix_AllocateChannels(SOUND_COUNT);
	}
	for (int i = 0; i < SOUND_COUNT; ++i)
	{
		sfxList[i] = DEFAULT_SFX;
	}
}

Audio::~Audio()
{
	FreeAllAudio();
	Mix_CloseAudio();
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
			std::cout << "Error while trying to play music, ERROR: %s\n", Mix_GetError(); // Doesn't work properly for reason yet unknown (never show the error message)
		}
	}
}

void Audio::AddSoundToList(char* const filePath)
{
	for (int i = 0; i < SOUND_COUNT; ++i)
	{
		if (sfxList[i].used == false)
		{
			if (!(sfxList[i].chunk = Mix_LoadWAV(filePath)))
			{
				std::cout << "New SoundFX could not be load, ERROR: %s\n", Mix_GetError();
				return;
			}
			else
			{
				sfxList[i].used = true;
				sfxList[i].filePath = filePath;
				return;
			}
		}
	}
	std::cout << "ERROR: Max number of sounds reached. Use OverrideSoundInList instead." << std::endl;
}

void Audio::OverrideSoundInList(char* const newFilePath, char* const oldFilePath)
{
	for (int i = 0; i < SOUND_COUNT; ++i)
	{
		if (sfxList[i].used != false) {
			if ((strcmp(sfxList[i].filePath, oldFilePath)) == 0)
			{
				if (!(sfxList[i].chunk = Mix_LoadWAV(newFilePath))) 
				{
					std::cout << "New SoundFX could not be load, ERROR: %s\n", Mix_GetError();
					return;
				}
				else
				{
					sfxList[i].filePath = newFilePath;
					return;
				}
			}
		}
	}
	std::cout << "ERROR: File to replace not found in list." << std::endl;
}

void Audio::removeSound(char* const filePath)
{
	for (int i = 0; i < SOUND_COUNT; ++i)
	{
		if (sfxList[i].used != false)
		{
			if ((strcmp(sfxList[i].filePath, filePath)) == 0)
			{
				Mix_FreeChunk(sfxList[i].chunk);
				sfxList[i] = DEFAULT_SFX;
				return;
			}
		}
	}
	std::cout << "ERROR: File to remove not found in list." << std::endl;
}

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

void Audio::FreeAllAudio()
{
	Mix_FreeMusic(music);
	FreeSfxList();
}

void Audio::FreeSfxList()
{
	for (int i = CHANNELS_COUNT; i >= 0; --i)
	{
		if (sfxList[i].used != false) {
			Mix_FreeChunk(sfxList[i].chunk);
			sfxList[i] = DEFAULT_SFX;
		}
	}
}