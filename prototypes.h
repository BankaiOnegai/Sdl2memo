#include "structs.h"

#ifndef PROTOTYPES
#define PROTOTYPES


/*catalogue des prototypes des fonctions utilisées */
extern void cleanMaps(void);
extern void cleanup(void);
extern void delay(unsigned int frameLimit);

extern void drawGame(void);
extern void drawImage(SDL_Texture*,int,int);
extern void drawMap(int);

extern void gestionInputs(Input *input);
extern void getInput(Input *input);
extern SDL_Renderer *getrenderer(void);
extern void init(char *);
extern void initMaps(void);
extern void loadGame(void);
extern SDL_Texture *loadImage(char *name);
extern SDL_Texture *getBackground(void);

#endif 