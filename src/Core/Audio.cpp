#include "Audio.h"
#include "Engine.h"

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
	Musics->Clear();
	Sounds->Clear();
}

/**
	Validate and convert a volume given, assume in percent, 
	to the default values used by SDL_Mixer (0 (0%) to 128 (100%))
**/
int Audio::CheckVolume(int volumeLevel)
{
	volumeLevel = (volumeLevel / 100.f) * 128;
	return volumeLevel < 0 ? 0
		: volumeLevel > 128 ? 128
		: volumeLevel;
}

/**
	Change the volume of the music
	------------------------
	@volumeLevel the volume level to give, in percents
**/
void Audio::SetMusicVolume(int volumeLevel)
{
	Mix_VolumeMusic(CheckVolume(volumeLevel));
}

/**
	Change the volume of all channels
	------------------------
	@volumeLevel the volume level to give, in percents
**/
void Audio::SetSfxVolume(int volumeLevel)
{
	Mix_Volume(-1, CheckVolume(volumeLevel));
}

/**
	Change the volume of a specific SFX
	(useful to make quick correction if one sound is louder than the others (due to the file itself))
	------------------------
	@volumeLevel the volume level to give, in percents
**/
void Audio::SetSfxVolume(Mix_Chunk* chunk, int volumeLevel)
{
	Mix_VolumeChunk(chunk, CheckVolume(volumeLevel));
}

/**
	Find a file and change the volume of a specific SFX
	(useful to make quick correction if one sound is louder than the others (due to the file itself))
	------------------------
	@volumeLevel the volume level to give, in percents
**/
void Audio::SetSfxVolume(std::string filePath, int volumeLevel)
{
	Mix_VolumeChunk(Sounds->Get(filePath), CheckVolume(volumeLevel));
}

void Audio::PlayMusic(Mix_Music* music) 
{
	if (Mix_PlayMusic(music, -1) == -1)
	{
		printf("Error while trying to play music, ERROR: %s\n", Mix_GetError());
	}
}

// Default will play once
void Audio::PlaySound(std::string filePath)
{
	if (Mix_PlayChannel(-1, Sounds->LoadSound(filePath), 0) == -1)
	{
		printf("Mix_PlayChannel error: %s\n", Mix_GetError());
	}
}

void Audio::PlaySound(std::string filePath, int playCount)
{
	if (Mix_PlayChannel(-1, Sounds->LoadSound(filePath), playCount - 1) == -1)
	{
		printf("Mix_PlayChannel error: %s\n", Mix_GetError());
	}
}

void Audio::PlaySound(Mix_Chunk* chunk) {
	if (Mix_PlayChannel(-1, chunk, 0) == -1)
	{
		printf("Mix_PlayChannel error: %s\n", Mix_GetError());
	}
}

void Audio::PlaySound(Mix_Chunk* chunk, int playCount) {
	if (Mix_PlayChannel(-1, chunk, playCount-1) == -1)
	{
		printf("Mix_PlayChannel error: %s\n", Mix_GetError());
	}
}


void Audio::FreeAllAudio()
{
	
}



void Audio::FreeSfxList()
{
	
}