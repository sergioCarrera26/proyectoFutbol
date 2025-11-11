#pragma once
#include "Estadio.h"

class ArchivoEstadio{
private:
    std::string _nombreArchivo;
public:
    ArchivoEstadio();
    int agregarRegistro();
    int buscarEstadio(int codEstadio);
    int cantidadRegistros();
    int mostrarRegistros();
    int buscarRegistro();
    int bajaRegistro();
    Estadio leer(int posicion);
    int modificarRegistro();
};
