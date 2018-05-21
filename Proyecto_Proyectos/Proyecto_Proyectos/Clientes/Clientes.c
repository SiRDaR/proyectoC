#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Clientes.h"
#include "../funciones.h"
int NRegistros(FILE * pf)
{
	int pos;
	fseek(pf, 0, SEEK_SET);
	pos = ftell(pf);
	fseek(pf, 0, SEEK_END);
	pos = ftell(pf) - pos;
	return pos / sizeof(CLIENTES);
}
void Clientes() {
	int opc;
	void(*funciones[4])() = { AltaC,ModificarC,ConsultarC,BajasC};
	opc = MenuClientes();
	while (opc != 5)
	{
		(*funciones[opc - 1])();
		opc = MenuClientes();
	}
}
void AltaC() {
	CLIENTES reg;
	FILE *pf;
	int ultimo;
	char si;
	pf = fopen(FCLIENTES, "rb+");
	if (pf == NULL) {
		printf("Error de apertura del fichero de clientes");
		getch(); return;
	}
	ultimo = NRegistros(pf);
	for (int i = 0; i < ultimo; i++)
	{
		fread(&reg, sizeof(reg), 1, pf);
		if (reg.estado== 0)
		{
			printf("Cliente numero: %d\n", i + 1);
			PedirDatos(&reg);
			printf("Esta conforme?");
			si = toupper(getche());
			if (si == 'S')
			{
				reg.Ncliente = i + 1;
				fwrite(&reg, sizeof(reg), 1, pf);
			}
		fclose(pf);
		return;
		}
		
	}
	printf("Cliente numero: %d\n", ultimo + 1);
	PedirDatos(&reg);
	printf("Esta conforme?");
	si = toupper(getche());
	if (si == 'S')
	{
		reg.Ncliente = ultimo + 1;
		fwrite(&reg, sizeof(reg), 1, pf);
	}
	fclose(pf);

}
void PedirDatos(CLIENTES *reg)
{
	printf("Nombre\n");
	gets(reg->Nombre);
	printf("Domicilio\n");
	gets(reg->Domicilio);
	printf("Codigo Postal\n");
	gets(reg->Codpos);
	printf("Municipio\n");
	gets(reg->Municipio);
	printf("N.I.F.\n");
	gets(reg->NIF);
	reg->estado = 1;

}

void ModificarC() {
	CLIENTES reg;
	FILE *pf;
	int ultimo, opc;
	char c;
	pf = fopen(FCLIENTES, "rb+");
	system("cls");
	if (pf == NULL) {
		printf("Error de apertura del fichero de clientes");
		getch(); return;
	}
	ultimo = NRegistros(pf);
		printf("Dame el nº de cliente\n");
		scanf("%d%c", &reg.Ncliente, &c);
		fseek(pf, sizeof(reg)*(reg.Ncliente-1), SEEK_SET);
		fread(&reg, sizeof(reg), 1, pf);
		if ((reg.Ncliente>=0 || reg.Ncliente<ultimo) && reg.estado==1)
		{
			 VerDatos(reg);
			 getch();
			 do {
				 system("cls");
				 printf("1.Modificar Nombre\n 2.Modificar Domicilio \n.3. Modificar Codigo Postal \n 4. Modificar Municipio \n 5.Modificar NIF \n 6.Salir \n Elige opcion: \n");
				 scanf("%d%c", &opc, &c);
			 } while (opc < 1 || opc>7);
			 while (opc != 6) {
				 switch (opc)
				 {
				 case 1: printf("\nDame el nuevo nombre");
					 gets(reg.Nombre);
					 break;
				 case 2: printf("\nDame el nuevo domicilio");
					 gets(reg.Domicilio);
					 break;
				 case 3: printf("\nDame el nuevo Codigo Postal");
					 gets(reg.Codpos);
					 break;
				 case 4: printf("\nDame el nuevo Municipio");
					 gets(reg.Municipio);
					 break;
				 default: printf("\nDame el nuevo NIF");
					 gets(reg.NIF);
					 break;
				 }
				 do {
					 system("cls");
					 printf("1.Modificar Nombre\n 2.Modificar Domicilio \n.3. Modificar Codigo Postal \n 4. Modificar Municipio \n 5.Modificar NIF \n 6.Salir \n Elige opcion: ");
					 scanf("%d%c", &opc, &c);
				 } while (opc < 1 || opc>7);
			 }
			 fwrite(&reg, sizeof(reg), 1, pf);
			 printf("Sus nuevos datos: \n");
			 getch();
			 system("cls");
			 VerDatos(reg);
		}
		else {
			printf("El cliente no existe");
		}
		getch();
		fclose(pf);
}
void ConsultarC() {
	CLIENTES reg;
	FILE *pf;
	int ultimo, opc;
	char c;
	pf = fopen(FCLIENTES, "rb+");
	system("cls");
	if (pf == NULL) {
		printf("Error de apertura del fichero de clientes");
		getch(); return;
	}
	ultimo = NRegistros(pf);
	printf("Dame el nº de cliente\n");
	scanf("%d%c", &reg.Ncliente, &c);
	fseek(pf, sizeof(reg)*(reg.Ncliente - 1), SEEK_SET);
	fread(&reg, sizeof(reg), 1, pf);
	if ((reg.Ncliente >= 0 || reg.Ncliente < ultimo) && reg.estado == 1)
	{
		VerDatos(reg);
		getch();
	}
	else printf("Te has equivocado con el cliente elegido.\n");
	getch();
	fclose(pf);
}
void BajasC() {
	system("cls");
	int cod;
	char c;
	FILE *pf;
	CLIENTES reg;
	char resp;
	pf = fopen(FCLIENTES, "rb+");
	if (pf == NULL)
	{
		printf("Error de apertura");
		getch();
		return;
	}
	printf("Dame el Nº de cliente a borrar\n");
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
		VerDatos(reg);
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

int MenuClientes() {

		int opc;
		char c;
		system("cls");
		GotoXY(35, 5);
		printf("Bienvenido al Menu de Clientes\n");
		GotoXY(35, 10);
		printf("1.Alta\n");
		GotoXY(35, 11);
		printf("2.Modificar\n");
		GotoXY(35, 12);
		printf("3.Consulta\n");
		GotoXY(35, 13);
		printf("4.Baja\n");
		GotoXY(35, 14);
		printf("5.Salir\n");
		GotoXY(35, 15);
		printf("Opcion elegida ->[ ]");
		do {
			//posicion del cursor
			GotoXY(53, 15);
			scanf("%d%c", &opc, &c);
		} while (opc < 1 || opc>6);
		return opc;
}
void VerDatos(CLIENTES reg) {
	printf("Nombre: %s\n", reg.Nombre);
	printf("Domicilio: %s\n", reg.Domicilio);
	printf("Codigo Postal: %s\n", reg.Codpos);
	printf("Municipio: %s\n", reg.Municipio);
	printf("N.I.F. : %s\n", reg.NIF);
}