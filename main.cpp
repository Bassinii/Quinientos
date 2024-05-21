#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "Funciones.h"
#include "rlutil.h"
#include "DADOS.h"

using namespace std;
using namespace rlutil;


/// Prototipos
void configuracion();
void un_jugador(char jugadorMayorPuntaje[], int tamanoNombre, int& highScore);
void dos_jugadores(char jugadorMayorPuntaje[], int tamanoNombre, int& highScore);
void mostrar_high_score(char jugadorMayorPuntaje[], int highScore);
void mostrarCreadores();
void dibujoMenu(int PosXchar, int PosYchar);

int main()
{
    int Y = 0, high_score = 0;
    int PosXchar = 45, PosYchar=11;
    const int posxMenu = 48;
    const int tamanoNombre = 30;
    char jugadorMayorPuntaje[tamanoNombre];
    setBackgroundColor(DARKGREY);

    //PlaySound(TEXT("WiiTheme.wav"),NULL,SND_ASYNC);

    hidecursor();
    system("Title ESCALERA DE DADOS");

    while (true) {
        cls();
        dibujoMenu( PosXchar,  PosYchar);
        setColor(WHITE);
        locate(posxMenu, 11);
        cout << "------- MENU -------" << endl;
        locate(posxMenu, 12);
        cout << "--------------------" << endl;
        locate(posxMenu, 13);
        cout << "MODO 1 JUGADOR" << endl;
        locate(posxMenu, 14);
        cout << "MODO 2 JUGADORES" << endl;
        locate(posxMenu, 15);
        cout << "PUNTUACION MAS ALTA" << endl;
        locate(posxMenu, 16);
        cout << "CREADORES" << endl;
        locate(posxMenu, 17);
        cout << "CONFIGURACION" << endl;
        locate(posxMenu, 19);
        cout << "SALIR DEL JUEGO" << endl;
        locate(posxMenu, 20);
        cout << "--------------------" << endl;

        /// Seleccion
        locate(46, 13 + Y);
        cout << (char)175 << endl;

        int key = getkey();

        switch (key) {
            /// Tecla UP
            case 14:
                locate(46, 13 + Y);
                cout << " " << endl;

                if (Y > 0) {
                    Y--;
                }

                if (Y == 5) {
                    Y-=1;
                }

                break;
            /// Tecla DOWN
            case 15:
                locate(46, 13 + Y);
                cout << " " << endl;

                if (Y < 6) {
                    Y++;
                }
                if (Y == 5) {
                    Y+=1;
                }

                break;
            /// Tecla ENTER
            case 1:
                if (Y == 0) {
                    un_jugador(jugadorMayorPuntaje, tamanoNombre, high_score);
                }

                if (Y == 1) {
                    dos_jugadores(jugadorMayorPuntaje, tamanoNombre, high_score);
                }

                if (Y == 2) {
                    mostrar_high_score(jugadorMayorPuntaje, high_score);
                }

                if (Y == 3) {
                    mostrarCreadores();
                }

                if (Y == 4) {
                    configuracion();
                }

                if (Y == 6) {
                    cls();
                    locate(48, 13);
                    cout << "Gracias por jugar!" << endl;
                    return 0;
                }

                break;
            default:
                cls();
                break;
        }

        PosXchar = 45;
        PosYchar=11;
    }

    return 0;
}
