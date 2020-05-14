#include<Administrador.h>
#include<Usuario.h>


Administrador admin;
Usuario usu;
//Inicializa disponibilidad de salas según archivo
map<int,map<string,vector<int>>> Administrador::inicializacion(){
     map<int,map<string,vector<int>>> salas;
    char linea[400],filaux;
    string sala="",disponible="",fila="",str="",filaaux="";
    ifstream archivo;
    int pos=0;
    vector<int> aux1;   //Filas
    map<string,vector<int>> aux;    //Fila y ocupados
    archivo.open("C:/Users/WIN10 PRO/Documents/Parcial1/Disponibilidad.txt");
    if(!archivo.is_open()){
        cout<<"Error al abrir archivo."<<endl;
        exit(1);
    }
    for(int i=0;i<5;i++){       //Inicializa mapa global
        for(int k=0;k<5;k++){
            filaux=admin.filas[k];
            for(int j=0;j<14;j++){      //Inicializa mapa en cero.
                aux1.push_back(0);          //Todos están desocupados(0).
            }filaaux=filaux; aux[filaaux]=aux1;
            salas[i+1]=aux;    //Actualiza mapa global.
            aux1.clear();
       }
    }while(!archivo.eof()){
        archivo.getline(linea,sizeof (linea));
        sala=admin.BuscarDisponible(linea,1);
        disponible=admin.BuscarDisponible(linea,2);
            for(int i=0;i<5;i++){       //Busca cada sala y reserva las sillas ocupadas
                filaux=admin.filas[i];
                if(disponible.length()>1){         //Tiene sillas ocupadas.
                    aux=salas[stoi(sala)];          //Obtiene mapa de cada sala para actualizar.
                    aux1=aux[filaaux];
                    for(int j=0;j<disponible.length();j++){     //Hay sillas reservadas.
                        if(disponible[j]==filaux){      //Se analiza cada fila.
                            pos=j;
                            while(disponible[pos+1]!=','){      //Silla reservada en la fila que se analiza
                                str+=disponible[pos+1];
                                pos+=1;
                            }if(stoi(str)>13){
                                cout<<"Solo existen 14 sillas."<<endl;
                            }else{aux1[stoi(str)-1]=1;}  //Si vale 1 está ocupada.
                            str="";
                            filaaux=filaux;     //Conviertea string.
                         }
                    }aux[filaaux]=aux1;     //Guarda el vector respectivo de la fila.
                    aux1.clear();
                    salas[stoi(sala)]=aux; //Actualiza en mapa global
                 }else{ i=5; }
            }
    }archivo.close();
    return salas;
};
int PreciosPelicula(int sala){
    int precio=0;
    char linea[400];
    int compara=0;
    string valor="";
    ifstream archivo;
    archivo.open("C:/Users/WIN10 PRO/Documents/Parcial1/Salas.txt");
    while(!archivo.eof()){
        archivo.getline(linea,sizeof (linea));
        compara=stoi(admin.BuscarDisponible(linea,1));
        if(compara==sala){
            valor=admin.BuscarDisponible(linea,2);
            precio=stoi(valor);
        }
    }
    return precio;
};

//Imprmir Cartelera.
void Administrador::imprimirCartelera(){
    cout<<endl;
    char linea[400];
    string nombre="",genero="",tiempo="",sala="",hora="",disponible="",edad="",linea1="";
    ifstream peliculas("C:/Users/WIN10 PRO/Documents/Parcial1/Peliculas.txt");
    cout<<"                                CARTELERA DISPONIBLE                                                    "<<endl;
    cout<<"| Sala |"<<"  Genero  |"<<"  Tiempo  |"<<"  Hora  |"<<" Disponibilidad |"<<"  Edad |"<<"    Nombre"<<endl;
    cout<<"|--------------------------------------------------------------------------------------------------------------------"<<endl;
    while(!peliculas.eof()){
       peliculas.getline(linea,sizeof(linea));
       linea1=linea;
       if(linea1.length()<1){break;}        //No hay mas peliculas.
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
//Imprimir estrenos
void Administrador::imprimirestreno(){
    cout<<endl<<endl<<endl;
    char linea[400];
    string linea1;
    string nombre="",genero="",tiempo="",sala="",hora="",disponible="",edad="";
    ifstream peliculas("C:/Users/WIN10 PRO/Documents/Parcial1/Estrenos.txt");
    cout<<"                                PROXIMOS ESTRENOS                                                 "<<endl;
    cout<<"| Sala |"<<"  Genero  |"<<"  Fecha Estreno   |"<<" Disponibilidad |"<<"  "<<"    Nombre"<<endl;
    cout<<"|--------------------------------------------------------------------------------------------------------------------"<<endl;
    while(!peliculas.eof()){
       peliculas.getline(linea,sizeof(linea));
        linea1=linea;
        if(linea1.length()<1){      //No hay más estrenos
            break;
        }
       sala=admin.BuscarPelicula(linea,1);
       nombre=admin.BuscarPelicula(linea,2);
       genero=admin.BuscarPelicula(linea,3);
       tiempo=admin.BuscarPelicula(linea,4);
       disponible=admin.BuscarPelicula(linea,5);
       cout<<"|"<<sala<<"    "<<genero <<"  "<<tiempo<<"  "<<disponible<<"   "<< nombre<<endl;
       cout<<"|-------------------------------------------------------------------------------------------------------------------"<<endl;
    }peliculas.close();
};
//Imprimir sala.
void Administrador::imprimirSala(int sala){
    map<int,map<string,vector<int>>> salas;
    map<string,vector<int>> filas;
    vector<int> sillas;
    string fila;
    salas=admin.inicializacion();
    filas=salas[sala];
    cout<<"------------------Sala "<<sala<<"------------------"<<endl;
    cout<<"   1 2 3 4   5 6 7 8 9  10   11 12 13 14|"<<endl;;
    for(int i=0;i<5;i++){
        fila=admin.filas[i];
        sillas=filas[fila];
        cout<<fila<<"| ";
        for(int j=0;j<14;j++){
            if(j==4 || j==10){  //Corredores.
                cout<<"  ";
            }if(j>8){
                if(sillas[j]==0){      //Silla disponible.
                    cout<<" - ";
                }else{
                    cout<<" + ";
                }
            }else{
                if(sillas[j]==0){      //Silla disponible.
                    cout<<"- ";
                }else{
                    cout<<"+ ";
                }
            }

        }cout<<"|"<<endl;
    }
    cout<<"-------------Pantalla--------------------"<<endl;
};


//Mostrar preciso según sala.
void Administrador::MostrarPrecios(){
    cout<<endl; cout<<endl;     //Imprime tabla de precios segun asiento.
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

//Agregar y ver proximos estreno
void Administrador::Agregarestrenos(){
    //Definición de variables.
    char linea[400];
    string nombre="",genero="",edad="",sala="",tiempo="",linea1="";
    ifstream archivo("C:/Users/WIN10 PRO/Documents/Parcial1/Estrenos.txt");      //Abre archivo
    ofstream final("C:/Users/WIN10 PRO/Documents/Parcial1/temp.txt");   //Archivo salida temporal.
    if(!archivo.is_open()){     //Verifica si logró abrir el archivo.
        cout<<"Error al abrir archivo"<<endl;
        exit(1);
    }       //Pide datos del estreno.
    while(!archivo.eof()){
        archivo.getline(linea,sizeof (linea));
        linea1=linea;
        if(linea1.length()<1){          //No hay mas estrenos.
            cout<<"Ingrese el nombre de la pelicula: ";
            cin>>nombre;
            cout<<endl;
            cout<<"Ingrese la sala en la que se va a proyectar: ";
            cin>>sala;
            cout<<endl;
            cout<<"Ingrese el genero: ";
            cin>>genero;
            cout<<endl;
            cout<<"Ingrese la fecha de estreno:(Dia-mes-anio-hora) ";
            cin>>tiempo;
            cout<<endl;
            cout<<"Ingrese la edad minima: ";
            cin>>edad;
            cout<<endl;
            final<<sala<<"/"<<nombre<<"/"<<genero<<"/"<<tiempo<<"/"<<"70-70"<<"/"<<edad<<"+"<<endl;       //Se agregan a la base de datos
            break;
        }else{
            final<<linea<<endl;
        }
    }
        archivo.close(); final.close();       //Cierr el archivo.
        //Cambia el archivo temporal por el nuevo
        usu.llenararchivo("C:/Users/WIN10 PRO/Documents/Parcial1/temp.txt","C:/Users/WIN10 PRO/Documents/Parcial1/Estrenos.txt");

};

//Las peliculas se definen por disponibilidad de sala, por ende lo que hace es modificarse si ya esta ocupada
void Administrador::Agregarpelicula(){
    int sala;
    cout<<"Ingrese la sala donde se proyectara la pelicula: ";cin>>sala; cout<<endl;
    ifstream archivo("C:/Users/WIN10 PRO/Documents/Parcial1/Peliculas.txt");
    ofstream final("C:/Users/WIN10 PRO/Documents/Parcial1/temp.txt");
    string cambio="",compara="",nombre,genero,disponible="70-70",linea1;
    int tiempo=0,hora=0,edad=0;
    char linea[400];
    while(!archivo.eof()){
        archivo.getline(linea,sizeof (linea));
        compara=admin.BuscarPelicula(linea,1);  //Retorna el normbre de pelicula en la linea
        linea1=linea;
        if(linea1.length()<1){break;}
        linea1=to_string(sala)+"/";
        if(stoi(compara)==sala){        //Es la pelicula a actualizar.
            cout<<"Ingrese el nombre de la pelicula: "<<endl;
            cin.ignore(100, '\n');
            getline(cin,nombre);
            linea1+=nombre+"/";
            cout<<"Genero de la pelicula: "<<endl;
            cin>>genero;
            linea1+=genero+"/";
            cout<<"Duracion de la pelicula en minutos: "<<endl;
            cin>>tiempo;
            linea1+=to_string(tiempo)+" min/";
            cout<<"Hora a la que se dara la pelicula(24h): "<<endl;
            cin>>hora;
            linea1+=to_string(hora)+"/"+disponible+"/";
            cout<<"Ingrese la edad minima: "<<endl;
            cin>>edad;
            linea1+=to_string(edad)+"+";
            final<<linea1<<endl;
        }else{
            final<<linea<<endl;
        }
    }archivo.close();final.close();
    usu.llenararchivo("C:/Users/WIN10 PRO/Documents/Parcial1/temp.txt","C:/Users/WIN10 PRO/Documents/Parcial1/Peliculas.txt");
};

void Administrador::EliminarE(string nombre){
    ifstream archivo("C:/Users/WIN10 PRO/Documents/Parcial1/Estrenos.txt");
    ofstream final("C:/Users/WIN10 PRO/Documents/Parcial1/temp.txt");
    char linea[400];
    string compara="",linea1="";
    while(!archivo.eof()){
        archivo.getline(linea,sizeof(linea)); linea1=linea;
        if( linea1.length() <1){break;}         //No hay mas estrenos.
        compara=admin.BuscarPelicula(linea,2);
        if(compara!=nombre){         //No pasa la linea de la pelicula que se quiere eliminar.
            final<<linea<<endl;
        }
    }archivo.close();final.close();
    usu.llenararchivo("C:/Users/WIN10 PRO/Documents/Parcial1/temp.txt","C:/Users/WIN10 PRO/Documents/Parcial1/Estrenos.txt");
};

//Reporte diario
void Administrador::Reportediario(string dia,string datos){
    ofstream salida("C:/Users/WIN10 PRO/Documents/Parcial1/Reporte.txt",std::fstream::app); //Lo abre como salid ay agrega al final.
    salida<<"Reporte: "<<"dia: "<<dia<<"->"<<datos<<endl;
    salida.close();
};
void Administrador::MostrarReporte(){
    char linea[400];
    ifstream archivo("C:/Users/WIN10 PRO/Documents/Parcial1/Reporte.txt");
    string linea1="";
    int cont=0;
    if(!archivo.is_open()){
        cout<<"Eror al abrir el archivo."<<endl;
        exit(1);
    }
    while(!archivo.eof()){
        cont+=1;
        archivo.getline(linea,sizeof (linea)); linea1=linea;
        if(linea1.length()<1 && cont<1){            //En la primera linea.
           cout<< "No hay reportes."<<endl;
           break;
        }else{
           if(linea1.length()<1){break;}      //Ya no hay más reportes.
            cout<<linea<<endl;
        }
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

//Preciso segun sala
int Administrador::PreciosPelicula(int sala){
    ifstream archivo("C:/Users/WIN10 PRO/Documents/Parcial1/Salas.txt");
    string compara="";
    int precio=0;
    char linea[400];
    while(!archivo.eof()){
        archivo.getline(linea, sizeof(linea));
        compara=admin.BuscarDisponible(linea,1);        //Retorna la sala de la linea
        if(stoi(compara)==sala){
            precio=stoi(admin.BuscarDisponible(linea,2));
            break;
        }
    }archivo.close();
    return precio;
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
    }s2=linea.substr(pos,cant);
    if(romper==1){return s1;}
    if(romper>1){return s2;}
};


