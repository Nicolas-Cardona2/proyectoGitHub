#include "../include/Concentrese.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

Concentrese::Concentrese(vector<Jugador*>& jugadores) : jugadores(jugadores), filas(4), columnas(4){
    cargarDesdeArchivo();
    mezclarCartas();
    tablero = vector<string>(); // Initialize tablero
    descubiertas = vector<bool>(tablero.size(), false);
}

void Concentrese::cargarDesdeArchivo(){
    ifstream archivo("cartas.txt");
    string a, b;
    while(archivo >> a >> b){
        pares.push_back({a, b});
    }
}
void Concentrese::mezclarCartas(){
    for(const auto& par : pares){
        tablero.push_back(par.first);
        tablero.push_back(par.second);
    }
    srand(time(nullptr));
    random_shuffle(tablero.begin(), tablero.end());
}

void Concentrese:: mostrarTablero(){
    cout<<"El tablero: \n";
    for(size_t i = 0; i < tablero.size(); ++i){
        if (descubiertas[i]){
            cout<< "["<<tablero[i]<<"]";
        }else{
            cout<<"["<< i << "]";
        }

        if ((i+1) % columnas == 0) cout<<endl;
    }
}

void Concentrese::jugar(){
    int turno = 0;
    int totalPares = tablero.size() / 2;
    int paresEncontrados = 0;

    while(paresEncontrados < totalPares){
        mostrarTablero();
        Jugador* jugadorActual = jugadores[turno % jugadores.size()];
        cout<< jugadorActual->getNombre()<<" escoge 2 posiciones: ";
        int pos1, pos2;
        cin>>pos1>>pos2;

        if(pos1 == pos2 || pos1 < 0 || pos2 < 0 || pos1 >= (int)tablero.size() || pos2 >= (int)tablero.size() || descubiertas[pos1] || descubiertas[pos2]){
            cout<<"estas posiciones no son validas, intente de nuevo \n";
            continue;
        }

        cout<<"escogiste: "<<tablero[pos1]<<" y "<<tablero[pos2]<<endl;

        if(tablero[pos1] == tablero[pos2]){
            cout<<"Encontraste un par!"<<endl;
            descubiertas[pos2], descubiertas[pos2] = true;
            jugadorActual->agregarPuntos(10);
            paresEncontrados++;
        }else{
            cout<<"no es un par \n";
            turno++;
        }
        cout<<endl;
    }
    for(Jugador* j : jugadores){
        guardarResultados(j, true);
    }
}

void Concentrese::guardarResultados(Jugador* jugador, bool gano){
    ofstream archivo("resultados.txt", ios::app);
    time_t now = time(0);
    tm* local = localtime(&now);
    archivo<< local->tm_mday<<"/"<<local->tm_mon + 1<<"/"<<1900+local->tm_year<<" "<<jugador->getNombre()<<"concentrese "<<(gano ? "gano":"perdio")<<" "<<jugador->getPuntaje()<<endl;
}

void Concentrese::mostrarResultados(){
    cout<<"puntajes:\n";
    for(Jugador* j : jugadores){
        cout<< j->getNombre()<<": "<<j->getPuntaje()<<" puntos\n";
    }
}

