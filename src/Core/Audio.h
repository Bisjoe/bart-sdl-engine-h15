#pragma once
#include "Common.h"
#include "Engine.h"

/**  =====================================================
	IN CASE OF DLL ERROR:
		Add the DLL from the folder ..\..\bart-sdl-engine-h15\dependencies\SDL2_mixer-2.0.0\lib\x86 into your Debug folder
	 SDL_Mixer Documentation : http://jcatki.no-ip.org:8080/SDL_mixer/SDL_mixer.html
	 ======================================
	 Still missing
		 PauseMusic option
		 ResumeMusic option
		 StopMusic option
		 perfect channel handling when sound are replaced or deleted

	=========================================
	IMPORTANT NOTE:
		Doesn't work with every file (even if the extension is supported), in case of doubt try another one.
		If the file turns out to be problematic try going to http://mp3cut.net/, upload your file and redownload it from there (with or without editing it) and in 
		the appropriate format (mp3 or wav), should work after.

		-------------------------------------------------
	HOW IT WORKS:
	For SFX:
	- To play soundFX, first add them to the list by using AddSoundToList() and providing the file path.
	- Once in the list, every song can then be played by using the command PlaySound() with the same filePath.
	- List can currently hold a maximum of 30 different sound and up to 16 can be played simultaneously. 
	- If the list is full use OverrideSoundInList() to replace an existing one.
	For MUSIC:
	- Simply call the function PlayMusic(), but keep in mind that only one music can be played at any given time, calling it again will replace the one existing.
**/

#ifndef SOUND_COUNT
#define SOUND_COUNT 30
#endif

// Shortcut
#ifndef AUDIO
#define AUDIO Audio::GetInstance()
#endif

#ifndef DEFAULT_SFX
#define DEFAULT_SFX { false, NULL, NULL }
#endif

struct SFX {
	bool used;
	char* filePath;
	// int channel;
	Mix_Chunk* chunk;
};

class Audio
{
public:
#pragma region SINGLETON
	static Audio* GetInstance()
	{
		if (!audioInst)
		{
			audioInst = new Audio();
		}

		return audioInst;
	}

	static void Kill()
	{
		if (audioInst)
		{
			delete audioInst;
			audioInst = NULL;
		}
	}

private:
	Audio();
	~Audio();
	static Audio* audioInst;
#pragma endregion

public:
	// Volumes
	void SetMusicVolume(int volumeLevel);
	void SetSfxVolume(char* const filePath, int volumeLevel);
	void SetAllSfxVolume(int volumeLevel);
	void SetGlobalVolume(int volumeLevel);

	// Music
	void PlayMusic(char* const filePath);
	void PlayMusic(char* const filePath, const int playCount);
	void PlayMusic(Mix_Music* music);

	// Sound effects
	void AddSoundToList(char* const filePath);
	void OverrideSoundInList(char* const newFilePath, char* const oldFilePath);
	void removeSound(char* const filePath);
	void PlaySound(char* const filePath);
	void PlaySound(char* const filePath, const int playCount);
	void PlaySound(Mix_Chunk* chunk);
	void PlaySound(Mix_Chunk* chunk, int playCount);
	

private:
	Mix_Music* music;
	SFX sfxList[SOUND_COUNT];
	int CheckVolume(int volumeLevel);
	void FreeAllAudio();
	void FreeSfxList();
};