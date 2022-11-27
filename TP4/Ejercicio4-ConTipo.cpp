#include <stdio.h>
#include <stdlib.h>

void ValoresPares(int N, int&impares);
float ValoresImpares(int N, int impares);

main(){
    int N, nro=0,impares=0;
    float promedio;

    printf("Cantidad de valores enteros a ingresar: ");
    scanf("%i",&N);

    ValoresPares(N,impares);

    promedio=ValoresImpares(N,impares);

    printf("\nEl promedio de valores impares es: %.2f\n",promedio);
    system("PAUSE");
}

void ValoresPares(int N, int&impares){
    int nro,par=0;
    float resultado;
    for(int i=1; i<=N; i++){
        printf("%i. Ingresar numero: ",i);
        scanf("%i",&nro);
        if(nro%2==0){
            par=par+1;
        } else {
            impares=impares+nro;
        }
    }
    resultado=(float) par*100/N;
    printf("El porcentaje de valores pares ingresados es: %.2f%",resultado);
}

float ValoresImpares(int N, int impares){
    float resultado;
    resultado=(float) impares/N;
    return resultado;
}