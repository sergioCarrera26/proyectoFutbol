#pragma once ///lo usa c++

class Fecha{
private:
    int _dia;
    int _mes;
    int _anio;
    bool esBisiesto(int anio); //S
    bool esFechaValida(int dia, int mes, int anio);//S
public:
    Fecha();
    Fecha(int dia, int mes, int anio);
    void Cargar();
    void Mostrar();
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    int getDia();
    int getMes();
    int getAnio();
};


