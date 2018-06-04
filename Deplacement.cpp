#include "Deplacement.h"

Deplacement::Deplacement()
{

    pos_i.Setx(0);
    pos_i.Sety(0);
    pos_f.Setx(0);
    pos_f.Sety(0);

}
Deplacement::Deplacement(int xi,int yi,int xf,int yf)
{

    pos_i.Setx(xi);
    pos_i.Sety(yi);
    pos_f.Setx(xf);
    pos_f.Sety(yf);

}
Deplacement::Deplacement(const Deplacement& dep) : pos_i(dep.pos_i), pos_f(dep.pos_f)
{

}

Deplacement::Deplacement(Position pi, Position pf)
{
    pos_i=pi;
    pos_f=pf;
}

Deplacement::~Deplacement()
{

}
/*
void Deplacement::operator=(Deplacement & dep)
{

}*/
void Deplacement::saisir()
{


    Position pi,pf;
    pi.saisir();

    if(pi == Position(-1,-1))
    {
        *this = Deplacement(-1,-1,-1,-1);
        return;
    }

    pf.saisir();

    *this = Deplacement(pi,pf);
    return;


}
string Deplacement::transformer()
{
    string ch;
    ch +=  (char)(pos_i.Getx( ) + 97);
    ch +=  8-pos_i.Gety() + 48 ;
    ch +=  pos_f.Getx()+  97;
    ch +=  8-pos_f.Gety() + 48 ;
    ch +=  " ";

    return ch;

}
void Deplacement::afficher()
{
    char d[5];
    d[0] = (char)(pos_i.Getx( ) + 97);
    d[1] = 8-pos_i.Gety() + 48 ;
    d[2] = pos_f.Getx()+  97;
    d[3] = 8-pos_f.Gety() + 48 ;
    cout<< d<<"\t";
}

bool Deplacement::operator==(const Deplacement& dep)
{
    return (pos_i == dep.pos_i && pos_f == dep.pos_f);
}

bool Deplacement::dans_echiquier()const
{
    if(pos_i.dans_echiquier() && pos_f.dans_echiquier())
        return true;
    return false;
}
