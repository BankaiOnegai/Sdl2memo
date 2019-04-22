#include "prototypes.h"


Map map;

void initMaps(void)
{
	//charge l'image du fond (background)
	map.background = loadImage("background.jpg");
}

SDL_Texture *getBackground(void)
{
	return map.background;
}

void cleanMaps(void)
{
	//libere la texture du background
	if(map.background != NULL)
	{
		SDL_DestroyTexture(map.background);
		map.background = NULL;
	}
}