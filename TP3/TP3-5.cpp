#include <stdio.h>
#include <stdlib.h>
main(void)
{
    int aprobado= 0, curso= 0, edad = 0;
    printf("---------------------------------------\nSistema de incripcion de la Academia.\n---------------------------------------");
    printf("\n\nResultado del alumno en los examenes: \nAprobado = 1 | Desaprobado = 2\nRespuesta: ");
    scanf("%i", &aprobado);
    printf("\n\nCual es la edad del alumno?\nRespuesta: ");
    scanf("%i",&edad);
    printf("\n\n");

    if(edad<=10){
        curso=1;
    } else if (edad <=20){
        curso=2;
    } else if (edad>20){
        curso=3;
    }

    if (aprobado==1){
        printf("El alumno fue registrado en el curso %i y en la division A\n\n",curso);
    }
    else {
        printf("El alumno fue registrado en el curso %i y en la division B\n\n",curso);   
    }
    system("PAUSE");
}
