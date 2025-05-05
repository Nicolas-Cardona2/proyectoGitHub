#include "../include/Ahorcado.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

Ahorcado::Ahorcado(vector<Jugador*>& jugadores, bool contraCPU)
    : jugadores(jugadores), intentosRestantes(6), contraCPU(contraCPU){

    }

void Ahorcado::seleccionarPalabra(){
    if(contraCPU){
        cargarPalabraDesdeArchivo();
    }else{
        cout<< jugadores[0]->getNombre()<<"ingrese la palabra secreta: ";
        cin>>palabraSecreta;
        system("cls");
    }
    estadoDePalabra = string(palabraSecreta.length(), '_');
}

void Ahorcado::cargarPalabraDesdeArchivo(){
    ifstream archivo("palabras.txt");
    vector<string> palabras;
    string linea;
    while(getline(archivo, linea)){
        palabras.push_back(linea);
    }
    srand(time(nullptr));
    palabraSecreta = palabras[rand() % palabras.size()];
}

void Ahorcado::mostrarEstado(){
    cout<< "palabra" << estadoDePalabra << "| intentos restantes: "<< intentosRestantes <<endl;
}

void Ahorcado::jugar(){
    seleccionarPalabra();
    Jugador* adivinador = contraCPU ? jugadores[0] : jugadores[1];
    char letra;
    bool gano = false;

    while(intentosRestantes > 0 && estadoDePalabra != palabraSecreta){
        mostrarEstado();
        cout<< adivinador->getNombre()<<"ingrese una letra: ";
        cin>> letra;

        bool acierto = false;
        for(size_t i = 0; i < palabraSecreta.length(); ++i){
            if(palabraSecreta[i]==letra && estadoDePalabra[i]=='_'){
                estadoDePalabra[i] = letra;
                acierto = true;
            }
        }
        if(!acierto) intentosRestantes--;
    }
    gano = (estadoDePalabra == palabraSecreta);
    if(gano){
        cout<<"!bien hecho¡ la palabra era: "<<palabraSecreta<<endl;
        adivinador->agregarPuntos(10);

    }else{
        cout<<"!paila¡ la palabra era: "<<palabraSecreta<<endl;
    }
    guardarResultados(adivinador, gano);

}

void Ahorcado::guardarResultados(Jugador* jugador, bool gano){
    ofstream archivo("resultados.txt", ios::app);
    time_t now = time(0);
    tm* local = localtime(&now);
    archivo<< local->tm_mday<<"/"<<local->tm_mon + 1<<"/"<<1900+local->tm_year<<" "
    <<jugador->getNombre()<<" Ahorcado "<<(gano ? "gano":"perdio")<< " "<<jugador->getPuntaje()<<endl;
}

void Ahorcado::mostrarResultados(){
cout<< "puntajes:\n";
    for(Jugador* j : jugadores){
        cout<< j->getNombre()<<": "<<j->getPuntaje()<<" puntos\n";
    }
}
