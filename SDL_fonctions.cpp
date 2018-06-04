#include "SDL_fonctions.h"


SDL_Surface *charger_image( std::string nom_fichier )
{

    SDL_Surface* img_optim = NULL;
     SDL_Surface* img_chargee = IMG_Load( nom_fichier.c_str() );

    if( img_chargee != NULL )
    {
        img_optim = SDL_DisplayFormat( img_chargee );

        SDL_FreeSurface( img_chargee );
        if( img_optim != NULL )
        {
            Uint32 colorkey = SDL_MapRGB( img_optim->format, 255, 255, 255);

            SDL_SetColorKey( img_optim, SDL_SRCCOLORKEY, colorkey );
        }
    }


    return img_optim;
}

void bliter_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{

    SDL_Rect offset;


    offset.x = x;
    offset.y = y;

    SDL_BlitSurface( source, NULL, destination, &offset );
}
