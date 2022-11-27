#include<stdio.h>
#include<stdlib.h>

main (){
	float montoprimerproducto=0,precio1,kiloproducto1;
	float montosegundoproducto=0,precio2,kiloproducto2;
	float montotercerproducto=0,precio3,kiloproducto3;
	const float descuento=0.05;
	float montotal=0, montofinal=0, desc=0;
	
	printf("Ingrese el precio del producto 1: \n");
	scanf("%f", &precio1);
	printf("Ingrese la cantidad en kilo del producto 1: \n");
	scanf("%f", &kiloproducto1);
	printf("Ingrese el precio del producto 2: \n");
	scanf("%f", &precio2);
	printf("Ingrese la cantidad en kilo del producto 2: \n");
	scanf("%f", &kiloproducto2);
	printf("Ingrese el precio del producto 3: \n");
	scanf("%f", &precio3);
	printf("Ingrese la cantidad en kilo del producto 3: \n");
	scanf("%f", &kiloproducto3);
	
	montoprimerproducto=precio1*kiloproducto1;
	montosegundoproducto=precio2*kiloproducto2;
	montotercerproducto=precio3*kiloproducto3;
	
	montotal=montoprimerproducto+montosegundoproducto+montotercerproducto;
	if(montotal>1000)
	{
		desc=montotal*descuento;
		montofinal=montotal-desc;
		printf("\nProducto 01 \t\t\t\t $%.2f \t\t\t\t %.2f \t\t\t\t $%.2f", precio1,kiloproducto1, montoprimerproducto);
		printf("\nProducto 02 \t\t\t\t $%.2f \t\t\t\t %.2f \t\t\t\t $%.2f", precio2,kiloproducto2, montosegundoproducto);
		printf("\nProducto 03 \t\t\t\t $%.2f \t\t\t\t %.2f \t\t\t\t $%.2f", precio3,kiloproducto3, montotercerproducto);
		printf("\nTotal a pagar \t\t\t\t                                                                         $%.2f",montotal);
		printf("\nDescuento \t\t\t\t                                                                         $%.2f",desc);
		printf("\nPago final \t\t\t\t                                                                         $%.2f\n",montofinal);
	}else
	{
		printf("\nProducto 01 \t\t\t\t $%.2f \t\t\t\t %.2f \t\t\t\t $%.2f", precio1,kiloproducto1, montoprimerproducto);
		printf("\nProducto 02 \t\t\t\t $%.2f \t\t\t\t %.2f \t\t\t\t $%.2f", precio2,kiloproducto2, montosegundoproducto);
		printf("\nProducto 03 \t\t\t\t $%.2f \t\t\t\t %.2f \t\t\t\t $%.2f\n", precio3,kiloproducto3, montotercerproducto);
		printf("\nTotal a pagar \t\t\t\t                                                      $%.2f\n",montotal);
	}
	system("PAUSE");
}
