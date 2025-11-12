#pragma once
#include "Torneo.h"

class ArchivoTorneo{
private:
    std::string _nombreArchivo;
public:
    ArchivoTorneo();
    int agregarRegistro();
    int buscarTorneo(int codTorneo);
    int cantidadRegistros();
    int mostrarRegistros();
    int buscarRegistro();
    int bajaRegistro();
    Torneo leer(int posicion);
    int modificarRegistro();
};
