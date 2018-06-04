#include "Position.h"

using namespace std;
Position::Position(int _x , int _y) : x(_x) , y(_y)
{

}
Position::Position():x(0),y(0)
{

}
Position::Position(const Position &p):x(p.x),y(p.y)
{

}

Position::~Position()
{

}
void Position::saisir()
{

    SDL_Event event1;
    Position p;
    string ch;

        while(SDL_WaitEvent(&event1))
    {
        if(event1.type == SDL_QUIT)
        {
            *this =Position(-1,-1);
            return;
        }

        if(event1.type == SDL_KEYDOWN)
        {
            if (event1.key.keysym.sym == SDLK_ESCAPE)
                *this =Position(-1,-1);
                return ;

        }

        if(event1.type == SDL_MOUSEBUTTONDOWN && event1.button.button == SDL_BUTTON_LEFT)
        {

            if(event1.button.x >= 20 && event1.button.x <= 532 && event1.button.y >= 20 && event1.button.y <= 532)
            {

                p.Setx((int)((event1.button.x - 20 )/64));
                p.Sety((int)((event1.button.y - 20 )/64));
                *this = p;
                return;
            }
        }



    }
}
void Position::afficher() const
{
    cout << "x : "<< x<< endl;
    cout << "y : "<< y<<endl;
}

bool Position::operator==(const Position &p)
{
    if(p.x == x && p.y == y)
        return true;
    return false;
}
int Position::chercher(Position lp[],int n)const
{
    for(int i=0;i<n;i++)
        if(lp[i] == *this)
            return i;
    return -1;
}
/*
string Position::transformer()
{
    string ch;
    ch +=  (char)(pos_i.Getx( ) + 97);
    ch +=  8-pos_i.Gety() + 48 ;
    ch +=  pos_f.Getx()+  97;
    ch +=  8-pos_f.Gety() + 48 ;
    ch +=  " ";

    return ch;

}*/



bool Position::dans_echiquier()const
{
    if(x >=0 && x<=7 && y >=0 && y<=7)
        return true;
    return false;
}
