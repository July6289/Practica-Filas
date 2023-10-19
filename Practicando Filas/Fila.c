#include <stdio.h>
#include <stdlib.h>
#include "Listas dobles.h"
#include "Fila.h"
#include "Lista simple.h"
#include "string.h"
#include <time.h>
#define archivos "archivos.dat"

void InicFila(Fila*f)
{
    f->Primero=InicNodo();
    f->Ultimo=InicNodo();
}

int extraer(Fila*f)
{
    int respuesta=-1;
    if(f->Primero!=NULL)
    {
        respuesta=((nodoDoble*)f->Primero)->Cliente.cantidadFacturas;
        f->Primero=BorrarPrimerNodo(f->Primero);
        if(f->Primero==NULL)
        {
            f->Ultimo=InicNodo();

        }


    }




}
int filavacia(Fila*f)
{

     return f->Primero? 0:1;


}
void SubAgregarOrdenadoEnFilas(nodoDoble**Primero,nodoDoble**Ultimo,nodoDoble*NuevoNodo)
{

    if((*Primero)->Cliente.cantidadFacturas<NuevoNodo->Cliente.cantidadFacturas)
    {
        NuevoNodo->siguiente=*Primero;
        *Primero=NuevoNodo;
    }
    else
    {
        nodoDoble*seguidora=(*Primero)->siguiente;
        nodoDoble*anterior=(*Primero);
        while(seguidora!=NULL&&seguidora->Cliente.cantidadFacturas<NuevoNodo->Cliente.cantidadFacturas)
        {
            anterior=seguidora;
            seguidora=seguidora->siguiente;
        }
        if(seguidora==NULL)
        {

            anterior->siguiente=NuevoNodo;
            NuevoNodo->anterior=anterior;

            *Ultimo=NuevoNodo;
        }
        else
        {
            anterior->siguiente=NuevoNodo;
            NuevoNodo->anterior=anterior;
            NuevoNodo->siguiente=seguidora;



        }

    }



}
void AgregarOrdenadoEnFilas(Fila*f,stCliente dato)
{
    nodoDoble*NuevoNodo=CrearNodoDoble(dato);
    if(f->Primero==NULL)
    {
        f->Primero=NuevoNodo;
        f->Ultimo=NuevoNodo;
    }
    else
    {

        SubAgregarOrdenadoEnFilas(&(f->Primero),&(f->Ultimo),NuevoNodo);

    }


}

nodoDoble*SubAgregarAlfinaldeFilas(nodoDoble*Final,nodoDoble*NuevoNodo)
{

    return agregarAlfinal(Final,NuevoNodo);

}
void AgregarAlfinaldeFilas(Fila*f,stCliente dato)
{
    nodoDoble*NuevoNodo=CrearNodoDoble(dato);
    if(f->Primero==NULL)
    {
        f->Primero=NuevoNodo;
        f->Ultimo=NuevoNodo;
    }
    else
    {
        f->Ultimo=SubAgregarAlfinaldeFilas(f->Ultimo,NuevoNodo);
    }

}
void agregarAlprincipiodeFilas(Fila*f,stCliente dato)
{
    nodoDoble*NuevoNodo=CrearNodoDoble(dato);
    if(f->Primero==NULL)
    {
        f->Primero=NuevoNodo;
        f->Ultimo=NuevoNodo;
    }
    else
    {
        f->Primero=SubAgregarAlprincipioDeFilas(f->Primero,NuevoNodo);

    }

}
nodoDoble*SubAgregarAlprincipioDeFilas(nodoDoble*primero,nodoDoble*NuevoNodo)  //esto lo hacemos para considerar una funcion
{                                                                              //de nodos dobles


    return agregarAlprincipio(primero,NuevoNodo);

}
void verFila(Fila*f)
{

    MostrarListaDoble(f->Primero);
}
int verPrimero(Fila*f)
{
    return f->Primero? -1:((nodoDoble*)f->Primero)->Cliente.cantidadFacturas;
}
void CargarFilas(Fila arreglo[],int dimension)
{
    char nombres[5][20]={{"Nil Pardo"},{"Jenifer Saura"},{"Maria Antonia"},{"Milagros Vega"},{"Eduardo Romera"}};

    int numero=1;
    int i=0;
    char nombreAcolocar[20];
    while(i<dimension)
    {   do
        {
        strcpy(nombreAcolocar,nombres[rand()%5]);                               //no se va a poder ir hasta que ponga un nombre unico
        }while(VerificarSiNoSeRepiteLaFila(arreglo,nombreAcolocar,dimension)==1);     //una caja la atiende una persona diferente

        strcpy(arreglo[i].nombreCajero,nombreAcolocar);
        arreglo[i].numeroFila=numero;

        arreglo[i].Primero=InicNodo();
        arreglo[i].Ultimo=InicNodo();
        i++;
        numero++;
    }

    printf("Cajeros Cargados\n");

}
int VerificarSiNoSeRepiteLaFila(Fila arreglo[],char nombre[],int dimension)
{
    int respuesta=0;
    int i=0;
    while(i<dimension)
    {
        if(strcmp(arreglo[i].nombreCajero,nombre)==0)
        {
            respuesta=1;
        }
        i++;

    }

    return respuesta;
}
int determinarMenor(int Fila1cant,int Fila3cant,int Fila4cant)
{
  int posicionMenor;

  if(Fila1cant<Fila3cant&&Fila1cant<Fila4cant)
  {

    posicionMenor=0;

  }
  else if(Fila3cant<Fila1cant<Fila4cant)
  {

    posicionMenor=2;


  }
  else
  {

      posicionMenor=3;

  }


}
void MostrarFilas(Fila arreglo[],int dimension)
{
    for(int i=0;i<dimension;i++)
    {
        printf("--------------------\n");
        printf("Fila %d\n",arreglo[i].numeroFila);
        printf("Nombre Del Cajero:%s\n",arreglo[i].nombreCajero);
        MostrarListaDoble(arreglo[i].Primero);
        printf("--------------------\n");
    }
}
void AgregarClientesAcaja(Fila arreglo[],nodoSimple*Lista)
{
    int Fila1cant;
    int Fila3cant;
    int Fila4Cant;

    int posicionMenor;
    while(Lista!=NULL)
    {
       Fila1cant=ContarTotalClientes(arreglo[0].Primero);
       Fila3cant=ContarTotalClientes(arreglo[2].Primero);
       Fila4Cant=ContarTotalClientes(arreglo[3].Primero);

       posicionMenor=determinarMenor(Fila1cant,Fila3cant,Fila4Cant);

       if(Lista->Cliente.tipoCliente==1)
       {
            if(posicionMenor==0)
            {
                AgregarAlfinaldeFilas(&arreglo[0],Lista->Cliente);

            }
            else if(posicionMenor==2)
            {
               AgregarAlfinaldeFilas(&arreglo[2],Lista->Cliente);

            }
            else
            {

                AgregarOrdenadoEnFilas(&arreglo[3],Lista->Cliente);


            }


       }

       else if(Lista->Cliente.tipoCliente==2)    //si el cliente es jubilado
       {
               AgregarAlfinaldeFilas(&arreglo[1],Lista->Cliente);


       }
       else if(Lista->Cliente.tipoCliente==3)
       {
           agregarAlprincipiodeFilas(&arreglo[2],Lista->Cliente);


       }
       else
       {
           if(Lista->Cliente.cantidadFacturas>10)
           {
                Lista->Cliente.cantidadFacturas=10;

           }

           AgregarAlfinaldeFilas(&arreglo[4],Lista->Cliente);

       }

            Lista=Lista->siguiente;

    }








}
