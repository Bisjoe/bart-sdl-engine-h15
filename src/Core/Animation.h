#pragma once

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
};

