#include <iostream>
#include<Registro.h>
#include<Usuario.h>
#include<Administrador.h>


using namespace std;


int main()
{
    int opcion=0,opcion1=0;
    string clave="",fecha="";
    Registro registro;
    Administrador admin;
    Usuario usuario;
    cout<<"------------------------------Bienvenido!------------------------------"<<endl;
    cout<<"Porfavor ingrese la fecha de hoy (day/month/year): ";cin>>fecha; cout<<endl;
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
                while(opcion!=5){
                       if(opcion==1){   //Agregar pelicula.
                           admin.Agregarpelicula();
                           admin.imprimirCartelera();
                       }if(opcion==2){ //Agregar estreno.
                           admin.Agregarestrenos();
                           admin.imprimirestreno();
                       }if(opcion==3){          //Ver reportes
                           admin.MostrarReporte();
                       }if(opcion==4){      //Eliminar estreno.
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
                   cin>>opcion;
                   if(opcion==1){       // Inciar sesion.
                       string id="",clave="",reporte="";
                       cout<<endl<<"Ingrese su ID: "; cin>>id;
                       cout<<"Ingrese su clave de 4 digitos: "; cin>>clave; cout<<endl;
                       if(registro.Usuario(id,clave)==true){        //Inicio de sesión
                           int sala=0,preci=0,cont=1,columna=0,billetes,compra=1;
                           char fila;
                           usuario.Bienvenido();
                           while(compra!=0){
                               admin.imprimirCartelera();admin.imprimirestreno();
                               cout<<endl<<"Porfavor ingrese la sala en la que se esta dando la pelicula que desea ver: "<<endl; cin>>sala;
                               admin.MostrarPrecios();
                               preci=admin.PreciosPelicula(sala);
                               cout<<endl<<"El asiento para la pelicula que desea ver tiene un valor de:"<<preci<<". Desea continuar? "<<"1.Si  0.No"<<endl;
                               cin>>cont;
                               if(cont==1){
                                   reporte="Usuario:"+id+",sala:"+to_string(sala)+", cancelo: "+to_string(preci);
                                   admin.Reportediario(fecha,reporte);
                                   admin.imprimirSala(sala);
                                   cout<<endl<<"Porfavor ingrese la letra de la fila en mayuscula: "; cin>>fila;
                                   cout<<"Ingrese el numero de la columna:"; cin>>columna; cout<<endl<<endl;
                                   while(usuario.Silladisponible(sala,fila,columna)==false){    //Silla no disponible.
                                       cout<<"La silla no está disponible.Ingrese otra:"<<endl;
                                       cout<<endl<<"Porfavor ingrese la letra de la fila en mayuscula: "; cin>>fila;
                                       cout<<"Ingrese el numero de la columna:"; cin>>columna; cout<<endl<<endl;
                                   }
                                   cout<<"Desea cancelar en efectivo o tarjeta? 1.Tajeta,2.Efectivo"<<endl;cin>>cont;
                                   if(cont==2){
                                        cout<<"Cantidad de dinero en billetes: "; cin>>billetes;
                                        usuario.Pago(billetes,preci);
                                   } usuario.Actualizarcartelera(sala);
                                   usuario.Actualizardisponibilidad(sala,fila,columna);
                                   cout<<"Desea hacer otra compra? 1.Si,0.No"<<endl; cin>>compra;
                               }
                         }
                       }else{ cout<<"Usuario no encontrado. "<<endl;}
                   }else{               //Registrar usuario.
                       string id="",clave="",nombre="";
                       cout<<"Porfavor ingrese su ID: "; cin>>id; cout<<endl;
                       cout<<"Ingrese su nombre: "; cin>>nombre; cout<<endl;
                       cout<<"Ingrese una clave de 4 digitos: ";cin>>clave; cout<<endl;
                       registro.RegistroUsuario(id,nombre,clave);
                       cout<<"Para validar su cuenta inicie sesion como usuario. "<<endl;
                   }
        }if(opcion1==3){
            cout<<endl<<"---------------------Gracias y vuelva pronto!-----------------------"<<endl;
            //Se inicializa todo en cero para nuevo dia.
            string linea1="1/",linea2="2/",linea3="3/",linea4="4/",linea5="5/";
            ofstream final("C:/Users/WIN10 PRO/Documents/Parcial1/temp.txt");       //Copia para modificar disponibilidad
            final<<linea1<<endl<<linea2<<endl<<linea3<<endl<<linea4<<endl<<linea5<<endl;
            usuario.llenararchivo("C:/Users/WIN10 PRO/Documents/Parcial1/temp.txt","C:/Users/WIN10 PRO/Documents/Parcial1/Disponibilidad.txt");
            final.close();
        }
    }
}


