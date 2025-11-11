#pragma once

class Club{
private:
    int _codClub;
    char _nombre[30];
    char _presidente[30];
    char _DT[30];
    bool _estado;
public:
    Club();
    void Cargar();
    void Cargar(int codClub);
    void Mostrar();
    void setClub(int codClub);
    void setNombre(const char* nombre);
    void setPresidente(const char* presidente);
    void setDT(const char* DT);
    void setEstado(bool estado);
    int getClub();
    char* getNombre();
    char* getPresidente();
    char* getDT();
    bool getEstado();
};
