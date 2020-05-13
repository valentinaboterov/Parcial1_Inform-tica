#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include<fstream>
#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;
class Administrador{
  public:
    map<int,map<string,vector<int>>> inicializacion();
    char filas[5]={'A','B','C','D','E'};
    void imprimirSala(int sala);
    void imprimirCartelera();
    void Agregarpelicula();
    void Reportediario(int dia,string datos);   //Recibe el día y los datos de la venta(Usuario,sala,pelicula y costo).
    void MostrarReporte();
    void MostrarPrecios();
    void Agregarestrenos();
    void imprimirestreno();
    void EliminarP(string nombre);
    void EliminarE(string nombre);
    int PreciosPelicula(int sala);  //Recibe la sala en la que se da la pelicula.
    //Buscar componentes en archivos.
    string BuscarPelicula(string linea,int romper);
    string Buscar(string linea,int romper);
    string BuscarDisponible(string linea, int romper);

};

#endif // ADMINISTRADOR_H
