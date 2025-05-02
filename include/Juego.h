#ifndef JUEGO_H
#define JUEGO_H

#include <string>
using namespace std;

class Juego {
    public:
        virtual void jugar() = 0;
        virtual void mostrarResultados() = 0;
        virtual ~Juego() {}
};

#endif