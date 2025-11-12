#include "Persona.h"
#include<iostream>
#include<cstring>
using namespace std;

Persona::Persona(){
    strcpy(_DNI,"39588420");
    strcpy(_nombre,"Sergio");
    strcpy(_apellido,"Carrera");
    strcpy(_telefono,"1162466644");
    strcpy(_mail,"sergio.carrera@utn");
}

void Persona::Cargar(){
    cout<<"DNI: ";
    cin.getline(_DNI,9);
    cout<<"Nombre: ";
    cin.getline(_nombre,30);
    cout<<"Apellido: ";
    cin.getline(_apellido,30);
    cout<<"Telefono: ";
    cin.getline(_telefono,11);
    cout<<"Mail: ";
    cin.getline(_mail,50);
    cout<<"Fecha de Nacimiento"<<endl;
    fechaNacimiento.Cargar();
}

void Persona::Cargar(char *DNI){

    strcpy(_DNI,DNI);
    cout<<"Nombre: ";
    cin.getline(_nombre,30);
    cout<<"Apellido: ";
    cin.getline(_apellido,30);
    cout<<"Telefono: ";
    cin.getline(_telefono,11);
    cout<<"Mail: ";
    cin.getline(_mail,50);
    cout<<"Fecha de Nacimiento"<<endl;
    fechaNacimiento.Cargar();
}

void Persona::Mostrar(){
    cout<<"DNI: "<<_DNI<<endl;
    cout<<"Nombre: "<<_nombre<<endl;
    cout<<"Apellido: "<<_apellido<<endl;
    cout<<"Telefono: "<<_telefono<<endl;
    cout<<"Mail: "<<_mail<<endl;
    cout<<"Fecha de Nacimiento: ";
    fechaNacimiento.Mostrar();
}

void Persona::setDNI(const char* DNI){
    strcpy(_DNI,DNI);
}

void Persona::setNombre(const char* nombre){
    strcpy(_nombre,nombre);
}

void Persona::setApellido(const char* apellido){
    strcpy(_apellido,apellido);
}

void Persona::setTelefono(const char* telefono){
    strcpy(_telefono,telefono);
}

void Persona::setMail(const char* mail){
    strcpy(_mail,mail);
}

char* Persona::getDNI(){
    return _DNI;
}

char* Persona::getNombre(){
    return _nombre;
}

char* Persona::getApellido(){
    return _apellido;
}

char* Persona::getTelefono(){
    return _telefono;
}

char* Persona::getMail(){
    return _mail;
}
