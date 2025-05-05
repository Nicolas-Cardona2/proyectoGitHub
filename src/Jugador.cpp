#include "../include/Jugador.h"

Jugador::Jugador(string nombre) : nombre(nombre), puntaje(0){

}
void Jugador::setNombre(string nombre){
    this->nombre = nombre;
}
string Jugador::getNombre() const{
    return nombre;
}
void Jugador::agregarPuntos(int puntos){
    this->puntaje += puntos;
}
int Jugador::getPuntaje() const{
    return puntaje;
}