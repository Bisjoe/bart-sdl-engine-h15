#pragma once
#include "Common.h"

/**  =====================================================
	 SDL_Mixer Documentation : http://jcatki.no-ip.org:8080/SDL_mixer/SDL_mixer.html
	 ======================================
	IMPORTANT NOTE:
		Doesn't work with every file (even if the extension is supported), in case of doubt try another one.
		If the file turns out to be problematic try going to http://mp3cut.net/, upload your file and redownload it from there (with or without editing it) and in 
		the appropriate format (mp3 or wav), should work after.

		-------------------------------------------------
	HOW IT WORKS:
	For SFX:
	- To play soundFX, first add them to the list by using AddSoundToList() and providing the file path.
	- Once in the list, every song can then be played by using the command PlaySound() with the same filePath.
	- Up to 50 sounds can be played simultaneously. 
	- If the list is full use OverrideSoundInList() to replace an existing one.
	For MUSIC:
	- Simply call the function PlayMusic(), but keep in mind that only one music can be played at any given time, calling it again will replace the one existing.
**/

#define CHANNEL_COUNT_MAX 50

class Audio
{
	friend class Engine;

private:
	Audio();
	~Audio();

	int CheckVolume(int volumeLevel);
	void FreeAllAudio();
	void FreeSfxList();

public:
	// Volumes
	void SetMusicVolume(int volumeLevel);
	void SetSfxVolume(int volumeLevel);
	void SetSfxVolume(Mix_Chunk* chunk, int volumeLevel);
	void SetSfxVolume(std::string filePath, int volumeLevel);
	void SetAllSfxVolume(int volumeLevel);
	void SetGlobalVolume(int volumeLevel);

	// Music
	void PlayMusic(std::string filePath);
	void PlayMusic(std::string filePath, int playCount);
	void PlayMusic(Mix_Music* music);

	// Sound effects
	void PlaySound(std::string filePath);
	void PlaySound(std::string filePath, int playCount);
	void PlaySound(Mix_Chunk* chunk);
	void PlaySound(Mix_Chunk* chunk, int playCount);
	
};