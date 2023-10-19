#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include "Lista simple.h"
typedef struct{
struct nodoDoble*Primero;
struct nodoDoble*Ultimo;
int numeroFila;
char nombreCajero[50];
}Fila;

void InicFila();
int extraer(Fila*f);
int filavacia(Fila*f);
nodoDoble*SubAgregarAlfinaldeFilas(nodoDoble*Final,nodoDoble*NuevoNodo);
void AgregarAlfinaldeFilas(Fila*f,stCliente dato);
void AgregarAlprincipioDeFilas(Fila*f,stCliente dato);
nodoDoble*SubAgregarAlprincipioDeFilas(nodoDoble*primero,nodoDoble*NuevoNodo);
void AgregarOrdenadoEnFilas(Fila*f,stCliente dato);
void SubAgregarOrdenadoEnFilas(nodoDoble**Primero,nodoDoble**Ultimo,nodoDoble*NuevoNodo);
void verFila(Fila*f);
int verPrimero(Fila*f);
void CargarFilas(Fila arreglo[],int dimension);
void MostrarFilas(Fila arreglo[],int dimension);
void AgregarClientesAcaja(Fila arreglo[],nodoSimple*Lista);
int determinarMenor(int Fila1cant,int Fila3cant,int Fila4cant);
int VerificarSiNoSeRepiteLaFila(Fila arreglo[],char nombre[],int dimension);

#endif // FILA_H_INCLUDED
