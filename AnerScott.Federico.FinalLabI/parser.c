
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "corredor.h"


int parser(FILE* pFile, LinkedList* lista)
{
    int todoOk = 1;
    eCorredor* pCorredor;
    char id[200];
    char apellido[200];

    char tipo[200];
    char promedio[200];
    char tiempo[200];




    if(pFile != NULL && lista != NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, apellido, tipo,promedio, tiempo);
        do
        {
            if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, apellido, tipo,promedio, tiempo) == 5)
            {
                pCorredor = corredor_newParametros(id, apellido, tipo,promedio, tiempo);

                if(pCorredor != NULL)//osea si pudo cargar
                {
                    ll_add(lista, pCorredor);
                    todoOk = 0;
                }
            }
            else
            {
                break;
            }

        }
        while(feof(pFile) == 0);
    }

    return todoOk;
}


int loadFromText(LinkedList* lista)
{
    int todoOk = 1;
    char path[128];

    printf("Ingrese el Nombre del archivo (autoscarrera)(sin extension): ");
    fflush(stdin);
    scanf("%s",path);

    strcat(path,".csv");



    FILE* f = fopen(path,"r");

    if(f != NULL)
    {
        if(!parser(f,lista))
        {
            todoOk = 0;
            printf("Se cargaron los datos\n");
        }
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
    }

    fclose(f);

    return todoOk;
}


int saveAsText(char* path , LinkedList* lista)
{
	int todoOk = 1;

	FILE* pFile;
	int auxId;
	char auxApellido[31];
	char auxTipo[31];
	float auxPromedio;
	float auxTiempo;
	eCorredor* auxBici;

	if(lista != NULL && path != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL)
		{
			todoOk = 0;
			fprintf(pFile, "id,apellido,tipo,promedio,tiempo\n");
			for(int i = 0; i < ll_len(lista); i++)
			{
				auxBici = (eCorredor*) ll_get(lista, i);
				if(!corredorGetId(auxBici,&auxId) &&
				   !corredorGetApellido(auxBici,auxApellido) &&
                   !corredorGetTipo(auxBici,auxTipo) &&
				   !corredorGetPromedio(auxBici,&auxPromedio)&&
                    !corredorGetTiempo(auxBici,&auxTiempo)

                    )

				{
					fprintf(pFile, "%d,%s,%s,%.2f,%.2f\n", auxId, auxApellido,auxTipo,auxPromedio,auxTiempo);
				}
			}
			fclose(pFile);
			printf("Se guardaron los datos en el archivo\n");
		}
	}

    return todoOk;
}

