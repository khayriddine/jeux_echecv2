#ifndef DEPLACEMENT_H
#define DEPLACEMENT_H


#include<iostream>
#include <string>

#include "Position.h"

using namespace std;
class Deplacement
{
    public:
        Deplacement();
        Deplacement(int xi,int yi,int xf,int yf);
        Deplacement(const Deplacement& dep);
        ~Deplacement();
        Deplacement(Position pi , Position pf);
        Position Getpos_i() { return pos_i; }
        void Setpos_i(Position val) { pos_i = val; }
        Position Getpos_f() { return pos_f; }
        void Setpos_f(Position val) { pos_f = val; }
        void afficher();
        void saisir();
        bool operator==(const Deplacement& dep);
        bool dans_echiquier()const;
        string transformer();


    private:
        Position pos_i;
        Position pos_f;
};

#endif // DEPLACEMENT_H
