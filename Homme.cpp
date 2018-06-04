#include "Homme.h"

Homme::Homme()
{
    //ctor
}

Homme::Homme(string n = "",string c="",string e= "",int t=0,Piece **lp = 0) :Joueur(n,c,e,t,lp)
{

}
Homme::Homme(string n,string c) :Joueur(n,c,"normal")
{

}
Homme::Homme(string n = "",string c="",string e= "") :Joueur(n,c,e)
{

}
Homme::Homme(Homme& h) : Joueur(h)
{

}
Homme::~Homme()
{

}


Deplacement Homme::jouer(Echiquier &ech,Joueur &j_adv)
{


    bool stop = true;
    Deplacement dep;
    int ind;
    do
    {

       dep.saisir();

        if(dep == Deplacement(-1,-1,-1,-1))
            return dep;

       else
       {
           if(!dep.dans_echiquier())
            stop = false;
           ind = chercher(dep.Getpos_i());

           if(ind == -1)
           {
               stop = false;
           }
          else if(liste_pieces[ind] != 0 && liste_pieces[ind]->verifer_deplacement(dep.Getpos_f()) == false)
           {
               stop = false;

           }
           else if(liste_pieces[ind] != 0 && liste_pieces[ind]->verifer_chemain(dep.Getpos_f(),liste_pieces,taille,j_adv.get_liste_pieces(),j_adv.GetTaille()) == false)
           {
               stop = false;
           }
           else
           {
            stop = true;
           }

       }
    }while(!stop);

    if(stop)
    {


        int ind_adv  = -1;
        for(int i=0;i<j_adv.GetTaille();i++)
        {
            if(j_adv.get_liste_pieces()[i] != 0 &&j_adv.get_liste_pieces()[i]->Getpos() == dep.Getpos_f())
            {
                ind_adv = i;
                break;
            }
        }

        if(ind_adv >=0)
        {
            j_adv.get_liste_pieces()[ind_adv] = 0;
        }
        ech.Set_case(dep.Getpos_f().Getx(),dep.Getpos_f().Gety(),liste_pieces[ind]);
        if(liste_pieces[ind] != 0)
        liste_pieces[ind]->deplacer(dep.Getpos_f());
        ech.Set_case(dep.Getpos_i().Getx(),dep.Getpos_i().Gety(),0);

        return dep;
    }

}


