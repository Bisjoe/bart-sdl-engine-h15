#include "TextTest.h"
#include "Libraries.h"

TextTest::TextTest()
:Text("Dolls are for overgrown dogs, not for trees.", Font::ID::Dialog, 700)
{
	SetPosition(100, 500);
}

TextTest::~TextTest()
{
}

void TextTest::Start()
{
}

void TextTest::Update()
{
	Text::Update();
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_F1))
	{
		this->SetColor(Color::RED);
		this->SetOptions(Options::OpFadeIn);
	}
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_F2))
	{
		this->SetColor(Color::BLUE);
		this->SetOptions(Options::OpFadeOut);
	}
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_F3))
	{
		this->SetColor(Color::YELLOW);
		this->SetOptions(Options::OpFlashing);
	}
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_F4))
	{
		this->SetColor(Color::GREEN);
		this->SetOptions(Options::OpTypewriter);
	}
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_F5))
	{
		this->SetColor(Color::WHITE);
		this->SetOptions(Options::OpFlashing | Options::OpTypewriter);
	}
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_F6))
	{
		this->Scale(1);
	}
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_F7))
	{
		this->Scale(0.75);
	}
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_F8))
	{
		this->SetText("Short dogs are more likely to survive in the wild");
	}
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_F9))
	{
		this->SetText("Never gamble with your giraffe's neck, it'll turn into bread crumbs for the sinful pigeons.");
	}
}

void TextTest::Stop()
{
}
