#include "cls_game.h"
#include "wtypes.h"

int main(int argc, char **argv)
{
	//gets the Desktop resolution size for the current hardware
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);

	//Initilized the game with the startup variabes
	game theGame(argc, argv);

	//set the screen size and fullscreen status
#ifdef _DEBUG
	theGame.set_screensize(1366, 768, false);
#else
	theGame.set_screensize(desktop.right, desktop.bottom, true);
#endif
	theGame.init();
	theGame.mainloop();
}