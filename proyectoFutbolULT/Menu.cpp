#include <iostream>
//#include <cstdlib>   // para system("cls") y system("pause")
#include "Menu.h"
using namespace std;

void Menu::Mostrar(){
    int opc;
    while(true){
        system("cls");
        cout<<"***********************************************"<<endl;
        cout<<"*              MENU PRINCIPAL                 *"<<endl;
        cout<<"***********************************************"<<endl;
        cout<<"* 1. Jugadores                                *"<<endl;
        cout<<"* 2. Clubes                                   *"<<endl;
        cout<<"* 3. Partidos                                 *"<<endl;
        cout<<"* 4. Torneos                                  *"<<endl;
        cout<<"* 5. Sanciones                                *"<<endl;
        cout<<"* 6. Estadios                                 *"<<endl;
        cout<<"* 0. Salir                                    *"<<endl;
        cout<<"***********************************************"<<endl;
        cout<<"Seleccionar una opcion: ";
        /*cout<<" *********** MENU PRINCIPAL ***************" <<endl;
        cout<<"1. ___ Jugadores __________________________" <<endl;
        cout<<"2. ___ Clubes _____________________________" <<endl;
        cout<<"3. ___ Partidos ___________________________" <<endl;
        cout<<"4. ___ Torneos ____________________________" <<endl;
        cout<<"5. ___ Sanciones __________________________" <<endl;
        cout<<"6. ___ Estadios ___________________________" <<endl;
        cout<<"-------------------------------------------" <<endl;
        cout<<"0. ___ Salir_______________________________"  <<endl;
        cout<<"*******************************************" <<endl<<endl;
        cout<<"SELECCIONAR OPCION ";*/
        cin>>opc;
        cin.ignore();
        system("cls");
        switch(opc){
            case 1: menuJugador();
                system("pause");
                break;
            case 2: menuClub();
                system("pause");
                break;
            case 3: menuPartido();
                system("pause");
                break;
            case 4: menuTorneo();
                system("pause");
                break;
            case 5: menuSanciones();
                system("pause");
                break;
            case 6: menuEstadios();
                system("pause");
                break;

            case 0:
                cout<<"FIN DEL PROGRAMA !!!!!!!"<<endl;
                return;
            default:
                cout<<"OPCION INCORRECTA. VUELVA A INGRESAR"<<endl;
                system("pause");
                break;
        }
    }
}

void Menu::menuJugador(){
    int opc;
    while(true){
        system("cls");
        cout<<" *********** 1. MENU JUGADORES ***************"  <<endl;
        cout<<"1. Agregar Registro Jugador"                     <<endl;///Agregar Registro1
        cout<<"2. Borrado Logico Registro Jugador"              <<endl;///Borrar Registro3
        cout<<"3. Modificar registro Jugador"                   <<endl;///Modificar Registro4
        cout<<"4. Listar Registro Jugador"                      <<endl;///Listar Registro2
        cout<<"5. Buscar jugador"                               <<endl;
        cout<<"6. Buscar jugador por nombre"                    <<endl;
        cout<<"7. Ordenar jugadores por edad"                   <<endl;
        cout<<"8. Listar jugadores por club"                    <<endl;
        cout<<"-------------------------------------------"     <<endl;
        cout<<"0. Salir"                                        <<endl;
        cout<<"*******************************************"     <<endl<<endl;
        cout<<"SELECCIONAR OPCION ";
        cin>>opc;
        cin.ignore();
        system("cls");
        switch(opc){
            case 1: if(_archivoJugador.agregarRegistro()<=0){
                        cout<<"Error al agregar el registro "<<endl<<endl;
                    }else cout<<"Registro agregado con exito"<<endl<<endl;
                system("pause");
                break;
            case 2: if(_archivoJugador.bajaRegistro()<=0)cout<<"ERROR AL ELIMINAR EL REGISTRO"<<endl;
                    else cout<<"REGISTRO ELIMINADO EXITOSAMENTE"<<endl;
                system("pause");
                break;
            case 3: if(_archivoJugador.modificarRegistro()<=0)cout<<"ERROR AL MODIFICAR EL REGISTRO"<<endl;
                    else cout<<"REGISTRO MODIFICADO EXITOSAMENTE"<<endl;
                system("pause");
                break;
            case 4: if(_archivoJugador.mostrarRegistros()<=0)cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
                system("pause");
                break;
            case 5: if(_archivoJugador.buscarRegistro()<=0)cout<<"ERROR AL BUSCAR EL REGISTRO"<<endl;
                system("pause");
                break;
            case 6: if(_archivoJugador.buscarXNombre()==0)cout<<"No hay jugadores con ese nombre"<<endl;
                system("pause");
                break;
            case 7: _archivoJugador.ordenarXEdad();
                system("pause");
                break;
            case 8: _archivoJugador.listarXEquipo();
                system("pause");
                break;
            case 0:
                cout<<"Volviendo al menu anterior"<<endl;
                return;
            default:
                cout<<"OPCION INCORRECTA. VUELVA A INGRESAR"<<endl;
                system("pause");
                break;
        }
    }
}

void Menu::menuClub(){
    int opc;
    while(true){
        system("cls");
        cout<<" *********** 2. MENU CLUBES ***************"     <<endl;
        cout<<"1. Agregar Registro Club"                        <<endl;///Agregar Club1
        cout<<"2. Borrado Logico Registro Club"                 <<endl;///Borrado Club3
        cout<<"3. Modificar registro Club"                      <<endl;///Modificar Club5
        cout<<"4. Listar Registro Club"                         <<endl;///Listar Club2
        cout<<"5. Buscar club"                                  <<endl;///4
        cout<<"-------------------------------------------"     <<endl;
        cout<<"0. Salir"                                        <<endl;
        cout<<"*******************************************"     <<endl<<endl;
        cout<<"SELECCIONAR OPCION ";
        cin>>opc;
        cin.ignore();
        system("cls");
        switch(opc){
            case 1: _archivoClub.agregarRegistro();
                system("pause");
                break;
            case 2: _archivoClub.bajaRegistro();
                system("pause");
                break;
            case 3: _archivoClub.modificarRegistro();
                system("pause");
                break;
            case 4: _archivoClub.mostrarRegistros();
                system("pause");
                break;
            case 5: _archivoClub.buscarRegistro();
                system("pause");
                break;
            case 0:
                cout<<"Volviendo al menu anterior"<<endl;
                return;
            default:
                cout<<"OPCION INCORRECTA. VUELVA A INGRESAR"<<endl;
                system("pause");
                break;
        }
    }
}

void Menu::menuPartido(){
    int opc;
    while(true){
        system("cls");
        cout<<" *********** 3. MENU PARTIDOS ***************"   <<endl;
        cout<<"1. Agregar Registro Partido"                     <<endl;
        cout<<"2. Borrado Logico Registro Partido"              <<endl;
        cout<<"3. Mostrar Registro Partido"                     <<endl;
        cout<<"4. Listar Registro Partido"                      <<endl;
        cout<<"5. Buscar Partido"                               <<endl;
        cout<<"-------------------------------------------"     <<endl;
        cout<<"0. Salir"                                        <<endl;
        cout<<"*******************************************"     <<endl<<endl;
        cout<<"SELECCIONAR OPCION ";
        cin>>opc;
        cin.ignore();
        system("cls");
        switch(opc){
            case 1: _archivoPartido.agregarRegistro();
                system("pause");
                break;
            case 2: _archivoPartido.bajaRegistro();
                system("pause");
                break;
            case 3: _archivoPartido.modificarRegistro();
                system("pause");
                break;
            case 4: _archivoPartido.mostrarRegistros();
                system("pause");
                break;
            case 5: _archivoPartido.buscarRegistro();
                system("pause");
                break;
            case 0:
                cout<<"Volviendo al menu anterior"<<endl;
                return;
            default:
                cout<<"OPCION INCORRECTA. VUELVA A INGRESAR"<<endl;
                system("pause");
                break;
        }
    }
}

void Menu::menuTorneo(){
    int opc;
    while(true){
        system("cls");
        cout<<" *********** 4. MENU TORNEOS ***************"    <<endl;
        cout<<"1. Agregar Registro Torneo"                      <<endl;
        cout<<"2. Borrado Logico Registro Torneo"               <<endl;
        cout<<"3. Modificar Registro Torneo"                    <<endl;
        cout<<"4. Listar Registro Torneo"                       <<endl;
        cout<<"5. Buscar Torneo"                                <<endl;
        cout<<"-------------------------------------------"     <<endl;
        cout<<"0. Salir"                                        <<endl;
        cout<<"*******************************************"     <<endl<<endl;
        cout<<"SELECCIONAR OPCION ";
        cin>>opc;
        cin.ignore();
        system("cls");
        switch(opc){
            case 1: _archivoTorneo.agregarRegistro();
                system("pause");
                break;
            case 2: _archivoTorneo.bajaRegistro();
                system("pause");
                break;
            case 3: _archivoTorneo.modificarRegistro();
                system("pause");
                break;
            case 4: _archivoTorneo.mostrarRegistros();
                system("pause");
                break;
            case 5: _archivoTorneo.buscarRegistro();
                system("pause");
                break;
            case 0:
                cout<<"Volviendo al menu anterior"<<endl;
                return;
            default:
                cout<<"OPCION INCORRECTA. VUELVA A INGRESAR"<<endl;
                system("pause");
                break;
        }
    }
}

void Menu::menuSanciones(){
    int opc;
    while(true){
        system("cls");
        cout<<" *********** 5. MENU SANCIONES ***************"  <<endl;
        cout<<"1. Agregar Registro Sancion"                     <<endl;
        cout<<"2. Borrado Logico Registro Sancion"              <<endl;
        cout<<"3. Modificar Registro Sancion"                   <<endl;
        cout<<"4. Listar Registro Sancion"                      <<endl;
        cout<<"5. Buscar Sancion"                               <<endl;
        cout<<"-------------------------------------------"     <<endl;
        cout<<"0. Salir"                                        <<endl;
        cout<<"*******************************************"     <<endl<<endl;
        cout<<"SELECCIONAR OPCION ";
        cin>>opc;
        cin.ignore();
        system("cls");
        switch(opc){
            case 1: _archivoSanciones.agregarRegistro();
                system("pause");
                break;
            case 2: _archivoSanciones.bajaRegistro();
                system("pause");
                break;
            case 3: _archivoSanciones.modificarRegistro();
                system("pause");
                break;
            case 4: _archivoSanciones.mostrarRegistros();
                system("pause");
                break;
            case 5: _archivoSanciones.buscarRegistro();

                system("pause");
                break;
            case 0:
                cout<<"Volviendo al menu anterior"<<endl;
                return;
            default:
                cout<<"OPCION INCORRECTA. VUELVA A INGRESAR"<<endl;
                system("pause");
                break;
        }
    }
}

void Menu::menuEstadios(){
    int opc;
    while(true){
        system("cls");
        cout<<" *********** 6. MENU ESTADIOS ***************"   <<endl;
        cout<<"1. Agregar Registro Estadio"                     <<endl;
        cout<<"2. Borrado Logico Registro Estadio"              <<endl;
        cout<<"3. Modificar Registro Estadio"                   <<endl;
        cout<<"4. Listar Registro Estadio"                      <<endl;
        cout<<"5. Buscar Estadio"                               <<endl;
        cout<<"-------------------------------------------"     <<endl;
        cout<<"0. Salir"                                        <<endl;
        cout<<"*******************************************"     <<endl<<endl;
        cout<<"SELECCIONAR OPCION ";
        cin>>opc;
        cin.ignore();
        system("cls");
        switch(opc){
            case 1: _archivoEstadio.agregarRegistro();
                system("pause");
                break;
            case 2: _archivoEstadio.bajaRegistro();
                system("pause");
                break;
            case 3: _archivoEstadio.modificarRegistro();
                system("pause");
                break;
            case 4: _archivoEstadio.mostrarRegistros();
                system("pause");
                break;
            case 5: _archivoEstadio.buscarRegistro();
                system("pause");
                break;
            case 0:
                cout<<"Volviendo al menu anterior"<<endl;
                return;
            default:
                cout<<"OPCION INCORRECTA. VUELVA A INGRESAR"<<endl;
                system("pause");
                break;
        }
    }
}









