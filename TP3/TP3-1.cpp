#include <stdio.h>
#include <stdlib.h>

main(){
  int v1, v2, v3;
  float promedio;
  
  printf("Ingrese el primer valor entero y positivo\n");
  scanf("%d", &v1);
  printf("Ingrese el segundo valor entero y positivo\n");
  scanf("%d", &v2);
  printf("Ingrese el tercer valor entero y positivo\n");
  scanf("%d", &v3);
  
  if(v1>=1 && v1<=10 &&
     v2>=1 && v2<=10 &&
	 v3>=1 && v3<=10){
	 
	 promedio = ((float)v1+v2+v3)/3;
	 printf("El promedio del alumno es: %.2f\n", promedio);
	 
	 if (promedio >= 6){
	 	printf("El alumno aprobo\n");
	 }else{
	 	printf("El alumno no aprobo el anio y debera rendir en diciembre\n");
	 }
	 
  }
  else{
  	printf("Error en la carga de las notas!\n");
  }
  system("PAUSE");
}


