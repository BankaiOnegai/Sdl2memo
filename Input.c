#include "prototypes.h"

void gestionInputs(Input *Input)
{
	getInput(Input);
}

void getInput(Input *input)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
			exit(0);
			break;

			case SDL_KEYDOWN:
			switch(event.key.keysym.sym)
			{
				case SDLK_ESCAPE:
				exit(0);
				break;

				case SDLK_RETURN:
				input->enter = 1;
				break;

				case SDLK_DELETE:
				input->erase;
				break;

				
				default:
				break;
			}
			break;

			case SDL_KEYUP:
			switch(event.key.keysym.sym)
			{
				case SDLK_DELETE:
				input->erase = 0;
				break;

				case SDLK_RETURN:
				input->enter = 0;
				break;

				default:
				break;
			}
			break;
		}
	}
}