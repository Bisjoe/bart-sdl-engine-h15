#include "Libraries.h"
#include "Ship.h"
#include "Gimmick.h"
#include "GimmickV2.h"


typedef int* pInt;

char* const sound1 = "about_time.wav";
char* const sound2 = "enemy_hit.wav";

int main(int argc, char* args[])
{
	Engine::GetInstance()->Init();

	// Declare tous mes objets
	//Ship* ship = new Ship();
	//Gimmick* gimmick = new Gimmick();
	//GimmickV2* gimmickV2 = new GimmickV2();
	TextAnim* textTest = new TextAnim("Text Animation - v:0.2.5", LETTER, "dialog.ttf");
	TextAnim* textTest2 = new TextAnim("Text Animation - v:0.2.5", WORD, "dialog.ttf", 18, 0, 50);
	TextAnim* textTest3 = new TextAnim("Hello you there on the wall", LINE, "dialog.ttf", 18, 0, 100);
	textTest->SetFontsize(18);
	textTest->Play();
	textTest2->Play();
	textTest3->Play();
	AUDIO->SetMusicVolume(30);
	AUDIO->PlayMusic("testmusic.mp3");
	AUDIO->AddSoundToList(sound2);
	AUDIO->OverrideSoundInList(sound1, sound2);
	// AUDIO->SetSfxVolume(sound1, 40);
	AUDIO->PlaySound(sound1, 1);

	// L'engin vire
	Engine::GetInstance()->Run();

	//delete ship;
	//delete gimmick;
	//delete gimmickV2;
	delete textTest;
	delete textTest2;
	delete textTest3;
	return 0;
}
