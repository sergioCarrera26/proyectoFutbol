#include "Club.h"
#include <iostream>
#include <cstring>
using namespace std;

Club::Club(){
    _codClub=1;
    strcpy(_nombre,"Independiente");
    strcpy(_presidente,"Alejandro");
    strcpy(_DT,"Tevez");
}

void Club::Cargar(){
    cout<<"Codigo Club: ";
    cin>>_codClub;
    cin.ignore();
    cout<<"Nombre: ";
    cin.getline(_nombre,30);
    cout<<"Presidente: ";
    cin.getline(_presidente,30);
    cout<<"Director Tecnico: ";
    cin.getline(_DT,30);
    _estado=true;
}
void Club::Cargar(int codClub){
    _codClub=codClub;

    cout<<"Nombre: ";
    cin.getline(_nombre,30);
    cout<<"Presidente: ";
    cin.getline(_presidente,30);
    cout<<"Director Tecnico: ";
    cin.getline(_DT,30);
    _estado=true;
}

void Club::Mostrar(){
    cout<<"Club: "<<_codClub<<endl;
    cout<<"Nombre: "<<_nombre<<endl;
    cout<<"Presidente: "<<_presidente<<endl;
    cout<<"Director Tecnico: "<<_DT<<endl;
}


void Club::setClub(int codClub){
    _codClub=codClub;
}

void Club::setNombre(const char* nombre){
    strcpy(_nombre,nombre);
}

void Club::setPresidente(const char* presidente){
    strcpy(_presidente,presidente);
}
void Club::setEstado(bool estado){
    _estado=estado;
}

void Club::setDT(const char* DT){
    strcpy(_DT,DT);
}

int Club::getClub(){
    return _codClub;
}

char* Club::getNombre(){
    return _nombre;
}

char* Club::getPresidente(){
    return _presidente;
}

char* Club::getDT(){
    return _DT;
}

bool Club::getEstado(){
    return _estado;
}
