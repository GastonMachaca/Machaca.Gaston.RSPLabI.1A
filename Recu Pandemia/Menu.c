#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Menu.h"

int menu(void)
{
    int option;

    printf(" \n Menu:\n");
    printf(" \n  1. Cargar archivo.");
    printf(" \n  2. Imprimir Lista.");
    printf(" \n  3. Asignar Estadisticas.");
    printf(" \n  4. Filtrar por paises exitosos.");
    printf(" \n  5. Filtrar por paises en el horno.");
    printf(" \n  6. Ordenar por nivel de infectados.");
    printf(" \n  7. Mostrar mas castigado.");
    printf(" \n  8. Salir");

    printf("\n \n Ingrese una opcion: ");
    fflush(stdin);
    scanf("%d",&option);


    while(option<1 || option >8 || isalpha(option)!=0)
    {
        printf("\nERROR!!!\n Vuelva a ingresar una opcion: ");
        fflush(stdin);
        scanf("%d",&option);
    }

    return option;
}
