#include "Fecha.h"
#include <iostream>
using namespace std;

bool Fecha::esBisiesto(int anio){
    return (anio%4==0 && anio%100!=0) || (anio%400==0);
}

bool Fecha::esFechaValida(int dia, int mes, int anio){
    if(anio<1 || mes<1 || mes>12 || dia<1){
        return false;
    }
    int diasEnMes[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(mes==2 && esBisiesto(anio)){
        diasEnMes[1]=29;
    }
    return dia<=diasEnMes[mes-1];
}
/*****************************************************/

Fecha::Fecha(){
    _dia=26;
    _mes=7;
    _anio=1995;
}

Fecha::Fecha(int dia, int mes, int anio){
    if(esFechaValida(dia,mes,anio)){
        _dia=dia;
        _mes=mes;
        _anio=anio;
    }
    else{
        _dia=1;
        _mes=1;
        _anio=2023;
    }
}

void Fecha::Cargar(){
    int dia,mes,anio;
    cout<<"Dia: ";
    cin>>dia;
    cout<<"Mes: ";
    cin>>mes;
    cout<<"Anio: ";
    cin>>anio;
    while(!esFechaValida(dia,mes,anio)){
        cout<<"Fecha invalida. Intente nuevamente:"<<endl;
        cout<<"Dia: ";
        cin>>dia;
        cout<<"Mes: ";
        cin>>mes;
        cout<<"Anio: ";
        cin>>anio;
    }
    _dia=dia;
    _mes=mes;
    _anio=anio;
}

void Fecha::Mostrar(){
    cout<<_dia<<"/"<<_mes<<"/"<<_anio<<endl;
}

void Fecha::setDia(int dia){
    if(esFechaValida(dia,_mes,_anio)){
        _dia = dia;
    }
}

void Fecha::setMes(int mes){
    if(esFechaValida(_dia,mes,_anio)){
        _mes = mes;
    }
}

void Fecha::setAnio(int anio){
    if(esFechaValida(_dia,_mes,anio))
        _anio=anio;
}

int Fecha::getDia(){
    return _dia;
}

int Fecha::getMes(){
    return _mes;
}

int Fecha::getAnio(){
    return _anio;
}
