#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "arraypassenger.h"
#include "validaciones.h"

int initPassenger(ePassenger pasajeros[], int TAM){

	int i;
	int todoOk=-1;

	for(i=0; i < TAM; i++){
		if(pasajeros != NULL){
			pasajeros[i].isEmpty = 0;

			todoOk= 0;
		}
	}

	return todoOk;
}
int indexLibre(ePassenger pasajeros[], int TAM){

	int i;
	int index=-1;

	for(i=0;i<TAM;i++){

		if(pasajeros[i].isEmpty==0){

			index=i;
			break;
		}
	}
	return index;
}
int addPassenger(ePassenger pasajeros[], eClass clase[], eVuelo vuelos[], int TAM, int cantVuelo, int cantClas, int *pNextId){

	int todoOk = 0;
	int i;
	ePassenger new;
	char bufferCodigoVuelo[10];


	    if(pasajeros != NULL && pNextId != NULL && clase != NULL && TAM > 0 && cantClas > 0){
	        printf("\n***** Carga de pasajeros *****\n\n");
	        buscarLibre(pasajeros, TAM, &i);

	        if(i == -1){
	            printf("No hay lugar en el sistema.\n");
	        }
	        else
	        {
	            new.id = *pNextId;

	            pidoLetras(new.name, 51, "Nombre: ");
	            pidoLetras(new.lastName, 51, "Apellido: ");
	            pidoLetras(&new.price, "Precio: ");

	            printf("Ingrese el codigo del vuelo: ");
	            fflush(stdin);
	            gets(bufferCodigoVuelo);

	            strcpy(new.flyCode, bufferCodigoVuelo);

	            listarClases(clase, cantClas);

	            (&new.typePassenger, "Tipo de pasajero: ", 1, 4);

	            new.isEmpty = 0;

	            pasajeros[i] = new;
	            mostrarPasajero(pasajeros[i], clase, vuelos, cantClas, cantVuelo);

	            (*pNextId)++;
	            todoOk = 1;
	        }
	    }
	    return todoOk;

int buscarPasajero(ePassenger pasajeros[], int id, int TAM, int* pIndex)
{
    int todoOk = 0;
    if(pasajeros != NULL && pIndex != NULL && TAM > 0)
    {
        *pIndex = -1;
        for(int i=0; i < TAM; i++)
        {
            if(!pasajeros[i].isEmpty  && pasajeros[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

void informarPasajero(ePassenger pasajeros[], eClass clase[], eVuelo vuelos[], int TAM, int cantVuelo, int cantClas){

	char descripcion[10];
	int i;

	for(i=0;i<TAM;i++){
	    printf("\nId: %d\n", pasajeros->id);
	    printf("Nombre: %s\n", pasajeros->name);
	    printf("Apellido: %s\n", pasajeros->lastName);
	    printf("Precio: %.2f\n", pasajeros->price);
	    printf("Codigo del vuelo: %s\n", pasajeros->flyCode);
	    cargarClase(clase, cantClas, pasajeros->typePassenger, descripcion);
	    printf("Tipo de pasajero: %s\n", descripcion);
	    statusFlight(vuelos, cantVuelo, pasajeros->flyCode, statusFlight);
	    printf("Estado de; vuelo: %s\n", statusFlight);
	}
}

void listarClases(ePassenger pasajeros[], int TAM){

	int i;

	for(i=0;i<TAM;i++){
		if(pasajeros[i].isEmpty==1)
		printf("ID:%d\tNombre:%s\tApellido:%s\tPrecio:%.2f\tCodigo:%s\tTipo:%d\t\n", pasajeros[i].id,
				pasajeros[i].name, pasajeros[i].lastName,
				pasajeros[i].price, pasajeros[i].flyCode, pasajeros[i].typePassenger);
	}
}

int findPassengerById(int id, ePassenger pasajeros[], int TAM){

	int idAux;

	printf("Ingrese el ID del pasajero a buscar\n");
	informarPasajero(pasajeros, TAM);
	scanf("%d", &idAux);

	return idAux;

}

int removePassenger(ePassenger pasajeros[], int TAM){

	int i;
	int idAux;
	int todoOk = -1;
	char confirmar;

	printf("Seleccione el ID a eliminar: \n");
	idAux = findPassengerById(pasajeros,TAM);

		for(i=0; i < TAM; i++){
		if(idAux == pasajeros[i].id){
			pasajeros[i].isEmpty = -1;
			todoOk = 0;

			utn_getCharacter(&confirmar,"\nSeguro desea dar de baja este pasajero? s/n: ", "Error. ", 's', 'n', 10);

			if(confirmar=='s')
	        {
	            pasajeros[i].isEmpty = 1;
	            todoOk = 0;
	        }
	        else
	        {
	            printf("Se cancela la baja del pasajero.}n");
	        }
	    }
	}
	return todoOk;
}

void mostrarPasajeroFila(ePassenger pasajeros[], eClass clases[], int cantClas, eVuelo vuelos[], int cantVuelo, int TAM){

    char descripcion[20];
    char status[10];

    statusFlight(vuelos, cantVuelo, pasajeros->flyCode, status);
    cargarClase(clases, cantClas, pasajeros->typePassenger, descripcion);

	printf("    %4d    %10s      %10s    %10.2f    %10s   %10s  \n",
	           pasajeros.id,
	           pasajeros.name,
	           pasajeros.lastName,
	           pasajeros.price,
	           pasajeros.flyCode,
	           descripcion,
			   status
	            );
}

int listarPasajeros(ePassenger pasajeros[], int TAM)
{
    int todoOk = 0;
    int flag = 1;
    if(pasajeros != NULL && TAM > 0)
    {
        printf("       *** Listado de pasajeros ***\n");
        printf("     ID        Nombre        Apellido    Precio     Codigo   Tipo de vuelo");
        printf("-----------------------------------------------------------------------\n");
        for(int i=0; i < TAM; i++)
        {
            if(!pasajeros[i].isEmpty)
            {
                mostrarPasajeroFila(pasajeros,TAM);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("     No hay pasajeros en el sistema\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int sortPassenger(ePassenger pasajeros[], int TAM) //ordena por apellido y tipo de pasajeros ASCENDENTE
{
    int todoOk = 0;
    ePassenger auxPassenger;

    if(pasajeros != NULL && TAM > 0)
    {
        for(int i=0; i < TAM - 1; i++)
        {
            for(int j= i+1; j < TAM; j++)
            {
                if(strcmp(pasajeros[i].lastName, pasajeros[j].lastName) > 0 ||
                (strcmp(pasajeros[i].lastName, pasajeros[i].lastName) == 0
                && pasajeros[i].typePassenger > pasajeros[j].typePassenger))
                {
                	auxPassenger = pasajeros[i];
                	pasajeros[i] = pasajeros[j];
                	pasajeros[j] = auxPassenger;
                }else
                	if(strcmp(pasajeros[i].lastName, pasajeros[j].lastName) < 0 ||
                            (strcmp(pasajeros[i].lastName, pasajeros[i].lastName) == 0
                            && pasajeros[i].typePassenger < pasajeros[j].typePassenger))
                	{
                    	auxPassenger = pasajeros[i];
                    	pasajeros[i] = pasajeros[j];
                    	pasajeros[j] = auxPassenger;
                	}
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int promedioPrecios(ePassenger pasajeros[], int TAM){

	int todoOk = 0;
    float acumuladorPrecios = 0;
    int contadorPasajes = 0;
    float promedio = 0;
    int contadorPromMay = 0;

    if(pasajeros != NULL && TAM > 0)
    {
        for(int i=0; i < TAM; i++)
        {
            if(!pasajeros[i].isEmpty)
            {
            	acumuladorPrecios += pasajeros[i].price;
            	contadorPasajes++;
            }
        }
        if(contadorPasajes != 0)
        {
            promedio = acumuladorPrecios / contadorPasajes;
        }

        printf("      *** Informe de precios ***\n");
        printf("El precio total de los vuelos es: $ %2.f\n", acumuladorPrecios);
        printf("El promedio de los precios de los vuelos es: $ %2.f\n", promedio);
        printf("Pasajeros que superan el precio promedio: \n\n");
        printf("     NOMBRE        APELLIDO          PRECIO\n");
        printf("-------------------------------------------\n");

        for(int i = 0; i < TAM; i++){

            if(pasajeros[i].price > promedio){

            	contadorPromMay++;
                printf("%10s      %10s      %10.2f\n", pasajeros[i].name, pasajeros[i].lastName, pasajeros[i].price);
            }
        }
        printf("%d pasajeros superan el precio promedio.\n", contadorPromMay);
        todoOk = 1;
    }
    return todoOk;
}

int sortPassengerFlyCode(ePassenger pasajeros[], int TAM, eVuelo vuelos[], int cantVuelo, eClass clases[], int cantClas){

    int todoOk = 0;
    char desc[10];
    ePassenger auxPass;
    int flag = 1;

    if(pasajeros != NULL && TAM > 0 && vuelos != NULL && cantVuelo > 0 && clases != NULL && cantClas > 0)
    {
        for(int i=0; i < TAM - 1; i++)
        {
            for(int j=i+1; j < TAM; j++)
            {
                if(stricmp(pasajeros[i].flyCode, pasajeros[j].flyCode) > 0 || stricmp(pasajeros[i].flyCode, pasajeros[j].flyCode) == 0)
                {
                    auxPass = pasajeros[i];
                    pasajeros[i] = pasajeros[j];
                    pasajeros[j] = auxPass;
                }
            }
        }
        printf("***************************** PASAJEROS *****************************\n\n");
        printf(" ID      NOMBRE      APELLIDO      PRECIO      CODIGO DE VUELO      CLASE Y TIPO      ESTADO DE VUELO\n\n");

        for(int i=0; i < TAM; i++)
        {
            statusFlight(vuelos, cantVuelo, pasajeros[i].flyCode, desc);
            if(!pasajeros[i].isEmpty && stricmp(desc, "ACTIVO") == 0)
            {
                mostrarPasajeroFila(pasajeros[i], clases, vuelos, cantVuelo, cantClas);
                flag = 0;
            }
        }
        if(flag == 1)
        {
            printf("No hay vuelos activos.\n");
        }
        todoOk = 1;
    }
    return todoOk;
}

int hardcodearPasajeros(ePassenger pasajeros[], int TAM, int cant, int* pNextId){

	int todoOk = 0;
    ePassenger pasaj[5] =
    {
        {0, "Laura", "Rodriguez", 2500, "AB", 1, 0},
        {0, "Juan", "Suarez", 4850, "CD", 2, 0},
        {0, "Pepe", "Vazquez", 8900, "BC", 3, 0},
        {0, "Carlos", "Perez", 3000, "AB", 1, 0},
        {0, "Lucia", "Lopez", 5670, "BC", 3, 0},
    };

    if(pasajeros != NULL && pNextId != NULL && TAM > 0 && TAM <= 5 && cant <= TAM)
    {
        for(int i=0; i < cant; i++)
        {
        	pasajeros[i] = pasaj[i];
        	pasajeros[i].id = *pNextId;
            (*pNextId)++;
        }
        todoOk = 1;
    }
    return todoOk;

}

void listarPorCodigo(ePassenger pasajeros[], int TAM){

	int todoOk = 0;
	char descripcion[10];
	int flag = 1;
	ePassenger auxPasaj;

	printf("\n     Nombre      Apellido      Codigo de vuelo     Estado de vuelo\n\n");

	if(pasajeros != NULL && TAM > 0){
		for(int i=0;i<TAM;i++){
			if(pasajeros[i].isEmpty == 0){
				if(pasajeros[i].statusFlight == 1){
					strcpy(descripcion,"ACTIVO");

					printf("%10s     %10s       %5s       %10s\n\n",
					pasajeros[i].name,pasajeros[i].lastName,pasajeros[i].flyCode,descripcion);
				}
			}
		}
	}
}

int altaForzada(ePassenger pasajeros[], int TAM, int* pNextId, int*pFlag){

	int todoOk = 0;
    int nextId;
    nextId = *pNextId;

    if(pasajeros != NULL && pNextId != NULL && TAM > 0){

        harcodearPasajeros(pasajeros, TAM, &nextId);
        *pNextId = nextId;
        *pFlag = 0;
        todoOk = 1;
    }
    return todoOk;
}
