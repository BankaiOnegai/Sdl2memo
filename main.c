#include "prototypes.h"

Input input;

int main(int argc, char *argv[])
{
	unsigned int frameLimit = SDL_GetTicks() + 16;
	int go;

	//init de la SDL
	init("Memo_master");

	loadGame();

	atexit(cleanup);

	go = 1;

	while(go == 1)
	{
		//gestion des inputs au clavier
		gestionInputs(&input);

		//on dessine tout
		drawGame();

		//gestion des 60 fps (1000ms/60 = 16.6 ->16)
		delay(frameLimit);
		frameLimit = SDL_GetTicks()+16;

	}

	exit (0);
}