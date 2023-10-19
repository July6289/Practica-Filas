#include <stdio.h>
#include <stdlib.h>
#include "Listas dobles.h"
#include "Fila.h"
#include "Lista simple.h"
#include "string.h"
#include <time.h>
#define archivos "archivos.dat"

nodoDoble*InicNodo()   //si usamos para un nodo simple, castearlo: nodoSimple*nuevoNodo=((nodoSimple*)inicNodo());
{
    return NULL;
}
nodoDoble*CrearNodoDoble(stCliente valor)
{
 nodoDoble*NuevoNodo=(nodoDoble*)malloc(sizeof(nodoDoble));
 NuevoNodo->Cliente=valor;
 NuevoNodo->siguiente=InicNodo();
 NuevoNodo->anterior=InicNodo();

 return NuevoNodo;
}
void MostrarListaDoble(nodoDoble*Lista)
{
    if(Lista!=NULL)
    {
        MostrarDato(Lista->Cliente);
        MostrarListaDoble(Lista->siguiente);
    }
}

nodoDoble*BorrarPrimerNodo(nodoDoble*Lista)
{
    if(Lista!=NULL)
    {
        nodoDoble*Borrar=Lista;
        Lista=Lista->siguiente;
        if(Lista!=NULL)
        {

            Lista->anterior=NULL;
        }


    }


        return Lista;


}
int ContarTotalClientes(nodoDoble*Lista)
{
    int numero=0;

    if(Lista!=NULL)
    {
       numero=1;

       numero=numero+ContarTotalClientes(Lista->siguiente);
    }
    return numero;
}

float CalcularPromedioDeFila(nodoDoble*Lista)
{
    int i=0;

    while(Lista!=NULL)
    {



    }






}
nodoDoble*agregarAlprincipio(nodoDoble*primero,nodoDoble*NuevoNodo)
{
    NuevoNodo->siguiente=primero;
    primero->anterior=NuevoNodo;

    primero=NuevoNodo;


    return primero;

}
nodoDoble*agregarAlfinal(nodoDoble*Final,nodoDoble*NuevoNodo)
{
    Final->siguiente=NuevoNodo;
    NuevoNodo->anterior=Final;
    Final=NuevoNodo;

    return Final;
}
