#include <stdlib.h>
#include <stdio.h> 

void intervalo(int A, int B, int n);

main(){
    int l1, l2, n;

    printf("\nIngresar los limites del intervalo (A, B]: \n");
    printf("A: ");
    scanf("%i",&l1);
    printf("B: ");
    scanf("%i",&l2);

    printf("\nCantidad de numeros a ingresar: ");
    scanf("%i",&n);

    intervalo(l1,l2,n);
    system("PAUSE"); 
}

void intervalo(int A, int B, int n){
    int dentro=0,fuera=0,nro;
    system("cls");
    printf("Ingresar %i numero(s) teniendo en cuenta el intervalo (%i,%i]:\n", n, A, B);
    for (int i = 1; i <= n; i++)
    {  
        printf("%i) ",i);
        scanf("%i",&nro);

        if (nro<A or nro>=B){
            fuera=fuera+1;
        } else {
            dentro=dentro+1;
        }
    }
    printf("*******************************************************************************");
    printf("\n\tCantidad de puntos fuera: %i\n\tCantidad de puntos dentro: %i\n", fuera, dentro);
    printf("*******************************************************************************\n");
}