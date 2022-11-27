#include <stdlib.h>
#include <ctime>
#include <iostream>
using namespace std;

void cargarArr(int array[10][10][10], int m, int n, int p);
void cargarVect(int vector[10],int array[10][10][10], int m, int n, int p);
void mostrarArr(int array[10][10][10], int m, int n, int p);
void mostrarVect(int vector[10], int p);

main(){
    int vector[10], array[10][10][10], m, n, p;

    cout << "Ingresar la cantidad de filas: ";
    cin >> m;
    cout << "Ingresar la cantidad de columnas: ";
    cin >> n;
    cout << "Ingresar la cantidad de planos: ";
    cin >> p;

    cargarArr(array, m, n, p);
    cargarVect(vector, array, m, n, p);
    mostrarArr(array, m, n, p);
    mostrarVect(vector, p);
}

void cargarArr(int array[10][10][10], int m, int n, int p){
    int opcion;
    do {
        cout << "\n Seleccionar una opcion: \n1. Carga manual.\n2. Carga automatica.\nRespuesta: ";
        cin >> opcion;
        cout << endl;

        if(opcion!=1 && opcion!=2){
            cout << "\nLa opcion no existe.\n";
        }
    }while(opcion!=1 && opcion!=2);

    switch (opcion)
    {
    case 1:
        for(int i=0;i<p;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<n;k++){
                    cout << "P: " << i << ", M: " << j << ", N: " << k << "\nIngresar valor: ";
                    cin >> array[j][k][i];
                }
            }
        }
        break;
    case 2:
        srand(time(NULL));
        for(int i=0;i<p;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<n;k++){
                    array[j][k][i]=10+rand()%90;
                }
            }
        }
        break;    
    default:
        break;
    }
}

void cargarVect(int vector[10],int array[10][10][10], int m, int n, int p){
    int suma=0;
    
    for(int i=0; i<p; i++){
        for(int k=0; k<m; k++){
            for(int j=0; j<n; j++){
                suma+=array[k][j][i];
            }
        }
        vector[i]=suma;
        suma=0;
    }
}

void mostrarArr(int array[10][10][10], int m, int n, int p){
    for(int i=0; i<p; i++){
        cout << "Plano: " << i+1 << endl;
        for(int k=0; k<m; k++){
            for(int j=0; j<n; j++){
                cout << "[" << array[k][j][i] << "] ";
            }
            cout << endl;
        }
        cout << endl;
    }

}

void mostrarVect(int vector[10], int p){
    cout << "Vector: ";
    for(int i=0; i<p; i++){
        cout << "[" << vector[i] << "] ";
    }
    cout << endl;
}