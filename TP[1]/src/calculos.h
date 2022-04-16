#ifndef CALCULOS_H_
#define CALCULOS_H_
#include "menu.h"


/// @brief pide la opcion elegida
///
/// @param ve si entra al if o no
/// @return devuelve la opcion elegida
float ingresoPrecio(int);


/// @brief calcula el descuento
///
/// @param float al que se le hace el descuento
/// @return devuelve numero con el descuento
float pagoConDebito(float);

/// @brief calcula el interes
///
/// @param numero al que se le hace el interes
/// @return devuelve el numero con el interes
float pagoConCredito(float);

/// @brief calcula el precio en bitcoin
///
/// @param precio a calcular
/// @return devuelve precio en bitcoin
float pagoConBitcoin(float);

/// @brief divide al precio ingreso por la cantidad de km
///
/// @param precio a dividir
/// @param cantidad de km por los que se divide al precio
/// @return devuelve el resultado de la division
float precioPorKm(float, float);

/// @brief resta los dos valores ingresados
///
/// @param se va a restar con el segundo precio ingresado
/// @param se resta con el primer precio ingresado
/// @return devuelve el resultado de la resta
float calculoDiferencia(float, float);


#endif /* CALCULOS_H_ */
