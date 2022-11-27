#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

main(){
	system("COLOR F1");
	
	int importe1 = 0;
	int importe2 = 0;
	int importe3 = 0;
	int cantidad1 = 0;
	int cantidad2 = 0;
	int cantidad3 = 0;
	int opcion = 0;
	int imptot1 = 0;
	int imptot2 = 0;
	int imptot3 = 0;
	int porcentaje1 = 0;
	int porcentaje2 = 0;
	int porcentaje3 = 0;
	int importetotal = 0;
	char articulo1[20];
	char articulo2[20];
	char articulo3[20];
	
	printf("\t\t BIENVENIDO SR VENDEDOR" );
	printf("\n\n *****************************************************\n\n");
	printf(" Inserte el nombre del articulo 1: ");
	scanf("%s",&articulo1);
	system("cls");
	printf(" Inserte el nombre del articulo 2: ");
	scanf("%s",&articulo2);
	system("cls");
	printf(" Inserte el nombre del articulo 3: ");
	scanf("%s",&articulo3);
	system("cls");
	
	
	printf(" Inserte cantidad de articulos vendidos para %s : ",articulo1);
	scanf ("%d",&cantidad1);
	printf(" Inserte importe de %s : ",articulo1);
	scanf ("%d",&importe1);
	
	imptot1 = importe1*cantidad1;
	system("cls");
	
	
	
	printf(" Inserte cantidad de articulos vendidos para %s : ",articulo2);
	scanf ("%d",&cantidad2);
	printf(" Inserte importe del %s : ",articulo2);
	scanf ("%d",&importe2);
	
	imptot2 = importe2*cantidad2;
	system("cls");
	
	
	
	printf(" Inserte cantidad de articulos vendidos para %s : ",articulo3);
	scanf ("%d",&cantidad3);
	printf(" Inserte importe del %s : ",articulo3);
	scanf ("%d",&importe3);
	
	imptot3 = importe3*cantidad3;
	system("cls");
	
	do
	{
	
	system ("cls");
	printf("\t\tIngrese operacion a realizar\n\n");
	printf(" 1) Indicar que articulo tiene mayor importe ingresado\n\n");
	printf(" 2) Indicar importe total vendido de cada articulo\n\n");
	printf(" 3) Calcular porcentaje de cada articulo ingresado\n\n");
	printf(" Ingrese 0 para salir \n\n");
	printf("INDIQUE OPCION A REALIZAR AQUI: ");
	scanf ("%d",&opcion);
	switch(opcion)
		{
			case 1:
					system("cls");
					
					if(importe1>importe2&&importe1>importe3)
						{
						printf("\n\t EL articulo con mayor importe es %s con un precio de %d$ y un total vendido de %d$ \n\n",articulo1,importe1,imptot1);
						}
					if(importe2>importe1&&importe2>importe3)
						{
						printf("\n\t EL articulo con mayor importe es %s con un precio de %d$ y un total vendido de %d$\n\n",articulo2,importe2,imptot2);
						}
					if(importe3>importe1&&importe3>importe2)
						{
						printf("\n\t EL articulo con mayor importe es %s con un precio de %d$ y un total vendido de %d$\n\n",articulo3,importe3,imptot3);
						}
					break;
					
			case 2:
					system("cls");
					printf("\n\t Importe total vendido de cada articulo\n");
					printf("\n\t Importe total de %s : %d$ \n",articulo1,imptot1);
					printf("\n\t Importe total de %s : %d$ \n",articulo2,imptot2);
					printf("\n\t Importe total de %s : %d$ \n",articulo3,imptot3);
					
					break;
					
			case 3:
					system("cls");
					
					importetotal = imptot1+imptot2+imptot3;
					porcentaje1 = imptot1*100/importetotal;
					porcentaje2 = imptot2*100/importetotal;
					porcentaje3 = imptot3*100/importetotal;
					
					printf("\n\t Porcentaje de cada articulo\n");
					printf("\n\t Porcentaje de %s: %d\n",articulo1,porcentaje1);
					printf("\n\t Porcentaje de %s: %d\n",articulo2,porcentaje2);
					printf("\n\t Porcentaje de %s: %d\n",articulo3,porcentaje3);
				
					break;
					
			case 0:
					printf("\n Ud Salio del Sistema...\n\n");
					break;
					
			default:
					printf("\n\n Opcion no valida...\n\n");
	}
	

	
	system("PAUSE");
	
	
	}while(opcion!=0);
	
}
