#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <iostream>
using namespace std;

struct fecha {
    int day;
    int month;
};

struct documentacion {
    char nroExp[60];
    char propietario[60];
    int metrosCuadrados;
    int tipo;
    fecha registro[12];
    float montoAdelanto[12];
};

void gotoxy(int x, int y);
void Limpiar();
void cargarRegistro(struct documentacion propietarios[100], int n);
void registrarMonto(struct documentacion propietarios[100], int n, char exp[60], struct fecha fecha1, float monto);
void mostrar(struct documentacion propietarios[100], int n, char expediente[60]);

int main(){
    int n, opcion, flag=0;
    char expediente[60];
    float monto;
    struct documentacion propietarios[100];
    struct fecha fecha1;

    // do {
    //     if(n<5){
    //         cout << endl << "Debe ingresar por lo menos 5 registros: ";
    //     } else {
    //         cout << endl << "Ingresar la cantidad de registros: ";
    //     }
    //     cin >> n;
    // } while (n<5);

    cout << endl << "Ingresar la cantidad de registros: ";
    cin >> n;
    do{
        cout << "----------------------------" << endl
        << "1. Registrar datos." << endl
        << "2. Registrar adelantos." << endl
        << "3. Mostrar expediente..." << endl
        << "4. Salir." << endl
        << "----------------------------" << endl
        << "Respuesta: "; cin >> opcion;
        system("CLS");
        switch (opcion){
        case 1:
            cargarRegistro(propietarios,n);
            cout << "Carga completa." << endl;
            flag=1;
            Limpiar();
            break;
        case 2:
            if(flag==1){
                cout << "--------- Registrar adelanto -----------" << endl
                << "Expediente: ";fflush(stdin);cin.getline(expediente, 60, '\n');
                cout << "Fecha del adelanto" << endl << "Dia: ";cin >> fecha1.day;
                cout << "Mes: ";cin >> fecha1.month;
                cout << "Monto: "; cin >> monto;
                cout << "----------------------------------------" << endl;
                registrarMonto(propietarios,n,expediente,fecha1,monto);
            } else {
                cout << "Los datos aun no fueron cargados." << endl;
            }
            Limpiar();
            break;
        case 3:
            if(flag==1){
                fflush(stdin);
                cout << endl << "Mostrar monto" << endl << "Expediente: ";cin.getline(expediente, 60, '\n');
                mostrar(propietarios, n, expediente);
            } else {
                cout << "Los datos aun no fueron cargados." << endl;
            }
            Limpiar();
            break;
        case 4:
            break;
        default:
            cout << "La opcion no existe.";
            Limpiar();
            break;
        }
        
    } while (opcion!=4);
    
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

void cargarRegistro(struct documentacion propietarios[100], int n){
    for(int i=0; i<n; i++){
        cout << "Registro #" << i+1 << endl;
        fflush(stdin);
        cout << endl << "Ingresar nro. de expediente: ";cin.getline(propietarios[i].nroExp, 60, '\n');
        fflush(stdin);
        cout << "Nombre del propietario: ";cin.getline(propietarios[i].propietario, 60, '\n');
        cout << "Metros cuadrados construidos: ";cin >> propietarios[i].metrosCuadrados;
        propietarios[i].tipo=1;
        do{
            if(propietarios[i].tipo<0 || propietarios[i].tipo>3){
                cout << endl << "La opcion no existe." << endl 
                << "Respuesta: ";
            } else {
                cout << endl << "Tipo de obra" << endl
                << "0. Vivienda basica" << endl
                << "1. Vivienda de lujo" << endl
                << "2. Edificio" << endl
                << "3. Predio especial" << endl
                << "Respuesta: ";
            }
            cin >> propietarios[i].tipo;
            system("CLS");
        }while (propietarios[i].tipo<0 || propietarios[i].tipo>3);
    }
    
}

void registrarMonto(struct documentacion propietarios[100], int n, char exp[60], struct fecha fecha1, float monto){
    int flag=0;
    for(int i=0; i<n; i++){
        if(strcmp(strlwr(propietarios[i].nroExp), strlwr(exp))==0){
            propietarios[i].registro[fecha1.month].day = fecha1.day;
            propietarios[i].registro[fecha1.month].month = fecha1.month;
            propietarios[i].montoAdelanto[fecha1.month] = monto;
            flag=1;
            cout << endl << "Registrado exitosamente." << endl;
        }
    }
    if(flag==0){
        cout << endl << "El expediente no fue encontrado." << endl;
    }
}

void mostrar(struct documentacion propietarios[100], int n, char expediente[60]){
    int count=0;
    float total=0.0;
    for(int i=0; i<n; i++){
        if(strcmp(strlwr(propietarios[i].nroExp), strlwr(expediente))==0){
            gotoxy(4, 4);cout << "Expediente: " << propietarios[i].nroExp;
            gotoxy(4, 5);cout << "Propietario: " << propietarios[i].propietario;
            gotoxy(4, 6);cout << "Tipo Obra: " << propietarios[i].tipo;
            gotoxy(8, 7);cout << "Fecha"; gotoxy(18,7);cout << "Monto" << endl;
            gotoxy(8,8);cout << "====================";
            for(int j=0; j<12;j++){
                if(propietarios[i].registro[j].month > 0 && propietarios[i].registro[j].month<=12){
                    gotoxy(8,9+count);cout << propietarios[i].registro[j].day << "/" << propietarios[i].registro[j].month;
                    gotoxy(18,9+count);cout << propietarios[i].montoAdelanto[j];
                    total+=propietarios[i].montoAdelanto[j];
                } else {
                    count--;
                }
                count++;
            }
            gotoxy(8,9+count);cout << "====================";
            gotoxy(8,9+count+1);cout << "Total";
            gotoxy(18,9+count+1);cout << total;
            cout << endl;
        }
    }
}