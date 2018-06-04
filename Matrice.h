#ifndef MATRICE_H
#define MATRICE_H

#include "structure_donnee.h"

#include "Case.h"
class Matrice : public structure_donnee
{
    public:
        Matrice();
        Matrice(int lo,int la);
        virtual ~Matrice();

        Case** Getmat() { return mat; }
        void Setmat(Case** val) { mat = val; }
        int Getlongueur() { return longueur; }
        void Setlongueur(int val) { longueur = val; }
        int Getlargeur() { return largeur; }
        void Setlargeur(int val) { largeur = val; }

    protected:

    private:
        Case** mat;
        int longueur;
        int largeur;
};

#endif // MATRICE_H
