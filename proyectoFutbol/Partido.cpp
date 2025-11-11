#include "Partido.h"
#include<iostream>
using namespace std;

Partido::Partido(){
    _nroPartido=1;
    _codEstadio=1;
    _codTorneo=1;
    _codClubLocal=1;
    _codClubVisitante=2;
    _golesLocal=0;
    _golesVisitante=0;
}

void Partido::Cargar(){
    cout<<"Numero de Partido: ";
    cin>>_nroPartido;
    cout<<"Codigo de Estadio: ";
    cin>>_codEstadio;
    cout<<"Codigo del Club Local: ";
    cin>>_codClubLocal;
    cout<<"Codigo del Club Visitante: ";
    cin>>_codClubVisitante;
    cout<<"Goles del equipo Local: ";
    cin>>_golesLocal;
    cout<<"Goles del equipo Visitante: ";
    cin>>_golesVisitante;
    cout<<"FECHA DEL PARTIDO: "<<endl;
    fechaDePartido.Cargar();
    _estado=true;
}
void Partido::Cargar(int nroPartido){
    _nroPartido = nroPartido;
    cout<<"Codigo de torneo: ";
    cin>>_codTorneo;
    cout<<"Codigo de Estadio: ";
    cin>>_codEstadio;
    cout<<"Codigo del Club Local: ";
    cin>>_codClubLocal;
    cout<<"Codigo del Club Visitante: ";
    cin>>_codClubVisitante;
    cout<<"Goles del equipo Local: ";
    cin>>_golesLocal;
    cout<<"Goles del equipo Visitante: ";
    cin>>_golesVisitante;
    cout<<"FECHA DEL PARTIDO: "<<endl;
    fechaDePartido.Cargar();
    _estado=true;
}
void Partido::Mostrar(){
    cout<<"Numero de Partido: "<<_nroPartido<<endl;
    cout<<"Numero de Torneo: "<<_codTorneo<<endl;
    cout<<"Codigo de Estadio: "<<_codEstadio<<endl;
    cout<<"Codigo del Club Local: "<<_codClubLocal<<endl;
    cout<<"Codigo del Club Visitante: "<<_codClubVisitante<<endl;
    cout<<"Goles del equipo Local: "<<_golesLocal<<endl;
    cout<<"Goles del equipo Visitante: "<<_golesVisitante<<endl;
    cout<<"FECHA DEL PARTIDO"<<endl;
    fechaDePartido.Mostrar();
}

void Partido::setNroPartido(int nroPartido){
    _nroPartido=nroPartido;
}

void Partido::setCodTorneo(int codTorneo){
    _codTorneo=codTorneo;
}

void Partido::setCodEstadio(int codEstadio){
    _codEstadio=codEstadio;
}

void Partido::setCodClubLocal(int codClubLocal){
    _codClubLocal=codClubLocal;
}

void Partido::setCodClubVisitante(int codClubVisitante){
    _codClubVisitante=codClubVisitante;
}

void Partido::setGolesLocal(int golesLocal){
    _golesLocal=golesLocal;
}

void Partido::setGolesVisitante(int golesVisitante){
    _golesVisitante=golesVisitante;
}

void Partido::setEstado(bool estado){
    _estado = estado;
}

int Partido::getNroPartido(){
    return _nroPartido;
}
int Partido::getCodTorneo(){
    return _codTorneo;
}
int Partido::getCodEstadio(){
    return _codEstadio;
}

int Partido::getCodClubLocal(){
    return _codClubLocal;
}

int Partido::getCodClubVisitante(){
    return _codClubVisitante;
}

int Partido::getGolesLocal(){
    return _golesLocal;
}

int Partido::getGolesVisitante(){
    return _golesVisitante;
}

bool Partido::getEstado(){
    return _estado;
}
