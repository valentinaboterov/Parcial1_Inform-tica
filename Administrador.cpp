#include<Administrador.h>
#include<map>
#include<vector>
#include<string>
#include<stdlib.h>
#include <bits/stdc++.h>

Administrador admin;
//Inicializa disponibilidad de salas según archivo
void Administrador::inicializacion(){
    char linea[400],salaux;
    string sala="",disponible="",fila="",str="",salaaux="";
    ifstream archivo;
    int auxi=0;
    vector<int> aux1;   //Filas
    map<string,vector<int>> aux;    //Fila y ocupados
    archivo.open("C:/Users/WIN10 PRO/Documents/Parcial1/Disponibilidad.txt");
    if(!archivo.is_open()){
        cout<<"Error al abrir archivo."<<endl;
        exit(1);
    }while(!archivo.eof()){
        archivo.getline(linea,sizeof (linea));
        sala=admin.BuscarDisponible(linea,1);
        disponible=admin.BuscarDisponible(linea,2);
        for(int i=0;i<5;i++){       //Busca cada sala y reserva las sillas ocupadas
            salaux=admin.filas[i];
            for(int j=0;j<disponible.length();i++){
                if(disponible[i]==salaux){      //Busca cada fila en cada sala.
                    int pos=i;
                    while(disponible[i+1]!=','){
                        str+=disponible[pos+1];
                        pos+=1;
                    }
                    aux1[stoi(str)]=1;  //Si vale 1 está ocupada.
                }
                salaaux=salaux;
            }aux[salaaux]=aux1;     //Guarda el vector respectivo de la fila.
        }admin.salas[stoi(sala)]=aux; //Actualiza en mapa global
    }
};


//Imprmir Cartelera.
void Administrador::imprimirCartelera(){
    cout<<endl;
    char linea[400];
    string nombre="",genero="",tiempo="",sala="",hora="",disponible="",edad="";
    ifstream peliculas("C:/Users/WIN10 PRO/Documents/Parcial1/Peliculas.txt");
    cout<<"                                CARTELERA DISPONIBLE                                                    "<<endl;
    cout<<"| Sala |"<<"  Genero  |"<<"  Tiempo  |"<<"  Hora  |"<<" Disponibilidad |"<<"  Edad |"<<"    Nombre"<<endl;
    cout<<"|--------------------------------------------------------------------------------------------------------------------"<<endl;
    while(!peliculas.eof()){
       peliculas.getline(linea,sizeof(linea));
       sala=admin.BuscarPelicula(linea,1);
       nombre=admin.BuscarPelicula(linea,2);
       genero=admin.BuscarPelicula(linea,3);
       tiempo=admin.BuscarPelicula(linea,4);
       hora=admin.BuscarPelicula(linea,5);
       disponible=admin.BuscarPelicula(linea,6);
       edad=admin.BuscarPelicula(linea,7);
       cout<<"|"<<sala<<"    "<<genero <<"  "<<tiempo<<" "<<hora<<"  "<<disponible<<"  "<<edad<<"  "<< nombre<<endl;
       cout<<"|-------------------------------------------------------------------------------------------------------------------"<<endl;
    }peliculas.close();
}

//Imprimir sala.
void Administrador::imprimirSala(int sala){
    map<string,vector<int>> filas;
    vector<int> sillas;
    string fila;
    filas=admin.salas[sala];
    cout<<"---- Sala: "<<sala<<"----"<<endl;
    cout<<" 1 2 3 4  5 6 7 8 9 10  11 12 13 14"<<endl;;
    for(int i=0;i<5;i++){
        fila=admin.filas[i];
        sillas=filas[fila];
        cout<<fila<<"| ";
        for(int j=0;j<17;j++){
            if(j==4 || j==11){  //Corredores.
                cout<<" ";
            }if(j>9){
                if(sillas[j]==0){      //Silla disponible.
                    cout<<" - ";
                }else{
                    cout<<" x ";
                }
            }else{
                if(sillas[j]==0){      //Silla disponible.
                    cout<<"- ";
                }else{
                    cout<<"x ";
                }
            }

        }cout<<endl;
    }
};


//Mostrar preciso según sala.
void Administrador::MostrarPrecios(){
    cout<<endl; cout<<endl;
        cout<<"   Tarifas segun tipo de  asientos   "<<endl;
        cout<<"  | Sala |  Clasificacion | Costo |"<<endl;
        cout<<"   ------ --------------- -------"<<endl;
        cout<<"  |  1   |   General 2D   | 7900  |"<<endl;
        cout<<"   ------ --------------- -------"<<endl;
        cout<<"  |  2   |   General 2D   | 7900  |"<<endl;
        cout<<"   ------ --------------- -------"<<endl;
        cout<<"  |  3   |   General 3D   |10800  |"<<endl;
        cout<<"   ------ --------------- -------"<<endl;
        cout<<"  |  4   |   General 3D   |10800  |"<<endl;
        cout<<"   ------ --------------- -------"<<endl;
        cout<<"  |  5   | Vibro Sound 3D |11900  |"<<endl;
};
//Agregar película
void Administrador::Agregarpelicula(){
    cout<<"Ingrese el numero de la sala en la que se proyectará la película, teniendo en cuenta que:"<<endl;
    int sala=0;
    string nombre="",genero="",tiempo="",hora="",dispo="",edad="";
    cout<<"Sala 1: 2D"<<endl<<"Sala 2: 2D"<<endl<<"Sala 3: 3D"<<endl<<"Sala 4: 3D"<<endl<<"Sala 5: VibroSound 3D"<<endl;
    cin>>sala;
    cout<<"Ingrese el nombre de la pelicula: ";cin>>nombre; cout<<endl;
    cout<<"Ingrese el género: "; cin>>genero; cout<<endl;
    cout<<"Ingrese la duración en minutos: "; cin>>tiempo; cout<<endl;
    cout<<"Ingrese el horario incluyendo(pm o am): ";cin>>hora; cout<<endl;
    cout<<"Ingrese la siponibilidad de los 70 asientos:";cin>>dispo;cout<<endl;
    cout<<"Ingrese la edad mínima: "; cin>>edad; cout<<endl;
    ofstream salida;
    salida.open("C:/Users/WIN10 PRO/Documents/Parcial1/Peliculas.txt");
    if(!salida.is_open()){
        cout<<"Error al abrir archivo."<<endl;
        exit(1);
    }
    salida<<sala<<"/"<<nombre<<"/"<<genero<<"/"<<tiempo<<" mi"<<"/"<<hora<<"/"<<dispo<<"-70/"<<edad<<"+"<<endl;
    salida.close();
};
//Reporte diario
void Administrador::Reportediario(int dia,string datos){
    ofstream salida("C:/Users/WIN10 PRO/Documents/Parcial1/Reporte.txt");
    salida<<"Reporte: "<<dia<<endl<<datos<<endl;
};
void Administrador::MostrarReporte(){
    char linea[400];
    ifstream archivo;
    archivo.open("C:/User/WIN10 PRO/Documents/Parcial1/Reporte.txt");
    while(!archivo.is_open()){
        archivo.getline(linea,sizeof (linea));
        cout<<linea<<endl;
    }
    archivo.close();
};

//Funciones para Buscar en archivos
string Administrador::Buscar(string linea,int romper){
    //Inicializacion de variables.
    //cant:Cantidad e elementos para el subplot,cont:acceder a diferentes valores, pos:Saber donde inicia cada valor.
    int lon=linea.length(),cont=0,cant=0,pos=0;
    string s1="",s2="",s3="";
    for(int i=0;i<lon;i++){
        cant+=1;
        if(linea[i]=='/'){   //Busca la separación de datos en la base.
            cont+=1;
            if(cont==1){ //Precio.
                s1=linea.substr(0,cant-1);
                pos=i+1;        //incremeta la posicion 1 unidad para empezar la clave.
                cant=0;
            }if(cont==2){   //Sala
                s2=linea.substr(pos,cant-1);
                pos=i+1;  //incremeta la posicion 1 unidad para empezar el saldo.
                cant=0;
            }
        }
    }
    if(romper==1){return s1;}
    if(romper>1){return s2;}
};

string Administrador::BuscarPelicula(string linea,int romper){
    //Inicializacion de variables.
    //cant:Cantidad e elementos para el subplot,cont:acceder a diferentes valores, pos:Saber donde inicia cada valor.
    int lon=linea.length(),cont=0,cant=0,pos=0;
    string s1="",s2="",s3="",s4="",s5="",s6="",s7="",s8="";
    for(int i=0;i<lon;i++){
        cant+=1;
        if(linea[i]=='/'){   //Busca la separación de datos en la base.
            cont+=1;
            if(cont==1){ //Hasta este valor de i esta el usuario.
                s1=linea.substr(0,cant-1);  //usario.
                pos=i+1;        //incremeta la posicion 1 unidad para empezar la clave.
                cant=0;
            }if(cont==2){
                s2=linea.substr(pos,cant-1);
                pos=i+1;  //incremeta la posicion 1 unidad para empezar el saldo.
                cant=0;
            }if(cont==3){
                s3=linea.substr(pos,cant-1);
                pos=i+1;  //incremeta la posicion 1 unidad para empezar el saldo.
                cant=0;
            }if(cont==4){
                s4=linea.substr(pos,cant-1);
                pos=i+1;  //incremeta la posicion 1 unidad para empezar el saldo.
                cant=0;
            }if(cont==5){
                s5=linea.substr(pos,cant-1);
                pos=i+1;  //incremeta la posicion 1 unidad para empezar el saldo.
                cant=0;
            }if(cont==6){
                s6=linea.substr(pos,cant-1);
                pos=i+1;  //incremeta la posicion 1 unidad para empezar el saldo.
                cant=0;
            }
        }
    }
    s7=linea.substr(pos,3);
    if(romper==1){return s1;}   //Sala
    if(romper==2){return s2;}   //Nombre
    if(romper==3){return s3;}   //Genero
    if(romper==4){return s4;}   //Tiempo
    if(romper==5){return s5;}   //Hora
    if(romper==6){return s6;}   //Disponibilidad
    if(romper>6){return s7;}    //Años
};
string Administrador::BuscarDisponible(string linea, int romper){
    //Inicializacion de variables.
    //cant:Cantidad e elementos para el subplot,cont:acceder a diferentes valores, pos:Saber donde inicia cada valor.
    int lon=linea.length(),cont=0,cant=0,pos=0;
    string s1="",s2="";
    for(int i=0;i<lon;i++){
        cant+=1;
        if(linea[i]=='/'){   //Busca la separación de datos en la base.
            cont+=1;
            if(cont==1){ //Precio.
                s1=linea.substr(0,cant-1);
                pos=i+1;        //incremeta la posicion 1 unidad para empezar la clave.
                cant=0;
            }
        }
    }s2=linea.substr(pos,cant-1);
    if(romper==1){return s1;}
    if(romper>1){return s2;}
};


