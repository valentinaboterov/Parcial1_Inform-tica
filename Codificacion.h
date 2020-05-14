#ifndef CODIFICACION_H
#define CODIFICACION_H
#include<string>

using namespace std;

class codificacion {
   public:
    string convbinario(char ascii);   //Recibe un caracter para obtener su valor binario.
    string convascii(string binario); //Recibe un binario de 8 bits para convertir a caracter por medio del valor ascii
    string Cod2(string binario1,int n);       //Codifica por el método 2,recibe el string a codificar y la semilla.
    string Deco2(string binario,int n);         //Decodifica metodo 2, recibe binario codificado por el metodos 2, y semilla
};
#endif // CODIFICACION_H
