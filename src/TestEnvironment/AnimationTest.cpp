#include "AnimationTest.h"
#include "Libraries.h"

AnimationTest::AnimationTest()
: Animation(Texture::ID::Gimmick, WALK_NB_FRAME(), ANIM_DEFAULT_SPEED, WALK_START_SRC(), FRAME_SIZE())
, currentState(WALK)
{
	//Start the animation on creation
	this->Play();
	//Make it loop
	this->SetIsLooping(true);
}

//Really basic animation state change
//You'd want to use another system to store an object's multiple animations
void AnimationTest::changeState(state newState)
{
	if (this->currentState != newState)
	{
		switch (newState)
		{
		case IDLE:
			this->SetSrcPos(IDLE_START_SRC());
			this->SetNbFrame(IDLE_NB_FRAME());
			this->SetFrameRate(3);
			//Using varying frame rates cause issues since we won't instantly change to the other frame.
			break;
		case WALK:
			this->SetSrcPos(WALK_START_SRC());
			this->SetNbFrame(WALK_NB_FRAME());
			this->SetFrameRate(ANIM_DEFAULT_SPEED);
			break;
		case DIZZY:
			this->SetSrcPos(DIZZY_START_SRC());
			this->SetNbFrame(DIZZY_NB_FRAME());
			this->SetFrameRate(ANIM_DEFAULT_SPEED);
			break;
		default:
			break;
		}
		//It's important to reset back to the first frame on change
		this->currentState = newState;
		this->ResetCurrentFrame();
	}
}

void AnimationTest::Update()
{
	//Very important, otherwise our animation won't update itself
	Animation::Update();

	//Don't mind the brackets. Simply tried to save some screen space.
	//Press Space to Pause & Resume
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_SPACE)){
		if (this->GetIsPlaying()){
			this->Stop(); }
		else {
			this->Play();}
	}
	//Press A for Idle
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_A)){
		changeState(IDLE);
	}
	//Press B for Walk
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_B)){
		changeState(WALK);
	}
	//Press C for Dizzy
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_C)){
		changeState(DIZZY);
	}

}

AnimationTest::~AnimationTest()
{

}
