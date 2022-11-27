#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

void cargarArr(int Array[10][10][10], int m, int n, int p);
void cargarVect(int Vector[10], int Array[10][10][10], int m, int n, int p);
void mostrar(int Array[10][10][10], int m, int n, int p);
float Promedio(int Vector[10], int p);

main(){
    int m, n, p, Array[10][10][10];
    int Vector[10];
    float resultado;

    cout << "Ingresar cantidad de filas: ";
    cin >> m;
    cout << "Ingresar cantidad de columnas: ";
    cin >> n;
    cout << "Ingresar cantidad de planos: ";
    cin >> p;

    cargarArr(Array, m, n, p);
    cargarVect(Vector, Array, m, n, p);
    mostrar(Array,m,n,p);
    resultado=Promedio(Vector, p);

    cout << "\nEl promedio del vector es: " << resultado << endl;

    system("PAUSE");
}

void cargarArr(int Array[10][10][10], int m, int n, int p){
    int opcion;
    do {
        cout << "\n Seleccionar una opcion: \n1. Carga manual.\n2. Carga automatica.\nRespuesta: ";
        cin >> opcion;

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
                    cin >> Array[j][k][i];
                }
            }
        }
        break;
    case 2:
        srand(time(NULL));
        for(int i=0;i<p;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<n;k++){
                    Array[j][k][i]=10+rand()%90;
                }
            }
        }
        break;    
    default:
        break;
    }
}

void cargarVect(int Vector[10], int Array[10][10][10], int m, int n, int p){
    int sumatoria=0;
    for(int i=0;i<p;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                sumatoria+=Array[j][k][i];
            }
        }
        Vector[i]=sumatoria;
        sumatoria=0;
    }
}

void mostrar(int Array[10][10][10], int m, int n, int p){
    for(int i=0;i<p;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                cout << "[" << Array[j][k][i] << "] ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

float Promedio(int Vector[10], int p){
    int suma=0;
    float resultado=0.0;

    for(int i=0; i<p; i++){
        suma+=Vector[i];
    }
    resultado=(float)suma/p;

    return resultado;
}