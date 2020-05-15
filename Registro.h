#ifndef REGISTRO_H
#define REGISTRO_H
#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Registro{
public:
    string nombreusuario;
    bool Administrador(string clave);       //Validacion clave administrador
    int  MenuAdmin();
    bool Usuario(string id,string clave);       //Iniciar sesion
    void RegistroUsuario(string id,string nombre,string clave);     //Registro nuevo
    string Buscar(string linea,int romper)
};
#endif // REGISTRO_H
