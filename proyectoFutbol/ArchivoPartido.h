#pragma once
#include "Partido.h"

class ArchivoPartido{
private:
    std::string _nombreArchivo;
public:
    ArchivoPartido();
    int agregarRegistro();
    int buscarPartido(int codClub);
    int cantidadRegistros();
    int mostrarRegistros();
    int buscarRegistro();
    int bajaRegistro();
    Partido leer(int posicion);
    int modificarRegistro();
};
