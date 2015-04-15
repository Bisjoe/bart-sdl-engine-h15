#include "Libraries.h"
#include "Ship.h"
#include "Gimmick.h"
#include "GimmickV2.h"


typedef int* pInt;

char* const sound1 = "about_time.wav";
char* const sound2 = "enemy_hit.wav";

int main(int argc, char* args[])
{
	Engine::GetInstance()->Init(800, 750); // Proportional resolution for NES (default: 256 * 240) (only to show it's working, default "Init()" has the same size as before (800 * 600))

	// Declare tous mes objets
	//Ship* ship = new Ship();
	//Gimmick* gimmick = new Gimmick();
	//GimmickV2* gimmickV2 = new GimmickV2();
	TextAnim* textTest = new TextAnim("Letter by letter", LETTER, "dialog.ttf");
	TextAnim* textTest2 = new TextAnim("Word by word", WORD, "dialog.ttf", 18, 0, 50);
	textTest2->SetTextColor(RED);
	TextAnim* textTest3 = new TextAnim("And now in color", LINE, "dialog.ttf", 18, 0, 100, GREEN);
	TextAnim* textTest4 = new TextAnim("Text animation - v.0.2.6", LINE, "dialog.ttf", 18, 0, 150);
	textTest4->SetTextColor(BLUE);
	textTest->SetFontsize(18);
	textTest->Play();
	textTest2->Play();
	textTest3->Play();
	textTest4->Play();
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
	delete textTest4;
	return 0;
}
