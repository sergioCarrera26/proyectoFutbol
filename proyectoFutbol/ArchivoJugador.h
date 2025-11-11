#pragma once
#include "Jugador.h"

class ArchivoJugador{
private:
    std::string _nombreArchivo;
public:
    ArchivoJugador();
    int agregarRegistro();
    int buscarJugador(char* DNI);
    int cantidadRegistros();
    int mostrarRegistros();
    int buscarRegistro();
    int bajaRegistro();
    int modificarRegistro();
    Jugador leer(int posicion);
    void ordenarXEdad();
    void listarXEquipo();
    int cantidadRegistrosActivos();
    int buscarXNombre();

};
