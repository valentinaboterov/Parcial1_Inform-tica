#ifndef USUARIO_H
#define USUARIO_H
#include<Registro.h>
#include<Administrador.h>
#include<Codificacion.h>
#include<fstream>
#include<iostream>
#include<string>

using namespace std;
class Usuario{
  public:
    int  MenuUsuario();
    void Actualizardisponibilidad(int sala,char fila,int asiento); //Actualiza disponibilidad de asientos.
    void Actualizarcartelera(string nombre);
    void Pago(int cantida,int pago);     //Retorna la devuelta según pago
    void llenararchivo(string origi,string temp);
};
#endif // USUARIO_H
