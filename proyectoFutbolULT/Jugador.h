#pragma once ///lo usa c++
#include "Persona.h"

class Jugador: public Persona{
private:
    int _codClub;
    bool _estado;
public:
    Jugador();
    void Cargar();
    void Cargar(char* DNI, int codClub);
    void Mostrar();
    //setters
    void setCodClub(int codClub);
    void setEstado(bool estado);
    //getters
    int getCodClub();
    bool getEstado();
    Fecha getFechanacimiento();
};

