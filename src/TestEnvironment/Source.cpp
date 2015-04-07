#include "Engine.h"
#include "Sprite.h"
#include "Ship.h"
#include "MegaSonic.h"
#include "Gimmick.h"
#include "GimmickV2.h"

typedef int* pInt;

int main(int argc, char* args[])
{
	#pragma region Exercices
	float* f = new float(2.0f);
	f++;

	pInt test = new int( 5);

	std::vector<int> v = std::vector<int>(2000);
	std::vector<int*>* v2 = new std::vector<int*>(10);

	std::vector<std::string> v3;
	v3.push_back("Salut");
	v3.push_back("Bonjour");
	v3.push_back("!");

	for (int i = 0; i < v3.size(); i++)
	{
		std::cout << v3[i];
	}

	std::vector<std::string>::iterator iter;
	for (iter = v3.begin(); iter != v3.end(); iter++)
	{
		std::cout << (*iter) << std::endl;
	}

	int* pI = new int(5);

	int** pI2 = new int*[5];
	for (int i = 0; i < 5; i++)
		pI2[i] = new int[5];

	for (int i = 0; i < 5; i++)
		delete[] pI2[i];
	delete[] pI2;
	#pragma endregion

	Engine::GetInstance()->Init();

	// Declare tous mes objets
	//Ship* ship = new Ship();
	//MegaSonic* megaSonic = new MegaSonic();
	//Gimmick* gimmick = new Gimmick();
	GimmickV2* gimmickV2 = new GimmickV2();

	// L'engin vire
	Engine::GetInstance()->Run();

	//delete ship;
	//delete megaSonic;
	//delete gimmick;
	delete gimmickV2;

	return 0;
}