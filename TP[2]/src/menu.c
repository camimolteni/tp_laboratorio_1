#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "arraypassenger.h"
#include "menu.h"
#include <string.h>
#include "validaciones.h"

int menuPrincipal(){

	int opcion;

	printf("1. Altas");
	printf("\n2. Modificar");
	printf("\n3. Bajas");
	printf("\n4. Informar");
	printf("\n5. Salir");
	printf("\nSeleccione opcion deseada: ");
	scanf("%d", &opcion);

	return opcion;
}

int menuModificar(ePassenger pasajeros[], int TAM){

	int idAux;
	int i;
	int opcion;

	idAux = findPassengerById(pasajeros,TAM);

	for(i = 0; i < TAM; i++){
		if(idAux == pasajeros[i].id){
		    printf("\n*** CAMPO A MODIFICAR ***\n\n");
		    printf("1. Nombre\n");
		    printf("2. Apellido\n");
		    printf("3. Precio del vuelo\n");
		    printf("4. Codigo del vuelo\n");
		    printf("5. Tipo de pasajero\n");
		    printf("6. Salir\n");
		    printf("Ingrese opcion: ");
		    fflush(stdin);
		    scanf("%d", &opcion);

		    switch(opcion){
		    case 1:
		    	printf("Ingrese nuevo nombre: \n");
		    	fflush(stdin);
		    	scanf("%[^\n]", pasajeros[i].name);
		    	break;

		    case 2:
		    	printf("Ingrese nuevo apellido: \n");
		    	fflush(stdin);
		    	scanf("%[^\n]", pasajeros[i].lastName);
		    	break;

		    case 3:
		    	printf("Ingrese nuevo precio del vuelo: \n");
		    	fflush(stdin);
		    	scanf("%f", &pasajeros[i].price);
		    	break;

		    case 4:
		    	printf("Ingrese nuevo codigo del vuelo: \n");
		    	fflush(stdin);
		    	scanf("%[^\n]", pasajeros[i].flyCode);
		    	break;

		    case 5:
		    	printf("Ingrese nuevo tipo de pasajero: \n");
		    	fflush(stdin);
		    	scanf("%d", &pasajeros[i].typePassenger);
		    	break;
		    }
		}
	}
	return 0;
}

void menuInformar(ePassenger pasajeros[], int TAM){

	char opcionInformar;
	int i;
	int j;
	int importeTotal = 0;
	int importeParcial = 0;
	int sumarDatos= 0;
	int promedio;
	int pasajesMasPromedio=0;

	printf("\n**MENU INFORMAR***\n\n");
	printf("Indique la opcion que desee informar:\n");
	printf("1- Listado de pasajeros ordenados alfabéticamente por apellido y tipo de pasajero.\n");
	printf("2- Total y promedio de los precios por pasajes, y cuantos pasajeros superan el precio promedio.\n");
	printf("3- Listado de pasajeros por codigo de vuelo, y estado activo.\n");
	fflush(stdin);
	scanf("%c", &opcionInformar);
	opcionInformar=toupper(opcionInformar);

	switch(opcionInformar){
		case 1:
			for(i=0;i<TAM;i++){
				if(pasajeros[i].isEmpty == 1){

					importeParcial = pasajeros[i].price;
					importeTotal += importeParcial;
					sumarDatos++;
				}
			}
			promedio = importeTotal / sumarDatos;

			for(j=0;j<TAM;j++){

				if(pasajeros[j].price > promedio && pasajeros[j].isEmpty == 1){
					pasajesMasPromedio++;
				}
			}
				printf("El importe total es: $%d y el promedio es: $%d\n", importeTotal, promedio);
				printf("La cantidad total de album que superan ese promedio es de: %d", pasajesMasPromedio);
		break;
	}

}

int informar(ePassenger pasajeros[], int TAM, eClass clases[], int cantVuelo, eVuelo vuelo[], int cantClas, int flag){

    int todoOk = 0;
    int criterio;

    if(pasajeros != NULL && TAM > 0 && clases != NULL && cantVuelo > 0 && vuelo != NULL && cantClas > 0 && flag == 0)
    {
        switch(menuInformar())
        {
        case 1:
            printf("Ingrese como desea ordenar: 1 'ASCENDENTE' / 0'DESCENDENTE': ");
            scanf("%d", &criterio);
            while(criterio != 0  && criterio != 1)
            {
                printf("Por favor, ingrese un criterio valido: 1 'ASCENDENTE' / 0'DESCENDENTE': ");
                scanf("%d", &criterio);
            }
            sortPassenger(pasajeros, TAM, clases, cantClas, criterio);
            listarPasajeros(pasajeros, TAM, clases, cantClas, vuelo, cantVuelo);
            break;
        case 2:
            promedioPrecios(pasajeros,TAM);
            break;
        case 3:
        	sortPassengerFlyCode(pasajeros, TAM, vuelo, cantVuelo, clases, cantClas);
            break;
        }
        todoOk = 1;
    }
    else
    {
        printf("No hay pasajeros cargados en sistema.\n");
    }
    return todoOk;
}

int cargarClase(eClass clases[], int TAM, int id, char desc[]){

    int todoOk = 0;

    if(clases != NULL && desc != NULL && TAM > 0)
    {
      for(int i = 0; i < TAM; i++)
      {
          if(clases[i].id == id)
          {
              strcpy(desc, clases[i].descripcion);
              todoOk = 1;
              break;
          }
      }
    }
    return todoOk;
}

