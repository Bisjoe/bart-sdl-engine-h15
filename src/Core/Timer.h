//=======================================================================================
// GameTimer.cpp by Frank Luna (C) 2008 All Rights Reserved.
//=======================================================================================

#pragma once
#include "Common.h"

class Timer
{
public:
	Timer();
	~Timer();

	float GetGameTime()const;
	float GetDeltaTime()const;

	// Call before message loop.
	void Reset();
	// Call when unpaused.
	void Start();
	// Call when paused.
	void Stop();
	// Call every frame.
	void Tick();

private:
	int mSeconds;
	double mSecondsPerCount;
	double mDeltaTime;

	__int64 mBaseTime;
	__int64 mPausedTime;
	__int64 mStopTime;
	__int64 mPrevTime;
	__int64 mCurrTime;

	bool mStopped;
};