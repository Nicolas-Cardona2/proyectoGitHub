#ifndef CONCENTRESE_H
#define CONCENTRESE_H

#include "Juego.h"
#include "Jugador.h"
#include <vector>
#include <string>
#include <utility>

using namespace std;

class Concentrese : public Juego {
    public:
        Concentrese(vector<Jugador*>& jugadores);
        void jugar() override;
        void mostrarResultados() override;

    private:
        void cargarDesdeArchivo();
        void mezclarCartas();
        void mostrarTablero();
        void guardarResultados(Jugador* jugador, bool gano);

        vector<Jugador*> jugadores;
        vector<pair<string, string>> pares;
        vector<string> tablero;
        vector<bool> descubiertas;
        int filas, columnas;

};

#endif

