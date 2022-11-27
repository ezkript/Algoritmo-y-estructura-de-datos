#include <stdlib.h>
#include <iostream>
using namespace std;

struct fecNac{
    int day;
    int month;
    int year;
};

struct notasTrim{
    int pTrim;
    int sTrim;
    int tTrim;
    float pAnual;
};

struct datosAlumnos {
    int nroDoc;
    char apNom[60];
    fecNac nacimiento;
    notasTrim notas;
};

void cargar(struct datosAlumnos alumno[100], int n);

int main(){
    struct datosAlumnos alumno[100];
    int n;
    float promedioTotal=0.0;

    cout << "Cantidad de alumnos: ";
    cin >> n;

    fflush(stdin);
    system("CLS");
    cargar(alumno, n);

    cout << endl << "Promedios: " << endl;
    for (int i = 0; i < n; i++){
        cout << alumno[i].apNom << "(" << alumno[i].nroDoc << "): " << alumno[i].notas.pAnual << endl;
        promedioTotal+=alumno[i].notas.pAnual;
    }

    promedioTotal=(float)promedioTotal/n;

    cout << endl << endl << "El promedio total del curso es: " << promedioTotal << endl;

    system("PAUSE");
    return 0;    
}

void cargar(struct datosAlumnos alumno[100], int n){
    float promedio;
    for (int i = 0; i < n; i++){
        system("CLS");
        cout << "Alumno #" << i+1 << ": " << endl << "Documento: ";
        cin >> alumno[i].nroDoc;
        fflush(stdin);
        cout << "Nombre: ";
        cin.getline(alumno[i].apNom, 60, '\n');
        
        cout << endl << "Fecha de nacimiento. " << endl << "Dia: ";
        cin >> alumno[i].nacimiento.day;
        cout << "Mes: ";
        cin >> alumno[i].nacimiento.month;
        cout << "Anio: ";
        cin >> alumno[i].nacimiento.year;
        
        cout << endl << "Promedio. " << endl << "1er Trimestre: ";
        cin >> alumno[i].notas.pTrim;
        cout << "2do Trimestre: ";
        cin >> alumno[i].notas.sTrim;
        cout << "3er Trimestre: ";
        cin >> alumno[i].notas.tTrim;

        promedio = (float) (alumno[i].notas.pTrim + alumno[i].notas.sTrim +
alumno[i].notas.tTrim)/3;

        alumno[i].notas.pAnual = promedio;
    }
}