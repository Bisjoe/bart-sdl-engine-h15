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
	AUDIO->PlayMusic(Musics->Get(Music::ID::TestMusic));
	AUDIO->PlaySound(Sounds->Get(Sound::ID::EnemyHit));

	Ship* ship = new Ship(25, 25);
	GimmickV2* gimmickv2 = new GimmickV2();
	//Ship* ship2 = new Ship(201, 0);
	//Ship* ship3 = new Ship(401, 0);
	//Ship* ship4 = new Ship(601, 0);
	//ship->ScaleSprite(200, 200);
	//ship2->ScaleSprite(200, 200);
	//ship3->ScaleSprite(200, 200);
	//ship4->ScaleSprite(200, 200);
	//ship->HorizontalFlip();
	//ship2->VerticalFlip();
	//ship3->HorizontalMirror();
	//ship4->VerticalMirror();
	//AUDIO->SetMusicVolume(30);
	//AUDIO->PlayMusic("testmusic.mp3");
	//AUDIO->AddSoundToList(sound2);
	//AUDIO->OverrideSoundInList(sound1, sound2);
	//// AUDIO->SetSfxVolume(sound1, 40);
	//AUDIO->PlaySound(sound1, 1);

	// L'engin vire
	Engine::GetInstance()->Run();

	//delete ship;
	//delete gimmick;
	//delete gimmickV2;
	return 0;
}
