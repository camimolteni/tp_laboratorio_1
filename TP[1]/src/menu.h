/*
 * menu.h
 *
 *  Created on: 12 abr. 2022
 *      Author: Camila
 */

#ifndef MENU_H_
#define MENU_H_

/// @brief menu de opciones
///
/// @return devuelve la opcion que ingresa el usuario
int menuPrincipal();
/// @brief confirma que el usuario ingreso los km
///
/// @return devuelve la cantidad de km
float ingresoYValidacionKms();
/// @brief pide la opcion de vuelo que desee ingresar
///
/// @return devuelve la opcion elegida
int subMenuVuelos();
/// @brief muestra los resultados
///
/// @param precio de aerolinea
/// @param precio de aerolinea
/// @param precio de aerolinea con debito
/// @param precio de aerolinea con debito
/// @param precio de aerolinea con credito
/// @param precio de aerolinea con credito
/// @param precio de aerolinea en bitcoin
/// @param precio de aerolinea en bitcoin
/// @param precio de aerolinea por km
/// @param precio de aerolinea por km
/// @param diferencia de precio entre una y otra
/// @param cantidad de km
void mostrarResultados(float, float, float, float, float, float, float, float, float, float, float, float);



#endif /* MENU_H_ */
