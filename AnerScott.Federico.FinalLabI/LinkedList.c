#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* nuevaLista= NULL;

    nuevaLista=(LinkedList*)malloc(sizeof(LinkedList));


    if(nuevaLista!=NULL)
    {

        nuevaLista->size=0; //Inizializo los campos a 0 y a NULL
        nuevaLista->pFirstNode=NULL;
    }

    return nuevaLista;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int cantidad = -1;

    if(this != NULL )
    {

        cantidad = this->size;
    }


    return cantidad;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* nodo=NULL;

    if(this != NULL && nodeIndex>=0 &&  nodeIndex < ll_len(this))
    {

        nodo=this->pFirstNode;

        while(nodeIndex > 0 )
        {

            nodo=nodo->pNextNode;
            nodeIndex--;
        }

    }

    return nodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* nuevoNodo=NULL;
    Node* anterior= NULL;

    if(this!= NULL && nodeIndex>=0 && nodeIndex <= ll_len(this) )
    {
        nuevoNodo=(Node*)malloc(sizeof(Node));

        if(nuevoNodo!=NULL)
        {

            nuevoNodo->pElement=pElement; //le asigno la carga
            nuevoNodo->pNextNode=NULL; //cargo el nodo en null por si va al final del linked

            if(nodeIndex==0)
            {

                nuevoNodo->pNextNode = this->pFirstNode; //engancho a locomotora
                this->pFirstNode =nuevoNodo; // locomotora nos aputa a nosotros

            }

            else

            {

                anterior=getNode(this,nodeIndex - 1);
                nuevoNodo->pNextNode=anterior->pNextNode;
                anterior->pNextNode=nuevoNodo;
            }

            this->size++;
            returnAux=0;
        }

    }


    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{

    int indice;

    indice=ll_len(this);  //adnode tiene el mismo tipo de retorno -1 / 0

    return addNode(this,indice,pElement);
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* auxNode = NULL ;


    auxNode = getNode(this,index);

    if(auxNode!=NULL)
    {
        returnAux=auxNode->pElement;
    }


    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* auxNode;


    if(this!=NULL)
    {

        auxNode=getNode(this,index);
        if(auxNode!=NULL)
        {
            auxNode->pElement=pElement;
            returnAux=0;
        }

    }


    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* actual;
    Node* anterior;


    if(this != NULL && index >=0 && index < ll_len(this))
    {

        actual= getNode(this,index);

        if(actual!=NULL)
        {

            if(index == 0)
            {
                this->pFirstNode = actual->pNextNode; // hago q la locomotora apunte al nodo sig al nodo actual
                this->size--;
                free(actual);
                returnAux=0;

            }


            else
            {
                anterior = getNode(this, index -1);

                if(anterior !=NULL )
                {
                    anterior->pNextNode= actual->pNextNode;
                    this->size--;
                    free(actual);
                    returnAux=0;
                }

            }
        }
    }


    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;  //clear es sacar todos los vagones

    if(this!=NULL)
    {

        while(ll_len(this) != 0)  //mientras el tren no este vacio
        {

            ll_remove(this,0); //remuevo el bagon cero (loop hasta vaciar)

        }
        returnAux=0;

    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if( this!=NULL)
    {
        if(!ll_clear(this))  //borro cada vagon si esta ok ->
        {

            free(this); //libero la Linkedlist
            returnAux=0;

        }

    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* auxnode;
    int tam;

    if(this!=NULL)
    {

        tam=ll_len(this);
        //   while(ll_len(this) !=0 && auxnode->pElement == pElement){

        for(int i=0; i<tam; i++)
        {
            auxnode=getNode(this,i);

            if(auxnode!=NULL && auxnode->pElement== pElement)
            {

                returnAux=i;
                break; //freno para devolver la primer ocurrencia

            }

        }

    }


    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {

        if(ll_len(this))
        {
            returnAux=0;
        }

        else
        {
            returnAux=1;

        }

    }



    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    return addNode(this,index,pElement);
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this!= NULL && index >= 0 && index < ll_len(this))
    {
        //auxNode=getNode(this,index);
        returnAux=ll_get(this,index);
        if(ll_remove(this,index) == -1)
        {
            returnAux=NULL; // si no lo pudiste remover devuelvo null
        }
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;


    if(this!=NULL)
    {
        returnAux=0;

        if(ll_indexOf(this,pElement)>=0)
        {

            returnAux=1;

        }

    }


    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int tam;
    void* pElemnt;

    if(this!=NULL && this2!=NULL)
    {
        tam=ll_len(this2);

        returnAux=1; // la cargo positiva

        for (int i=0; i<tam ; i++ ) //Recorro lista 2
        {

            pElemnt=ll_get(this2,i);

            if(!ll_contains(this,pElemnt))  // si ya hay 1 q no esta devuelve 0
            {

                returnAux=0;
                break;
            }

        }

    }


    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    if( !(this== NULL || from < 0 || from > ll_len(this) || to <= from  || to > ll_len(this) ))
    {

        cloneArray=ll_newLinkedList();

        if(cloneArray!=NULL)
        {

            for (int i=from; i < to ; i++ )
            {

                ll_add(cloneArray,ll_get(this,i));
            }

        }

    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this!=NULL)
    {

        cloneArray=ll_subList(this,0,ll_len(this));

    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    void* auxElement;
    int tam;


    if(this != NULL && pFunc !=NULL && order >=0 && order <=1)
    {

        tam=ll_len(this);

        for (int i= 0; i<tam - 1 ; i++ )
        {

            for (int j= i+1; j<tam ; j++ )
            {

                if(pFunc (ll_get(this,i), ll_get(this,j)) > 0 && order == 1)    //Criterio de ordenamiento
                {
                    //paso los pElement de cada indice para swapearlos

                    auxElement=ll_get(this,i);
                    ll_set(this,i,ll_get(this,j));
                    ll_set(this,j,auxElement);

                }

                else if (pFunc (ll_get(this,i), ll_get(this,j)) < 0 && order == 0)
                {

                    auxElement=ll_get(this,i);
                    ll_set(this,i,ll_get(this,j));
                    ll_set(this,j,auxElement);

                }
            }

        }


        returnAux=0;

    }


    return returnAux;

}

//Filter llama al callback y le pasa cada uno de los elementos de la lista
//Y si pfunc devuelve 1 a ese elemento lo carga en la nueva lista
//Funcion devuelve un linkedlist Filtradro
//3:22 ver explicacion


LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{

    LinkedList* listaFiltrada = NULL;
    void* auxElement=NULL;

    if(this !=NULL && pFunc !=NULL)
    {

        listaFiltrada=ll_newLinkedList();

        if(listaFiltrada!=NULL)
        {

            for(int i = 0; i < ll_len(this); i++)
            {
                auxElement=ll_get(this,i);
                if(pFunc(auxElement) )
                {

                    ll_add(listaFiltrada, auxElement);

                }
            }
        }
    }

    return listaFiltrada;
}



// Asigna datos que se le pasen por parametro en una lista y retorna otra con esos datos.
LinkedList* ll_map(LinkedList* this, void* (*pFunc)(void*))//Devuelve lista mapeada.
{
	void* pElement;
	LinkedList* listaMapeada = NULL;
	int tam;

    if(this != NULL && pFunc != NULL)
    {

        listaMapeada = ll_newLinkedList();

        if(listaMapeada != NULL)
        {
            tam = ll_len(this);    //Tamanio de la lista original.

            for(int i = 0; i < tam; i++)//Recorre la lista original.
            {
                pElement = ll_get(this, i); //Obtengo cada elemento.
                pElement = pFunc(pElement);//Settea los datos random, entonces:
                if(pElement != NULL)
                {
                    ll_add(listaMapeada, pElement);  //Se los agrega a la nueva listaMap.
                }

            }
        }

    }
    return listaMapeada;
}


//Ordena los elementos de la lista utilizando las funciones criterio recibidas como parametro, primero ordena por la primera funcion
//Luego si el resultado de esa funcion es 0 ordena por la segunda funcion.
int ll_tieBreakerSort(LinkedList* this, int (*pFunc1)(void*,void*), int (*pFunc2)(void*,void*), int order)
{
    int returnAux =-1;
    int tam;
    void* pElement1;//Se deben ordenar los elementos de la lista. Hay que obtenerlos y se guardan en evar tipo void*
    void* pElement2;
    void* auxElement;

    tam = ll_len(this);
    if(this != NULL && pFunc1 != NULL && (order == 0 || order == 1)&& tam > 0)
    {

        for(int i = 0; i < tam-1; i++)
        {

            for(int j = i+1; j < tam; j++)
            {
                pElement1 = ll_get(this,i);//Obtiene un elemento en el indice especificado.
                pElement2 = ll_get(this,j);//Obtiene un elemento en el indice especificado.


                //Si el elemento 1 es mas grande que elemento 2 , y el orden es ascendente, los swapeo O Si el elemento 1 es mas chico que elelemento 2, y el orden es descendente, los swapeo.

                if((pFunc1(pElement1, pElement2) > 0 && order == 1) || (pFunc1(pElement1, pElement2) < 0 && order == 0))
                 {
                     auxElement= pElement1;
                     ll_set(this,i,pElement2); //copio el elemento 2 en el lugar del 1.
                     ll_set(this,j,auxElement); //copio el elemento 1 en el lugar del 2.
                 }
                 //Si los elementos son iguales, desempata y ordena con la segunda funcion
                else if(pFunc1(pElement1, pElement2) == 0)
                {
                    	if(pFunc2(pElement1,pElement2)>0)
                        {
                            auxElement= pElement1;
                            ll_set(this,i,pElement2);
                            ll_set(this,j,auxElement);
                        }
                }

            }
        }
        returnAux = 0;
    }

    return returnAux;

}
