#include <stdio.h>
#include <stdlib.h>
main(){
	int N;
	int CodAvion, DuracionVuelo, CantPas, AlturaMax;
	int Dur1=0, Dur2=0, Dur3=0, Dur4=0;
	int Alt1=0, Alt2=0, Alt3=0, Alt4=0;
	int v1=0, v2=0, v3=0, v4=0;
	int Cant1 = 0, Cant2 = 0, Cant3 = 0, Cant4 = 0;
	
	int MayCantPas = 0;
	int MayCod;
	int MayAltura;
	
	printf("Ingrese la cantidad de vuelos registrados en el mes: \n");
	scanf("%d", &N);
	
	for(int i=0; i<N; i++){
		printf("Datos del vuelo %d: \n", i+1);
		printf("\tIngrese el codigo del avion: \n");
		scanf("%d", &CodAvion);
		system("CLS");
		printf("\tIngrese la duracion del vuelo en minutos: \n");
		scanf("%d", &DuracionVuelo);
		system("CLS");
		printf("\tIngrese la cantidad de pasajeros en el vuelo: \n");
		scanf("%d", &CantPas);
		system("CLS");
		printf("\tIngrese la altura maxima en el vuelo: \n");
		scanf("%d", &AlturaMax);
		system("CLS");
		if (CodAvion == 1){
			Dur1 = Dur1 + DuracionVuelo;	
			Alt1 = Alt1 + AlturaMax; 
			Cant1 += CantPas;
			v1++;
		}
		if (CodAvion == 2){
			Dur2 = Dur2 + DuracionVuelo;	
			Alt2 = Alt2 + AlturaMax; 
			Cant2 += CantPas;
			v2++;
		} 
		if (CodAvion == 3){
			Dur3 = Dur3 + DuracionVuelo;
			Alt3 = Alt3 + AlturaMax; 
			Cant3 += CantPas;
			v3++;
		} 
		if (CodAvion == 4){
			Dur4 = Dur4 + DuracionVuelo;
			Alt4 += AlturaMax; 
			Cant4 += CantPas;
			v4 = v4 + 1;
		} 
		
		if (CantPas > MayCantPas){
			MayCantPas = CantPas;
			MayCod = CodAvion;
			MayAltura = AlturaMax;
		}
		
	}
	
	printf("Para el avion cod 1 la duracion en horas y minutos es de %d hs y %d min\n", Dur1/60, Dur1%60);
	printf("Para el avion cod 2 la duracion en horas y minutos es de %d hs y %d min\n", Dur2/60, Dur2%60);
	printf("Para el avion cod 3 la duracion en horas y minutos es de %d hs y %d min\n", Dur3/60, Dur3%60);
	printf("Para el avion cod 4 la duracion en horas y minutos es de %d hs y %d min\n", Dur4/60, Dur4%60);
	
	printf("Para el avion cod 1 el promedio de altura es %d\n", Alt1/v1);
	printf("Para el avion cod 2 el promedio de altura es %d\n", Alt2/v2);
	printf("Para el avion cod 3 el promedio de altura es %d\n", Alt3/v3);
	printf("Para el avion cod 4 el promedio de altura es %d\n", Alt4/v4);	
	
	printf("El avion con mayor cantidad de pasajeros en un vuelo es el %d y su altura fue de %d\n", MayCod, MayAltura);
	
	printf("Para el avion cod 1 la cantidad de pasajeros total es %d\n", Cant1);
	printf("Para el avion cod 2 la cantidad de pasajeros total es %d\n", Cant2);
	printf("Para el avion cod 3 la cantidad de pasajeros total es %d\n", Cant3);
	printf("Para el avion cod 4 la cantidad de pasajeros total es %d\n", Cant4);
	system("PAUSE");
}
