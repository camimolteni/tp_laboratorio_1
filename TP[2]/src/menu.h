#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "arraypassenger.h"
#include <string.h>

#ifndef MENU_H_
#define MENU_H_

int cargarClase(eClass[], int, int, char[]);
int menuPrincipal();
int menuModificar(ePassenger[], int);
void menuInformar(ePassenger[], int);
int informar(ePassenger[], int, eClass[], int, eVuelo[], int, int);

#endif /* MENU_H_ */
