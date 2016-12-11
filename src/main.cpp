#include "cls_game.h"

int main(int argc, char **argv)
{
	//Initilized the game with the startup variabes
	game theGame(argc, argv);

	//set the screen size and fullscreen status
	theGame.set_screensize(800,800,false);

	theGame.init();

	system("PAUSE");

}