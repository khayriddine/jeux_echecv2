#include "menu.h"



void afficher_menu_p(SDL_Surface *ecran)
{
    ecran = SDL_SetVideoMode(900,600,32,SDL_HWSURFACE );
    SDL_Surface *menu_p = IMG_Load("background_menu_p.jpg");

    SDL_Event event;

    while(SDL_WaitEvent(&event))
    {

        if(event.type == SDL_QUIT)
        {
            return;
        }
        else if(event.type == SDL_KEYDOWN)
        {
            if(event.key.keysym.sym == SDLK_KP1)
            {
                return afficher_menu_choix_adversaire(ecran);
            }
            else if(event.key.keysym.sym == SDLK_KP2)
            {
                return afficher_menu_regle_du_jeu(ecran);
            }
            else if(event.key.keysym.sym == SDLK_KP3)
            {
                return afficher_menu_option(ecran);
            }
            else if(event.key.keysym.sym == SDLK_KP4 || event.key.keysym.sym == SDLK_ESCAPE)
            {
                return;
            }
            else if(event.key.keysym.sym == SDLK_KP5)
            {
                return afficher_menu_apropos(ecran);
            }

        }
        else if(event.type == SDL_MOUSEBUTTONUP)
        {
            if(event.button.button == SDL_BUTTON_LEFT)
            {
                if(event.button.x >= 28 && event.button.x <= 276 && event.button.y >= 140 && event.button.y <= 176)
                {
                    return afficher_menu_choix_adversaire(ecran);
                }
                else if(event.button.x >= 28 && event.button.x <= 200 && event.button.y >= 200 && event.button.y <= 240)
                {
                    return afficher_menu_regle_du_jeu(ecran);
                }
                else if(event.button.x >= 28 && event.button.x <= 156 && event.button.y >= 266 && event.button.y <= 302)
                {
                    return afficher_menu_option(ecran);
                }

                else if(event.button.x >= 28 && event.button.x <= 156 && event.button.y >= 323 && event.button.y <= 364)
                {
                    return;
                }
                else if(event.button.x >= 28 && event.button.x <= 205 && event.button.y >= 380 && event.button.y <= 415)
                {
                    return afficher_menu_apropos(ecran);
                }

            }
        }
        bliter_surface(0,0,menu_p,ecran);
        SDL_Flip(ecran);
    }
}

void afficher_menu_choix_adversaire(SDL_Surface *ecran)
{
    ecran = SDL_SetVideoMode(900,600,32,SDL_HWSURFACE );
    SDL_Surface *menu_choix_adversaire = IMG_Load("background_choix_adversaire.jpg");
    SDL_Event event;
    while(SDL_WaitEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
            return ;
        }
        else if(event.type == SDL_KEYDOWN)
        {
            if(event.key.keysym.sym == SDLK_ESCAPE)
            {
                return afficher_menu_p(ecran);
                break;
            }
            else if(event.key.keysym.sym == SDLK_KP1)
            {
                return afficher_menu_contre_machine(ecran);
            }
            else if(event.key.keysym.sym == SDLK_KP2)
            {
                return afficher_menu_contre_etre_humain(ecran);
            }

        }
        else if(event.type == SDL_MOUSEBUTTONDOWN )
        {
            if(event.button.x >= 35 && event.button.x <= 185 && event.button.y >= 120 && event.button.y <= 160)
            {
                return afficher_menu_contre_machine(ecran);
            }
            else if(event.button.x >= 35 && event.button.x <= 230 && event.button.y >= 185 && event.button.y <= 225)
            {
                return afficher_menu_contre_etre_humain(ecran);
            }

            else if(event.button.x >= 35 && event.button.x <= 205 && event.button.y >= 250 && event.button.y <= 285)
            {
                return afficher_menu_p(ecran);
            }


        }

        bliter_surface(0,0,menu_choix_adversaire,ecran);
        SDL_Flip(ecran);
    }



}

void afficher_menu_contre_etre_humain(SDL_Surface *ecran)
{

    ecran = SDL_SetVideoMode(900,600,32,SDL_HWSURFACE );

    SDL_Surface *menu_contre_etre_humain = IMG_Load("background_contre_homme.jpg"),
                 *message[2],*message1,*fleche = IMG_Load("fleche.jpg"), *jouer = IMG_Load("jouer.png");


    TTF_Font *font = TTF_OpenFont( "Agreloy.ttf", 70 );
    SDL_Color textColor = { 255, 255, 255 };

    SDL_FillRect(ecran,0,SDL_MapRGB(ecran->format,0,0,0));

    SDL_Rect r;
    r.x = 700;
    r.y=500;
    r.h=100;
    r.w=200;
    int i=0,y[2] = {150,270};
    string ch[2] = {"",""},couleur = "blanc";
    SDL_Event event;
    while(1)
    {
        SDL_WaitEvent(&event);
        if(event.type == SDL_QUIT)
        {
            return;
        }
        else if(event.type == SDL_KEYDOWN)
        {
            if(event.key.keysym.sym == SDLK_ESCAPE)
            {
                return afficher_menu_choix_adversaire(ecran);
            }
            else if(event.key.keysym.sym == SDLK_BACKSPACE && ch[i].length() > 0)
            {
                ch[i].erase(ch[i].begin() + ch[i].length() - 1);
            }
            else if (event.key.keysym.sym == SDLK_UP)
            {
                i = 0;
            }
            else if (event.key.keysym.sym == SDLK_DOWN)
            {
                i = 1;
            }
            else if((event.key.keysym.sym >= 97  && event.key.keysym.sym <= (97 +32) ) || (event.key.keysym.sym >= 65  && event.key.keysym.sym <= (65 +32)) )
            {

                ch[i]+= (char)(event.key.keysym.sym);

            }
            else if(event.key.keysym.sym == SDLK_RETURN)
            {
                Homme h1(ch[0],couleur);


                Homme h2(ch[1],couleur == "blanc" ? "noir" : "blanc");
                Partie p(h1,h2);
                p.lancer(ecran);
                return;
            }
            //
        }
        else if(event.type == SDL_MOUSEBUTTONDOWN)
        {
            if(event.button.button == SDL_BUTTON_LEFT)
            {

                if(event.button.x >= 270 && event.button.x <= 330 && event.button.y >= 270 && event.button.y <= 330)
                {
                    couleur = "blanc";

                }
                else if(event.button.x >= 340 && event.button.x <= 400 && event.button.y >= 370 && event.button.y <= 420)
                {
                    couleur = "noir";

                }
                else if(event.button.x >= 700 && event.button.x <= 900 && event.button.y >= 500 && event.button.y <= 600)
                {
                    Homme h1(ch[0],couleur);
                    Homme h2(ch[1],couleur == "blanc" ? "noir" : "blanc");
                    Partie p(h1,h2);
                    p.lancer(ecran);
                    return;

                }


            }
        }
        const char *chaine = ch[i].c_str();
        message[i] = TTF_RenderText_Solid( font, chaine, textColor );

        bliter_surface(0,0,menu_contre_etre_humain,ecran);
        if(message[0] != 0)
            bliter_surface(36,140,message[0],ecran);
        if(message[1])
            bliter_surface(36,270,message[1],ecran);
        bliter_surface(460,y[i],fleche,ecran);
        SDL_BlitSurface(jouer,0,ecran,&r);
        SDL_Flip(ecran);
    }

}

void afficher_menu_contre_machine(SDL_Surface *ecran)
{
    ecran = SDL_SetVideoMode(900,600,32,SDL_HWSURFACE );
    SDL_Surface *menu_contre_machine = IMG_Load("background_contre_machine.jpg");
    SDL_Surface *message,*niveau_image = charger_image("niveaux.png"),*jouer = IMG_Load("jouer.png");
    SDL_Event event;
    TTF_Font *font = TTF_OpenFont( "Agreloy.ttf", 70 );
    SDL_Color textColor = { 255, 255, 255 };
    SDL_FillRect(ecran,0,SDL_MapRGB(ecran->format,0,0,0));
    string chaine,couleur = "blanc" ;
    int i=-1,niveau = 1;
    bool niv = false;

    while(1)
    {
        SDL_WaitEvent(&event);

        if(event.type == SDL_QUIT)
        {
            return ;
        }
        else if(event.type == SDL_KEYDOWN)
        {
            if(event.key.keysym.sym == SDLK_ESCAPE)
            {
                return afficher_menu_choix_adversaire(ecran);
            }
            else if(event.key.keysym.sym == SDLK_BACKSPACE && chaine.length() > 0)
            {
                //ch[i][ch[i].length()-1] = ' ';
                chaine.erase(chaine.begin() + chaine.length() - 1);
                const char *chaine1 = chaine.c_str();
                message = TTF_RenderText_Solid( font, chaine1, textColor );
            }
            else if((event.key.keysym.sym >= 97  && event.key.keysym.sym <= (97 +32) ) || (event.key.keysym.sym >= 65  && event.key.keysym.sym <= (65 +32)) )
            {

                chaine += (char)(event.key.keysym.sym);
                const char *chaine1 = chaine.c_str();
                message = TTF_RenderText_Solid( font, chaine1, textColor );
            }
            else if(event.key.keysym.sym == SDLK_RETURN)
            {
                Homme h1(chaine,couleur);

                if(niveau == 1)
                {
                    Machine_bete mb(couleur == "blanc" ? "noir" : "blanc");
                    Partie p(h1,mb);
                    p.lancer(ecran);
                }
                if(niveau == 2)
                {
                    Machine_intel mi(couleur == "blanc" ? "noir" : "blanc");
                    Partie p(h1,mi);
                    p.lancer(ecran);
                }
                if(niveau == 3)
                {
                    Machine_intelpp mpp(couleur == "blanc" ? "noir" : "blanc");
                    Partie p(h1,mpp);
                    p.lancer(ecran);
                }

                return;
            }



        }
        else if(event.type == SDL_MOUSEBUTTONDOWN)
        {
            if(event.button.button == SDL_BUTTON_LEFT)
            {
                if(event.button.x >= 220 && event.button.x <= 330 && event.button.y >= 280 && event.button.y <= 430)
                {
                    if(event.button.x >= 220 && event.button.x <= 330 && event.button.y >= 280 && event.button.y <= 310)
                    {
                        niv = true;
                    }
                    else if(event.button.y >= 310 && event.button.y <= 350 && niv)
                    {

                        niveau = 1;
                    }
                    else if(event.button.y >= 350 && event.button.y <= 390 && niv)
                    {
                        niveau = 2;
                    }
                    else if(event.button.y >= 390 && event.button.y <= 430 && niv)
                    {
                        niveau = 3;
                    }
                }
                else
                {
                    niv = false;
                    if(event.button.x >= 245 && event.button.x <= 280 && event.button.y >= 210 && event.button.y <= 250)
                    {
                        couleur = "blanc";

                    }
                    else if(event.button.x >= 300 && event.button.x <= 340 && event.button.y >= 210 && event.button.y <= 250)
                    {
                        couleur = "noir";

                    }
                    else if(event.button.x >= 700 && event.button.x <= 900 && event.button.y >= 500 && event.button.y <= 600)
                    {
                        Homme h1(chaine,couleur);

                        if(niveau == 1)
                        {
                            Machine_bete mb(couleur == "blanc" ? "noir" : "blanc");
                            Partie p(h1,mb);
                            p.lancer(ecran);
                        }
                        if(niveau == 2)
                        {
                            Machine_intel mi(couleur == "blanc" ? "noir" : "blanc");
                            Partie p(h1,mi);
                            p.lancer(ecran);
                        }
                        if(niveau == 3)
                        {
                            Machine_intelpp mpp(couleur == "blanc" ? "noir" : "blanc");
                            Partie p(h1,mpp);
                            p.lancer(ecran);
                        }

                        return;

                    }
                }


            }
        }


        bliter_surface(0,0,menu_contre_machine,ecran);
        if(niv)
            bliter_surface(220,280,niveau_image,ecran);
        bliter_surface(50,140,message,ecran);
        bliter_surface(700,500,jouer,ecran);
        SDL_Flip(ecran);
    }

}

void afficher_menu_regle_du_jeu(SDL_Surface *ecran)
{
    ecran = SDL_SetVideoMode(1145,600,32,SDL_HWSURFACE );
    SDL_Surface *boutonDefillement =NULL, *regleImage = NULL;
    SDL_Event event;
    SDL_Rect boutonRect, imageRect ;
    boutonRect.h = 6;
    boutonRect.w = 4;
    boutonRect.x = 1135;
    boutonRect.y = 0;
    imageRect.x = 200;
    imageRect.y = 0;
    imageRect.w = 1145;
    imageRect.h = 6940;

    int continuer = 1;
    int bouton_bas = 0;
    const int rapport = (int)((float)imageRect.h/600);
    regleImage = IMG_Load("regleDuJeu_image.png");
    boutonDefillement = IMG_Load("cb.bmp");
    //while(1)
    while(1)
    {
        SDL_WaitEvent(&event);
        if(event.type == SDL_QUIT )
        {
            return ;
        }

        else if(event.type == SDL_KEYDOWN )
        {
            if(event.key.keysym.sym == SDLK_ESCAPE)
            {
                return afficher_menu_p(ecran);
            }
        }
        else   if(event.key.keysym.sym == SDLK_ESCAPE)
        {
            return afficher_menu_p(ecran);
        }

        else if ( event.type == SDL_MOUSEBUTTONDOWN )
            if(event.motion.x >= 1135 && event.motion.x <1145)
            {
                boutonRect.y = event.motion.y;
                imageRect.y = event.motion.y * rapport;
                if(imageRect.y >= 6340)
                    imageRect.y = 6340;
                bouton_bas = 1;
            }


        if(event.type ==  SDL_MOUSEBUTTONUP )
        {
            bouton_bas = 0;
        }
        if (event.type == SDL_MOUSEMOTION )
        {
            if(bouton_bas)
            {
                boutonRect.y = event.motion.y;
                imageRect.y = event.motion.y * rapport;
                if(imageRect.y >= 6340)
                    imageRect.y = 6340;
            }
        }

        SDL_BlitSurface(regleImage,&imageRect,ecran,NULL);
        SDL_BlitSurface(boutonDefillement,NULL,ecran,&boutonRect);

        SDL_Flip(ecran);

    }






}
void afficher_menu_apropos(SDL_Surface *ecran)
{
    SDL_Surface *menu_contre_machine = IMG_Load("apropos_image.png");
    SDL_Event event;
    while(SDL_WaitEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
            return ;
        }
        else if(event.type == SDL_KEYDOWN)
        {
            if(event.key.keysym.sym == SDLK_ESCAPE)
            {
                return afficher_menu_choix_adversaire(ecran);
            }
        }
        bliter_surface(0,0,menu_contre_machine,ecran);
        SDL_Flip(ecran);
    }

}
void afficher_menu_option(SDL_Surface *ecran)
{
    ecran = SDL_SetVideoMode(900,600,32,SDL_HWSURFACE );

    extern string echiquier_path;
    SDL_Surface *menu_option = IMG_Load("background_autres_options.jpg"),*choix_echiquier= charger_image("choix_echiquier.png");
    SDL_Event event;
    SDL_FillRect(ecran,0,SDL_MapRGB(ecran->format,0,0,0));
    bool niv = false;

    while(1)
    {
        SDL_WaitEvent(&event);

        if(event.type == SDL_QUIT)
        {
            return ;
        }
        else if(event.type == SDL_KEYDOWN)
        {
            if(event.key.keysym.sym == SDLK_ESCAPE)
            {
                return afficher_menu_choix_adversaire(ecran);
            }

        }
        else if(event.type == SDL_MOUSEBUTTONDOWN)
        {
            if(event.button.button == SDL_BUTTON_LEFT)
            {
                if(event.button.x >= 206 && event.button.x <= 245 && event.button.y >= 206 && event.button.y <= 245)
                {

                    niv = true;
                }
                else
                {
                    //296

                    if(event.button.x >= 336 && event.button.x <= 400 && event.button.y >= 185 && event.button.y <= 249 && niv)
                    {

                        echiquier_path = "echiquier1.png";
                        niv = false;


                    }
                    else if(event.button.x >= 430 && event.button.x <= 494 && event.button.y >= 185 && event.button.y <= 249  && niv)
                    {
                        echiquier_path = "echiquier2.png";
                        niv = false;
                    }
                    else if(event.button.x >= 524 && event.button.x <= 588 && event.button.y >= 185 && event.button.y <= 249  && niv)
                    {
                        echiquier_path = "echiquier3.png";
                        niv = false;
                    }
                    else if(event.button.x >= 618 && event.button.x <= 682 && event.button.y >= 185 && event.button.y <= 249  && niv)
                    {
                        echiquier_path = "echiquier4.png";
                        niv = false;
                    }
                }



            }
        }

        //message = TTF_RenderText_Solid( font, chaine1, textColor );
        bliter_surface(0,0,menu_option,ecran);
        if(niv)
            bliter_surface(336,185,choix_echiquier,ecran);
        SDL_Flip(ecran);
    }


}
void afficher_animation(SDL_Surface *ecran,string nom)
{
    SDL_Event event;
    int rep,current_frame = 0;
SDL_Surface *image = IMG_Load("chess-gif.png"),*nom_image;
TTF_Font *font = TTF_OpenFont( "Agreloy.ttf", 70 );
    SDL_Color textColor = { 255, 255, 255 };
    nom_image = TTF_RenderText_Solid( font, nom.c_str(), textColor );
    ecran = SDL_SetVideoMode(640,480,32,SDL_SWSURFACE);
    SDL_Rect rects,rectd;
    rects.h = 250;
    rects.w = 340;
    rects.y = 0;
rectd.w = 340;rectd.h = 250;
    rectd.x = 160;
    rectd.y = 120;
    rects.x=0;
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_FillRect(ecran,0,SDL_MapRGB(ecran->format,0,0,0));
    while(1)
    {
        SDL_PollEvent(&event);
        if(event.type == SDL_KEYDOWN)
        {
            if(event.key.keysym.sym == SDLK_ESCAPE)
            {
                afficher_menu_p(ecran);
                return;
            }
        }
        current_frame +=1;
        if(current_frame > 10*50)
            current_frame = 0;
        rects.x = (current_frame/50)*375;
        bliter_surface(160,50,nom_image,ecran);
        SDL_BlitSurface(image,&rects,ecran,&rectd);
        SDL_Flip(ecran);

    }


}




