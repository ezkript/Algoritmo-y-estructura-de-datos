#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

struct Coordenadas {
    int x; //Coordenada X
    int y; //Coordenada Y
};

void Limpiar(); //Limpiar y pausar.
void cargar(struct Coordenadas &P1, struct Coordenadas &P2); //Cargar P1 y P2.
void mostrar(struct Coordenadas P1, struct Coordenadas P2); //Mostrar P1 y P2.
float calcular(struct Coordenadas P1); //Calcular la distancia de P1 al origen.
float distancia(struct Coordenadas P1,struct Coordenadas P2); //Calcular distancia entre P1 y P2.

int main(){
    struct Coordenadas P1, P2;
    int opcion, flag=0;

    do{
        //--------------Menu de opciones---------------
        cout << "-------------------" << endl << "1. Cargar dos puntos." << endl << "2. Mostrar puntos cargados." << endl << "3. Calcular la distancia del punto 1 al origen." << endl << "4. Calcular distancia entre los dos puntos." << endl << "5. Salir." << endl << "-------------------" << endl << "Opcion: ";
        cin >> opcion;

        system("CLS"); //Limpiar el menu cuando se elija la opcion.

        switch (opcion){
        case 1:
            cargar(P1, P2);
            cout << endl << endl;
            flag=1;
            Limpiar();
            break;
        case 2:
            if(flag==1){
                mostrar(P1, P2);
                Limpiar();
                break;
            } else {
                cout << endl << "Los puntos aun no fueron cargados." << endl;
                Limpiar();
                break;
            }
        case 3:
            if(flag==1){
                cout << "La distancia de P1 al origen es: " << calcular(P1) << endl;
                Limpiar();
                break;
            } else {
                cout << endl << "Los puntos aun no fueron cargados." << endl;
                Limpiar();
                break;
            }
        case 4:
            if(flag==1){
                cout << endl << "La longitud del segmento de recta que une los dos puntos es: " << distancia(P1, P2) << endl;
                Limpiar();
                break;
            } else {
                cout << endl << "Los puntos aun no fueron cargados." << endl;
                Limpiar();
                break;
            }
        case 5:
            break;
        default:
            cout << endl << "La opcion elegida no existe." << endl;
            Limpiar();
            break;
        }
    } while (opcion!=5);
    
}

void Limpiar(){
    system("PAUSE");
    system("CLS");
}

void cargar(struct Coordenadas &P1, struct Coordenadas &P2){
    cout << "Coordenada X(P1): ";
    cin >> P1.x;
    cout << "Coordenada Y(P1): ";
    cin >> P1.y;
    system("CLS");
    cout << "Coordenada X(P2): ";
    cin >> P2.x;
    cout << "Coordenada Y(P2): ";
    cin >> P2.y;
}

void mostrar(struct Coordenadas P1, struct Coordenadas P2){
    cout << endl << "Puntos:" << endl << "P1(" << P1.x << "," << P1.y << ") / " << "P2(" << P2.x << "," << P2.y << ")" << endl;
}

float calcular(struct Coordenadas P1){
    int a=P1.x, b=P1.y;

    //Calcular la distancia con teorema de pitagoras.
    float c=sqrt(pow(a, 2)+pow(b, 2));

    return c;
}

float distancia(struct Coordenadas P1,struct Coordenadas P2){
    int x1=P1.x, y1=P1.y, x2=P2.x, y2=P2.y;
    float c;

    //Calcular la distancia con formula de distancia entre dos puntos.
    c = sqrt(pow((x2 - x1),2) + pow((y2 - y1), 2));

     return c;
}