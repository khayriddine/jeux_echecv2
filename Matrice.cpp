#include "Matrice.h"
Matrice::Matrice()
{
    longueur = largeur = 0;
}
Matrice::Matrice(int lo,int la): longueur(lo) , largeur(la)
{
  /*  mat = new Case*[longueur];
    for(int i=0;i<largeur;i++)
        mat[i] = new Case[largeur];*/
}

Matrice::~Matrice()
{
    //dtor
}
