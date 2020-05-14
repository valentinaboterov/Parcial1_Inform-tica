#include<Usuario.h>
#include<Registro.h>
#include<map>
#include<vector>
#include<string>
#include<stdlib.h>
#include <bits/stdc++.h>

Registro regis;
Administrador admini;
Usuario usua;
using namespace std;

//Mostrar menú Usuario.
void Usuario::Bienvenido(){
    cout<<endl;
    string nombre;
    nombre=regis.nombreusuario;
    cout<<"   Bienvenid@ "<<nombre<<"!"<<endl;
};
//Actualizar cartelera
void Usuario::Actualizarcartelera(int sala){
    ifstream archivo("C:/Users/WIN10 PRO/Documents/Parcial1/Peliculas.txt");
    ofstream final("C:/Users/WIN10 PRO/Documents/Parcial1/temp.txt");
    int dis=0,pos=0;
    string cambio="",compara="",nombre="",genero="",tiempo="",hora="",disponible="",edad="",linea1="";
    char linea[400];
    while(!archivo.eof()){
        archivo.getline(linea,sizeof (linea));
        compara=admini.BuscarPelicula(linea,1);  //Retorna el normbre de pelicula en la linea
        if(stoi(compara)==sala){        //Es la pelicula a actualizar.
            nombre=admini.BuscarPelicula(linea,2);genero=admini.BuscarPelicula(linea,3);tiempo=admini.BuscarPelicula(linea,4);
            hora=admini.BuscarPelicula(linea,5);disponible=admini.BuscarPelicula(linea,6);edad=admini.BuscarPelicula(linea,7);
            while(disponible[pos]!='-'){
                cambio+=disponible[pos];
                pos+=1;
            }
            dis=stoi(cambio)-1;
            disponible=to_string(dis)+"-70";
            linea1=to_string(sala)+"/"+nombre+"/"+genero+"/"+tiempo+"/"+hora+"/"+disponible+"/"+edad+"+";
            final<<linea1<<endl;
        }else{
            final<<linea<<endl;
        }
    }archivo.close();final.close();
    usua.llenararchivo("C:/Users/WIN10 PRO/Documents/Parcial1/temp.txt","C:/Users/WIN10 PRO/Documents/Parcial1/Peliculas.txt");
};
//Atualiza asientos
void Usuario::Actualizardisponibilidad(int sala,char fila,int asiento){
    ifstream archivo("C:/Users/WIN10 PRO/Documents/Parcial1/Disponibilidad.txt");
    ofstream final("C:/Users/WIN10 PRO/Documents/Parcial1/temp.txt");       //Copia para modificar disponibilidad
    string cambio="",compara="",linea1="";
    char linea[400];
    while(!archivo.eof()){
        archivo.getline(linea,sizeof (linea));
        compara=admini.BuscarDisponible(linea,1);
        if(stoi(compara)==sala){        //Sala a actualizar.
            cambio=fila+to_string(asiento)+",";
            linea1=linea+cambio;
            final<<linea1<<endl;
        }else{
            final<<linea<<endl;
        }
    }
    archivo.close();final.close();
    usua.llenararchivo("C:/Users/WIN10 PRO/Documents/Parcial1/temp.txt","C:/Users/WIN10 PRO/Documents/Parcial1/Disponibilidad.txt");
};
//Pago asiento
void Usuario::Pago(int cantidad,int pago){
    int devuelta=0;
    devuelta=cantidad-pago;     //Resta la cantidad en billetes con la cantidad a pagar.
    cout<<"Su devuelta es: "<<devuelta<<endl;
};
//Cambiar archivo temporal por actualizado.
void Usuario::llenararchivo(string temp,string origi){
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
