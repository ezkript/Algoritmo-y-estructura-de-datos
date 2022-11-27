#include <stdio.h>
#include <stdlib.h>
main(){
	int I, J, K, L;
	
	printf("Ingrese el valor para I\n");
	scanf("%d", &I);
	printf("Ingrese el valor para J\n");
	scanf("%d", &J);
	printf("Ingrese el valor para K\n");
	scanf("%d", &K);
	printf("Ingrese el valor para L\n");
	scanf("%d", &L);
	
	if (I/J == K/L) {
		printf("El resultado de las divisiones es igual\n"); 
	}else{
		printf("No son iguales\n");
	}
	system("PAUSE");
}
