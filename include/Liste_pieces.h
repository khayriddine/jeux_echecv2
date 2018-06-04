#ifndef LISTE_PIECES_H
#define LISTE_PIECES_H

#include "structure_donnee.h"


class Liste_pieces : public structure_donnee
{
    public:
        Liste_pieces();
        virtual ~Liste_pieces();

        vector <Piece*> Getlp() { return lp; }
        void Setlp(vector <Piece*> val) { lp = val; }
        int Gettaille() { return taille; }
        void Settaille(int val) { taille = val; }

    protected:

    private:
        vector <Piece*> lp;
        int taille;
};

#endif // LISTE_PIECES_H
