#include "Engine.h"
#include "Sprite.h"
#include "Ship.h"
#include "Gimmick.h"
#include "GimmickV2.h"
#include "Text.h"
#include "Audio.h"

typedef int* pInt;

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
	Audio* musicTest = new Audio("testmusic.mp3", -1);
	Audio::SetVolume(30); // Change this value to raise or lower the volume. Work overall and not per instance.


	// L'engin vire
	Engine::GetInstance()->Run();

	//delete ship;
	//delete gimmick;
	//delete gimmickV2;
	delete musicTest;
	delete textTest;
	return 0;
}
