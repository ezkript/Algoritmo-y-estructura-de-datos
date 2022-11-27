#include <stdio.h>
#include <stdlib.h>
main(void){
    int nro1=0,nro2=0,nro3=0,operacion=0;
    printf("\nIngresar primer numero: ");
    scanf("%i",&nro1);
    printf("\nIngresar segundo numero: ");
    scanf("%i",&nro2);
    printf("\nIngresar tercer numero: ");
    scanf("%i",&nro3);
    if(nro1==nro2){
        operacion=nro1+nro2+nro3;
        printf("\n\nNumeros: %i, %i, %i\nOperacion: Suma de los 3 numeros\nResultado: %i\n\n",nro1,nro2,nro3,operacion);
    }
    if(nro1<nro3){
        operacion=nro1*nro2;
        printf("\n\nNumeros: %i, %i, %i\nOperacion: producto de %i por %i\nResultado: %i\n\n",nro1,nro2,nro3,nro1,nro2,operacion);
    }
    if(nro2>nro1){
        if (nro1==0)
        {
            printf("\n\nNumeros: %i, %i, %i\nOperacion: division de %i con %i\nResultado: La division en 0 esta indefinida.\n\n",nro1,nro2,nro3,nro2,nro1);
        } else {
            operacion=nro2/nro1;
            printf("\n\nNumeros: %i, %i, %i\nOperacion: division de %i con %i\nResultado: %i\n\n",nro1,nro2,nro3,nro2,nro1,operacion);
        }
        
    }
    system("PAUSE");
}