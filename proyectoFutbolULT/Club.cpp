#include "Club.h"
#include "Partido.h"
#include <iostream>
#include <cstring>
using namespace std;

Club::Club(){
    _codClub=1;
    strcpy(_nombre,"Independiente");
    strcpy(_presidente,"Alejandro");
    strcpy(_DT,"Tevez");
}

void Club::Cargar(){
    cout<<"Codigo Club: ";
    cin>>_codClub;
    cin.ignore();
    cout<<"Nombre: ";
    cin.getline(_nombre,30);
    cout<<"Presidente: ";
    cin.getline(_presidente,30);
    cout<<"Director Tecnico: ";
    cin.getline(_DT,30);
    _estado=true;
}
void Club::Cargar(int codClub){
    _codClub=codClub;

    cout<<"Nombre: ";
    cin.getline(_nombre,30);
    cout<<"Presidente: ";
    cin.getline(_presidente,30);
    cout<<"Director Tecnico: ";
    cin.getline(_DT,30);
    _estado=true;
}

void Club::Mostrar(){
    cout<<"Club: "<<_codClub<<endl;
    cout<<"Nombre: "<<_nombre<<endl;
    cout<<"Presidente: "<<_presidente<<endl;
    cout<<"Director Tecnico: "<<_DT<<endl;
}
////////////////////////////////////////////////////////////

void Club::actualizarPuntos(int codClub, int pts) {
    FILE* p = fopen("Club.dat", "rb+");
    if (p == NULL) return;

    Club aux;
    while (fread(&aux, sizeof(Club), 1, p)) {
        if (aux.getClub() == codClub && aux.getEstado()) {
            aux.setPuntos(aux.getPuntos() + pts);
            fseek(p, -sizeof(Club), SEEK_CUR);
            fwrite(&aux, sizeof(Club), 1, p);
            break;
        }
    }
    fclose(p);
}

void Club::mostrarTablaTorneo(int nroTorneo) {
    FILE *pClub = fopen("Club.dat", "rb");
    FILE *pPartido = fopen("Partido.dat", "rb");

    if (!pClub || !pPartido) {
        cout << "No se pudo abrir alguno de los archivos." << endl;
        if (pClub) fclose(pClub);
        if (pPartido) fclose(pPartido);
        return;
    }

    // Primero reiniciamos puntos de todos los clubes en memoria
    Club clubes[200];
    int cantClubes = 0;
    while (fread(&clubes[cantClubes], sizeof(Club), 1, pClub) == 1) {
        if (clubes[cantClubes].getEstado()) {
            clubes[cantClubes].setPuntos(0);
            cantClubes++;
        }
    }

    // Recorremos todos los partidos del torneo
    Partido partido;
    while (fread(&partido, sizeof(Partido), 1, pPartido) == 1) {
        if (partido.getEstado() && partido.getCodTorneo() == nroTorneo) {
            int codLocal = partido.getCodClubLocal();
            int codVis = partido.getCodClubVisitante();
            int golL = partido.getGolesLocal();
            int golV = partido.getGolesVisitante();

            // Actualizar puntos según resultado
            if (golL > golV) {
                for (int i = 0; i < cantClubes; i++)
                    if (clubes[i].getClub() == codLocal)
                        clubes[i].setPuntos(clubes[i].getPuntos() + 3);
            } else if (golL < golV) {
                for (int i = 0; i < cantClubes; i++)
                    if (clubes[i].getClub() == codVis)
                        clubes[i].setPuntos(clubes[i].getPuntos() + 3);
            } else {
                for (int i = 0; i < cantClubes; i++)
                    if (clubes[i].getClub() == codLocal || clubes[i].getClub() == codVis)
                        clubes[i].setPuntos(clubes[i].getPuntos() + 1);
            }
        }
    }

    fclose(pClub);
    fclose(pPartido);

    // Mostrar resultados
    cout << "\nTABLA DE POSICIONES - TORNEO Nº " << nroTorneo << endl;
    cout << "------------------------------------------" << endl;

    for (int i = 0; i < cantClubes; i++) {
        cout << "Club: " << clubes[i].getNombre()
             << "  | Puntos: " << clubes[i].getPuntos() << endl;
    }
}

///////////////////////////////////////////////////////////

void Club::setClub(int codClub){
    _codClub=codClub;
}

void Club::setNombre(const char* nombre){
    strcpy(_nombre,nombre);
}

void Club::setPresidente(const char* presidente){
    strcpy(_presidente,presidente);
}
void Club::setEstado(bool estado){
    _estado=estado;
}

void Club::setDT(const char* DT){
    strcpy(_DT,DT);
}

void Club::setPuntos(int puntos){
    _puntos=puntos;
}

int Club::getClub(){
    return _codClub;
}

char* Club::getNombre(){
    return _nombre;
}

char* Club::getPresidente(){
    return _presidente;
}

char* Club::getDT(){
    return _DT;
}

int Club::getPuntos(){
    return _puntos;
}

bool Club::getEstado(){
    return _estado;
}
