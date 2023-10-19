#ifndef LISTA_SIMPLE_H_INCLUDED
#define LISTA_SIMPLE_H_INCLUDED
#include "Cliente.h"
typedef struct{
struct nodoSimple*siguiente;
stCliente Cliente;
}nodoSimple;
nodoSimple*CrearNodoSimple(stCliente valor);
void agregarAlfinalSimple(nodoSimple**Lista,nodoSimple*NuevoNodo);
void MostrarListaSimple(nodoSimple*Lista);
void CargarListaClientes(nodoSimple**Lista);
int VerificarQueNoSeRepitaListaSimple(nodoSimple*Lista,char nombre[]);


#endif // LISTA_SIMPLE_H_INCLUDED
