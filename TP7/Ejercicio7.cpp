#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

struct fecha {
    int day;
    int month;
    int year;
};

struct datos {
    char apNom[60];
    char domicilio[60];
    fecha ingreso;
    fecha proceso;
    int antiguedad;
};

float promedio(int antigTotal, int i);
void mostrarAntig(datos empleados[100], int i, char busqueda[60]);

int main(){
    char eleccion[10], busqueda[60];
    int opcion, flag=0, antigTotal=0, i;
    datos empleados[100];

    do{
        cout << "------------------------------------" << endl
        << "1. Ingresar datos" << endl
        << "2. Mostrar antiguedad" << endl
        << "3. Listar empleados" << endl 
        << "4. Salir" << endl 
        << "------------------------------------" << endl
        << "Respuesta: "; cin >> opcion;

        system("CLS");

        switch (opcion){
        case 1:
            strcpy(eleccion, "y");
            for(i=0;i<20 && strcmp(strlwr(eleccion), "y")==0; i++){
                    
                if(i<20){
                    cout << "Empleado #" << i+1 << endl
                    << "Nombre: ";fflush(stdin); cin.getline(empleados[i].apNom,60,'\n');
                    cout << "Direccion: ";fflush(stdin); cin.getline(empleados[i].domicilio,60,'\n');
                    cout << endl << "Fecha de ingreso" << endl 
                    << "Dia: "; cin >> empleados[i].ingreso.day;
                    cout << "Mes: "; cin >> empleados[i].ingreso.month;
                    do {
                        cout << "Anio (Debe ser de 4 digitos): "; cin >> empleados[i].ingreso.year;
                    } while (empleados[i].ingreso.year/1000 < 1 || empleados[i].ingreso.year/1000 >= 10);
                    cout << endl << "Fecha de Proceso" << endl 
                    << "Dia: "; cin >> empleados[i].proceso.day;
                    cout << "Mes: "; cin >> empleados[i].proceso.month;
                    do {
                        cout << "Anio (Debe ser de 4 digitos): "; cin >> empleados[i].proceso.year;
                    } while (empleados[i].proceso.year/1000 < 1 || empleados[i].proceso.year/1000 >= 10);
                    empleados[i].antiguedad=empleados[i].proceso.year - empleados[i].ingreso.year;
                    antigTotal+=empleados[i].antiguedad;
                    cout << endl;
                    cout << "Continuar carga? (si = 'y', no = 'n'): ";fflush(stdin); cin.getline(eleccion,10,'\n');
                    system("CLS");
                } else {
                    cout << endl << "Limite de carga alcanzado.(20/20)" << endl;
                }
            }

            cout << "El promedio de antiguedad de los empleados es: " << promedio(antigTotal, i) << endl << endl;
            flag=1;
            system("PAUSE");
            system("CLS");
            break;
        case 2:
            if (flag==1){
                cout << "Ingresar nombre: ";fflush(stdin); cin.getline(busqueda,60,'\n');
                mostrarAntig(empleados,i,busqueda);
            } else {
                cout << "Los datos aun no fueron cargados." << endl;
            }
            system("PAUSE");
            system("CLS");
            break;
        case 3:
            if(flag==1){
                for(int j=0; j<i; j++){
                    cout << endl << empleados[j].apNom << endl
                    << "--------------------" << endl
                    << "Domicilio: " << empleados[j].domicilio << endl
                    << "Fecha de ingreso: " << empleados[j].ingreso.day << "/" << empleados[j].ingreso.month << "/" << empleados[j].ingreso.year << endl 
                    << "Fecha de proceso: " << empleados[j].proceso.day << "/" << empleados[j].proceso.month << "/" << empleados[j].proceso.year << endl
                    << "Antiguedad: " << empleados[j].antiguedad << " anios." << endl;
                }       
            } else {
                cout << "Los datos aun no fueron cargados." << endl;
            }
            system("PAUSE");
            system("CLS");
            break;
        case 4:
            break;
        default:
            cout << "La opcion no existe" << endl;
            break;
        }
    } while (opcion!=4);
    return 0;
}

float promedio(int antigTotal, int i){
    return (float)antigTotal/i;
}

void mostrarAntig(datos empleados[100], int i, char busqueda[60]){
    int flag=0;
    for(int j=0; j<i; j++){
        if(strcmp(strlwr(empleados[j].apNom), strlwr(busqueda))==0){
            cout << endl << "Empleado - " << empleados[j].apNom << endl
            << "Antiguedad: " << empleados[j].antiguedad << " anios" << endl << endl;
            flag=1;
        } else if (j==i && flag==0){
             cout << endl << "Error: el empleado no existe." << endl;
        }
    }
}