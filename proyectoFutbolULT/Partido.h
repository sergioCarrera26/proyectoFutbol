#pragma once ///lo usa c++
#include "Fecha.h"

class Partido{
private:
    int _nroPartido;
    int _codTorneo;
    int _codEstadio;
    int _codClubLocal;
    int _codClubVisitante;
    int _golesLocal;
    int _golesVisitante;
    Fecha fechaDePartido;
    bool _estado;
public:
    Partido();
    void Cargar();
    void Cargar(int nroPartido);
    void Mostrar();
    void setNroPartido(int nroPartido);
    void setCodTorneo(int codTorneo);
    void setCodEstadio(int codEstadio);
    void setCodClubLocal(int codClubLocal);
    void setCodClubVisitante(int codClubVisitante);
    void setGolesLocal(int golesLocal);
    void setGolesVisitante(int golesVisitante);
    void setEstado(bool estado);
    int getNroPartido();
    int getCodTorneo();
    int getCodEstadio();
    int getCodClubLocal();
    int getCodClubVisitante();
    int getGolesLocal();
    int getGolesVisitante();
    bool getEstado();
};

