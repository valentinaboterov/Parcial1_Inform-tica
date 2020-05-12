#include <iostream>
#include<Registro.h>

using namespace std;

int main()
{
    int opcion=0,clave=0;
    Registro registro;
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
                while(opcion!=5){           //IMPLEMENTAR OPCIONES COMO ADMINISTRADOR.

                }
            }else{
                cout<<"Clave incorrecta. Recuerde que la clave es de 8 dígitos numéricos."<<endl;
            }
        }
        if(opcion==2){  //Ingresar como usuario.
            registro.MenuUsuario();
        }
    }
}
