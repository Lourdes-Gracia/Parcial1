/*
 * Contribuyente.c
 *
 *  Created on: 13 may. 2021
 *      Author: Lourdes Gracia 1E



1) Alta de Contribuyente: Se da de alta un contribuyente con nombre, apellido, y c.u.i.l. Se
generará un ID único (comenzando en 1000) para este contribuyente que se imprimirá por
pantalla si el alta es correcta.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Contribuyente.h"

int invalidList(sContribuyente* list, int len)
{
	if (len > 0 && list != NULL)
	{
		return 0;
	}
	else
	{
		printf("Lista NULL o fuera de rango.");
		return -1;
	}
}

/** Se indica que el array esta vacio*/

int initContribuyentes(sContribuyente* list, int len)
{
	if((invalidList(list, len)))
	{
		return -1;
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			list[i].isEmpty = 1;
		}
		return 0;
	}
}

/**
 * No hay contribuyenes añadidos
 */

int noContribuyentes (int ready)
{
	if(!(ready))
	{
		printf("Aun no se han ingresado contribuyentes.\n\n");
		return -1;
	}
	return 0;
}

/**
 * Menu
 */

int menue(char message[350])
{
	int option;

	printf( "\n%s\n", message);
	scanf("%d", &option);

	return option;
}

/** Se encuentra al Contribuyente por ID
*/

int findContribuyenteById(sContribuyente* list, int len, int id)
{
	if((invalidList(list, len)))
	{
		return -1;
	}
	else
	{
		for(int i = 0; i < len; i++)
		{
			if (list[i].id == id && list[i].isEmpty == 0)
			{
				return i;
			}
		}
		printf("No existe contribuyente asociado al ID %d.", id);
		return -1;
	}
}

/** Se piden los datos del contribuyent
*/

int askData(sContribuyente* list, int len, int id)
{
	sContribuyente auxCont;

	if((invalidList(list, len)))
	{
		return -1;
	}
	else
	{
		for(int i = 0; i < len; i++)
		{
			if (list[i].isEmpty == 1 )
			{
				inputString("nombre", auxCont.name);
				inputString("apellido", auxCont.lastName);
				auxCont.cuil = inputCuil("cuil");


				addContribuyentes (list, len, id, auxCont.name, auxCont.lastName, auxCont.cuil);

				return 0;
			}
		}
		printf("Listado completo. No se pueden ingresar nuevos contribuyentes\n");
		return -1;
	}
}

/**
 * Se agrega contribuyente a la lista de contribuyentes
*/

int addContribuyentes (sContribuyente* list, int len, int id, char name[], char lastName [], int cuil)

{
	if((invalidList(list, len)))
	{
		return -1;
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			if (list[i].isEmpty == 1 )
			{
				list[i].id = id;
				strcpy(list[i].name, name);
				strcpy(list[i].lastName, lastName);
				list[i].cuil = cuil;
				list[i].isEmpty = 0;
				return 0;
			}
		}
		printf("Listado completo. No se pueden ingresar nuevos contribuyentes\n");
		return -1;
	}
}

/** Modificar Contribuyentes
*/
int modifyContribuyente (sContribuyente* list, int len)
{
	int index;
	sContribuyente auxCont;

	if((invalidList(list, len)))
	{
		return -1;
	}
	else
	{
		index = findContribuyenteById(list, len, inputInt("ID"));

		if (index == -1)
		{
			return -1;
		}
		else
		{
			switch(menue("Seleccione parametro a modificar:\n"
							"1.- Nombre\n"
							"2.- Apellido\n"
							"3.- Cuil\n"
							"Presione una tecla para cancelar.\n"))
			{
				case 1:
					printf("Ingrese nuevo nombre: ");
					fflush(stdin);
					gets(auxCont.name);
					strcpy(list[index].name, auxCont.name);
				break;
				case 2:
					printf("Ingrese nuevo apellido: ");
					fflush(stdin);
					gets(auxCont.lastName);
					strcpy(list[index].lastName, auxCont.lastName);
					break;
				case 3:
					list[index].cuil = inputCuil("nuevo cuil");
					break;
				default:
					printf("No se realizaron cambios.\n\n");
					break;
			}
		return 0;
		}
	}
}

/** Remover Contribuyente
*/
int removeContribuyente(sContribuyente* list, int len, int id)
{
	char confirm = 'n';
	int index;

	if((invalidList(list, len)))
	{
		return -1;
	}
	else
	{
		index = findContribuyenteById(list, len, id);

		if(index == -1)
		{
			return -1;
		}
		else
		{
			printf("Esta seguro que desea eliminar a %s %s? s/n ", list[id].name, list[id].lastName);
			fflush(stdin);
			scanf("%c", &confirm);

			if(confirm == 's')
			{
				list[index].isEmpty = 1;
				printf("Contribuyente eliminado exitosamente.\n");
			}
			else
			{
				printf("No se realizaron cambios.");
			}
		return 0;
		}
	}
}


/** ordenar los contribuyentes
*/
int sortContribuyentes(sContribuyente* list, int len, int order)
{
	sContribuyente auxCont;


	if((invalidList(list, len)))
	{
		return -1;
	}
	else
	{
		if(order > 2 || order < 1)
		{
			printf("Orden invalido.\n");
		}
		else
		{
			for (int i = 0; i < len -1 ; i++)
			{

				for (int j = i+1; j < len; j ++)
				{
					if (order == 1 && list[i].isEmpty == 0 && (strcmp(list[i].lastName,list[j].lastName) > 0))
					{
						auxCont = list[i];
						list[i] = list[j];
						list[j] = auxCont;
					}
					if (order == 1 && list[i].isEmpty == 0 && (strcmp(list[i].lastName,list[j].lastName) == 0 ))
					{
						auxCont = list[i];
						list[i] = list[j];
						list[j] = auxCont;
					}
					if (order == 2 && list[i].isEmpty == 0 && (strcmp(list[i].lastName,list[j].lastName) < 0))
					{
						auxCont = list[i];
						list[i] = list[j];
						list[j] = auxCont;
					}
					if (order == 2 && list[i].isEmpty == 0 && (strcmp(list[i].lastName,list[j].lastName) == 0 ))
					{
						auxCont = list[i];
						list[i] = list[j];
						list[j] = auxCont;
					}
				}
			}
			printContribuyentes(list, len);
		}
	return 0;
	}
}

/** Se pide la informacion del contribuyente
*/
int requestInfo(sContribuyente* list, int len)
{
	if((invalidList(list, len)))
	{
		return -1;
	}
	else
	{
		if(menue("Por favor, seleccione una opcion:\n"
				"1.- Listado de contribuyentes\n"))
				{
			sortContribuyentes(list, len, menue("Modo de ordenamiento:\n"
									"1.- Ascendente\n"
									"2.- Descendente\n"));
		}
		return 0;
	}
}

/** imprime contribuyente
*/

void printContribuyente(sContribuyente cont)
{
	printf(	"| %04d | %20s | %20s | $%04d \n", cont.id, cont.name, cont.lastName, cont.cuil);

}

/** Imprimimos los contribuyentes
*/

int printContribuyentes(sContribuyente* list, int len)

{
	if((invalidList(list, len)))
	{
		return -1;
	}
	else
	{
		printf(	"#======#======================#======================#=============#\n"
				"|  ID  |        NOMBRE        |       APELLIDO       |    CUIL     |\n"
				"#======#======================#======================#=============#\n");
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				printContribuyente(list[i]);
			}
		}
		printf( "#======#======================#======================#=============#\n");
		return 0;
	}
}

/** cuil
 * */
int inputCuil(char message[20])
{
	int num;

	printf("Ingrese %s: ", message);
	scanf("%d", &num);

	while (num < 1)
	{
		printf("ERROR: %s fuera de rango. Ingrese %s nuevamente: \n", message, message);
		scanf("%d", &num);
	}
	return num;
}


int inputInt(char message[20])

{
	int num;

	printf("Ingrese %s: ", message);
	scanf("%d", &num);

	while (num < 0)
	{
		printf("ERROR: %s fuera de rango. Ingrese %s nuevamente: ", message, message);
		scanf("%d", &num);
	}
	return num;
}

void inputString(char message[20], char* string)
{
	printf("Ingrese %s: ", message);
	fflush(stdin);
	gets(string);
	int noNum = 0;

	do
	{
	if (strlen(string) > 19)
	{
		printf("ERROR: %s es demasiado largo. Ingrese %s nuevamente: ", message, message);
		fflush(stdin);
		gets(string);
	}
	else
	{
		strlwr(string);

		for (int i = 0; i < strlen(string); i++)
		{
			if(isdigit(string[i]))
			{
				noNum = 1;
				break;
			}
			else
			{
				noNum = 0;
			}
		}
	}
	if (noNum == 1)
	{
		printf("ERROR: No se aceptan numeros. Ingrese %s nuevamente: ", message);
		fflush(stdin);
		gets(string);
	}
	else
	{
		for(int i = 0; i < strlen(string); i++)
		{
			string[0] = toupper(string[0]);
			if(string[i] == ' ')
			{
				string[i+1] = toupper(string[i+1]);
			}
		}
	}
	}while(noNum == 1);

}

