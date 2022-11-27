#include <stdlib.h>
#include <stdio.h>

float Porcentaje(int total, int x);

main(){

    int id,prod,prod1=0,prod2=0,prod3=0,fallas,fallas1=0,fallas2=0,fallas3=0;
    int TotalProducido=0,TotalFallas=0,tp1=0,tp2=0,tp3=0,tf1=0,tf2=0,tf3=0;
    float desechos;

    printf("Bienvenido. Codigos:\n1) (Maquina 1)\n2) (Maquina 2)\n3) (Maquina 3)\n0) Salir.\n");
    
    do {
        printf("\nIngresar el codigo: ");
        scanf("%i",&id);
        
        switch (id)
        {
        case 0:
            break;

        case 1:
            printf("Cantidad de envases que produjo en la semana: ");
            scanf("%i", &prod);
            prod1=prod1+prod;

            printf("Cantidad de envase que poseen falla: ");
            scanf("%i", &fallas);
            fallas1=fallas1+fallas;

            TotalProducido=TotalProducido+prod1;
            TotalFallas=TotalFallas+fallas1;
            tp1=tp1+prod1;
            tf1=tf1+fallas1;
            prod1=0;
            fallas1=0;
            break;

        case 2:
            printf("Cantidad de envases que produjo en la semana: ");
            scanf("%i", &prod);
            prod2=prod2+prod;

            printf("Cantidad de envase que poseen falla: ");
            scanf("%i", &fallas);
            fallas2=fallas2+fallas;

            TotalProducido=TotalProducido+prod2;
            TotalFallas=TotalFallas+fallas2;
            tp2=tp2+prod2;
            tf2=tf2+fallas2;
            prod2=0;
            fallas2=0;
            break;

        case 3:
            printf("Cantidad de envases que produjo en la semana: ");
            scanf("%i", &prod);
            prod3=prod3+prod;

            printf("Cantidad de envase que poseen falla: ");
            scanf("%i", &fallas);
            fallas3=fallas3+fallas;

            TotalProducido=TotalProducido+prod3;
            TotalFallas=TotalFallas+fallas3;
            tp3=tp3+prod3;
            tf3=tf3+fallas3;
            prod3=0;
            fallas3=0;
            break;

        default:
            printf("La maquina no pudo ser identificada.\n");
            break;
        }

    } while(id!=0);
    system("CLS");
    desechos=Porcentaje(TotalProducido, TotalFallas);
    printf("\nCodigo de maquina: 1\nCantidad de envases producidos: %i\nCantidad de envases desechados: %i\n",tp1, tf1);
    printf("------------------------------------------------------------------------------------------------\n");
    printf("Codigo de maquina: 2\nCantidad de envases producidos: %i\nCantidad de envases desechados: %i\n",tp2, tf2);
    printf("------------------------------------------------------------------------------------------------\n");
    printf("Codigo de maquina: 3\nCantidad de envases producidos: %i\nCantidad de envases desechados: %i\n",tp3, tf3);
    printf("------------------------------------------------------------------------------------------------\n");

    printf("Total de envases producidos: %i\nPorcentaje de envases desechados: %.2f% (%i)\n\n",TotalProducido,desechos, TotalFallas);
    system("PAUSE");
}

float Porcentaje(int total, int x){
    float calculo;
    calculo=(float) (x*100)/total;
    return calculo;
}