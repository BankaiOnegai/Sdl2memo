#include "prototypes.h"

SDL_Window *screen;
SDL_Renderer *renderer;

SDL_Renderer *getrenderer(void)
{
	return renderer;
}

void init (char *title)
{
	screen = SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(screen ,-1 ,SDL_RENDERER_PRESENTVSYNC);

	if(screen == NULL || renderer == NULL)
	{
		printf("Impossible d'initialer le mode écran à %d x %d :%s\n",SCREEN_WIDTH,SCREEN_HEIGHT,SDL_GetError());
		exit(1);
	}

	if(TTF_Init() < 0)
	{
		printf("Impossible d'initialer la SDL TFF: %s\n",TTF_GetError());
		exit(1);
	}

}

void cleanup()
{
	//nettoie les sprites de la map
	cleanMaps();
	
	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	SDL_DestroyWindow(screen);
	screen = NULL ;

	TTF_Quit();

	SDL_Quit(); 
}

void loadGame(void)
{
	//on charge les données pour la map
	initMaps();
}