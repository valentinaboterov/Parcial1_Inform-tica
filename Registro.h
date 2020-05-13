#ifndef REGISTRO_H
#define REGISTRO_H
#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Registro{
public:
    string nombreusuario;
    bool Administrador(string clave);
    int  MenuAdmin();
    bool Usuario(string id,string clave);
    void RegistroUsuario(string id,string nombre,string clave);
private:
    void RegistroUsuario();
    string Buscar(string linea,int romper); //Recibe linea de archivo y busca los separadores de datos..
};
#endif // REGISTRO_H
