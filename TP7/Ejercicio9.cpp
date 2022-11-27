#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

typedef char longChar[100];

struct Articulos {
    int codigo;
    char descripcion[100];
    int disponible;
    float precio;
};

void Limpiar();
void cargar(Articulos articulo[100], int n);
void buscar(Articulos articulo[100], int &n, int buscarCod);
void ordenarDesc(Articulos articulo[100], int n);
void ordenarStock(Articulos articulo[100], int n);

int main(){
    int n,
        opcion,
        flag,
        buscarCod;
    float precio;
    Articulos articulo[100];

    do {
        cout << "----------------------------" << endl 
        << "Elegir opcion" << endl
        << "1. Ingresar articulos" << endl
        << "2. Buscar y/o Eliminar" << endl
        << "3. Listar inventario p/Descripcion" << endl
        << "4. Listar inventario p/Stock" << endl
        << "5. Salir" << endl
        << "----------------------------" << endl
        << "Respuesta: "; cin >> opcion;
        system("CLS");

        switch (opcion){
        case 1:
            cout << "Cantidad de articulos a ingresar: "; cin >> n;
            
            cargar(articulo,n);

            Limpiar();
            flag=1;
            break;
        case 2:
            if(flag==1){
                cout << "Buscar articulo por codigo" << endl
                << "Ingresar codigo: "; cin >> buscarCod;
                buscar(articulo, n, buscarCod);
            } else {
                cout << "Error: los datos aun no fueron cargados!" << endl;
            }
            Limpiar();
            break;
        case 3:
            if(flag==1){
                ordenarDesc(articulo, n);
            } else {
                cout << "Error: los datos aun no fueron cargados!" << endl;
            }
            Limpiar();
            break;
        case 4:
            if(flag==1){
                ordenarStock(articulo, n);
            } else {
                cout << "Error: los datos aun no fueron cargados!" << endl;
            }
            Limpiar();
            break;
        case 5:
            break;
        default:
            cout << "La opcion elegida no existe." << endl;
            Limpiar();
            break;
        }
        

    } while(opcion!=5);



    return 0;
}

void Limpiar(){
    system("PAUSE");
    system("CLS");
}

void cargar(Articulos articulo[100], int n){
    for(int i=0; i<n; i++){
        system("CLS");
        cout << "Producto #" << i+1 << endl << endl;
        cout << "Codigo: "; cin >> articulo[i].codigo;
        cout << "Descripcion: ";fflush(stdin); cin.getline(articulo[i].descripcion, 100, '\n');
        cout << "Stock: "; cin >> articulo[i].disponible;
        cout << "Precio: "; cin >> articulo[i].precio;
    }
}

void buscar(Articulos articulo[100], int &n, int buscarCod){
    int encontrado=0,
        respuesta;
    for(int i=0; i<n && encontrado==0; i++){
        if(buscarCod==articulo[i].codigo){
            encontrado=1;
            cout << "Articulo encontrado." << endl
            << "Descripcion: " << articulo[i].descripcion << endl
            << "Codigo: " << articulo[i].codigo << endl
            << "Stock: " << articulo[i].disponible << endl
            << "Precio: " << articulo[i].precio << endl << endl
            << "Eliminar articulo?" << endl
            << "1. Si" << endl
            << "2. No" << endl
            << "Respuesta: "; cin >> respuesta;
            if(respuesta==1){
                for(int j=i; j<n; j++){
                    articulo[j]=articulo[j+1];
                }
                n--;
                cout << "El articulo fue eliminado." << endl << endl;
            }
        }
    }
    if(encontrado==0){
        cout << "El articulo no fue encontrado." << endl << endl;
    }
}

void ordenarDesc(Articulos articulo[100], int n){
    Articulos Ordenar[100];
    Articulos aux;
    int pos, min;

    for(int i=0; i<n; i++){
        strcpy(Ordenar[i].descripcion,articulo[i].descripcion);
        Ordenar[i].codigo=articulo[i].codigo;
        Ordenar[i].disponible=articulo[i].disponible;
        Ordenar[i].precio=articulo[i].precio;
    }

    for(int c=0;c<n;c++){
		
		min = c;
		for(int j=c+1;j<n;j++){
			if(strcmp(Ordenar[j].descripcion,Ordenar[min].descripcion)>0){
				min = j;
			}
		}
		aux = Ordenar[c];
		Ordenar[c] = Ordenar[min];
		Ordenar[min] = aux;
    }
    
    for(int k=0; k<n; k++){
        cout << "Stock: " << Ordenar[k].disponible << endl
        << "Codigo: " << Ordenar[k].codigo << endl
        << "Descripcion: " << Ordenar[k].descripcion << endl
        << "Precio: " << Ordenar[k].precio << endl << endl;
    }
    
}

void ordenarStock(Articulos articulo[100], int n){
    int pos,min;
    Articulos aux;
    Articulos Ordenar[100];

    for(int i=0; i<n; i++){
        Ordenar[i]=articulo[i];
    }

    for(int c=0;c<n;c++){
		min = c;
		for(int j=c+1;j<n;j++){
			if(Ordenar[j].disponible<Ordenar[min].disponible){
				min = j;
			}
		}
		aux = Ordenar[c];
		Ordenar[c] = Ordenar[min];
		Ordenar[min] = aux;
    }

    for(int k=0; k<n; k++){
        cout << "Stock: " << Ordenar[k].disponible << endl
        << "Codigo: " << Ordenar[k].codigo << endl
        << "Descripcion: " << Ordenar[k].descripcion << endl
        << "Precio: " << Ordenar[k].precio << endl << endl;
    }
}