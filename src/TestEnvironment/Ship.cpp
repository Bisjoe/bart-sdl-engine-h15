#include "Ship.h"

const float Ship::SPEED = 0.1f;

Ship::Ship()
	: Sprite("ship.jpg")
	, currentX(0)
	, currentY(0)
{
}

Ship::~Ship()
{
}

void Ship::Start()
{
}

void Ship::Update()
{
	if (Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_SPACE))
	{
		currentX += SPEED;
		currentY += SPEED;
		SetPosition(currentX, currentY);
	}
}

void Ship::Stop()
{
}
