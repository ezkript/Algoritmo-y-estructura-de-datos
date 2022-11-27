#include <stdio.h>
#include <stdlib.h>
main(void){
    int cantPreg = 0, correct = 0, porcent = 0;
    printf("Cantidad de preguntas realizadas: ");
    scanf("%i",&cantPreg);
    printf("Preguntas contestadas correctamente: ");
    scanf("%i",&correct);
    porcent=(correct*100)/cantPreg;
    if(porcent>=50 and porcent<75){
        printf("\nEl porcentaje de preguntas correctas es %i%\nNivel: Regular.\n", porcent);
    } else if (porcent>=75 and porcent<90){
        printf("\nEl porcentaje de preguntas correctas es %i%\nNivel: Medio.\n", porcent);
    } else if (porcent>=90){
        printf("\nEl porcentaje de preguntas correctas es %i%\nNivel: Superior.\n", porcent);
    }
    system("PAUSE");
}