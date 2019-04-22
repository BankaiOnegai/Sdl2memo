#include "prototypes.h"

void drawGame(void)
{
	//Remplit le renderer de noir , efface l'écran et l'affiche
	//SDL_RendererPresent() remplace SDL_Flip de la SDL 1.2

	//affiche le fond background aux coordonnées 0 , 0
	drawImage(getBackground(), 0 ,0);

	//afffiche l'écran
	SDL_RenderPresent(getrenderer());

	//delai pour laisser respirer le processeur
	SDL_Delay(1);
}

SDL_Texture *loadImage(char *name)
{
	//charge les images avec SDL Image dans une SDL surface

	SDL_Surface *loadedImage = NULL ;
	SDL_Texture *texture = NULL ;
	loadedImage = IMG_Load(name);

	if(loadedImage != NULL)
	{
		//convertion de l'image en texture
		texture = SDL_CreateTextureFromSurface(getrenderer(),loadedImage);

		//on se debarasse du pointeur vers une surface
		SDL_FreeSurface(loadedImage);
		loadedImage = NULL ;
	}

	else 
		printf("L'image n'a pas pu etre chargé !SDL_Error :%s\n",SDL_GetError());

	return texture;
}

void drawImage(SDL_Texture *image ,int x ,int y)
{
	SDL_Rect dest;
	//regle le rectangle a dessiner selon la taille des images sources
	dest.x = x ;
	dest.y = y ;

	//on dessine l'image entiere sur l'éecran aux coordonnées x et y
	SDL_QueryTexture(image,NULL,NULL,&dest.w,&dest.h);
	SDL_RenderCopy(getrenderer(),image,NULL,&dest);
}

void makeGif(char *name)

void delay(unsigned int frameLimit)
{
	//gestion des 60 fps
	unsigned int ticks = SDL_GetTicks();

	if( frameLimit < ticks)
	{
		return;
	}

	if( frameLimit > ticks + 16)
	{
		SDL_Delay(16);
	}

	else
	{
		SDL_Delay(frameLimit - ticks);
	}
}