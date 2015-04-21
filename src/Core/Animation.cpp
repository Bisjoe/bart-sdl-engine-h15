#include "Animation.h"

/////////////////////////////////
//Default Animation constructor//
/////////////////////////////////
//Shouldn't ever be used directly
////////////////////////////////
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

//Sprite::Sprite(Texture::ID id, point<int> srcPos, point<int> srcSize)

/////////////////////////
//Animation Constructor//
/////////////////////////
//All of animated sprite's states should be contained within the same sprite sheet.
//You should line up horizontaly all of an animation's frames.
//If you happen to have an offset between each frames on your sprite sheet, it should be consistent.
//@id - This is your "Sprite sheet" ID
//@nbFrame - Your animation's number of frames
//@frameRate - Your animation's playback speed
//@srcPos - The animation's starting (X,Y) position from the Sprite Sheet
//@srcSize - The animation's frameSize in width/height
//WARNING: Non-Consistent FrameSize are not supported as of now.
////////////////////////////////////////////////////////////////
Animation::Animation(Texture::ID id, int nbFrame, int frameRate, const point<int>& srcPos, const point<int>& frameSize)
	: Sprite(id, srcPos, frameSize)
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
		float dt = Engine::GetInstance()->GetTimer()->GetDeltaTime();
		currentTime += dt;
		if (currentTime >= 1.0f / frameRate)
		{
			NextFrame();
		}
	}
}

void Animation::NextFrame()
{
	SetSrcFrame(
		srcPos.x + currentFrame * frameSize.x,
		srcPos.y,
		frameSize.x, frameSize.y);
	if (currentFrame < nbFrame - 1)
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
