#pragma once

#define ANIM_SPEED_SLOW 6
#define ANIM_SPEED_DEFAULT 12
#define ANIM_SPEED_FAST 18

#include "Common.h"
#include "Sprite.h"

class Animation :
	public Sprite
{
public:
	Animation();
	Animation(std::string filepath, int nbFrame, int frameRate, const point<int>& srcPos, const point<int>& frameSize);
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
	point<int> srcPos;
	point<int> frameSize;

protected:
	//Setters
	void SetIsLooping(bool isLooping)		{ this->isLooping = isLooping;}
	void SetSrcPos(point<int> point)		{ this->srcPos = point;}
	void SetNbFrame(int nbFrame)			{ this->nbFrame = nbFrame;}
	void SetFrameRate(int frameRate)		{ this->frameRate = frameRate;}
	void ResetCurrentFrame()				{ this->currentFrame = 0;}

	//Getter
	bool GetIsPlaying()						{ return this->isPlaying;}
};

