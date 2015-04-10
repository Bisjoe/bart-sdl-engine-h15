#pragma once
#include "Common.h"
#include "Engine.h"

/**  =====================================================

	IN CASE OF DLL ERROR:
		Add the DLL from the folder ..\..\bart-sdl-engine-h15\dependencies\SDL2_mixer-2.0.0\lib\x86 into your Debug folder

	 SDL_Mixer Documentation : http://jcatki.no-ip.org:8080/SDL_mixer/SDL_mixer.html
	 ======================================
	 Positive point - Works
	 Negative point - So far only the music has been implemented and it's impossible to play more than one Sound/Music at the same time 
	 (need to implement "chunk" / SoundFX to allow multiple sound at the same time. Comming soon in an engine near you (hopefully))
**/
class Audio :
	public Component
{
private:
	Mix_Music* music;
	int playCount; // Number of time the music will loop before stoping. (-1 = infinite loop)

	virtual void Start();
	virtual void Update();
	virtual void Stop();

public:
	Audio(char* const filePath, const int playCount);
	~Audio();

	static void SetVolume(const int volumeLevel) {
		Mix_VolumeMusic(volumeLevel);
	}
};

