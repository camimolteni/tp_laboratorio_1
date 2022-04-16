#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"

float ingresoPrecio(int opcionElegida){

	float opcion;
	if(opcionElegida == 1){
		printf("Ingrese el precio para Aerolineas Argentinas: ");
		scanf("%f", &opcion);
	}else{
		printf("Ingrese el precio para Latam: ");
		scanf("%f", &opcion);
	}

	return opcion;
}

float pagoConDebito(float precio){

	float precioDebito;

	precioDebito = precio - ((precio * 0.10));

	return precioDebito;
}

float pagoConCredito(float precio){

	float precioCredito;

	precioCredito = precio + ((precio * 0.25));

	return precioCredito;
}

float pagoConBitcoin(float precio){

	float precioBitcoin;

	precioBitcoin = precio / 4456782.18;

	return precioBitcoin;
}

float precioPorKm(float precio, float km){

	float precioUnitario;

	precioUnitario = precio / km;

	return precioUnitario;
}

float calculoDiferencia(float precioAerolineas, float precioLatam){

	float difPrecio;

	if(precioAerolineas > precioLatam){
		difPrecio = precioAerolineas - precioLatam;
	}else{
		difPrecio = precioLatam - precioAerolineas;
	}

	return difPrecio;
}
