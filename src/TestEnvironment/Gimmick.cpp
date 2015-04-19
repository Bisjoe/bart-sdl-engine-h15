#include "Gimmick.h"
#include "Libraries.h"

// First 'Clean & Simple' iteration

Gimmick::Gimmick()
	: Animation("gimmick.png", 6, 18, point<int>(2, 24), point<int>(16, 19))
{
	// Start the animation on creation
	this->Play();
	// Make it loop
	this->SetIsLooping(true);
}

void Gimmick::Update()
{
	Animation::Update();

	// Press Space to Pause & Resume
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_SPACE))
	{
		if (this->GetIsPlaying())
		{
			this->Stop();
		}
		else
		{
			this->Play();
		}
	}
	
}

Gimmick::~Gimmick()
{
}
