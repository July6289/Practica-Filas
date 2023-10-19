#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "Listas dobles.h"
#include "Fila.h"
#include "Lista simple.h"
#include "string.h"
#include <time.h>
#define archivos "archivos.dat"
fsfefr
nodoSimple*CrearNodoSimple(stCliente valor)
{
    nodoSimple*NuevoNodo=(nodoSimple*)malloc(sizeof(nodoSimple));

    NuevoNodo->siguiente=((nodoSimple*)InicNodo());
    NuevoNodo->Cliente=valor;
    return NuevoNodo;
}

void agregarAlfinalSimple(nodoSimple**Lista,nodoSimple*NuevoNodo)
{

    if((*Lista)==NULL)
    {
        *Lista=NuevoNodo;

    }

    else
    {
     agregarAlfinalSimple(&((*Lista)->siguiente),NuevoNodo);
    }
}
void MostrarListaSimple(nodoSimple*Lista)
{
    if(Lista!=NULL)
    {
       MostrarDato(Lista->Cliente);
       MostrarListaSimple(Lista->siguiente);
    }

}
void CargarListaClientes(nodoSimple**Lista)
{
    int cantidadDeClientes;
    int i=1;
    nodoSimple*NuevoNodo;

    printf("cuantos clientes van a entrar?\n");
    scanf("%d",&cantidadDeClientes);

    while(i<=cantidadDeClientes)
    {
        NuevoNodo=CrearNodoSimple(CargarCliente());

        agregarAlfinalSimple(Lista,NuevoNodo);
        i++;
    }


}
int VerificarQueNoSeRepitaListaSimple(nodoSimple*Lista,char nombre[])
{
    int respuesta=0;

    if(Lista!=NULL)
    {
        if(strcmp(Lista->Cliente.nombre,nombre)==0)
        {
            respuesta=1;



        }
        else
        {
           respuesta=VerificarQueNoSeRepitaListaSimple(Lista->siguiente,nombre);

        }

    }

        return respuesta;



}
