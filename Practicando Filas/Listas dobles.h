#ifndef LISTAS_DOBLES_H_INCLUDED
#define LISTAS_DOBLES_H_INCLUDED
#include "Cliente.h"
typedef struct{
struct nodoDoble*siguiente;
struct nodoDoble*anterior;
stCliente Cliente;
}nodoDoble;

nodoDoble*InicNodo();
nodoDoble*CrearNodoDoble(stCliente valor);
void MostrarDato();
void MostrarListaDoble();
nodoDoble*BorrarPrimerNodo();
int ContarTotalClientes(nodoDoble*Lista);
nodoDoble*agregarAlprincipio(nodoDoble*primero,nodoDoble*NuevoNodo);
nodoDoble*agregarAlfinal(nodoDoble*Final,nodoDoble*NuevoNodo);

#endif // LISTAS_DOBLES_H_INCLUDED
