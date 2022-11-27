#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

typedef char C30[30];

void cargar(C30 Nombres[10], int inscritos[100], int N);
int masInsc(int inscritos[100], int N);
int cantInsc(int inscritos[100], C30 Nombres[10], int N);

main(){
    
    C30 Nombres[10];
    int inscritos[100], N, mayor,result;

    cout << "Cantidad de asignaturas: ";
    cin >> N;
    cout << endl;

    cargar(Nombres, inscritos, N);
    mayor=masInsc(inscritos, N);
    cout << "La asignatura con el mayor numeros de inscritos es: " << Nombres[mayor] << endl;

    result=cantInsc(inscritos, Nombres, N);
    if(result==-1){
        cout << "La asignatura no se encontro" << endl;
    } else {
        cout << "La asignatura (" << Nombres[result] << ") tiene una cantidad de " << inscritos[result] << " inscritos." << endl;
    }

    system("PAUSE");
}

void cargar(C30 Nombres[10], int inscritos[100], int N){
    for(int i=0; i<N; i++){
        _flushall();
        cout << "Asignatura: ";
        cin >> Nombres[i];
        cout << "Cantidad de inscritos: ";
        cin >> inscritos[i];
        cout << endl;
    }
}

int masInsc(int inscritos[100], int N){
    int mayor=0, index;
    for(int i=0; i<N; i++){
        if(inscritos[i]>mayor){
            mayor=inscritos[i];
            index=i;
        }
    }

    return index;
}

int cantInsc(int inscritos[100], C30 Nombres[10], int N){
    char buscar[30];
    cout << "Mostrar cantidad de inscritos de: ";
    _flushall();
    gets(buscar);
    for(int i=0; i<N; i++){
        if(strcmp(strlwr(Nombres[i]),strlwr(buscar))==0){
            return i;
        }
    }

    return -1;
}