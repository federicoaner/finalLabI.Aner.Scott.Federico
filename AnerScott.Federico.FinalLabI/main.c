#include "corredor.h"
#include "parser.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "validacion.h"
#include "LinkedList.h"


int menu();



int main()
{
//    srand (time(NULL));

    char seguir='S';
    char confirma;


    LinkedList* lista = ll_newLinkedList();
    //LinkedList* listaMap= ll_newLinkedList();
    //LinkedList* listaTiempos= ll_newLinkedList();


    if(lista==NULL)
    {

        printf("Hubo un Problema para conseguir Memoria!!!\n");
        exit(EXIT_FAILURE);

    }





    do
    {
        switch (menu())
        {

        case 1:

            loadFromText(lista);

            break;

        case 2:

           mostrarCorredores(lista);

            break;

        case 3:
             if(ll_map(lista,asignarTiempo)){
                printf("Se asignaron los tiempos\n");
             }
            break;


        case 4:

            ll_sort(lista,OrdenarPosiciones,1);
            //mostrarCorredores(lista);

            saveAsText("posiciones.csv",lista);
            break;





        case 7:

            /*printf("Confirma Salida?: ");
            fflush(stdin);
            scanf("%c", &confirma);*/

            getChar(&confirma,"Confirme salida(s/n): ","Error. Confirme salida (s/n): ");

            if(confirma=='S')
            {
                seguir='N';
            }

            break;
        }

        system("pause");

    }
    while (seguir=='S');





    ll_deleteLinkedList(lista);

    return 0;
}


int menu()
{

    int opcion;
    system("cls");
    printf("1-Cargar Archivo\n");
    printf("2- Imprimir lista\n");
    printf("3- Asignar Tiempos\n");
    printf("4- Guardar Posiciones\n");

    printf("7-Salir \n");

/*
    printf("Ingrese Opcion:");
    fflush(stdin);
    scanf("%d",&opcion);
    */

    utn_getEntero(&opcion,3,"Ingrese opcion: ","error ingrese opcion valida\n",1,7);



    return opcion;
}

