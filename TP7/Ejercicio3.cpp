#include <stdlib.h>
#include <iostream>
using namespace std;

struct fecha{
    int dia;
    int mes;
    int anio;
};

struct datosCliente{
    char ApeNom[40]; //apellido y nombre del cliente
    char dire[60]; //domicilio particular del cliente
    float monVehi; //Monto del vehículo.
    fecha fecVenta; //Fecha de venta del vehículo.
};

int menor(struct datosCliente Cliente[100], int i, int menorPos); //Determinar la fecha con la menor venta.
void mostrar(struct datosCliente Cliente[100], int i); //Mostrar dato registrado.

int main(){
    struct datosCliente Cliente[100];
    int n,menorPos=0;

    cout << "Ingresar la cantidad de clientes: ";
    cin >> n;
    
    for(int i=0; i<n; i++){
        fflush(stdin);
        cout << endl << "Cliente #" << i+1 << endl << "Nombre: ";
        cin.getline(Cliente[i].ApeNom, 40, '\n');
        cout << "Direccion: ";
        cin.getline(Cliente[i].dire, 60, '\n');
        cout << "Monto del vehiculo: ";
        cin >> Cliente[i].monVehi;
        cout << endl << "Fecha de venta" << endl << "Dia: ";
        cin >> Cliente[i].fecVenta.dia;
        cout << "Mes: ";
        cin >> Cliente[i].fecVenta.mes;
        cout << "Anio: ";
        cin >> Cliente[i].fecVenta.anio;

        menorPos=menor(Cliente,i, menorPos);
        mostrar(Cliente, i);
    }

    cout << endl << "La fecha con la menor cantidad de ventas es: " << Cliente[menorPos].fecVenta.dia << "/" << Cliente[menorPos].fecVenta.mes << "/" << Cliente[menorPos].fecVenta.anio << endl; 

    system("PAUSE");
    return 0;
}

int menor(struct datosCliente Cliente[100], int i, int menorPos){
    int menorVentas=Cliente[menorPos].monVehi;
    if(menorVentas>Cliente[i].monVehi){
        menorVentas=Cliente[i].monVehi;
        return i;
    } else {
        return menorPos;
    }
}

void mostrar(struct datosCliente Cliente[100], int i){
    cout << endl << "Cliente registrado: " << endl << "Nombre: " << Cliente[i].ApeNom << " - Direccion: " << Cliente[i].dire << " - Monto del vehiculo: " << Cliente[i].monVehi << " - Fecha de venta: " << Cliente[i].fecVenta.dia << "/" << Cliente[i].fecVenta.mes << "/" << Cliente[i].fecVenta.anio << endl;
}