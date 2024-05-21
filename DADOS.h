#ifndef DADOS_H_INCLUDED
#define DADOS_H_INCLUDED

#include "rlutil.h"
using namespace std;
using namespace rlutil;

void Backgraund(int posx, int posy){
    setColor(WHITE);
    for(int x=0; x<11; x++){
        for(int y=0; y<5; y++){
           locate(x+posx, y+posy);
           cout<<(char)219;
        }
    }
}

void dibujarPuntos(int c, int posx, int posy){
    setColor(BLACK);
    setBackgroundColor(WHITE);

    switch(c){
        case 1:
            locate(posx+5, posy+2);
            cout<<(char)254;
            break;

        case 2:
            locate(posx+8, posy);
            cout<<(char)220;

            locate(posx+2, posy+3);
            cout<<(char)220;
            break;

        case 3:
            locate(posx+8, posy);
            cout<<(char)220;

            locate(posx+5, posy+2);
            cout<<(char)254;

            locate(posx+2, posy+3);
            cout<<(char)220;
            break;


        case 4:
            locate(posx+8, posy);
            cout<<(char)220;

            locate(posx+2, posy);
            cout<<(char)220;

            locate(posx+8, posy+3);
            cout<<(char)220;

            locate(posx+2, posy+3);
            cout<<(char)220;
            break;

        case 5:
            locate(posx+8, posy);
            cout<<(char)220;

            locate(posx+2, posy);
            cout<<(char)220;

            locate(posx+5, posy+2);
            cout<<(char)254;

            locate(posx+8, posy+3);
            cout<<(char)220;

            locate(posx+2, posy+3);
            cout<<(char)220;
            break;

        case 6:
            locate(posx+8, posy);
            cout<<(char)220;

            locate(posx+2, posy);
            cout<<(char)220;

            locate(posx+2, posy+2);
            cout<<(char)254;
            locate(posx+8, posy+2);
            cout<<(char)254;

            locate(posx+8, posy+3);
            cout<<(char)220;

            locate(posx+2, posy+3);
            cout<<(char)220;
            break;

    }
}
void Dados(int c, int posx, int posy){
    Backgraund(posx, posy);
    dibujarPuntos(c, posx, posy);
    }

#endif // DADOS_H_INCLUDED
