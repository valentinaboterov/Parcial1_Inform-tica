#include<Codificacion.h>
#include <iostream>
#include<math.h>

using namespace std;
codificacion codi;
//Conversiones
string codificacion::convbinario(char ascii){
    //Inicializacion variables:
   std:: string bin="",div="";
    int di=ascii;
    //Para hacer la conversion se divide por 2 y se toma el residuo, hasta que el dividendo sea <2.
    while(di>=2){
        div+=std::to_string(di%2);
        di/=2;
    }div+="1";  //Se le concatena el 1 restante de las divisiones.
    //Cada entero se convierte en 8 bits, los que sean menores se le asignan 0 al inicio.
    while(div.length()<8){
        div+="0";
    }
    //Se guardan los valores de abajo hacia arriba para obtener el inario.
    for(int i=(div.length()-1);i>=0;i--){
        bin+=div[i];
    }
    return bin;
}

string codificacion::convascii(string binario){
    int lon=binario.length(),ascii=0,suma=0;
    int pos=lon-1;  //Recorrer string de atras para adelante.
    string letra="";
    //Se toma el valor 1 o 0 del binario y se multiplica por 2^pos para obtener el valor del caracter en ascii.
    for(int i=0;i<8;i++){
        ascii=(binario[pos])-48;
        pos-=1;
        suma+=ascii*(pow(2,i));
    }
    //Se obtiene el caracter.
    letra=suma;
    return letra;
}
//Codificación por el método 2 de la práctica 2.
string codificacion::Cod2(string binario1,int n){
    string binario="";
    for(int i=0;i<binario1.length();i++){    //Convierte string recibido a binario.
        binario+=codi.convbinario(binario1[i]);
    }
    double elev=1,pot=0;  //Nota inicio.
    if(n==1){
        n=2;
    }
    if(n%2!=0){  //Si es impar toma el par siguiente.
        n=n+1;
    }
    pot=pow((double)n,(1/elev));
    while(pot!=2||n!=2){  //Potencia de 2 mayor más cercana.
        if(pow(2,elev)<n){
            elev+=1;
        }else{
            n=pow(2,elev);
        }pot=pow(double(n),(1/elev));
    }
     int pos=0,n1=n,lon=binario.length();
     string codifi="";
    while(pos<lon){
         //Pone la ultima posicion en la primera.
            codifi+=binario[pos+n1-1];
        for(int i=pos;i<=pos+n1-2;i++){
             //Corre el resto del paquete una unidad a la derecha.
                codifi+=binario[i];
        }
        pos+=n1;
    }
    return codifi;
}
//Decodificación por el método 2 de la práctica 2.
string codificacion::Deco2(string binario,int n){
    //Inicializacion variables.
    string deco="",sub="",final="";
    double elev=1,pot=0;
    if(n==1){
        n=2;
    }
    if(n%2!=0){
        n=n+1;
    }
    pot=pow((double)n,(1/elev));
    while(pot!=2||n!=2){  //Nota inicio
        if(pow(2,elev)<n){
            elev+=1;
        }else{
            n=pow(2,elev);
        }pot=pow(double(n),(1/elev));
    }
    int pos=0,n1=n,lon=binario.length();

    while(pos<lon){
        //Desde el 2 dato del paquete(ya partido en la semilla),lo corre todo una posicion a la izquierda.
        for(int i=pos+1;i<=pos+n1-1;i++){
            deco+=binario[i];
        }
        //El primer dato es el ultimo.
        deco+=binario[pos];
        //Pasa al siguiente paquete.
        pos+=n1;
    }
    int lond=deco.length();
    for(int j=0;j<lond;j+=8){  //Parte el binario codificado en 8 bits para accdecer al ascii.
        sub="";
        sub=deco.substr(j,pos);   //Substring con 8 bits.
        final+=convascii(sub);
    }
    return final;
}

