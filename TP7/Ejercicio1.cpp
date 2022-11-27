#include <stdlib.h>
#include <iostream>
using namespace std;

struct datosCliente{
    int codCli; //código del cliente.
    char ApeNom[40]; //apellido y nombre.
    char dire[60]; //domicilio particular.
    float monCred; //monto máximo del crédito que puede realizar en cada compra.
};

void mostrar(struct datosCliente cliente[100],int i);
int monSup(struct datosCliente cliente[100], int n);

int main(){
    struct datosCliente clientes[100];    
    int n;

    cout << "Ingresar la cantidad de clientes: ";
    cin >> n;

    //Cargar los datos de los clientes.
    for (int i = 0; i < n; i++){
        cout << endl << "Cliente #" << i+1 << endl << "Codigo de cliente: ";
        cin >> clientes[i].codCli;
        fflush(stdin);
        cout << "Apellido y nombre: ";
        cin.getline(clientes[i].ApeNom, 40, '\n');
        fflush(stdin);
        cout << "Domicilio: ";
        cin.getline(clientes[i].dire,60,'\n');
        fflush(stdin);
        cout << "Monto maximo de credito: ";
        cin >> clientes[i].monCred;

        mostrar(clientes, i); //Mostrar los datos registrados.
    }
    
    //Mostrar cantidad de clientes con un monto maximo mayor a 30,000.
    cout << endl << "Hay " << monSup(clientes,n) << " que superan el monto maximo de 30000." << endl;

    system("PAUSE");
    return 0;
}

void mostrar(struct datosCliente cliente[100],int i){
    cout << endl << "Registrado: " << endl;
    cout << "Codigo: " << cliente[i].codCli << ", Nombre: " << cliente[i].ApeNom << ", Domicilio: " <<  cliente[i].dire << ", Monto maximo permitido: " << cliente[i].monCred << endl;
}

int monSup(struct datosCliente cliente[100], int n){
    int count=0;
    for(int i=0; i<n; i++){
        if(cliente[i].monCred > 30000){
            count++;
        }
    }
    return count;
}