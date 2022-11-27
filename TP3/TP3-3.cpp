#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main(){
	int numero=0;
	float raiz=0.00;
	printf("Ingrese un numero entero\n");
	scanf("%d", &numero);
	
	if (numero >0){
		raiz = sqrt(numero);
		printf("La raiz cuadrada es %2.2f\n", raiz);
	}
	else{
		raiz = sqrt(abs(numero));
		printf("La raiz cuadrada es %f\n", raiz);
	}
	system("PAUSE");
}
