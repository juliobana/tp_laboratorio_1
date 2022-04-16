/*
 * realizarCalculos.c
 *
 *  Created on: 14 abr. 2022
 *      Author: Julio
 */

#include <stdio.h>
#include <stdlib.h>
#include "realizarCalculos.h"

/// @brief Funcion realiza calculos de porcentajes
/// @param pNumeroIngresado
/// @param mensaje
/// @param mensajeError
/// @param maximo
/// @param minimo
/// @param maximoDeReintentos
/// @return 0 si esta OK. -1 si algo no salio bien

float calculoPorcentaje(float monto, float porcentaje, float * pMontoMasRecargo){

	float retorno;
	retorno=-1;
	float recargo;
	if(porcentaje >= 0){
	recargo = monto * porcentaje;
	*pMontoMasRecargo = recargo;
	retorno=0;
	}
    return retorno;
}
