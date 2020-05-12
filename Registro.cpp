#include "Registro.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;


//Validación ingreso administración.
bool Registro::Administrador(int clave){
    //Se abre el archivo que contiene la clave del usuario administrador.
    ifstream archivo;
    archivo.open("C:/Users/WIN10 PRO/Documents/Parcial1/Admin.txt");
    if(!archivo.is_open()){          //Si no abrio exitosamente el archivo se acaba el programa.
        cout<<"Error al abrir el archivo"<<endl;
        exit(1);
    }
    //Inicialización de variables.
    string linea=""; int original=0;
    getline(archivo,linea);     //Se lee la primera línea y se guarda en string linea.
    archivo.close();
    original=atoi(linea.c_str());   //Se convierte la clave original en entero.
    if(original==clave){        //Si la clave es correcta retorna true de lo contrario false.
        return true;
    }else{
        return false;
    }
};

//Mostrar menú Admin.
int Registro::MenuAdmin(){
    int opcion=0;
    cout<<"------------------------------Administrador------------------------------"<<endl;
    cout<<"1. Ingresar pelicula a cartelera."<<endl;
    cout<<"2. Ingresar pelicula para estreno."<<endl;
    cout<<"3. Revisar reportes del dia."<<endl;
    cout<<"4. Actualizar disponibilidad. "<<endl;
    cout<<"5. Salir"<<endl;
    cout<<"Ingrese la opcion deseada: ";
    cin>>opcion; cout<<endl;
    return opcion;
};

//Ingreso como usuario.
void Registro::Usuario(string nombre){
    nombreusuario=nombre;
}

//Mostrar menú Usuario.
int  Registro::MenuUsuario(){
    cout<<endl;
    int opcion=0;
    cout<<"   Bienvenido "<<nombreusuario<<"!"<<endl;
    //IMPRIMIR OPCIONES DISPONIBLES CUADRO 1 DE LA GUÍA
};
