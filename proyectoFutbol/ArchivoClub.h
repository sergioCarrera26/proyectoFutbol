#pragma once
#include "Club.h"

class ArchivoClub{
private:
    std::string _nombreArchivo;
public:
    ArchivoClub();
    int agregarRegistro();
    int buscarClub(int codClub);
    int cantidadRegistros();
    int mostrarRegistros();
    int buscarRegistro();
    int bajaRegistro();
    Club leer(int posicion);
    int modificarRegistro();
    int cantidadRegistrosActivos();

};
