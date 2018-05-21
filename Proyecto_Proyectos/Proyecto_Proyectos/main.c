#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "funciones.h"
#include <Windows.h>

//GotoXY, usado por todas las demas funciones de Menu
void GotoXY(int x, int y)
{
	HANDLE h;
	COORD pos;
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(h, pos);
}
//Main y Menú principal
main()
{	int opc;
	void(*funciones[4])() = { Clientes,Servicios,Presupuestos,Facturacion };
	opc = Menu();
	while (opc != 5)
	{
		(*funciones[opc-1])();
		opc = Menu();
	}
}

int Menu() {
	int opc;
	char c;
	system("cls");
	GotoXY(35, 10);
	printf("1.Clientes\n");
	GotoXY(35, 11);
	printf("2.Servicios\n");
	GotoXY(35, 12);
	printf("3.Presupuestos\n");
	GotoXY(35, 13);
	printf("4.Facturacion\n");
	GotoXY(35, 14);
	printf("5.Salir\n");
	GotoXY(35, 15);
	printf("Opcion elegida ->[ ]");
	do {
		GotoXY(53, 15);
		scanf("%d%c", &opc, &c);
	} while (opc < 1 || opc>5);
	return opc;
}
