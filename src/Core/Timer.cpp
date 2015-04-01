//=======================================================================================
// GameTimer.cpp by Frank Luna (C) 2008 All Rights Reserved.
//=======================================================================================

#include "Timer.h"

Timer::Timer()
	: mSecondsPerCount(0.0)
	, mDeltaTime(0.0)
	, mBaseTime(0)
	, mPausedTime(0)
	, mPrevTime(0)
	, mCurrTime(0)
	, mStopped(false)
{
	__int64 countsPerSec = SDL_GetPerformanceFrequency();
	mSecondsPerCount = 1.0 / (double)countsPerSec;
}

Timer::~Timer()
{
}

// Returns the total time elapsed since reset() was called, NOT counting any
// time when the clock is stopped.
float Timer::GetGameTime()const
{
	// If we are stopped, do not count the time that has passed since we stopped.
	//
	// ----*---------------*------------------------------*------> time
	//  mBaseTime       mStopTime                      mCurrTime
	if (mStopped)
	{
		return (float)((mStopTime - mBaseTime)*mSecondsPerCount);
	}
	// The distance mCurrTime - mBaseTime includes paused time,
	// which we do not want to count.  To correct this, we can subtract 
	// the paused time from mCurrTime:  
	//
	//  (mCurrTime - mPausedTime) - mBaseTime 
	//
	//                     |<-------d------->|
	// ----*---------------*-----------------*------------*------> time
	//  mBaseTime       mStopTime        startTime     mCurrTime
	else
	{
		return (float)(((mCurrTime - mPausedTime) - mBaseTime)*mSecondsPerCount);
	}
}

float Timer::GetDeltaTime()const
{
	return (float)mDeltaTime;
}

void Timer::Reset()
{
	__int64 currTime = SDL_GetPerformanceCounter();

	mBaseTime = currTime;
	mPrevTime = currTime;
	mStopTime = 0;
	mStopped = false;
}

void Timer::Start()
{
	__int64 startTime = SDL_GetPerformanceCounter();

	// Accumulate the time elapsed between stop and start pairs.
	//
	//                     |<-------d------->|
	// ----*---------------*-----------------*------------> time
	//  mBaseTime       mStopTime        startTime     
	if (mStopped)
	{
		mPausedTime += (startTime - mStopTime);

		mPrevTime = startTime;
		mStopTime = 0;
		mStopped = false;
	}
}

void Timer::Stop()
{
	if (!mStopped)
	{
		__int64 currTime = SDL_GetPerformanceCounter();
		mStopTime = currTime;
		mStopped = true;
	}
}

void Timer::Tick()
{
	if (mStopped)
	{
		mDeltaTime = 0.0;
		return;
	}

	__int64 currTime = SDL_GetPerformanceCounter();
	mCurrTime = currTime;

	// Time difference between this frame and the previous.
	mDeltaTime = (mCurrTime - mPrevTime)*mSecondsPerCount;

	// Prepare for next frame.
	mPrevTime = mCurrTime;

	// Force nonnegative.  The DXSDK's CDXUTTimer mentions that if the 
	// processor goes into a power save mode or we get shuffled to another
	// processor, then mDeltaTime can be negative.
	if (mDeltaTime < 0.0)
	{
		mDeltaTime = 0.0;
	}
}