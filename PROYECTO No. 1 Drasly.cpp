//============================================================================
// Name        : .cpp
// Author      : DRASLY RAFAEL
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<cstdlib>
#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

void nuevo();
void eliminar();
void modificar();
void salir();


char nombre[60],carrera[70];
int semestre=0;
int edad=0;
int Carnet=0;
int AuxCarnet=0;
bool encontrado=false;
char AuxCarrera[10];

int main(){
	system("color F5");

    int opcion=0;
    do{
        cout<<"-----DATOS DE ESTUDIANTES DE UNIVERSIDAD SAN RAFAEL------"<<endl;
        cout<<"1. Nuevos datos"<<endl;
        cout<<"2. Eliminar datos"<<endl;
        cout<<"3. Modifique datos"<<endl;
        cout<<"4. Salir"<<endl;
        cout<<"ESCOGA UNA OPCION  " <<endl;
        cin>>opcion;
        switch(opcion){
            case 1:
                nuevo();
            break;
            case 2:
                eliminar();
            break;
            case 3:
                modificar();
            break;
            case 4:
                salir();
            break;
            default:
                cout<<"!ERROR, ESCOGA UNA OPCION DE LAS ANTERIORES" <<endl;
        }
    }while(opcion!=4);

    return 0;
    system("PAUSE");
}


void nuevo(){
    ofstream Escribir;
    ifstream consulta;
    bool repetido=false;
    Escribir.open("Universitarios.txt",ios::out|ios::app);
    consulta.open("Universitarios.txt",ios::in);
    if(Escribir.is_open() && consulta.is_open()){
        cout<<"INGRESE EL CARNET DEL ESTUDIANTE:" <<endl;
        cin>>AuxCarnet;
        consulta>>Carnet;
        while(!consulta.eof()){
            consulta>>nombre>>semestre>>carrera>>edad;
            if(Carnet==AuxCarnet){
                cout<<"YA HAY DATOS CON ESTA CLAVE"<<endl;
                repetido=true;
                break;
            }
            consulta>>Carnet;
        }
        if(repetido==false){
            cout<<"INGRESE EL NOMBRE DEL ESTUDIANTE: " <<endl;
            cin>>nombre;
            cout<<"CUAL ES EL SEMESTRE DEL ESTUDIANTE: "<<endl;
            cin>>semestre;
            cout<<"CUAL ES LA CARRERA DEL ESTUDIANTE: "<<endl;
            cin>>carrera;
            cout<<"INGRESE LA EDAD DEL ESTUDIANTE: "<<endl;
            cin>>edad;
            Escribir<<AuxCarnet<<" "<<nombre<<" "<<semestre<<" "<<carrera<<" "<<edad<<endl;
            cout<<"LOS DATOS HAN SIDO AGREGADOS"<<endl;
        }

    }else{
        cout<<" NO SE HA LOGRADO ABRIR/CREAR EL ARCHIVO"<<endl;
    }
    Escribir.close();
    consulta.close();
}

void eliminar(){
    ofstream aux;
    ifstream lectura;
    encontrado=false;
    int AuxCarnet=0;

    aux.open("auxiliar.txt",ios::out);
    lectura.open("universitarios.txt",ios::in);
    if(aux.is_open() && lectura.is_open()){
        cout<<"INGRESE EL NUMERO DE CARNET DEL ESTUDIANTE QUE DESEA ELIMINAR: " <<endl;
       cin>>AuxCarnet;
        lectura>>Carnet;
        while(!lectura.eof()){
            lectura>>nombre>>semestre>>carrera>>edad;
            if(AuxCarnet==Carnet){
                encontrado=true;

                cout<<"LOS DATOS HAN SIDO ELIMINADOS:"<<endl;
            }else{
                aux<<Carnet<<" "<<nombre<<" "<<semestre<<" "<<carrera<<" "<<edad<<endl;
            }
            lectura>>Carnet;
            }
    }else{
        cout<< "NO SE HA APERTURADO O CREADO EL ARCHIVO"<<endl;
    }
    if(encontrado==false){
        cout<<"NO SE HA ENCONTRADO NINGUN DATO CON EL NUMERO DE CARNET INGRESADO: "<<AuxCarnet<<endl;
    }
    aux.close();
    lectura.close();
    remove("universitarios.txt");
    rename("auxiliar.txt","universitarios.txt");

}

void modificar(){
    ofstream aux;
    ifstream lectura;
    encontrado=false;
    int AuxCarnet=0;
    char auxNombre[30];
    aux.open("auxiliar.txt",ios::out);
    lectura.open("universitarios.txt",ios::in);
    if(aux.is_open() && lectura.is_open()){
        cout<<"INGRESE EL NUMERO DE CARNET QUE DESEA MODIFICAR "<<endl;
        cin>>AuxCarnet;
        lectura>>Carnet;
        while(!lectura.eof()){
            lectura>>nombre>>semestre>>carrera>>edad;
            if(AuxCarnet==Carnet){
                encontrado=true;
                cout<<"__________________________"<<endl;
                cout<<"carnet: "<<Carnet<<endl;
                cout<<"Nombre: "<<nombre<<endl;
                cout<<"Semestre: "<<semestre<<endl;
                cout<<"Carrera: "<<carrera<<endl;
                cout<<"Edad: "<<edad<<endl;
                cout<<"__________________________"<<endl;
                cout<< "INGRESE EL NUEVO UNIVERSITARIO A INGRESAR Y SU NUMERO DE CARNET:" <<Carnet<<": ";
                cin>>auxNombre;
                aux<<Carnet<<" "<<auxNombre<<" "<<semestre<<" "<<carrera<<" "<<edad<<endl;
                cout<<"LOS DATOS HAN SIDO MODIFICADOS"<<endl;
            }else{
                aux<<Carnet<<" "<<nombre<<" "<<semestre<<" "<<carrera<<" "<<edad<<endl;
            }
            lectura>>Carnet;
        }
    }else{
        cout<<"NO SE HA APERTURADO O CREADO EL ARCHIVO: "<<endl;
    }
    if(encontrado==false){
        cout<<"NO HAY DATOS QUE COINCIDAN CON EL NUMERO DE CARNET: "<<AuxCarnet<<endl;
    }
    aux.close();
    lectura.close();
    remove("universitarios.txt");
    rename("auxiliar.txt","universitarios.txt");
}
void salir(){
    cout<<"EL PROGRAMA HA FINALIZADO"<<endl;
}
