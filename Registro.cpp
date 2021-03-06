#include "Registro.h"
#include<Codificacion.h>
#include <iostream>
#include<string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;
codificacion codif;
Registro reg;
//Validación ingreso administración.
bool Registro::Administrador(string clave){
    //Se abre el archivo que contiene la clave del usuario administrador.
    ifstream archivo;
    archivo.open("C:/Users/WIN10 PRO/Documents/Parcial1/Registro.txt");
    if(!archivo.is_open()){          //Si no abrio exitosamente el archivo se acaba el programa.
        cout<<"Error al abrir el archivo"<<endl;
        exit(1);
    }
    //Inicialización de variables.
    string linea="";
    getline(archivo,linea);     //Se lee la primera línea y se guarda en string linea.
    archivo.close();
    clave=codif.Cod2(clave,2);
    if(linea==clave){        //Si la clave es correcta retorna true de lo contrario false.
        return true;
    }else{
        return false;
    }
};

//Mostrar menú Admin.
int Registro::MenuAdmin(){
    int opcion=0;
    cout<<"------------------------------Administrador------------------------------"<<endl;
    cout<<"1. Agregar pelicula."<<endl;
    cout<<"2. Ingresar pelicula para estreno."<<endl;
    cout<<"3. Ver reporte."<<endl;
    cout<<"4. Eliminar estreno."<<endl;
    cout<<"5.Salir."<<endl;
    cout<<"Ingrese la opcion deseada: ";
    cin>>opcion; cout<<endl;
    return opcion;
};
//Validación Usuario.
bool Registro::Usuario(string id,string clave){
    bool ban1=true,ban2=true,acceso=false;
    char linea[400];
    string idoriginal="",claveoriginal="",nombre="";
    int cont=0;;
    Registro regis;
    codificacion cod;
    clave=cod.Cod2(clave,2);
    ifstream base("C:/Users/WIN10 PRO/Documents/Parcial1/Registro.txt");
    while(!base.eof()){
        cont+=1;
        base.getline(linea,sizeof(linea));  //Obtiene la linea
        if(cont>1){ //El primer renglon es el administrador.
          idoriginal=regis.Buscar(linea,1);     //Obtiene lo original para comparar
          claveoriginal=regis.Buscar(linea,3);
          for(int i=0;i<id.length();i++){       //Busca el id en la base de datos
              if(idoriginal[i]!=id[i]){
                  ban1=false;
                  break;
              }
          }for(int i=0;i<clave.length();i++){       //Busca la clave en la base de datos
              if(claveoriginal[i]!=clave[i]){
                  ban2=false;
                  break;
              }
          }if(ban1==true&&ban2==true){      //El id y clave se encontraron
              return true;
              nombre=regis.Buscar(linea,2);
              regis.nombreusuario=nombre;
              acceso=true;
          }if(acceso==true){
            return acceso;
         }
        }ban1=true;ban2=true;
    }if(acceso==false){
        return false;
    }

};
//Ingreso como usuario.
void Registro::RegistroUsuario(string id,string nombre,string clave){
    if(clave.length()!=4){
        cout<<"La clave debe ser de 4 digitos."<<endl;
        exit(1);
    }
    clave=codif.Cod2(clave,2);
    ofstream archivosalida("C:/Users/WIN10 PRO/Documents/Parcial1/Registro.txt",std::fstream::app); //Abre el archivo de salida
    if(!archivosalida.is_open()){
        cout<<"Error al abrir el archivo de salida."<<endl;
        exit(1);
    }
    archivosalida<<id<<"/"<<nombre<<"/"<<clave<<endl;       //Lo agrega al final en formato respectivo
    archivosalida.close();
    cout<<"Registro exitoso!"<<endl;
}


//Buscar separadores
string Registro::Buscar(string linea,int romper){
    //Inicializacion de variables.
    //cant:Cantidad e elementos para el subplot,cont:acceder a diferentes valores, pos:Saber donde inicia cada valor.
    int lon=linea.length(),cont=0,cant=0,pos=0;
    string s1="",s2="",s3="",s4="";
    for(int i=0;i<lon;i++){
        cant+=1;
        if(linea[i]=='/'){   //Busca la separación de datos en la base.
            cont+=1;
            if(cont==1){ //Hasta este valor de i esta el id del usuario.
                s1=linea.substr(0,cant-1);  //id.
                pos=i+1;        //incremeta la posicion 1 unidad para empezar el nombre.
                cant=0;
            }if(cont==2){   //Nombre
                s2=linea.substr(pos,cant-1);
                pos=i+1;  //incremeta la posicion 1 unidad para empezar el saldo.
                cant=0;
            }
        }
    }
    s3=linea.substr(pos,cant);
    if(romper==1){return s1;}
    if(romper==2){return s2;}
    if(romper>2){return s3;}
};
