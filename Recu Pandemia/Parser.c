#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Pandemia.h"
#include "Parser.h"

int cargarArchivo_Pandemia(char* path , LinkedList* pArrayListP)
{
    int error = -1;

    FILE* pFile;

    if(path != NULL && pArrayListP != NULL)
    {
        pFile = fopen(path, "r");

        if(pFile != NULL)
        {
            parser_Pandemia(pFile, pArrayListP);
            error = 1;
            printf("Cargado con exito.\n");
        }
        fclose(pFile);
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
        error = 0;
    }

    return error;
}

int parser_Pandemia(FILE* pFile , LinkedList* pArrayListP)
{
    int error = -1;
    char auxId[128];
    char auxNombre[128];
    char auxRecu[128];
    char auxInfec[128];
    char auxMuertos[128];

    int r=0;

    ePais* auxPais;

    do
    {
        if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxRecu,auxInfec,auxMuertos)== 5)
        {
            auxPais = nuevo_PaisParametros(auxId,auxNombre,auxRecu,auxInfec,auxMuertos);

            if(auxPais != NULL)
            {
                r = ll_add(pArrayListP,auxPais);

                if(r>=ll_len(pArrayListP))
                {
                    break;
                }
            }

        }
        else
        {
            break;
        }


    }while(feof(pFile)== 0);

    fclose(pFile);

    error = r;

    return error;
}

int guardarComoTexto(char* path, LinkedList* pArrayListP)
{
	FILE* pFile;
	ePais* pais;

	int auxId;
	char auxNombre[128];
	int auxRecu;
	int auxInfec;
	int auxMuertos;

	int error = 0;
    int i;

	if(pArrayListP!=NULL && path!=NULL)
	{
		pFile= fopen(path, "w");
		if(pFile!=NULL)
		{
			error = 1;
			for(i = 0; i < ll_len(pArrayListP); i++)
			{
				pais = (ePais*)ll_get(pArrayListP, i);
                pais_getId(pais,&auxId);
                pais_getNombre(pais,auxNombre);
                pais_getRecu(pais,&auxRecu);
                pais_getInfec(pais,&auxInfec);
                pais_getMuertos(pais,&auxMuertos);

                fprintf(pFile, "%d,%s,%d,%d,%d\n", auxId, auxNombre, auxRecu, auxInfec,auxMuertos);
			}

			fclose(pFile);

			printf("Archivo guardado correctamente\n");
		}
		else if(error == 0)
        {
            printf("Error\n");
        }
	}

    return error;
}
