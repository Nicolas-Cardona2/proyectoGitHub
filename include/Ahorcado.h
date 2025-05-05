#ifndef AHORCADO_H
#define AHORCADO_H

#include "Juego.h"
#include "Jugador.h"
#include <vector>
#include <string>

using namespace std;

class Ahorcado : public Juego {
    public:
        Ahorcado(vector<Jugador*>& jugadores, bool contraCPU);
        void jugar() override;
        void mostrarResultados() override;

    private:
        void seleccionarPalabra();
        void cargarPalabraDesdeArchivo();
        void mostrarEstado();
        void guardarResultados(Jugador* jugador, bool gano);

        vector<Jugador*> jugadores;
        string palabraSecreta;
        string estadoDePalabra;
        int intentosRestantes;
        bool contraCPU;
};

#endif