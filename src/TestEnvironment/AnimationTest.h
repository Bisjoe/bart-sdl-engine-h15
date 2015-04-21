#pragma once
//There's a billion way to handle this but with only 3 animations this works just fine for our current purpose.
//Might want to consider another way to stock animations if you end up with 6-7 animations per actors.

#include "Common.h"
#include "Animation.h"


//Press A for Idle
//Press B for Walk
//Press C for Dizzy
//Press D for Not-Flipped
//Press E for Flipped
//Press Space to Pause/Resume

class AnimationTest :
	public Animation
{
public:
	AnimationTest();
	~AnimationTest();

	void Update();

private:

	//States used to determine which animation will take place 
	enum state { IDLE, WALK, DIZZY };
	state currentState;

	//State Setter
	void changeState(state newState);

	//This part is ugly, but at least we can use those "fake consts" in our constructor...
	const int IDLE_NB_FRAME() { return 2; }
	const int WALK_NB_FRAME() { return 6; }
	const int DIZZY_NB_FRAME() { return 2; }
	const point<int> FRAME_SIZE() { return{ 32, 38 }; };
	const point<int> IDLE_START_SRC() { return{ 4, 4 }; };
	const point<int> WALK_START_SRC() { return{ 4, 48 }; };
	const point<int> DIZZY_START_SRC() { return{ 2, 202 }; };
};

