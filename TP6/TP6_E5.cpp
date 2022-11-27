#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
typedef char c30[30];

void cargar(c30 Nombre[100], c30 Apellido[100], int n);
void Ordenar(c30 Nombre[100], c30 Apellido[100], c30 nombreCompleto[100], int n);
void Mostrar(c30 nombreCompleto[100], int n);
void OrdenAp(c30 Apellidos[100], c30 orden2[100], int n);
void Error();
main(){
    int opcion, n, flag=0, flag2=0;
    c30 Nombre[100], Apellido[100], nombreCompleto[100], orden2[100];
    

    do{
        system("CLS");
        cout << "Seleccionar una opcion:\n1. Ingresar datos.\n2. Ordenar datos de forma decreciente\n3. Mostrar lista.\n4. Mostrar apellidos de forma creciente.\n5. Salir.\nRespuesta: ";
        cin >> opcion;
        cout << endl;
        switch (opcion)
        {
        case 1:
            system("CLS");
            cout << "Ingresar la cantidad de socios: ";
            cin >> n;
            cargar(Nombre, Apellido, n);
            flag=1;

            break;
        case 2:
            if(flag==0){
                Error();
            } else {
                system("CLS");
                Ordenar(Nombre, Apellido, nombreCompleto, n);
                cout << endl << "Ordenado correctamente." << endl;
                system("PAUSE");
                flag2=1;
            }

            break;
        case 3:
            if(flag==0 || flag2==0){
                Error();
            } else {
                system("CLS");
                cout << "La lista ordenada es: " << endl;
                Mostrar(nombreCompleto, n);
            }

            break;
        case 4:
            if(flag==0){
                Error();
            } else {
                system("CLS");
                OrdenAp(Apellido, orden2, n);
            }

            break;
        case 5:
            break;
        default:
            cout << endl << "La opcion elegida no existe." << endl;
            system("PAUSE");
            break;
        }
    } while (opcion!=5);
    
}

void cargar(c30 Nombre[100], c30 Apellido[100], int n){
    
    for(int i=0;i<n;i++){
        system("CLS");
        cout << "Socio #" << i+1 << endl;
        cout << "Ingresar Nombre: ";
        cin >> Nombre[i];
        _flushall();
        cout << "Ingresar Apellido: ";
        cin >> Apellido[i];
    }

    cout << endl << "Carga completa." << endl;
    system("PAUSE");
}

void Ordenar(c30 Nombre[100], c30 Apellido[100], c30 nombreCompleto[100], int n){
    int min;
    c30 aux[100];
    //Unir

    for(int i=0; i<n; i++){
        strcpy(nombreCompleto[i], Nombre[i]);
        strcat(nombreCompleto[i], " ");
        strcat(nombreCompleto[i], Apellido[i]);
    }

    //Ordenar por metodo de seleccion

    for(int i=0;i<n;i++){	
		min = i;
		for(int j=i+1;j<n;j++){
			if(strcmp(nombreCompleto[j], nombreCompleto[min])>0){
				min = j;
			}
		}
		strcpy(aux[0],nombreCompleto[i]);
		strcpy(nombreCompleto[i], nombreCompleto[min]);
		strcpy(nombreCompleto[min], aux[0]);
	}

}

void Mostrar(c30 nombreCompleto[100], int n){
    cout << endl;
    for(int i=0; i<n; i++){
        cout << i+1 << ")" << nombreCompleto[i] << endl;
    }
    cout << endl;
    system("PAUSE");
}

void OrdenAp(c30 Apellidos[100], c30 orden2[100], int n){
    int min;
    c30 aux[100];

    //Copiar el contenido de apellidos en la nueva lista.
    for(int i=0;i<n;i++){
        strcpy(orden2[i], Apellidos[i]);
    }
    

    //Ordenar por metodo de seleccion

    for(int i=0;i<n;i++){	
		min = i;
		for(int j=i+1;j<n;j++){
			if(strcmp(orden2[j], orden2[min])<0){
				min = j;
			}
		}
		strcpy(aux[0],orden2[i]);
		strcpy(orden2[i], orden2[min]);
		strcpy(orden2[min], aux[0]);
	}
    
    //Mostrar el vector ordenado.
    cout << endl;
    for(int i=0; i<n; i++){
        cout << orden2[i] << endl;
    }

    system("PAUSE");
}

void Error(){
    cout << endl << "El vector aun no ha sido cargado." << endl;
    system("PAUSE");
}