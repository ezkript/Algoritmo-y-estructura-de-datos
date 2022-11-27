#include <stdlib.h>
#include <stdio.h>

void suma(int N, float&resultado);

main(){

    int N;
    float resultado=0.0;

    printf("Cantidad de numeros que van a ser ingresados: ");
    scanf("%i",&N);

    suma(N, resultado); 

    printf("\nEl resultado de la suma es: %f\n",resultado);
    system("PAUSE");
}

void suma(int N, float&resultado){
    float nro;
    printf("Ingresar numeros: \n");
    for (int i = 1; i <= N; i++)
    {
        printf("%i) ",i);
        scanf("%f",&nro);

        resultado=resultado+nro;
    }    
}