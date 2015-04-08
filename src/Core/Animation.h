#pragma once

//Right now the current implentation:
//[-] Does not support varying frameSizes animations. *Quite easy to implement
//[-] Does not support offsets between frames. *You'd only need this if you had varying frameSizes... easy to implement.
//[-] Sucks.
//[+] Meh, it does the job.

#define ANIM_SLOW_SPEED 6
#define ANIM_DEFAULT_SPEED 12
#define ANIM_FAST_SPEED 18

#include "Common.h"
#include "Sprite.h"

class Animation :
	public Sprite
{
public:
	Animation();
	Animation(std::string filePath, int nbFrame, int frameRate, const point<int>& frameSize, const point<int>& startSrcPos);
	~Animation();

	// Virtual from Sprite
	void Start(); 
	void Update();
	void Stop();

	// Custom
	void Play();

private:
	bool isPlaying;
	bool isLooping;
	int nbFrame;
	int frameRate; 
	int currentFrame;
	float currentTime;
	point<int> startSrcPos;
	point<int> frameSize;

protected:
	//Setters
	void SetIsLooping(bool isLooping)		{ this->isLooping = isLooping;}
	void SetStartSrcPos(point<int> point)	{ this->startSrcPos = point;  }
	void SetNbFrame(int nbFrame)			{ this->nbFrame = nbFrame;	  }
	void SetFrameRate(int frameRate)		{ this->frameRate = frameRate;}
	void ResetCurrentFrame()				{ this->currentFrame = 0;	  }

	//Getter
	bool GetIsPlaying()						{ return this->isPlaying;	  }
};

