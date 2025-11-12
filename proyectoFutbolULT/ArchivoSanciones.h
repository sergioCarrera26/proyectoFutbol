#pragma once
#include "Sanciones.h"

class ArchivoSanciones{
private:
    std::string _nombreArchivo;
public:
    ArchivoSanciones();
    int agregarRegistro();
    int buscarSancion(int codSancion);
    int cantidadRegistros();
    int mostrarRegistros();
    int buscarRegistro();
    int bajaRegistro();
    Sanciones leer(int posicion);
    int modificarRegistro();
};
