#include <stdio.h>
#include <stdlib.h>
#include "menu.h"


int menuPrincipal(){

	int opcion;
	printf("*** BIENVENIDOS! *** \n\n");
	printf("1- Ingresar kilometros: \n");
	printf("2- ingresar precio de vuelos: \n");
	printf("3- Calcular todos los costos: \n");
	printf("4- Informar Resultados: \n");
	printf("5- Carga forzada de datos: \n");
	printf("6- Salir: \n");
	printf("Ingrese una opcion: \n");
	scanf("%d", &opcion);

	return opcion;
}


float ingresoYValidacionKms(){

	float km;

	printf("Ingrese los kilometros del vuelo: \n");
	scanf("%f", &km);

	while(km <= 0){
		fflush(stdin);
		printf("Error. Por favor ingrese kilometros validos: \n");
		scanf("%f", &km);
	}

	return km;
}

int subMenuVuelos(){

	int opcion;

	printf("Elija la aerolineas que desee ingresar: \n");
	printf("1- Precio vuelo Aerolineas Argentinas: \n");
	printf("2- Precio vuelo Latam: \n");
	scanf("%d", &opcion);

	return opcion;
}

void mostrarResultados(float precioLatam, float precioAerolineas, float precioDebitoLatam, float precioDebitoAA, float precioCreditoLatam,
		float precioCreditoAA, float precioBitcoinLatam, float precioBitcoinAA, float precioUnitarioLatam, float precioUnitarioAA,
		float diferenciaPrecios, float km){

	printf("Kilometros ingresados: %.2f km \n\n", km);

	printf("Precio Aerolineas Argentinas: $%.2f \n", precioAerolineas);
	printf("a) Precio con tarjeta de debito: $%.2f \n", precioDebitoAA);
	printf("b) Precio con tarjeta de credito: $%.2f \n", precioCreditoAA);
	printf("c) Precio pagando con bitcoins: %.5f BTC \n", precioBitcoinAA);
	printf("d) Precio unitario: $%.2f \n\n", precioUnitarioAA);

	printf("Precio Latam: $%.2f \n", precioLatam);
	printf("a) Precio con tarjeta de debito: $%.2f \n", precioDebitoLatam);
	printf("b) Precio con tarjeta de credito: $%.2f \n", precioCreditoLatam);
	printf("c) Precio pagando con bitcoins: %.5f BTC \n", precioBitcoinLatam);
	printf("d) Precio unitario: $%.2f \n\n", precioUnitarioLatam);

	printf("La diferencia de precio es: $%.2f \n\n", diferenciaPrecios);

}
