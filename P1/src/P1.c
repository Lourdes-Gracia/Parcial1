/*
 ============================================================================
 Name        : P1.c
 Author      : Lourdes Gracia 1 E
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Contribuyente.h"

#define LEN 1000

int main(void) {

	sContribuyente contribuyentes[LEN];
	int nextID = 1000;
	char repeat = 's';
	int readyStep1 = 0;

	setbuf(stdout, NULL);

	initContribuyentes(contribuyentes, LEN);

	printf("*** BIENVENIDO ***\n\n");

	do
	{
		system("cls");
		fflush(stdin);

		switch(menue("Por favor, seleccione una opcion:\n\n"
					"1.- Alta Contribuyente\n"
					"2.- Modificar Contribuyente\n"
					"3.- Baja Contribuyente\n"
					"4.- Informar\n"
					"5.- Salir\n"))
		{
			case 1:
				if(askData(contribuyentes, LEN, nextID) == 0)
				{
					nextID++;
					readyStep1 = 1;
				}
				break;
			case 2:
				if(!(noContribuyente(readyStep1)))

			{
					modifyContribuyente(contribuyentes, LEN);
				}
				break;
			case 3:
				if (!(noContribuyente(readyStep1)))
				{
					removeContribuyente(contribuyentes, LEN, inputInt("ID"));
				}
				break;
			case 4:
				if(!(noContribuyente(readyStep1)))
				{
					requestInfo(contribuyentes, LEN);
				}
				break;
			case 5:
				exit(-1);
				break;
			default:
				printf("No es una opcion valida.\n");
				break;
		}
		system("pause");

	} while (repeat == 's');

	return EXIT_SUCCESS;
}
