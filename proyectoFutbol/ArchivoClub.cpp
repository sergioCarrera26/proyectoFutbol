#include <iostream>
#include <cstring>
#include "ArchivoClub.h"

using namespace std;

ArchivoClub::ArchivoClub(){
    _nombreArchivo = "Clubes.dat";
}

int ArchivoClub::agregarRegistro(){
    Club obj;
    int codClub;
    cout<<"Ingrese el codigo del club: ";
    cin>>codClub;
    cin.ignore();

    int posicion = buscarClub(codClub);
    if (posicion >= 0){
        cout<<"El CLUB ya fue registrado"<<endl<<endl;
        return 0;
    }

    FILE *pFile = fopen(_nombreArchivo.c_str(),"ab");
    if(pFile==nullptr) return -1;

    obj.Cargar(codClub);

    int escribio = fwrite(&obj,sizeof(Club),1,pFile);
    fclose(pFile);

    return escribio;
}


int ArchivoClub::buscarClub(int codClub){
    Club obj;
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb");
    if(pFile==nullptr)return -2;

    int pos=0;
    while(fread(&obj, sizeof(Club),1,pFile)){
        if(obj.getClub()==codClub&&obj.getEstado()==true){
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}

int ArchivoClub::cantidadRegistros(){
    Club obj;
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb");
    if (pFile==nullptr) return -1;

    fseek(pFile, 0, SEEK_END);
    int cantidadRegistros = ftell(pFile)/sizeof(Club);
    fclose(pFile);
    return cantidadRegistros;
}

int ArchivoClub::mostrarRegistros(){
    Club obj;
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb");
    if (pFile==nullptr) return -1;

    while(fread(&obj,sizeof(Club),1,pFile)){
        if(obj.getEstado()==true){
            obj.Mostrar();
            cout<<endl;
        }
    }

    fclose(pFile);
    return 1;
}

int ArchivoClub::buscarRegistro(){
    Club obj;

    int codClub;
    cout<<"Ingresa el codigo del club"<<endl;
    cin>>codClub;
    cin.ignore();

    int posicion = buscarClub(codClub);
    if (posicion == -1){
        cout<<"EL CLUB NO EXISTE"<<endl;
        return 0;
    }
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb");
    if (pFile==nullptr) return -1;

    //Al tener la posicion no hace falta un while
    fseek(pFile,posicion*sizeof(Club),SEEK_SET);
    fread(&obj,sizeof(Club),1,pFile);
    obj.Mostrar();

    fclose(pFile);
    return 1;
}

int ArchivoClub::bajaRegistro(){
    Club obj;

    int codClub;
    cout<<"Ingresa el codigo del club a dar de baja"<<endl;
    cin>>codClub;
    cin.ignore();

    int posicion = buscarClub(codClub);
    if (posicion == -1){
        cout<<"EL CLUB NO EXISTE"<<endl;
        return 0;
    }
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb+");
    if (pFile==nullptr) return -1;

    fseek(pFile,posicion*sizeof(Club),SEEK_SET);
    fread(&obj,sizeof(Club),1,pFile);
    obj.setEstado(false);

    fseek(pFile,posicion*sizeof(Club),SEEK_SET);
    fwrite(&obj,sizeof(Club),1,pFile);

    fclose(pFile);
    return 1;
}

Club ArchivoClub::leer(int posicion){
    Club obj;
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb");
    if(pFile==nullptr) return obj;

    fseek(pFile,posicion*sizeof(Club),SEEK_SET);
    fread(&obj,sizeof(Club),1,pFile);

    fclose(pFile);
    return obj;
}

int ArchivoClub::modificarRegistro(){
    Club obj;
    int codClub;
    cout<<"Ingrese el Codigo del club del registro a modificar: ";
    cin>>codClub;
    cin.ignore();

    int posicion = buscarClub(codClub);
    if(posicion<0){
        cout<<"El Codigo del club ingresado no existe "<<endl<<endl;
        return 0;
    }
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb+");
    if (pFile==nullptr) return -1;

    fseek(pFile, posicion*sizeof(Club),SEEK_SET);
    fread(&obj, sizeof(Club),1,pFile);
    obj.Cargar(codClub);

    fseek(pFile, posicion*sizeof(Club),SEEK_SET);
    fwrite(&obj, sizeof(Club),1,pFile);
    fclose(pFile);
    return 1;
}

int ArchivoClub::cantidadRegistrosActivos(){
    Club obj;
    int cantidadReg = 0;
    for (int i=0;i<cantidadRegistros();i++){
        obj = leer(i);
        if(obj.getEstado())cantidadReg++;
    }
    return cantidadReg;
}

