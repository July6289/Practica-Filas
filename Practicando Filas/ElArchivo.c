#include <stdio.h>
#include <stdlib.h>
#include "Listas dobles.h"
#include "Fila.h"
#include "Lista simple.h"
#include "Cliente.h"
#include "string.h"
#include <time.h>
#define archivos "archivos.dat"

void GuardarClientesAtendidos(nodoDoble*Borrado)
{
  FILE*buffer=fopen(archivos,"wb");

  stCliente nuevo=Borrado->Cliente;
  if(buffer!=NULL)
  {
      fwrite(&nuevo,sizeof(stCliente),1,buffer);


      fclose(buffer);
  }


}
void MostrarClientes()
{
    FILE*buffer=fopen(archivos,"rb");
    stCliente dato;
    if(buffer!=NULL)
    {
        while(!feof(buffer))
        {
            fread(&dato,sizeof(stCliente),1,buffer);
            if(!feof(buffer))
            {
                MostrarDato(dato);

            }
        }
    }
}
