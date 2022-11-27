#include <stdio.h>
#include <stdlib.h>

int Cuadrado(int nro);

main(){

    int n, nro, r;
    
    printf("Cantidad de numeros a calcular: ");
    scanf("%i",&n);

    for (int i = 1; i <= n; i++)
    {
        printf("Calcular el cuadrado de: ");
        scanf("%i",&nro);

        r=Cuadrado(nro);
        printf("el cuadrado de %i es %i.\n\n",nro,r);
    }
    system("PAUSE");
}

int Cuadrado(int nro){
    int impares=1,suma=0;
    printf("Se sumaran los siguientes numeros: \n");
    for(int i=1;i<=nro;i++)
    {
        printf("%i, ",impares);
        suma=suma+impares;
        impares=impares+2;
    }
    printf("dando como resultado que ");
    return suma;
}