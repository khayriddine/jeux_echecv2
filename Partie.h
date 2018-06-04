#ifndef PARTIE_H
#define PARTIE_H

#include "menu.h"
#include "Machine_bete.h"
#include "Machine_intel.h"
#include "Machine_intelpp.h"
#include "Homme.h"
#include "Echiquier.h"
#include "Deplacement.h"
#include <windows.h>
#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <iostream>
#include <string>
#include <windows.h>

class Partie
{
    public:
        Partie();
        Partie(Homme &h1,Homme &h2);
        Partie(Homme &h,Machine_bete &mb);
        Partie(Homme &h,Machine_intel &mi);
        Partie(Machine_bete &mb1,Machine_bete &mb2);
        Partie(Machine_bete &mb1,Machine_intel &mi);
        Partie(Machine_bete &mb1,Machine_intelpp &mipp);
        Partie(Homme &h,Machine_intelpp &mipp);
        virtual ~Partie();

        void afficher(SDL_Surface *ecran) ;
        void m_a_j();
        void lancer(SDL_Surface *ecran);

    protected:

    private:
        Joueur *js[2];
        Echiquier *ech;
        vector <Deplacement> His;
        int tour;
        bool terminee;
};

#endif // PARTIE_H
