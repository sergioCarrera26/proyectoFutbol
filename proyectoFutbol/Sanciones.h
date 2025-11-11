#pragma once

class Sanciones{
private:
    int _nroSancion;
    char _DNIjugador[9];
    int _nroPartido;
    int _tipoTarjeta;
    int _cantFechasSuspension;
    bool _estado;
public:
    Sanciones();
    void Cargar();
    void Cargar(int nroSancion);
    void Mostrar();
    void setNroSancion(int nroSancion);
    void setDNIjugador(const char* DNIjugador);
    void setNroPartido(int nroPartido);
    void setTipoTarjeta(int tipoTarjeta);
    void setCantFechasSuspension(int cantFechasSuspension);
    void setEstado(bool estado);
    int getNroSancion();
    const char* getDNIjugador();
    int getNroPartido();
    int getTipoTarjeta();
    int getCantFechasSuspension();
    bool getEstado();
};

