#include <stdio.h>
#include <stdlib.h>

void multiplos(int num1, int num2);

main(){
    int duplas, num1, num2;

    printf("Cantidad de duplas a ingresar: ");
    scanf("%i",&duplas);

    for (int i = 1; i <=duplas; i++)
    {   
        do {
            printf("1) Ingresar numero entre 1 y 9: ");
            scanf("%i",&num1);
        }while(num1<1 or num1>9);

        do {
            printf("2) Ingresar numero entre 1 y 9(distinto del primero): ");
            scanf("%i",&num2);
        }while(num2==num1 or num2<1 or num2>9);

        multiplos(num1,num2);
    }
    system("PAUSE");
}

void multiplos(int num1, int num2){
    int tope=0, contador=0,puntero=0, multiplo1,multiplos2[10];

    while(tope<10){
        if(num1>num2){
            multiplo1=num1*contador;
            if(multiplo1%num2==0){
                multiplos2[puntero]=multiplo1;  
                tope=tope+1;
                puntero=puntero+1;
            }
            contador=contador+1;
        } else {
            multiplo1=num2*contador;
            if(multiplo1%num1==0){
                multiplos2[puntero]=multiplo1;
                tope=tope+1;  
                puntero=puntero+1;
            }
            contador=contador+1; 
        }
    }
    printf("\nLos primeros 10 multiplos comunes entre %i y %i son: \n%i - %i - %i - %i - %i - %i - %i - %i - %i - %i\n",num1,num2,multiplos2[0],multiplos2[1],multiplos2[2],multiplos2[3],multiplos2[4],multiplos2[5],multiplos2[6],multiplos2[7],multiplos2[8],multiplos2[9]);
    printf("------------------------------------------------------------\n");
}