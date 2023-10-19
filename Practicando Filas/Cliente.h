#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct{
int tipoCliente; //1-regular,2-jubilado,3-persona gestante,4-empresario
int cantidadFacturas;
char nombre[20];
}stCliente;

void MostrarDato(stCliente dato);
stCliente CargarCliente();//lo prototipo aca porque sino no funciona

#endif // CLIENTE_H_INCLUDED
