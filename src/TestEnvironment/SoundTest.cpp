#include "SoundTest.h"
#include "Libraries.h"

SoundTest::SoundTest()
{
}

SoundTest::~SoundTest()
{
}

void SoundTest::Start()
{
}

void SoundTest::Update()
{
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_1))
	{
		AudioSys->PlaySound(Sounds->Get(Sound::ID::EnemyHit));
	}
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_2))
	{
		AudioSys->SetSfxVolume(100);
	}
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_3))
	{
		AudioSys->SetSfxVolume(50);
	}
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_4))
	{
		AudioSys->PauseSfx();
	}
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_5))
	{
		AudioSys->ResumeSfx();
	}
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_6))
	{
		AudioSys->StopSfx();
	}
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_KP_1))
	{
		AudioSys->PlayMusic(Musics->Get(Music::ID::TestMusic));
	}
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_KP_2))
	{
		AudioSys->SetMusicVolume(100);
	}
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_KP_3))
	{
		AudioSys->SetMusicVolume(50);
	}
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_KP_4))
	{
		AudioSys->PauseMusic();
	}
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_KP_5))
	{
		AudioSys->ResumeMusic();
	}
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_KP_6))
	{
		AudioSys->StopMusic();
	}
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_KP_PLUS))
	{
		AudioSys->SetGlobalVolume(100);
	}
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_KP_MINUS))
	{
		AudioSys->SetGlobalVolume(50);
	}
}

void SoundTest::Stop()
{
}
