#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

void Mostrar(char Nombres[100]);
int Longitud(char Nombres[100]);

main(){
    char Nombres[100];
    int largo;

    cout << "Ingresar nombres separados por comas.\nIngreso: ";
    cin >> Nombres;
    _flushall();
    Mostrar(Nombres);
    largo=Longitud(Nombres);

    cout << "El largo total de la cadena ingresada es: " << largo << endl;

    system("PAUSE");
}

void Mostrar(char Nombres[100]){
    for(int i=0; i<100 && Nombres[i]!='\0'; i++){
        if(Nombres[i]!=','){
            cout << Nombres[i];      
        } else {
            cout << endl;
        }
    }
    cout << endl;
}

int Longitud(char Nombres[100]){
    int c=0;
    while(Nombres[c]!='\0'){
        c++;
    }

    return c;
}