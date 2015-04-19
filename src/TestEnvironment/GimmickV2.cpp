#include "GimmickV2.h"
#include "Libraries.h"

GimmickV2::GimmickV2()
: Animation(t_gimmick, WALK_NB_FRAME(), ANIM_SPEED_DEFAULT, WALK_START_SRC(), FRAME_SIZE())
, currentState(IDLE)
{
	//Start the animation on creation
	this->Play();
	//Make it loop
	this->SetIsLooping(true);
}

//Really basic animation state change
//You'd want to use another system to store an object's multiple animations
void GimmickV2::changeState(state newState)
{
	if (this->currentState != newState)
	{
		switch (newState)
		{
		case IDLE:
			this->SetSrcPos(IDLE_START_SRC());
			this->SetNbFrame(IDLE_NB_FRAME());
			this->SetFrameRate(3);
			// Using varying frame rates cause issues since we won't instantly change to the other frame.
			break;
		case WALK:
			this->SetSrcPos(WALK_START_SRC());
			this->SetNbFrame(WALK_NB_FRAME());
			this->SetFrameRate(ANIM_SPEED_DEFAULT);
			break;
		case DIZZY:
			this->SetSrcPos(DIZZY_START_SRC());
			this->SetNbFrame(DIZZY_NB_FRAME());
			this->SetFrameRate(ANIM_SPEED_DEFAULT);
			break;
		default:
			break;
		}
		// It's important to reset back to the first frame on change
		this->currentState = newState;
		this->ResetCurrentFrame();
	}
}

void GimmickV2::Update()
{
	// [!] Very important, otherwise the animation won't update itself
	Animation::Update();

	// Press Space to Pause & Resume
	if (ThisKeyPressed(SDL_SCANCODE_SPACE)) 
	{
		if (this->GetIsPlaying()){
			this->Stop(); }
		else {
			this->Play();}
	}
	// Press 1 for Idle
	if (ThisKeyPressed(SDL_SCANCODE_1)) 
	{
		changeState(IDLE);
	}
	// Press 2 for Walk
	if (ThisKeyPressed(SDL_SCANCODE_2)) 
	{
		changeState(WALK);
	}
	// Press 3 for Dizzy
	if (ThisKeyPressed(SDL_SCANCODE_3)) 
	{
		changeState(DIZZY);
	}

}

GimmickV2::~GimmickV2()
{

}
