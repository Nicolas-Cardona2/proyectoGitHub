#include <iostream>
#include <string>
#include <vector>
#include "Jugador.h"
#include "Ahorcado.h"
#include "Concentrese.h"

using namespace std;

int main()
{
    vector<Jugador*> jugadores;
    int numJugadores;

    cout<<"Bienvenido a los minijuegos\n";
    cout<<"Cuantos jugadores son? (1 o 2): ";
    cin>>numJugadores;

    for(int i = 0; i <numJugadores; ++i){
        string nombre;
        cout<<"nombre del jugador: "<<(i + 1)<<": ";
        cin>>nombre;
        jugadores.push_back(new Jugador(nombre));
    }

    int opcionJuego;
    cout<<"---Seleccione el juego---\n";
    cout<<"1.Ahorcado\n";
    cout<<"2.Concentrese\n";
    cout<<"Opcion: ";
    cin>>opcionJuego;

    Juego* juego = nullptr;

    if(opcionJuego == 1){
        bool contraCPU = false;
        if(numJugadores == 1){
            cout<<"Contra CPU\n";
            contraCPU = true;
        }else{
            char elegirModo;
            cout<<"Jugador 1 escoge la palabra? (s/n): ";
            cin>>elegirModo;
            contraCPU = (elegirModo == 'n' || elegirModo == 'N');
        }
        juego = new Ahorcado(jugadores, contraCPU);

    }else if(opcionJuego == 2){
        juego = new Concentrese(jugadores);
    }else{
        cout<<"opcion invalida\n";
        return 1;
    }

    juego->jugar();
    juego->mostrarResultados();

    delete juego;
    for(Jugador* j: jugadores) delete j;
    return 0;
}
