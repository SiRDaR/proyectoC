#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "servicios.h"
#include "../funciones.h"
void Servicios()
{
	char c;
	int opc;
	scanf("%c", &c);
	void(*funciones[4])() = { AltaS,ModificarS,ConsultarS,BajaS};
	opc = MenuServicios();
	while (opc != 5)
	{
		(*funciones[opc - 1])();
		opc = MenuServicios();
	}
}
void AltaS(){
	FILE *pf;
	SERVICIO reg;
	int ultimo;
	char resp;
	pf = fopen(FSERVICIO, "rb+");
	if (pf == NULL)
	{
		printf("Error al abrir el fichero de Servicios");
		getch(); return;
	}
	ultimo = NRegistrosS(pf);
	for (int i = 0; i < ultimo; i++)
	{
		fread(&reg, sizeof(reg), 1, pf);
		if (reg.estado == 0)
		{
			printf("Servicio numero: %d\n", i + 1);
			PedirDatosS(&reg);
			printf("Esta conforme?");
			resp = toupper(getche());
			if (resp == 'S')
			{
				reg.nservicio = i + 1;
				fwrite(&reg, sizeof(reg), 1, pf);
			}
			fclose(pf);
			return;
		}
		printf("Se dispone a rellenar el serivio nº %d\n", ultimo + 1);
		PedirDatosS(&reg);
		printf("Esta conforme?");
		resp = toupper(getche());
		if (resp == 'S')
		{
			reg.nservicio = ultimo + 1;
			fwrite(&reg, sizeof(reg), 1, pf);
		}
		fclose(pf);

	}
}
void ModificarS(){
	SERVICIO reg;
	FILE *pf;
	int ultimo, opc;
	char c;
	pf = fopen(FSERVICIO, "rb+");
	system("cls");
	if (pf == NULL) {
		printf("Error de apertura del fichero de servicio");
		getch(); return;
	}
	ultimo = NRegistrosS(pf);
	printf("Dame el nº del servicio\n");
	scanf("%d%c", &reg.nservicio, &c);
	fseek(pf, sizeof(reg)*(reg.nservicio - 1), SEEK_SET);
	fread(&reg, sizeof(reg), 1, pf);
	if (reg.nservicio >= 0 || reg.nservicio<ultimo)
	{
		VerDatosS(reg);
		getch();
		do {
			system("cls");
			printf("1.Modificar Denominacion\n 2.Modificar precio coste \n.3. Modificar precio final \n 4. Salir\n Elige opcion: \n");
			scanf("%d%c", &opc, &c);
		} while (opc < 1 || opc>5);
		while (opc != 4) {
			switch (opc)
			{
			case 1: printf("\nDame la nueva Denominacion");
				gets(reg.Denominacion);
				break;
			case 2: printf("\nDame el nuevo precio de coste");
				scanf("%d%c", &reg.preciocoste, &c);
				break;
			default: printf("\nDame el nuevo precio de venta al publico");
				scanf("%d%c",&reg.pvp,&c);
			}
			do {
				system("cls");
				printf("1.Modificar Denominacion\n 2.Modificar precio coste \n.3. Modificar precio final \n 4. Salir\n Elige opcion: \n");
				scanf("%d%c", &opc, &c);
			} while (opc < 1 || opc>5);
		}
		fwrite(&reg, sizeof(reg), 1, pf);
		printf("El servicio modificado es el siguiente: \n");
		getch();
		system("cls");
		VerDatosS(reg);
	}
	else {
		printf("El servicio especificado es invalido");
	}
	getch();
	fclose(pf);
}
void ConsultarS(){
	SERVICIO reg;
	FILE *pf;
	int ultimo, opc;
	char c;
	pf = fopen(FSERVICIO, "rb+");
	system("cls");
	if (pf == NULL) {
		printf("Error de apertura del fichero de servicios");
		getch(); return;
	}
	ultimo = NRegistrosS(pf);
	printf("Dame el nº de servicio\n");
	scanf("%d%c", &reg.nservicio, &c);
	fseek(pf, sizeof(reg)*(reg.nservicio - 1), SEEK_SET);
	fread(&reg, sizeof(reg), 1, pf);
	if ((reg.nservicio >= 0 || reg.nservicio < ultimo) && reg.estado == 1)
	{
		VerDatosS(reg);
		getch();
	}
	else printf("Te has equivocado con el servicio elegido.\n");
	getch();
	fclose(pf);
}
int MenuServicios() {
	int opc;
	char c;
	system("cls");
	GotoXY(35, 5);
	printf("Bienvenido al Menu de Servicios\n");
	GotoXY(35, 10);
	printf("1.Alta\n");
	GotoXY(35, 11);
	printf("2.Modificar\n");
	GotoXY(35, 12);
	printf("3.Consulta\n");
	GotoXY(35, 13);
	printf("4.Borrar Servicio\n");
	GotoXY(35, 14);
	printf("5.Salir\n");
	GotoXY(35, 15);
	printf("Opcion elegida ->[ ]");
	do {
		GotoXY(53, 15);
		scanf("%d%c", &opc, &c);
	} while (opc < 1 || opc>6);
	return opc;
}
void PedirDatosS(SERVICIO *reg) {
	char c;
	printf("Denominacion:");
	gets(reg->Denominacion);
	printf("\n Precio de coste:");
	scanf("%d%c", &reg->preciocoste,&c);
	printf("\n Precio de venta al publico:");
	scanf("%d%c", &reg->pvp,&c);
}
void VerDatosS(SERVICIO reg) {
	printf("Denominacion: %s\n", reg.Denominacion);
	printf("Precio coste: %d\n", reg.preciocoste);
	printf("Precio final: %d\n", reg.pvp);
}
void BajaS() {
	system("cls");
	int cod;
	char c;
	FILE *pf;
	SERVICIO reg;
	char resp;
	pf = fopen(FSERVICIO, "rb+");
	if (pf == NULL)
	{
		printf("Error de apertura");
		getch();
		return;
	}
	printf("Dame el Nº de servicio a borrar\n");
	scanf("%d%c", &cod, &c);
	fseek(pf, sizeof(reg)*(cod - 1), SEEK_SET);
	fread(&reg, sizeof(reg), 1, pf);
	if (reg.estado == 0)
	{
		printf("El registro no existe");
		getch();

	}
	else
	{
		VerDatosS(reg);
		printf("Desea elimnar el registro");
		resp = toupper(getche());
		if (resp == 'S')
		{
			reg.estado = 0;
			fseek(pf, sizeof(reg)*(cod - 1), SEEK_SET);
			fwrite(&reg, sizeof(reg), 1, pf);
		}
	}
	fclose(pf);
}
int NRegistrosS(FILE * pf)
{
	int pos;
	fseek(pf, 0, SEEK_END);
	pos = ftell(pf);
	return pos / sizeof(SERVICIO);
}