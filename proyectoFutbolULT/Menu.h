#pragma once
#include"Jugador.h"
#include"Club.h"
#include"Partido.h"
#include"Torneo.h"
#include"Sanciones.h"
#include"Estadio.h"
#include"ArchivoJugador.h"
#include"ArchivoClub.h"
#include"ArchivoPartido.h"
#include"ArchivoTorneo.h"
#include"ArchivoSanciones.h"
#include"ArchivoEstadio.h"

class Menu{
private:
    Jugador _jugado;
    Club _club;
    Partido _partido;
    Torneo _torneo;
    Sanciones _sanciones;
    Estadio _estadio;
    //Archivos
    ArchivoJugador _archivoJugador;
    ArchivoClub _archivoClub;
    ArchivoPartido _archivoPartido;
    ArchivoTorneo _archivoTorneo;
    ArchivoSanciones _archivoSanciones;
    ArchivoEstadio _archivoEstadio;
public:
    void cargarJugador();
    void mostrarJugador();
    void cargarClub();
    void mostrarClub();
    void cargarPartido();
    void mostrarPartido();
    void cargarTorneo();
    void mostrarTorneo();
    void cargarSancion();
    void mostrarSancion();
    void cargarEstadio();
    void mostrarEstadio();

    void Mostrar();
    void menuJugador();
    void menuClub();
    void menuPartido();
    void menuTorneo();
    void menuSanciones();
    void menuEstadios();
};


