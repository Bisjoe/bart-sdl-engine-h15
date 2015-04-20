#include "Libraries.h"
#include "AnimationTest.h"
#include "SpriteTest.h"
#include "SoundTest.h"
#include "TextTest.h"

int main(int argc, char* args[])
{
	//Initializes the engine
	Engine::GetInstance()->Init(800, 750);

	//Loading resources
	Textures->LoadTexture(Texture::ID::Gimmick, "Gimmick2.png");
	Textures->LoadTexture(Texture::ID::Ship,	"Ship.jpg");
	Sounds->  LoadSound  (Sound::ID::EnemyHit,  "enemy_hit.wav");
	Musics->  LoadMusic  (Music::ID::TestMusic, "testmusic.mp3");
	Fonts->   LoadFont   (Font::ID::Dialog,		"dialog.ttf", 23);

	//Soundtest		demonstrates the Audio system's functionnalities,	 look at SoundTest.H for info on the various controls: ([1-6], Numpad[1-6], +, -)
	//SpriteTest	demonstrates the Sprite system's functionnalities,	 look at SpriteTest.H for info on the various controls: (Up, Down, Left, Right, PageUp, PageDown, End, Home)
	//AnimationTest demonstrates the Animation system's functionnalities,look at AnimationTest.H for info on the various controls: (A, B, C, Space)
	//TextTest		demonstrates the Text system's functionnalities,	 look at TextTest.H for info on the various controls: (F1-F7)

	SpriteTest*		spriteTest		= new SpriteTest(25, 25);
	SoundTest*		soundTest		= new SoundTest();
	AnimationTest*  animationTest	= new AnimationTest();
	TextTest*		textTest		= new TextTest();

	Engine::GetInstance()->Run();

	return 0;
}
