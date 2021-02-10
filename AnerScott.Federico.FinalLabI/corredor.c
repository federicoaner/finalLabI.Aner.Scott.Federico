#include "corredor.h"
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <string.h>


eCorredor* corredor_new()
{

    eCorredor* newCorredor = (eCorredor*) malloc(sizeof(eCorredor));

    if (newCorredor != NULL)
    {
        newCorredor->id_corredor = 0;
        strcpy(newCorredor->apellido," ");
        strcpy(newCorredor->tipo," ");
        newCorredor->promedio = 0;
        newCorredor->tiempo = 0;

    }

    return newCorredor;

}


eCorredor* corredor_newParametros(char* idStr,char* apellidoStr,char* tipoStr,char* promedioStr,char* tiempoStr)
{


    eCorredor* nuevoCorredor = corredor_new();

    if (nuevoCorredor != NULL)
    {

        corredorSetId(nuevoCorredor,atoi(idStr));
        corredorSetApellido(nuevoCorredor,apellidoStr);
        corredorSetTipo(nuevoCorredor,tipoStr);
        corredorSetPromedio(nuevoCorredor,atof(promedioStr));
        corredorSetTiempo(nuevoCorredor,atof(tiempoStr));

    }

    return nuevoCorredor;
}

int corredorSetId( eCorredor* corredor, int id)
{

    int todoOk=1;
    if( corredor!=NULL && id >= 0)
    {

        corredor->id_corredor=id;
        todoOk=0;
    }


    return todoOk;

}




int corredorGetId( eCorredor* corredor, int* id )
{

    int todoOk=1;

    if( corredor!=NULL && id != NULL)
    {

        *id=corredor->id_corredor;
        todoOk=0;
    }


    return todoOk;

}



int corredorSetApellido( eCorredor* corredor, char* apellido)
{


    int todoOk=1;
    if( corredor!=NULL && apellido!=NULL  )
    {

        strcpy(corredor->apellido,apellido);
        todoOk=0;
    }


    return todoOk;

}


int corredorGetApellido( eCorredor* corredor, char* apellido )
{
    int todoOk=1;

    if(corredor!=NULL && apellido !=NULL){

        strcpy(apellido, corredor->apellido);
        todoOk=0;

    }

    return todoOk;
}


int corredorSetTipo( eCorredor* corredor, char* tipo)
{


    int todoOk=1;
    if( corredor!=NULL && tipo!=NULL )
    {

        strcpy(corredor->tipo,tipo);
        todoOk=0;
    }


    return todoOk;

}


int corredorGetTipo( eCorredor* corredor, char* tipo )
{
    int todoOk=1;

    if(corredor!=NULL && tipo !=NULL){

        strcpy(tipo, corredor->tipo);
        todoOk=0;

    }

    return todoOk;
}


int corredorSetPromedio( eCorredor* corredor, float promedio)
{

    int todoOk=1;
    if( corredor!=NULL )
    {

        corredor->promedio=promedio;
        todoOk=0;
    }


    return todoOk;

}






int corredorGetPromedio( eCorredor* corredor, float* promedio)
{
    int todoOk=1;

    if(corredor!=NULL && promedio !=NULL){

        *promedio = corredor->promedio;
        todoOk=0;

    }

    return todoOk;
}


int corredorSetTiempo( eCorredor* corredor, float tiempo)
{

    int todoOk=1;
    if( corredor!=NULL && tiempo >= 0)
    {

        corredor->tiempo=tiempo;
        todoOk=0;
    }


    return todoOk;

}



int corredorGetTiempo( eCorredor* corredor, float* tiempo)
{
    int todoOk=1;

    if(corredor!=NULL && tiempo !=NULL){

        *tiempo=corredor->tiempo;
        todoOk=0;

    }

    return todoOk;
}



void mostrarCorredor (LinkedList* lista, int index)
{
    eCorredor* pCorredor = (eCorredor*) corredor_new();
    int id;
    char apellido[128];
    char tipo[20];
    float promedio;
    float tiempo;



    if(lista != NULL && index >=0)
    {
        pCorredor = ll_get(lista, index);

        corredorGetId(pCorredor,&id);
        corredorGetApellido(pCorredor,apellido);
       corredorGetTipo(pCorredor,tipo);
       corredorGetPromedio(pCorredor,&promedio);
        corredorGetTiempo(pCorredor,&tiempo);




        printf("%2d        %-10s       %-10s       %.2f           %.2f \n",id,apellido,tipo,promedio,tiempo );

    }

}


int mostrarCorredores(LinkedList* pArraylist)
{
    int todoOk = 1;

    eCorredor* pCorredor;


    if(pArraylist != NULL)
    {
       // system("cls");
        printf("\n  ID      Apellido          Tipo        Promedio           Tiempo    \n\n");
        for(int i = 0; i < ll_len(pArraylist); i++)
        {
            pCorredor = ll_get(pArraylist, i);
            if(pCorredor != NULL)
            {
                mostrarCorredor(pArraylist, i);
                todoOk = 0;
            }
        }
    }
    else if(todoOk == 1)
    {
        printf("No hay Corredores cargados en la lista\n");
    }

    return todoOk;
}


void* asignarTiempo(void* corredor)//Calcula numeros random y los settea en el campo.
{

   eCorredor* auxCorredor = NULL;
    float tiempo = rand()%(71)+50;

    if(corredor != NULL)
    {
        auxCorredor = (eCorredor*) corredor;

        corredorSetTiempo(auxCorredor,tiempo);
    }

    return auxCorredor;
}


int OrdenarPosiciones(void* a, void* b){

    int retorno=0;
    float tiempoP1;
    float tiempoP2;


    eCorredor* p1;
    eCorredor* p2;


    if(a!=NULL && b!=NULL){

        p1=(eCorredor*)a; //conversion
        p2=(eCorredor*)b;

    corredorGetTiempo(p1,&tiempoP1);
    corredorGetTiempo(p2,&tiempoP2);

    }


    if(tiempoP1 > tiempoP2 ){
        retorno=1;

    }else if (tiempoP1 < tiempoP2 ){
        retorno=-1;
    }




    return retorno;
}

