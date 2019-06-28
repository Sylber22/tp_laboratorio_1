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
    LinkedList* this;
    this = (LinkedList*)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
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
        returnAux= this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o
 (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
      Node* pNode = NULL;

    if((this!=NULL) && (nodeIndex>=0) && (nodeIndex < ll_len(this)))
    {
        pNode = this->pFirstNode;
        for(int i=0; i<nodeIndex; i++)
        {
            pNode = pNode->pNextNode;
        }
    }
    return pNode;

}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o
 (si el indice es menor a 0 o mayor al len de la lista)
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
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o
 (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pBufferNode= (Node*)malloc(sizeof(Node));
    Node* pBufferNodeAnterior =NULL;
    if((this!=NULL) && (nodeIndex>=0) && (nodeIndex <=ll_len(this)))
    {
        pBufferNode->pElement= pElement;
         if(nodeIndex==0)//POSICION 0
        {
            pBufferNode->pNextNode = this->pFirstNode;//GUARDO EL PUNTERO DEL PRIMER NODO AL SIGUIENTE NODO
            this->pFirstNode = pBufferNode;//EL QUE ERA EL PRIMER NODO AHORA ES EL 2

        }
        else
        {
              pBufferNodeAnterior = getNode(this, nodeIndex-1);// TOMA EL NODO ANTERIOR
              pBufferNode->pNextNode = pBufferNodeAnterior->pNextNode;//LE ASIGNA EL PUNTERO SIGUIENTE AL NODO ANTERIOR
              pBufferNodeAnterior->pNextNode= pBufferNode;

        }
         returnAux=0;
        this->size++;
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
    int returnAux = -1;
    if(this!=NULL)
    {
        addNode(this,ll_len(this),pElement);
        returnAux=0;
    }
    return returnAux;
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
    Node* pBufferNode= getNode(this, index);
     if((this!=NULL) && (index>=0) && (index <ll_len(this)))
     {
       returnAux = pBufferNode->pElement;
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
    Node* pBufferNode = NULL;

    if((this!=NULL) && (index>=0) && (index < ll_len(this)))
    {
        pBufferNode=getNode(this, index);
        pBufferNode->pElement= pElement;
        returnAux=0;
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
    Node* pBufferNode= NULL;
    Node* pBufferNodeNext= NULL;
        if((this!=NULL) && (index>=0) && (index <ll_len(this)))
        {
            if(index==0)
            {
               pBufferNode = getNode(this, index);
                this->pFirstNode = pBufferNode->pNextNode;
                free(pBufferNode);
                 returnAux=0;
                 this->size--;
            }
            else
            {
                pBufferNode = getNode(this,(index-1));//TOMO EL NODO ANTERIOR
                pBufferNodeNext = getNode(this,index);//NODO SIGUIENTE
                pBufferNode->pNextNode = pBufferNodeNext->pNextNode;//CARGO LA DIRECCION DEL SIGUIENTE EN EL PRIMER NODO
                free(pBufferNodeNext);
                this->size--;
                 returnAux=0;
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
            for(int i=0; i<ll_len(this); i++)
            {
               ll_remove(this, i);
                returnAux=0;
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
        for(int i=0; i<ll_len(this); i++)
            {
               ll_clear(this);
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
    Node* pBufferNode = NULL;
    if(this != NULL)
    {
        for(int i=0; i<ll_len(this); i++)
        {
            pBufferNode=getNode(this, i);
            if(pBufferNode->pElement == pElement)
            {
                returnAux = i;
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
    if(this != NULL)
    {
        if(this->size > 0)
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
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
    int returnAux = -1;
    if((this != NULL) && (index>=0) && (index<=ll_len(this)))
    {
        addNode(this, index, pElement);
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)//QUEDARNOS CON EL ELEMENTO Y REMOVE RETORN EL ELEMENTO
{
    void* returnAux = NULL;
    if((this != NULL) && (index>=0) && (index<=ll_len(this)))
    {
        returnAux=ll_get(this, index);
        if(returnAux!=NULL)
        {
           ll_remove(this, index);
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
int ll_contains(LinkedList* this, void* pElement)//INDEXOF
{
    int returnAux = -1;
    int indexAux;
     if(this != NULL)
     {
         indexAux=ll_indexOf(this, pElement);// si falla retorna -1
         if(indexAux!=-1)
         {
           returnAux=1;
         }
         else// si no contiene el elemento
            {
                returnAux=0;
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
int ll_containsAll(LinkedList* this,LinkedList* this2)//FOR GET IF SI NO ESTA SALGO
{
    int returnAux = -1;
    Node* pBufferNode=NULL;
    int pBufferContains;
    if((this != NULL) && (this2 !=NULL))
   {
       returnAux=1;//SI CONTIENE EL ELEMENTO SIGUE ITERANDO
        for(int i=0; i<ll_len(this2); i++)
        {
            pBufferNode=ll_get(this,i);
            pBufferContains=ll_contains(this2, pBufferNode);// SI NO CONTIENE EL ELEMENTO RETORNA 0
            if (pBufferContains== 0)
            {
                returnAux= 0;
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
LinkedList* ll_subList(LinkedList* this,int from,int to)//NEW FOR GET ADD
{
    LinkedList* cloneArray = NULL;
    Node* pBufferNode= NULL;
    if((this != NULL)&& (from>=0)&&(from<ll_len(this))&& (to>=0)&&(to<=ll_len(this)))//RANGOS
      {
          cloneArray = ll_newLinkedList();
          for(int i=0; i<ll_len(this); i++)
          {
               pBufferNode=ll_get(this,i);
               ll_add(cloneArray,pBufferNode);
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
    //cloneArray = ll_newLinkedList(); ACA NO
    Node* pBufferNode= NULL;
    if(this != NULL)
      {
          cloneArray = ll_newLinkedList();//ACA SI--TENGO QUE VERIFICAR QUE THIS NO SEA NULL ANTES DE CREAR LA PROXIMA LISTA
          for(int i=0; i<ll_len(this); i++)
          {
               pBufferNode=ll_get(this,i);
               ll_add(cloneArray,pBufferNode );
          }
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
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* pElement1=NULL;
    void* pElement2=NULL;
    void* pBufferElement=NULL;
    if((this!=NULL)&&(pFunc!=NULL)&&(order==1||order==0))
    {

        for (int i = 0; i < ll_len(this)-1; i++)
        {
            pElement1=ll_get(this,i);
            for (int j = i+1; j < ll_len(this); j++)
            {
               pElement2=ll_get(this,j);
               if(!order)
               {
                   if(pFunc(pElement1,pElement2)==-1)
                   {
                    //Swap
                    pBufferElement=pElement2;
                    pElement2=pElement1;
                    pElement1=pBufferElement;
                    //Guardo en This
                    if(!ll_set(this, i,pElement1))
                    {
                         if(!ll_set(this,j, pElement2))
                         {
                               returnAux=0;
                         }
                    }
                   }
                }//ORDER==0
               else if(order==1)
                {
                     if(pFunc(pElement1,pElement2)==1)
                     {
                        pBufferElement=pElement1;
                        pElement1=pElement2;
                        pElement2=pBufferElement;
                        if(!ll_set(this, i, pElement2))
                        {
                             if(!ll_set(this, j, pElement1))
                             {
                                   returnAux=0;
                             }
                        }
                    }
                }//ORDER ==1

            }//FOR J
        }//FOR I
    }
    return returnAux;

}


/** \brief recibe la lista y filtra los elementos
 *
 * \param lista
 * \param puntero a funcion parametro
 * \return lista filtrada
 *
 */

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* listFilter=NULL;
    void* pBufferElement=NULL;
    if((this!=NULL)&&(pFunc!=NULL))
    {
        listFilter=ll_newLinkedList();
        if(listFilter!=NULL)
        {
            for(int i=0; i<ll_len(this); i++)
            {
                pBufferElement=ll_get(this, i);
                if(!pFunc(pBufferElement))
                {
                    ll_add(listFilter, pBufferElement);
                }
            }
        }
    }
    return listFilter;
}

/** \brief recibe la lista y accede al campo y hace algo
 *
 * \param lista
 * \param puntero a funcion parametro y modificacion
 * \return -1 si no pudo modificar la lista, 0 si pudo modificar
 *
 */

int ll_map(LinkedList* this, int (*pFunc)(void*))
{

    int ret=-1;
     void* pBufferElement=NULL;
     int contadorDeElementos=0;

     if((this!=NULL)&&(pFunc!=NULL))
     {
          for(int i=0; i<ll_len(this); i++)
          {
              pBufferElement=ll_get(this,i);
              contadorDeElementos++;
              if(!pFunc(pBufferElement))
              {
                  continue;
                  ret=0;
              }
              if(pFunc(pBufferElement)==-1)//SI LA FUNCION FALLA
              {
                printf("No se pudo modifical el elemento n%d \n", contadorDeElementos);
                continue;
              }
          }//FOR
     }
     return ret;
}

/** \brief recibe la lista la recorre y va eliminando elementos
    que entren en el parametro y los cuenta, imprime los q no.
 *
 * \param lista
 * \param puntero a funcion
 * \return -1 si no pudo modificar la lista, 0 si pudo modificar
 *
 */
int ll_reduce(LinkedList* this, int (*pFunc)(void*))
{
   int ret=-1;
    int contador=0;
    int flagEliminados=0;
    void* pBufferElement=NULL;
    if((this!=NULL)&&(pFunc!=NULL))
    {
        for(int i=0; i<ll_len(this); i++)
        {
            pBufferElement=ll_get(this, i);
            if(!pFunc(pBufferElement))
            {
                if(!ll_remove(this,i))// o ll_pop
                {
                   i--;
                   contador++;
                }
            }
        }//FOR
        printf("Elementos eliminados %d\n", contador);
        ret=0;
    }
    return ret;
}

/** \brief cuenta canpos de a uno
 *
 * \param lista
 * \param puntero a funcion parametro
 * \return -1 si no pudo contar, 0 si esta ok
 *
 */

int ll_counter(LinkedList* this, int (*pFunc)(void*))
{
     int ret=-1;
     void* pBufferElement=NULL;
     int contadorDeElementos=0;

     if((this!=NULL)&&(pFunc!=NULL))
     {
          for(int i=0; i<ll_len(this); i++)
          {
              pBufferElement=ll_get(this,i);
              if(pFunc(pBufferElement))
              {
                  contadorDeElementos++;
              }
          }//FOR
     }
     return contadorDeElementos;
}

/** \brief recibe la lista mediante el parametro entra al campo y devuelve cant en int
 *
 * \param lista
 * \param puntero a funcion
 * \return la cant dentro del campo
 *
 */
int ll_sumador(LinkedList* this, int (*pFunc)(void*))
{
    int sumador=0;
     int contador=0;
     void* pBufferElement=NULL;

     if((this!=NULL)&&(pFunc!=NULL))
     {
          for(int i=0; i<ll_len(this); i++)
          {
            pBufferElement=ll_get(this,i);
            contador=pFunc(pBufferElement);
            sumador=sumador+contador;
          }//FOR
     }
     return sumador;
}
/** \brief recibe la lista mediante el parametro entra al campo y devuelve cant en float
 *
 * \param lista
 * \param puntero a funcion
 * \return la cant dentro del campo
 *
 */
float ll_sumadorFloat(LinkedList* this,float (*pFunc)(void*))
{
    float sumador=0;
     float contador;
     void* pBufferElement=NULL;

     if((this!=NULL)&&(pFunc!=NULL))
     {
          for(int i=0; i<ll_len(this); i++)
          {
            pBufferElement=ll_get(this,i);
            contador=pFunc(pBufferElement);
            sumador=sumador+contador;

          }//FOR
     }
     //printf("suma %.2f\n", sumador);
     return sumador;
}

/** \brief busca el maximo en todos los campos
 *
 * \param lista
 * \param punteroa a funcion
 * \return devuelve el elemento maximo encontrado
 *
 */

int ll_maximo(LinkedList* this, int (*pFunc)(void*))
{
    int bufferCantidad;
    int cantidadMaxima=0;
    void* pBufferElement=NULL;

     if((this!=NULL)&&(pFunc!=NULL))
     {
          for(int i=0; i<ll_len(this); i++)
          {
            pBufferElement=ll_get(this,i);
            bufferCantidad=pFunc(pBufferElement);
             if(cantidadMaxima<bufferCantidad)
            {
                cantidadMaxima=bufferCantidad;
            }
          }//FOR
     }
     return cantidadMaxima;
}

/** \brief busca el minima de todos los campo
 *
 * \param lista
 * \param punteroa a funcion
 * \return devuelve el elemento minima encontrado
 *
 */
int ll_minimo(LinkedList* this, int (*pFunc)(void*))
{
    int bufferCantidad;
    int cantMinima=0;
    void* pBufferElement=NULL;

     if((this!=NULL)&&(pFunc!=NULL))
     {
          for(int i=0; i<ll_len(this); i++)
          {
            pBufferElement=ll_get(this,i);
            bufferCantidad=pFunc(pBufferElement);
             if(cantMinima>bufferCantidad)
            {
                cantMinima=bufferCantidad;
            }
          }//FOR
     }
     return cantMinima;
}




