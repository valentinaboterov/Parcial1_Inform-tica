#include<Usuario.h>
#include<Registro.h>
#include<map>
#include<vector>
#include<string>
#include<stdlib.h>
#include <bits/stdc++.h>

Registro regis;
Administrador admin;
Usuario usu;
using namespace std;

//Mostrar menú Usuario.
int Usuario::MenuUsuario(){
    cout<<endl;
    string nombre;
    nombre=regis.nombreusuario;
    int opcion=0;
    cout<<"   Bienvenido "<<nombre<<"!"<<endl;
    cin>>opcion;
};
//Actualizar cartelera
void Usuario::Actualizarcartelera(string nombre){
    ifstream archivo("C:/Users/WIN10 PRO/Documents/Parcial1/Pelicula.txt");
    ofstream final("C:/Users/WIN10 PRO/Documents/Parcial1/temp.txt");
    int dis=0,pos=0;
    string cambio="",compara="",sala="",genero="",tiempo="",hora="",disponible="",años="",edad="",linea1="";
    char linea[400];
    while(!archivo.eof()){
        archivo.getline(linea,sizeof (linea));
        compara=admin.BuscarPelicula(linea,2);  //Retorna el normbre de pelicula en la linea
        if(compara==nombre){        //Es la pelicula a actualizar.
            sala=admin.BuscarPelicula(linea,1);genero=admin.BuscarPelicula(linea,3);tiempo=admin.BuscarPelicula(linea,4);
            hora=admin.BuscarPelicula(linea,5);disponible=admin.BuscarPelicula(linea,6);edad=admin.BuscarPelicula(linea,7);
            while(disponible[pos+1]!='-'){
                cambio+=disponible[pos];
                pos+=1;
            }
            dis=stoi(cambio)-1;
            disponible=to_string(dis)+"-70";
            linea1=sala+"/"+compara+"/"+genero+"/"+tiempo+"/"+hora+"/"+disponible+"/"+edad;
            final<<linea1<<endl;
        }else{
            final<<linea<<endl;
        }
    }archivo.close();final.close();
    usu.llenararchivo("C:/Users/WIN10 PRO/Documents/Parcial1/temp.txt","C:/Users/WIN10 PRO/Documents/Parcial1/Pelicula.txt");
};
//Atualiza asientos
void Usuario::Actualizardisponibilidad(int sala,char fila,int asiento){
    ifstream archivo("C:/Users/WIN10 PRO/Documents/Parcial1/Disponibilidad.txt");
    ofstream final("C:/Users/WIN10 PRO/Documents/Parcial1/temp.txt");       //Copia para modificar disponibilidad
    string cambio="",compara="",linea1="";
    char linea[400];
    while(!archivo.eof()){
        archivo.getline(linea,sizeof (linea));
        compara=admin.BuscarDisponible(linea,1);
        if(stoi(compara)==sala){        //Sala a actualizar.
            cambio=fila+to_string(asiento)+",";
            linea1=linea+cambio;
            final<<linea1<<endl;
        }else{
            final<<linea<<endl;
        }
    }
    archivo.close();final.close();
    usu.llenararchivo("C:/Users/WIN10 PRO/Documents/Parcial1/temp.txt","C:/Users/WIN10 PRO/Documents/Parcial1/Disponibilidad.txt");
};
//Pago asiento
void Usuario::Pago(int cantidad,int pago){
    int devuelta=0;
    devuelta=cantidad-pago;     //Resta la cantidad en billetes con la cantidad a pagar.
    cout<<"Su devuelta es: "<<devuelta<<endl;
};
//Cambiar archivo temporal por actualizado.
void Usuario::llenararchivo(string origi,string temp){
    char linea[200];
    string linea1="";
    ifstream temporal(temp);  //Abre archivo para leer
    ofstream original(origi);  //Archivo final con informacion actualizada.
    while(!temporal.eof()){  //Hasta que llegue al final del archivo
        temporal.getline(linea,sizeof (linea));     //Toma linea a linea
        linea1=linea;
        original<<linea1<<endl;     //Lo lleva al archivo final.
    }
    temporal.close();original.close();//Cierra archivos.
};
