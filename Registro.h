#ifndef REGISTRO_H
#define REGISTRO_H
#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Registro{
public:
    bool Administrador(int clave);
    int  MenuAdmin();
    void Usuario(string nombre);
    int  MenuUsuario();
private:
    string nombreusuario;
};
#endif // REGISTRO_H
