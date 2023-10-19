#include <stdio.h>
#include <stdlib.h>
#include "Listas dobles.h"
#include "Fila.h"
#include "Lista simple.h"
#include "Cliente.h"
#include "string.h"
#include <time.h>
#define archivos "archivos.dat"
int main()
{
  srand(time(NULL));


  nodoSimple*ListaSimple=((nodoSimple*)InicNodo());
  CargarListaClientes(&ListaSimple);
  printf("ListaSimple, mostrando datos\n");
  MostrarListaSimple(ListaSimple);
  Fila filas[5];
  CargarFilas(filas,5);

  MostrarFilas(filas,5);

}
