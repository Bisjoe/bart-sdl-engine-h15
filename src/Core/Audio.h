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
	- Up to 50 sounds can be played simultaneously. 
	For MUSIC:
	- Simply call the function PlayMusic(), but keep in mind that only one music can be played at any given time, calling it again will replace the existing one.
**/

#ifndef CHANNEL_COUNT_MAX
#define CHANNEL_COUNT_MAX 50
#endif

class Audio
{
	friend class Engine;
private:
	 Audio();
	 ~Audio();

	 int Volume(int volumeLevel);

public:
	// Volumes
	void SetSfxVolume(int volumeLevel);
	void SetSfxVolume(Mix_Chunk* chunk, int volumeLevel);
	void SetMusicVolume(int volumeLevel);
	void SetGlobalVolume(int volumeLevel)	{ SetMusicVolume(volumeLevel), SetSfxVolume(volumeLevel); }

	// Sound effects
	void PlaySound(Mix_Chunk* chunk);
	void PlaySound(Mix_Chunk* chunk, int playCount);
	void PauseSfx();
	void ResumeSfx();
	void StopSfx();

	// Music
	void PlayMusic(Mix_Music* music);
	void PauseMusic();
	void ResumeMusic();
	void StopMusic();

};