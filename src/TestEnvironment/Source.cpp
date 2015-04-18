#include "Libraries.h"
#include "Ship.h"
#include "Gimmick.h"
#include "GimmickV2.h"


typedef int* pInt;

char* const sound1 = "about_time.wav";
char* const sound2 = "enemy_hit.wav";

int main(int argc, char* args[])
{

	// Proportional resolution for NES (default: 256 * 240) (only to show it's working, default "Init()" has the same size as before (800 * 600))
	Engine::GetInstance()->Init(800, 750); 


	Textures->LoadTexture(Texture::ID::Gimmick, "Gimmick2.png");
	Textures->LoadTexture(Texture::ID::Ship, "Ship.jpg");
	Sounds->LoadSound(Sound::ID::EnemyHit, "enemy_hit.wav");
	Musics->LoadMusic(Music::ID::TestMusic, "testmusic.mp3");
	Fonts->LoadFont(Font::ID::Dialog, "dialog.ttf");
	AUDIO->PlaySound(Sounds->Get(Sound::ID::EnemyHit));
	AUDIO->PlayMusic(Musics->Get(Music::ID::TestMusic));

	Ship* ship = new Ship(25, 25);
	GimmickV2* gimmickv2 = new GimmickV2();

	// L'engin vire
	Engine::GetInstance()->Run();

	return 0;
}
