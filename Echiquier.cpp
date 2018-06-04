#include"Echiquier.h"



Echiquier::Echiquier(Piece* lpb[] = 0,int tb = 0,Piece* lpn[] = 0,int tn = 0)
{

    int i,j;
    for(int i=0; i<8; i++)
    {
         for(int j=0; j<8; j++)
        {
            ech[j][i].Setcouleur(((i+j)% 2 == 1 )? "noir" : "blanc") ;
        }

    }

    for(int k=0; k<tb; k++)
    {

        i = lpb[k]->Getpos().Getx();
        j = lpb[k]->Getpos().Gety();
        ech[i][j].Set_piece(lpb[k]);

    }
    for(int k=0; k<tn; k++)
    {

        i = lpn[k]->Getpos().Getx();
        j = lpn[k]->Getpos().Gety();
        ech[i][j].Set_piece(lpn[k]);

    }
    //Ech = load_image("echiquier.png");


}



Echiquier::~Echiquier()
{

}

void Echiquier::afficher(SDL_Surface *ecran)
{
ecran = SDL_SetVideoMode(1145,600,32,SDL_HWSURFACE );
 extern string echiquier_path;
SDL_Surface *Ech = charger_image(echiquier_path);
SDL_Surface *donnee = charger_image("donne_partie.png");
SDL_FillRect(ecran, 0, SDL_MapRGB(ecran->format, 255, 255, 255));


    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(ech[i][j].Get_piece() != 0)
        {
            bliter_surface(20 + i*64,20 + j*64,ech[i][j].Get_piece()->Getsymbole(),Ech);

        }

    }
}
     bliter_surface(0,0,Ech,ecran);
     bliter_surface(570,0,donnee,ecran);



}

