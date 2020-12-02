#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Pandemia.h"

ePais* nuevo_Pais()
{
    ePais* auxPais = NULL;

    auxPais = (ePais*) malloc (sizeof(ePais));

    return auxPais;
}

ePais* nuevo_PaisParametros(char* idStr,char* nombreStr,char* recuStr,char* infecStr,char* muertosStr)
{
    int flag=0;

    ePais* auxPais = NULL;

    auxPais = nuevo_Pais();

    if(auxPais != NULL)
	{
		if(setId_Pais(auxPais,atoi(idStr))==0)
		{
			if(set_nombrePais(auxPais,nombreStr)==0)
			{
				if(set_recuPais(auxPais,atoi(recuStr))==0)
				{
                    if(set_infecPais(auxPais,atoi(infecStr))==0)
                    {
                        if(set_muertosPais(auxPais,atoi(muertosStr))==0)
                        {
                            flag=1;
                        }
                    }
				}
			}
		}
		if(flag==0)
		{
			borrar_Pais(auxPais);
			auxPais=NULL;
		}
	}
	return auxPais;
}

int setId_Pais(ePais* this,int id)
{
    int error = -1;

    if( this != NULL && id > 0)
    {
        this->id = id;
        error = 0;
    }

    return error;
}

int pais_getId(ePais* this,int* id)
{
    int error = -1;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        error = 0;
    }

    return error;
}

int set_nombrePais(ePais* this,char* nombre)
{
    int error = -1;

    if( this != NULL && nombre != NULL)
    {
        if(validNombre_Pais(nombre,strlen(nombre)))
        {
            strcpy(this->nombre,nombre);
            error = 0;
        }
    }
    return error;
}

int pais_getNombre(ePais* this,char* nombre)
{
	int error = -1;
	if(this != NULL && nombre != NULL)
	{
		error = 0;
		//strncpy(nombre,this->nombre,strlen(nombre));
		strcpy(nombre,this->nombre);
	}
	return error;
}

int set_recuPais(ePais* this,int recuperados)
{
    int error = -1;

    if(this!=NULL && recuperados>=0)
    {
        this->recuperados=recuperados;
        error = 0;
    }

    return error;
}

int pais_getRecu(ePais* this,int* recuperados)
{
    int error = -1;

	if(this != NULL && recuperados != NULL)
	{
		error = 0;
		*recuperados = this->recuperados;
	}

	return error;
}

int set_infecPais(ePais* this,int infectados)
{
    int error = -1;

    if(this!=NULL && infectados>=0)
    {
        this->infectados=infectados;
        error = 0;
    }

    return error;
}

int pais_getInfec(ePais* this,int* infectados)
{
    int error = -1;

	if(this != NULL && infectados != NULL)
	{
		error = 0;
		*infectados = this->infectados;
	}

	return error;
}

int set_muertosPais(ePais* this,int muertos)
{
    int error = -1;

    if(this!=NULL && muertos>=0)
    {
        this->muertos=muertos;
        error = 0;
    }

    return error;
}

int pais_getMuertos(ePais* this,int* muertos)
{
    int error = -1;

	if(this != NULL && muertos != NULL)
	{
		error = 0;
		*muertos = this->muertos;
	}

	return error;
}

void borrar_Pais(ePais* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int validNombre_Pais(char* cadena,int longitud)
{
	int i=0;
	int error = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				error = 0;
				break;
			}
		}
	}
	return error;
}

int listar_Paises(LinkedList* pArrayListP)
{
    int error = -1;
    int i;
    int tam = ll_len(pArrayListP);

    ePais* auxPais;


    if(pArrayListP != NULL && ll_isEmpty(pArrayListP)== 0)
    {

        system("cls");
        printf("                         ***LISTA DE PAISES***                            \n\n");

        printf("\n     ID     |        NOMBRE        |     RECUPERADOS      |      INFECTADOS      |      MUERTOS  \n");
        printf("---------------------------------------------------------------------------------------------------------\n");


        for(i=0;i<tam;i++)
        {
            auxPais = (ePais*) ll_get(pArrayListP,i);
            if( auxPais != NULL)
            {
                ver_Pais( auxPais );
                error=1;
                auxPais = NULL;
            }
        }
    }
    else
    {
        printf("\n No hay publicaciones cargadas\n\n");
        error = 0;
    }

    return error;
}

void ver_Pais(ePais* pais)
{
    if(pais != NULL)
    {
        printf(" %10d | %20s | %20d | %20d | %20d | \n",pais->id,pais->nombre,pais->recuperados,pais->infectados,pais->muertos);
    }
}

int agregar_recu(LinkedList* pArrayListP)
{
    int error = -1;

    if(pArrayListP != NULL && ll_isEmpty(pArrayListP)== 0)
    {
        ll_map(pArrayListP,datosAleatoriosRecu);
        error=0;
    }
    else
    {
        error = 1;
    }

    return error;
}

int agregar_infec(LinkedList* pArrayListP)
{
    int error = -1;

    if(pArrayListP != NULL && ll_isEmpty(pArrayListP)== 0)
    {
        ll_map(pArrayListP,datosAleatoriosInfec);
        error=0;
    }
    else
    {
        error = 1;
    }

    return error;
}

int agregar_Muertos(LinkedList* pArrayListP)
{
    int error = -1;

    if(pArrayListP != NULL && ll_isEmpty(pArrayListP)== 0)
    {
        ll_map(pArrayListP,datosAleatoriosMuertos);
        error=0;
    }
    else
    {
        error = 1;
    }

    return error;
}


int datosAleatoriosRecu(void* aleatorios)
{
    int error = 0;
    int aleatorio;

    if(aleatorios != NULL)
    {
        ePais* pPais = (ePais*)aleatorios;
        aleatorio = rand()%((1000000 - 50000) + 1)+ 50000;
        pPais->recuperados = aleatorio;
        error = 1;
    }
    return error;
}

int datosAleatoriosInfec(void* aleatorios)
{
    int error = 0;
    int aleatorio;

    if(aleatorios != NULL)
    {
        ePais* pPais = (ePais*)aleatorios;
        aleatorio = rand()%((2000000 - 400000) + 1)+ 400000;
        pPais->infectados = aleatorio;
        error = 1;
    }
    return error;
}

int datosAleatoriosMuertos(void* aleatorios)
{
    int error = 0;
    int aleatorio;

    if(aleatorios != NULL)
    {
        ePais* pPais = (ePais*)aleatorios;
        aleatorio = rand()%((50000 - 1000) + 1)+ 1000;
        pPais->muertos = aleatorio;
        error = 1;
    }
    return error;
}


int filtrarMejoresPaises(void* paisExitoso)
{
    int auxReturn = 0;
    ePais* x;

    if(paisExitoso != NULL)
    {
        x = (ePais*) paisExitoso;
        if(x->muertos < 5000)
        {
            auxReturn = 1;
        }
    }

    return auxReturn;
}

int filtrarPaisesAlHorno(void* pais)
{
    int auxReturn = 0;
    ePais* x;

    if(pais != NULL)
    {
        x = (ePais*) pais;
        if(x->infectados >= (x->recuperados * 3))
        {
            auxReturn = 1;
        }
    }

    return auxReturn;
}

int ordenarXinfeccion(void* x, void* y)
{
    int cambio;
    int infeccionUno;
    int infeccionDos;

    pais_getInfec(x, &infeccionUno);
    pais_getInfec(y, &infeccionDos);

    if(infeccionUno > infeccionDos)
    {
        cambio = 1;
    }
    else if(infeccionUno < infeccionDos)
    {
        cambio = -1;
    }

    return cambio;
}

void mostrarMasCastigado(LinkedList* lista)
{
    ePais* auxPais;
    int auxMuertos;
    int maxMuertos = 0;
    int flag = 0;
    int i;

    if(lista != NULL)
    {

        for(i = 0; i < ll_len(lista); i++)
        {
            auxPais = (ePais*) ll_get(lista,i);
            pais_getMuertos(auxPais,&auxMuertos);
            if(auxMuertos > maxMuertos || !flag)
            {
                maxMuertos = auxMuertos;
                flag = 1;
            }
        }

        printf("Pais o paises mas castigados - Numero de muertos: %d\n",maxMuertos);
        printf("\n     ID     |        NOMBRE        |     RECUPERADOS      |      INFECTADOS      |      MUERTOS  \n");
        printf("---------------------------------------------------------------------------------------------------------\n");


        for(i = 0; i < ll_len(lista); i++)
        {
            auxPais = (ePais*) ll_get(lista,i);
            pais_getMuertos(auxPais,&auxMuertos);

            if(auxMuertos >= maxMuertos)
            {
                listarPais(lista,i);
            }
        }

    }

}

void listarPais(LinkedList* lista, int index)
{
    ePais* auxPais = (ePais*) nuevo_Pais();
    int id;
    char auxNombre[128];
    int auxRecu;
    int auxInfec;
    int auxMuertos;


    if(lista != NULL && index >=0)
    {
        auxPais = ll_get(lista, index);
        pais_getId(auxPais,&id);
        pais_getNombre(auxPais,auxNombre);
        pais_getRecu(auxPais,&auxRecu);
        pais_getInfec(auxPais,&auxInfec);
        pais_getMuertos(auxPais,&auxMuertos);


        printf(" %10d | %20s | %20d | %20d | %20d | \n", id, auxNombre, auxRecu, auxInfec,auxMuertos);

    }

}
