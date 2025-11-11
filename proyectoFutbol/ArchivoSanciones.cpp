#include <iostream>
#include <cstring>
#include "ArchivoSanciones.h"

using namespace std;

ArchivoSanciones::ArchivoSanciones(){
    _nombreArchivo = "Sanciones.dat";
}

int ArchivoSanciones::agregarRegistro(){
    Sanciones obj;
    int codSancion;
    cout<<"Ingrese el codigo de la sancion: ";
    cin>>codSancion;
    cin.ignore();

    int posicion = buscarSancion(codSancion);
    if (posicion >= 0){
        cout<<"La SANCION ya fue registrada"<<endl<<endl;
        return 0;
    }

    FILE *pFile = fopen(_nombreArchivo.c_str(),"ab");
    if(pFile==nullptr) return -1;

    obj.Cargar(codSancion);

    int escribio = fwrite(&obj,sizeof(Sanciones),1,pFile);
    fclose(pFile);

    return escribio;
}

int ArchivoSanciones::buscarSancion(int codSancion){
    Sanciones obj;
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb");
    if(pFile==nullptr)return -2;

    int pos=0;
    while(fread(&obj, sizeof(Sanciones),1,pFile)){
        if(obj.getNroSancion()==codSancion&&obj.getEstado()==true){
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}

int ArchivoSanciones::cantidadRegistros(){
    Sanciones obj;
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb");
    if (pFile==nullptr) return -1;

    fseek(pFile, 0, SEEK_END);
    int cantidadRegistros = ftell(pFile)/sizeof(Sanciones);
    fclose(pFile);
    return cantidadRegistros;
}

int ArchivoSanciones::mostrarRegistros(){
    Sanciones obj;
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb");
    if (pFile==nullptr) return -1;

    while(fread(&obj,sizeof(Sanciones),1,pFile)){
        if(obj.getEstado()){
            obj.Mostrar();
            cout<<endl;
        }
    }

    fclose(pFile);
    return 1;
}

int ArchivoSanciones::buscarRegistro(){
    Sanciones obj;

    int codSancion;
    cout<<"Ingresa el codigo de la sancion"<<endl;
    cin>>codSancion;
    cin.ignore();

    int posicion = buscarSancion(codSancion);
    if (posicion == -1){
        cout<<"LA SANCION NO EXISTE"<<endl;
        return 0;
    }
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb");
    if (pFile==nullptr) return -1;

    fseek(pFile,posicion*sizeof(Sanciones),SEEK_SET);
    fread(&obj,sizeof(Sanciones),1,pFile);
    obj.Mostrar();

    fclose(pFile);
    return 1;
}

int ArchivoSanciones::bajaRegistro(){
    Sanciones obj;

    int codSancion;
    cout<<"Ingresa el codigo de la sancion a dar de baja"<<endl;
    cin>>codSancion;
    cin.ignore();

    int posicion = buscarSancion(codSancion);
    if (posicion == -1){
        cout<<"LA SANCION NO EXISTE"<<endl;
        return 0;
    }
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb+");
    if (pFile==nullptr) return -1;

    fseek(pFile,posicion*sizeof(Sanciones),SEEK_SET);
    fread(&obj,sizeof(Sanciones),1,pFile);
    obj.setEstado(false);

    fseek(pFile,posicion*sizeof(Sanciones),SEEK_SET);
    fwrite(&obj,sizeof(Sanciones),1,pFile);

    fclose(pFile);
    return 1;
}

Sanciones ArchivoSanciones::leer(int posicion){
    Sanciones obj;
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb");
    if(pFile==nullptr) return obj;

    fseek(pFile,posicion*sizeof(Sanciones),SEEK_SET);
    fread(&obj,sizeof(Sanciones),1,pFile);

    fclose(pFile);
    return obj;
}

int ArchivoSanciones::modificarRegistro(){
    Sanciones obj;
    int codSancion;
    cout<<"Ingrese el Codigo de la sancion del registro a modificar: ";
    cin>>codSancion;
    cin.ignore();

    int posicion = buscarSancion(codSancion);
    if(posicion<0){
        cout<<"El Codigo de la sancion ingresado no existe "<<endl<<endl;
        return 0;
    }
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb+");
    if (pFile==nullptr) return -1;

    fseek(pFile, posicion*sizeof(Sanciones),SEEK_SET);
    fread(&obj, sizeof(Sanciones),1,pFile);
    obj.Cargar(codSancion);

    fseek(pFile, posicion*sizeof(Sanciones),SEEK_SET);
    fwrite(&obj, sizeof(Sanciones),1,pFile);
    fclose(pFile);
    return 1;
}
