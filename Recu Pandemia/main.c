#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "LinkedList.h"
#include "Parser.h"
#include "Pandemia.h"
#include "Menu.h"

int main()
{
    srand(time(NULL));

    int option;
    int flag=0;

    LinkedList* listaPaises = ll_newLinkedList();
    LinkedList* listaMejoresPaises = NULL;
    LinkedList* listaAlHorno = NULL;
    LinkedList* listaOrdenada = NULL;

    do
    {
        option = menu();

        switch(option)
        {
            case 1:
                if(flag== 0)
                {
                   cargarArchivo_Pandemia("Pandemia.csv",listaPaises);
                   flag=1;
                }
                else
                {
                    printf("\nYa se cargo los paises.");
                }
                break;
            case 2:
                listar_Paises(listaPaises); // LISTAR PAISES
                break;
            case 3:
                if(agregar_recu(listaPaises)==0 && agregar_infec(listaPaises)==0 && agregar_Muertos(listaPaises)==0) // ASIGNAR RECUPERADOS,INFECTADOS Y MUERTOS
                {
                    printf("Exito\n");
                }
                else
                {
                    printf("Error. No hay archivos registrados.\n");
                }
                break;
            case 4:
                if(flag == 1)
                {
                    printf("------------------------------------------------\n");
                    listaMejoresPaises =  ll_filter(listaPaises, filtrarMejoresPaises);
                    guardarComoTexto("MejoresPaises.csv", listaMejoresPaises);
                    printf("**** Los paises fueron filtrados por menos muertes y guardados en -MejoresPaises.csv- ****\n\n");
                    printf("------------------------------------------------\n");

                }
                else
                {
                    printf("Error. No hay archivos registrados.\n");
                }
            	break;
            case 5:
                if(flag == 1)
                {
                    printf("------------------------------------------------\n");
                    listaAlHorno =  ll_filter(listaPaises, filtrarPaisesAlHorno);
                    guardarComoTexto("PaisesAlHorno.csv", listaAlHorno);
                    printf("**** Los paises fueron filtrados donde la cantidad de infectados triplique a la de recuperados y guardados en -PaisesAlHorno.csv- ****\n\n");
                    printf("------------------------------------------------\n");

                }
                else
                {
                    printf("Error. No hay archivos registrados.\n");
                }

                // FILTRAR POR PAISES AL HORNO.
                break;
            case 6:
            if(!ll_isEmpty(listaPaises))
            {
                listaOrdenada= ll_clone(listaPaises);

                if(listaOrdenada!=NULL)
                {
                    ll_sort(listaOrdenada, ordenarXinfeccion, 0);
                }
                listar_Paises(listaOrdenada);
            }
            else
            {
                printf("Error. No hay archivos registrados.\n");
            }
            // ORDENAR POR INFECCION DESCENDENTE
            break;
            case 7:
            if(!ll_isEmpty(listaPaises))
            {
                mostrarMasCastigado(listaPaises);
            }
            else
            {
                printf("Error. No hay archivos registrados.\n");
            }
            break;
        }
        system("pause");
        system("cls");

    }while(option != 8);

    return 0;
}
