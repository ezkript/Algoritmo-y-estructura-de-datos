#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

main(){
    typedef char cadena30[30];
    cadena30 cadena[100];
    int c=-1, largo=0, index;
    do{
        
        c++;
        _flushall();
        cout << "Ingresar una palabra: ";
        cin >> cadena[c];
        if(strlen(cadena[c])>largo){
            largo=strlen(cadena[c]);
            index=c;
        }
        
    }while(strcmp(cadena[c], "final")!=0);

    cout << endl << "La palabra mas larga ingresada es: " << cadena[index] << "(" << largo << " caracteres)" << endl;
    cout << "Se ingresaron un total de " << c << " palabras." << endl;
    system("PAUSE");
}