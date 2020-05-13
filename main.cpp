#include <iostream>
#include<Registro.h>
#include<Administrador.h>

using namespace std;

int main()
{
    int opcion=0;
    string clave="";
    Registro registro;
    Administrador admin;
    //Iniciar sesión como usuario.
    cout<<"------------------------------Bienvenido!------------------------------"<<endl;
    while(opcion!=3){
        cout<<"-------------------------Como desea ingresar?------------------------- "<<endl;
        cout<<"1. Administrador."<<endl;
        cout<<"2. Usuario."<<endl;
        cout<<"3.Salir."<<endl;
        cout<<"Opcion: ";
        cin>>opcion;
        if(opcion==1){      //Ingresar como admin.
            cout<<"                           Usuario: Admin"<<endl;
            cout<<"                             Clave:";
            cin>>clave;cout<<endl;
            if(registro.Administrador(clave)==true){        //Clave correcta
                opcion=registro.MenuAdmin();
                while(opcion!=5){
                       if(opcion==1){   //Agregar pelicula.
                           admin.Agregarpelicula();
                       }if(opcion==2){ //Agregar estreno.
                           admin.estrenos();
                       }
                }
            }else{
                cout<<"Clave incorrecta"<<endl;
            }
        }
        if(opcion==2){  //Ingresar como usuario.

        }
    }
}
