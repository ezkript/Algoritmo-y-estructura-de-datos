#include <stdio.h>
#include <stdlib.h>
main(void){
    int dia = 0, mes = 0;
    printf("\n*******************\nEstaciones del anio\n*******************\n");

    while (mes<=0 or mes>12)
    {
        printf("\nIngresar el mes: ");
        scanf("%i",&mes);
    } 

    while (dia<=0 or dia>31)
    {
        printf("\nIngresar el dia: ");
        scanf("%i",&dia); 
    }
   
    if(mes==4 or mes==6 or mes==9 or mes==11){
        while(dia>=31){
            printf("\nIngresar el dia: ");
            scanf("%i",&dia);
        }
    } else if (mes==2)
    {
        while(dia>=30){
            printf("\nIngresar el dia: ");
            scanf("%i",&dia);
        }
    }
    
    if(mes==12 or (mes>=1 and mes<=3)){
        if((mes!=3 and mes!=12) or (mes==12 and dia>=21) or (mes==3 and dia<=20)){
            printf("Estacion: Verano\n");
        } else if (mes==3 and dia>=21){
            printf("Estacion: Otonio\n");
        } else if (mes==12 and dia<=20){
            printf("Estacion: Primavera\n");
        }
    } else if (mes>=4 and mes<=6){
        if (mes!=6 or dia<=20){
            printf("Estacion: Otonio\n");
        } else if(mes==6 and dia>=21){
            printf("Estacion: Invierno\n");
        }
    } else if (mes>=7 and mes<=9)
    {
        if (mes!=9 or dia<=20){
            printf("Estacion: Invierno\n");
        } else if(mes==9 and dia>=21){
            printf("Estacion: Primavera\n");
        }
    } else if (mes>=10 and mes<=11)
    {
        printf("Estacion: Primavera\n");
    }
    system("PAUSE");
}