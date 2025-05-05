#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
using namespace std;

class Jugador {
    public:
        Jugador(string nombre = "");
        void setNombre(string nombre);
        string getNombre() const;
        void agregarPuntos(int puntos);
        int getPuntaje() const;

    private:
        string nombre;
        int puntaje;
};

#endif