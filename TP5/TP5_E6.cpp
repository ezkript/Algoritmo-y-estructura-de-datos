#include <stdlib.h>
#include <ctime>
#include <iostream>
using namespace std;

 void cargaArray(float array[10][10][10], int m, int n, int p);
 void muestra(float array[10][10][10], int m, int n, int p);
 float  menor(float array[10][10][10], int m, int n, int p);
 bool esPar(int nro);

int main(){
    int m,n,p;
    float array[10][10][10], menorn;
    bool parONo;
    
    cout << "Ingresar la cantidad de filas: ";
    cin >> m;
    cout << "Ingresar la cantidad de columnas: ";
    cin >> n;
    cout << "Ingresar la cantidad de planos: ";
    cin >> p;
    
    cargaArray(array, m, n, p);
    muestra(array, m, n, p);
    menorn=menor(array, m, n, p);
  
    cout << endl << "El menor numero es: " << menorn << endl;
    
    parONo=esPar(menorn);
    cout << endl << "Tomando SOLO la parte entera" << endl;
    if(parONo==true){
        cout << endl << "Es par" << endl;
    } else {
        cout << endl << "No es par" << endl;
    }
    
    return 0;
 }
 
 void cargaArray(float array[10][10][10], int m, int n, int p){
     srand(time(NULL));
     for(int k=0;k<p;k++){
         for(int i=0;i<m;i++){
             for(int j=0;j<n;j++){
                 array[i][j][k]=(float)(1+rand()%1000)/10;
             }
         }
     }
 }

void muestra(float array[10][10][10], int m, int n, int p){
      cout << endl;
      for(int k=0;k<p;k++){
         for(int i=0;i<m;i++){
             for(int j=0;j<n;j++){
                 cout << "[" << array[i][j][k] << "]";
             }
             cout << endl;
         }
         cout << endl;
     }
}

float menor(float array[10][10][10], int m, int n, int p){
     float menorNro=array[0][0][0];
     for(int k=0;k<p;k++){
         for(int i=0;i<m;i++){
             for(int j=0;j<n;j++){
                 if(array[i][j][k]<menorNro){
                     menorNro=array[i][j][k];
                 }
             }
         }
     }   
     return menorNro;
}

bool esPar(int nro){
    if(nro%2==0){
        return true;
    } else {
        return false;
    }
}
      