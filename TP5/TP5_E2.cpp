#include <stdlib.h>
#include <iostream>
using namespace std;

void cargarMatriz(int matriz[100][100], int m, int n);
void mostrarM(int matriz[100][100], int m, int n);
void chgElement(int matriz[100][100], int m, int n);
void mostrarFoC(int matriz[100][100], int m, int n);

main(){
    int m, n, matriz[100][100];

    cout << "Ingresar la cantidad de filas: ";
    cin >> m;
    cout << "Ingresar la cantidad de columnas: ";
    cin >> n;

    cargarMatriz(matriz,m,n);
    mostrarM(matriz, m, n);
    chgElement(matriz, m, n);
    mostrarM(matriz, m, n);
    mostrarFoC(matriz, m, n);

    system("PAUSE");
}

void cargarMatriz(int matriz[100][100], int m, int n){
    int value;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            do{
                system("CLS");
                cout << "\nPosicion: " << "(" << i << "," << j << ")" << endl;
                cout << "Ingresar numero: ";
                cin >> value;
            }while(value<0);

            matriz[i][j]=value;
        }
    }
}

void mostrarM(int matriz[100][100], int m, int n){
    cout << "\n\nMatriz: " << endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << "[" << matriz[i][j] << "] ";
        }
        cout << endl;
    }
}

void chgElement(int matriz[100][100], int m, int n){
    int posx, posy;
    do{
       cout << "\nCambiar valor a 0. \n Fila: ";
       cin >> posx;
       if(posx>m || posx<0){
        cout << "La posicion no existe en la matriz. Ingresar nuevamente" << endl;
       }
    }while(posx>m || posx<0);
    do{
        cout << " Columna: ";
        cin >> posy;
        if(posy>n || posy<0){
         cout << "La posicion no existe en la matriz. Ingresar nuevamente" << endl;
        }
    }while(posy>n || posy<0);
    matriz[posx-1][posy-1]=0;
}

void mostrarFoC(int matriz[100][100], int m, int n){
    int opcion, f, c;
    do{
        cout << "\nMostrar fila o columna.\n1. Fila\n2. Columna\nRespuesta: ";
        cin >> opcion;
        if(opcion!=1 && opcion!=2){
            cout << "La opcion elegida no existe.";
        }
    }while(opcion!=1 && opcion!=2);

    switch (opcion)
    {
    case 1:
        cout << "Fila a mostrar: ";
        cin >> f;
        for(int i=0; i<n; i++){
            cout << "["<< matriz[f-1][i] << "] ";
        }
        cout << endl;
        break;
    case 2:
        cout << "Columna a mostrar: ";
        cin >> c;
        for(int i=0; i<m; i++){
            cout << "[" << matriz[i][c-1] << "] ";
            cout << endl;
        }
    default:
        break;
    }
}