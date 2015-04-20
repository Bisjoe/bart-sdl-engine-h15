#include "Libraries.h"
#include "Ship.h"
#include "Gimmick.h"
#include "GimmickV2.h"

typedef int* pInt;

int main(int argc, char* args[])
{
	// Proportional resolution for NES (default: 256 * 240) (only to show it's working, default "Init()" has the same size as before (800 * 600))
	Engine::GetInstance()->Init(800, 750); 

	// Simplified sprite creation no longer requirering to create a texture first (does it while making the sprite)
	Sprite* testS = new Sprite(t_ship); // Check ResourceIDs for explanations on "t_ship"
	GimmickV2* gimmick2 = new GimmickV2();
	gimmick2->Scale(2);

	//gimmick2->Flip(flip_h); // Check sprite.h for the full list of flipping shortcuts
	//testS->SetRotation(180);

	// Load now return a pointer to the ressources added, you can stock it or not if you want (useful for quick use after creation)
	// Mix_Chunk* x = Sounds->LoadSound("enemy_hit.wav");

	// Example of errors management
	// Mix_Music* y = Musics->LoadMusic("dialog.ttf"); // <- Take out the first commentary to try it
	Text* testText = new Text("Hello world!", Color::BLACK);
	testText->SetOptions(OpFadeIn);

	//testText->Scale(3);

	Fonts->LoadFont("dialog.ttf");

	cAudio->PlaySound("about_time.wav");
	cAudio->SetGlobalVolume(34);

	// Other example where the load music is use as soon as it is created, without needing to stock it elsewhere or having to get it 
	// (use is safe as the resource system will never load twice the same file. If already loaded, it will return that one)
	// (That is, of course, unless said two files are identical but have different names)
	cAudio->PlayMusic(Musics->LoadMusic(m_testmusic)); // <- Take out the first commentary to try it

	// L'engin vire
	Engine::GetInstance()->Run();
	delete gimmick2;
	delete testS;
	return 0;
}
