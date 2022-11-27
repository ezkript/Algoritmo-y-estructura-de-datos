#include <stdio.h>
#include <stdlib.h>

int Equivalencias(int min);

main(){
    int min, equiv;
    do {
        printf("Ingresar una cantidad en minutos: ");
        scanf("%i",&min);
    } while(min<600);

    equiv=Equivalencias(min);
    printf("El resultado es: %i\n\n",equiv);
    system("PAUSE");
}

int Equivalencias(int min){
    int opcion, equiv;
    printf("Seleccionar: \n1)Equivalencia en horas.\n2)Equivalencia en minutos.\n3)Equivalencia en segundos.\nRespuesta: ");
    scanf("%i",&opcion);
    
    switch (opcion)
    {
        case 1:
            printf("\nEquivalencia en horas:\n");
            equiv=min/60;
            break;
        
        case 2:
            printf("\nEquivalencia en minutos:\n");
            equiv=min;
            break;
        case 3:
            printf("\nEquivalencia en segundos:\n");
            equiv=min*60;
            break;
        default:
            printf("La opcion elegida no existe.");
            break;
    }
    return equiv;
}