#include "Sanciones.h"
#include<iostream>
#include<cstring>
using namespace std;

Sanciones::Sanciones(){
    _nroSancion=1;
    strcpy(_DNIjugador,"39588420");
    _nroPartido=1;
    _tipoTarjeta=2;
    _cantFechasSuspension=1;
}

void Sanciones::Cargar(){
    cout<<"Numero de Sancion: ";
    cin>>_nroSancion;
    cin.ignore();
    cout<<"DNI del Jugador: ";
    cin.getline(_DNIjugador,20);
    cout<<"Numero de Partido: ";
    cin>>_nroPartido;
    while(true){
        cout<<"Tipo de Tarjeta( 1 = amarilla, 2 = roja): ";
        cin>>_tipoTarjeta;
        if(_tipoTarjeta==1 || _tipoTarjeta==2){
            break;
        }
        cout<<"Dato invalido, intente nuevamente!!!"<<endl;
    }
    cout<<"Cantidad de fechas Suspendido: ";
    cin>>_cantFechasSuspension;
    _estado=true;
}
void Sanciones::Cargar(int nroSancion){
    _nroSancion = nroSancion;
    cout<<"DNI del Jugador: ";
    cin.getline(_DNIjugador,20);
    cout<<"Numero de Partido: ";
    cin>>_nroPartido;
    while(true){
        cout<<"Tipo de Tarjeta( 1 = amarilla, 2 = roja): ";
        cin>>_tipoTarjeta;
        if(_tipoTarjeta==1 || _tipoTarjeta==2){
            break;
        }
        cout<<"Dato invalido, intente nuevamente!!!"<<endl;
    }
    cout<<"Cantidad de fechas Suspendido: ";
    cin>>_cantFechasSuspension;
    _estado=true;
}
void Sanciones::Mostrar(){
    cout<<"Numero de Sancion: "<<_nroSancion<<endl;
    cout<<"DNI del Jugador: "<<_DNIjugador<<endl;
    cout<<"Numero de Partido: "<<_nroPartido<<endl;
    cout<<"Tipo de Tarjeta: ";
    if(_tipoTarjeta==1){
        cout<<"Amarilla"<<endl;
    }
    else{
        cout<<"Roja"<<endl;
    }
    cout<<"Cantidad de fechas suspendido: "<<_cantFechasSuspension<<endl;
}

void Sanciones::setNroSancion(int nroSancion){
    _nroSancion=nroSancion;
}

void Sanciones::setDNIjugador(const char* DNIjugador){
    strcpy(_DNIjugador,DNIjugador);
}

void Sanciones::setNroPartido(int nroPartido){
    _nroPartido=nroPartido;
}

void Sanciones::setTipoTarjeta(int tipoTarjeta){
    _tipoTarjeta=tipoTarjeta;
}

void Sanciones::setCantFechasSuspension(int cantFechasSuspension){
    _cantFechasSuspension=cantFechasSuspension;
}
void Sanciones::setEstado(bool estado){
    _estado = estado;
}

int Sanciones::getNroSancion(){
    return _nroSancion;
}

const char* Sanciones::getDNIjugador(){
    return _DNIjugador;
}

int Sanciones::getNroPartido(){
    return _nroPartido;
}

int Sanciones::getTipoTarjeta(){
    return _tipoTarjeta;
}

int Sanciones::getCantFechasSuspension(){
    return _cantFechasSuspension;
}

bool Sanciones::getEstado(){
    return _estado;
}
