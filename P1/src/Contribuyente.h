/*
 * Contribuyente.h
 *
 *  Created on: 13 may. 2021
 *      Author: reyna
 */


#ifndef CONTRIBUYENTE_H_
#define CONTRIBUYENTE_H_
typedef struct
{
	int id;
	char name[20];
	char lastName[20];
	int cuil;
	int isEmpty;


}sContribuyente;

#endif /* ARRAYEMPLOYEES_H_ */

int invalidList(sContribuyente* list, int len);
int initContribuyentes(sContribuyente* list, int len);
int noContribuyente (int ready);
int menue(char message[350]);
int menueRecaudacion(char message[350]);
int findContribuyenteById(sContribuyente* list, int len, int id);
int askData (sContribuyente* list, int len, int id);
int addContribuyentes (sContribuyente* list, int len, int id, char name[], char lastName [], int cuil);
int modifyContribuyente (sContribuyente* list, int len);
int removeContribuyente(sContribuyente* list, int len, int id);
int sortContribuyentes(sContribuyente* list, int len, int order);
int requestInfo(sContribuyente* list, int len);
void printContribuyente(sContribuyente emp);
int printContribuyentes(sContribuyente* list, int len);
int inputCuil(char message[40]);
int inputInt(char message[40]);
void inputString(char message[20], char* string);


