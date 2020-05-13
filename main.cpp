#include <iostream>
#include<Registro.h>
#include<Usuario.h>
#include<Administrador.h>

using namespace std;

int main()
{
    int opcion=0,opcion1=0;
    string clave="";
    Registro registro;
    Administrador admin;
    Usuario usuario;
    cout<<"------------------------------Bienvenido!------------------------------"<<endl;
    while(opcion1!=3){
        cout<<"-------------------------Como desea ingresar?------------------------- "<<endl;
        cout<<"1. Administrador."<<endl;
        cout<<"2. Usuario."<<endl;
        cout<<"3.Salir."<<endl;
        cout<<"Opcion: ";
        cin>>opcion1;
        if(opcion1==1){      //Ingresar como admin.
            cout<<"                           Usuario: Admin"<<endl;
            cout<<"                             Clave:";
            cin>>clave;cout<<endl;
            if(registro.Administrador(clave)==true){        //Clave correcta
                opcion=registro.MenuAdmin();
                while(opcion!=6){
                       if(opcion==1){   //Agregar pelicula.
                           admin.Agregarpelicula();
                           admin.imprimirCartelera();
                       }if(opcion==2){ //Agregar estreno.
                           admin.Agregarestrenos();
                           admin.imprimirestreno();
                       }if(opcion==3){          //Ver reportes
                           admin.MostrarReporte();
                       }if(opcion==4){  //Eliminar pelicula
                           string nombre="";
                           cout<<"Ingrese el nombre de la pelicula que desea eliminar: "<<endl;
                           cin>>nombre;
                           admin.EliminarP(nombre);
                           admin.imprimirCartelera();
                       }if(opcion==5){      //Eliminar estreno.
                           string nombre="";
                           cout<<"Ingrese el nombre del estreno que desea eliminar: "<<endl;
                           cin>>nombre;
                           admin.EliminarE(nombre);
                           admin.imprimirestreno();
                       }
                       opcion=registro.MenuAdmin();
                }
            }else{
                cout<<"Clave incorrecta"<<endl;
            }
        }
        if(opcion1==2){  //Ingresar como usuario.
                   cout<<"Desea: "<<endl<<"1. Iniciar sesion."<<endl<<"2.Registrarse."<<endl;
                   cout<<opcion;
                   if(opcion==1){       // Inciar sesion.
                       string id="",clave="";
                       cout<<"Ingrese su ID: "<<endl; cin>>id;
                       cout<<"Ingrese su clave de 4 digitos: "<<endl; cin>>clave;
                       if(registro.Usuario(id,clave)==true){        //Inicio de sesión
                           int sala=0,preci=0,cont=1,columna=0,billetes,compra=1;
                            char fila;
                           usuario.Bienvenido();
                           while(compra!=0){
                               admin.imprimirCartelera();admin.imprimirestreno();
                               cout<<"Profavor ingrese la sala en la que se está dando la película que desea ver: "<<endl; cin>>sala;
                               admin.MostrarPrecios();preci=admin.PreciosPelicula(sala);
                               cout<<"El asiento para la pelicula que desea ver tiene un valor de:"<<preci<<"Desea continuar? "<<"1.Si, 0.No"<<endl;
                               cin>>cont;
                               if(cont==1){
                                   admin.imprimirSala(sala);
                                   cout<<"Porfavor ingrese la letra de la fila en mayuscula: "; cin>>fila; cout<<endl;
                                   cout<<"Ingrese el numero de la columna:"; cin>>columna; cout<<endl<<endl;
                                   cout<<"Desea cancelar en efectivo o tarjeta? 1.Tajeta,2.Efectivo";cin>>cont;
                                   if(cont==2){
                                       cout<<"Cantidad de dinero en billetes: "; cin>>billetes;
                                        usuario.Pago(billetes,preci);
                                   } usuario.Actualizarcartelera(sala);usuario.Actualizardisponibilidad(sala,fila,columna);
                                   cout<<"Desea hacer otra compra? 1.Si,0.No"<<endl; cin>>compra;
                               }
                         }
                       }
                   }else{
                       string id="",clave="",nombre="";
                       cout<<"Porfavor ingrese su ID: "; cin>>id; cout<<endl;
                       cout<<"Ingrese su nombre: "; cin>>nombre; cout<<endl;
                       cout<<"Ingrese una clave de 4 digitos: ";cin>>clave; cout<<endl;
                       registro.RegistroUsuario(id,nombre,clave);
                       cout<<"Para validar su cuenta inicie sesion como usuario. "<<endl;
                   }
        }if(opcion1==3){cout<<endl<<"---------------------Gracias y vuelva pronto!-----------------------"<<endl;}
    }
}
