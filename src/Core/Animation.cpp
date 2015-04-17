#include "Animation.h"

Animation::Animation()
	: Sprite()
	, isPlaying(false)
	, isLooping(false)
	, nbFrame(0)
	, frameRate(DEFAULT_FRAMERATE)
	, currentTime(0)
	, currentFrame(0)
	, startSrcPos()
	, frameSize()
{
}

Animation::Animation(Texture::ID id, int nbFrame, int frameRate, const point<int>& frameSize, const point<int>& startSrcPos)
	: Sprite(id, startSrcPos, frameSize)
	, isPlaying(false)
	, isLooping(false)
	, nbFrame(nbFrame)
	, frameRate(frameRate)
	, currentTime(0)
	, currentFrame(0)
	, startSrcPos(startSrcPos)
	, frameSize(frameSize)
{
	SetSrcFrame(
		startSrcPos.x, startSrcPos.y,
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
			SetSrcFrame(
				startSrcPos.x + currentFrame * frameSize.x,
				startSrcPos.y,
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
		startSrcPos.x,
		startSrcPos.y,
		frameSize.x, frameSize.y);

	isPlaying = true;
}
