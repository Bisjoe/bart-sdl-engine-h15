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
	Text* textTest = new Text("Hello world!");
	textTest->SetFontsize(18);
	textTest->SetTextColor({ 245, 222, 187 });
	AUDIO->SetMusicVolume(30);
	AUDIO->PlayMusic("testmusic.mp3");
	AUDIO->AddSoundToList(sound2);
	AUDIO->SetSfxVolume(sound2, 40);
	AUDIO->OverrideSoundInList(sound1, sound2);
	AUDIO->PlaySound(sound1, 1);

	// L'engin vire
	Engine::GetInstance()->Run();

	//delete ship;
	//delete gimmick;
	//delete gimmickV2;
	delete textTest;
	return 0;
}
