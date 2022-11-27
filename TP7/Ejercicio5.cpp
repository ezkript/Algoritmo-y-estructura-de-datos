#include <stdlib.h>
#include <stdio.h>
#include <string.h> //Usar funciones para manipular strings (strcmp(), strlwr())
#include <windows.h> //Para programar la funcion gotoxy()
#include <iostream>
using namespace std;

//Registro de la fecha de ingreso
struct fecha {
    int day;
    int month;
    int year;
};

//Registro de los datos de los vendedores
struct datosVendedores {
    char apNom[60];
    int nroDoc;
    fecha ingreso;
    float ventaSemanal[5]={0.00,0.00,0.00,0.00,0.00}; //Vector de ventas, inicializado en 0.00 para evitar errores.
};

void gotoxy(int x, int y); //Mueve el cursor para mostrar los datos de forma ordenada 
void Limpiar(); //Limpia la pantalla y pausa la ejecucion
void Error(); //Mensaje de error
void cargarVentas(struct datosVendedores vendedor[100], int n, char nombre[60], int diaVenta, float monto); //Cargar los datos de las ventas
void mostrarVentas(struct datosVendedores vendedor[100], int n); //Mostrar los datos de las ventas
void modificarVenta(struct datosVendedores vendedor[100], int n, int documento, int diaVenta, float monto); //Cambiar algun monto de un empleado

int main(){
    int opcion, bandera, n=6, diaVenta=1, documento;
    char nombre[60];
    float monto, cambiarMonto;
    struct datosVendedores vendedor[100];

    //Pedir y validar la cantidad de empleados
    do {
        if(n<5){
            cout << "Error: debe haber minimo 5 empleados. Reingresar: ";
        } else {
            cout << "Cantidad de empleados (minimo 5): ";
        }
        cin >> n;
    } while(n<5);

    do{
        //Menu principal
        cout << "--------------------------" << endl 
        << "1. Registrar empleados." << endl 
        << "2. Registrar ventas." << endl 
        << "3. Mostrar ventas. " << endl 
        << "4. Modificar datos." << endl 
        << "5. Salir. " << endl 
        << "--------------------------" << endl
        << "Respuesta: ";cin >> opcion;

        system("CLS");

        switch (opcion)
        {
        case 1:
            bandera=1; //Para verificar la carga de datos antes de ingresar a otras opciones del menu
            for(int i=0; i<n; i++){
                cout << "Empleado #" << i+1 << endl;
                fflush(stdin); //Limpiar el buffer de memoria
                cout << "Nombre: ";cin.getline(vendedor[i].apNom, 60, '\n');
                cout << "Documento: ";cin >> vendedor[i].nroDoc;

                cout << endl << "Ingreso" << endl;
                cout << "Dia: ";cin >> vendedor[i].ingreso.day;
                cout << "Mes: ";cin >> vendedor[i].ingreso.month;
                cout << "Anio: ";cin >> vendedor[i].ingreso.year;
                
                Limpiar();
            }
            break;
        case 2:
            if(bandera!=1){
                Error();
            } else {
                fflush(stdin);
                cout << "Nombre: "; cin.getline(nombre, 60, '\n');

                do {

                    //Pedir y validar el dia
                    if(diaVenta>5 || diaVenta<0){
                        cout << endl << "La opcion no existe." << endl;
                    } else {
                        cout << endl << "Dia" << endl
                        << "1. Lunes" << endl
                        << "2. Martes" << endl
                        << "3. Miercoles" << endl
                        << "4. Jueves" << endl
                        << "5. Viernes" << endl;
                    }

                    cout << "Respuesta: "; cin >> diaVenta;

                } while(diaVenta > 5 || diaVenta < 0);
                

                cout << endl << "Monto: "; cin >> monto;

                cargarVentas(vendedor, n, nombre,diaVenta-1, monto);
                Limpiar();
            }
            break;
        case 3:
            if(bandera!=1){
                Error();
            } else {
                mostrarVentas(vendedor, n);
            }
            Limpiar();
            break;
        case 4:
            if(bandera!=1){
                Error();
            } else {
                cout << "Documento del empleado:"; cin >> documento;
                
                diaVenta=1;
                do {
                    if(diaVenta>5 || diaVenta<0){
                        cout << endl << "La opcion no existe." << endl;
                    } else {
                        cout << endl << "Dia" << endl
                        << "1. Lunes" << endl
                        << "2. Martes" << endl
                        << "3. Miercoles" << endl
                        << "4. Jueves" << endl
                        << "5. Viernes" << endl;
                    }

                    cout << "Respuesta: "; cin >> diaVenta;

                } while(diaVenta > 5 || diaVenta < 0);

                cout << "Monto a cambiar: "; cin >> cambiarMonto;

                modificarVenta(vendedor, n, documento,diaVenta-1,cambiarMonto);
            }
            Limpiar();
            break;
        case 5:
            break;
        default:
            cout << "La opcion no existe.";
            Limpiar();
            break;
        }
    } while (opcion!=5);
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

void Error(){
    cout << "Error: los datos no han sido cargados." << endl;
    system("PAUSE");
    system("CLS");
}

void cargarVentas(struct datosVendedores vendedor[100], int n, char nombre[60], int diaVenta, float monto){
    int flag=0; //Bandera para verificar si el usuario fue encontrado o no
    for (int i = 0; i < n && flag==0; i++){
        if(strcmp(strlwr(vendedor[i].apNom), strlwr(nombre))==0){
            vendedor[i].ventaSemanal[diaVenta]=monto;
            cout << endl << "Venta registrada satisfactoriamente." << endl;
            flag=1;
        }
    }
    if(flag!=1){
        cout << endl << "Error: el empleado no fue encontrado." << endl;
    }
}

void mostrarVentas(struct datosVendedores vendedor[100], int n){
    float ventasTotales[100];
    cout << endl << "Documento\tApellido y Nombre\tLunes   Martes   Miercoles   Jueves   Viernes\t Total" << endl
    << "-----------------------------------------------------------------------------------------------" << endl;
    
    //Inicializar los valores en 0.00 para evitar errores
    for(int k=0; k<n; k++){
        ventasTotales[k]=0.00;
    }

    for (int i = 0; i < n; i++){

        //Sumar las ventas semanales de cada empleado
        for(int j=0; j<5; j++){
            ventasTotales[i]+=(float)vendedor[i].ventaSemanal[j];
        }
        gotoxy(0,4+i);printf("%i", vendedor[i].nroDoc);
        gotoxy(16,4+i);printf("%s", vendedor[i].apNom);
        gotoxy(40,4+i);printf("%.2f ", vendedor[i].ventaSemanal[0]);
        gotoxy(48,4+i);printf("%.2f ", vendedor[i].ventaSemanal[1]);
        gotoxy(57,4+i);printf("%.2f ", vendedor[i].ventaSemanal[2]);
        gotoxy(69,4+i);printf("%.2f ", vendedor[i].ventaSemanal[3]);
        gotoxy(78,4+i);printf("%.2f ", vendedor[i].ventaSemanal[4]);
        gotoxy(89,4+i);printf("%.2f", ventasTotales[i]);
        cout << endl;
    }
    cout << endl << "-----------------------------------------------------------------------------------------------" << endl;
}

void modificarVenta(struct datosVendedores vendedor[100], int n, int documento, int diaVenta, float monto){
    int flag=0;
    for(int i=0; i<n; i++){
        if(documento==vendedor[i].nroDoc){
            vendedor[i].ventaSemanal[diaVenta]=monto;
            cout << "Monto actualizado." << endl;
            flag=1;
        }
    }
    if(flag==0){
        cout << "El empleado no fue encontrado." << endl;
    }
}