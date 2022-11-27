#include <stdio.h>
#include <stdlib.h>

void SuperficieCuadrado(int lado1, int lado2, int& areacuadrado);
void SuperCirculo(int numero1,int num2, int& areacirculo);

main(){
    int num1, num2, area=0;
    
    printf("Ingresar primer numero entero: ");
    scanf("%i",&num1);

    do {
    printf("Ingresar segundo numero entero (Debe ser distinto del primero): ");
    scanf("%i",&num2);
    } while(num2 == num1);

    SuperficieCuadrado(num1,num2,area);
    printf("El area del cuadrado es %i\n", area);
    SuperCirculo(num1,num2,area);
    printf("El area del circulo es %i", area);
}

void SuperficieCuadrado(int lado1, int lado2, int& areacuadrado){
    if(lado1>lado2){
        areacuadrado=lado1*lado1;
    } else {
        areacuadrado=lado2*lado2;
    }
}

void SuperCirculo(int numero1,int num2, int& areacirculo){
    if(numero1<num2){
        areacirculo=numero1*numero1*3.14;
    } else {
        areacirculo=num2*num2*3.14;
    }
}