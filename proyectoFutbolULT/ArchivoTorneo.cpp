#include <iostream>
#include <cstring>
#include "ArchivoTorneo.h"
#include "Torneo.h"
#include "Club.h"

using namespace std;

ArchivoTorneo::ArchivoTorneo(){
    _nombreArchivo = "Torneos.dat";
}

int ArchivoTorneo::agregarRegistro(){
    Torneo obj;
    int codTorneo;
    cout<<"Ingrese el codigo del torneo: ";
    cin>>codTorneo;
    cin.ignore();

    int posicion = buscarTorneo(codTorneo);
    if (posicion >= 0){
        cout<<"El TORNEO ya fue registrado"<<endl<<endl;
        return 0;
    }

    FILE *pFile = fopen(_nombreArchivo.c_str(),"ab");
    if(pFile==nullptr) return -1;

    obj.Cargar(codTorneo);

    int escribio = fwrite(&obj,sizeof(Torneo),1,pFile);
    fclose(pFile);

    return escribio;
}


int ArchivoTorneo::buscarTorneo(int codTorneo){
    Torneo obj;
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb");
    if(pFile==nullptr)return -2;

    int pos=0;
    while(fread(&obj, sizeof(Torneo),1,pFile)){
        if(obj.getCodTorneo()==codTorneo&&obj.getEstado()==true){
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}

int ArchivoTorneo::cantidadRegistros(){
    Torneo obj;
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb");
    if (pFile==nullptr) return -1;

    fseek(pFile, 0, SEEK_END);
    int cantidadRegistros = ftell(pFile)/sizeof(Torneo);
    fclose(pFile);
    return cantidadRegistros;
}

int ArchivoTorneo::mostrarRegistros(){
    Club _club;
    int nro;
    cout << "Ingrese número de Torneo a mostrar: ";
    cin >> nro;

    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr) return -1;

    Torneo obj;
    bool encontrado = false;

    while (fread(&obj, sizeof(Torneo), 1, pFile)) {
        if (obj.getEstado() && obj.getCodTorneo() == nro) {
            obj.Mostrar();
            encontrado = true;
            break;
        }
    }
    fclose(pFile);

    if (!encontrado) {
        cout << "No se encontró el torneo con ese código." << endl;
        return 0;
    }

    // Aquí llamás a la función que calcula los puntos del torneo
    _club.mostrarTablaTorneo(nro);

    return 1;
}

/*int ArchivoTorneo::mostrarRegistros(){
    Torneo obj;
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb");
    if (pFile==nullptr) return -1;

    while(fread(&obj,sizeof(Torneo),1,pFile)){
        if(obj.getEstado()==true){
            obj.Mostrar();
            cout<<endl;
        }
    }

    fclose(pFile);
    return 1;
}*/

int ArchivoTorneo::buscarRegistro(){
    Torneo obj;

    int codTorneo;
    cout<<"Ingresa el codigo del torneo"<<endl;
    cin>>codTorneo;
    cin.ignore();

    int posicion = buscarTorneo(codTorneo);
    if (posicion == -1){
        cout<<"EL TORNEO NO EXISTE"<<endl;
        return 0;
    }
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb");
    if (pFile==nullptr) return -1;

    fseek(pFile,posicion*sizeof(Torneo),SEEK_SET);
    fread(&obj,sizeof(Torneo),1,pFile);
    obj.Mostrar();

    fclose(pFile);
    return 1;
}

int ArchivoTorneo::bajaRegistro(){
    Torneo obj;

    int codTorneo;
    cout<<"Ingresa el codigo del torneo a dar de baja"<<endl;
    cin>>codTorneo;
    cin.ignore();

    int posicion = buscarTorneo(codTorneo);
    if (posicion == -1){
        cout<<"EL TORNEO NO EXISTE"<<endl;
        return 0;
    }
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb+");
    if (pFile==nullptr) return -1;

    fseek(pFile,posicion*sizeof(Torneo),SEEK_SET);
    fread(&obj,sizeof(Torneo),1,pFile);
    obj.setEstado(false);

    fseek(pFile,posicion*sizeof(Torneo),SEEK_SET);
    fwrite(&obj,sizeof(Torneo),1,pFile);

    fclose(pFile);
    return 1;
}

Torneo ArchivoTorneo::leer(int posicion){
    Torneo obj;
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb");
    if(pFile==nullptr) return obj;

    fseek(pFile,posicion*sizeof(Torneo),SEEK_SET);
    fread(&obj,sizeof(Torneo),1,pFile);

    fclose(pFile);
    return obj;
}

int ArchivoTorneo::modificarRegistro(){
    Torneo obj;
    int codTorneo;
    cout<<"Ingrese el Codigo del torneo del registro a modificar: ";
    cin>>codTorneo;
    cin.ignore();

    int posicion = buscarTorneo(codTorneo);
    if(posicion<0){
        cout<<"El Codigo del torneo ingresado no existe "<<endl<<endl;
        return 0;
    }
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb+");
    if (pFile==nullptr) return -1;

    fseek(pFile, posicion*sizeof(Torneo),SEEK_SET);
    fread(&obj, sizeof(Torneo),1,pFile);
    obj.Cargar(codTorneo);

    fseek(pFile, posicion*sizeof(Torneo),SEEK_SET);
    fwrite(&obj, sizeof(Torneo),1,pFile);
    fclose(pFile);
    return 1;
}
