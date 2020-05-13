#ifndef REGISTRO_H
#define REGISTRO_H
#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Registro{
public:
    bool Administrador(string clave);
    int  MenuAdmin();
    bool Usuario(string id,string clave);
    void RegistroUsuario(string id,string nombre,string clave);
    int  MenuUsuario();
private:
    string nombreusuario;
    void RegistroUsuario();
    string Buscar(string linea,int romper); //Recibe linea de archivo y busca los separadores de datos..
};
#endif // REGISTRO_H
