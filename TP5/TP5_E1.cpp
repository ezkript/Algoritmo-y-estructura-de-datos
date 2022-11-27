#include <stdlib.h>
#include <iostream>
using namespace std;

void cargar(int Arreglo[4][3]);
int MoM(int Arreglo[4][3], int&menor);
void Mostrar(int Arreglo[4][3]);

main(){
    int Arreglo[4][3], menor, mayor;

    cargar(Arreglo);
    mayor=MoM(Arreglo, menor);

    cout << "\nEl mayor elemento es: " << mayor << endl << "El menor elemento es: " << menor << endl;
    cout << "Matriz:" << endl;

    Mostrar(Arreglo);

    system("PAUSE");
}

void cargar(int Arreglo[4][3]){
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            system("CLS");
            cout << "\nPosicion: " << "(" << i << "," << j << ")" << "\nIngresar un valor: ";
            cin >> Arreglo[i][j];
        }
    }
}

int MoM(int Arreglo[4][3], int&menor){
    int mayor=Arreglo[0][0];
    menor=Arreglo[0][0];
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            if(Arreglo[i][j]>mayor){
                mayor=Arreglo[i][j];
            } else if(Arreglo[i][j]<menor){
                menor=Arreglo[i][j];
            }
        }
    }

    return mayor;
}

void Mostrar(int Arreglo[4][3]){
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            cout << Arreglo[i][j] << " - ";
        }
        cout << endl;
    }
}