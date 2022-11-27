#include <stdlib.h>
#include <windows.h>
#include <iostream>
using namespace std;

struct fecha {
    int day;
    int month;
    int year;
};

struct stock {
    int codigo;
    char nombre[50];
    int cantMin;
    fecha ultCompra;
    int existencia;
    float precio;
};

void gotoxy(int x, int y);
void Limpiar();
void Actualizar(stock producto[100], int n, int codigoAct,fecha fechaAct, int cantAct);
void Realizar(stock producto[100], int n, int codigoAct, int cantAct);
void reponer(stock producto[100], int n);

int main(){
    int n=11,
        flag=0,
        opcion,
        codigoAct,
        cantAct;
    stock producto[100];
    fecha fechaAct;
    

    do {
        cout << "-------------------------------" << endl
        << "Elegir opcion:" << endl
        << "1. Ingresar productos." << endl
        << "2. Actualizar producto." << endl
        << "3. Vender producto." << endl
        << "4. Mostrar productos con poco stock." << endl
        << "5. Salir." << endl
        << "-------------------------------" << endl
        << "Respuesta: "; cin >> opcion;

        system("CLS");

        switch (opcion){
        case 1:
            cout << " -------------------------------------------" << endl 
            <<      "|Se debe ingresar un minimo de 10 productos.|" << endl
            <<      " -------------------------------------------" << endl;
            do {
                if(n<10){
                    cout << "Cantidad inferior a la minima. Reingresar: ";
                } else {
                    cout << "Cantidad de productos a ingresar: ";
                }
                cin >> n;
            } while(n<10);
            
            for(int i=0; i<n; i++){
                cout << "Producto #" << i+1 << endl;
                do{
                    cout << "El codigo debe ser de 5 digitos" << endl << "Codigo: "; cin >> producto[i].codigo;
                } while (producto[i].codigo<10000 || producto[i].codigo>99999);
                cout << "Nombre del producto: ";fflush(stdin);cin.getline(producto[i].nombre, 50, '\n');
                cout << "Stocks minimo del producto: "; cin >> producto[i].cantMin;
                cout << endl << "Fecha de ultima compra" << endl
                << "Dia: "; cin >> producto[i].ultCompra.day;
                cout << "Mes: "; cin >> producto[i].ultCompra.month;
                cout << "Anio: "; cin >> producto[i].ultCompra.year;

                cout << "Existencia actual: "; cin >> producto[i].existencia;
                cout << "Precio: "; cin >> producto[i].precio;
                system("CLS");
            }
            flag=1;
            break;
        case 2:
            if(flag==1){
                cout << "Actualizar existencia." << endl
                << "Codigo del producto: "; cin >> codigoAct;
                cout << "Cantidad comprada: "; cin >> cantAct;
                cout << "Fecha de compra" << endl
                << "Dia: "; cin >> fechaAct.day;
                cout << "Mes: "; cin >> fechaAct.month;
                cout << "Anio: "; cin >> fechaAct.year;

                Actualizar(producto, n, codigoAct, fechaAct, cantAct);
            } else {
                cout << "Error: los productos aun no fueron cargados." << endl;
            }
            Limpiar();
            break;
        case 3:
            if(flag==1){
                cout << "Realizar venta" << endl
                << "Codigo del producto: "; cin >> codigoAct;
                cout << "Cantidad: "; cin >> cantAct;
                Realizar(producto, n, codigoAct, cantAct);
            } else {
                cout << "Error: los productos aun no fueron cargados." << endl;
            }
            Limpiar();
            break;
        case 4:
            if(flag==1){
                reponer(producto, n);
            } else {
                cout << "Error: los productos aun no fueron cargados." << endl;
            }
            Limpiar();
            break;
        case 5:
            break;
        default:
            cout << "La opcion no existe" << endl << endl;
            Limpiar();
            break;
        }

    } while(opcion!=5);


    return 0;
}

void gotoxy(int x, int y){
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X=x;
    dwPos.Y=y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void Limpiar(){
    system("PAUSE");
    system("CLS");
}

void Actualizar(stock producto[100], int n, int codigoAct,fecha fechaAct, int cantAct){
    for(int i=0; i<n; i++){
        if(codigoAct==producto[i].codigo){
            producto[i].codigo=codigoAct;
            producto[i].ultCompra.day=fechaAct.day;
            producto[i].ultCompra.month=fechaAct.month;
            producto[i].ultCompra.year=fechaAct.year;
            producto[i].existencia-=cantAct;
        } else if(codigoAct!=producto[i].codigo && i==n){
            cout << endl << "Error: el codigo del producto no esta registrado." << endl;
        }
    }
}

void Realizar(stock producto[100], int n, int codigoAct, int cantAct){
    int flag=0;
    for(int i=0; i<n; i++){
        if(producto[i].codigo==codigoAct){
            if(cantAct>producto[i].existencia){
                flag=1;
            } else {
                flag=i;
            }
        } else {
            flag=3;
        }
    }
    if(flag!=1&&flag!=3){
        gotoxy(5, 5); cout << "| Codigo";
        gotoxy(5, 6); cout << "--------------------------------------------------------------------------------";
        gotoxy(5, 7); cout << "| " << codigoAct;
        gotoxy(14,5); cout << "| Descripcion";
        gotoxy(14,7); cout << "| " << producto[flag].nombre;
        gotoxy(28,5); cout << "| Precio/Unitario";
        gotoxy(28,7); cout << "| $" << producto[flag].precio;
        gotoxy(46,5); cout << "| Cantidad Solicitada";
        gotoxy(46,7); cout << "| " << cantAct;
        gotoxy(68,5); cout << "| Monto a pagar |";
        gotoxy(68,7); cout << "| $" << producto[flag].precio*cantAct << endl << endl;
        
    } else if(flag==1){
        cout << endl << "Error: la existencia actual no es suficiente para satisfacer la compra." << endl;
    } else {
        cout << endl << "Error: el codigo del producto no esta registrado." << endl;
    }
}

void reponer(stock producto[100], int n){
    cout << "Productos que se necesitan reponer" << endl
    << "-----------------------------------" << endl << endl;
    for(int i=0; i<n; i++){
        if(producto[i].existencia<producto[i].cantMin){
            cout << producto[i].nombre << endl;
        }
    }
}