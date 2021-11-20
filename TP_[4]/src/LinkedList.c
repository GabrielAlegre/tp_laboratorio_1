#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"

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
    LinkedList* this= NULL;

    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
        this->size =0;
        this-> pFirstNode=NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        returnAux=this->size;
    }

    return returnAux;
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
    Node* pNodo = NULL;

    if(this!=NULL && nodeIndex>=0 && nodeIndex < ll_len(this))
    {
        pNodo = this->pFirstNode;
        for(int i=nodeIndex; i>0;  i--)
        {
            pNodo = pNodo->pNextNode;
        }
    }

    return pNodo;
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
        /*
    if(this!=NULL)
    {


    }
    */

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
static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
    int returnAux = -1;
    Node* nuevoNodo = NULL;
    Node* nodoAnterior = NULL;


    if(this!=NULL && nodeIndex>=0 && nodeIndex <=ll_len(this))
    {
        nuevoNodo = (Node*) malloc(sizeof(Node));
        if(nuevoNodo!=NULL)
        {
            nuevoNodo->pElement = pElement;
            nuevoNodo->pNextNode = getNode(this, nodeIndex);

            if(nodeIndex==0)
            {
                this->pFirstNode = nuevoNodo;
            }
            else
            {
                nodoAnterior = getNode (this, nodeIndex-1);
                nodoAnterior->pNextNode = nuevoNodo;
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
        return addNode(this, ll_len(this), pElement);
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada // permite obtener un elemento de la lista
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
    Node* pNodo = NULL;

    if(this!=NULL && index>=0 && index < ll_len(this))
    {
        pNodo=getNode(this, index);
        if(pNodo!=NULL)
        {
            returnAux=pNodo->pElement;
        }
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
    Node* pNodo = NULL;

    if(this!=NULL && index>=0 && index < ll_len(this))
    {
        pNodo=getNode(this, index);
        if(pNodo!=NULL)
        {
            pNodo->pElement = pElement;

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
	Node* nodoAnteriorAlDeEliminar=NULL;
    Node* nodoParaEliminar = NULL;

    if(this!=NULL && index>=0 && index< ll_len(this))
    {
        nodoParaEliminar=getNode(this,index);

        if(nodoParaEliminar != NULL)
        {
            if(index==0)
            {
                this->pFirstNode=nodoParaEliminar->pNextNode;
                free(nodoParaEliminar);
                this->size--;
                returnAux=0;
            }
            else
            {
                nodoAnteriorAlDeEliminar=getNode(this,index-1);

                if(nodoAnteriorAlDeEliminar!=NULL)
                {
                    //si eliminio el nodo 5 el nodo anterior es el 4 y el siguiente es el 6 entonces el nodo anterior (indice 4)tiene que apuntar al 6 que pasaria al ser el nuevo 5
                    //es decir, la direccion de memoria que va a contener el nodo anterior va a ser la misma direcion de memoria que contenga el nodo a eliminar en su pNextNode
                    nodoAnteriorAlDeEliminar->pNextNode = nodoParaEliminar->pNextNode;
                    free(nodoParaEliminar);
                    this->size--;
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
    int returnAux = -1;


    if(this!=NULL)
    {
    	returnAux=0;
        while(ll_len(this))
        {
            returnAux = ll_remove(this, 0);

            if(returnAux)
            {
                break;
            }
        }
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

    if(this!=NULL)
    {
        //solo podemos eliminar la locomotora si se eliminaron correctamente los vagones
        if(!ll_clear(this))
        {
            free(this);
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
    int tam = ll_len(this);

    if(this!=NULL)
    {
        for(int i=0; i<tam;  i++)
        {
           if(ll_get(this, i) == pElement)
           {
               returnAux=i;

               break;
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
    int tam = ll_len(this);

    if(this!=NULL)
    {
        if(tam==0)
       {
           returnAux=1;

       }
       else if (tam>0)
       {
           returnAux=0;
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
    return addNode(this, index, pElement);;
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

    if(this!=NULL && index < ll_len(this) && index>=0)
    {
        returnAux = ll_get (this, index);
        ll_remove(this, index);
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
//    Node* nodoActual=NULL;
   //int estaElElemento=0;


    if(this!=NULL)
    {
        returnAux = 0;
        if(ll_indexOf(this, pElement) != -1)
        {
            returnAux = 1;
        }
    }

    /*
    if (this!=NULL)
    {
    	for(int i=0 ;i<ll_len(this); i++)
        {
    		nodoActual=getNode(this,i);
    		if(nodoActual!=NULL)
            {
                if(nodoActual->pElement==pElement)
                {
                    estaElElemento=1;

                }
            }
    	}

    	if(estaElElemento)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }
    }
    */
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

    //porque si this 2 es mayor a this es imposible que this contenga todos los elementos de this 2
    int returnAux = -1;
    int tam=ll_len(this2);

    if (this!=NULL && this2!=NULL)
    {
        //soy optimista y ya declaro que todos los elemntos de ls this 2 va a estar en this
        returnAux=1;

        for(int i = 0; i<tam; i++)
        {
            //aca verifico si los elementos (consiguendolos con ll_get(this2, i)) de la this 2 en cada indice esten contenidos en la this, el primero que no este ya verifica que no estan todos los elemntos de la this2 en la this entonces breakeo
            if(ll_contains(this, ll_get(this2, i))==0)
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
                         //to no esta incluido
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    if (this!=NULL && from>=0 && to>=0 && to>from && to<=ll_len(this))
    {
    	cloneArray=ll_newLinkedList();

        if(cloneArray!=NULL)
        {
            for(int i=from; i<to; i++)
            {
                ll_add(cloneArray, ll_get(this,i));
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
    return ll_subList(this, 0, ll_len(this));
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio 1 si es mayor// -1 si es menor
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* cosaUno;
    void* cosaDos;
    int len=ll_len(this);

	if (this!=NULL && pFunc!=NULL && order>=0 && order<=1)
    {
		for (int i=0; i<len-1; i++)
        {
            //profe el proyecto que tenemos que hacer en el tp4 para utilizar todas las funciones de la linkedlist tiene que tener controller, parser y eso? o ya con utilizar las funciones en el main alcanza?

			for (int j=i+1; j<len; j++)
            {
                cosaUno=ll_get(this,i);
				cosaDos=ll_get(this,j);

				//si el orden es 1 es xq es ascendernte (el menor primero) y si la funcion retorna 1 es xq el primer elemnto es mayor al segundo
				// por lo que se debe ordenar, es decir lo que esta en la cosa uno debe ir en la cosa dos
				if (pFunc(cosaUno,cosaDos)==1 && order==1)
                {
					ll_set(this,i,cosaDos); //lo que esta en el coso dos va al nodo uno
					ll_set(this,j,cosaUno);
				}
				else
                {
                    if (pFunc(cosaUno,cosaDos)==-1 && order==0)
                    {
                        ll_set(this,i,cosaDos);
                        ll_set(this,j,cosaUno);
                    }

				}
			}
		}
		 returnAux=0;
	}
    return returnAux;

}

