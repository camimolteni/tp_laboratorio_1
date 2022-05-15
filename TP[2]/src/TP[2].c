#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "arraypassenger.h"
#include "menu.h"
#include "validaciones.h"

#define TAM 5
#define CANTVUELO 5
#define CANTCLAS 3

int main(void) {

	setbuf(stdout, NULL);

	int proximoId = 1000;
	int datos = 0;
	int opcion;
	int flag = 1;

	ePassenger pasajeros[TAM];
	initPassenger(pasajeros,TAM);

    eClass clases[CANTCLAS] =
    {
        {1, "Economica"},
        {2, "Ejecutiva"},
        {3, "Premium"},
    };

    eVuelo vuelo[CANTVUELO] =
    {
        {"AB15", 1, "Activo"},
        {"CD24", 2, "Cancelado"},
        {"EF36", 3, "Demorado"},
        {"MV87", 1, "Activo"},
        {"TL51", 2, "Demorado"},
    };


	do{
		opcion = menuPrincipal();

		switch(opcion){
			case 1:
				addPassenger(pasajeros, clases, cantClas, vuelos, cantVuelo, TAM, &proximoId, &flag);
					datos++;
				break;
			case 2:
				menuModificar(pasajeros, clases, cantClas, vuelos, cantVuelo, TAM, flag);
			break;
			case 3:
				if(datos>0){
					removePassenger(pasajeros, TAM);
						printf("\nPasajero eliminado!\n\n");
                   }
        break;
			case 4:
				if(datos>0){
					informes(pasajeros, TAM, clases, cantClas, vuelos, cantVuelo, flag);
				}else{
					printf("\nPara listar pasajeros, primero debe dar de alta alguno. Vuelva a la opcion 1\n\n");
				}
				break;
			case 5:
				altaForzada(pasajeros, TAM, &proximoId, &flag);
				break;
			}
		system("pause");

	}while(opcion != 5);

	return EXIT_SUCCESS;
}
