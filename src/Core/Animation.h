#pragma once

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
	Animation(Texture::ID id, int nbFrame, int frameRate, const point<int>& srcPos, const point<int>& frameSize);
	~Animation();

	// Virtual from Sprite
	void Start(); 
	void Update();
	void Stop();
	void ForceNextFrame();
	void ForceReset()						{ this->currentFrame = 0; }

	// Custom
	void Play();

	// Setters
	void SetIsLooping(bool isLooping)		{ this->isLooping = isLooping; }
	void SetSrcPos(point<int> point)		{ this->srcPos = point; }
	void SetNbFrame(int nbFrame)			{ this->nbFrame = nbFrame; }
	void SetFrameRate(int frameRate)		{ this->frameRate = frameRate; }
	void ResetCurrentFrame()				{ this->currentFrame = 0; NextFrame(); }

	// Getter
	bool GetIsPlaying()						{ return this->isPlaying; }
	const bool GetIsFinished()				{ return currentFrame == nbFrame - 1; }

private:
	void NextFrame();
	bool isPlaying;
	bool isLooping;
	int nbFrame;
	int frameRate; 
	int currentFrame;
	float currentTime;
	point<int> srcPos;
	point<int> frameSize;
};

