#include <stdlib.h>
#include <iostream>
#include <ctime>
using namespace std;

void cargarM(int matriz[100][3], int n);
void mostrarM(int matriz[100][3], int n);
int calcular(int matriz[100][3], int n, int& mayor);

main(){
    int n, matriz[100][3], mayorT, mayor=0;
    cout << "Ingresar la cantidad de talleres: ";
    cin >> n;

    cargarM(matriz,n);
    mostrarM(matriz, n);
    mayorT=calcular(matriz, n, mayor);

    cout << "\n\nEl taller con mayor produccion fue el numero " << mayorT+1 << " con un total de " << mayor << " prendas producidas. \n" << endl;
    system("PAUSE");
}

void cargarM(int matriz[100][3], int n){
    srand(time(NULL));
    for(int i=0; i<n;i++){
        for(int j=0; j<3;j++){
            matriz[i][j]=10+rand()%41;
        }
    }
}

void mostrarM(int matriz[100][3], int n){
    cout << "\n          Pantalones | Camisas | Remeras\n";
    for(int i=0; i<n;i++){
        cout << "Taller " << i+1 << "  ";
        for(int j=0; j<3;j++){
            cout << "[" << matriz[i][j] << "]         ";
        }
        cout << endl;
    }
}

int calcular(int matriz[100][3], int n, int& mayor){
    int mayorT=0, aux=0;
    for(int i=0; i<n;i++){
        for(int j=0; j<3;j++){ 
            aux+=matriz[i][j];
        }
        if(mayor<aux){
            mayor=aux;
            mayorT=i;
        }
        aux=0;
        
    }
    return mayorT;
}