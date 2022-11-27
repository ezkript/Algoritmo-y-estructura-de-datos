#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

void cargarM(int Array[3][4][2]);
int bestSell(int Array[3][4][2]);
void mostrar(int Array[3][4][2]);

int main(){

    int Array[3][4][2], best;

    cargarM(Array);
    mostrar(Array);

    best=bestSell(Array);
    cout << "El pais que mejor vendio fue el numero " << best+1 << "." << endl << endl;

    system("PAUSE");
    return 0;
}

void cargarM(int Array[3][4][2]){
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
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<4;k++){
                    cout << "P: " << i << ", M: " << j << ", N: " << k << "\nIngresar valor: ";
                    cin >> Array[j][k][i];
                }
            }
        }
        break;
    case 2:
        srand(time(NULL));
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<4;k++){
                    Array[j][k][i]=10+rand()%90;
                }
            }
        }
        break;    
    default:
        break;
    }
}

int bestSell(int Array[3][4][2]){
    int aux=0, best=0, bestP=0;
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<4;k++){
                aux+=Array[j][k][i];
            }
        }
        if(aux>best){
            best=aux;
            bestP=i;
        }
        aux=0;
    }
    return bestP;
}

void mostrar(int Array[3][4][2]){
    int suma=0,total=0;

    for(int i=0;i<2;i++){
        cout << endl << "Pais " << i+1 << ")" << endl << "\t\t Productos" << endl;
        for(int j=0;j<3;j++){
            cout << "Sucursal " << j+1 << "  ";
            for(int k=0;k<4;k++){
                cout << "[" << Array[j][k][i] << "] ";
                suma+=Array[j][k][i];
            }
            cout << "= "<< suma << endl;
            total+=suma;
            suma=0;
        }
        cout << "\t\t\t   ----------" << endl << "\t\t\t   Total: " << total << endl;
        total=0;
    }
}