#include "Estadio.h"
#include<iostream>
#include<cstring>
using namespace std;

Estadio::Estadio(){
    _codEstadio = 100;
    _codClub = 1;
    strcpy(_nombre,"Libertadores de America");
    _capacidad = 50000;
}

void Estadio::Cargar(){
    cout<<"Codigo de Estadio: ";
    cin>>_codEstadio;
    cout<<"Codigo de Club: ";
    cin>>_codClub;
    cin.ignore();
    cout<<"Nombre: ";
    cin.getline(_nombre,50);
    cout<<"Capacidad: ";
    cin>>_capacidad;
    _estado=true;
}

void Estadio::Cargar(int codEstadio, int codClub){
    _codEstadio=codEstadio;
    _codClub=codClub;
    cout<<"Nombre: ";
    cin.getline(_nombre,50);
    cout<<"Capacidad: ";
    cin>>_capacidad;
    _estado=true;
}


void Estadio::Mostrar(){
    cout<<"Codigo de Estadio: "<<_codEstadio<<endl;
    cout<<"Codigo de Club: "<<_codClub<<endl;
    cout<<"Nombre: "<<_nombre<<endl;
    cout<<"Capacidad: "<<_capacidad<<" personas"<<endl;
}

void Estadio::setCodEstadio(int codEsttadio){
    _codEstadio=codEsttadio;
}

void Estadio::setCodClub(int codClub){
    _codClub=codClub;
}

void Estadio::setNombre(const char* nombre){
    strcpy(_nombre,nombre);
}

void Estadio::setCapacidad(int capacidad){
    _capacidad = capacidad;
}

void Estadio::setEstado(bool estado){
    _estado = estado;
}

int Estadio::getCodEstadio(){
    return _codEstadio;
}

int Estadio::getCodClub(){
    return _codClub;
}

const char* Estadio::getNombre(){
    return _nombre;
}

int Estadio::getCapacidad(){
    return _capacidad;
}
bool Estadio::getEstado(){
    return _estado;
}
