#include <iostream>
#include <cstring>
#include "ArchivoJugador.h"
#include "ArchivoClub.h"

using namespace std;

ArchivoJugador::ArchivoJugador(){
    _nombreArchivo = "jugadores.dat";
}

int ArchivoJugador::agregarRegistro(){
    Jugador j1;
    ArchivoClub archiClub;
    char DNI[9];

    cout<<"Ingrese el DNI del jugador: ";
    cin>>DNI;
    cin.ignore();

    int posicion = buscarJugador(DNI);
    if (posicion >= 0){
        cout<<"El DNI ya fue registrado"<<endl<<endl;
        return 0;
    }

    int codClub;
    cout<<"Ingrese el codigo del club: ";
    cin>>codClub;
    cin.ignore();

    int posicionClub = archiClub.buscarClub(codClub);
    if (posicionClub<0){
        cout<<"ERROR: club inexistente"<<endl;
        return 0;
    }
    //Rechaza si encontró el jugador (posición >= 0)
    // Si es -2 (error al abrir) o -1 (no encontrado), continuar

    FILE *pFile = fopen(_nombreArchivo.c_str(),"ab"); //Devuelve un puntero constante (const char*) al contenido
    if(pFile==nullptr) return -1;                     //interno de la cadena, terminada en carácter nulo '\0'

    j1.Cargar(DNI,codClub);

    int escribio = fwrite(&j1,sizeof(Jugador),1,pFile);
    fclose(pFile);

    return escribio;
}


int ArchivoJugador::buscarJugador(char *DNI){
    Jugador j1;
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb");
    if(pFile==nullptr)return -2;

    int pos=0;
    while(fread(&j1, sizeof(Jugador),1,pFile)){
        if(strcmp(j1.getDNI(),DNI)==0&&j1.getEstado()==true){
            fclose(pFile);
            return pos; //Si lo encuentra retorna su posicion
        }
        pos++;
    }
    fclose(pFile);
    return -1; ////Si no encuentra retorna -1
}

int ArchivoJugador::cantidadRegistros(){
    Jugador j1;
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb");
    if (pFile==nullptr) return -1;

    fseek(pFile, 0, SEEK_END); //mueve el puntero al final del archvo
    int cantidadRegistros = ftell(pFile)/sizeof(Jugador); //ftell devuelve la posición actual del puntero dentro del archivo en bytes.
    fclose(pFile);
    return cantidadRegistros;
}

int ArchivoJugador::mostrarRegistros(){
    Jugador j1;
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb");
    if (pFile==nullptr) return -1;

    while(fread(&j1,sizeof(Jugador),1,pFile)){
        if(j1.getEstado()==true){
            j1.Mostrar();
            cout<<endl;
        }
    }

    fclose(pFile);
    return 1;
}

int ArchivoJugador::buscarRegistro(){
    Jugador j1;

    char DNI[9];
    cout<<"Ingresa el DNI del jugador"<<endl;
    cin>>DNI;
    cin.ignore();

    int posicion = buscarJugador(DNI);
    if (posicion == -1){
        cout<<"EL DNI NO EXISTE"<<endl;
        return 0;
    }
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb");
    if (pFile==nullptr) return -1;

    //Al tener la posicion no hace falta un while
    fseek(pFile,posicion*sizeof(Jugador),SEEK_SET);
    fread(&j1,sizeof(Jugador),1,pFile);
    j1.Mostrar();

    fclose(pFile);
    return 1;
}

int ArchivoJugador::bajaRegistro(){
    Jugador j1;

    char DNI[9];
    cout<<"Ingresa el DNI del jugador a dar de baja"<<endl;
    cin>>DNI;
    cin.ignore();

    int posicion = buscarJugador(DNI);
    if (posicion == -1){
        cout<<"EL DNI NO EXISTE"<<endl;
        return 0;
    }
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb+");
    if (pFile==nullptr) return -1;

    fseek(pFile,posicion*sizeof(Jugador),SEEK_SET);
    fread(&j1,sizeof(Jugador),1,pFile);
    j1.setEstado(false);

    fseek(pFile,posicion*sizeof(Jugador),SEEK_SET);
    fwrite(&j1,sizeof(Jugador),1,pFile);

    fclose(pFile);
    return 1;
}

Jugador ArchivoJugador::leer(int posicion){
    Jugador j1;
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb");
    if(pFile==nullptr) return j1;

    fseek(pFile,posicion*sizeof(Jugador),SEEK_SET);
    fread(&j1,sizeof(Jugador),1,pFile);

    fclose(pFile);
    return j1;
}

int ArchivoJugador::modificarRegistro(){
    Jugador j1;
    ArchivoClub archiClub;
    char DNI[9];
    cout<<"Ingrese el DNI del registro a modificar: ";
    cin>>DNI;
    cin.ignore();
    int posicion = buscarJugador(DNI);
    if(posicion<0){
        cout<<"El DNI ingresado no existe "<<endl<<endl;
        return 0;
    }
    int codClub;
    cout<<"Ingresa el codigo del club "<<endl;
    cin>>codClub;
    cin.ignore();

    int posicionClub = archiClub.buscarClub(codClub);
    if (posicionClub<0){
        cout<<"ERROR: club inexistente"<<endl;
        return 0;
    }
    FILE *pFile = fopen(_nombreArchivo.c_str(),"rb+");
    if (pFile==nullptr) return -1;

    fseek(pFile, posicion*sizeof(Jugador),SEEK_SET);
    fread(&j1, sizeof(Jugador),1,pFile);
    j1.Cargar(DNI,codClub);

    fseek(pFile, posicion*sizeof(Jugador),SEEK_SET);
    fwrite(&j1, sizeof(Jugador),1,pFile);
    fclose(pFile);
    return 1;
}

int ArchivoJugador::cantidadRegistrosActivos(){
    Jugador obj;
    int cantidadReg = 0;
    for (int i=0;i<cantidadRegistros();i++){
        obj = leer(i);
        if(obj.getEstado())cantidadReg++;
    }
    return cantidadReg;
}

void ArchivoJugador::ordenarXEdad(){
    int cantidad = cantidadRegistrosActivos(); //solo registros activos
    if(cantidad==0){
        cout<<"No hay registros para ordenar "<<endl;
        return;
    }

    Jugador obj,*jugadores,aux;
    jugadores  = new Jugador [cantidad];

    int contador = 0;
    for (int i=0;i<cantidadRegistros();i++){
        obj = leer(i);
        if(obj.getEstado()){
            jugadores[contador] = obj ; //Cuando encuentre un registro activo lo guarda en la posicion 0
            contador++;                 //e incrementa el contador
        }
    }
    int anio;
    cout<<"Introduzca el anio actual "<<endl;
    cin>>anio;
    for (int i=0;i<cantidad;i++){
        bool intercambio = false;
        for (int j=0;j<cantidad-i-1;j++){
            int edad1 = anio - jugadores[j].getFechanacimiento().getAnio();
            int edad2 = anio - jugadores[j+1].getFechanacimiento().getAnio();
            if(edad1<edad2){
                aux = jugadores[j];
                jugadores[j] = jugadores[j+1];
                jugadores[j+1] = aux;
                intercambio = true;
            }
        }
        if(!intercambio)break;
    }
    cout << "======================================" << endl;
    cout << "     JUGADORES ORDENADOS POR EDAD     " << endl;
    cout << "======================================" << endl;
    for (int i = 0;i<cantidad;i++){
        int edad = anio - jugadores[i].getFechanacimiento().getAnio();

        //Si tiene una edad de cero no muestra el jugador
        if(edad>0){
            cout<<edad<<" "<<jugadores[i].getNombre()<<" "<<jugadores[i].getApellido()<<endl;
        }
    }
    cout<<endl;
    delete []jugadores;
}

void ArchivoJugador::listarXEquipo(){
    Jugador obj;
    ArchivoClub archi;
    Club c1;

    int cantidadJugadores = cantidadRegistrosActivos();
    int cantidadClubes = archi.cantidadRegistrosActivos();
    if(cantidadJugadores==0||cantidadClubes==0){
        cout<<"No hay registros para ordenar "<<endl;
        return;
    }
    for (int i=0;i<archi.cantidadRegistros();i++){
        c1 = archi.leer(i);
        if (c1.getEstado()){
            cout << "======================================"<<endl;
            cout << "CLUB: " << c1.getNombre() <<endl;
            cout << "--------------------------------------"<<endl;
        }
        bool hayJugadores = false;
        for (int j = 0; j < cantidadRegistros(); j++){
            obj = leer(j);
            if (obj.getEstado() && obj.getCodClub() == c1.getClub()){
                cout << obj.getNombre() << " " << obj.getApellido() << endl;
                hayJugadores = true;
            }
        }

        if (!hayJugadores){
            cout<<"(Sin jugadores)"<<endl;
        }
        cout<<endl;
        }


}

int ArchivoJugador::buscarXNombre(){
    Jugador obj;
    int cantidad = cantidadRegistros();
    char nombre[30];
    cout<<"Ingresa el nombre del jugador"<<endl;
    cin.getline(nombre,30);
    cout<<endl;
    int encontrados=0;
    for (int i=0;i<cantidad;i++){
        obj = leer(i);
        if(obj.getEstado()&&strcmp(obj.getNombre(),nombre)==0){
            obj.Mostrar();
            encontrados++;
            cout<<endl;
        }
    }

    return encontrados;
}
