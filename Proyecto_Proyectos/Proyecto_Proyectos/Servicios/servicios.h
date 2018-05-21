#pragma once
#include "../funciones.h"
#define FSERVICIO "Listado_Servicios.txt"

typedef struct {
	int nservicio;
	char Denominacion[20];
	int preciocoste;
	int pvp;
	int estado;
}SERVICIO;
void Servicios();
int MenuServicios();
void AltaS();
void ModificarS();
void ConsultarS();
void PedirDatosS(SERVICIO *reg);
void VerDatosS(SERVICIO reg);
void BajaS();
int NRegistrosS(FILE * pf);