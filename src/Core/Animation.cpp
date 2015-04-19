#include "Animation.h"

/**
	==============================
	Default Animation constructor
	------------------------------
	[!] Should never be used directly
**/
Animation::Animation()
	: Sprite()
	, isPlaying(false)
	, isLooping(false)
	, nbFrame(0)
	, frameRate(DEFAULT_FRAMERATE)
	, currentTime(0)
	, currentFrame(0)
	, srcPos()
	, frameSize()
{
}

/** 
	==============================
	All of animated sprite's states should be contained within the same sprite sheet.
	You should line up horizontaly all of an animation's frames.
	------------------------------
	Properties:
		@filepath - The path to your spritesheet, also serve as it's ID
		@nbFrame - Your animation's number of frames
		@frameRate - Your animation's playback speed
		@srcPos - The animation's starting (x,y) position from the Sprite Sheet
		@srcSize - The animation's frameSize in width/height
	------------------------------
	[!] WARNING: Non-Consistent FrameSizes are not supported as of now.
		If you happen to have an offset between each frames on your sprite sheet, as of now it must be consistent.

**/
Animation::Animation(std::string filepath, int nbFrame, int frameRate, const point<int>& srcPos, const point<int>& frameSize)
	: Sprite(filepath, srcPos, frameSize)
	, isPlaying(false)
	, isLooping(false)
	, nbFrame(nbFrame)
	, frameRate(frameRate)
	, currentTime(0)
	, currentFrame(0)
	, srcPos(srcPos)
	, frameSize(frameSize)
{
	SetSrcFrame(
		srcPos.x, srcPos.y,
		frameSize.x, frameSize.y);
}

Animation::~Animation()
{

}


void Animation::Update()
{
	if (isPlaying)
	{
		float dt = DTime;
		currentTime += dt;
		if (currentTime >= 1.0f / frameRate)
		{
			SetSrcFrame(
				srcPos.x + currentFrame * frameSize.x,
				srcPos.y,
				frameSize.x, frameSize.y);
			if (currentFrame < nbFrame-1)
			{
				currentFrame++;
			}
			else
			{
				currentFrame = 0;
				if (!isLooping)
				{
					Stop();
				}
			}
			currentTime = 0;
		}
	}
}

void Animation::Start()
{
	
}

void Animation::Stop()
{
	isPlaying = false;
}

void Animation::Play()
{
	SetSrcFrame(
		srcPos.x,
		srcPos.y,
		frameSize.x, frameSize.y);

	isPlaying = true;
}
