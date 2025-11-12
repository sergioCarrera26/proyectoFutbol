#pragma once

class Club{
private:
    int _codClub;
    char _nombre[30];
    char _presidente[30];
    char _DT[30];
    int _puntos;/////////
    bool _estado;
public:
    Club();
    void Cargar();
    void Cargar(int codClub);
    void Mostrar();
    void actualizarPuntos(int codClub, int puntos);///
    void mostrarTablaTorneo(int nroTorneo);/////
    void setClub(int codClub);
    void setNombre(const char* nombre);
    void setPresidente(const char* presidente);
    void setDT(const char* DT);
    void setPuntos(int puntos);//////
    void setEstado(bool estado);
    int getClub();
    char* getNombre();
    char* getPresidente();
    char* getDT();
    int getPuntos();////
    bool getEstado();
};
