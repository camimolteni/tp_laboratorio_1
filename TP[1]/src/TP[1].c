#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "calculos.h"

int main(){
	setbuf(stdout, NULL);

	int opcion, opcionAerea, flagKm = 0, flagAerolineas = 0, flagLatam = 0, flagCalculos = 0;
	float km = 7090, precioAerolineas = 162965, precioLatam = 159339, precioDebitoLatam, precioDebitoAA, precioCreditoLatam,
		  precioCreditoAA,precioBitcoinLatam, precioBitcoinAA, precioUnitarioLatam, precioUnitarioAA, diferenciaPrecios;
	char salida;

	do{
		opcion = menuPrincipal();
		switch(opcion){
			case 1:
				km = ingresoYValidacionKms();
				flagKm = 1;
			break;
			case 2:
				opcionAerea = subMenuVuelos(precioAerolineas, precioLatam);
				if(opcionAerea == 1){
						precioAerolineas = ingresoPrecio(opcionAerea);
						flagAerolineas = 1;
				}else{
					precioLatam = ingresoPrecio(opcionAerea);
					flagLatam = 1;
				}
			break;
			case 3:
				if(flagLatam == 1 && flagAerolineas == 0){
				printf("Antes de realizar los calculos debe ingresar el precio de Aerolineas. \n");
				}else if(flagLatam == 0 && flagAerolineas == 1){
					printf("Antes de realizar los calculos debe ingresar el precio de Latam. \n");
				}
				if(flagKm == 1 && flagAerolineas == 1 && flagLatam == 1){
					precioDebitoLatam = pagoConDebito(precioLatam);
					precioCreditoLatam = pagoConCredito(precioLatam);
					precioBitcoinLatam = pagoConBitcoin(precioLatam);
					precioUnitarioLatam = precioPorKm(precioLatam, km);
					precioDebitoAA = pagoConDebito(precioAerolineas);
					precioCreditoAA = pagoConCredito(precioAerolineas);
					precioBitcoinAA = pagoConBitcoin(precioAerolineas);
					precioUnitarioAA = precioPorKm(precioAerolineas, km);
					diferenciaPrecios = calculoDiferencia(precioAerolineas, precioLatam);
					flagCalculos = 1;

					printf("REALIZANDO CALCULOS... \n");
					printf("CALCULOS REALIZADOS CON EXITO! \n");

				}else if(flagKm == 0 && flagAerolineas == 1 && flagLatam == 1){
					printf("Antes de realizar los calculos debe ingresar los kilometros. \n");
				}else if(flagKm == 1 && flagAerolineas == 0 && flagLatam == 0){
					printf("Antes de realizar los calculos debe ingresar los precios de los vuelos. \n");
				}else if(flagKm == 0 && flagAerolineas == 0 && flagLatam == 0){
					printf("No se ingresaron datos. \n");
				}
			break;
			case 4:
				if(flagCalculos == 1){
				mostrarResultados(precioLatam, precioAerolineas, precioDebitoLatam, precioDebitoAA, precioCreditoLatam, precioCreditoAA,
								  precioBitcoinLatam, precioBitcoinAA, precioUnitarioLatam, precioUnitarioAA, diferenciaPrecios, km);
				}else{
					printf("Debe ingresar todos los datos para realizar los calculos. Vuelva al menu.. \n");
				}
			break;
			case 5:
				precioDebitoLatam = pagoConDebito(159339);
				precioDebitoAA = pagoConDebito(162965);
				precioCreditoLatam = pagoConCredito(159339);
				precioCreditoAA = pagoConCredito(162965);
				precioBitcoinLatam = pagoConBitcoin(159339);
				precioBitcoinAA = pagoConBitcoin(162965);
				precioUnitarioLatam = precioPorKm(159339, 7090);
				precioUnitarioAA = precioPorKm(162965, 7090);
				diferenciaPrecios = 162965-159339;
				mostrarResultados(159339, 162965, precioDebitoLatam, precioDebitoAA, precioCreditoLatam, precioCreditoAA, precioBitcoinLatam,
								  precioBitcoinAA, precioUnitarioLatam, precioUnitarioAA, diferenciaPrecios, 7090);
			break;
			case 6:
				salida = 's';
			break;
			default:
				printf("Opcion invalida. Por favor ingrese un numero de la lista: \n");
		}
		fflush(stdin);
		system("pause");

	  }while(salida != 's');

	printf("Gracias por elegirnos! Hasta pronto.");
	return 0;
}
