#include <iostream>
#include <cstring>
#include "ArchivoPartido.h"

using namespace std;

ArchivoPartido::ArchivoPartido(){
    _nombreArchivo = "Partidos.dat";
}

int ArchivoPartido::agregarRegistro(){
    Partido obj;
    int codPartido;
    cout<<"Ingrese el codigo del partido: ";
    cin>>codPartido;
    cin.ignore();

    int posicion = buscarPartido(codPartido);
    if (posicion >= 0){
        cout<<"El PARTIDO ya fue registrado"<<endl<<endl;
        return 0;
    }

    FILE *pFile = fopen(_nombreArchivo.c_str(),"ab");
    if(pFile==nullptr) return -1;

    obj.Cargar(codPartido);

    int escribio = fwrite(&obj,sizeof(Partido),1,pFile);
    fclose(pFile);

    return escribio;
}


int ArchivoPartido::buscarPartido(int codPartido){
    Partido obj;
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb");
    if(pFile==nullptr)return -2;

    int pos=0;
    while(fread(&obj, sizeof(Partido),1,pFile)){
        if(obj.getNroPartido()==codPartido&&obj.getEstado()==true){
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}

int ArchivoPartido::cantidadRegistros(){
    Partido obj;
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb");
    if (pFile==nullptr) return -1;

    fseek(pFile, 0, SEEK_END);
    int cantidadRegistros = ftell(pFile)/sizeof(Partido);
    fclose(pFile);
    return cantidadRegistros;
}

int ArchivoPartido::mostrarRegistros(){
    Partido obj;
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb");
    if (pFile==nullptr) return -1;

    while(fread(&obj,sizeof(Partido),1,pFile)){
        if(obj.getEstado()==true){
            obj.Mostrar();
            cout<<endl;
        }
    }

    fclose(pFile);
    return 1;
}

int ArchivoPartido::buscarRegistro(){
    Partido obj;

    int codPartido;
    cout<<"Ingresa el codigo del partido"<<endl;
    cin>>codPartido;
    cin.ignore();

    int posicion = buscarPartido(codPartido);
    if (posicion == -1){
        cout<<"EL PARTIDO NO EXISTE"<<endl;
        return 0;
    }
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb");
    if (pFile==nullptr) return -1;

    //Al tener la posicion no hace falta un while
    fseek(pFile,posicion*sizeof(Partido),SEEK_SET);
    fread(&obj,sizeof(Partido),1,pFile);
    obj.Mostrar();

    fclose(pFile);
    return 1;
}

int ArchivoPartido::bajaRegistro(){
    Partido obj;

    int codPartido;
    cout<<"Ingresa el codigo del partido a dar de baja"<<endl;
    cin>>codPartido;
    cin.ignore();

    int posicion = buscarPartido(codPartido);
    if (posicion == -1){
        cout<<"EL PARTIDO NO EXISTE"<<endl;
        return 0;
    }
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb+");
    if (pFile==nullptr) return -1;

    fseek(pFile,posicion*sizeof(Partido),SEEK_SET);
    fread(&obj,sizeof(Partido),1,pFile);
    obj.setEstado(false);

    fseek(pFile,posicion*sizeof(Partido),SEEK_SET);
    fwrite(&obj,sizeof(Partido),1,pFile);

    fclose(pFile);
    return 1;
}

Partido ArchivoPartido::leer(int posicion){
    Partido obj;
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb");
    if(pFile==nullptr) return obj;

    fseek(pFile,posicion*sizeof(Partido),SEEK_SET);
    fread(&obj,sizeof(Partido),1,pFile);

    fclose(pFile);
    return obj;
}

int ArchivoPartido::modificarRegistro(){
    Partido obj;
    int codPartido;
    cout<<"Ingrese el Codigo del partido del registro a modificar: ";
    cin>>codPartido;
    cin.ignore();

    int posicion = buscarPartido(codPartido);
    if(posicion<0){
        cout<<"El Codigo del partido ingresado no existe "<<endl<<endl;
        return 0;
    }
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb+");
    if (pFile==nullptr) return -1;

    fseek(pFile, posicion*sizeof(Partido),SEEK_SET);
    fread(&obj, sizeof(Partido),1,pFile);
    obj.Cargar(codPartido);

    fseek(pFile, posicion*sizeof(Partido),SEEK_SET);
    fwrite(&obj, sizeof(Partido),1,pFile);
    fclose(pFile);
    return 1;
}

