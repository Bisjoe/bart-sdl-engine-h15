#include "Ship.h"
#include "Libraries.h"
/*
const float Ship::SPEED = 100.0f;

Ship::Ship()
	: Sprite("ship.jpg")
	, currentX(0)
	, currentY(0)
	, currentTime(0)
{
}

Ship::Ship(int x, int y)
	: Sprite("ship.jpg")
	, currentX(0)
	, currentY(0)
	, currentTime(0)
{
	this->SetPosition(x, y);
}

Ship::~Ship()
{
}

void Ship::Start()
{
}

void Ship::Update()
{
	float dt = Engine::GetInstance()->GetTimer()->GetDeltaTime();

	if (Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_SPACE))
	{
		// Opération time Base
		currentX += SPEED * dt;
		currentY += SPEED * dt;
		SetPosition(currentX, currentY);
		std::cout << "deltaTime" << SPEED*dt;
	}
}

void Ship::Stop()
{
}
*/