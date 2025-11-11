#pragma once
#include"Fecha.h"

class Torneo{
private:
    int _codTorneo;
    char _nombre[50];
    Fecha fechaInicio;
    Fecha fechaFin;
    int _cantEquipos;
    //int _codClubCampeon;
    //int _codClubSubcampeon;
    bool _estado;
public:
    Torneo();
    void Cargar();
    void Cargar(int codTorneo);
    void Mostrar();
    //fechaInicio.Fecha(26,6,2026);
    //fechaFin.Fecha(23,7,2026);
    void setCodTorneo(int codTorneo);
    void setNombre(const char* nombre);
    void setCantEquipos(int cantEquipos);
    void setEstado(bool estado);

    int getCodTorneo();
    bool getEstado();
    const char* getNombre();
    int getCantEquipos();
};

