#include <iostream>
#include "Jugador.h"
using namespace std;

Jugador::Jugador(){
    //Persona(); No hace falta poner el constructor Persona() porque lo hereda automaticamente.
    _codClub=1;
}

void Jugador::setCodClub(int codClub){
    _codClub=codClub;
}

void Jugador::setEstado(bool estado){
    _estado = estado;
}

int Jugador::getCodClub(){
    return _codClub;
}

void Jugador::Cargar(){
    Persona::Cargar();
    cin.ignore();
    cout<<"Codigo Club: ";
    cin>>_codClub;
    _estado=true;
}

bool Jugador::getEstado(){
    return _estado;
}

Fecha Jugador::getFechanacimiento(){
    return fechaNacimiento;
}

void Jugador::Cargar(char* DNI, int codClub){
    Persona::Cargar(DNI);
    _codClub = codClub;
    _estado = true;
}

void Jugador::Mostrar(){
    Persona::Mostrar();
    cout<<"Codigo Club: "<<_codClub<<endl;
}



