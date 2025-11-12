#include "Torneo.h"
#include<iostream>
#include<cstring>
using namespace std;

Torneo::Torneo():
    fechaInicio(26,6,2026), ///Asi se usa el constructor Fecha(int,int,int)
    fechaFin(23,7,2026)
{
    _codTorneo=15;
    strcpy(_nombre,"Copa Mundial");
    _cantEquipos=32;

}

void Torneo::Cargar(){
    cout<<"Codigo de Torneo: ";
    cin>>_codTorneo;
    cin.ignore();
    cout<<"Nombre: ";
    cin.getline(_nombre,50);
    cout<<"Fecha de inicio: "<<endl;
    fechaInicio.Cargar();
    cout<<"Fecha de finalizacion: "<<endl;
    fechaFin.Cargar();
    cout<<"Cantidad de Equipos: ";
    cin>>_cantEquipos;
    _estado=true;
}

void Torneo::Cargar(int codTorneo){
    _codTorneo = codTorneo;
    cout<<"Nombre: ";
    cin.getline(_nombre,50);
    cout<<"Fecha de inicio: "<<endl;
    fechaInicio.Cargar();
    cout<<"Fecha de finalizacion: "<<endl;
    fechaFin.Cargar();
    cout<<"Cantidad de Equipos: ";
    cin>>_cantEquipos;
    _estado=true;
}

void Torneo::Mostrar(){
    cout<<"Codigo de Torneo: "<<_codTorneo<<endl;
    cout<<"Nombre: "<<_nombre<<endl;
    cout<<"Fecha de inicio: "<<endl;
    fechaInicio.Mostrar();
    cout<<"Fecha de finalizacion: "<<endl;
    fechaFin.Mostrar();
    cout<<"Cantidad de Equipos: "<<_cantEquipos<<endl;
}

void Torneo::setCodTorneo(int codTorneo){
    _codTorneo=codTorneo;
}

void Torneo::setNombre(const char* nombre){
    strcpy(_nombre,nombre);
}

void Torneo::setCantEquipos(int cantEquipos){
    _cantEquipos=cantEquipos;
}


void Torneo::setEstado(bool estado){
    _estado = estado;
}

int Torneo::getCodTorneo(){
    return _codTorneo;
}

const char* Torneo::getNombre(){
    return _nombre;
}

int Torneo::getCantEquipos(){
    return _cantEquipos;
}



bool Torneo::getEstado(){
    return _estado;
}
