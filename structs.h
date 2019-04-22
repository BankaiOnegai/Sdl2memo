#ifndef DEF_STRUCTS 
#define DEF_STRUCTS 

#include "defs.h"

/* Structures qui seront utilisées pour gérer le jeu */

// structure pour gérer l'input (clavier puis joystick)

typedef struct Input
{
	int enter , erase , pause ;
} Input ;

typedef struct Map
{
	SDL_Texture *background;
}Map;


#endif
