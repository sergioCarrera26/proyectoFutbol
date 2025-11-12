#include <iostream>
#include <cstring>
#include "ArchivoEstadio.h"
#include "ArchivoClub.h"
using namespace std;

ArchivoEstadio::ArchivoEstadio(){
    _nombreArchivo = "Estadios.dat";
}

int ArchivoEstadio::agregarRegistro(){
    Estadio obj;
    ArchivoClub archiClub;
    int codEstadio;
    cout<<"Ingrese el codigo del estadio: ";
    cin>>codEstadio;
    cin.ignore();

    int posicion = buscarEstadio(codEstadio);
    if (posicion >= 0){
        cout<<"El ESTADIO ya fue registrado"<<endl<<endl;
        return 0;
    }
    int codClub;
    cout<<"Ingrese el codigo del club: ";
    cin>>codClub;
    cin.ignore();
    int posicionClub = archiClub.buscarClub(codClub);;
    if (posicionClub < 0){
        cout<<"ERROR: Club no registrado"<<endl<<endl;
        return 0;
    }
    FILE *pFile = fopen(_nombreArchivo.c_str(),"ab");
    if(pFile==nullptr) return -1;

    obj.Cargar(codEstadio,codClub);

    int escribio = fwrite(&obj,sizeof(Estadio),1,pFile);
    fclose(pFile);

    return escribio;
}

int ArchivoEstadio::buscarEstadio(int codEstadio){
    Estadio obj;
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb");
    if(pFile==nullptr)return -2;

    int pos=0;
    while(fread(&obj, sizeof(Estadio),1,pFile)){
        if(obj.getCodEstadio()==codEstadio&&obj.getEstado()==true){
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}

int ArchivoEstadio::cantidadRegistros(){
    Estadio obj;
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb");
    if (pFile==nullptr) return -1;

    fseek(pFile, 0, SEEK_END);
    int cantidadRegistros = ftell(pFile)/sizeof(Estadio);
    fclose(pFile);
    return cantidadRegistros;
}

int ArchivoEstadio::mostrarRegistros(){
    Estadio obj;
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb");
    if (pFile==nullptr) return -1;

    while(fread(&obj,sizeof(Estadio),1,pFile)){
        if(obj.getEstado()==true){
            obj.Mostrar();
            cout<<endl;
        }
    }

    fclose(pFile);
    return 1;
}

int ArchivoEstadio::buscarRegistro(){
    Estadio obj;

    int codEstadio;
    cout<<"Ingresa el codigo del estadio"<<endl;
    cin>>codEstadio;
    cin.ignore();

    int posicion = buscarEstadio(codEstadio);
    if (posicion == -1){
        cout<<"EL ESTADIO NO EXISTE"<<endl;
        return 0;
    }
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb");
    if (pFile==nullptr) return -1;

    fseek(pFile,posicion*sizeof(Estadio),SEEK_SET);
    fread(&obj,sizeof(Estadio),1,pFile);
    obj.Mostrar();

    fclose(pFile);
    return 1;
}

int ArchivoEstadio::bajaRegistro(){
    Estadio obj;

    int codEstadio;
    cout<<"Ingresa el codigo del estadio a dar de baja"<<endl;
    cin>>codEstadio;
    cin.ignore();

    int posicion = buscarEstadio(codEstadio);
    if (posicion == -1){
        cout<<"EL ESTADIO NO EXISTE"<<endl;
        return 0;
    }
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb+");
    if (pFile==nullptr) return -1;

    fseek(pFile,posicion*sizeof(Estadio),SEEK_SET);
    fread(&obj,sizeof(Estadio),1,pFile);
    obj.setEstado(false);

    fseek(pFile,posicion*sizeof(Estadio),SEEK_SET);
    fwrite(&obj,sizeof(Estadio),1,pFile);

    fclose(pFile);
    return 1;
}

Estadio ArchivoEstadio::leer(int posicion){
    Estadio obj;
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb");
    if(pFile==nullptr) return obj;

    fseek(pFile,posicion*sizeof(Estadio),SEEK_SET);
    fread(&obj,sizeof(Estadio),1,pFile);

    fclose(pFile);
    return obj;
}

int ArchivoEstadio::modificarRegistro(){
    Estadio obj;
    ArchivoClub archiClub;
    int codEstadio;
    cout<<"Ingrese el Codigo del estadio del registro a modificar: ";
    cin>>codEstadio;
    cin.ignore();

    int posicion = buscarEstadio(codEstadio);
    if(posicion<0){
        cout<<"El Codigo del estadio ingresado no existe "<<endl<<endl;
        return 0;
    }
    int codClub;
    cout<<"Ingrese el codigo del club: ";
    cin>>codClub;
    cin.ignore();
    int posicionClub = archiClub.buscarClub(codClub);;
    if (posicionClub < 0){
        cout<<"ERROR: Club no registrado"<<endl<<endl;
        return 0;
    }
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb+");
    if (pFile==nullptr) return -1;

    fseek(pFile, posicion*sizeof(Estadio),SEEK_SET);
    fread(&obj, sizeof(Estadio),1,pFile);
    obj.Cargar(codEstadio,codClub);

    fseek(pFile, posicion*sizeof(Estadio),SEEK_SET);
    fwrite(&obj, sizeof(Estadio),1,pFile);
    fclose(pFile);
    return 1;
}
