#pragma once ///lo usa c++
#include "Fecha.h"

class Persona{
protected:
    char _DNI[9];
    char _nombre[30];
    char _apellido[30];
    char _telefono[20];
    char _mail[50];
    Fecha fechaNacimiento;
public:
    Persona();
    void Cargar();
    void Cargar(char* DNI);

    void Mostrar();
    void setDNI(const char* DNI);
    void setNombre(const char* nombre);
    void setApellido(const char* apellido);
    void setTelefono(const char* telefono);
    void setMail(const char* mail);
    char* getDNI();
    char* getNombre();
    char* getApellido();
    char* getTelefono();
    char* getMail();
};
