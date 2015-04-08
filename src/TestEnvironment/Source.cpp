#include "Engine.h"
#include "Sprite.h"
#include "Ship.h"
#include "Gimmick.h"
#include "GimmickV2.h"

typedef int* pInt;

int main(int argc, char* args[])
{
	Engine::GetInstance()->Init();

	// Declare tous mes objets
	//Ship* ship = new Ship();
	//Gimmick* gimmick = new Gimmick();
	GimmickV2* gimmickV2 = new GimmickV2();

	// L'engin vire
	Engine::GetInstance()->Run();

	//delete ship;
	//delete gimmick;
	delete gimmickV2;

	return 0;
}