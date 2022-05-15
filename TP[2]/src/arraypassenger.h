#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_


typedef struct{

	int id;
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;

}ePassenger;

typedef struct{

   int id;
   char descripcion[20];

}eClass;

typedef struct{

	char descripcion[20];
    char flyCode[10];
    int statusFlight;
}eVuelo;

int addPassenger(ePassenger[], eClass[], eVuelo[], int, int, int);
int indexLibre(ePassenger[], int);
int findPassengerById(int, ePassenger[], int);
void informarPasajero(ePassenger[], int);
void informarPasajero(ePassenger[], eClass[], eVuelo[], int, int , int);
int removePassenger(ePassenger[], int);
void mostrarPasajeroFila(ePassenger[], eClass[], int, eVuelo[], int, int);
int listarPasajeros(ePassenger[], int);
int sortPassenger(ePassenger[], int);
int sortPassengerFlyCode(ePassenger[], int, eVuelo[], int, eClass[], int);
int hardcodearPasajeros(ePassenger[], int, int, int*);
int promedioPrecios(ePassenger[], int);
void listarPorCodigo(ePassenger[], int);
int altaForzada(ePassenger[], int, int*, int*);

#endif /* ARRAYPASSENGER_H_ */
