#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "rlutil.h"
#include "DADOS.h"
#include "conio.h"
#include "dos.h"
using namespace rlutil;
using namespace std;

/// Prototipos
void configuracion();
void generar_dados(int *dados, int tam);
void mostrar_dados();
void ordenar_dados(int *dados, int tam);
int calcular_puntaje(int *dados, int tam, bool &ganador);
int tirarDados();
int jugarRonda(char jugador[], int puntaje , int ronda);
void un_jugador(char jugadorMayorPuntaje[], int tamanoNombre, int& high_score);
void dos_jugadores(char jugadorMayorPuntaje[], int tamanoNombre, int& high_score);
void mostrar_high_score(char jugadorMayorPuntaje[], int high_score);
void solicitarNombre(char nombre[], int tamano, int jugador);
void mostrarCreadores();
void pantallaTurno(char jugador[], int ronda, int lanzamiento, int puntajeTotal, int puntajeMaxTurno);
void pantallaEntreTurnos(int ronda, char nombreP1[], char nombreP2[], int puntajeP1, int puntajeP2, int turno);
void dibujoMenu(int PosXchar, int PosYchar);
void mostrarGanador(char jugador[], int puntaje, int ronda, int& high_score, char jugadorMayorPuntaje[]);

// DIBUJO DEL MENU
void dibujoMenu(int PosXchar, int PosYchar){
    int k=1;
    locate (53, 7);
    cout << "QUINIENTOS"<< endl;

    for(k=0; k<=9; k++){
        locate(53+k, 8);
        cout << (char)241 << endl;
    }

    for(int posx=1; posx<=24 ; posx++){
        locate(PosXchar+1, 10);
        cout << (char)205 << endl;
        locate(PosXchar+1, 21);
        cout << (char)205 << endl;
        PosXchar+=1;
    }

    PosXchar=68;
    locate(70, 10);
    cout << (char)187 << endl;
    locate(70, 21);
    cout << (char)188 << endl;
    locate(45, 10);
    cout << (char)201 << endl;
    locate(45, 21);
    cout << (char)200 << endl;

    for(int posy=1; posy<=10 ; posy++){
        locate(45, PosYchar);
        cout << (char)186 << endl;
        PosYchar+=1;
    }

    PosYchar=11;

    for(int posy=1; posy<=10 ; posy++){
        locate(PosXchar+2, PosYchar);
        cout << (char)186 << endl;
        PosYchar+=1;
    }
}

// CONFIGURACION DE BACKGROUND Y MUSICA
void configuracion(void){
    int op=1, i=0;
    int posx=36, posy=8;

    do{
        cls();
        for(int i=1; i<=16; i++){
        locate(posx=36, posy+i);
        cout << (char)186 << endl;
        }

        for(int i=0; i<=24; i++){
        locate(posx+i, posy=25);
        cout << (char)178 << endl;
        }

        for(int i=0; i<=24; i++){
        locate(posx+i, posy=8);
        cout << (char)178 << endl;
        }

        for(int i=1; i<=16; i++){
        locate(posx=60, posy+i);
        cout << (char)186 << endl;
        }

        locate(40, 10);
        cout<< "Elegir Color";
        locate(40, 12);
        cout<< "DARKGREY";
        locate(40, 13);
        cout<< "BLUE";
        locate(40, 14);
        cout<< "RED";
        locate(40, 15);
        cout<< "CYAN";
        locate(40, 16);
        cout<< "MAGENTA";
        locate(40, 17);
        cout<< "BLACK";
        //ESPACIO 6
        locate(40, 19);
        cout<< "Musica";
        locate(40, 20);
        cout<<"Activar";
        locate(40, 21);
        cout<<"Desactivar";
        //ESPACIO 10
        locate(40, 23);
        cout<< "VOLVER";

        locate(38, 12 + i);
        cout<< (char)175 <<endl;

        int key = getkey();

        switch(key)
        {
            case 14://UP
                i--;

                if(i<0){
                    i=0;
                }
                if(i==7){
                    i-=2;
                }
                if(i==10){
                    i--;
                }
                break;
            case 15://DOWN
                i++;

                if(i==6){
                    i+=2;
                }
                if(i==10 || i>11){
                    i=11;
                }
                break;
            case 1://ENTER
                switch(i){

                    case 0:
                        setBackgroundColor(DARKGREY);
                        break;
                    case 1:
                        setBackgroundColor(BLUE);
                        break;
                    case 2:
                        setBackgroundColor(RED);
                        break;
                    case 3:
                        setBackgroundColor(CYAN);
                        break;
                    case 4:
                        setBackgroundColor(MAGENTA);
                        break;
                    case 5:
                        setBackgroundColor(BLACK);
                        break;
                    case 8:
                        //PlaySound(TEXT("WiiTheme.wav"),NULL,SND_ASYNC);
                        break;
                    case 9:
                        //PlaySound(NULL, 0, 0);
                        break;
                    case 11:
                        op=0;

                }
                break;
            default:
                break;
            }

    }while(op!=0);
}

///Funcion que genera los dados de manera aleatoria
void generar_dados(int *dados, int tam){
    srand(time(NULL));
    for(int i = 0; i < tam; i++){
        dados[i] = 1 + rand()% 6;
    }
}

/// Funcion que muestra los dados
void mostrar_dados(int *dados, int tam){
    int posx=5;

    for(int j = 0; j < tam; j++){
        switch(dados[j]){
        case 1:
            Dados(dados[j], posx, 10);
            posx+=13;
            break;
        case 2:
            Dados(dados[j], posx, 10);
            posx+=13;
            break;
        case 3:
            Dados(dados[j], posx, 10);
            posx+=13;
            break;
        case 4:
            Dados(dados[j], posx, 10);
            posx+=13;
            break;
        case 5:
            Dados(dados[j], posx, 10);
            posx+=13;
            break;
        case 6:
            Dados(dados[j], posx, 10);
            posx+=13;
            break;

        }
    }
}

void ordenar_dados(int *dados, int tam){
    for (int j = 0; j < tam; j++)
    {
        for (int i = 0; i < tam; i++){
            if (dados[i] > dados[j]){
                int aux = dados[i];
                dados[i] = dados[j];
                dados[j] = aux;
            }
        }
    }
}

int calcular_puntaje(int *dados, int tam, bool &ganador){/// Funcion que calcula el puntaje, cuenta la cantidad de
    int situacion=0,cnum[6];                                      /// veces que salió cada numero y a traves de eso realiza
    for(int a=0;a<tam;a++){                                     /// el tipo de jugada que es y los puntos que se otorgan
        cnum[a]=0;
    }
    for(int i=0;i<tam;i++){
        if (dados[i]==1){
            cnum[0]++;
        }
    }
    for(int j=0;j<tam;j++){
        if (dados[j]==2){
            cnum[1]++;
        }
    }
    for(int k=0;k<tam;k++){
        if (dados[k]==3){
            cnum[2]++;
        }
    }
    for(int l=0;l<tam;l++){
        if (dados[l]==4){
            cnum[3]++;
        }
    }
    for(int m=0;m<tam;m++){
        if (dados[m]==5){
            cnum[4]++;
        }
    }
    for(int n=0;n<tam;n++){
        if (dados[n]==6){
            cnum[5]++;
        }
    }

    if(cnum[5]==6){                                                                        ///SEXTETO DE SEIS
        situacion=13;
    }else if(cnum[0]==1&&cnum[1]==1&&cnum[2]==1&&cnum[3]==1&&cnum[4]==1&&cnum[5]==1){      ///ESCALERA
        situacion=777;
    }else if(cnum[0]<3&&cnum[1]<3&&cnum[2]<3&&cnum[3]<3&&cnum[4]<3&&cnum[5]<3){            ///SUMA DE DADOS
        situacion=1;
    }else if(cnum[0]==6){                                                                  ///SEXTETO DE UNO
        situacion=2;
    }else if(cnum[1]==6){                                                                  ///SEXTETO DE DOS
        situacion=3;
    }else if(cnum[2]==6){                                                                  ///SEXTETO DE TRES
        situacion=4;
    }else if(cnum[3]==6){                                                                  ///SEXTETO DE CUATRO
        situacion=5;
    }else if(cnum[4]==6){                                                                  ///SEXTETO DE CINCO
        situacion=6;
    }else if((cnum[0]>2&&cnum[0]<6)||(cnum[1]>2&&cnum[1]<6)||(cnum[2]>2&&cnum[2]<6)||(cnum[3]>2&&cnum[3]<6)||(cnum[4]>2&&cnum[4]<6)||(cnum[5]>2&&cnum[5]<6)){
        if(cnum[0]>2){                                                                     ///TRIO DE UNOS
            situacion=7;
        }
        if(cnum[1]>2){                                                                     ///TRIO DE DOS
            situacion=8;
        }
        if(cnum[2]>2){                                                                     ///TRIO DE TRES
            situacion=9;
        }
        if(cnum[3]>2){                                                                     ///TRIO DE CUATROS
            situacion=10;
        }
        if(cnum[4]>2){                                                                     ///TRIO DE CINCOS
            situacion=11;
        }
        if(cnum[5]>2){                                                                     ///TRIOS DE SEIS
            situacion=12;
        }
    }

    return situacion;
}

int tirarDados() {
    const int tamano = 6;
    int puntajeRonda = 0;
    int dados[tamano];
    int posx=5;

    /// Llamar a funcion.
    srand(time(NULL));

    for(int i = 0; i < 6; i++) {
        dados[i] = 1 + rand()% 6;
        //dados[i] =i+1;
    }

    /// llamar funcion.
    for (int j = 0; j < tamano; j++){
        for (int i = 0; i < tamano; i++){
            if (dados[i] > dados[j]){
                int aux = dados[i];
                dados[i] = dados[j];
                dados[j] = aux;
            }
        }
    }

    for(int x = 0; x < tamano; x++){
        switch(dados[x]){
        case 1:
            Dados(dados[x], posx, 10);
            posx+=13;
            break;
        case 2:
            Dados(dados[x], posx, 10);
            posx+=13;
            break;
        case 3:
            Dados(dados[x], posx, 10);
            posx+=13;
            break;
        case 4:
            Dados(dados[x], posx, 10);
            posx+=13;
            break;
        case 5:
            Dados(dados[x], posx, 10);
            posx+=13;
            break;
        case 6:
            Dados(dados[x], posx, 10);
            posx+=13;
            break;
        }


        puntajeRonda += dados[x]; /// Acá reemplazar por lógica de las reglas de puntaje.
    }
    return puntajeRonda;
}

int jugarRonda(char jugador[], int puntaje , int ronda, bool &escalera) {
    const int tam = 6;
    int lanzamiento = 1, puntajeMaxTurno = 0, puntajeLanzamiento = 0, dados[tam], situacion;
    bool sexteto = false, ganador = false;

    for (int i = 0; i < 3; i++) {
        resetColor();
        pantallaTurno(jugador, ronda, lanzamiento, puntaje, puntajeMaxTurno);

        generar_dados(&dados[0],tam);
        ordenar_dados(&dados[0],tam);
        situacion=calcular_puntaje(&dados[0], tam, ganador); /// Ganador no se usa dentro de la func.

        mostrar_dados(dados, tam);
        cout<<endl<<endl<<endl<<endl<<endl;

        switch(situacion){
            case 1:
                puntajeLanzamiento=dados[0]+dados[1]+dados[2]+dados[3]+dados[4]+dados[5];
                cout<<"SUMA DE DADOS! +"<<puntajeLanzamiento<<endl<<endl;
                break;
            case 2:
                puntajeLanzamiento=50;
                cout<<"SEXTETO DE 1! +"<<puntajeLanzamiento<<endl<<endl;
                break;
            case 3:
                puntajeLanzamiento=100;
                cout<<"SEXTETO DE 2! +"<<puntajeLanzamiento<<endl<<endl;
                break;
            case 4:
                puntajeLanzamiento=150;
                cout<<"SEXTETO DE 3! +"<<puntajeLanzamiento<<endl<<endl;
                break;
            case 5:
                puntajeLanzamiento=200;
                cout<<"SEXTETO DE 4! +"<<puntajeLanzamiento<<endl<<endl;
                break;
            case 6:
                puntajeLanzamiento=250;
                cout<<"SEXTETO DE 5! +"<<puntajeLanzamiento<<endl<<endl;
                break;
            case 7:
                puntajeLanzamiento=10;
                cout<<"TRIO DE 1++! +"<<puntajeLanzamiento<<endl<<endl;
                break;
            case 8:
                puntajeLanzamiento=20;
                cout<<"TRIO DE 2++! +"<<puntajeLanzamiento<<endl<<endl;
                break;
            case 9:
                puntajeLanzamiento=30;
                cout<<"TRIO DE 3++! +"<<puntajeLanzamiento<<endl<<endl;
                break;
            case 10:
                puntajeLanzamiento=40;
                cout<<"TRIO DE 4++! +"<<puntajeLanzamiento<<endl<<endl;
                break;
            case 11:
                puntajeLanzamiento=50;
                cout<<"TRIO DE 5++! +"<<puntajeLanzamiento<<endl<<endl;
                break;
            case 12:
                puntajeLanzamiento=60;
                cout<<"TRIO DE 6++! +"<<puntajeLanzamiento<<endl<<endl;
                break;
            case 13:
                puntajeLanzamiento=0;
                sexteto=true;
                cout<<"SEXTETO DE 6! PIERDES TODOS LOS PUNTOS DE LA RONDA :("<<endl<<endl;
                break;
            case 777:
                puntajeLanzamiento=500;
                escalera = true;
                cout<<"ESCALERA! GANASTE LA PARTIDA"<<endl<<endl;
                break;
            default:
                cout<<"Configuracion no programada"<<endl<<endl;
                break;
            }

            if (escalera == true) {
                puntajeMaxTurno = 500;
                resetColor();
                system("pause");
                cls();
                break;
            } else if (sexteto == true) {
                puntajeMaxTurno = 0;
                resetColor();
                system("pause");
                cls();
                break;
            }

            if (puntajeLanzamiento > puntajeMaxTurno) {
                puntajeMaxTurno = puntajeLanzamiento;
            }

            sleep(1);
            lanzamiento++;
            resetColor();
            system("pause");
            cls();
        }

    return puntajeMaxTurno;
}

void un_jugador(char jugadorMayorPuntaje[], int tamanoNombre, int& high_score) {
    cls();
    saveDefaultColor();

    char jugador[tamanoNombre];
    solicitarNombre(jugador, tamanoNombre, 1);
    const int tam=6;
    int n_rondas = 0, punt_total = 0, dados[tam], situacion, max_puntaje_ant=0;
    bool ganador = false;

    while(punt_total<=500 && ganador == false){          //3 rondas
        int lanzamientos = 0, puntaje=0, max_puntaje=0;
        n_rondas++;

        int x=40, y=8;
                                    /// Linea arriba
        for(int p=0; p<=31; p++){
            locate(x+p, y);
            cout << (char)205;
        }

            x=40, y=14;             /// Linea central 1er
        for(int p=0; p<=31; p++){
            locate(x+p, y);
            cout << (char)205;
        }

            x=40, y=11;             /// Linea central 2da
        for(int p=0; p<=31; p++){
            locate(x+p, y);
            cout << (char)205;
        }

            x=40, y=18;             /// Linea abajo
        for(int p=0; p<=31; p++){
            locate(x+p, y);
            cout << (char)205;
        }

            x=39, y=8;              ///Lado iz
        for(int p=0; p<=10; p++){
            locate(x, y+p);
            cout << (char)178;
        }

            x=72, y=8;              ///Lado der
        for(int p=0; p<=10; p++){
            locate(x, y+p);
            cout << (char)178;
        }

        if(n_rondas == 1){
            locate(40, 9);
            cout << "------- INICIA LA PARTIDA ------" << endl;
        } else {
            locate(40, 10);
            cout << "-------- PROXIMA RONDA ---------" << endl;
        }
            locate(52, 12);
            cout << "Ronda: " << n_rondas;
            locate(40, 13);
            cout << "----- Jugador: ";
        setColor(LIGHTRED);
            cout << jugador;
        resetColor();
            locate(40, 15);
            cout << "--                            --" << endl; //funcion nombre
            locate(40, 16);
            cout<<"Puntos de la ronda anterior:  "<<max_puntaje_ant<<endl;
            locate(40, 17);
            cout << "-------- Puntuacion: " << punt_total << " --------" << endl <<endl<<endl;

        system("pause");
        cls();

        while(lanzamientos < 3 && ganador == false ){      //3 lanzamientos
            int lanzamiento1,lanzamiento2,lanzamiento3;
            bool sexteto=false;

            lanzamientos++;
            generar_dados(&dados[0],tam);
            ordenar_dados(&dados[0],tam);
           // dados[0]=1,dados[1]=2,dados[2]=3,dados[3]=4,dados[4]=5,dados[5]=6;
            situacion=calcular_puntaje(&dados[0],tam, ganador);


            cout << "Turno de ";
            setColor(LIGHTRED);
            cout << jugador;
            resetColor();
            cout << " || Ronda: " << n_rondas << " || Puntaje total: " << punt_total << endl;
            cout << "--------------------------------------------------------------------------------------------------------------" << endl;
            cout << "Maximo de puntaje de la ronda: " << max_puntaje << endl <<endl;
            cout << "Lanzamiento: " << lanzamientos << endl;
            cout << "--------------------------------------------------------------------------------------------------------------" << endl;
            cout << "LOS DADOS FUERON TIRADOS!" << endl;

            int posx=0, posy=25;

            for(int i=1; i<=110; i++){
            locate(posx+i, posy);
            cout << (char)205 << endl;
            }
            posx=111;
            posy=0;
            for(int i=1; i<=24; i++){
            locate(posx, posy+i);
            cout << (char)186 << endl;
            }
            locate (111, 25);
            cout << (char) 188;

            mostrar_dados(dados,tam);
            cout<<endl<<endl<<endl<<endl<<endl;


            switch(situacion){
            case 1:
                puntaje=dados[0]+dados[1]+dados[2]+dados[3]+dados[4]+dados[5];
                cout<<"SUMA DE DADOS! +"<<puntaje<<endl<<endl;
                break;
            case 2:
                puntaje=50;
                cout<<"SEXTETO DE 1! +"<<puntaje<<endl<<endl;
                break;
            case 3:
                puntaje=100;
                cout<<"SEXTETO DE 2! +"<<puntaje<<endl<<endl;
                break;
            case 4:
                puntaje=150;
                cout<<"SEXTETO DE 3! +"<<puntaje<<endl<<endl;
                break;
            case 5:
                puntaje=200;
                cout<<"SEXTETO DE 4! +"<<puntaje<<endl<<endl;
                break;
            case 6:
                puntaje=250;
                cout<<"SEXTETO DE 5! +"<<puntaje<<endl<<endl;
                break;
            case 7:
                puntaje=10;
                cout<<"TRIO DE 1++! +"<<puntaje<<endl<<endl;
                break;
            case 8:
                puntaje=20;
                cout<<"TRIO DE 2++! +"<<puntaje<<endl<<endl;
                break;
            case 9:
                puntaje=30;
                cout<<"TRIO DE 3++! +"<<puntaje<<endl<<endl;
                break;
            case 10:
                puntaje=40;
                cout<<"TRIO DE 4++! +"<<puntaje<<endl<<endl;
                break;
            case 11:
                puntaje=50;
                cout<<"TRIO DE 5++! +"<<puntaje<<endl<<endl;
                break;
            case 12:
                puntaje=60;
                cout<<"TRIO DE 6++! +"<<puntaje<<endl<<endl;
                break;
            case 13:
                puntaje=0;
                cout<<"SEXTETO DE 6! PIERDES TODOS LOS PUNTOS DE LA RONDA :("<<endl<<endl;
                sexteto=true;
                break;
            case 777:
                punt_total+=500;
                ganador=true;
                cout<<"ESCALERA! GANASTE LA PARTIDA"<<endl<<endl;
                break;
            default:
                cout<<"Configuracion no programada"<<endl<<endl;
                break;
            }


            if(lanzamientos==1){
                lanzamiento1=puntaje;
            }else if(lanzamientos==2){
                lanzamiento2=puntaje;
            }else if (lanzamientos==3){
                lanzamiento3=puntaje;
            }

            if(lanzamientos==1){
                max_puntaje=puntaje;
            }else if(puntaje>max_puntaje){
                max_puntaje=puntaje;
            }

            if(lanzamientos==3){
                if(sexteto==false){         //si sale sexteto, no se suma ningun punto
                    if(lanzamiento1>=lanzamiento2&&lanzamiento1>=lanzamiento3){
                        punt_total=punt_total+lanzamiento1;
                    }else if(lanzamiento2>=lanzamiento1&&lanzamiento2>=lanzamiento3){
                        punt_total=punt_total+lanzamiento2;
                    }else if(lanzamiento3>=lanzamiento1&&lanzamiento3>=lanzamiento2){
                        punt_total=punt_total+lanzamiento3;
                    }
                }
            }
            max_puntaje_ant=max_puntaje;
            sleep(1);
            resetColor();
            system("pause");
            cls();
        }
    }

    mostrarGanador(jugador, punt_total, n_rondas, high_score, jugadorMayorPuntaje);
    system("pause");
}

void dos_jugadores(char jugadorMayorPuntaje[], int tamanoNombre, int& high_score) {
    const int puntosParaGanar = 500;
    int ronda = 1, puntajeP1 = 0, puntajeP2 = 0;
    bool escalera = false;
    char nombreP1[tamanoNombre];
    char nombreP2[tamanoNombre];

    solicitarNombre(nombreP1, tamanoNombre, 1);
    solicitarNombre(nombreP2, tamanoNombre, 2);

    while (true) {
        puntajeP1 += jugarRonda(nombreP1, puntajeP1, ronda, escalera);

        if (escalera == true) {
            mostrarGanador(nombreP1, puntajeP1, ronda, high_score, jugadorMayorPuntaje);
            break;
        }

        pantallaEntreTurnos(ronda, nombreP1, nombreP2, puntajeP1, puntajeP2, 2);

        puntajeP2 += jugarRonda(nombreP2, puntajeP2, ronda, escalera);

        if (puntajeP1 >= puntosParaGanar || puntajeP2 >= puntosParaGanar) {
            cls();

            if (puntajeP1 > puntajeP2) {
                mostrarGanador(nombreP1, puntajeP1, ronda, high_score, jugadorMayorPuntaje);
            } else if (puntajeP2 > puntajeP1) {
                mostrarGanador(nombreP2, puntajeP2, ronda, high_score, jugadorMayorPuntaje);
            } else {
                cout << "Ambos jugadores empataron con un total de: " << puntajeP1 << " puntos!" << endl;
            }

            break;
        }

        ronda++;
        pantallaEntreTurnos(ronda, nombreP1, nombreP2, puntajeP1, puntajeP2, 1);
    }

    system("pause");
    cls();
}

void mostrar_high_score(char jugadorMayorPuntaje[], int high_score) {
    cls();

    locate(40, 10);
    cout << "----------------------" << endl;
    locate(40, 11);
    cout << "Puntaje: " << high_score << endl;
    locate(40, 12);
    cout << "Jugador: " << jugadorMayorPuntaje << endl << endl;
    locate(40, 13);
    cout << "----------------------" << endl;

    system("pause");
    cls();
}

void mostrarCreadores() {
    cls();

    locate(49, 10);
    cout << "----------------------" << endl;
    locate(49, 11);
    cout << "Bruno | Marco | Juan" << endl << endl;
    locate(49, 12);
    cout << "----------------------" << endl;
    locate(1, 14);
    cout << "Alumnos de la Universidad Tecnologica Nacional. Este juego es el trabajo de los 3 integrantes ya mencionados, con mucha dedicacion y esfuerzo, esperamos que les guste." << endl<<endl;
    system("pause");
    cls();
}

void solicitarNombre(char nombre[], int tamano, int jugador) {
    /// Obtenemos el vector que se modificará los modos de juego y el tamano max del nombre.
    /// Mientras que el nombre ingresado sea " " o nada, se seguirá solicitando.

    cls();
    showcursor();
    int posx=36, posy=8;

    do {
        for(int i=1; i<=16; i++){
            locate(posx=36, posy+i);
            cout << (char)186 << endl;
        }

        locate(40, 10);
        cout << "Ingrese nombre jugador " << jugador << endl;
        locate(40, 12);
        cin.getline(nombre, tamano);
    } while (cin.fail() || nombre[0] == '\0' || nombre[0] == ' ');

    hidecursor();
    cls();
}

void pantallaTurno(char jugador[], int ronda, int lanzamiento, int puntajeTotal, int puntajeMaxTurno) {
    cls();

    cout << "Turno de " << jugador << "  |  Ronda " << ronda << "  |  Puntaje total: " << puntajeTotal << " puntos" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Maximo puntaje de la ronda: " << puntajeMaxTurno << " puntos" << endl << endl;
    cout << "Lanzamiento " << lanzamiento << endl;
    cout << "--------------------------------------------------------------------------------------------------------------" << endl;
    int posx=0, posy=25;

    for(int i=1; i<=110; i++){
        locate(posx+i, posy);
        cout << (char)205 << endl;
    }
    posx=111;
    posy=0;
    for(int i=1; i<=24; i++){
        locate(posx, posy+i);
        cout << (char)186 << endl;
    }

    locate (111, 25);
    cout << (char) 188;
}

void pantallaEntreTurnos(int ronda, char nombreP1[], char nombreP2[], int puntajeP1, int puntajeP2, int turno) {
    cls();

    int x=40, y=8;
                                    /// Linea arriba
        for(int p=0; p<=31; p++){
            locate(x+p, y);
            cout << (char)205;
        }

            x=40, y=14;             /// Linea central 1er
        for(int p=0; p<=31; p++){
            locate(x+p, y);
            cout << (char)205;
        }

            x=40, y=11;             /// Linea central 2da
        for(int p=0; p<=31; p++){
            locate(x+p, y);
            cout << (char)205;
        }

            x=40, y=18;             /// Linea abajo
        for(int p=0; p<=31; p++){
            locate(x+p, y);
            cout << (char)205;
        }

            x=39, y=8;              ///Lado iz
        for(int p=0; p<=10; p++){
            locate(x, y+p);
            cout << (char)178;
        }

            x=72, y=8;              ///Lado der
        for(int p=0; p<=10; p++){
            locate(x, y+p);
            cout << (char)178;
        }

    locate(51, 9);
    cout << "Ronda " << ronda;
    locate(42, 12);
    cout << "Proximo turno: ";
    if (turno == 1) {
        locate(42, 13);
         cout << nombreP1;
    } else {
         locate(42, 13);
        cout << nombreP2;
    }
    cout << endl << endl;
     locate(42, 15);
    cout << "Puntaje " << nombreP1 << ": " << puntajeP1;
     locate(42, 17);
    cout << "Puntaje " << nombreP2 << ": " << puntajeP2 << endl<<endl<<endl;


    system("pause");
}

void mostrarGanador(char jugador[], int puntaje, int ronda, int& high_score, char jugadorMayorPuntaje[]) {
    cout<<"---------------------------------"<<endl;
    cout<<"             GANASTE!            "<<endl;
    cout<<"           "<< jugador<<endl;
    cout<<"   PUNTUACION FINAL: "<<puntaje<<endl;
    cout<<"   CANTIDAD DE RONDAS: "<<ronda<<endl;
    cout<<"---------------------------------"<<endl;

    if (puntaje > high_score) {
        high_score = puntaje;
        strcpy(jugadorMayorPuntaje, jugador);
    }
}

#endif // FUNCIONES_H_INCLUDED
