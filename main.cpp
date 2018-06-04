#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string>

#include "Echiquier.h"
#include "Homme.h"
#include "SDL_fonctions.h"
#include "Partie.h"
#include "menu.h"


string echiquier_path = "echiquier1.png";
int main ( int argc, char** argv )
{
   SDL_Init( SDL_INIT_VIDEO ) ;
   TTF_Init();
    SDL_Surface* ecran = SDL_SetVideoMode(1145,600,32,SDL_HWSURFACE );




    afficher_menu_p(ecran);

    Homme yas("yas","noir","normal");
    Homme kha("khayri","blanc","echec emat");

    Machine_bete m2("blanc");
    Machine_intel m1("noir");

    //Partie partie1(kha,yas);
    Partie partie1(m2,m1);
    partie1.lancer(ecran);


    return 0;
}
