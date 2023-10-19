#include <stdio.h>
#include <stdlib.h>
#include "Listas dobles.h"
#include "Fila.h"
#include "Lista simple.h"
#include "Cliente.h"
#include "string.h"
#include <time.h>
#define archivos "archivos.dat"

void MostrarDato(stCliente dato)
{
    char Eldato[20];
    printf("---------------\n");

    printf("Nombre:%s\n",dato.nombre);


    printf("cantidad de facturas:%d\n",dato.cantidadFacturas);
    if(dato.tipoCliente==1)
    {
        strcpy(Eldato,"Regular");
    }
    else if(dato.tipoCliente==2)
    {
        strcpy(Eldato,"Jubilado");

    }
    else if(dato.tipoCliente==3)
    {
        strcpy(Eldato,"Persona Gestante");
    }
    else
    {
        strcpy(Eldato,"Empresario");
    }
    printf("tipo de cliente:%s\n",Eldato);

    printf("---------------\n");


}
stCliente CargarCliente()
{
    char nombre[10][35]={{"Uxue"},{"Brigida"},{"Eduard"},{"Maria"},{"Fabio"},{"Rosa"},{"Emiliana"},{"Luis"},{"Adria"},{"Carme"}};
    //el limite de personas maximas siempre seran 10
    char nuevoNombre[20];
    stCliente nuevo;

    nuevo.cantidadFacturas=rand()%15+1;

    nuevo.tipoCliente=rand()%3+1;

    strcpy(nuevo.nombre,nombre[rand()%9]);

   return nuevo;
}
