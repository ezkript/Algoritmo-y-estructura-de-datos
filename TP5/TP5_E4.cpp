#include <stdlib.h>
#include <iostream>
#include <ctime>
using namespace std;

void cargarM(int matrizA[100][100], int m, int n);
void getB(int matrizA[100][100], int matrizB[100][100], int m, int n);
void mostrar(int matrizA[100][100], int matrizB[100][100], int m, int n);
void incrementar(int matrizA[100][100], int m, int n, int add);

main(){
    int matrizA[100][100], matrizB[100][100], m, n, add;

    do {
        cout << "Ingresar la cantidad de filas: ";
        cin >> m;
        cout << "Ingresar la cantidad de columnas. Debe ser distinta a la cantidad de filas: ";
        cin >> n;
        if (m==n){
            cout << "\nLa cantidad de filas y columnas son iguales.\n";
        }
    } while (m==n);

    cargarM(matrizA, m, n);
    getB(matrizA, matrizB, m, n);
    mostrar(matrizA, matrizB, m, n);

    cout << "\nIncrementar la matriz A en: ";
    cin >> add;

    incrementar(matrizA, m, n, add);
    mostrar(matrizA, matrizB, m, n);

    system("PAUSE");
}

void cargarM(int matrizA[100][100], int m, int n){
    srand(time(NULL));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            matrizA[i][j]=10+rand()%90;
        }
    }
}

void getB(int matrizA[100][100], int matrizB[100][100], int m, int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            matrizB[j][i]=matrizA[i][j];
        }
    }
}

void mostrar(int matrizA[100][100], int matrizB[100][100], int m, int n){
    cout << "\nMatriz A: " << endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << "[" << matrizA[i][j] << "] ";
        }
        cout << endl;
    }

    cout << "\nMatriz B (Traspuesta): " << endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << "[" << matrizB[i][j] << "] ";
        }
        cout << endl;
    }

    cout << endl;
}

void incrementar(int matrizA[100][100], int m, int n, int add){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            matrizA[i][j]+=add;
        }
    }
}
