#ifndef SDL_FONCTIONS_H_INCLUDED
#define SDL_FONCTIONS_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>
SDL_Surface *charger_image( std::string nom_fichier );
void bliter_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );

#endif // SDL_FONCTIONS_H_INCLUDED
