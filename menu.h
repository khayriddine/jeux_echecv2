#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <iostream>
#include <string>

#include "SDL_fonctions.h"
#include "Homme.h"
#include "Machine_bete.h"
#include "Machine_intel.h"
#include "Machine_intelpp.h"
#include "Partie.h"



using namespace std;

void afficher_menu_p(SDL_Surface *ecran);
void afficher_menu_choix_adversaire(SDL_Surface *ecran);
void afficher_menu_contre_etre_humain(SDL_Surface *ecran);
void afficher_menu_contre_machine(SDL_Surface *ecran);
void afficher_menu_regle_du_jeu(SDL_Surface *ecran);
void afficher_menu_option(SDL_Surface *ecran);
void afficher_menu_apropos(SDL_Surface *ecran);
void afficher_animation(SDL_Surface *ecran);
void afficher_animation(SDL_Surface *ecran,string nom);


#endif // MENU_H_INCLUDED
