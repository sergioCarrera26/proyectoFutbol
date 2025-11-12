#pragma once

class Estadio{
private:
    int _codEstadio;
    int _codClub;
    char _nombre[50];
    int _capacidad;
    bool _estado;
public:
    Estadio();
    void Cargar();
    void Cargar(int codEstadio, int codClub);
    void Mostrar();
    void setCodEstadio(int codEsttadio);
    void setCodClub(int codClub);
    void setNombre(const char* nombre);
    void setCapacidad(int capacidad);
    void setEstado(bool estado);
    int getCodEstadio();
    int getCodClub();
    const char* getNombre();
    int getCapacidad();
    bool getEstado();
};
