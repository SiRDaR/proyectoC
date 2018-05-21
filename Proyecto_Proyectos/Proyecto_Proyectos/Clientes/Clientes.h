#pragma once
#include "../funciones.h"
#define FCLIENTES "Listado_Clientes.txt"

typedef struct {
	int Ncliente;
	char Nombre[20];
	char Domicilio[20];
	char Codpos[6];
	char Municipio[15];
	char NIF[10];
	int estado;
}CLIENTES;

void Clientes();
int MenuClientes();
void AltaC();
void ModificarC();
void ConsultarC();
void PedirDatos(CLIENTES *reg);
void VerDatos(CLIENTES reg);
void BajasC();
int NRegistros(FILE * pf);