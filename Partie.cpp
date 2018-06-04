#include "Partie.h"

Partie::Partie()
{
    //ctor
}

Partie::Partie(Homme &h1,Homme &h2)
{
    if(h1.Getcouleur() == "noir")
    {
        js[1] = new Homme(h1);
        js[0] =  new Homme(h2);
    }
    else
    {

        js[1] = new Homme(h2);
        js[0] = new  Homme(h1);
    }
    ech = new Echiquier(js[0]->get_liste_pieces(),js[0]->GetTaille(),js[1]->get_liste_pieces(),js[1]->GetTaille());
    tour =0;
    terminee = false;



}
Partie::Partie(Homme &h,Machine_bete &mb)
{
    if(h.Getcouleur() == "noir")
    {
        js[1] = new Homme(h);
        js[0] = new Machine_bete(mb);
    }
    else
    {

        js[0] = new Homme(h);
        js[1] = new Machine_bete(mb);
    }
    ech = new Echiquier(js[0]->get_liste_pieces(),js[0]->GetTaille(),js[1]->get_liste_pieces(),js[1]->GetTaille());

    tour =0;
    terminee = false;


}
Partie::Partie(Machine_bete &mb1,Machine_bete &mb2)
{
    js[0] = new Machine_bete(mb1);
    js[1] = new Machine_bete(mb2);
    ech = new Echiquier(js[0]->get_liste_pieces(),js[0]->GetTaille(),js[1]->get_liste_pieces(),js[1]->GetTaille());

    tour =0;
    terminee = false;


}
Partie::Partie(Machine_bete &mb1,Machine_intel &mi)
{
    js[0] = new Machine_bete(mb1);
    js[1] = new Machine_intel(mi);
    ech = new Echiquier(js[0]->get_liste_pieces(),js[0]->GetTaille(),js[1]->get_liste_pieces(),js[1]->GetTaille());

    tour =0;
    terminee = false;

}
Partie::Partie(Machine_bete &mb1,Machine_intelpp &mipp)
{
    js[0] = new Machine_bete(mb1);
    js[1] = new Machine_intelpp(mipp);
    ech = new Echiquier(js[0]->get_liste_pieces(),js[0]->GetTaille(),js[1]->get_liste_pieces(),js[1]->GetTaille());

    tour =0;
    terminee = false;

}
Partie::Partie(Homme &h,Machine_intel &mi)
{
    if(h.Getcouleur() == "noir")
    {
        js[1] = new Homme(h);
        js[0] = new Machine_intel(mi);
    }
    else
    {

        js[0] = new Homme(h);
        js[1] = new Machine_intel(mi);
    }
    ech = new Echiquier(js[0]->get_liste_pieces(),js[0]->GetTaille(),js[1]->get_liste_pieces(),js[1]->GetTaille());

    tour =0;
    terminee = false;

}
Partie::Partie(Homme &h,Machine_intelpp &mipp)
{
    if(h.Getcouleur() == "noir")
    {
        js[1] = new Homme(h);
        js[0] = new Machine_intelpp(mipp);
    }
    else
    {

        js[0] = new Homme(h);
        js[1] = new Machine_intelpp(mipp);
    }


    ech = new Echiquier(js[0]->get_liste_pieces(),js[0]->GetTaille(),js[1]->get_liste_pieces(),js[1]->GetTaille());

    tour =0;
    terminee = false;

}
Partie::~Partie()
{
    delete ech;
    delete []js;
}
void Partie::afficher(SDL_Surface *ecran)
{
    SDL_Surface  *nom_text,*historique[255];
    TTF_Font *font_h = TTF_OpenFont( "gillsansmt.ttf", 20 ),*font_n = TTF_OpenFont( "GreyscaleBasicBoldItalic.ttf", 40 );
    SDL_Color textColor_n[2] = {{255,255,255},{255,0,0}},textColor_h = {0,0,0};

    ech->afficher(ecran);
    const char* nom = js[tour]->Getnom().c_str();
int i=0,k=-1,choix = js[tour]->Getetat() == "echec" ? 1:0;
    nom_text = TTF_RenderText_Solid(font_n,nom,textColor_n[choix]);
    bliter_surface(800,80,nom_text,ecran);

    string ch[255] ;
    while(i<His.size())
    {
        if(i%8 ==0)
        {
            k++;
        }
        ch[k] += '1' +i ;
        ch[k] +=".";
        ch[k] += His[i].transformer();
        i++;
    }

    for(int h=0; h<=k; h++)
    {
        historique[h] = TTF_RenderText_Solid( font_h, ch[h].c_str(), textColor_h );
        bliter_surface(580, 270+20*h,historique[h],ecran);
    }



}
void Partie::lancer(SDL_Surface *ecran)
{
    Deplacement dep;
    bool done = false;

    while (!terminee)
    {

        string e = js[tour]->m_a_j_etat(*js[(tour+1)%2]);
        js[tour]->Setetat(e);
        afficher(ecran);
        SDL_Flip(ecran);

        if(js[tour]->Getetat() == "echec emat")
        {
           afficher_animation(ecran,js[(tour+1)%2]->Getnom());
        }
        else
        {

            dep = js[tour]->jouer(*ech,*js[(tour + 1)%2]);
            if(dep == Deplacement(-1,-1,-1,-1))
                terminee = true;
            else
            {


                int ind = js[tour]->chercher(dep.Getpos_f());
                if(ind >=0)
                {
                    if(js[tour]->get_liste_pieces()[ind] != 0 && js[tour]->get_liste_pieces()[ind]->Getnom() == "Pion")
                    {
                        if(js[tour]->Getcouleur() == "blanc" && dep.Getpos_f().Gety() == 0 || js[tour]->Getcouleur() == "noir" && dep.Getpos_f().Gety() == 7)
                        js[tour]->get_liste_pieces()[ind] = new Reine(dep.Getpos_f(),js[tour]->Getcouleur());
                        ech->Set_case(dep.Getpos_f().Getx(),dep.Getpos_f().Gety(),js[tour]->get_liste_pieces()[ind]);
                    }
                }
                His.push_back(dep);
                tour = (tour + 1)%2;

            }

        }

    }

}

