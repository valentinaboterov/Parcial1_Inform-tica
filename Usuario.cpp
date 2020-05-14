#include<Usuario.h>
#include<Registro.h>
#include<string>


Registro regis;
Administrador admini;
Usuario usua;
using namespace std;

//Mostrar menú Usuario.
void Usuario::Bienvenido(){
    cout<<endl;
    string nombre;
    nombre=regis.nombreusuario;
    cout<<"   Bienvenid@ "<<"!"<<nombre<<endl;
};
//Actualizar cartelera
void Usuario::Actualizarcartelera(int sala){
    ifstream archivo("C:/Users/WIN10 PRO/Documents/Parcial1/Peliculas.txt");
    ofstream final("C:/Users/WIN10 PRO/Documents/Parcial1/temp.txt");
    int dis=0,pos=0;
    string cambio="",compara="",nombre="",genero="",tiempo="",hora="",disponible="",edad="",linea1="";
    char linea[400];
    while(!archivo.eof()){
        archivo.getline(linea,sizeof (linea));linea1=linea;
        if(linea1.length()<1){break;}       //Ya acabo el archivo
        compara=admini.BuscarPelicula(linea,1);  //Retorna el normbre de pelicula en la linea
        if(stoi(compara)==sala){        //Es la pelicula a actualizar.
            nombre=admini.BuscarPelicula(linea,2);
            genero=admini.BuscarPelicula(linea,3);
            tiempo=admini.BuscarPelicula(linea,4);
            hora=admini.BuscarPelicula(linea,5);
            disponible=admini.BuscarPelicula(linea,6);
            edad=admini.BuscarPelicula(linea,7);
            while(disponible[pos]!='-'){
                cambio+=disponible[pos];
                pos+=1;
            }
            dis=(stoi(cambio))-1;
            disponible=to_string(dis)+"-70";
            linea1=to_string(sala)+"/"+nombre+"/"+genero+"/"+tiempo+"/"+hora+"/"+disponible+"/"+edad;
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
        archivo.getline(linea,sizeof (linea)); linea1=linea;
        if(linea1.length()<1){break;}
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
int Usuario::Pago(int cantidad,int pago){
    int devuelta=0;
    if(cantidad<pago){
        cout<<"No es suficiente dinero."<<endl;
        devuelta=-1;
    }else{
        devuelta=cantidad-pago;     //Resta la cantidad en billetes con la cantidad a pagar.
    }return devuelta;
};
//Silla diponible
bool Usuario::Silladisponible(int sala,char fila, int columna){
    map<int,map<string,vector<int>>> salas;
    map<string,vector<int>> filas;
    vector<int> sillas;
    string filaux="";
    filaux+=fila;
    salas=admini.inicializacion();
    filas=salas[sala];
    sillas=filas[filaux];
    if(sillas[columna-1]==0){
        return true;
    }else{
        return false;
    }
}

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
